#include "Application.h"
#include "wxfb_project.h"
#include "VentanaPrincipalHija.h"
#include "Wallet.h"

IMPLEMENT_APP(Application)

Application::Application() : m_wallet("Usuarios.bin","Transacciones.bin"){}

bool Application::OnInit() {
	wxInitAllImageHandlers();
	VentanaPrincipalHija *win = new VentanaPrincipalHija(&m_wallet);
	win->Show();
	return true;
}

