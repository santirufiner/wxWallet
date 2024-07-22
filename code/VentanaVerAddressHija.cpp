#include "VentanaVerAddressHija.h"
#include "Utils.h"
#include <string>
using namespace std;

VentanaVerAddressHija::VentanaVerAddressHija(wxWindow *parent, string address) : VentanaVerAddress(parent), m_address(address){
	m_mostrarAddress->SetValue(std_to_wx(m_address));
}

VentanaVerAddressHija::~VentanaVerAddressHija() {
	
}

