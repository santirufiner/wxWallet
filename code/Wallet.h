#ifndef WALLET_H
#define WALLET_H

#include "Usuario.h"
#include "Transaccion.h"
#include <vector>
using namespace std;

class Wallet {
	
private:
	// Datos de la wallet
	string binario_usuarios;				/// Nombre del Binario de Usurios
	string binario_transacciones;			/// Nombre del Binario de Transacciones
	vector<Usuario> Usuarios;				/// Vector de Usuarios Registrados
	vector<Transaccion>Transacciones;		/// Vector de Transacciones 
	Usuario *SesionIniciada;					/// Usuario que se encuentra Iniciada la Sesion
	
public:
	/// Constructor
	Wallet(string archivo, string archivo2);
	
	/// Guardar los Usuarios de la wallet en un archivo binario
	bool GuardarUsuarios();
	
	/// Funciones para Usuario
	vector<Usuario> VerUsuarios();
	int CantidadUsuarios();
	Usuario &VerUsuario(int i);
	Usuario &VerSesionIniciada();
	int BuscarUsuario(string Address);
	bool IniciarSesion(string email_o_usuario, string contrasenia);
	bool CrearCuenta(string email, string usuario, string contrasenia);
	
	/// Funciones para Transacciones
	bool LeerEnBinarioTransacciones();
	vector<Transaccion> VerTransacciones();
	int CantidadTransacciones();
	void GenerarIngreso(string simbolo_moneda, float monto, string motivo);
	void GenerarEgreso(string address_receptor, string simbolo_moneda, float monto, string motivo);
	void AgregarTransaccion(Transaccion &t);
	void CargarIngresoDinero(Transaccion &t);
	void CargarEgresoDinero(string Address, string Simbolo, float Monto_Transaccion);
	string ValidarDatosTransaccionIngreso(string monto, double monto2);
	string ValidarDatosTransaccionEgreso(float balance_actual, string address_receptor, string monto, double monto2);
	Transaccion &VerTransaccion(int i);
	
	///==================== Funciones para Ordenar ===========================///
	
	/* Ordenamiento de Activos */

	void OrdenarActivosUsuario(int criterio);
	
	/* Ordenamiento de Transacciones */
	
	void OrdenarTransacciones(int criterio);
	
	
	///==================== Funciones para Filtrar ===========================/// 
	
	/* Filtrar Transacciones */
	vector<Transaccion> FiltrarTransacciones(int criterio_tipo, int criterio_simbolo, Fecha fecha_desde, Fecha fecha_hasta, int criterio_motivo);
	
};

#endif
