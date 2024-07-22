#include "VentanaCrearCuentaHija.h"
#include "VentanaPrincipalHija.h"
#include <wx/msgdlg.h>
#include "Herramientas.h"
#include "Utils.h"
#include "Wallet.h"


VentanaCrearCuentaHija::VentanaCrearCuentaHija(wxWindow *parent, Wallet *wallet) : VentanaCrearCuenta(parent), m_wallet(wallet) {
	
}

VentanaCrearCuentaHija::~VentanaCrearCuentaHija() {
	
}


/*------------------------------------------------------------------------*/


void VentanaCrearCuentaHija::Click_CrearCuenta( wxCommandEvent& event )  {
	
	// Le pide los datos a la ventana y los transforma de wxString a string
	string email = wx_to_std(m_email->GetValue());
	string contrasenia = wx_to_std(m_contrasenia->GetValue());
	string n_usuario = wx_to_std(m_usuario->GetValue());
	
	if( ( !m_email->IsEmpty() and is_email_valid(email) ) and
		( !m_contrasenia->IsEmpty() and is_pass_valid(contrasenia) ) and
		( !m_usuario->IsEmpty() and is_user_valid(n_usuario) ) )
	{
		
		// Llama a la función de crear cuenta y le pasa los datos del Usuario
		bool existe=m_wallet->CrearCuenta(email,contrasenia,n_usuario);
		
		if(existe){ // Si el usuario no estaba ya registrado, devuelve un modal = 1
			EndModal(1);
		}else{ // Si el usuario ya estaba registrado, muestra el mensaje:
			wxMessageBox("Usuario ya existente", "Error", wxOK|wxICON_ERROR, this);
		}
	} else {
		
		// Mensajes de datos vacios
		if( m_email->IsEmpty()){
			wxMessageBox("Ingrese un email.", "Error", wxOK|wxICON_ERROR, this);
		}
		if( m_contrasenia->IsEmpty()){
			wxMessageBox("Ingrese una contraseña.", "Error", wxOK|wxICON_ERROR, this);
		}
		if( m_usuario->IsEmpty()){
			wxMessageBox("Ingrese un nombre de usuario.", "Error", wxOK|wxICON_ERROR, this);
		}
		
		// Mensajes de errores
		if( !is_email_valid(email) ){
			wxMessageBox("Email invalido. Ingreselo nuevamente.", "Error", wxOK|wxICON_ERROR, this);
		}
		if( !is_pass_valid(contrasenia) ){
			wxMessageBox("Contraseña invalida. Ingresela nuevamente.", "Error", wxOK|wxICON_ERROR, this);
			wxMessageBox("- Al menos 1 mayúscula\n- Al menos 1 minúscula\n- Sin espacios\n- Entre 8 y 16 caracteres\n", "Requisitos contraseña", wxOK|wxICON_EXCLAMATION, this);
		}
		if( !is_user_valid(n_usuario) ){
			wxMessageBox("Nombre de usuario invalido. Ingreselo nuevamente.", "Error", wxOK|wxICON_ERROR, this);
			wxMessageBox("- Al menos 1 minúscula\n- Sin espacios\n- Entre 6 y 16 caracteres\n", "Requisitos nombre de usuario", wxOK|wxICON_EXCLAMATION, this);
		}
		
	}
}
