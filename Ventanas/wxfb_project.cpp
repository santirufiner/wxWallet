///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.10.1-0-g8feb16b3)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "wxfb_project.h"

///////////////////////////////////////////////////////////////////////////

VentanaPrincipal::VentanaPrincipal( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNFACE ) );

	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxHORIZONTAL );

	m_bitmap1 = new wxStaticBitmap( this, wxID_ANY, wxBitmap( wxT("c-logo.ico"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer7->Add( m_bitmap1, 0, wxALL, 5 );

	m_staticText2 = new wxStaticText( this, wxID_ANY, wxT("Wallet"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2->Wrap( -1 );
	bSizer7->Add( m_staticText2, 1, wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM|wxRIGHT, 5 );


	bSizer7->Add( 0, 0, 14, wxEXPAND, 5 );

	m_button71 = new wxButton( this, wxID_ANY, wxT("Cerrar sesión"), wxDefaultPosition, wxDefaultSize, 0 );
	m_button71->SetLabelMarkup( wxT("Cerrar sesión") );
	bSizer7->Add( m_button71, 1, wxALL|wxALIGN_CENTER_VERTICAL|wxEXPAND, 5 );


	bSizer3->Add( bSizer7, 0, 0, 5 );


	bSizer2->Add( bSizer3, 0, 0, 5 );

	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxHORIZONTAL );


	bSizer5->Add( 0, 0, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer( wxVERTICAL );

	m_bpButton1 = new wxBitmapButton( this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|0 );
	m_bpButton1->SetLabelMarkup( wxT("MyButton") );
	m_bpButton1->SetBitmap( wxBitmap( wxT("boton-mas.png"), wxBITMAP_TYPE_ANY ) );
	m_bpButton1->SetBitmapMargins( wxSize( 0,-1 ) );
	m_bpButton1->SetBackgroundColour( wxColour( 68, 180, 92 ) );

	bSizer8->Add( m_bpButton1, 0, wxALL, 5 );

	m_bpButton2 = new wxBitmapButton( this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|0 );

	m_bpButton2->SetBitmap( wxBitmap( wxT("boton-menos.png"), wxBITMAP_TYPE_ANY ) );
	m_bpButton2->SetBackgroundColour( wxColour( 244, 68, 52 ) );

	bSizer8->Add( m_bpButton2, 0, wxALL, 5 );


	bSizer5->Add( bSizer8, 0, wxRIGHT|wxLEFT, 5 );

	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer( wxHORIZONTAL );

	wxString m_choice1Choices[] = { wxT("Peso argentino"), wxT("Dolar estadounidense"), wxT("etc") };
	int m_choice1NChoices = sizeof( m_choice1Choices ) / sizeof( wxString );
	m_choice1 = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choice1NChoices, m_choice1Choices, 0 );
	m_choice1->SetSelection( 0 );
	bSizer9->Add( m_choice1, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_button2 = new wxButton( this, wxID_ANY, wxT("Añadir Moneda"), wxDefaultPosition, wxDefaultSize, 0 );
	m_button2->SetLabelMarkup( wxT("Añadir Moneda") );
	bSizer9->Add( m_button2, 0, wxALL, 5 );


	bSizer5->Add( bSizer9, 0, wxALIGN_CENTER_VERTICAL, 5 );


	bSizer5->Add( 0, 0, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer10;
	bSizer10 = new wxBoxSizer( wxHORIZONTAL );

	m_button3 = new wxButton( this, wxID_ANY, wxT("USD"), wxDefaultPosition, wxDefaultSize, 0 );
	m_button3->SetLabelMarkup( wxT("USD") );
	bSizer10->Add( m_button3, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_button4 = new wxButton( this, wxID_ANY, wxT("ARS"), wxDefaultPosition, wxDefaultSize, 0 );
	m_button4->SetLabelMarkup( wxT("ARS") );
	bSizer10->Add( m_button4, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_textCtrl1 = new wxTextCtrl( this, wxID_ANY, wxT("usd o ars"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer10->Add( m_textCtrl1, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer5->Add( bSizer10, 1, wxEXPAND, 5 );


	bSizer5->Add( 0, 0, 1, wxEXPAND, 5 );


	bSizer2->Add( bSizer5, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer11;
	bSizer11 = new wxBoxSizer( wxHORIZONTAL );


	bSizer11->Add( 0, 0, 1, wxEXPAND, 5 );

	m_button6 = new wxButton( this, wxID_ANY, wxT("Activos"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer11->Add( m_button6, 0, wxALL, 5 );

	m_button7 = new wxButton( this, wxID_ANY, wxT("Actividad"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer11->Add( m_button7, 0, wxALL, 5 );


	bSizer11->Add( 0, 0, 1, wxEXPAND, 5 );


	bSizer6->Add( bSizer11, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer12;
	bSizer12 = new wxBoxSizer( wxVERTICAL );

	m_propertyGridManager4 = new wxPropertyGridManager(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxPGMAN_DEFAULT_STYLE);
	m_propertyGridManager4->SetExtraStyle( wxPG_EX_MODE_BUTTONS );
	bSizer12->Add( m_propertyGridManager4, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer6->Add( bSizer12, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer2->Add( bSizer6, 1, wxEXPAND, 5 );


	this->SetSizer( bSizer2 );
	this->Layout();

	this->Centre( wxBOTH );
}

VentanaPrincipal::~VentanaPrincipal()
{
}

VentanaAgregarMoneda::VentanaAgregarMoneda( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer14;
	bSizer14 = new wxBoxSizer( wxHORIZONTAL );

	m_bitmap1 = new wxStaticBitmap( this, wxID_ANY, wxBitmap( wxT("c-logo.ico"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer14->Add( m_bitmap1, 0, wxALL, 5 );

	wxBoxSizer* bSizer20;
	bSizer20 = new wxBoxSizer( wxHORIZONTAL );

	m_comboBox4 = new wxComboBox( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	m_comboBox4->Append( wxT("Bitcoin") );
	m_comboBox4->Append( wxT("Ethereum") );
	m_comboBox4->Append( wxT("Etc") );
	m_comboBox4->Append( wxEmptyString );
	bSizer20->Add( m_comboBox4, 1, wxALL, 5 );


	bSizer14->Add( bSizer20, 1, wxEXPAND|wxALIGN_CENTER_VERTICAL, 5 );


	this->SetSizer( bSizer14 );
	this->Layout();

	this->Centre( wxBOTH );
}

VentanaAgregarMoneda::~VentanaAgregarMoneda()
{
}
