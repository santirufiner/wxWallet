#include <wx/image.h>
#include "Application.h"
#include "VentanaPrincipalHija.h"

IMPLEMENT_APP(Application)

bool Application::OnInit() {
	wxInitAllImageHandlers();
	VentanaPrincipalHija *win = new VentanaPrincipalHija(NULL);
	win->Show();
	return true;
}

