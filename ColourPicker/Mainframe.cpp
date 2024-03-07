#include "Mainframe.h"
#include <wx/wx.h>
#include "resource.h"

int red = 0;
int green = 0;
int blue = 0;

Mainframe::Mainframe(const wxString& title) : wxFrame(nullptr, wxID_ANY, title)
{
	wxPanel* panel = new wxPanel(this);
	panel->SetBackgroundColour(wxColor(127, 127, 127));

	wxStaticText* RedText = new wxStaticText(panel, wxID_ANY, "Red Value", wxPoint(50,50));
	RedText->SetForegroundColour(wxColor(185, 66, 10));
	wxSlider* red_s = new wxSlider(panel, wxID_ANY, 0, 0, 255, wxPoint(43,70), wxSize(-1,-1),wxSL_VALUE_LABEL);

	wxStaticText* GreenText = new wxStaticText(panel, wxID_ANY, "Green Value", wxPoint(50, 120));
	GreenText->SetForegroundColour(wxColor(0, 255, 0));
	wxSlider* green_s = new wxSlider(panel, wxID_ANY, 0, 0, 255, wxPoint(43, 140), wxSize(-1, -1), wxSL_VALUE_LABEL);

	wxStaticText* BlueText = new wxStaticText(panel, wxID_ANY, "Blue Value", wxPoint(50, 180));
	BlueText->SetForegroundColour(wxColor(0, 0, 255));
	wxSlider* blue_s = new wxSlider(panel, wxID_ANY, 0, 0, 255, wxPoint(43, 200), wxSize(-1, -1), wxSL_VALUE_LABEL);

	
	wxStaticText* rgbText = new wxStaticText(panel, wxID_ANY, "RGB Value", wxPoint(50, 250));

	rgbCode = new wxStaticText(panel, wxID_ANY, "", wxPoint(50, 280));
	

	red_s->Bind(wxEVT_SLIDER, &Mainframe::RedChanged, this);
	green_s->Bind(wxEVT_SLIDER, &Mainframe::GreenChanged, this);
	blue_s->Bind(wxEVT_SLIDER, &Mainframe::BlueChanged, this);

	colourDisplay = new wxPanel(panel);
	colourDisplay->SetSize(250, 250);
	colourDisplay->SetPosition(wxPoint(300, 50));
	ChangePanelColour(255, 255, 255);
	colourDisplay->Show();
}

void Mainframe::ChangePanelColour(int _red, int _green, int _blue)
{
	colourDisplay->SetBackgroundColour(wxColor(_red, _green, _blue));
	colourDisplay->Refresh();

	wxColour temp = colourDisplay->GetBackgroundColour();
	wxString HexValue = temp.GetAsString(wxC2S_HTML_SYNTAX);

	rgbCode->SetLabelText(HexValue);

}

void Mainframe::RedChanged(wxCommandEvent& evt)
{
	red = evt.GetInt();
	ChangePanelColour(red, green, blue);
}

void Mainframe::GreenChanged(wxCommandEvent& evt)
{
	green = evt.GetInt();
	ChangePanelColour(red, green, blue);
}

void Mainframe::BlueChanged(wxCommandEvent& evt)
{
	blue = evt.GetInt();
	ChangePanelColour(red, green, blue);
}
