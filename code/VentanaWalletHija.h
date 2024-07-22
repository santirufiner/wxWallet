#ifndef VENTANAWALLETHIJA_H
#define VENTANAWALLETHIJA_H
#include "wxfb_project.h"

class Wallet;

class VentanaWalletHija : public VentanaWallet {
	
private:
	Wallet *m_wallet;
protected:
	void ClickGrillaActivos( wxGridEvent& event )  override;
	void ClickGrillaTransacciones( wxGridEvent& event )  override;
	
	void CargarFilaActivos();
	void CargarFilaTransacciones();
	void Click_OrdenarActivos( wxCommandEvent& event )  override;
	void Click_OrdenarTransacciones( wxCommandEvent& event )  override;
	
	void Click_BotonAgregar( wxCommandEvent& event )  override;
	void Click_BotonEnviar( wxCommandEvent& event )  override;
	void Click_VerWallet( wxCommandEvent& event )  override;
	void Click_toARS( wxCommandEvent& event )  override;
	void Click_toUSD( wxCommandEvent& event )  override;
	void Click_Filtrar( wxCommandEvent& event )  override;
	void Click_EditarPerfil( wxCommandEvent& event )  override;
	void Click_CerrarSesion( wxCommandEvent& event ) override;
	
public:
	VentanaWalletHija(Wallet *m_wallet);
	~VentanaWalletHija();
};

#endif
