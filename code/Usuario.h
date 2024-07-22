#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include <fstream>
#include <vector>
#include <cstring>
using namespace std;

struct Activo {
	/*Datos activo*/
	char simbolo[256];
	float balance;
	float toARS;
	float toUSD;
	Activo& operator=(const Activo& a2){
		strcpy(simbolo,a2.simbolo);
		balance = a2.balance;
		toARS = a2.toARS;
		toUSD = a2.toUSD;
		return *this;
	}
	
};

struct registro_usuario {
	/*Datos usuario*/
	char email[256];
	char contrasena[256];
	char usuario[256];
	char address[256];
};


class Usuario {
	
private:
	// Datos del Usuario
	string m_email;					/// Email del Usuario
	string m_contrasena; 			/// Contraseña del Usuario
	string m_usuario; 				/// Nombre de Usuario
	string m_address;				/// Address del Usuario
	vector<Activo> Balances;		/// Balances del Usuario
	
public:
	/// Constructor
	Usuario(string email, string contrasena, string nombre_usuario);
	Usuario(string email, string contrasena, string nombre_usuario, string address,vector<Activo>&Balance);
	Usuario();
	
	/// Valida que los datos cargados del usuario sean correctos y suficientes
	string ValidarDatosUsuario();
	
	/// Obtener los datos del usuario
	string VerEmail() const;
	string VerContrasena() const;
	string VerUsuario() const;
	string VerAddress() const;
	vector<Activo> VerActivos() const;
	
	/// Modificar los datos del usuario
	void ModificarEmail(string email);
	void ModificarContrasena(string contrasena);
	void ModificarUsuario(string nombre_usuario);
	
	void AgregarBalanceARS(float montoARS);
	void AgregarBalanceUSD(float montoUSD);
	void AgregarBalanceBTC(float montoBTC);
	void AgregarBalanceETH(float montoETH);
	void AgregarBalanceCPP(float montoCPP);
	
	void RestarBalanceARS(float montoARS);
	void RestarBalanceUSD(float montoUSD);
	void RestarBalanceBTC(float montoBTC);
	void RestarBalanceETH(float montoETH);
	void RestarBalanceCPP(float montoCPP);
	
	void ModificarBalanceARSToARS();
	void ModificarBalanceUSDToARS();
	void ModificarBalanceBTCToARS();
	void ModificarBalanceETHToARS();
	void ModificarBalanceCPPToARS();
	
	void ModificarBalanceARSToUSD();
	void ModificarBalanceUSDToUSD();
	void ModificarBalanceBTCToUSD();
	void ModificarBalanceETHToUSD();
	void ModificarBalanceCPPToUSD();
	
	Usuario& operator=(Usuario &u);
	
	/// Guardar los datos del usuario en un archivo binario
	void GuardarUsuarioEnBinario(ofstream &archivo);
	void OrdenarActivos(int criterio);

};

bool OrdenarPorBalance(const Activo& a, const Activo& b);
bool OrdenarPorSimbolo(const Activo& a, const Activo& b);

#endif
