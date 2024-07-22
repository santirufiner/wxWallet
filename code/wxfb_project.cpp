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
	this->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_3DLIGHT ) );

	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxHORIZONTAL );

	Clogo = new wxStaticBitmap( this, wxID_ANY, wxBitmap( wxT("resources/c-logo(64px).png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( Clogo, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );


	bSizer1->Add( bSizer2, 1, wxALIGN_CENTER_HORIZONTAL, 5 );

	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxHORIZONTAL );

	IniciarSesion = new wxButton( this, wxID_ANY, wxT("Iniciar sesión"), wxDefaultPosition, wxSize( 150,50 ), 0 );
	IniciarSesion->SetFont( wxFont( 9, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Arial") ) );

	bSizer3->Add( IniciarSesion, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer1->Add( bSizer3, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxHORIZONTAL );

	CrearCuenta = new wxButton( this, wxID_ANY, wxT("Crear cuenta"), wxDefaultPosition, wxSize( 150,50 ), 0 );
	CrearCuenta->SetFont( wxFont( 9, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Arial") ) );

	bSizer4->Add( CrearCuenta, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer1->Add( bSizer4, 0, wxEXPAND, 5 );


	this->SetSizer( bSizer1 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	IniciarSesion->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaPrincipal::Click_IniciarSesion ), NULL, this );
	CrearCuenta->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaPrincipal::Click_CrearCuenta ), NULL, this );
}

VentanaPrincipal::~VentanaPrincipal()
{
	// Disconnect Events
	IniciarSesion->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaPrincipal::Click_IniciarSesion ), NULL, this );
	CrearCuenta->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaPrincipal::Click_CrearCuenta ), NULL, this );

}

VentanaIniciarSesion::VentanaIniciarSesion( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 300,250 ), wxSize( 300,250 ) );
	this->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_3DLIGHT ) );

	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxVERTICAL );


	bSizer5->Add( 0, 0, 1, 0, 5 );

	texto1 = new wxStaticText( this, wxID_ANY, wxT("Nombre de usuario o email:"), wxDefaultPosition, wxDefaultSize, 0 );
	texto1->Wrap( -1 );
	texto1->SetFont( wxFont( 10, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Arial") ) );

	bSizer5->Add( texto1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	m_usuarioemail = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 150,25 ), 0 );
	m_usuarioemail->SetMinSize( wxSize( 150,25 ) );
	m_usuarioemail->SetMaxSize( wxSize( 150,25 ) );

	bSizer5->Add( m_usuarioemail, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	texto2 = new wxStaticText( this, wxID_ANY, wxT("Contraseña:"), wxDefaultPosition, wxDefaultSize, 0 );
	texto2->Wrap( -1 );
	texto2->SetFont( wxFont( 10, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Arial") ) );

	bSizer5->Add( texto2, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	m_contrasenia = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 150,25 ), wxTE_PROCESS_ENTER );
	m_contrasenia->SetMinSize( wxSize( 150,25 ) );
	m_contrasenia->SetMaxSize( wxSize( 150,25 ) );

	bSizer5->Add( m_contrasenia, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	Ingresar = new wxButton( this, wxID_ANY, wxT("Ingresar"), wxDefaultPosition, wxSize( 100,30 ), 0 );
	Ingresar->SetFont( wxFont( 9, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Arial") ) );

	bSizer5->Add( Ingresar, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer5->Add( 0, 0, 1, 0, 5 );


	this->SetSizer( bSizer5 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	m_contrasenia->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( VentanaIniciarSesion::OnClickIngresar ), NULL, this );
	Ingresar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaIniciarSesion::Click_Ingresar ), NULL, this );
}

VentanaIniciarSesion::~VentanaIniciarSesion()
{
	// Disconnect Events
	m_contrasenia->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( VentanaIniciarSesion::OnClickIngresar ), NULL, this );
	Ingresar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaIniciarSesion::Click_Ingresar ), NULL, this );

}

VentanaCrearCuenta::VentanaCrearCuenta( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_3DLIGHT ) );

	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer( wxVERTICAL );

	texto3 = new wxStaticText( this, wxID_ANY, wxT("Ingresá tu email:"), wxDefaultPosition, wxDefaultSize, 0 );
	texto3->Wrap( -1 );
	bSizer8->Add( texto3, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer8->Add( 0, 0, 1, wxALIGN_CENTER_HORIZONTAL, 5 );

	texto4 = new wxStaticText( this, wxID_ANY, wxT("Ingresá una contraseña:"), wxDefaultPosition, wxDefaultSize, 0 );
	texto4->Wrap( -1 );
	bSizer8->Add( texto4, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer8->Add( 0, 0, 1, wxALIGN_CENTER_HORIZONTAL, 5 );

	texto5 = new wxStaticText( this, wxID_ANY, wxT("Ingresá un nombre de usuario:"), wxDefaultPosition, wxDefaultSize, 0 );
	texto5->Wrap( -1 );
	bSizer8->Add( texto5, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer7->Add( bSizer8, 1, wxALL, 5 );

	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer( wxVERTICAL );

	m_email = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer9->Add( m_email, 0, wxEXPAND|wxTOP|wxRIGHT|wxLEFT, 5 );


	bSizer9->Add( 0, 0, 0, 0, 5 );

	m_contrasenia = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer9->Add( m_contrasenia, 0, wxEXPAND|wxTOP|wxRIGHT|wxLEFT, 5 );


	bSizer9->Add( 0, 0, 0, 0, 5 );

	m_usuario = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer9->Add( m_usuario, 0, wxALL|wxEXPAND, 5 );


	bSizer7->Add( bSizer9, 1, 0, 5 );


	bSizer6->Add( bSizer7, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	wxBoxSizer* bSizer10;
	bSizer10 = new wxBoxSizer( wxHORIZONTAL );

	CrearCuenta = new wxButton( this, wxID_ANY, wxT("Crear cuenta"), wxDefaultPosition, wxSize( 100,30 ), 0 );
	CrearCuenta->SetFont( wxFont( 9, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Arial") ) );

	bSizer10->Add( CrearCuenta, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer6->Add( bSizer10, 0, wxALIGN_CENTER_HORIZONTAL, 5 );


	this->SetSizer( bSizer6 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	CrearCuenta->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaCrearCuenta::Click_CrearCuenta ), NULL, this );
}

VentanaCrearCuenta::~VentanaCrearCuenta()
{
	// Disconnect Events
	CrearCuenta->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaCrearCuenta::Click_CrearCuenta ), NULL, this );

}

VentanaWallet::VentanaWallet( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_3DLIGHT ) );

	wxBoxSizer* bSizer11;
	bSizer11 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer12;
	bSizer12 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer13;
	bSizer13 = new wxBoxSizer( wxHORIZONTAL );

	Clogo = new wxStaticBitmap( this, wxID_ANY, wxBitmap( wxT("resources/c-logo.ico"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer13->Add( Clogo, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	texto6 = new wxStaticText( this, wxID_ANY, wxT("Wallet"), wxDefaultPosition, wxDefaultSize, 0 );
	texto6->Wrap( -1 );
	texto6->SetFont( wxFont( 9, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Arial") ) );

	bSizer13->Add( texto6, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer13->Add( 0, 0, 1, wxALIGN_CENTER_VERTICAL, 5 );

	EditarPerfil = new wxButton( this, wxID_ANY, wxT("Editar perfil"), wxDefaultPosition, wxSize( 100,30 ), 0 );
	bSizer13->Add( EditarPerfil, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	CerrarSesion = new wxButton( this, wxID_ANY, wxT("Cerrar sesión"), wxDefaultPosition, wxSize( 100,30 ), 0 );
	bSizer13->Add( CerrarSesion, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer12->Add( bSizer13, 1, wxALIGN_CENTER_VERTICAL, 5 );


	bSizer11->Add( bSizer12, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer14;
	bSizer14 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer15;
	bSizer15 = new wxBoxSizer( wxHORIZONTAL );


	bSizer15->Add( 0, 0, 1, wxEXPAND, 5 );

	m_botonAgregar = new wxBitmapButton( this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|0 );

	m_botonAgregar->SetBitmap( wxBitmap( wxT("resources/boton-mas.png"), wxBITMAP_TYPE_ANY ) );
	m_botonAgregar->SetBitmapMargins( wxSize( 0,-1 ) );
	m_botonAgregar->SetBackgroundColour( wxColour( 68, 180, 92 ) );

	bSizer15->Add( m_botonAgregar, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_botonEnviar = new wxBitmapButton( this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|0 );

	m_botonEnviar->SetBitmap( wxBitmap( wxT("resources/boton-menos.png"), wxBITMAP_TYPE_ANY ) );
	m_botonEnviar->SetBackgroundColour( wxColour( 244, 68, 52 ) );

	bSizer15->Add( m_botonEnviar, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	VerWallet = new wxButton( this, wxID_ANY, wxT("Ver Wallet"), wxDefaultPosition, wxSize( 100,30 ), 0 );
	bSizer15->Add( VerWallet, 0, wxALL, 5 );


	bSizer15->Add( 0, 0, 1, wxEXPAND, 5 );


	bSizer14->Add( bSizer15, 1, wxRIGHT|wxLEFT|wxALIGN_BOTTOM, 5 );

	wxBoxSizer* bSizer16;
	bSizer16 = new wxBoxSizer( wxHORIZONTAL );


	bSizer16->Add( 0, 0, 1, wxEXPAND, 5 );

	toUSD = new wxButton( this, wxID_ANY, wxT("USD"), wxDefaultPosition, wxDefaultSize, 0 );
	toUSD->SetLabelMarkup( wxT("USD") );
	bSizer16->Add( toUSD, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	toARS = new wxButton( this, wxID_ANY, wxT("ARS"), wxDefaultPosition, wxDefaultSize, 0 );
	toARS->SetLabelMarkup( wxT("ARS") );
	bSizer16->Add( toARS, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_balancetotal = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 150,-1 ), wxTE_READONLY );
	m_balancetotal->Enable( false );

	bSizer16->Add( m_balancetotal, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );


	bSizer16->Add( 0, 0, 1, wxEXPAND, 5 );


	bSizer14->Add( bSizer16, 1, wxEXPAND, 5 );


	bSizer11->Add( bSizer14, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer17;
	bSizer17 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer18;
	bSizer18 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer19;
	bSizer19 = new wxBoxSizer( wxVERTICAL );

	texto8 = new wxStaticText( this, wxID_ANY, wxT("ACTIVOS"), wxDefaultPosition, wxDefaultSize, 0 );
	texto8->Wrap( -1 );
	texto8->SetFont( wxFont( 9, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Arial") ) );

	bSizer19->Add( texto8, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	m_grilla_activos = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );

	// Grid
	m_grilla_activos->CreateGrid( 0, 4 );
	m_grilla_activos->EnableEditing( false );
	m_grilla_activos->EnableGridLines( true );
	m_grilla_activos->EnableDragGridSize( false );
	m_grilla_activos->SetMargins( 0, 0 );

	// Columns
	m_grilla_activos->SetColSize( 0, 87 );
	m_grilla_activos->SetColSize( 1, 87 );
	m_grilla_activos->SetColSize( 2, 87 );
	m_grilla_activos->SetColSize( 3, 87 );
	m_grilla_activos->EnableDragColMove( false );
	m_grilla_activos->EnableDragColSize( true );
	m_grilla_activos->SetColLabelValue( 0, wxT("Moneda") );
	m_grilla_activos->SetColLabelValue( 1, wxT("Balance") );
	m_grilla_activos->SetColLabelValue( 2, wxT("En ARS") );
	m_grilla_activos->SetColLabelValue( 3, wxT("En USD") );
	m_grilla_activos->SetColLabelSize( 30 );
	m_grilla_activos->SetColLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Rows
	m_grilla_activos->AutoSizeRows();
	m_grilla_activos->EnableDragRowSize( false );
	m_grilla_activos->SetRowLabelSize( 1 );
	m_grilla_activos->SetRowLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Label Appearance

	// Cell Defaults
	m_grilla_activos->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	bSizer19->Add( m_grilla_activos, 0, wxALL, 5 );

	wxBoxSizer* bSizer20;
	bSizer20 = new wxBoxSizer( wxHORIZONTAL );

	texto9 = new wxStaticText( this, wxID_ANY, wxT("Ordenar por:"), wxDefaultPosition, wxDefaultSize, 0 );
	texto9->Wrap( -1 );
	bSizer20->Add( texto9, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM|wxRIGHT, 5 );

	wxString m_ordenar_activosChoices[] = { wxT("Balance: Mayor a menor"), wxT("Balance: Menor a mayor"), wxT("Moneda: A a Z"), wxT("Moneda: Z a A") };
	int m_ordenar_activosNChoices = sizeof( m_ordenar_activosChoices ) / sizeof( wxString );
	m_ordenar_activos = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_ordenar_activosNChoices, m_ordenar_activosChoices, 0 );
	m_ordenar_activos->SetSelection( 0 );
	bSizer20->Add( m_ordenar_activos, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer20->Add( 0, 0, 1, wxEXPAND, 5 );


	bSizer19->Add( bSizer20, 0, wxALL|wxEXPAND, 5 );


	bSizer18->Add( bSizer19, 1, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizer21;
	bSizer21 = new wxBoxSizer( wxVERTICAL );

	texto10 = new wxStaticText( this, wxID_ANY, wxT("TRANSACCIONES"), wxDefaultPosition, wxDefaultSize, 0 );
	texto10->Wrap( -1 );
	texto10->SetFont( wxFont( 9, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Arial") ) );

	bSizer21->Add( texto10, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	m_grilla_transacciones = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );

	// Grid
	m_grilla_transacciones->CreateGrid( 0, 5 );
	m_grilla_transacciones->EnableEditing( false );
	m_grilla_transacciones->EnableGridLines( true );
	m_grilla_transacciones->EnableDragGridSize( false );
	m_grilla_transacciones->SetMargins( 0, 0 );

	// Columns
	m_grilla_transacciones->SetColSize( 0, 70 );
	m_grilla_transacciones->SetColSize( 1, 70 );
	m_grilla_transacciones->SetColSize( 2, 70 );
	m_grilla_transacciones->SetColSize( 3, 70 );
	m_grilla_transacciones->SetColSize( 4, 70 );
	m_grilla_transacciones->EnableDragColMove( false );
	m_grilla_transacciones->EnableDragColSize( true );
	m_grilla_transacciones->SetColLabelValue( 0, wxT("Fecha") );
	m_grilla_transacciones->SetColLabelValue( 1, wxT("Tipo") );
	m_grilla_transacciones->SetColLabelValue( 2, wxT("Moneda") );
	m_grilla_transacciones->SetColLabelValue( 3, wxT("Monto") );
	m_grilla_transacciones->SetColLabelValue( 4, wxT("Motivo") );
	m_grilla_transacciones->SetColLabelSize( 30 );
	m_grilla_transacciones->SetColLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Rows
	m_grilla_transacciones->EnableDragRowSize( true );
	m_grilla_transacciones->SetRowLabelSize( 1 );
	m_grilla_transacciones->SetRowLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Label Appearance

	// Cell Defaults
	m_grilla_transacciones->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	bSizer21->Add( m_grilla_transacciones, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	wxBoxSizer* bSizer22;
	bSizer22 = new wxBoxSizer( wxHORIZONTAL );

	texto11 = new wxStaticText( this, wxID_ANY, wxT("Ordenar por:"), wxDefaultPosition, wxDefaultSize, 0 );
	texto11->Wrap( -1 );
	bSizer22->Add( texto11, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	wxString m_ordenar_transaccionesChoices[] = { wxT("Fecha: Mayor a menor"), wxT("Fecha: Menor a mayor"), wxT("Monto maximo"), wxT("Monto minimo"), wxT("Motivo: A a Z"), wxT("Motivo: Z a A") };
	int m_ordenar_transaccionesNChoices = sizeof( m_ordenar_transaccionesChoices ) / sizeof( wxString );
	m_ordenar_transacciones = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_ordenar_transaccionesNChoices, m_ordenar_transaccionesChoices, 0 );
	m_ordenar_transacciones->SetSelection( 4 );
	bSizer22->Add( m_ordenar_transacciones, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );


	bSizer22->Add( 0, 0, 1, wxEXPAND, 5 );

	Filtrar = new wxButton( this, wxID_ANY, wxT("Filtrar"), wxDefaultPosition, wxSize( 100,25 ), 0 );
	bSizer22->Add( Filtrar, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM|wxLEFT, 5 );


	bSizer21->Add( bSizer22, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer18->Add( bSizer21, 1, wxALL|wxEXPAND, 5 );


	bSizer17->Add( bSizer18, 1, wxALL|wxEXPAND, 5 );


	bSizer11->Add( bSizer17, 1, wxEXPAND|wxALL, 5 );


	this->SetSizer( bSizer11 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	this->Connect( wxEVT_SIZE, wxSizeEventHandler( VentanaWallet::CambiarTamanio ) );
	EditarPerfil->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaWallet::Click_EditarPerfil ), NULL, this );
	CerrarSesion->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaWallet::Click_CerrarSesion ), NULL, this );
	m_botonAgregar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaWallet::Click_BotonAgregar ), NULL, this );
	m_botonEnviar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaWallet::Click_BotonEnviar ), NULL, this );
	VerWallet->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaWallet::Click_VerWallet ), NULL, this );
	toUSD->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaWallet::Click_toUSD ), NULL, this );
	toARS->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaWallet::Click_toARS ), NULL, this );
	m_grilla_activos->Connect( wxEVT_GRID_LABEL_LEFT_CLICK, wxGridEventHandler( VentanaWallet::ClickGrillaActivos ), NULL, this );
	m_ordenar_activos->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( VentanaWallet::Click_OrdenarActivos ), NULL, this );
	m_grilla_transacciones->Connect( wxEVT_GRID_LABEL_LEFT_CLICK, wxGridEventHandler( VentanaWallet::ClickGrillaTransacciones ), NULL, this );
	m_ordenar_transacciones->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( VentanaWallet::Click_OrdenarTransacciones ), NULL, this );
	Filtrar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaWallet::Click_Filtrar ), NULL, this );
}

VentanaWallet::~VentanaWallet()
{
	// Disconnect Events
	this->Disconnect( wxEVT_SIZE, wxSizeEventHandler( VentanaWallet::CambiarTamanio ) );
	EditarPerfil->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaWallet::Click_EditarPerfil ), NULL, this );
	CerrarSesion->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaWallet::Click_CerrarSesion ), NULL, this );
	m_botonAgregar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaWallet::Click_BotonAgregar ), NULL, this );
	m_botonEnviar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaWallet::Click_BotonEnviar ), NULL, this );
	VerWallet->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaWallet::Click_VerWallet ), NULL, this );
	toUSD->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaWallet::Click_toUSD ), NULL, this );
	toARS->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaWallet::Click_toARS ), NULL, this );
	m_grilla_activos->Disconnect( wxEVT_GRID_LABEL_LEFT_CLICK, wxGridEventHandler( VentanaWallet::ClickGrillaActivos ), NULL, this );
	m_ordenar_activos->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( VentanaWallet::Click_OrdenarActivos ), NULL, this );
	m_grilla_transacciones->Disconnect( wxEVT_GRID_LABEL_LEFT_CLICK, wxGridEventHandler( VentanaWallet::ClickGrillaTransacciones ), NULL, this );
	m_ordenar_transacciones->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( VentanaWallet::Click_OrdenarTransacciones ), NULL, this );
	Filtrar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaWallet::Click_Filtrar ), NULL, this );

}

VentanaAgregar::VentanaAgregar( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 420,300 ), wxSize( 420,300 ) );
	this->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_3DLIGHT ) );

	wxBoxSizer* bSizer23;
	bSizer23 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer24;
	bSizer24 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer25;
	bSizer25 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer26;
	bSizer26 = new wxBoxSizer( wxVERTICAL );

	texto12 = new wxStaticText( this, wxID_ANY, wxT("Wallet emisor:"), wxDefaultPosition, wxDefaultSize, 0 );
	texto12->Wrap( -1 );
	bSizer26->Add( texto12, 1, wxALL|wxEXPAND, 5 );

	texto13 = new wxStaticText( this, wxID_ANY, wxT("Wallet receptor:"), wxDefaultPosition, wxDefaultSize, 0 );
	texto13->Wrap( -1 );
	bSizer26->Add( texto13, 1, wxALL|wxEXPAND, 5 );

	texto14 = new wxStaticText( this, wxID_ANY, wxT("Fecha:"), wxDefaultPosition, wxDefaultSize, 0 );
	texto14->Wrap( -1 );
	bSizer26->Add( texto14, 1, wxALL|wxEXPAND, 5 );

	texto15 = new wxStaticText( this, wxID_ANY, wxT("Moneda:"), wxDefaultPosition, wxDefaultSize, 0 );
	texto15->Wrap( -1 );
	bSizer26->Add( texto15, 1, wxALL|wxEXPAND, 5 );

	texto16 = new wxStaticText( this, wxID_ANY, wxT("Monto:"), wxDefaultPosition, wxDefaultSize, 0 );
	texto16->Wrap( -1 );
	bSizer26->Add( texto16, 1, wxALL|wxEXPAND, 5 );

	texto17 = new wxStaticText( this, wxID_ANY, wxT("Motivo:"), wxDefaultPosition, wxDefaultSize, 0 );
	texto17->Wrap( -1 );
	bSizer26->Add( texto17, 1, wxALL|wxEXPAND, 5 );


	bSizer25->Add( bSizer26, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer27;
	bSizer27 = new wxBoxSizer( wxVERTICAL );

	m_emisor = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	bSizer27->Add( m_emisor, 1, wxEXPAND|wxALL, 5 );

	m_receptor = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	bSizer27->Add( m_receptor, 1, wxALL|wxEXPAND, 5 );

	m_date1 = new wxDatePickerCtrl( this, wxID_ANY, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxDP_DEFAULT );
	m_date1->Enable( false );

	bSizer27->Add( m_date1, 1, wxALL|wxEXPAND, 5 );

	wxString m_choice_moneda1Choices[] = { wxT("ARS"), wxT("USD"), wxT("BTC"), wxT("ETH"), wxT("CPP") };
	int m_choice_moneda1NChoices = sizeof( m_choice_moneda1Choices ) / sizeof( wxString );
	m_choice_moneda1 = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choice_moneda1NChoices, m_choice_moneda1Choices, 0 );
	m_choice_moneda1->SetSelection( 0 );
	bSizer27->Add( m_choice_moneda1, 1, wxALL|wxEXPAND, 5 );

	m_monto = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer27->Add( m_monto, 1, wxALL|wxEXPAND, 5 );

	wxString m_choice_motivo1Choices[] = { wxT("Alquiler"), wxT("Cuotas"), wxT("Expensas"), wxT("Facturas"), wxT("Honorarios"), wxT("Préstamo"), wxT("Varios") };
	int m_choice_motivo1NChoices = sizeof( m_choice_motivo1Choices ) / sizeof( wxString );
	m_choice_motivo1 = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choice_motivo1NChoices, m_choice_motivo1Choices, 0 );
	m_choice_motivo1->SetSelection( 0 );
	bSizer27->Add( m_choice_motivo1, 1, wxALL|wxEXPAND, 5 );


	bSizer25->Add( bSizer27, 1, 0, 5 );


	bSizer24->Add( bSizer25, 0, wxTOP|wxRIGHT|wxLEFT|wxEXPAND, 5 );

	wxBoxSizer* bSizer28;
	bSizer28 = new wxBoxSizer( wxVERTICAL );


	bSizer28->Add( 0, 0, 1, wxEXPAND, 5 );

	Agregar = new wxButton( this, wxID_ANY, wxT("Agregar"), wxDefaultPosition, wxSize( 100,30 ), 0 );
	Agregar->SetFont( wxFont( 9, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Arial") ) );
	Agregar->SetForegroundColour( wxColour( 255, 255, 255 ) );
	Agregar->SetBackgroundColour( wxColour( 68, 180, 92 ) );
	Agregar->SetMinSize( wxSize( 100,30 ) );
	Agregar->SetMaxSize( wxSize( 100,30 ) );

	bSizer28->Add( Agregar, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer28->Add( 0, 0, 1, wxEXPAND, 5 );


	bSizer24->Add( bSizer28, 1, wxALL|wxEXPAND, 5 );


	bSizer23->Add( bSizer24, 0, wxEXPAND|wxTOP|wxRIGHT|wxLEFT, 5 );


	this->SetSizer( bSizer23 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	Agregar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaAgregar::Click_Agregar ), NULL, this );
}

VentanaAgregar::~VentanaAgregar()
{
	// Disconnect Events
	Agregar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaAgregar::Click_Agregar ), NULL, this );

}

VentanaEnviar::VentanaEnviar( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 420,300 ), wxSize( 420,300 ) );
	this->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_3DLIGHT ) );

	wxBoxSizer* bSizer29;
	bSizer29 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer30;
	bSizer30 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer31;
	bSizer31 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer32;
	bSizer32 = new wxBoxSizer( wxVERTICAL );

	texto18 = new wxStaticText( this, wxID_ANY, wxT("Wallet emisor:"), wxDefaultPosition, wxDefaultSize, 0 );
	texto18->Wrap( -1 );
	bSizer32->Add( texto18, 1, wxALL|wxEXPAND, 5 );

	texto19 = new wxStaticText( this, wxID_ANY, wxT("Wallet receptor:"), wxDefaultPosition, wxDefaultSize, 0 );
	texto19->Wrap( -1 );
	bSizer32->Add( texto19, 1, wxALL|wxEXPAND, 5 );

	texto20 = new wxStaticText( this, wxID_ANY, wxT("Fecha:"), wxDefaultPosition, wxDefaultSize, 0 );
	texto20->Wrap( -1 );
	bSizer32->Add( texto20, 1, wxALL|wxEXPAND, 5 );

	texto21 = new wxStaticText( this, wxID_ANY, wxT("Moneda:"), wxDefaultPosition, wxDefaultSize, 0 );
	texto21->Wrap( -1 );
	bSizer32->Add( texto21, 1, wxALL|wxEXPAND, 5 );

	texto22 = new wxStaticText( this, wxID_ANY, wxT("Monto:"), wxDefaultPosition, wxDefaultSize, 0 );
	texto22->Wrap( -1 );
	bSizer32->Add( texto22, 1, wxALL|wxEXPAND, 5 );

	texto23 = new wxStaticText( this, wxID_ANY, wxT("Motivo:"), wxDefaultPosition, wxDefaultSize, 0 );
	texto23->Wrap( -1 );
	bSizer32->Add( texto23, 1, wxALL|wxEXPAND, 5 );


	bSizer31->Add( bSizer32, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer33;
	bSizer33 = new wxBoxSizer( wxVERTICAL );

	m_emisor = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	bSizer33->Add( m_emisor, 1, wxEXPAND|wxALL, 5 );

	m_receptor = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer33->Add( m_receptor, 1, wxALL|wxEXPAND, 5 );

	m_date2 = new wxDatePickerCtrl( this, wxID_ANY, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxDP_DEFAULT );
	m_date2->Enable( false );

	bSizer33->Add( m_date2, 0, wxALL|wxEXPAND, 5 );

	wxString m_choice_moneda2Choices[] = { wxT("ARS"), wxT("USD"), wxT("BTC"), wxT("ETH"), wxT("CPP") };
	int m_choice_moneda2NChoices = sizeof( m_choice_moneda2Choices ) / sizeof( wxString );
	m_choice_moneda2 = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choice_moneda2NChoices, m_choice_moneda2Choices, 0 );
	m_choice_moneda2->SetSelection( 0 );
	bSizer33->Add( m_choice_moneda2, 1, wxALL|wxEXPAND, 5 );

	m_monto = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer33->Add( m_monto, 1, wxALL|wxEXPAND, 5 );

	wxString m_choice_motivo2Choices[] = { wxT("Alquiler"), wxT("Cuotas"), wxT("Expensas"), wxT("Facturas"), wxT("Honorarios"), wxT("Préstamo"), wxT("Varios") };
	int m_choice_motivo2NChoices = sizeof( m_choice_motivo2Choices ) / sizeof( wxString );
	m_choice_motivo2 = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choice_motivo2NChoices, m_choice_motivo2Choices, 0 );
	m_choice_motivo2->SetSelection( 0 );
	bSizer33->Add( m_choice_motivo2, 1, wxALL|wxEXPAND, 5 );


	bSizer31->Add( bSizer33, 1, 0, 5 );


	bSizer30->Add( bSizer31, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer34;
	bSizer34 = new wxBoxSizer( wxVERTICAL );


	bSizer34->Add( 0, 0, 1, wxEXPAND, 5 );

	Enviar = new wxButton( this, wxID_ANY, wxT("Enviar"), wxDefaultPosition, wxSize( 100,30 ), 0 );
	Enviar->SetFont( wxFont( 9, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Arial") ) );
	Enviar->SetForegroundColour( wxColour( 255, 255, 255 ) );
	Enviar->SetBackgroundColour( wxColour( 244, 68, 52 ) );
	Enviar->SetMinSize( wxSize( 100,30 ) );
	Enviar->SetMaxSize( wxSize( 100,30 ) );

	bSizer34->Add( Enviar, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer34->Add( 0, 0, 1, wxEXPAND, 5 );


	bSizer30->Add( bSizer34, 1, wxEXPAND, 5 );


	bSizer29->Add( bSizer30, 1, wxEXPAND|wxALL, 5 );


	this->SetSizer( bSizer29 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	Enviar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaEnviar::Click_Enviar ), NULL, this );
}

VentanaEnviar::~VentanaEnviar()
{
	// Disconnect Events
	Enviar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaEnviar::Click_Enviar ), NULL, this );

}

VentanaEditarPerfil::VentanaEditarPerfil( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_3DLIGHT ) );

	wxBoxSizer* bSizer35;
	bSizer35 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer36;
	bSizer36 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer37;
	bSizer37 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer38;
	bSizer38 = new wxBoxSizer( wxVERTICAL );


	bSizer38->Add( 0, 0, 1, wxEXPAND, 5 );

	texto24 = new wxStaticText( this, wxID_ANY, wxT("Email:"), wxDefaultPosition, wxDefaultSize, 0 );
	texto24->Wrap( -1 );
	bSizer38->Add( texto24, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	texto25 = new wxStaticText( this, wxID_ANY, wxT("Contraseña:"), wxDefaultPosition, wxDefaultSize, 0 );
	texto25->Wrap( -1 );
	bSizer38->Add( texto25, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	texto26 = new wxStaticText( this, wxID_ANY, wxT("Nombre de usuario:"), wxDefaultPosition, wxDefaultSize, 0 );
	texto26->Wrap( -1 );
	bSizer38->Add( texto26, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer38->Add( 0, 0, 1, wxEXPAND, 5 );


	bSizer37->Add( bSizer38, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	wxBoxSizer* bSizer39;
	bSizer39 = new wxBoxSizer( wxVERTICAL );


	bSizer39->Add( 0, 0, 1, wxEXPAND, 5 );

	m_email = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer39->Add( m_email, 0, wxALL|wxEXPAND, 5 );

	m_contrasenia = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer39->Add( m_contrasenia, 0, wxALL|wxEXPAND, 5 );

	m_usuario = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer39->Add( m_usuario, 0, wxALL|wxEXPAND, 5 );


	bSizer39->Add( 0, 0, 1, wxEXPAND, 5 );


	bSizer37->Add( bSizer39, 1, wxALL|wxEXPAND, 5 );


	bSizer36->Add( bSizer37, 1, wxEXPAND|wxALL, 5 );

	wxBoxSizer* bSizer40;
	bSizer40 = new wxBoxSizer( wxHORIZONTAL );


	bSizer40->Add( 0, 0, 1, wxEXPAND, 5 );

	Aceptar = new wxButton( this, wxID_ANY, wxT("Aceptar"), wxDefaultPosition, wxSize( 100,30 ), 0 );
	Aceptar->SetFont( wxFont( 9, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Arial") ) );

	bSizer40->Add( Aceptar, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	Cancelar = new wxButton( this, wxID_ANY, wxT("Cancelar"), wxDefaultPosition, wxSize( 100,30 ), 0 );
	Cancelar->SetFont( wxFont( 9, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Arial") ) );

	bSizer40->Add( Cancelar, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer40->Add( 0, 0, 1, wxEXPAND, 5 );


	bSizer36->Add( bSizer40, 1, wxALL|wxEXPAND, 5 );


	bSizer35->Add( bSizer36, 1, wxEXPAND|wxALL, 5 );


	this->SetSizer( bSizer35 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	Aceptar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaEditarPerfil::Click_Aceptar ), NULL, this );
	Cancelar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaEditarPerfil::Click_Cancelar ), NULL, this );
}

VentanaEditarPerfil::~VentanaEditarPerfil()
{
	// Disconnect Events
	Aceptar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaEditarPerfil::Click_Aceptar ), NULL, this );
	Cancelar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaEditarPerfil::Click_Cancelar ), NULL, this );

}

VentanaFiltrar::VentanaFiltrar( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_3DLIGHT ) );

	wxBoxSizer* bSizer41;
	bSizer41 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer42;
	bSizer42 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer43;
	bSizer43 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer44;
	bSizer44 = new wxBoxSizer( wxVERTICAL );

	texto27 = new wxStaticText( this, wxID_ANY, wxT("Tipo de transacción:"), wxDefaultPosition, wxDefaultSize, 0 );
	texto27->Wrap( -1 );
	bSizer44->Add( texto27, 1, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );

	texto28 = new wxStaticText( this, wxID_ANY, wxT("Moneda:"), wxDefaultPosition, wxDefaultSize, 0 );
	texto28->Wrap( -1 );
	bSizer44->Add( texto28, 1, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	texto29 = new wxStaticText( this, wxID_ANY, wxT("Fecha desde:"), wxDefaultPosition, wxDefaultSize, 0 );
	texto29->Wrap( -1 );
	bSizer44->Add( texto29, 1, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );

	texto30 = new wxStaticText( this, wxID_ANY, wxT("Fecha hasta:"), wxDefaultPosition, wxDefaultSize, 0 );
	texto30->Wrap( -1 );
	bSizer44->Add( texto30, 1, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );

	texto31 = new wxStaticText( this, wxID_ANY, wxT("Motivo:"), wxDefaultPosition, wxDefaultSize, 0 );
	texto31->Wrap( -1 );
	bSizer44->Add( texto31, 1, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer43->Add( bSizer44, 0, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizer45;
	bSizer45 = new wxBoxSizer( wxVERTICAL );

	wxString m_choice_tipo_transChoices[] = { wxT("-"), wxT("Ingreso"), wxT("Egreso") };
	int m_choice_tipo_transNChoices = sizeof( m_choice_tipo_transChoices ) / sizeof( wxString );
	m_choice_tipo_trans = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choice_tipo_transNChoices, m_choice_tipo_transChoices, 0 );
	m_choice_tipo_trans->SetSelection( 0 );
	bSizer45->Add( m_choice_tipo_trans, 0, wxALL|wxEXPAND, 5 );

	wxString m_choice_simboloChoices[] = { wxT("-"), wxT("ARS"), wxT("USD"), wxT("BTC"), wxT("ETH"), wxT("CPP") };
	int m_choice_simboloNChoices = sizeof( m_choice_simboloChoices ) / sizeof( wxString );
	m_choice_simbolo = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choice_simboloNChoices, m_choice_simboloChoices, 0 );
	m_choice_simbolo->SetSelection( 0 );
	bSizer45->Add( m_choice_simbolo, 0, wxALL|wxEXPAND, 5 );

	m_date_desde = new wxDatePickerCtrl( this, wxID_ANY, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxDP_DEFAULT );
	bSizer45->Add( m_date_desde, 0, wxALL|wxEXPAND, 5 );

	m_date_hasta = new wxDatePickerCtrl( this, wxID_ANY, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxDP_DEFAULT );
	bSizer45->Add( m_date_hasta, 0, wxALL|wxEXPAND, 5 );

	wxString m_choice_motivoChoices[] = { wxT("-"), wxT("Alquiler"), wxT("Cuotas"), wxT("Expensas"), wxT("Facturas"), wxT("Honorarios"), wxT("Préstamo"), wxT("Varios") };
	int m_choice_motivoNChoices = sizeof( m_choice_motivoChoices ) / sizeof( wxString );
	m_choice_motivo = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choice_motivoNChoices, m_choice_motivoChoices, 0 );
	m_choice_motivo->SetSelection( 0 );
	bSizer45->Add( m_choice_motivo, 0, wxALL|wxEXPAND, 5 );


	bSizer43->Add( bSizer45, 1, wxALL, 5 );


	bSizer42->Add( bSizer43, 0, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizer49;
	bSizer49 = new wxBoxSizer( wxHORIZONTAL );

	Filtrar = new wxButton( this, wxID_ANY, wxT("Filtrar"), wxDefaultPosition, wxSize( 100,30 ), 0 );
	Filtrar->SetFont( wxFont( 9, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Arial") ) );

	bSizer49->Add( Filtrar, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer42->Add( bSizer49, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer41->Add( bSizer42, 0, wxALL|wxEXPAND, 5 );


	this->SetSizer( bSizer41 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	Filtrar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaFiltrar::Click_Filtrar ), NULL, this );
}

VentanaFiltrar::~VentanaFiltrar()
{
	// Disconnect Events
	Filtrar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaFiltrar::Click_Filtrar ), NULL, this );

}

VentanaVerAddress::VentanaVerAddress( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_3DLIGHT ) );

	wxBoxSizer* bSizer50;
	bSizer50 = new wxBoxSizer( wxHORIZONTAL );

	texto32 = new wxStaticText( this, wxID_ANY, wxT("Address:"), wxDefaultPosition, wxDefaultSize, 0 );
	texto32->Wrap( -1 );
	bSizer50->Add( texto32, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_mostrarAddress = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	bSizer50->Add( m_mostrarAddress, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	this->SetSizer( bSizer50 );
	this->Layout();

	this->Centre( wxBOTH );
}

VentanaVerAddress::~VentanaVerAddress()
{
}
