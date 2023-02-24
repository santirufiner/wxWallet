#include <iostream>
#include <vector>
using namespace std;

vector<string> addresses;

string generarAddress() {
	
	char address[42];
	char hex_characters[]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F', 'a', 'b', 'c', 'd', 'e', 'f'};
	
	address[0] = '0';
	address[1] = 'x';
	
	for(int i=2;i<41;i++)
		address[i]=hex_characters[rand()%22];
	
	for(size_t i=0;i<addresses.size();i++) { 
		if(address==addresses[i])
			generarAddress();
	}
	
	addresses.push_back(address);
	
	return address;
}

int main() {
	
	cout << "Address de prueba: " << generarAddress();
	
	return 0;
}
