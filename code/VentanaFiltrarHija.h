#ifndef VENTANAFILTRARHIJA_H
#define VENTANAFILTRARHIJA_H
#include "wxfb_project.h"

class Wallet;

class VentanaFiltrarHija : public VentanaFiltrar {
	
private:
	Wallet *m_wallet;
	wxGrid *m_grilla;
protected:
	void Click_Filtrar( wxCommandEvent& event )  override;
	
public:
	VentanaFiltrarHija(wxWindow *parent, Wallet *wallet,wxGrid *grilla);
	~VentanaFiltrarHija();
};

#endif

