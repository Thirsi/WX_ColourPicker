#pragma once
#include <wx/wx.h>

#define MAINICON 101

class Mainframe : public wxFrame
{
public:
	Mainframe(const wxString& title);

	wxStaticText* rgbCode;
	wxPanel* colourDisplay;

private:
	void ChangePanelColour(int _red, int _green, int _blue);
	void RedChanged(wxCommandEvent& evt);
	void GreenChanged(wxCommandEvent& evt);
	void BlueChanged(wxCommandEvent& evt);
};

