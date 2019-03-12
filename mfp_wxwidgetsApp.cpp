/***************************************************************
 * Name:      mfp_wxwidgetsApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Aleksandar Krstic (aleksandar.krstic@d-logic.rs)
 * Created:   2019-02-20
 * Copyright: Aleksandar Krstic (www.d-logic.net)
 * License:
 **************************************************************/

#include "mfp_wxwidgetsApp.h"

//(*AppHeaders
#include "mfp_wxwidgetsMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(mfp_wxwidgetsApp);

bool mfp_wxwidgetsApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	mfp_wxwidgetsFrame* Frame = new mfp_wxwidgetsFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
