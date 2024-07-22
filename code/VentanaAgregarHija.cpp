#include "VentanaAgregarHija.h"
#include <vector>
#include "Utils.h"
#include "Wallet.h"
#include <wx/msgdlg.h>
#include <cctype>
using namespace std;

VentanaAgregarHija::VentanaAgregarHija(wxWindow *parent, Wallet *wallet) : VentanaAgregar(parent) ,m_wallet(wallet) {
	string emisor=m_wallet->VerSesionIniciada().VerAddress();
	m_emisor->SetValue(std_to_wx(emisor));
	m_receptor->SetValue(std_to_wx(emisor));
}

VentanaAgregarHija::~VentanaAgregarHija() {
	
}


/*------------------------------------------------------------------------*/


void VentanaAgregarHija::Click_Agregar( wxCommandEvent& event )  {
	
	vector<string> choices_moneda = {"ARS","USD","BTC","ETH","CPP"};
	string moneda = choices_moneda[m_choice_moneda1->GetSelection()];
	
	string monto = wx_to_std(m_monto->GetValue());
	
	double monto2;
	m_monto->GetValue().ToDouble(&monto2);
	
	vector<string> choices_motivo = {"Alquiler","Cuotas","Expensas","Facturas","Honorarios", "Préstamo", "Varios"};
	string motivo = choices_motivo[m_choice_motivo1->GetSelection()];
	
	string errores = m_wallet->ValidarDatosTransaccionIngreso(monto,monto2);
	
	if(errores==""){
		m_wallet->GenerarIngreso(moneda,float(monto2),motivo);
		EndModal(0);
	} else {
		wxMessageBox("Datos de ingreso erróneos. Ingréselos nuevamente.", "Error",wxICON_ERROR);
		wxMessageBox(errores, "Error",wxICON_INFORMATION);
	}
}

