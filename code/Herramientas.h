#ifndef HERRAMIENTAS_H
#define HERRAMIENTAS_H

#include <regex>
#include "Usuario.h"
using namespace std;

bool is_email_valid(const string &email);
bool is_pass_valid(const string &pass);
bool is_user_valid(const string &user);
string generarAddress();
vector<Activo> generarBalances();
bool isNumeric(std::string const &str);

#endif
