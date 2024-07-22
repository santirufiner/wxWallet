#include <iostream>
#include <regex>
#include <vector>
#include "Herramientas.h"
#include "Usuario.h"
#include <ctime>
using namespace std;


/// Funciones de validación ///
bool is_email_valid(const string &email){
	
	// Regex del Official Standard RFC 5322 para validar emails
	const regex expRegEmail("^[a-z0-9!#$%&'*+/=?^_`{|}~-]+(?:\\.[a-z0-9!#$%&'*+/=?^_`{|}~-]+)*@(?:[a-z0-9](?:[a-z0-9-]*[a-z0-9])?\\.)+[a-z0-9](?:[a-z0-9-]*[a-z0-9])?$");
	return regex_match(email, expRegEmail);
	
}
	
bool is_pass_valid(const string &pass) {
	
	// Regex para validar contraseñas (propio)
	const regex expRegPass("^(?=.*[A-Z])(?=.*[a-z])(?=.*[0-9])(?!.*[ ]).{8,16}$");
	return regex_match(pass, expRegPass);
	
}

bool is_user_valid(const string &user) {
	
	// Regex para validar usuarios (propio)
	const regex expRegUser("^(?=.*[a-z])(?!.*[ ]).{6,16}$");
	return regex_match(user, expRegUser);
	
}

/*--------------------------------------------------------------------------------*/

/// Función para generar balances iniciales (todos 0's)
vector<Activo> generarBalances() {
	
	vector<Activo> activos;
	
	Activo a1 = {"ARS", 0, 0, 0};
	activos.push_back(a1);
	Activo a2 = {"USD", 0, 0, 0};
	activos.push_back(a2);	
	Activo a3 = {"BTC", 0, 0, 0};
	activos.push_back(a3);
	Activo a4 = {"ETH", 0, 0, 0};
	activos.push_back(a4);
	Activo a5 = {"CPP", 0, 0, 0};
	activos.push_back(a5);
	
	return activos;
	
}

/// Función para generar direcciones de wallets
string generarAddress() {
	
	char address[41];
	char hex_characters[]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F', 'a', 'b', 'c', 'd', 'e', 'f'};
	
	address[0] = '0';
	address[1] = 'x';
	
	// Toma el rand según la hora del ordenador
	srand(time(0));
	for(int i=2;i<41;i++)
		address[i]=hex_characters[rand()%22];

	return address;
	
}

bool isNumeric(std::string const &str) {
	char* p;
	strtol(str.c_str(), &p, 10);
	return *p == 0;
}
