#include "VentanaPrincipalHija.h"

VentanaPrincipalHija::VentanaPrincipalHija(wxWindow *parent) : wxfbExample(parent){
	
}

void VentanaPrincipalHija::OnButtonClose( wxCommandEvent& event ) { 
	Close();
}
