#ifndef VENTANAINICIARSESIONHIJA_H
#define VENTANAINICIARSESIONHIJA_H
#include "wxfb_project.h"

class Wallet;

class VentanaIniciarSesionHija : public VentanaIniciarSesion {	
private:
	Wallet *m_wallet;
protected:
	void OnClickIngresar( wxCommandEvent& event )  override;
	/*void Enter_Iniciar_sesion( wxCommandEvent& event ) ;*/
	void Click_Ingresar( wxCommandEvent& event ) override;
	
public:
	VentanaIniciarSesionHija(wxWindow *parent, Wallet *wallet);
	~VentanaIniciarSesionHija();
};

#endif

