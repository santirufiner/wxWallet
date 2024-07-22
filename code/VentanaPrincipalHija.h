#ifndef VENTANAPRINCIPALHIJA_H
#define VENTANAPRINCIPALHIJA_H
#include "wxfb_project.h"

class Wallet;

class VentanaPrincipalHija : public VentanaPrincipal {
	
private:
	Wallet *m_wallet;
protected:
	void Click_CrearCuenta( wxCommandEvent& event )  override;
	void Click_IniciarSesion( wxCommandEvent& event )  override;
	
public:
	VentanaPrincipalHija(Wallet *wallet);
	~VentanaPrincipalHija();
};

#endif

