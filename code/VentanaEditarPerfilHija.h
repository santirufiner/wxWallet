#ifndef VENTANAEDITARPERFILHIJA_H
#define VENTANAEDITARPERFILHIJA_H
#include "wxfb_project.h"


class Wallet;

class VentanaEditarPerfilHija : public VentanaEditarPerfil {
private:
	Wallet *m_wallet;
protected:
	void Click_Aceptar( wxCommandEvent& event )  override;
	void Click_Cancelar( wxCommandEvent& event )  override;
	
public:
	VentanaEditarPerfilHija(wxWindow *parent, Wallet *wallet);
	~VentanaEditarPerfilHija();
};

#endif

