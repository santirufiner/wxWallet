#include "VentanaIniciarSesionHija.h"
#include <wx/msgdlg.h>
#include "Application.h"
#include "Utils.h"


VentanaIniciarSesionHija::VentanaIniciarSesionHija(wxWindow *parent, Wallet *wallet) : VentanaIniciarSesion(parent), m_wallet(wallet) {
	
}

VentanaIniciarSesionHija::~VentanaIniciarSesionHija() {
	
}


/*------------------------------------------------------------------------*/


void VentanaIniciarSesionHija::Click_Ingresar( wxCommandEvent& event )  {
	
	// Si el nombre de usuario/email y/o la contraseña están vacíos, mostrar mensaje y volver a pantalla de iniciar sesión
	if( m_usuarioemail->IsEmpty() and m_contrasenia->IsEmpty() ){
		wxMessageBox("Ingrese un nombre de usuario/email y contraseña.", "Error", wxOK|wxICON_ERROR, this);
	} else {
		
		if( m_usuarioemail->IsEmpty()){
			wxMessageBox("Ingrese un nombre de usuario o email.", "Error", wxOK|wxICON_ERROR, this);
		}
		
		if( m_contrasenia->IsEmpty()){
			wxMessageBox("Ingrese una contraseña.", "Error", wxOK|wxICON_ERROR, this);
		}
	}
	
	// Buscar en el vector de Usuarios si matchean el usuario/email y la contraseña
	bool match = false;
	string Usuario_email = wx_to_std(m_usuarioemail->GetValue());
	string Contrasenia = wx_to_std(m_contrasenia->GetValue());
	match = m_wallet->IniciarSesion(Usuario_email,Contrasenia);
	if(match){ // Si matchea, quiere decir que ya se cargaron los datos del usuario desde IniciarSesion()
		EndModal(0);
	}
	if(!match){
		wxMessageBox("Usuario/email y/o contraseña incorrectos. Ingreselos nuevamente.", "Error", wxOK|wxICON_ERROR, this);
	}
}

void VentanaIniciarSesionHija::OnClickIngresar( wxCommandEvent& event )  {
	Click_Ingresar(event);
}

