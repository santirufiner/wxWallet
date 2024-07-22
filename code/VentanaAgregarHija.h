#ifndef VENTANAAGREGARHIJA_H
#define VENTANAAGREGARHIJA_H
#include "wxfb_project.h"

class Wallet;

class VentanaAgregarHija : public VentanaAgregar {
	
private:
	Wallet *m_wallet;
	
protected:
	void Click_Agregar( wxCommandEvent& event )  override;
	
public:
	VentanaAgregarHija(wxWindow *parent, Wallet *wallet);
	~VentanaAgregarHija();
};

#endif

