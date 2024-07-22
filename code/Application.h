#ifndef APPLICATION_H
#define APPLICATION_H

#include <wx/app.h>
#include "VentanaPrincipalHija.h"
#include "Wallet.h"

class Application : public wxApp {
public:
	Application();
	virtual bool OnInit();
private:
	Wallet m_wallet;
};


#endif
