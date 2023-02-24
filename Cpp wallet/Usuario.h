/**
* @file Usuario.h
* @brief Declaraciones de todo lo necesario para trabajar con la clase Usuario
*
* Este archivo define la clase Usuario, las funciones auxiliares para compararlas
* y el struct que hace de intermediario para guardar y leer en archivo binarios.
**/

#ifndef Usuario_H
#define Usuario_H
#include <string>
#include <fstream>

struct registro_Usuario {
	char email[256];
	char contrasena[256];
	char nombre_usuario[256];
	char address[256];
	double balanceCuentaARS, balanceCuentaUSD, balanceCuentaCppCoin; // después vemos si agregamos más monedas (bitcoin, eth, etc.), por ahora estas 3
};

class Usuario {
	
private:
	
	// Datos del Usuario
	std::string email; ///< direccion de correo electronico del Usuario
	std::string contrasena; ///< contraseña del Usuario
	std::string nombre_usuario; ///< nombre de usuario del Usuario
	std::string address; ///< dirección de la wallet del Usuario
	double balanceCuentaARS; ///< balance en pesos argentinos (ARS) del Usuario
	double balanceCuentaUSD; ///< balance en dolares estadounidenses (USD) del Usuario
	double balanceCuentaCPP; ///< balance en CPP Coin (CPP) del Usuario
	
public:
	
	// Constructor por defecto (inicializa todo vacío)
	Usuario(std::string a_email = "", std::string a_contrasena = "", std::string a_nombre_usuario = "",
			std::string a_direccion = "", double a_balanceCuentaARS = 0, double a_balanceCuentaUSD = 0, double a_balanceCuentaCPP = 0);

	
	// Valida que los datos cargados del usuario sean correctos y suficientes
	std::string ValidarDatos();
	
	
	// Obtener los datos del usuario
	std::string VerEmail() const; ///< devuelve la direccion de correo electronico del Usuario
	std::string VerContrasena() const; ///< devuelve la contraseña del Usuario
	std::string VerNombreUsuario() const; ///< devuelve el nombre de usuario del Usuario
	std::string VerAddress() const; ///< devuelve el address de la wallet del Usuario
	double VerBalanceARS() const; ///< devuelve el balance en pesos argentinos (ARS) del Usuario
	double VerBalanceUSD() const; ///< devuelve el balance en dólares estadounidenses (USD) del Usuario
	double VerBalanceCPP() const; ///< devuelve el balance en CPP Coin (CPP) del Usuario
	
	
	// Modificar los datos del usuario
	void ModificarEmail(std::string a_email); ///< actualiza la direccion de correo electronico del Usuario
	void ModificarContrasena(std::string a_contrasena); ///< actualiza la contraseña del Usuario
	void ModificarNombreUsuario(std::string a_nombre_usuario); ///< actualiza el nombre de usuario del Usuario
	/* wallet no se puede modificar */
	void ModificarBalanceARS(double a_balanceCuentaARS); ///< actualiza el balance en pesos argentinos (ARS) del Usuario
	void ModificarBalanceUSD(double a_balanceCuentaUSD); ///< actualiza el balance en dólares estadounidenses (USD) del Usuario
	void ModificarBalanceCPP(double a_balanceCuentaCPP); ///< actualiza el balance en CPP Coin (CPP) del Usuario
	
	
	// Guardar los datos en un archivo binario
	void GuardarEnBinario(std::ofstream &archivo);
	// Leer los datos desde un archivo binario
	void LeerDesdeBinario(std::ifstream &archivo);

};

	// Criterios para matchear Usuarios

/// @brief Funcion para comparar dos Usuarios por email
bool criterio_comparacion_email(const Usuario &p1, const Usuario &p2);

/// @brief Funcion para comparar dos Usuarios por nombre de usuario
bool criterio_comparacion_nombre_de_usuario(const Usuario &p1, const Usuario &p2);

/// @brief Funcion para comparar dos Usuarios por contraseña
bool criterio_comparacion_contrasena(const Usuario &p1, const Usuario &p2);


#endif

