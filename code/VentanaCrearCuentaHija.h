#ifndef VENTANACREARCUENTAHIJA_H
#define VENTANACREARCUENTAHIJA_H
#include "wxfb_project.h"

class Wallet;

class VentanaCrearCuentaHija : public VentanaCrearCuenta {
	
private:
	Wallet *m_wallet;
protected:
	void Click_CrearCuenta( wxCommandEvent& event ) override;
	
public:
	VentanaCrearCuentaHija(wxWindow *parent, Wallet *wallet);
	~VentanaCrearCuentaHija();
};

#endif

