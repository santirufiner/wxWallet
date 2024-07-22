#include "Wallet.h"
#include <vector>
#include <fstream>
#include <algorithm>
#include "Usuario.h"
#include "Herramientas.h"
#include "Transaccion.h"
#include <cctype>
#include <cstdlib>
using namespace std;

/// Constructor
Wallet::Wallet(string a_nombre_archivo, string a_nombre_archivo2){
	binario_usuarios = a_nombre_archivo;
	binario_transacciones = a_nombre_archivo2;
	ifstream archivo(binario_usuarios.c_str(),ios::binary);
	if(archivo.is_open()) {
		registro_usuario reg;
		while(archivo.read(reinterpret_cast<char*>(&(reg)),sizeof(reg))) {
			vector<Activo> Balances;
			Activo a1;
			for(size_t i=0;i<5;i++) { 
				archivo.read((char*)&a1, sizeof(a1));
				Balances.push_back(a1);
			}
			Usuario u1(reg.email, reg.contrasena, reg.usuario, reg.address, Balances);
			Usuarios.push_back(u1);
		}
		archivo.close();
	}
}

/// Guardar los datos de la Wallet en un archivo binario
bool Wallet::GuardarUsuarios() {
	ofstream archivo(binario_usuarios.c_str(),ios::binary|ios::trunc);
	if(!archivo.is_open()) return false;
	for(unsigned int i=0;i<Usuarios.size();i++) {
		Usuarios[i].GuardarUsuarioEnBinario(archivo);
	}
	archivo.close();
	return true;
}

/// Funciones para Usuario
vector<Usuario> Wallet::VerUsuarios() { return Usuarios; }
int Wallet::CantidadUsuarios(){ return Usuarios.size(); }
Usuario& Wallet::VerUsuario(int i) { return Usuarios[i]; }
Usuario& Wallet::VerSesionIniciada() {return *SesionIniciada; }
int Wallet::BuscarUsuario(string Address) {
	for(size_t i=0;i<Usuarios.size();i++){
		if(Usuarios[i].VerAddress() == Address){
			return i;
		}
	}
	return -1;
}


/// Inicia sesion con un Usuario
bool Wallet::IniciarSesion(string email_o_usuario, string contrasenia){
	for(size_t i=0;i<VerUsuarios().size();i++) { 
		if((email_o_usuario == Usuarios[i].VerEmail() or email_o_usuario == Usuarios[i].VerUsuario()) and contrasenia == Usuarios[i].VerContrasena()){
			SesionIniciada = &Usuarios[i];
			Transacciones.clear();
			LeerEnBinarioTransacciones();
			return true;
		}
	}
	return false;
}

/// Crea una nueva cuenta y valida que los datos no estén previamente en el vector de Usuarios
bool Wallet::CrearCuenta(string email, string contrasena, string nombre_usuario){
	for(size_t i=0;i<VerUsuarios().size();i++) {
		if(email==Usuarios[i].VerEmail() or nombre_usuario==Usuarios[i].VerUsuario()){
			return false;
		}
	}	
	Usuario U1(email, contrasena, nombre_usuario);
	Usuarios.push_back(U1); 
	ofstream archivo(binario_usuarios.c_str(), ios::binary|ios::app|ios::ate);
	if(archivo.is_open()){
		U1.GuardarUsuarioEnBinario(archivo);
		archivo.close();
	}
	return true;
}

/// Funciones para Transacciones
bool Wallet::LeerEnBinarioTransacciones(){
	ifstream archivo(binario_transacciones.c_str(),ios::binary);
	if(archivo.is_open()){
		registro_transaccion reg2;
		while(archivo.read(reinterpret_cast<char*>(&(reg2)), sizeof(reg2))) {
			if(reg2.emisor == SesionIniciada->VerAddress() or reg2.receptor == SesionIniciada->VerAddress()){
				Fecha f_emision(reg2.F_Transaccion.dia,reg2.F_Transaccion.mes,reg2.F_Transaccion.anio);
				Transaccion t1(reg2.id, reg2.emisor, reg2.receptor, reg2.simbolomoneda, f_emision, reg2.monto, reg2.motivo);
				Transacciones.push_back(t1);
			}
		}
		archivo.close();
	}
	return true;
}

/// Funcion para retornar el vector de Transacciones
vector<Transaccion> Wallet::VerTransacciones() { return Transacciones; }

/// Funcion para retornar la cantidad de Transacciones
int Wallet::CantidadTransacciones(){ return Transacciones.size(); }

void Wallet::GenerarIngreso(string simbolo_moneda, float monto, string motivo){
	Transaccion t(Transacciones.size()+1,SesionIniciada->VerAddress(),SesionIniciada->VerAddress(),simbolo_moneda,monto,motivo);
	this->AgregarTransaccion(t);
}

void Wallet::GenerarEgreso(string address_receptor, string simbolo_moneda, float monto, string motivo){
	Transaccion t(Transacciones.size()+1,SesionIniciada->VerAddress(), address_receptor,simbolo_moneda,monto,motivo);
	this->AgregarTransaccion(t);
}

/// Funcion para agregar Transacciones
void Wallet::AgregarTransaccion(Transaccion &t) { 
	Transacciones.push_back(t); 
	
	ofstream archivo(binario_transacciones.c_str(), ios::binary|ios::app|ios::ate);
	if(archivo.is_open()){
		t.GuardarTransaccionEnBinario(archivo);
	archivo.close();
	}
	// Llama a la función para modificar el balance de el/los usuarios
	CargarIngresoDinero(t);
}


/// Funcion para cargar ingreso/egreso de dinero
void Wallet::CargarIngresoDinero(Transaccion &t){
	if(t.verTipoTransaccion()=="Ingreso"){
		
		if(t.verSimboloMoneda()== "ARS"){
			SesionIniciada->AgregarBalanceARS( t.verMonto() );
		}
		if(t.verSimboloMoneda()== "USD"){
			SesionIniciada->AgregarBalanceUSD( t.verMonto() );
		}
		if(t.verSimboloMoneda()== "BTC"){
			SesionIniciada->AgregarBalanceBTC( t.verMonto() );
		}
		if(t.verSimboloMoneda()== "ETH"){
			SesionIniciada->AgregarBalanceETH( t.verMonto() );
		}
		if(t.verSimboloMoneda()== "CPP"){
			SesionIniciada->AgregarBalanceCPP( t.verMonto() );
		}
		
	} else if(t.verTipoTransaccion()=="Egreso"){
		
		if(t.verSimboloMoneda()== "ARS"){
			SesionIniciada->RestarBalanceARS( t.verMonto() );
		}
		if(t.verSimboloMoneda()== "USD"){
			SesionIniciada->RestarBalanceUSD( t.verMonto() );
		}
		if(t.verSimboloMoneda()== "BTC"){
			SesionIniciada->RestarBalanceBTC( t.verMonto() );
		}
		if(t.verSimboloMoneda()== "ETH"){
			SesionIniciada->RestarBalanceETH( t.verMonto() );
		}
		if(t.verSimboloMoneda()== "CPP"){
			SesionIniciada->RestarBalanceCPP( t.verMonto() );
		}
		
		// Llama a la función de egreso de dinero, y le pasa el address al que le tiene que enviar, junto con el simbolo de la moneda y el monto
		CargarEgresoDinero(t.verAddressReceptor(), t.verSimboloMoneda(), t.verMonto());
	}
	SesionIniciada->ModificarBalanceARSToARS();
	SesionIniciada->ModificarBalanceUSDToARS();
	SesionIniciada->ModificarBalanceBTCToARS();
	SesionIniciada->ModificarBalanceETHToARS();
	SesionIniciada->ModificarBalanceCPPToARS();
	
	SesionIniciada->ModificarBalanceARSToUSD();
	SesionIniciada->ModificarBalanceUSDToUSD();
	SesionIniciada->ModificarBalanceBTCToUSD();
	SesionIniciada->ModificarBalanceETHToUSD();
	SesionIniciada->ModificarBalanceCPPToUSD();
}

void Wallet::CargarEgresoDinero(string Address, string Simbolo, float MontoTransaccion){
	
	// Busca la posición del usuario al que se le tiene que modificar el balance (Agregar dinero)
	int pos = BuscarUsuario(Address);
	
	if(Simbolo == "ARS"){
		Usuarios[pos].AgregarBalanceARS( MontoTransaccion );
//		Usuarios[pos].ModificarBalanceARSToARS();
//		Usuarios[pos].ModificarBalanceARSToUSD();
	}
	if(Simbolo == "USD"){
		Usuarios[pos].AgregarBalanceUSD( MontoTransaccion );
//		Usuarios[pos].ModificarBalanceUSDToARS();
//		Usuarios[pos].ModificarBalanceUSDToUSD();
	}
	if(Simbolo == "BTC"){
		Usuarios[pos].AgregarBalanceBTC( MontoTransaccion );
//		Usuarios[pos].ModificarBalanceBTCToARS();
//		Usuarios[pos].ModificarBalanceBTCToUSD();
	}
	if(Simbolo == "ETH"){
		Usuarios[pos].AgregarBalanceETH( MontoTransaccion );
//		Usuarios[pos].ModificarBalanceETHToARS();
//		Usuarios[pos].ModificarBalanceETHToUSD();
	}
	if(Simbolo == "CPP"){
		Usuarios[pos].AgregarBalanceCPP( MontoTransaccion );
//		Usuarios[pos].ModificarBalanceCPPToARS();
//		Usuarios[pos].ModificarBalanceCPPToUSD();
	}
	
}

/// Validar datos de transacción de ingreso
string Wallet::ValidarDatosTransaccionIngreso(string monto, double monto2){
	string errores = "";
	
	bool b = isNumeric(monto);
	
	if(!b or monto2 <= 0 or monto == ""){
		errores += "El valor ingresado no puede:\n- Ser negativo ni cero.\n- Ser texto.\n- Estar vacío.\n";
	}
	
	return errores;
}

/// Validar datos de transacción de egreso
string Wallet::ValidarDatosTransaccionEgreso(float balance_actual, string address_receptor, string monto, double monto2){
	string errores = "";
	
	// Condición de matcheo de wallet emisor == wallet receptor
	if(SesionIniciada->VerAddress()==address_receptor){
		errores += "Address receptor es la misma que del emisor. Intentelo nuevamente.\n";
	}
	
	// Condición de matcheo de wallet en el vector de usuarios
	bool match = false;
	for(size_t i=0;i<Usuarios.size();i++) { 
		if(Usuarios[i].VerAddress() == address_receptor){
			match = true; 
			break;
		}
	}
	if(!match){
		errores += "No se encontraron wallets con esa dirección Intentelo nuevamente.\n";
	}
	
	// Condición de balance > balance que se quiere enviar
	if(balance_actual < monto2){
		errores += "Balance insuficiente. Intentelo nuevamente\n.";
	}
	
	// Condición de balance correcto
	bool b = isNumeric(monto);
	
	if(!b or monto2 <= 0 or monto == "" ){
		errores += "El valor ingresado no puede:\n- Ser negativo ni cero.\n- Ser texto.\n- Estar vacío.\n";
	}
	
	return errores;
}

/// Funcion para ver Transaccion completa
Transaccion& Wallet::VerTransaccion(int i) { return Transacciones[i]; }

///==================== Funciones para Ordenar ===========================///

///* Ordenamiento de Transacciones *///
void Wallet::OrdenarTransacciones(int criterio) {
	
	switch(criterio){
	case 0: sort(Transacciones.begin(), Transacciones.end(), OrdenarPorFecha); break;
	case 1: sort(Transacciones.rbegin(), Transacciones.rend(), OrdenarPorFecha); break;
	case 2: sort(Transacciones.begin(), Transacciones.end(), OrdenarPorMonto); break;
	case 3: sort(Transacciones.rbegin(), Transacciones.rend(), OrdenarPorMonto); break;
	case 4: sort(Transacciones.rbegin(), Transacciones.rend(), OrdenarPorMotivo); break;
	case 5: sort(Transacciones.begin(), Transacciones.end(), OrdenarPorMotivo); break;
	default: sort(Transacciones.begin(), Transacciones.end(), OrdenarPorFecha); break;
	}
}

///==================== Funciones para Filtrar ===========================///

///* Filtrar Transacciones *///

vector<Transaccion> Wallet::FiltrarTransacciones(int criterio_tipo, int criterio_simbolo, Fecha fecha_desde, Fecha fecha_hasta, int criterio_motivo){
	
	// Inicializa un vector que va a ir llenándose según la transacción coincida con el filtro que se colocó
	vector<Transaccion> Filtro;
	
	// Inicializa distintos vectores con los distintos tipos de filtros 
	vector<string> v_criterios_tipo = {"-", "Ingreso", "Egreso"};
	vector<string> v_criterios_simbolo = {"-", "ARS", "USD", "BTC", "ETH", "CPP"};
	vector<string> v_criterios_motivo = {"-", "Alquiler", "Cuotas", "Expensas", "Facturas", "Honorarios", "Préstamo", "Varios"};
	int fechaDesde=Pasar_A_Dias(fecha_desde);
	int fechaHasta=Pasar_A_Dias(fecha_hasta);
	
	
	// Recorre todas las transacciones y se fija si el tipo de transacción coincide con el criterio del tipo seleccionado
	for(size_t i=0;i<Transacciones.size();i++) { 
		if(this->Transacciones[i].verTipoTransaccion() == v_criterios_tipo[criterio_tipo]){
			Filtro.push_back(Transacciones[i]); // Si coincide, lo pushea al vector de Filtro
		}
	}
	
	// Recorre todas las transacciones del usuario y se fija si el simbolo de la moneda/activo coincide con el criterio del simbolo seleccionado
	for(size_t i=0;i<Transacciones.size();i++) { 
		if(Transacciones[i].verSimboloMoneda() == v_criterios_simbolo[criterio_simbolo]){
			Filtro.push_back(Transacciones[i]); // Si coincide, lo pushea al vector de Filtro
		}
	}
	
	// Recorre todas las transacciones y se fija si el motivo de transacción coincide con el criterio del motivo seleccionado
	for(size_t i=0;i<Transacciones.size();i++) { 
		if(Transacciones[i].verMotivo() == v_criterios_motivo[criterio_motivo]){
			Filtro.push_back(Transacciones[i]); // Si coincide, lo pushea al vector de Filtro
		}
	}
	
	// Recorre todas las transacciones y se fija si los dias de la fecha están entre el criterio de Fecha desde a Fecha hasta
	for(size_t i=0;i<Transacciones.size();i++) { 
		int dias_fecha=Pasar_A_Dias(Transacciones[i].verFechaTransaccion());
		if(fechaDesde <=dias_fecha and fechaHasta>=dias_fecha){
			Filtro.push_back(Transacciones[i]);
		}
	}
	
	// Cuenta cuantos filtros no nulos ingresó el usuario, y lo usa para determinar la coincidencia de transacciones repetidas 
	int cont_filtros_no_nulos = 0;
	if(criterio_tipo!=0) cont_filtros_no_nulos++;
	if(criterio_simbolo!=0) cont_filtros_no_nulos++;
	if(criterio_motivo!=0) cont_filtros_no_nulos++;
	if(fechaDesde!=0 or fechaHasta!=0)cont_filtros_no_nulos++;
	
	// Inicializa un vector de filtro final y cuenta las ocurrencias repetidas que cumplen con el contador de filtros no nulo (osea las veces que se va a repetir)
	vector<Transaccion> FiltroFinal;
	for(size_t i=0;i<Filtro.size();i++) { 
		int cont = 1;
		for(size_t j=i+1;j<Filtro.size();j++) { 
			if( Filtro[i].verIdTransaccion() == Filtro[j].verIdTransaccion() ) 
				cont++;
		}
		if(cont == cont_filtros_no_nulos){
			FiltroFinal.push_back(Filtro[i]);
		}
	}
	
	// Retorna el vector con las transacciones filtradas finales para ser mostrado en la wallet
	return FiltroFinal;
}
