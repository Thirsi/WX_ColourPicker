#include "App.h"
#include "Mainframe.h"
#include <wx/wx.h>

wxIMPLEMENT_APP(App);

bool App::OnInit()
{
	Mainframe* mainframe = new Mainframe("Kay's Colour Picker");
	mainframe->SetClientSize(600, 360);
	mainframe->Center();
	mainframe->Show();
	return true;
}



