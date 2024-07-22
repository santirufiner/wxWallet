#include "VentanaWalletHija.h"
#include "VentanaEditarPerfilHija.h"
#include "VentanaAgregarHija.h"
#include "VentanaEnviarHija.h"
#include "VentanaFiltrarHija.h"
#include "VentanaPrincipalHija.h"
#include "VentanaVerAddressHija.h"
#include <wx/msgdlg.h>
#include <wx/clipbrd.h>
#include <wx/icon.h>
#include <string>
#include "Wallet.h"
#include "Utils.h"
#include "clogo.xpm"
using namespace std;


VentanaWalletHija::VentanaWalletHija(Wallet *wallet ) : VentanaWallet(nullptr), m_wallet(wallet) {
	
	// Setear el logo de la aplicación
	SetIcon(wxIcon(clogo_xpm));
	
	m_grilla_activos->AppendRows(5);
	m_grilla_transacciones->AppendRows(m_wallet->CantidadTransacciones());
	CargarFilaActivos();
	CargarFilaTransacciones();
	
	// coso
	float balanceARS = 0;
	vector<Activo>Balances_Usuario=m_wallet->VerSesionIniciada().VerActivos();
	
	for(size_t i=0;i<Balances_Usuario.size();i++) { 
		balanceARS += Balances_Usuario[i].toARS;
	}
	
	m_balancetotal->SetValue(std_to_wx(to_string(balanceARS)));
}

VentanaWalletHija::~VentanaWalletHija() {
	m_wallet->GuardarUsuarios();
}

/*------------------------------------------------------------------------*/

/// Función para cargar las filas de Activos en la grilla
void VentanaWalletHija::CargarFilaActivos(){
	
	vector<Activo>Balances_Usuario=m_wallet->VerSesionIniciada().VerActivos();
	
	for(size_t i=0;i<5;i++){
		
		string monto=to_string(Balances_Usuario[i].balance);
		string ARS=to_string(Balances_Usuario[i].toARS);
		string USD=to_string(Balances_Usuario[i].toUSD);
		
		m_grilla_activos->SetCellValue(i,0,std_to_wx(Balances_Usuario[i].simbolo));
		m_grilla_activos->SetCellValue(i,1,std_to_wx(monto));
		m_grilla_activos->SetCellValue(i,2,std_to_wx(ARS));
		m_grilla_activos->SetCellValue(i,3,std_to_wx(USD));
	}
}

/// Función para cargar las filas de Transacciones en la grilla
void VentanaWalletHija::CargarFilaTransacciones() {
	
	vector<Transaccion> Transacciones_Usuario = m_wallet->VerTransacciones();
	reverse(Transacciones_Usuario.begin(),Transacciones_Usuario.end());
	
	for(size_t i=0;i<Transacciones_Usuario.size();i++) { 
		
		// Si address.receptor() == address.sesioniniciada(), cambia el tipo de transacción para que en pantalla muestre un ingreso en ves de un engreso
		string tipo = "";
		if( Transacciones_Usuario[i].verAddressReceptor() == m_wallet->VerSesionIniciada().VerAddress() ) {
			tipo = "Ingreso";
		} else {
			tipo = Transacciones_Usuario[i].verTipoTransaccion();
		}
		
		Fecha fecha = Transacciones_Usuario[i].verFechaTransaccion();
		string fecha_trans = to_string(fecha[0]) + "/" + to_string(fecha[1]) + "/" + to_string(fecha[2]); 
		
		string moneda = Transacciones_Usuario[i].verSimboloMoneda();
		string monto_trans = to_string(Transacciones_Usuario[i].verMonto());
		string motivo = Transacciones_Usuario[i].verMotivo();
		
		m_grilla_transacciones->SetCellValue(i,0, std_to_wx(fecha_trans));
		m_grilla_transacciones->SetCellValue(i,1, std_to_wx(tipo));
		m_grilla_transacciones->SetCellValue(i,2, std_to_wx(moneda));
		m_grilla_transacciones->SetCellValue(i,3, std_to_wx(monto_trans));
		m_grilla_transacciones->SetCellValue(i,4, std_to_wx(motivo));
	}
}


void VentanaWalletHija::Click_BotonAgregar( wxCommandEvent& event ) {
	VentanaAgregarHija winAgregar(this,m_wallet);
	winAgregar.ShowModal();
	m_grilla_transacciones->AppendRows(1);
	CargarFilaActivos();
	CargarFilaTransacciones();
}

void VentanaWalletHija::Click_BotonEnviar( wxCommandEvent& event ) {
	VentanaEnviarHija winEnviar(this,m_wallet);
	winEnviar.ShowModal();
	m_grilla_transacciones->AppendRows(1);
	CargarFilaActivos();
	CargarFilaTransacciones();
}

void VentanaWalletHija::Click_VerWallet( wxCommandEvent& event ) {
	string address=m_wallet->VerSesionIniciada().VerAddress();
	VentanaVerAddressHija winVerAddress(this, address);
	winVerAddress.ShowModal();
}

void VentanaWalletHija::Click_toARS( wxCommandEvent& event ) {
	float balanceARS=0;
	vector<Activo>Balances_Usuario=m_wallet->VerSesionIniciada().VerActivos();
	
	for(size_t i=0;i<Balances_Usuario.size();i++) { 
		balanceARS += Balances_Usuario[i].toARS;
	}
	
	m_balancetotal->SetValue(std_to_wx(to_string(balanceARS)));
	
}

void VentanaWalletHija::Click_toUSD( wxCommandEvent& event ) {
	float balanceUSD=0;
	
	vector<Activo>Balances_Usuario=m_wallet->VerSesionIniciada().VerActivos();
	
	for(size_t i=0;i<Balances_Usuario.size();i++) { 
		balanceUSD += Balances_Usuario[i].toUSD;
	}
	
	m_balancetotal->SetValue(std_to_wx(to_string(balanceUSD)));
}

void VentanaWalletHija::Click_Filtrar( wxCommandEvent& event ) {
	m_grilla_transacciones->ClearSelection();
	VentanaFiltrarHija winFiltrar(this, m_wallet,m_grilla_transacciones);
	winFiltrar.ShowModal();
}

void VentanaWalletHija::Click_EditarPerfil( wxCommandEvent& event ) {
	VentanaEditarPerfilHija winEditarPerfil(this, m_wallet);
	winEditarPerfil.ShowModal();
}

void VentanaWalletHija::Click_CerrarSesion(wxCommandEvent& event) {
	int respuesta = wxMessageBox("¿Estás seguro de que querés cerrar sesión?", "Cerrar sesión", wxICON_EXCLAMATION | wxYES_NO);
	m_wallet->GuardarUsuarios();
	if (respuesta == wxYES) { // El usuario hizo clic en "Sí"
		
		// Crea una nueva instancia de la ventana principal y la muestra
		VentanaPrincipalHija *winNueva = new VentanaPrincipalHija(m_wallet);
		winNueva->Show();
		
		// Cierra la ventana de la wallet
		Close();
	}
}

void VentanaWalletHija::Click_OrdenarActivos( wxCommandEvent& event ) {
	
	int criterio_activos = m_ordenar_activos->GetSelection();
	m_wallet->VerSesionIniciada().OrdenarActivos(criterio_activos);
	CargarFilaActivos();
	
}

void VentanaWalletHija::Click_OrdenarTransacciones( wxCommandEvent& event ) {
	
	int criterio_transacciones = m_ordenar_transacciones->GetSelection();
	m_wallet->OrdenarTransacciones(criterio_transacciones);
	
	vector<Transaccion> Transacciones_Usuario = m_wallet->VerTransacciones();
	
	CargarFilaTransacciones();
}


void VentanaWalletHija::ClickGrillaActivos( wxGridEvent& event ) {
	int columna = event.GetCol();
	m_wallet->VerSesionIniciada().OrdenarActivos(columna);
	CargarFilaActivos();
}

void VentanaWalletHija::ClickGrillaTransacciones( wxGridEvent& event ) {
	int columna = event.GetCol();
	m_wallet->OrdenarTransacciones(columna);
	CargarFilaTransacciones();
}

