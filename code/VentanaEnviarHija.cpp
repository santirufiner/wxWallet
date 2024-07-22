#include "VentanaEnviarHija.h"
#include <string>
#include "Utils.h"
#include "Wallet.h"
#include <wx/msgdlg.h>
using namespace std;

VentanaEnviarHija::VentanaEnviarHija(wxWindow *parent,Wallet *wallet) : VentanaEnviar(parent), m_wallet(wallet) {
	string emisor=m_wallet->VerSesionIniciada().VerAddress();
	m_emisor->SetValue(std_to_wx(emisor));
}

VentanaEnviarHija::~VentanaEnviarHija() {
	
}


/*------------------------------------------------------------------------*/


void VentanaEnviarHija::Click_Enviar( wxCommandEvent& event )  {
	
	vector<string> choices_moneda = {"ARS","USD","BTC","ETH","CPP"};
	string moneda = choices_moneda[m_choice_moneda2->GetSelection()];
	
	vector<Activo> aux = m_wallet->VerSesionIniciada().VerActivos();
	
	string address_receptor = wx_to_std(m_receptor->GetValue());
	
	string monto = wx_to_std(m_monto->GetValue());
	double monto2;
	m_monto->GetValue().ToDouble(&monto2);
	
	vector<string> choices_motivo = {"Alquiler","Cuotas","Expensas","Facturas","Honorarios", "Préstamo", "Varios"};
	string motivo = choices_motivo[m_choice_motivo2->GetSelection()];
	
	string errores = m_wallet->ValidarDatosTransaccionEgreso(aux[m_choice_moneda2->GetSelection()].balance,address_receptor,monto,monto2);
	
	if(errores==""){
		m_wallet->GenerarEgreso(address_receptor,moneda,float(monto2),motivo);
		EndModal(0);
	} else {
		wxMessageBox("Datos de ingreso erróneos. Ingréselos nuevamente.", "Error",wxICON_ERROR);
		wxMessageBox(errores, "Error",wxICON_INFORMATION);
	}
}

