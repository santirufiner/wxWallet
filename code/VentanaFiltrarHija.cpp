#include "VentanaFiltrarHija.h"
#include <vector>
#include "Fecha.h"
#include "Transaccion.h"
#include "Wallet.h"
#include <wx/grid.h>

using namespace std;

VentanaFiltrarHija::VentanaFiltrarHija(wxWindow *parent, Wallet *wallet, wxGrid *grilla) : VentanaFiltrar(parent), m_wallet(wallet), m_grilla(grilla) {
	
}

VentanaFiltrarHija::~VentanaFiltrarHija() {
	
}


/*------------------------------------------------------------------------*/


void VentanaFiltrarHija::Click_Filtrar( wxCommandEvent& event )  {
	
	// Inicializa enteros para representar los distintos criterios de filtrado y sus posibles selecciones
	int criterio_tipo, criterio_simbolo, criterio_motivo;
	
	// Toma los valores seleccionados de los choicers y los coloca en cada criterio
	criterio_tipo = m_choice_tipo_trans->GetSelection();
	criterio_simbolo = m_choice_simbolo->GetSelection();
	
	Fecha desde(m_date_desde->GetValue().GetDay(), m_date_desde->GetValue().GetMonth()+1, m_date_desde->GetValue().GetYear());
	Fecha hasta(m_date_hasta->GetValue().GetDay(), m_date_hasta->GetValue().GetMonth()+1, m_date_hasta->GetValue().GetYear());
	criterio_motivo = m_choice_motivo->GetSelection();
	
	vector<Transaccion> vec_filtrado = m_wallet->FiltrarTransacciones(criterio_tipo, criterio_simbolo, desde, hasta, criterio_motivo);
	vector<Transaccion>aux=m_wallet->VerTransacciones();
	reverse(aux.begin(),aux.end());
	
	for(size_t i=0;i<m_wallet->VerTransacciones().size();i++){ 
		for(size_t j=0;j<vec_filtrado.size();j++){
			if( aux[i].verIdTransaccion() == vec_filtrado[j].verIdTransaccion() ){
				m_grilla->SelectRow(i,true);
			}
		}
	}
	
	EndModal(0);
}

