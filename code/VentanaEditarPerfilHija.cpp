#include "VentanaEditarPerfilHija.h"
#include <wx/msgdlg.h>
#include "Utils.h"
#include "Wallet.h"
#include "Herramientas.h"

VentanaEditarPerfilHija::VentanaEditarPerfilHija(wxWindow *parent, Wallet *wallet) : VentanaEditarPerfil(parent), m_wallet(wallet){
	m_email->SetValue(std_to_wx(m_wallet->VerSesionIniciada().VerEmail()));
	m_contrasenia->SetValue(std_to_wx(m_wallet->VerSesionIniciada().VerContrasena()));
	m_usuario->SetValue(std_to_wx(m_wallet->VerSesionIniciada().VerUsuario()));
}

VentanaEditarPerfilHija::~VentanaEditarPerfilHija() {
	
}


/*------------------------------------------------------------------------*/


void VentanaEditarPerfilHija::Click_Aceptar( wxCommandEvent& event )  {
	
	string cambio_email = wx_to_std( m_email->GetValue() );
	string cambio_contrasenia = wx_to_std( m_contrasenia->GetValue() );
	string cambio_nom_usuario = wx_to_std( m_usuario->GetValue() );
	
	int respuesta = wxMessageBox("¿Estás seguro de que querés editar tus datos?", "Editar datos de usuario", wxICON_EXCLAMATION | wxYES_NO);
	
	if (respuesta == wxYES) { // Si el usuario hace click en "SI"
		
		if( is_email_valid(cambio_email) and 
		   is_pass_valid(cambio_contrasenia) and 
		   is_user_valid(cambio_nom_usuario) )
		{
			// Modifica los datos del usuario que tiene la sesión iniciada
			m_wallet->VerSesionIniciada().ModificarEmail(cambio_email);
			m_wallet->VerSesionIniciada().ModificarContrasena(cambio_contrasenia);
			m_wallet->VerSesionIniciada().ModificarUsuario(cambio_nom_usuario);
			
			EndModal(0);
			
		} else {
			
			if( !is_email_valid(cambio_email) ){
				wxMessageBox("Email invalido. Ingreselo nuevamente.", "Error", wxOK|wxICON_ERROR, this);
			}
			if( !is_pass_valid(cambio_contrasenia) ){
				wxMessageBox("Contraseña invalida. Ingresela nuevamente.", "Error", wxOK|wxICON_ERROR, this);
				wxMessageBox("- Al menos 1 mayúscula\n- Al menos 1 minúscula\n- Sin espacios\n- Entre 8 y 16 caracteres\n", "Requisitos contraseña", wxOK|wxICON_EXCLAMATION, this);
			}
			if( !is_user_valid(cambio_nom_usuario) ){
				wxMessageBox("Nombre de usuario invalido. Ingreselo nuevamente.", "Error", wxOK|wxICON_ERROR, this);
				wxMessageBox("- Al menos 1 minúscula\n- Sin espacios\n- Entre 6 y 16 caracteres\n", "Requisitos nombre de usuario", wxOK|wxICON_EXCLAMATION, this);
			}
		}
	}
}

void VentanaEditarPerfilHija::Click_Cancelar( wxCommandEvent& event )  {
	
	EndModal(0);
}

