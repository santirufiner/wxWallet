///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.10.1-0-g8feb16b3)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/statbmp.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/dialog.h>
#include <wx/bmpbuttn.h>
#include <wx/grid.h>
#include <wx/choice.h>
#include <wx/datectrl.h>
#include <wx/dateevt.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class VentanaPrincipal
///////////////////////////////////////////////////////////////////////////////
class VentanaPrincipal : public wxFrame
{
	private:

	protected:
		wxStaticBitmap* Clogo;
		wxButton* IniciarSesion;
		wxButton* CrearCuenta;

		// Virtual event handlers, override them in your derived class
		virtual void Click_IniciarSesion( wxCommandEvent& event ) { event.Skip(); }
		virtual void Click_CrearCuenta( wxCommandEvent& event ) { event.Skip(); }


	public:

		VentanaPrincipal( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("C++ Wallet"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 400,273 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~VentanaPrincipal();

};

///////////////////////////////////////////////////////////////////////////////
/// Class VentanaIniciarSesion
///////////////////////////////////////////////////////////////////////////////
class VentanaIniciarSesion : public wxDialog
{
	private:

	protected:
		wxStaticText* texto1;
		wxTextCtrl* m_usuarioemail;
		wxStaticText* texto2;
		wxTextCtrl* m_contrasenia;
		wxButton* Ingresar;

		// Virtual event handlers, override them in your derived class
		virtual void OnClickIngresar( wxCommandEvent& event ) { event.Skip(); }
		virtual void Click_Ingresar( wxCommandEvent& event ) { event.Skip(); }


	public:

		VentanaIniciarSesion( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("C++ Wallet: Iniciar sesion"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 300,250 ), long style = wxDEFAULT_DIALOG_STYLE );

		~VentanaIniciarSesion();

};

///////////////////////////////////////////////////////////////////////////////
/// Class VentanaCrearCuenta
///////////////////////////////////////////////////////////////////////////////
class VentanaCrearCuenta : public wxDialog
{
	private:

	protected:
		wxStaticText* texto3;
		wxStaticText* texto4;
		wxStaticText* texto5;
		wxTextCtrl* m_email;
		wxTextCtrl* m_contrasenia;
		wxTextCtrl* m_usuario;
		wxButton* CrearCuenta;

		// Virtual event handlers, override them in your derived class
		virtual void Click_CrearCuenta( wxCommandEvent& event ) { event.Skip(); }


	public:

		VentanaCrearCuenta( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("C++ Wallet: Crear cuenta"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 400,165 ), long style = wxDEFAULT_DIALOG_STYLE );

		~VentanaCrearCuenta();

};

///////////////////////////////////////////////////////////////////////////////
/// Class VentanaWallet
///////////////////////////////////////////////////////////////////////////////
class VentanaWallet : public wxFrame
{
	private:

	protected:
		wxStaticBitmap* Clogo;
		wxStaticText* texto6;
		wxButton* EditarPerfil;
		wxButton* CerrarSesion;
		wxBitmapButton* m_botonAgregar;
		wxBitmapButton* m_botonEnviar;
		wxButton* VerWallet;
		wxButton* toUSD;
		wxButton* toARS;
		wxTextCtrl* m_balancetotal;
		wxStaticText* texto8;
		wxGrid* m_grilla_activos;
		wxStaticText* texto9;
		wxChoice* m_ordenar_activos;
		wxStaticText* texto10;
		wxGrid* m_grilla_transacciones;
		wxStaticText* texto11;
		wxChoice* m_ordenar_transacciones;
		wxButton* Filtrar;

		// Virtual event handlers, override them in your derived class
		virtual void CambiarTamanio( wxSizeEvent& event ) { event.Skip(); }
		virtual void Click_EditarPerfil( wxCommandEvent& event ) { event.Skip(); }
		virtual void Click_CerrarSesion( wxCommandEvent& event ) { event.Skip(); }
		virtual void Click_BotonAgregar( wxCommandEvent& event ) { event.Skip(); }
		virtual void Click_BotonEnviar( wxCommandEvent& event ) { event.Skip(); }
		virtual void Click_VerWallet( wxCommandEvent& event ) { event.Skip(); }
		virtual void Click_toUSD( wxCommandEvent& event ) { event.Skip(); }
		virtual void Click_toARS( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickGrillaActivos( wxGridEvent& event ) { event.Skip(); }
		virtual void Click_OrdenarActivos( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickGrillaTransacciones( wxGridEvent& event ) { event.Skip(); }
		virtual void Click_OrdenarTransacciones( wxCommandEvent& event ) { event.Skip(); }
		virtual void Click_Filtrar( wxCommandEvent& event ) { event.Skip(); }


	public:

		VentanaWallet( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("C++ wallet"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 870,450 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~VentanaWallet();

};

///////////////////////////////////////////////////////////////////////////////
/// Class VentanaAgregar
///////////////////////////////////////////////////////////////////////////////
class VentanaAgregar : public wxDialog
{
	private:

	protected:
		wxStaticText* texto12;
		wxStaticText* texto13;
		wxStaticText* texto14;
		wxStaticText* texto15;
		wxStaticText* texto16;
		wxStaticText* texto17;
		wxTextCtrl* m_emisor;
		wxTextCtrl* m_receptor;
		wxDatePickerCtrl* m_date1;
		wxChoice* m_choice_moneda1;
		wxTextCtrl* m_monto;
		wxChoice* m_choice_motivo1;
		wxButton* Agregar;

		// Virtual event handlers, override them in your derived class
		virtual void Click_Agregar( wxCommandEvent& event ) { event.Skip(); }


	public:

		VentanaAgregar( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("C++ Wallet: Agregar"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 420,300 ), long style = wxDEFAULT_DIALOG_STYLE );

		~VentanaAgregar();

};

///////////////////////////////////////////////////////////////////////////////
/// Class VentanaEnviar
///////////////////////////////////////////////////////////////////////////////
class VentanaEnviar : public wxDialog
{
	private:

	protected:
		wxStaticText* texto18;
		wxStaticText* texto19;
		wxStaticText* texto20;
		wxStaticText* texto21;
		wxStaticText* texto22;
		wxStaticText* texto23;
		wxTextCtrl* m_emisor;
		wxTextCtrl* m_receptor;
		wxDatePickerCtrl* m_date2;
		wxChoice* m_choice_moneda2;
		wxTextCtrl* m_monto;
		wxChoice* m_choice_motivo2;
		wxButton* Enviar;

		// Virtual event handlers, override them in your derived class
		virtual void Click_Enviar( wxCommandEvent& event ) { event.Skip(); }


	public:

		VentanaEnviar( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("C++ Wallet: Enviar"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 420,300 ), long style = wxDEFAULT_DIALOG_STYLE );

		~VentanaEnviar();

};

///////////////////////////////////////////////////////////////////////////////
/// Class VentanaEditarPerfil
///////////////////////////////////////////////////////////////////////////////
class VentanaEditarPerfil : public wxDialog
{
	private:

	protected:
		wxStaticText* texto24;
		wxStaticText* texto25;
		wxStaticText* texto26;
		wxTextCtrl* m_email;
		wxTextCtrl* m_contrasenia;
		wxTextCtrl* m_usuario;
		wxButton* Aceptar;
		wxButton* Cancelar;

		// Virtual event handlers, override them in your derived class
		virtual void Click_Aceptar( wxCommandEvent& event ) { event.Skip(); }
		virtual void Click_Cancelar( wxCommandEvent& event ) { event.Skip(); }


	public:

		VentanaEditarPerfil( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("C++ Wallet: Editar perfil"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 400,200 ), long style = wxDEFAULT_DIALOG_STYLE );

		~VentanaEditarPerfil();

};

///////////////////////////////////////////////////////////////////////////////
/// Class VentanaFiltrar
///////////////////////////////////////////////////////////////////////////////
class VentanaFiltrar : public wxDialog
{
	private:

	protected:
		wxStaticText* texto27;
		wxStaticText* texto28;
		wxStaticText* texto29;
		wxStaticText* texto30;
		wxStaticText* texto31;
		wxChoice* m_choice_tipo_trans;
		wxChoice* m_choice_simbolo;
		wxDatePickerCtrl* m_date_desde;
		wxDatePickerCtrl* m_date_hasta;
		wxChoice* m_choice_motivo;
		wxButton* Filtrar;

		// Virtual event handlers, override them in your derived class
		virtual void Click_Filtrar( wxCommandEvent& event ) { event.Skip(); }


	public:

		VentanaFiltrar( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("C++ Wallet: Filtrar"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 400,270 ), long style = wxDEFAULT_DIALOG_STYLE );

		~VentanaFiltrar();

};

///////////////////////////////////////////////////////////////////////////////
/// Class VentanaVerAddress
///////////////////////////////////////////////////////////////////////////////
class VentanaVerAddress : public wxDialog
{
	private:

	protected:
		wxStaticText* texto32;
		wxTextCtrl* m_mostrarAddress;

	public:

		VentanaVerAddress( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Ver Wallet"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 427,107 ), long style = wxDEFAULT_DIALOG_STYLE );

		~VentanaVerAddress();

};

