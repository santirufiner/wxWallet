#ifndef VENTANAVERADDRESSHIJA_H
#define VENTANAVERADDRESSHIJA_H
#include "wxfb_project.h"
#include <string>
using namespace std;

class Wallet;

class VentanaVerAddressHija : public VentanaVerAddress {
	
private:
	string m_address;
protected:
	
public:
	VentanaVerAddressHija(wxWindow *parent, string address);
	~VentanaVerAddressHija();
};

#endif

