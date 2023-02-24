#include <iostream>
#include <regex>
using namespace std;

bool is_email_valid(const string &email){
	
	// Regex del Official Standard RFC 5322 para validar emails
	const regex expRegEmail("^[a-z0-9!#$%&'*+/=?^_`{|}~-]+(?:\\.[a-z0-9!#$%&'*+/=?^_`{|}~-]+)*@(?:[a-z0-9](?:[a-z0-9-]*[a-z0-9])?\\.)+[a-z0-9](?:[a-z0-9-]*[a-z0-9])?$");
	return regex_match(email, expRegEmail);
	
}
/*
int main() {
	
	bool b;
	cout << "Quiere validar un email? 0=NO 1=SI" << endl;
	cin >> b;
	
	while(b){
	
		string email;
		
		cout << "Ingrese un email: "; 
		cin >> email;
	
		if( is_email_valid(email) )
			cout << "Email valido" << endl;
		else
			cout << "Email invalido" << endl;
		
		cout << "Quiere validar un email? 0=NO 1=SI" << endl;
		cin >> b;
	}
	
	
	return 0;
	
}
*/
