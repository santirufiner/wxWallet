#include "Usuario.h"
#include <string>
#include <fstream>
#include <cstring>
#include "Herramientas.h"
using namespace std;
	
/// Constructores
Usuario::Usuario(string email, string contrasena, string nombre_usuario){
	m_email = email;
	m_contrasena = contrasena;
	m_usuario = nombre_usuario;
	m_address = generarAddress();
	Balances = generarBalances();
}

Usuario::Usuario(string email, string contrasena, string nombre_usuario, string Address, vector<Activo>&Balance){
	m_email = email;
	m_contrasena = contrasena;
	m_usuario = nombre_usuario;
	m_address = Address;
	Balances = Balance;
}

Usuario::Usuario(){}

/// Valida que los datos cargados del usuario sean correctos y suficientes
string Usuario::ValidarDatosUsuario() {
		string errores;
		
		return errores;
}

/// Obtener los datos del usuario
string Usuario::VerEmail() const { return m_email; }
string Usuario::VerContrasena() const { return m_contrasena; }
string Usuario::VerUsuario() const { return m_usuario; }
string Usuario::VerAddress() const { return m_address; }
vector<Activo> Usuario::VerActivos() const { return Balances; }

/// Modificar los datos del usuario
void Usuario::ModificarEmail(string email){ m_email = email; }
void Usuario::ModificarContrasena(string contrasena){ m_contrasena = contrasena; }
void Usuario::ModificarUsuario(string usuario){ m_usuario = usuario; }

void Usuario::AgregarBalanceARS(float montoARS){ Balances[0].balance += montoARS; }
void Usuario::AgregarBalanceUSD(float montoUSD){ Balances[1].balance += montoUSD; }
void Usuario::AgregarBalanceBTC(float montoBTC){ Balances[2].balance += montoBTC; }
void Usuario::AgregarBalanceETH(float montoETH){ Balances[3].balance += montoETH; }
void Usuario::AgregarBalanceCPP(float montoCPP){ Balances[4].balance += montoCPP; }

void Usuario::RestarBalanceARS(float montoARS){ Balances[0].balance -= montoARS; }
void Usuario::RestarBalanceUSD(float montoUSD){ Balances[1].balance -= montoUSD; }
void Usuario::RestarBalanceBTC(float montoBTC){ Balances[2].balance -= montoBTC; }
void Usuario::RestarBalanceETH(float montoETH){ Balances[3].balance -= montoETH; }
void Usuario::RestarBalanceCPP(float montoCPP){ Balances[4].balance -= montoCPP; }

/// Modificar balances de monedas toARS
void Usuario::ModificarBalanceARSToARS(){ 
	// Multiplica el balance en ARS por la cotización ARS/ARS al dia 8/3/2023
	Balances[0].toARS = Balances[0].balance * 1; 
}
void Usuario::ModificarBalanceUSDToARS(){
	// Multiplica el balance en USD por la cotización USD/ARS al dia 8/3/2023
	Balances[1].toARS = Balances[1].balance * 371;
}
void Usuario::ModificarBalanceBTCToARS(){
	// Multiplica el balance en BTC por la cotización BTC/ARS al dia 8/3/2023
	Balances[2].toARS = Balances[2].balance * 4435617;
}
void Usuario::ModificarBalanceETHToARS(){
	// Multiplica el balance en ETH por la cotización ETH/ARS al dia 8/3/2023
	Balances[3].toARS = Balances[3].balance * 312726;
}
void Usuario::ModificarBalanceCPPToARS(){
	// Multiplica el balance en CPP por la cotización CPP/ARS al dia 8/3/2023 (ficticia)
	Balances[4].toARS = Balances[4].balance * 49343;
}

/// Modificar balances de monedas toUSD
void Usuario::ModificarBalanceARSToUSD(){
	// Divide el balance en ARS por la cotización ARS/USD al dia 8/3/2023
	Balances[0].toUSD = Balances[0].balance / 371; 
}
void Usuario::ModificarBalanceUSDToUSD(){
	// Multiplica el balance en USD por la cotización USD/USD al dia 8/3/2023
	Balances[1].toUSD = Balances[1].balance * 1; 
}

void Usuario::ModificarBalanceBTCToUSD(){
	// Multiplica el balance en BTC por la cotización BTC/USD al dia 8/3/2023
	Balances[2].toUSD = Balances[2].balance * 22232; 
}
void Usuario::ModificarBalanceETHToUSD(){
	// Multiplica el balance en ETH por la cotización ETH/USD al dia 8/3/2023
	Balances[3].toUSD = Balances[3].balance * 1566; 
}
void Usuario::ModificarBalanceCPPToUSD(){
	// Multiplica el balance en CPP por la cotización CPP/USD al dia 8/3/2023 (ficticio)
	Balances[4].toUSD = Balances[4].balance * 133; 
}

/// Operador= para asignar un usuario
Usuario& Usuario::operator=(Usuario &u){
	this->m_email=u.m_email;
	this->m_contrasena=u.m_contrasena;
	this->m_usuario=u.m_usuario;
	this->m_address=u.m_address;
	this->Balances=u.Balances;
	return *this;
}

/// Guardar los datos del usuario en un archivo binario
void Usuario::GuardarUsuarioEnBinario(ofstream &archivo){
	registro_usuario reg;
	strcpy(reg.email,m_email.c_str());
	strcpy(reg.contrasena,m_contrasena.c_str());
	strcpy(reg.usuario,m_usuario.c_str());
	strcpy(reg.address,m_address.c_str());
	archivo.write((char*)&reg,sizeof(reg));
	
	///ESCRIBE EL VECTOR DE BALANCES
	for(size_t i=0;i<Balances.size();i++) {
		archivo.write((char*)&Balances[i], sizeof(Balances[i]));
	}
}

void Usuario::OrdenarActivos(int criterio){
	switch(criterio){
	case 0: sort(Balances.rbegin(), Balances.rend(), OrdenarPorBalance); break;
	case 1: sort(Balances.begin(), Balances.end(), OrdenarPorBalance); break;
	case 2: sort(Balances.begin(), Balances.end(), OrdenarPorSimbolo); break;
	case 3: sort(Balances.rbegin(), Balances.rend(), OrdenarPorSimbolo); break;
	default: sort(Balances.rbegin(), Balances.rend(), OrdenarPorBalance); break;
	}
}

/// Funciones de ordenamiento de activos
bool OrdenarPorBalance(const Activo& a, const Activo& b) {
	return a.balance < b.balance;
}
bool OrdenarPorSimbolo(const Activo& a, const Activo& b) {
	return a.simbolo[0]<b.simbolo[0];
}


