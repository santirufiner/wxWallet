#ifndef VENTANAENVIARHIJA_H
#define VENTANAENVIARHIJA_H
#include "wxfb_project.h"

class Wallet;

class VentanaEnviarHija : public VentanaEnviar {
	
private:
	Wallet *m_wallet;
protected:
	void Click_Enviar( wxCommandEvent& event )  override;
	
public:
	VentanaEnviarHija(wxWindow *parent, Wallet *wallet);
	~VentanaEnviarHija();
};

#endif

