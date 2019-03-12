/***************************************************************
 * Name:      mfp_wxwidgetsApp.h
 * Purpose:   Defines Application Class
 * Author:    Aleksandar Krstic (aleksandar.krstic@d-logic.rs)
 * Created:   2019-02-20
 * Copyright: Aleksandar Krstic (www.d-logic.net)
 * License:
 **************************************************************/

#ifndef MFP_WXWIDGETSAPP_H
#define MFP_WXWIDGETSAPP_H

#include <wx/app.h>

class mfp_wxwidgetsApp : public wxApp
{
    public:
        virtual bool OnInit();
};

#endif // MFP_WXWIDGETSAPP_H
