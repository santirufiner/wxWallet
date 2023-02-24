#include <iostream>
#include <string>
#include <algorithm>
#include <regex>
using namespace std;

class Usuario {
	
private:
	string m_email;
	string contrasena;
	string nombre;
	string apellido;
	int dni;
	char sexo;
	int dia_nac;
	int mes_nac;
	int anio_nac;
	string fecha_nac="";
	string direccion;
	string localidad;
	string provincia;
	int cod_postal;
	long telefono;
	double balanceCuentaARS = 0;
	double balanceCuentaUSD = 0;
	double balanceCuentaCppCoin = 0;
	
	// función para generar fecha de nacimiento, que se invocará en el constructor de Usuario
	void generarFechaNac(int dia_nac, int mes_nac, int anio_nac){ fecha_nac = to_string(dia_nac) + '/' + to_string(mes_nac) + '/' + to_string(anio_nac); }
	
public:
		
		Usuario(string email, string contrasena, string nombre, string apellido, int dni, char sexo,
				int dia_nac, int mes_nac, int anio_nac, string direccion, string localidad, string provincia, int cod_postal, long telefono){
			m_email = email;
			generarFechaNac(dia_nac, mes_nac, anio_nac);
		};
		
		string verEmail() const { return m_email; }; ///< devuelve el email del usuario
		string verContrasena() const { return contrasena; }; ///< devuelve la contraseña del usuario
		string verNombre() const { return nombre; }; ///< devuelve el nombre del usuario
		string verApellido() const { return apellido; }; ///< devuelve el apellido del usuario
		int verDni() const { return dni; }; ///< devuelve el dni del usuario
		char verSexo() const { return sexo; }; ///< devuelve el sexo del usuario
		string verFechaNac() const { return fecha_nac; }; ///< devuelve la fecha de nacimineto del usuario
		string verDirecc() const { return direccion; }; ///< devuelve la dirección del usuario
		string verLocalidad() const { return localidad; }; ///< devuelve la ciudad del usuario
		string verProvincia() const { return provincia; }; ///< devuelve la provincia del usuario
		int verCodPostal() const { return cod_postal; }; ///< devuelve el código postal del usuario
		int verTelefono() const { return telefono; }; ///< devuelve el telefono del usuario
		double verBalanceARS() const { return balanceCuentaARS; }; ///< devuelve el balance en pesos argentinos (ARS) del usuario
		double verBalanceUSD() const { return balanceCuentaUSD; }; ///< devuelve el balance en dólares estadounidenses (USD) del usuario
		double verBalanceCPP() const { return balanceCuentaCppCoin; }; ///< devuelve el balance en CPP Coin (CPP) del usuario
		
		void ModificarEmail(std::string a_email) { m_email = a_email; } ; ///< actualiza la dirección de correo electrónico del usuario
		void ModificarContrasena(std::string a_contrasena) { contrasena = a_contrasena; }; ///< actualiza la contraseña del usuario
		void ModificarNombre(std::string a_nombre) { nombre = a_nombre; }; ///< actualiza el nombre del usuario
		void ModificarApellido(std::string a_apellido) { apellido = a_apellido; } ; ///< actualiza el apellido del usuario
		void ModificarDireccion(std::string a_direccion) { direccion = a_direccion; } ; ///< actualiza la direccion del usuario
		void ModificarLocalidad(std::string a_localidad) { localidad = a_localidad; } ; ///< actualiza la localidad del usuario
		void ModificarProvincia(std::string a_provincia) { provincia = a_provincia; } ; ///< actualiza la provincia del usuario
		void ModificarCodPostal(int a_codpostal) { cod_postal = a_codpostal; } ; ///< actualiza el código postal del usuario
		void ModificarTelefono(int a_telefono) { telefono = a_telefono; } ; ///< actualiza el telefono del usuario
		
		void ModificarBalanceARS(); ///< actualiza el balance en pesos argentinos (ARS) del usuario
		void ModificarBalanceUSD(); ///< actualiza el balance en dólares estadounidenses (USD) del usuario
		void ModificarBalanceCPP(); ///< actualiza el balance en CPP Coin (CPP) del usuario
		
};


bool is_email_valid(const string &email){
	
	// Regex del Official Standard RFC 5322 para validar emails
	const regex expRegEmail("^[a-z0-9!#$%&'*+/=?^_`{|}~-]+(?:\\.[a-z0-9!#$%&'*+/=?^_`{|}~-]+)*@(?:[a-z0-9](?:[a-z0-9-]*[a-z0-9])?\\.)+[a-z0-9](?:[a-z0-9-]*[a-z0-9])?$");
	return regex_match(email, expRegEmail);
	
}

int main() {
	
	Usuario p1("santirufiner1@gmail.com", "petiso123", "Santiago", "Rufiner", 40990653, 'm', 10, 04, 1998, "jrb1175", "Parana", "Entre Rios", 3100, 155172120);
	cout << p1.verFechaNac() << endl;
	cout << p1.verEmail() << endl;
	
	if( is_email_valid(p1.verEmail()) ) // no se pq acá da invalido el mail xd chequear
		cout << "Email valido";
	else
		cout << "Email invalido";
	
	return 0;
	
}
