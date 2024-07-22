#include "VentanaPrincipalHija.h"
#include "VentanaIniciarSesionHija.h"
#include "VentanaCrearCuentaHija.h"
#include "VentanaWalletHija.h"
#include "Utils.h"
#include <wx/icon.h>
#include "clogo.xpm"
#include "Wallet.h"

VentanaPrincipalHija::VentanaPrincipalHija(Wallet *wallet) : VentanaPrincipal(nullptr), m_wallet(wallet){
	// Setear el logo de la aplicación
	SetIcon(wxIcon(clogo_xpm));
}

VentanaPrincipalHija::~VentanaPrincipalHija() {
	
}


/*------------------------------------------------------------------------*/


void VentanaPrincipalHija::Click_CrearCuenta( wxCommandEvent& event )  {
	
	VentanaCrearCuentaHija winCrearCuenta(this,m_wallet);
	winCrearCuenta.ShowModal();
	
}

void VentanaPrincipalHija::Click_IniciarSesion( wxCommandEvent& event )  {
	
	VentanaIniciarSesionHija winIniciarSesion(this, m_wallet);
	bool ok = winIniciarSesion.ShowModal();
	
	if(!ok){
		
		// Crea una instancia de la ventana de la wallet y la muestra
		VentanaWalletHija *winWallet = new VentanaWalletHija(m_wallet);
		winWallet->Show();
		
		// Cierra la ventana principal y sus ventanas hijas
		Close();
		
	}
	
}



