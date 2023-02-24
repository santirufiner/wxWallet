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
#include <wx/stattext.h>
#include <wx/button.h>
#include <wx/sizer.h>
#include <wx/bmpbuttn.h>
#include <wx/choice.h>
#include <wx/textctrl.h>
#include <wx/propgrid/propgrid.h>
#include <wx/propgrid/manager.h>
#include <wx/propgrid/advprops.h>
#include <wx/frame.h>
#include <wx/combobox.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class VentanaPrincipal
///////////////////////////////////////////////////////////////////////////////
class VentanaPrincipal : public wxFrame
{
	private:

	protected:
		wxStaticBitmap* m_bitmap1;
		wxStaticText* m_staticText2;
		wxButton* m_button71;
		wxBitmapButton* m_bpButton1;
		wxBitmapButton* m_bpButton2;
		wxChoice* m_choice1;
		wxButton* m_button2;
		wxButton* m_button3;
		wxButton* m_button4;
		wxTextCtrl* m_textCtrl1;
		wxButton* m_button6;
		wxButton* m_button7;
		wxPropertyGridManager* m_propertyGridManager4;

	public:

		VentanaPrincipal( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("C++ wallet"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 700,700 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~VentanaPrincipal();

};

///////////////////////////////////////////////////////////////////////////////
/// Class VentanaAgregarMoneda
///////////////////////////////////////////////////////////////////////////////
class VentanaAgregarMoneda : public wxDialog
{
	private:

	protected:
		wxStaticBitmap* m_bitmap1;
		wxComboBox* m_comboBox4;

	public:

		VentanaAgregarMoneda( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Añadir Moneda"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 315,195 ), long style = wxDEFAULT_DIALOG_STYLE );

		~VentanaAgregarMoneda();

};

