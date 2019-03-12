/***************************************************************
 * Name:      ufr_mfp_wxwidgetsMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Aleksandar Krstic (aleksandar.krstic@d-logic.rs)
 * Created:   2019-02-18
 * Copyright: Aleksandar Krstic (www.d-logic.net)
 * License:
 **************************************************************/

#include "mfp_wxwidgetsMain.h"
#include <wx/msgdlg.h>
#include "ufr-lib/include/uFCoder.h"
#include <string>
#include <string.h>
#include <cstring>
#include <sstream>
#include "uFR.h"

UFR_STATUS status;
UFR uFR;

//(*InternalHeaders(mfp_wxwidgetsFrame)
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/settings.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(mfp_wxwidgetsFrame)
const long mfp_wxwidgetsFrame::ID_STATICTEXT1 = wxNewId();
const long mfp_wxwidgetsFrame::ID_TEXTCTRL1 = wxNewId();
const long mfp_wxwidgetsFrame::ID_STATICTEXT2 = wxNewId();
const long mfp_wxwidgetsFrame::ID_TEXTCTRL2 = wxNewId();
const long mfp_wxwidgetsFrame::ID_RADIOBUTTON1 = wxNewId();
const long mfp_wxwidgetsFrame::ID_RADIOBUTTON2 = wxNewId();
const long mfp_wxwidgetsFrame::ID_STATICTEXT3 = wxNewId();
const long mfp_wxwidgetsFrame::ID_TEXTCTRL3 = wxNewId();
const long mfp_wxwidgetsFrame::ID_STATICTEXT4 = wxNewId();
const long mfp_wxwidgetsFrame::ID_TEXTCTRL4 = wxNewId();
const long mfp_wxwidgetsFrame::ID_STATICTEXT5 = wxNewId();
const long mfp_wxwidgetsFrame::ID_TEXTCTRL5 = wxNewId();
const long mfp_wxwidgetsFrame::ID_STATICTEXT6 = wxNewId();
const long mfp_wxwidgetsFrame::ID_TEXTCTRL6 = wxNewId();
const long mfp_wxwidgetsFrame::ID_STATICTEXT7 = wxNewId();
const long mfp_wxwidgetsFrame::ID_TEXTCTRL7 = wxNewId();
const long mfp_wxwidgetsFrame::ID_STATICTEXT8 = wxNewId();
const long mfp_wxwidgetsFrame::ID_TEXTCTRL8 = wxNewId();
const long mfp_wxwidgetsFrame::ID_STATICTEXT9 = wxNewId();
const long mfp_wxwidgetsFrame::ID_TEXTCTRL9 = wxNewId();
const long mfp_wxwidgetsFrame::ID_STATICTEXT10 = wxNewId();
const long mfp_wxwidgetsFrame::ID_TEXTCTRL10 = wxNewId();
const long mfp_wxwidgetsFrame::ID_STATICTEXT11 = wxNewId();
const long mfp_wxwidgetsFrame::ID_TEXTCTRL11 = wxNewId();
const long mfp_wxwidgetsFrame::ID_BUTTON1 = wxNewId();
const long mfp_wxwidgetsFrame::ID_STATICTEXT78 = wxNewId();
const long mfp_wxwidgetsFrame::ID_PANEL1 = wxNewId();
const long mfp_wxwidgetsFrame::ID_STATICTEXT14 = wxNewId();
const long mfp_wxwidgetsFrame::ID_TEXTCTRL13 = wxNewId();
const long mfp_wxwidgetsFrame::ID_STATICTEXT15 = wxNewId();
const long mfp_wxwidgetsFrame::ID_COMBOBOX1 = wxNewId();
const long mfp_wxwidgetsFrame::ID_BUTTON3 = wxNewId();
const long mfp_wxwidgetsFrame::ID_PANEL2 = wxNewId();
const long mfp_wxwidgetsFrame::ID_STATICTEXT16 = wxNewId();
const long mfp_wxwidgetsFrame::ID_TEXTCTRL14 = wxNewId();
const long mfp_wxwidgetsFrame::ID_STATICTEXT17 = wxNewId();
const long mfp_wxwidgetsFrame::ID_COMBOBOX2 = wxNewId();
const long mfp_wxwidgetsFrame::ID_BUTTON4 = wxNewId();
const long mfp_wxwidgetsFrame::ID_PANEL3 = wxNewId();
const long mfp_wxwidgetsFrame::ID_STATICTEXT18 = wxNewId();
const long mfp_wxwidgetsFrame::ID_TEXTCTRL15 = wxNewId();
const long mfp_wxwidgetsFrame::ID_STATICTEXT19 = wxNewId();
const long mfp_wxwidgetsFrame::ID_TEXTCTRL16 = wxNewId();
const long mfp_wxwidgetsFrame::ID_STATICTEXT20 = wxNewId();
const long mfp_wxwidgetsFrame::ID_COMBOBOX3 = wxNewId();
const long mfp_wxwidgetsFrame::ID_STATICTEXT21 = wxNewId();
const long mfp_wxwidgetsFrame::ID_TEXTCTRL17 = wxNewId();
const long mfp_wxwidgetsFrame::ID_BUTTON5 = wxNewId();
const long mfp_wxwidgetsFrame::ID_PANEL4 = wxNewId();
const long mfp_wxwidgetsFrame::ID_STATICTEXT22 = wxNewId();
const long mfp_wxwidgetsFrame::ID_TEXTCTRL18 = wxNewId();
const long mfp_wxwidgetsFrame::ID_STATICTEXT23 = wxNewId();
const long mfp_wxwidgetsFrame::ID_TEXTCTRL19 = wxNewId();
const long mfp_wxwidgetsFrame::ID_STATICTEXT24 = wxNewId();
const long mfp_wxwidgetsFrame::ID_COMBOBOX4 = wxNewId();
const long mfp_wxwidgetsFrame::ID_STATICTEXT25 = wxNewId();
const long mfp_wxwidgetsFrame::ID_TEXTCTRL20 = wxNewId();
const long mfp_wxwidgetsFrame::ID_BUTTON6 = wxNewId();
const long mfp_wxwidgetsFrame::ID_PANEL5 = wxNewId();
const long mfp_wxwidgetsFrame::ID_RADIOBUTTON3 = wxNewId();
const long mfp_wxwidgetsFrame::ID_RADIOBUTTON4 = wxNewId();
const long mfp_wxwidgetsFrame::ID_STATICTEXT26 = wxNewId();
const long mfp_wxwidgetsFrame::ID_COMBOBOX5 = wxNewId();
const long mfp_wxwidgetsFrame::ID_STATICTEXT108 = wxNewId();
const long mfp_wxwidgetsFrame::ID_STATICTEXT27 = wxNewId();
const long mfp_wxwidgetsFrame::ID_TEXTCTRL21 = wxNewId();
const long mfp_wxwidgetsFrame::ID_STATICTEXT28 = wxNewId();
const long mfp_wxwidgetsFrame::ID_TEXTCTRL22 = wxNewId();
const long mfp_wxwidgetsFrame::ID_STATICTEXT29 = wxNewId();
const long mfp_wxwidgetsFrame::ID_COMBOBOX6 = wxNewId();
const long mfp_wxwidgetsFrame::ID_STATICTEXT30 = wxNewId();
const long mfp_wxwidgetsFrame::ID_TEXTCTRL23 = wxNewId();
const long mfp_wxwidgetsFrame::ID_BUTTON7 = wxNewId();
const long mfp_wxwidgetsFrame::ID_PANEL6 = wxNewId();
const long mfp_wxwidgetsFrame::ID_RADIOBUTTON5 = wxNewId();
const long mfp_wxwidgetsFrame::ID_RADIOBUTTON6 = wxNewId();
const long mfp_wxwidgetsFrame::ID_STATICTEXT31 = wxNewId();
const long mfp_wxwidgetsFrame::ID_TEXTCTRL24 = wxNewId();
const long mfp_wxwidgetsFrame::ID_STATICTEXT32 = wxNewId();
const long mfp_wxwidgetsFrame::ID_COMBOBOX7 = wxNewId();
const long mfp_wxwidgetsFrame::ID_BUTTON8 = wxNewId();
const long mfp_wxwidgetsFrame::ID_PANEL7 = wxNewId();
const long mfp_wxwidgetsFrame::ID_STATICTEXT33 = wxNewId();
const long mfp_wxwidgetsFrame::ID_TEXTCTRL25 = wxNewId();
const long mfp_wxwidgetsFrame::ID_STATICTEXT34 = wxNewId();
const long mfp_wxwidgetsFrame::ID_TEXTCTRL26 = wxNewId();
const long mfp_wxwidgetsFrame::ID_STATICTEXT35 = wxNewId();
const long mfp_wxwidgetsFrame::ID_COMBOBOX8 = wxNewId();
const long mfp_wxwidgetsFrame::ID_STATICTEXT36 = wxNewId();
const long mfp_wxwidgetsFrame::ID_COMBOBOX9 = wxNewId();
const long mfp_wxwidgetsFrame::ID_BUTTON9 = wxNewId();
const long mfp_wxwidgetsFrame::ID_STATICTEXT45 = wxNewId();
const long mfp_wxwidgetsFrame::ID_TEXTCTRL33 = wxNewId();
const long mfp_wxwidgetsFrame::ID_PANEL8 = wxNewId();
const long mfp_wxwidgetsFrame::ID_STATICTEXT37 = wxNewId();
const long mfp_wxwidgetsFrame::ID_TEXTCTRL27 = wxNewId();
const long mfp_wxwidgetsFrame::ID_STATICTEXT38 = wxNewId();
const long mfp_wxwidgetsFrame::ID_TEXTCTRL28 = wxNewId();
const long mfp_wxwidgetsFrame::ID_STATICTEXT39 = wxNewId();
const long mfp_wxwidgetsFrame::ID_COMBOBOX10 = wxNewId();
const long mfp_wxwidgetsFrame::ID_STATICTEXT40 = wxNewId();
const long mfp_wxwidgetsFrame::ID_TEXTCTRL29 = wxNewId();
const long mfp_wxwidgetsFrame::ID_BUTTON10 = wxNewId();
const long mfp_wxwidgetsFrame::ID_PANEL9 = wxNewId();
const long mfp_wxwidgetsFrame::ID_STATICTEXT41 = wxNewId();
const long mfp_wxwidgetsFrame::ID_TEXTCTRL30 = wxNewId();
const long mfp_wxwidgetsFrame::ID_STATICTEXT42 = wxNewId();
const long mfp_wxwidgetsFrame::ID_TEXTCTRL31 = wxNewId();
const long mfp_wxwidgetsFrame::ID_STATICTEXT43 = wxNewId();
const long mfp_wxwidgetsFrame::ID_COMBOBOX11 = wxNewId();
const long mfp_wxwidgetsFrame::ID_STATICTEXT44 = wxNewId();
const long mfp_wxwidgetsFrame::ID_TEXTCTRL32 = wxNewId();
const long mfp_wxwidgetsFrame::ID_BUTTON11 = wxNewId();
const long mfp_wxwidgetsFrame::ID_PANEL10 = wxNewId();
const long mfp_wxwidgetsFrame::ID_RADIOBUTTON7 = wxNewId();
const long mfp_wxwidgetsFrame::ID_RADIOBUTTON8 = wxNewId();
const long mfp_wxwidgetsFrame::ID_STATICTEXT53 = wxNewId();
const long mfp_wxwidgetsFrame::ID_COMBOBOX14 = wxNewId();
const long mfp_wxwidgetsFrame::ID_STATICTEXT52 = wxNewId();
const long mfp_wxwidgetsFrame::ID_TEXTCTRL38 = wxNewId();
const long mfp_wxwidgetsFrame::ID_BUTTON16 = wxNewId();
const long mfp_wxwidgetsFrame::ID_RADIOBUTTON9 = wxNewId();
const long mfp_wxwidgetsFrame::ID_RADIOBUTTON10 = wxNewId();
const long mfp_wxwidgetsFrame::ID_STATICTEXT54 = wxNewId();
const long mfp_wxwidgetsFrame::ID_COMBOBOX15 = wxNewId();
const long mfp_wxwidgetsFrame::ID_STATICTEXT55 = wxNewId();
const long mfp_wxwidgetsFrame::ID_COMBOBOX16 = wxNewId();
const long mfp_wxwidgetsFrame::ID_STATICTEXT114 = wxNewId();
const long mfp_wxwidgetsFrame::ID_BUTTON17 = wxNewId();
const long mfp_wxwidgetsFrame::ID_RADIOBUTTON11 = wxNewId();
const long mfp_wxwidgetsFrame::ID_RADIOBUTTON12 = wxNewId();
const long mfp_wxwidgetsFrame::ID_STATICTEXT56 = wxNewId();
const long mfp_wxwidgetsFrame::ID_COMBOBOX17 = wxNewId();
const long mfp_wxwidgetsFrame::ID_BUTTON18 = wxNewId();
const long mfp_wxwidgetsFrame::ID_RADIOBUTTON13 = wxNewId();
const long mfp_wxwidgetsFrame::ID_RADIOBUTTON14 = wxNewId();
const long mfp_wxwidgetsFrame::ID_STATICTEXT57 = wxNewId();
const long mfp_wxwidgetsFrame::ID_COMBOBOX18 = wxNewId();
const long mfp_wxwidgetsFrame::ID_BUTTON19 = wxNewId();
const long mfp_wxwidgetsFrame::ID_STATICTEXT107 = wxNewId();
const long mfp_wxwidgetsFrame::ID_PANEL14 = wxNewId();
const long mfp_wxwidgetsFrame::ID_RADIOBUTTON15 = wxNewId();
const long mfp_wxwidgetsFrame::ID_RADIOBUTTON16 = wxNewId();
const long mfp_wxwidgetsFrame::ID_STATICTEXT68 = wxNewId();
const long mfp_wxwidgetsFrame::ID_COMBOBOX24 = wxNewId();
const long mfp_wxwidgetsFrame::ID_STATICTEXT58 = wxNewId();
const long mfp_wxwidgetsFrame::ID_COMBOBOX19 = wxNewId();
const long mfp_wxwidgetsFrame::ID_STATICTEXT59 = wxNewId();
const long mfp_wxwidgetsFrame::ID_TEXTCTRL39 = wxNewId();
const long mfp_wxwidgetsFrame::ID_BUTTON20 = wxNewId();
const long mfp_wxwidgetsFrame::ID_RADIOBUTTON17 = wxNewId();
const long mfp_wxwidgetsFrame::ID_RADIOBUTTON18 = wxNewId();
const long mfp_wxwidgetsFrame::ID_STATICTEXT71 = wxNewId();
const long mfp_wxwidgetsFrame::ID_COMBOBOX25 = wxNewId();
const long mfp_wxwidgetsFrame::ID_STATICTEXT60 = wxNewId();
const long mfp_wxwidgetsFrame::ID_COMBOBOX20 = wxNewId();
const long mfp_wxwidgetsFrame::ID_STATICTEXT61 = wxNewId();
const long mfp_wxwidgetsFrame::ID_COMBOBOX21 = wxNewId();
const long mfp_wxwidgetsFrame::ID_STATICTEXT113 = wxNewId();
const long mfp_wxwidgetsFrame::ID_BUTTON21 = wxNewId();
const long mfp_wxwidgetsFrame::ID_RADIOBUTTON19 = wxNewId();
const long mfp_wxwidgetsFrame::ID_RADIOBUTTON20 = wxNewId();
const long mfp_wxwidgetsFrame::ID_STATICTEXT74 = wxNewId();
const long mfp_wxwidgetsFrame::ID_COMBOBOX26 = wxNewId();
const long mfp_wxwidgetsFrame::ID_STATICTEXT62 = wxNewId();
const long mfp_wxwidgetsFrame::ID_COMBOBOX22 = wxNewId();
const long mfp_wxwidgetsFrame::ID_BUTTON22 = wxNewId();
const long mfp_wxwidgetsFrame::ID_RADIOBUTTON21 = wxNewId();
const long mfp_wxwidgetsFrame::ID_RADIOBUTTON22 = wxNewId();
const long mfp_wxwidgetsFrame::ID_STATICTEXT76 = wxNewId();
const long mfp_wxwidgetsFrame::ID_COMBOBOX27 = wxNewId();
const long mfp_wxwidgetsFrame::ID_STATICTEXT63 = wxNewId();
const long mfp_wxwidgetsFrame::ID_COMBOBOX23 = wxNewId();
const long mfp_wxwidgetsFrame::ID_BUTTON23 = wxNewId();
const long mfp_wxwidgetsFrame::ID_STATICTEXT106 = wxNewId();
const long mfp_wxwidgetsFrame::ID_PANEL15 = wxNewId();
const long mfp_wxwidgetsFrame::ID_RADIOBUTTON23 = wxNewId();
const long mfp_wxwidgetsFrame::ID_RADIOBUTTON24 = wxNewId();
const long mfp_wxwidgetsFrame::ID_STATICTEXT64 = wxNewId();
const long mfp_wxwidgetsFrame::ID_TEXTCTRL40 = wxNewId();
const long mfp_wxwidgetsFrame::ID_STATICTEXT69 = wxNewId();
const long mfp_wxwidgetsFrame::ID_TEXTCTRL41 = wxNewId();
const long mfp_wxwidgetsFrame::ID_STATICTEXT70 = wxNewId();
const long mfp_wxwidgetsFrame::ID_TEXTCTRL42 = wxNewId();
const long mfp_wxwidgetsFrame::ID_BUTTON24 = wxNewId();
const long mfp_wxwidgetsFrame::ID_RADIOBUTTON25 = wxNewId();
const long mfp_wxwidgetsFrame::ID_RADIOBUTTON26 = wxNewId();
const long mfp_wxwidgetsFrame::ID_STATICTEXT65 = wxNewId();
const long mfp_wxwidgetsFrame::ID_TEXTCTRL43 = wxNewId();
const long mfp_wxwidgetsFrame::ID_STATICTEXT72 = wxNewId();
const long mfp_wxwidgetsFrame::ID_TEXTCTRL44 = wxNewId();
const long mfp_wxwidgetsFrame::ID_STATICTEXT73 = wxNewId();
const long mfp_wxwidgetsFrame::ID_COMBOBOX28 = wxNewId();
const long mfp_wxwidgetsFrame::ID_STATICTEXT112 = wxNewId();
const long mfp_wxwidgetsFrame::ID_BUTTON25 = wxNewId();
const long mfp_wxwidgetsFrame::ID_RADIOBUTTON27 = wxNewId();
const long mfp_wxwidgetsFrame::ID_RADIOBUTTON28 = wxNewId();
const long mfp_wxwidgetsFrame::ID_STATICTEXT66 = wxNewId();
const long mfp_wxwidgetsFrame::ID_TEXTCTRL45 = wxNewId();
const long mfp_wxwidgetsFrame::ID_STATICTEXT75 = wxNewId();
const long mfp_wxwidgetsFrame::ID_TEXTCTRL46 = wxNewId();
const long mfp_wxwidgetsFrame::ID_BUTTON26 = wxNewId();
const long mfp_wxwidgetsFrame::ID_RADIOBUTTON29 = wxNewId();
const long mfp_wxwidgetsFrame::ID_RADIOBUTTON30 = wxNewId();
const long mfp_wxwidgetsFrame::ID_STATICTEXT67 = wxNewId();
const long mfp_wxwidgetsFrame::ID_TEXTCTRL47 = wxNewId();
const long mfp_wxwidgetsFrame::ID_STATICTEXT77 = wxNewId();
const long mfp_wxwidgetsFrame::ID_TEXTCTRL48 = wxNewId();
const long mfp_wxwidgetsFrame::ID_BUTTON27 = wxNewId();
const long mfp_wxwidgetsFrame::ID_STATICTEXT105 = wxNewId();
const long mfp_wxwidgetsFrame::ID_PANEL16 = wxNewId();
const long mfp_wxwidgetsFrame::ID_NOTEBOOK2 = wxNewId();
const long mfp_wxwidgetsFrame::ID_PANEL11 = wxNewId();
const long mfp_wxwidgetsFrame::ID_RADIOBUTTON31 = wxNewId();
const long mfp_wxwidgetsFrame::ID_RADIOBUTTON32 = wxNewId();
const long mfp_wxwidgetsFrame::ID_STATICTEXT80 = wxNewId();
const long mfp_wxwidgetsFrame::ID_COMBOBOX29 = wxNewId();
const long mfp_wxwidgetsFrame::ID_STATICTEXT81 = wxNewId();
const long mfp_wxwidgetsFrame::ID_TEXTCTRL50 = wxNewId();
const long mfp_wxwidgetsFrame::ID_BUTTON28 = wxNewId();
const long mfp_wxwidgetsFrame::ID_RADIOBUTTON33 = wxNewId();
const long mfp_wxwidgetsFrame::ID_RADIOBUTTON34 = wxNewId();
const long mfp_wxwidgetsFrame::ID_STATICTEXT82 = wxNewId();
const long mfp_wxwidgetsFrame::ID_COMBOBOX30 = wxNewId();
const long mfp_wxwidgetsFrame::ID_STATICTEXT83 = wxNewId();
const long mfp_wxwidgetsFrame::ID_COMBOBOX31 = wxNewId();
const long mfp_wxwidgetsFrame::ID_STATICTEXT111 = wxNewId();
const long mfp_wxwidgetsFrame::ID_BUTTON29 = wxNewId();
const long mfp_wxwidgetsFrame::ID_RADIOBUTTON35 = wxNewId();
const long mfp_wxwidgetsFrame::ID_RADIOBUTTON36 = wxNewId();
const long mfp_wxwidgetsFrame::ID_STATICTEXT84 = wxNewId();
const long mfp_wxwidgetsFrame::ID_COMBOBOX32 = wxNewId();
const long mfp_wxwidgetsFrame::ID_BUTTON30 = wxNewId();
const long mfp_wxwidgetsFrame::ID_RADIOBUTTON37 = wxNewId();
const long mfp_wxwidgetsFrame::ID_RADIOBUTTON38 = wxNewId();
const long mfp_wxwidgetsFrame::ID_STATICTEXT85 = wxNewId();
const long mfp_wxwidgetsFrame::ID_CHOICE1 = wxNewId();
const long mfp_wxwidgetsFrame::ID_BUTTON31 = wxNewId();
const long mfp_wxwidgetsFrame::ID_STATICTEXT103 = wxNewId();
const long mfp_wxwidgetsFrame::ID_PANEL17 = wxNewId();
const long mfp_wxwidgetsFrame::ID_RADIOBUTTON39 = wxNewId();
const long mfp_wxwidgetsFrame::ID_RADIOBUTTON40 = wxNewId();
const long mfp_wxwidgetsFrame::ID_STATICTEXT86 = wxNewId();
const long mfp_wxwidgetsFrame::ID_COMBOBOX33 = wxNewId();
const long mfp_wxwidgetsFrame::ID_STATICTEXT87 = wxNewId();
const long mfp_wxwidgetsFrame::ID_COMBOBOX34 = wxNewId();
const long mfp_wxwidgetsFrame::ID_STATICTEXT88 = wxNewId();
const long mfp_wxwidgetsFrame::ID_TEXTCTRL51 = wxNewId();
const long mfp_wxwidgetsFrame::ID_BUTTON32 = wxNewId();
const long mfp_wxwidgetsFrame::ID_RADIOBUTTON41 = wxNewId();
const long mfp_wxwidgetsFrame::ID_RADIOBUTTON42 = wxNewId();
const long mfp_wxwidgetsFrame::ID_STATICTEXT89 = wxNewId();
const long mfp_wxwidgetsFrame::ID_COMBOBOX35 = wxNewId();
const long mfp_wxwidgetsFrame::ID_STATICTEXT90 = wxNewId();
const long mfp_wxwidgetsFrame::ID_COMBOBOX36 = wxNewId();
const long mfp_wxwidgetsFrame::ID_STATICTEXT91 = wxNewId();
const long mfp_wxwidgetsFrame::ID_COMBOBOX37 = wxNewId();
const long mfp_wxwidgetsFrame::ID_STATICTEXT110 = wxNewId();
const long mfp_wxwidgetsFrame::ID_BUTTON33 = wxNewId();
const long mfp_wxwidgetsFrame::ID_RADIOBUTTON43 = wxNewId();
const long mfp_wxwidgetsFrame::ID_RADIOBUTTON44 = wxNewId();
const long mfp_wxwidgetsFrame::ID_STATICTEXT92 = wxNewId();
const long mfp_wxwidgetsFrame::ID_COMBOBOX38 = wxNewId();
const long mfp_wxwidgetsFrame::ID_STATICTEXT93 = wxNewId();
const long mfp_wxwidgetsFrame::ID_COMBOBOX39 = wxNewId();
const long mfp_wxwidgetsFrame::ID_BUTTON34 = wxNewId();
const long mfp_wxwidgetsFrame::ID_RADIOBUTTON45 = wxNewId();
const long mfp_wxwidgetsFrame::ID_RADIOBUTTON46 = wxNewId();
const long mfp_wxwidgetsFrame::ID_STATICTEXT94 = wxNewId();
const long mfp_wxwidgetsFrame::ID_COMBOBOX40 = wxNewId();
const long mfp_wxwidgetsFrame::ID_STATICTEXT95 = wxNewId();
const long mfp_wxwidgetsFrame::ID_COMBOBOX41 = wxNewId();
const long mfp_wxwidgetsFrame::ID_BUTTON35 = wxNewId();
const long mfp_wxwidgetsFrame::ID_STATICTEXT100 = wxNewId();
const long mfp_wxwidgetsFrame::ID_PANEL18 = wxNewId();
const long mfp_wxwidgetsFrame::ID_RADIOBUTTON47 = wxNewId();
const long mfp_wxwidgetsFrame::ID_RADIOBUTTON48 = wxNewId();
const long mfp_wxwidgetsFrame::ID_STATICTEXT96 = wxNewId();
const long mfp_wxwidgetsFrame::ID_TEXTCTRL52 = wxNewId();
const long mfp_wxwidgetsFrame::ID_STATICTEXT98 = wxNewId();
const long mfp_wxwidgetsFrame::ID_TEXTCTRL54 = wxNewId();
const long mfp_wxwidgetsFrame::ID_BUTTON2 = wxNewId();
const long mfp_wxwidgetsFrame::ID_RADIOBUTTON49 = wxNewId();
const long mfp_wxwidgetsFrame::ID_RADIOBUTTON50 = wxNewId();
const long mfp_wxwidgetsFrame::ID_STATICTEXT99 = wxNewId();
const long mfp_wxwidgetsFrame::ID_TEXTCTRL55 = wxNewId();
const long mfp_wxwidgetsFrame::ID_STATICTEXT101 = wxNewId();
const long mfp_wxwidgetsFrame::ID_COMBOBOX42 = wxNewId();
const long mfp_wxwidgetsFrame::ID_STATICTEXT109 = wxNewId();
const long mfp_wxwidgetsFrame::ID_BUTTON36 = wxNewId();
const long mfp_wxwidgetsFrame::ID_RADIOBUTTON51 = wxNewId();
const long mfp_wxwidgetsFrame::ID_RADIOBUTTON52 = wxNewId();
const long mfp_wxwidgetsFrame::ID_STATICTEXT102 = wxNewId();
const long mfp_wxwidgetsFrame::ID_TEXTCTRL57 = wxNewId();
const long mfp_wxwidgetsFrame::ID_BUTTON37 = wxNewId();
const long mfp_wxwidgetsFrame::ID_RADIOBUTTON53 = wxNewId();
const long mfp_wxwidgetsFrame::ID_RADIOBUTTON54 = wxNewId();
const long mfp_wxwidgetsFrame::ID_STATICTEXT104 = wxNewId();
const long mfp_wxwidgetsFrame::ID_TEXTCTRL59 = wxNewId();
const long mfp_wxwidgetsFrame::ID_BUTTON38 = wxNewId();
const long mfp_wxwidgetsFrame::ID_STATICTEXT97 = wxNewId();
const long mfp_wxwidgetsFrame::ID_PANEL19 = wxNewId();
const long mfp_wxwidgetsFrame::ID_NOTEBOOK3 = wxNewId();
const long mfp_wxwidgetsFrame::ID_STATICTEXT79 = wxNewId();
const long mfp_wxwidgetsFrame::ID_TEXTCTRL49 = wxNewId();
const long mfp_wxwidgetsFrame::ID_PANEL12 = wxNewId();
const long mfp_wxwidgetsFrame::ID_STATICTEXT46 = wxNewId();
const long mfp_wxwidgetsFrame::ID_TEXTCTRL34 = wxNewId();
const long mfp_wxwidgetsFrame::ID_STATICTEXT47 = wxNewId();
const long mfp_wxwidgetsFrame::ID_COMBOBOX12 = wxNewId();
const long mfp_wxwidgetsFrame::ID_BUTTON12 = wxNewId();
const long mfp_wxwidgetsFrame::ID_STATICTEXT48 = wxNewId();
const long mfp_wxwidgetsFrame::ID_TEXTCTRL35 = wxNewId();
const long mfp_wxwidgetsFrame::ID_STATICTEXT49 = wxNewId();
const long mfp_wxwidgetsFrame::ID_COMBOBOX13 = wxNewId();
const long mfp_wxwidgetsFrame::ID_BUTTON13 = wxNewId();
const long mfp_wxwidgetsFrame::ID_STATICTEXT50 = wxNewId();
const long mfp_wxwidgetsFrame::ID_TEXTCTRL36 = wxNewId();
const long mfp_wxwidgetsFrame::ID_BUTTON14 = wxNewId();
const long mfp_wxwidgetsFrame::ID_STATICTEXT51 = wxNewId();
const long mfp_wxwidgetsFrame::ID_TEXTCTRL37 = wxNewId();
const long mfp_wxwidgetsFrame::ID_BUTTON15 = wxNewId();
const long mfp_wxwidgetsFrame::ID_PANEL13 = wxNewId();
const long mfp_wxwidgetsFrame::ID_NOTEBOOK1 = wxNewId();
const long mfp_wxwidgetsFrame::ID_TEXTCTRL12 = wxNewId();
const long mfp_wxwidgetsFrame::ID_STATICTEXT12 = wxNewId();
const long mfp_wxwidgetsFrame::ID_STATICTEXT13 = wxNewId();
const long mfp_wxwidgetsFrame::idMenuQuit = wxNewId();
const long mfp_wxwidgetsFrame::idMenuAbout = wxNewId();
const long mfp_wxwidgetsFrame::ID_STATUSBAR1 = wxNewId();
const long mfp_wxwidgetsFrame::ID_TIMER1 = wxNewId();
const long mfp_wxwidgetsFrame::ID_TIMER2 = wxNewId();
//*)

BEGIN_EVENT_TABLE(mfp_wxwidgetsFrame,wxFrame)
    //(*EventTable(mfp_wxwidgetsFrame)
    //*)
END_EVENT_TABLE()

mfp_wxwidgetsFrame::mfp_wxwidgetsFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(mfp_wxwidgetsFrame)
    wxBoxSizer* BoxSizer10;
    wxBoxSizer* BoxSizer11;
    wxBoxSizer* BoxSizer12;
    wxBoxSizer* BoxSizer13;
    wxBoxSizer* BoxSizer14;
    wxBoxSizer* BoxSizer15;
    wxBoxSizer* BoxSizer16;
    wxBoxSizer* BoxSizer17;
    wxBoxSizer* BoxSizer18;
    wxBoxSizer* BoxSizer19;
    wxBoxSizer* BoxSizer1;
    wxBoxSizer* BoxSizer20;
    wxBoxSizer* BoxSizer21;
    wxBoxSizer* BoxSizer22;
    wxBoxSizer* BoxSizer23;
    wxBoxSizer* BoxSizer24;
    wxBoxSizer* BoxSizer25;
    wxBoxSizer* BoxSizer26;
    wxBoxSizer* BoxSizer27;
    wxBoxSizer* BoxSizer28;
    wxBoxSizer* BoxSizer29;
    wxBoxSizer* BoxSizer2;
    wxBoxSizer* BoxSizer30;
    wxBoxSizer* BoxSizer31;
    wxBoxSizer* BoxSizer32;
    wxBoxSizer* BoxSizer33;
    wxBoxSizer* BoxSizer34;
    wxBoxSizer* BoxSizer35;
    wxBoxSizer* BoxSizer36;
    wxBoxSizer* BoxSizer37;
    wxBoxSizer* BoxSizer38;
    wxBoxSizer* BoxSizer39;
    wxBoxSizer* BoxSizer3;
    wxBoxSizer* BoxSizer40;
    wxBoxSizer* BoxSizer41;
    wxBoxSizer* BoxSizer42;
    wxBoxSizer* BoxSizer43;
    wxBoxSizer* BoxSizer44;
    wxBoxSizer* BoxSizer45;
    wxBoxSizer* BoxSizer46;
    wxBoxSizer* BoxSizer47;
    wxBoxSizer* BoxSizer48;
    wxBoxSizer* BoxSizer49;
    wxBoxSizer* BoxSizer4;
    wxBoxSizer* BoxSizer50;
    wxBoxSizer* BoxSizer51;
    wxBoxSizer* BoxSizer52;
    wxBoxSizer* BoxSizer53;
    wxBoxSizer* BoxSizer54;
    wxBoxSizer* BoxSizer55;
    wxBoxSizer* BoxSizer56;
    wxBoxSizer* BoxSizer57;
    wxBoxSizer* BoxSizer58;
    wxBoxSizer* BoxSizer59;
    wxBoxSizer* BoxSizer5;
    wxBoxSizer* BoxSizer60;
    wxBoxSizer* BoxSizer61;
    wxBoxSizer* BoxSizer62;
    wxBoxSizer* BoxSizer63;
    wxBoxSizer* BoxSizer64;
    wxBoxSizer* BoxSizer65;
    wxBoxSizer* BoxSizer66;
    wxBoxSizer* BoxSizer67;
    wxBoxSizer* BoxSizer68;
    wxBoxSizer* BoxSizer6;
    wxBoxSizer* BoxSizer7;
    wxBoxSizer* BoxSizer8;
    wxBoxSizer* BoxSizer9;
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;
    wxStaticBoxSizer* StaticBoxSizer10;
    wxStaticBoxSizer* StaticBoxSizer11;
    wxStaticBoxSizer* StaticBoxSizer12;
    wxStaticBoxSizer* StaticBoxSizer13;
    wxStaticBoxSizer* StaticBoxSizer14;
    wxStaticBoxSizer* StaticBoxSizer15;
    wxStaticBoxSizer* StaticBoxSizer16;
    wxStaticBoxSizer* StaticBoxSizer17;
    wxStaticBoxSizer* StaticBoxSizer18;
    wxStaticBoxSizer* StaticBoxSizer19;
    wxStaticBoxSizer* StaticBoxSizer1;
    wxStaticBoxSizer* StaticBoxSizer20;
    wxStaticBoxSizer* StaticBoxSizer21;
    wxStaticBoxSizer* StaticBoxSizer22;
    wxStaticBoxSizer* StaticBoxSizer23;
    wxStaticBoxSizer* StaticBoxSizer24;
    wxStaticBoxSizer* StaticBoxSizer25;
    wxStaticBoxSizer* StaticBoxSizer26;
    wxStaticBoxSizer* StaticBoxSizer27;
    wxStaticBoxSizer* StaticBoxSizer28;
    wxStaticBoxSizer* StaticBoxSizer29;
    wxStaticBoxSizer* StaticBoxSizer2;
    wxStaticBoxSizer* StaticBoxSizer30;
    wxStaticBoxSizer* StaticBoxSizer31;
    wxStaticBoxSizer* StaticBoxSizer32;
    wxStaticBoxSizer* StaticBoxSizer33;
    wxStaticBoxSizer* StaticBoxSizer34;
    wxStaticBoxSizer* StaticBoxSizer35;
    wxStaticBoxSizer* StaticBoxSizer36;
    wxStaticBoxSizer* StaticBoxSizer37;
    wxStaticBoxSizer* StaticBoxSizer38;
    wxStaticBoxSizer* StaticBoxSizer39;
    wxStaticBoxSizer* StaticBoxSizer3;
    wxStaticBoxSizer* StaticBoxSizer40;
    wxStaticBoxSizer* StaticBoxSizer41;
    wxStaticBoxSizer* StaticBoxSizer42;
    wxStaticBoxSizer* StaticBoxSizer43;
    wxStaticBoxSizer* StaticBoxSizer44;
    wxStaticBoxSizer* StaticBoxSizer45;
    wxStaticBoxSizer* StaticBoxSizer46;
    wxStaticBoxSizer* StaticBoxSizer47;
    wxStaticBoxSizer* StaticBoxSizer48;
    wxStaticBoxSizer* StaticBoxSizer49;
    wxStaticBoxSizer* StaticBoxSizer4;
    wxStaticBoxSizer* StaticBoxSizer50;
    wxStaticBoxSizer* StaticBoxSizer51;
    wxStaticBoxSizer* StaticBoxSizer52;
    wxStaticBoxSizer* StaticBoxSizer53;
    wxStaticBoxSizer* StaticBoxSizer54;
    wxStaticBoxSizer* StaticBoxSizer55;
    wxStaticBoxSizer* StaticBoxSizer56;
    wxStaticBoxSizer* StaticBoxSizer57;
    wxStaticBoxSizer* StaticBoxSizer58;
    wxStaticBoxSizer* StaticBoxSizer59;
    wxStaticBoxSizer* StaticBoxSizer5;
    wxStaticBoxSizer* StaticBoxSizer60;
    wxStaticBoxSizer* StaticBoxSizer61;
    wxStaticBoxSizer* StaticBoxSizer62;
    wxStaticBoxSizer* StaticBoxSizer63;
    wxStaticBoxSizer* StaticBoxSizer64;
    wxStaticBoxSizer* StaticBoxSizer65;
    wxStaticBoxSizer* StaticBoxSizer66;
    wxStaticBoxSizer* StaticBoxSizer67;
    wxStaticBoxSizer* StaticBoxSizer68;
    wxStaticBoxSizer* StaticBoxSizer69;
    wxStaticBoxSizer* StaticBoxSizer6;
    wxStaticBoxSizer* StaticBoxSizer7;
    wxStaticBoxSizer* StaticBoxSizer8;
    wxStaticBoxSizer* StaticBoxSizer9;

    Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
    StaticBoxSizer1 = new wxStaticBoxSizer(wxVERTICAL, this, wxEmptyString);
    BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Card type:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    BoxSizer1->Add(StaticText1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
    CType = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxSize(172,21), wxTE_READONLY|wxTE_CENTRE, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    BoxSizer1->Add(CType, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
    StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Factory UID :"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    BoxSizer1->Add(StaticText2, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
    CUid = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxDefaultPosition, wxSize(181,21), wxTE_READONLY|wxTE_CENTRE, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    BoxSizer1->Add(CUid, 0, wxALL|wxALIGN_CENTER_VERTICAL, 2);
    StaticBoxSizer4 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Auth mode"));
    RBProvided = new wxRadioButton(this, ID_RADIOBUTTON1, _("Provided AES key"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON1"));
    RBProvided->SetValue(true);
    StaticBoxSizer4->Add(RBProvided, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
    RBReader = new wxRadioButton(this, ID_RADIOBUTTON2, _("Reader AES key"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON2"));
    StaticBoxSizer4->Add(RBReader, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
    BoxSizer1->Add(StaticBoxSizer4, 1, wxALL|wxEXPAND, 2);
    StaticBoxSizer1->Add(BoxSizer1, 0, wxALL|wxEXPAND, 0);
    BoxSizer2 = new wxBoxSizer(wxVERTICAL);
    Notebook1 = new wxNotebook(this, ID_NOTEBOOK1, wxDefaultPosition, wxSize(847,370), 0, _T("ID_NOTEBOOK1"));
    Panel1 = new wxPanel(Notebook1, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    StaticBoxSizer2 = new wxStaticBoxSizer(wxVERTICAL, Panel1, wxEmptyString);
    BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
    StaticText3 = new wxStaticText(Panel1, ID_STATICTEXT3, _("Card master key:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    BoxSizer3->Add(StaticText3, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
    CardMasterKeyTB = new wxTextCtrl(Panel1, ID_TEXTCTRL3, _("FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF"), wxDefaultPosition, wxSize(214,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
    CardMasterKeyTB->SetMaxLength(32);
    BoxSizer3->Add(CardMasterKeyTB, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
    StaticText4 = new wxStaticText(Panel1, ID_STATICTEXT4, _("SL1 Card authentication key:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
    BoxSizer3->Add(StaticText4, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
    SL1CardAuthKeyTB = new wxTextCtrl(Panel1, ID_TEXTCTRL4, _("FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF"), wxDefaultPosition, wxSize(216,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL4"));
    SL1CardAuthKeyTB->SetMaxLength(32);
    BoxSizer3->Add(SL1CardAuthKeyTB, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
    StaticBoxSizer2->Add(BoxSizer3, 0, wxALL|wxEXPAND, 2);
    BoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
    StaticText5 = new wxStaticText(Panel1, ID_STATICTEXT5, _("Card configuration key:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
    BoxSizer4->Add(StaticText5, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
    CardConfKeyTB = new wxTextCtrl(Panel1, ID_TEXTCTRL5, _("FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF"), wxDefaultPosition, wxSize(208,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL5"));
    CardConfKeyTB->SetMaxLength(32);
    BoxSizer4->Add(CardConfKeyTB, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
    StaticText6 = new wxStaticText(Panel1, ID_STATICTEXT6, _("Select VC key:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT6"));
    BoxSizer4->Add(StaticText6, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
    SelectVCKeyTB = new wxTextCtrl(Panel1, ID_TEXTCTRL6, _("FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF"), wxDefaultPosition, wxSize(214,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL6"));
    SelectVCKeyTB->SetMaxLength(32);
    BoxSizer4->Add(SelectVCKeyTB, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
    StaticBoxSizer2->Add(BoxSizer4, 0, wxALL|wxALIGN_LEFT, 2);
    BoxSizer5 = new wxBoxSizer(wxHORIZONTAL);
    StaticText7 = new wxStaticText(Panel1, ID_STATICTEXT7, _("Level 2 switch key:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT7"));
    BoxSizer5->Add(StaticText7, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
    Level2SwitchKeyTB = new wxTextCtrl(Panel1, ID_TEXTCTRL7, _("FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF"), wxDefaultPosition, wxSize(209,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL7"));
    Level2SwitchKeyTB->SetMaxLength(32);
    BoxSizer5->Add(Level2SwitchKeyTB, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
    StaticText8 = new wxStaticText(Panel1, ID_STATICTEXT8, _("Proximity check key:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT8"));
    BoxSizer5->Add(StaticText8, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
    ProximityCheckKeyTB = new wxTextCtrl(Panel1, ID_TEXTCTRL8, _("FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF"), wxDefaultPosition, wxSize(206,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL8"));
    ProximityCheckKeyTB->SetMaxLength(32);
    BoxSizer5->Add(ProximityCheckKeyTB, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
    StaticBoxSizer2->Add(BoxSizer5, 0, wxALL|wxEXPAND, 2);
    BoxSizer6 = new wxBoxSizer(wxHORIZONTAL);
    StaticText9 = new wxStaticText(Panel1, ID_STATICTEXT9, _("Level 3 swirch key:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT9"));
    BoxSizer6->Add(StaticText9, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
    Level3SwitchKeyTB = new wxTextCtrl(Panel1, ID_TEXTCTRL9, _("FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF"), wxDefaultPosition, wxSize(210,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL9"));
    Level3SwitchKeyTB->SetMaxLength(32);
    BoxSizer6->Add(Level3SwitchKeyTB, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
    StaticText10 = new wxStaticText(Panel1, ID_STATICTEXT10, _("VC polling ENC key:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT10"));
    BoxSizer6->Add(StaticText10, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
    VCPollingEncKeyTB = new wxTextCtrl(Panel1, ID_TEXTCTRL10, _("FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF"), wxDefaultPosition, wxSize(209,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL10"));
    VCPollingEncKeyTB->SetMaxLength(32);
    BoxSizer6->Add(VCPollingEncKeyTB, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
    StaticBoxSizer2->Add(BoxSizer6, 0, wxALL|wxEXPAND, 2);
    BoxSizer7 = new wxBoxSizer(wxHORIZONTAL);
    StaticText11 = new wxStaticText(Panel1, ID_STATICTEXT11, _("VC polling MAC key:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT11"));
    BoxSizer7->Add(StaticText11, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
    VCPollingMacKeyTB = new wxTextCtrl(Panel1, ID_TEXTCTRL11, _("FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF"), wxDefaultPosition, wxSize(205,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL11"));
    VCPollingMacKeyTB->SetMaxLength(32);
    BoxSizer7->Add(VCPollingMacKeyTB, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
    bPersonalizeCard = new wxButton(Panel1, ID_BUTTON1, _("Personalize card"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    BoxSizer7->Add(bPersonalizeCard, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
    StaticBoxSizer2->Add(BoxSizer7, 0, wxALL|wxEXPAND, 2);
    StaticText77 = new wxStaticText(Panel1, ID_STATICTEXT78, _("All keys must be 16 bytes long."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT78"));
    StaticBoxSizer2->Add(StaticText77, 0, wxALL|wxALIGN_LEFT, 5);
    Panel1->SetSizer(StaticBoxSizer2);
    StaticBoxSizer2->Fit(Panel1);
    StaticBoxSizer2->SetSizeHints(Panel1);
    Panel2 = new wxPanel(Notebook1, ID_PANEL2, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL2"));
    StaticBoxSizer3 = new wxStaticBoxSizer(wxVERTICAL, Panel2, wxEmptyString);
    StaticBoxSizer34 = new wxStaticBoxSizer(wxVERTICAL, Panel2, _("Provided AES  key"));
    StaticText13 = new wxStaticText(Panel2, ID_STATICTEXT14, _("Enter SL1 card authentication key (16 bytes):"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT14"));
    StaticBoxSizer34->Add(StaticText13, 0, wxALL|wxALIGN_LEFT, 3);
    SL1AuthKeyTB = new wxTextCtrl(Panel2, ID_TEXTCTRL13, _("FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF"), wxDefaultPosition, wxSize(204,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL13"));
    SL1AuthKeyTB->SetMaxLength(32);
    StaticBoxSizer34->Add(SL1AuthKeyTB, 0, wxALL|wxALIGN_LEFT, 3);
    StaticBoxSizer3->Add(StaticBoxSizer34, 0, wxALL|wxEXPAND, 3);
    StaticBoxSizer35 = new wxStaticBoxSizer(wxVERTICAL, Panel2, _("Reader AES  key"));
    StaticText14 = new wxStaticText(Panel2, ID_STATICTEXT15, _("Enter reader key index for SL1 card authentication key (0 - 15):"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT15"));
    StaticBoxSizer35->Add(StaticText14, 0, wxALL|wxALIGN_LEFT, 3);
    SL1RK = new wxComboBox(Panel2, ID_COMBOBOX1, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, wxCB_READONLY, wxDefaultValidator, _T("ID_COMBOBOX1"));
    SL1RK->SetSelection( SL1RK->Append(_("0")) );
    SL1RK->Append(_("1"));
    SL1RK->Append(_("2"));
    SL1RK->Append(_("3"));
    SL1RK->Append(_("4"));
    SL1RK->Append(_("5"));
    SL1RK->Append(_("6"));
    SL1RK->Append(_("7"));
    SL1RK->Append(_("8"));
    SL1RK->Append(_("9"));
    SL1RK->Append(_("10"));
    SL1RK->Append(_("11"));
    SL1RK->Append(_("12"));
    SL1RK->Append(_("13"));
    SL1RK->Append(_("14"));
    SL1RK->Append(_("15"));
    StaticBoxSizer35->Add(SL1RK, 0, wxALL|wxALIGN_LEFT, 3);
    StaticBoxSizer3->Add(StaticBoxSizer35, 0, wxALL|wxEXPAND, 3);
    bAesAuthSL1 = new wxButton(Panel2, ID_BUTTON3, _("AES authentication on SL1"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
    StaticBoxSizer3->Add(bAesAuthSL1, 0, wxALL|wxALIGN_LEFT, 3);
    Panel2->SetSizer(StaticBoxSizer3);
    StaticBoxSizer3->Fit(Panel2);
    StaticBoxSizer3->SetSizeHints(Panel2);
    Panel3 = new wxPanel(Notebook1, ID_PANEL3, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL3"));
    StaticBoxSizer5 = new wxStaticBoxSizer(wxVERTICAL, Panel3, wxEmptyString);
    StaticBoxSizer36 = new wxStaticBoxSizer(wxVERTICAL, Panel3, _("Provided AES key"));
    StaticText15 = new wxStaticText(Panel3, ID_STATICTEXT16, _("Enter level 3 switch key (16 bytes):"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT16"));
    StaticBoxSizer36->Add(StaticText15, 0, wxALL|wxALIGN_LEFT, 3);
    SwitchSL3KeyTB = new wxTextCtrl(Panel3, ID_TEXTCTRL14, _("FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF"), wxDefaultPosition, wxSize(204,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL14"));
    SwitchSL3KeyTB->SetMaxLength(32);
    StaticBoxSizer36->Add(SwitchSL3KeyTB, 0, wxALL|wxALIGN_LEFT, 3);
    StaticBoxSizer5->Add(StaticBoxSizer36, 0, wxALL|wxEXPAND, 3);
    StaticBoxSizer37 = new wxStaticBoxSizer(wxVERTICAL, Panel3, _("Reader AES key"));
    StaticText16 = new wxStaticText(Panel3, ID_STATICTEXT17, _("Enter reader key index for level 3 switch key (0 - 15):"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT17"));
    StaticBoxSizer37->Add(StaticText16, 0, wxALL|wxALIGN_LEFT, 3);
    SL3RK = new wxComboBox(Panel3, ID_COMBOBOX2, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, wxCB_READONLY, wxDefaultValidator, _T("ID_COMBOBOX2"));
    SL3RK->SetSelection( SL3RK->Append(_("0")) );
    SL3RK->Append(_("1"));
    SL3RK->Append(_("2"));
    SL3RK->Append(_("3"));
    SL3RK->Append(_("4"));
    SL3RK->Append(_("5"));
    SL3RK->Append(_("6"));
    SL3RK->Append(_("7"));
    SL3RK->Append(_("8"));
    SL3RK->Append(_("9"));
    SL3RK->Append(_("10"));
    SL3RK->Append(_("11"));
    SL3RK->Append(_("12"));
    SL3RK->Append(_("13"));
    SL3RK->Append(_("14"));
    SL3RK->Append(_("15"));
    StaticBoxSizer37->Add(SL3RK, 0, wxALL|wxALIGN_LEFT, 3);
    StaticBoxSizer5->Add(StaticBoxSizer37, 0, wxALL|wxEXPAND, 3);
    bSwitchToSL3 = new wxButton(Panel3, ID_BUTTON4, _("Switch to SL3"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON4"));
    StaticBoxSizer5->Add(bSwitchToSL3, 0, wxALL|wxALIGN_LEFT, 3);
    Panel3->SetSizer(StaticBoxSizer5);
    StaticBoxSizer5->Fit(Panel3);
    StaticBoxSizer5->SetSizeHints(Panel3);
    Panel4 = new wxPanel(Notebook1, ID_PANEL4, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL4"));
    StaticBoxSizer6 = new wxStaticBoxSizer(wxVERTICAL, Panel4, wxEmptyString);
    StaticBoxSizer7 = new wxStaticBoxSizer(wxHORIZONTAL, Panel4, _("Provided AES key"));
    BoxSizer13 = new wxBoxSizer(wxVERTICAL);
    StaticText17 = new wxStaticText(Panel4, ID_STATICTEXT18, _("Enter old card master key (16 bytes):"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT18"));
    BoxSizer13->Add(StaticText17, 0, wxALL|wxALIGN_LEFT, 3);
    OldMasterTB = new wxTextCtrl(Panel4, ID_TEXTCTRL15, _("FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF"), wxDefaultPosition, wxSize(204,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL15"));
    OldMasterTB->SetMaxLength(32);
    BoxSizer13->Add(OldMasterTB, 0, wxALL|wxALIGN_LEFT, 3);
    StaticText18 = new wxStaticText(Panel4, ID_STATICTEXT19, _("Enter new card master key (16 bytes):"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT19"));
    BoxSizer13->Add(StaticText18, 0, wxALL|wxALIGN_LEFT, 3);
    NewMasterTB = new wxTextCtrl(Panel4, ID_TEXTCTRL16, _("FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF"), wxDefaultPosition, wxSize(203,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL16"));
    NewMasterTB->SetMaxLength(32);
    BoxSizer13->Add(NewMasterTB, 0, wxALL|wxALIGN_LEFT, 3);
    StaticBoxSizer7->Add(BoxSizer13, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    StaticBoxSizer6->Add(StaticBoxSizer7, 0, wxALL|wxEXPAND, 3);
    StaticBoxSizer8 = new wxStaticBoxSizer(wxHORIZONTAL, Panel4, _("Reader AES key"));
    BoxSizer14 = new wxBoxSizer(wxVERTICAL);
    StaticText19 = new wxStaticText(Panel4, ID_STATICTEXT20, _("Enter reader key index for old card master key (0 - 15):"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT20"));
    BoxSizer14->Add(StaticText19, 0, wxALL|wxALIGN_LEFT, 3);
    OldMasterIndex = new wxComboBox(Panel4, ID_COMBOBOX3, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, wxCB_READONLY, wxDefaultValidator, _T("ID_COMBOBOX3"));
    OldMasterIndex->SetSelection( OldMasterIndex->Append(_("0")) );
    OldMasterIndex->Append(_("1"));
    OldMasterIndex->Append(_("2"));
    OldMasterIndex->Append(_("3"));
    OldMasterIndex->Append(_("4"));
    OldMasterIndex->Append(_("5"));
    OldMasterIndex->Append(_("6"));
    OldMasterIndex->Append(_("7"));
    OldMasterIndex->Append(_("8"));
    OldMasterIndex->Append(_("9"));
    OldMasterIndex->Append(_("10"));
    OldMasterIndex->Append(_("11"));
    OldMasterIndex->Append(_("12"));
    OldMasterIndex->Append(_("13"));
    OldMasterIndex->Append(_("14"));
    OldMasterIndex->Append(_("15"));
    BoxSizer14->Add(OldMasterIndex, 0, wxALL|wxALIGN_LEFT, 3);
    StaticText20 = new wxStaticText(Panel4, ID_STATICTEXT21, _("Enter new card master key (16 bytes):"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT21"));
    BoxSizer14->Add(StaticText20, 0, wxALL|wxALIGN_LEFT, 3);
    NewMasterRK = new wxTextCtrl(Panel4, ID_TEXTCTRL17, _("FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF"), wxDefaultPosition, wxSize(203,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL17"));
    NewMasterRK->SetMaxLength(32);
    BoxSizer14->Add(NewMasterRK, 0, wxALL|wxALIGN_LEFT, 3);
    StaticBoxSizer8->Add(BoxSizer14, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    StaticBoxSizer6->Add(StaticBoxSizer8, 0, wxALL|wxEXPAND, 3);
    Button3 = new wxButton(Panel4, ID_BUTTON5, _("Change master key"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON5"));
    StaticBoxSizer6->Add(Button3, 0, wxALL|wxALIGN_LEFT, 3);
    Panel4->SetSizer(StaticBoxSizer6);
    StaticBoxSizer6->Fit(Panel4);
    StaticBoxSizer6->SetSizeHints(Panel4);
    Panel5 = new wxPanel(Notebook1, ID_PANEL5, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL5"));
    StaticBoxSizer9 = new wxStaticBoxSizer(wxVERTICAL, Panel5, wxEmptyString);
    StaticBoxSizer10 = new wxStaticBoxSizer(wxHORIZONTAL, Panel5, _("Provided AES key"));
    BoxSizer15 = new wxBoxSizer(wxVERTICAL);
    StaticText21 = new wxStaticText(Panel5, ID_STATICTEXT22, _("Enter old card configuration key (16 bytes):"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT22"));
    BoxSizer15->Add(StaticText21, 0, wxALL|wxALIGN_LEFT, 3);
    OldConfigKeyTB = new wxTextCtrl(Panel5, ID_TEXTCTRL18, _("FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF"), wxDefaultPosition, wxSize(204,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL18"));
    OldConfigKeyTB->SetMaxLength(32);
    BoxSizer15->Add(OldConfigKeyTB, 0, wxALL|wxALIGN_LEFT, 3);
    StaticText22 = new wxStaticText(Panel5, ID_STATICTEXT23, _("Enter new card configuration key (16 bytes):"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT23"));
    BoxSizer15->Add(StaticText22, 0, wxALL|wxALIGN_LEFT, 3);
    NewConfigKeyTB = new wxTextCtrl(Panel5, ID_TEXTCTRL19, _("FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF"), wxDefaultPosition, wxSize(203,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL19"));
    NewConfigKeyTB->SetMaxLength(32);
    BoxSizer15->Add(NewConfigKeyTB, 0, wxALL|wxALIGN_LEFT, 3);
    StaticBoxSizer10->Add(BoxSizer15, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    StaticBoxSizer9->Add(StaticBoxSizer10, 0, wxALL|wxEXPAND, 3);
    StaticBoxSizer11 = new wxStaticBoxSizer(wxHORIZONTAL, Panel5, _("Reader AES key"));
    BoxSizer16 = new wxBoxSizer(wxVERTICAL);
    StaticText23 = new wxStaticText(Panel5, ID_STATICTEXT24, _("Enter reader key index for old card configuration key (0 - 15):"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT24"));
    BoxSizer16->Add(StaticText23, 0, wxALL|wxALIGN_LEFT, 3);
    OldConfigIndex = new wxComboBox(Panel5, ID_COMBOBOX4, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, wxCB_READONLY, wxDefaultValidator, _T("ID_COMBOBOX4"));
    OldConfigIndex->SetSelection( OldConfigIndex->Append(_("0")) );
    OldConfigIndex->Append(_("1"));
    OldConfigIndex->Append(_("2"));
    OldConfigIndex->Append(_("3"));
    OldConfigIndex->Append(_("4"));
    OldConfigIndex->Append(_("5"));
    OldConfigIndex->Append(_("6"));
    OldConfigIndex->Append(_("7"));
    OldConfigIndex->Append(_("8"));
    OldConfigIndex->Append(_("9"));
    OldConfigIndex->Append(_("10"));
    OldConfigIndex->Append(_("11"));
    OldConfigIndex->Append(_("12"));
    OldConfigIndex->Append(_("13"));
    OldConfigIndex->Append(_("14"));
    OldConfigIndex->Append(_("15"));
    BoxSizer16->Add(OldConfigIndex, 0, wxALL|wxALIGN_LEFT, 3);
    StaticText24 = new wxStaticText(Panel5, ID_STATICTEXT25, _("Enter new card configuration key (16 bytes):"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT25"));
    BoxSizer16->Add(StaticText24, 0, wxALL|wxALIGN_LEFT, 3);
    NewConfigKeyRK = new wxTextCtrl(Panel5, ID_TEXTCTRL20, _("FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF"), wxDefaultPosition, wxSize(203,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL20"));
    NewConfigKeyRK->SetMaxLength(32);
    BoxSizer16->Add(NewConfigKeyRK, 1, wxALL|wxALIGN_LEFT, 3);
    StaticBoxSizer11->Add(BoxSizer16, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    StaticBoxSizer9->Add(StaticBoxSizer11, 0, wxALL|wxEXPAND, 3);
    Button4 = new wxButton(Panel5, ID_BUTTON6, _("Change config key"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON6"));
    StaticBoxSizer9->Add(Button4, 0, wxALL|wxALIGN_LEFT, 3);
    Panel5->SetSizer(StaticBoxSizer9);
    StaticBoxSizer9->Fit(Panel5);
    StaticBoxSizer9->SetSizeHints(Panel5);
    Panel6 = new wxPanel(Notebook1, ID_PANEL6, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL6"));
    StaticBoxSizer12 = new wxStaticBoxSizer(wxVERTICAL, Panel6, wxEmptyString);
    StaticBoxSizer13 = new wxStaticBoxSizer(wxHORIZONTAL, Panel6, _("Settings"));
    BoxSizer17 = new wxBoxSizer(wxHORIZONTAL);
    RB_AES_KEY_A = new wxRadioButton(Panel6, ID_RADIOBUTTON3, _("AES KEY A"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON3"));
    RB_AES_KEY_A->SetValue(true);
    BoxSizer17->Add(RB_AES_KEY_A, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    RB_AES_KEY_B = new wxRadioButton(Panel6, ID_RADIOBUTTON4, _("AES KEY B"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON4"));
    BoxSizer17->Add(RB_AES_KEY_B, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    BoxSizer17->Add(-1,-1,0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    StaticText25 = new wxStaticText(Panel6, ID_STATICTEXT26, _("Enter sector number:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT26"));
    BoxSizer17->Add(StaticText25, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    SectorNumber = new wxComboBox(Panel6, ID_COMBOBOX5, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, wxCB_READONLY, wxDefaultValidator, _T("ID_COMBOBOX5"));
    SectorNumber->SetSelection( SectorNumber->Append(_("0")) );
    SectorNumber->Append(_("1"));
    SectorNumber->Append(_("2"));
    SectorNumber->Append(_("3"));
    SectorNumber->Append(_("4"));
    SectorNumber->Append(_("5"));
    SectorNumber->Append(_("6"));
    SectorNumber->Append(_("7"));
    SectorNumber->Append(_("8"));
    SectorNumber->Append(_("9"));
    SectorNumber->Append(_("10"));
    SectorNumber->Append(_("11"));
    SectorNumber->Append(_("12"));
    SectorNumber->Append(_("13"));
    SectorNumber->Append(_("14"));
    SectorNumber->Append(_("15"));
    SectorNumber->Append(_("16"));
    SectorNumber->Append(_("17"));
    SectorNumber->Append(_("18"));
    SectorNumber->Append(_("19"));
    SectorNumber->Append(_("20"));
    SectorNumber->Append(_("21"));
    SectorNumber->Append(_("22"));
    SectorNumber->Append(_("23"));
    SectorNumber->Append(_("24"));
    SectorNumber->Append(_("25"));
    SectorNumber->Append(_("26"));
    SectorNumber->Append(_("27"));
    SectorNumber->Append(_("28"));
    SectorNumber->Append(_("29"));
    SectorNumber->Append(_("30"));
    SectorNumber->Append(_("31"));
    SectorNumber->Append(_("32"));
    SectorNumber->Append(_("33"));
    SectorNumber->Append(_("34"));
    SectorNumber->Append(_("35"));
    SectorNumber->Append(_("36"));
    SectorNumber->Append(_("37"));
    SectorNumber->Append(_("38"));
    SectorNumber->Append(_("39"));
    BoxSizer17->Add(SectorNumber, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    StaticText107 = new wxStaticText(Panel6, ID_STATICTEXT108, _("(0 - 31 for 2K cards) and (0 - 39 for 4K cards)"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT108"));
    BoxSizer17->Add(StaticText107, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    StaticBoxSizer13->Add(BoxSizer17, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    StaticBoxSizer12->Add(StaticBoxSizer13, 0, wxALL|wxEXPAND, 3);
    StaticBoxSizer14 = new wxStaticBoxSizer(wxVERTICAL, Panel6, _("Provided AES key"));
    StaticText26 = new wxStaticText(Panel6, ID_STATICTEXT27, _("Enter old AES sector key (16 bytes):"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT27"));
    StaticBoxSizer14->Add(StaticText26, 0, wxALL|wxALIGN_LEFT, 3);
    OldAesSectorKeyTB = new wxTextCtrl(Panel6, ID_TEXTCTRL21, _("FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF"), wxDefaultPosition, wxSize(203,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL21"));
    OldAesSectorKeyTB->SetMaxLength(32);
    StaticBoxSizer14->Add(OldAesSectorKeyTB, 1, wxALL|wxALIGN_LEFT, 3);
    StaticText27 = new wxStaticText(Panel6, ID_STATICTEXT28, _("Enter new AES sector key (16 bytes):"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT28"));
    StaticBoxSizer14->Add(StaticText27, 0, wxALL|wxALIGN_LEFT, 3);
    NewAesSectorKeyTB = new wxTextCtrl(Panel6, ID_TEXTCTRL22, _("FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF"), wxDefaultPosition, wxSize(203,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL22"));
    NewAesSectorKeyTB->SetMaxLength(32);
    StaticBoxSizer14->Add(NewAesSectorKeyTB, 1, wxALL|wxALIGN_LEFT, 3);
    StaticBoxSizer12->Add(StaticBoxSizer14, 0, wxALL|wxEXPAND, 3);
    StaticBoxSizer15 = new wxStaticBoxSizer(wxVERTICAL, Panel6, _("Reader AES key"));
    StaticText28 = new wxStaticText(Panel6, ID_STATICTEXT29, _("Enter reader key index for old AES sector key (0 - 15):"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT29"));
    StaticBoxSizer15->Add(StaticText28, 0, wxALL|wxALIGN_LEFT, 3);
    AESKeyIndex = new wxComboBox(Panel6, ID_COMBOBOX6, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, wxCB_READONLY, wxDefaultValidator, _T("ID_COMBOBOX6"));
    AESKeyIndex->SetSelection( AESKeyIndex->Append(_("0")) );
    AESKeyIndex->Append(_("1"));
    AESKeyIndex->Append(_("2"));
    AESKeyIndex->Append(_("3"));
    AESKeyIndex->Append(_("4"));
    AESKeyIndex->Append(_("5"));
    AESKeyIndex->Append(_("6"));
    AESKeyIndex->Append(_("7"));
    AESKeyIndex->Append(_("8"));
    AESKeyIndex->Append(_("9"));
    AESKeyIndex->Append(_("10"));
    AESKeyIndex->Append(_("11"));
    AESKeyIndex->Append(_("12"));
    AESKeyIndex->Append(_("13"));
    AESKeyIndex->Append(_("14"));
    AESKeyIndex->Append(_("15"));
    StaticBoxSizer15->Add(AESKeyIndex, 0, wxALL|wxALIGN_LEFT, 3);
    StaticText29 = new wxStaticText(Panel6, ID_STATICTEXT30, _("Enter new AES sector key (16 bytes):"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT30"));
    StaticBoxSizer15->Add(StaticText29, 0, wxALL|wxALIGN_LEFT, 3);
    BoxSizer68 = new wxBoxSizer(wxHORIZONTAL);
    NewAesSectorKeyRK = new wxTextCtrl(Panel6, ID_TEXTCTRL23, _("FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF"), wxDefaultPosition, wxSize(203,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL23"));
    NewAesSectorKeyRK->SetMaxLength(32);
    BoxSizer68->Add(NewAesSectorKeyRK, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    bChangeSectorKeys = new wxButton(Panel6, ID_BUTTON7, _("Change sector key"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON7"));
    BoxSizer68->Add(bChangeSectorKeys, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    StaticBoxSizer15->Add(BoxSizer68, 1, wxALL|wxEXPAND, 3);
    StaticBoxSizer12->Add(StaticBoxSizer15, 0, wxALL|wxEXPAND, 3);
    Panel6->SetSizer(StaticBoxSizer12);
    StaticBoxSizer12->Fit(Panel6);
    StaticBoxSizer12->SetSizeHints(Panel6);
    Panel7 = new wxPanel(Notebook1, ID_PANEL7, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL7"));
    StaticBoxSizer16 = new wxStaticBoxSizer(wxVERTICAL, Panel7, wxEmptyString);
    StaticBoxSizer17 = new wxStaticBoxSizer(wxVERTICAL, Panel7, _("Random ID option"));
    RB_UseRandomID = new wxRadioButton(Panel7, ID_RADIOBUTTON5, _("Use random ID"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON5"));
    StaticBoxSizer17->Add(RB_UseRandomID, 0, wxALL|wxALIGN_LEFT, 3);
    RB_UseUID = new wxRadioButton(Panel7, ID_RADIOBUTTON6, _("Use UID"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON6"));
    RB_UseUID->SetValue(true);
    StaticBoxSizer17->Add(RB_UseUID, 0, wxALL|wxALIGN_LEFT, 3);
    StaticBoxSizer16->Add(StaticBoxSizer17, 0, wxALL|wxEXPAND, 3);
    StaticBoxSizer18 = new wxStaticBoxSizer(wxVERTICAL, Panel7, _("Provided AES key"));
    StaticText30 = new wxStaticText(Panel7, ID_STATICTEXT31, _("Enter configuration key (16 bytes):"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT31"));
    StaticBoxSizer18->Add(StaticText30, 0, wxALL|wxALIGN_LEFT, 3);
    FieldConfKeyTB = new wxTextCtrl(Panel7, ID_TEXTCTRL24, _("FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF"), wxDefaultPosition, wxSize(203,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL24"));
    FieldConfKeyTB->SetMaxLength(32);
    StaticBoxSizer18->Add(FieldConfKeyTB, 1, wxALL|wxALIGN_LEFT, 5);
    StaticBoxSizer16->Add(StaticBoxSizer18, 0, wxALL|wxEXPAND, 3);
    StaticBoxSizer19 = new wxStaticBoxSizer(wxVERTICAL, Panel7, _("Reader AES key"));
    StaticText31 = new wxStaticText(Panel7, ID_STATICTEXT32, _("Enter reader key index for old configuration key (0 - 15):"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT32"));
    StaticBoxSizer19->Add(StaticText31, 0, wxALL|wxALIGN_LEFT, 3);
    FieldConfKeyIndex = new wxComboBox(Panel7, ID_COMBOBOX7, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, wxCB_READONLY, wxDefaultValidator, _T("ID_COMBOBOX7"));
    FieldConfKeyIndex->SetSelection( FieldConfKeyIndex->Append(_("0")) );
    FieldConfKeyIndex->Append(_("1"));
    FieldConfKeyIndex->Append(_("2"));
    FieldConfKeyIndex->Append(_("3"));
    FieldConfKeyIndex->Append(_("4"));
    FieldConfKeyIndex->Append(_("5"));
    FieldConfKeyIndex->Append(_("6"));
    FieldConfKeyIndex->Append(_("7"));
    FieldConfKeyIndex->Append(_("8"));
    FieldConfKeyIndex->Append(_("9"));
    FieldConfKeyIndex->Append(_("10"));
    FieldConfKeyIndex->Append(_("11"));
    FieldConfKeyIndex->Append(_("12"));
    FieldConfKeyIndex->Append(_("13"));
    FieldConfKeyIndex->Append(_("14"));
    FieldConfKeyIndex->Append(_("15"));
    StaticBoxSizer19->Add(FieldConfKeyIndex, 0, wxALL|wxALIGN_LEFT, 3);
    StaticBoxSizer16->Add(StaticBoxSizer19, 0, wxALL|wxEXPAND, 3);
    bSetFieldConfiguration = new wxButton(Panel7, ID_BUTTON8, _("Set field configuration"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON8"));
    StaticBoxSizer16->Add(bSetFieldConfiguration, 0, wxALL|wxALIGN_LEFT, 3);
    Panel7->SetSizer(StaticBoxSizer16);
    StaticBoxSizer16->Fit(Panel7);
    StaticBoxSizer16->SetSizeHints(Panel7);
    Panel8 = new wxPanel(Notebook1, ID_PANEL8, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL8"));
    StaticBoxSizer20 = new wxStaticBoxSizer(wxVERTICAL, Panel8, wxEmptyString);
    StaticBoxSizer21 = new wxStaticBoxSizer(wxVERTICAL, Panel8, _("Provided AES key"));
    StaticText32 = new wxStaticText(Panel8, ID_STATICTEXT33, _("Enter VC polling ENC key (16 bytes):"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT33"));
    StaticBoxSizer21->Add(StaticText32, 0, wxALL|wxALIGN_LEFT, 3);
    ENCKeyTB = new wxTextCtrl(Panel8, ID_TEXTCTRL25, _("FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF"), wxDefaultPosition, wxSize(203,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL25"));
    ENCKeyTB->SetMaxLength(32);
    StaticBoxSizer21->Add(ENCKeyTB, 1, wxALL|wxALIGN_LEFT, 3);
    StaticText33 = new wxStaticText(Panel8, ID_STATICTEXT34, _("Enter VC polling MAC key (16 bytes):"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT34"));
    StaticBoxSizer21->Add(StaticText33, 0, wxALL|wxALIGN_LEFT, 3);
    MACKeyTB = new wxTextCtrl(Panel8, ID_TEXTCTRL26, _("FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF"), wxDefaultPosition, wxSize(203,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL26"));
    MACKeyTB->SetMaxLength(32);
    StaticBoxSizer21->Add(MACKeyTB, 1, wxALL|wxALIGN_LEFT, 3);
    StaticBoxSizer20->Add(StaticBoxSizer21, 0, wxALL|wxEXPAND, 3);
    StaticBoxSizer22 = new wxStaticBoxSizer(wxVERTICAL, Panel8, _("Reader AES key"));
    StaticText34 = new wxStaticText(Panel8, ID_STATICTEXT35, _("Enter reader key index for VC polling ENC key (0 - 15):"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT35"));
    StaticBoxSizer22->Add(StaticText34, 0, wxALL|wxALIGN_LEFT, 3);
    ENCKeyIndex = new wxComboBox(Panel8, ID_COMBOBOX8, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, wxCB_READONLY, wxDefaultValidator, _T("ID_COMBOBOX8"));
    ENCKeyIndex->SetSelection( ENCKeyIndex->Append(_("0")) );
    ENCKeyIndex->Append(_("1"));
    ENCKeyIndex->Append(_("2"));
    ENCKeyIndex->Append(_("3"));
    ENCKeyIndex->Append(_("4"));
    ENCKeyIndex->Append(_("5"));
    ENCKeyIndex->Append(_("6"));
    ENCKeyIndex->Append(_("7"));
    ENCKeyIndex->Append(_("8"));
    ENCKeyIndex->Append(_("9"));
    ENCKeyIndex->Append(_("10"));
    ENCKeyIndex->Append(_("11"));
    ENCKeyIndex->Append(_("12"));
    ENCKeyIndex->Append(_("13"));
    ENCKeyIndex->Append(_("14"));
    ENCKeyIndex->Append(_("15"));
    StaticBoxSizer22->Add(ENCKeyIndex, 0, wxALL|wxALIGN_LEFT, 3);
    StaticText35 = new wxStaticText(Panel8, ID_STATICTEXT36, _("Enter reader key index for VC polling MAC key (0 - 15):"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT36"));
    StaticBoxSizer22->Add(StaticText35, 0, wxALL|wxALIGN_LEFT, 3);
    MACKeyIndex = new wxComboBox(Panel8, ID_COMBOBOX9, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, wxCB_READONLY, wxDefaultValidator, _T("ID_COMBOBOX9"));
    MACKeyIndex->SetSelection( MACKeyIndex->Append(_("0")) );
    MACKeyIndex->Append(_("1"));
    MACKeyIndex->Append(_("2"));
    MACKeyIndex->Append(_("3"));
    MACKeyIndex->Append(_("4"));
    MACKeyIndex->Append(_("5"));
    MACKeyIndex->Append(_("6"));
    MACKeyIndex->Append(_("7"));
    MACKeyIndex->Append(_("8"));
    MACKeyIndex->Append(_("9"));
    MACKeyIndex->Append(_("10"));
    MACKeyIndex->Append(_("11"));
    MACKeyIndex->Append(_("12"));
    MACKeyIndex->Append(_("13"));
    MACKeyIndex->Append(_("14"));
    MACKeyIndex->Append(_("15"));
    StaticBoxSizer22->Add(MACKeyIndex, 0, wxALL|wxALIGN_LEFT, 3);
    StaticBoxSizer20->Add(StaticBoxSizer22, 0, wxALL|wxEXPAND, 3);
    bGetENCMACUid = new wxButton(Panel8, ID_BUTTON9, _("Get card UID"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON9"));
    StaticBoxSizer20->Add(bGetENCMACUid, 0, wxALL|wxALIGN_LEFT, 3);
    BoxSizer18 = new wxBoxSizer(wxHORIZONTAL);
    StaticText44 = new wxStaticText(Panel8, ID_STATICTEXT45, _("Card UID :"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT45"));
    BoxSizer18->Add(StaticText44, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    ENCMACUidTB = new wxTextCtrl(Panel8, ID_TEXTCTRL33, wxEmptyString, wxDefaultPosition, wxSize(203,-1), wxTE_READONLY|wxTE_CENTRE, wxDefaultValidator, _T("ID_TEXTCTRL33"));
    wxFont ENCMACUidTBFont(14,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Courier New"),wxFONTENCODING_DEFAULT);
    ENCMACUidTB->SetFont(ENCMACUidTBFont);
    BoxSizer18->Add(ENCMACUidTB, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    StaticBoxSizer20->Add(BoxSizer18, 0, wxALL|wxALIGN_LEFT, 3);
    Panel8->SetSizer(StaticBoxSizer20);
    StaticBoxSizer20->Fit(Panel8);
    StaticBoxSizer20->SetSizeHints(Panel8);
    Panel9 = new wxPanel(Notebook1, ID_PANEL9, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL9"));
    StaticBoxSizer23 = new wxStaticBoxSizer(wxVERTICAL, Panel9, wxEmptyString);
    StaticBoxSizer24 = new wxStaticBoxSizer(wxVERTICAL, Panel9, _("Provided AES key"));
    StaticText36 = new wxStaticText(Panel9, ID_STATICTEXT37, _("Enter card configuration key (16 bytes):"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT37"));
    StaticBoxSizer24->Add(StaticText36, 0, wxALL|wxALIGN_LEFT, 3);
    CardConfigurationKeyTB = new wxTextCtrl(Panel9, ID_TEXTCTRL27, _("FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF"), wxDefaultPosition, wxSize(203,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL27"));
    CardConfigurationKeyTB->SetMaxLength(32);
    StaticBoxSizer24->Add(CardConfigurationKeyTB, 1, wxALL|wxALIGN_LEFT, 5);
    StaticText37 = new wxStaticText(Panel9, ID_STATICTEXT38, _("Enter new VC polling ENC key (16 bytes):"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT38"));
    StaticBoxSizer24->Add(StaticText37, 0, wxALL|wxALIGN_LEFT, 3);
    NewVCPollingENCKeyTB = new wxTextCtrl(Panel9, ID_TEXTCTRL28, _("FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF"), wxDefaultPosition, wxSize(203,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL28"));
    NewVCPollingENCKeyTB->SetMaxLength(32);
    StaticBoxSizer24->Add(NewVCPollingENCKeyTB, 0, wxALL|wxALIGN_LEFT, 3);
    StaticBoxSizer23->Add(StaticBoxSizer24, 0, wxALL|wxEXPAND, 3);
    StaticBoxSizer25 = new wxStaticBoxSizer(wxVERTICAL, Panel9, _("Reader AES key"));
    StaticText38 = new wxStaticText(Panel9, ID_STATICTEXT39, _("Enter reader key index for configuration key (0 - 15):"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT39"));
    StaticBoxSizer25->Add(StaticText38, 0, wxALL|wxALIGN_LEFT, 3);
    ConfRK = new wxComboBox(Panel9, ID_COMBOBOX10, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, wxCB_READONLY, wxDefaultValidator, _T("ID_COMBOBOX10"));
    ConfRK->SetSelection( ConfRK->Append(_("0")) );
    ConfRK->Append(_("1"));
    ConfRK->Append(_("2"));
    ConfRK->Append(_("3"));
    ConfRK->Append(_("4"));
    ConfRK->Append(_("5"));
    ConfRK->Append(_("6"));
    ConfRK->Append(_("7"));
    ConfRK->Append(_("8"));
    ConfRK->Append(_("9"));
    ConfRK->Append(_("10"));
    ConfRK->Append(_("11"));
    ConfRK->Append(_("12"));
    ConfRK->Append(_("13"));
    ConfRK->Append(_("14"));
    ConfRK->Append(_("15"));
    StaticBoxSizer25->Add(ConfRK, 0, wxALL|wxALIGN_LEFT, 3);
    StaticText39 = new wxStaticText(Panel9, ID_STATICTEXT40, _("Enter new card VC polling ENC key (16 bytes):"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT40"));
    StaticBoxSizer25->Add(StaticText39, 0, wxALL|wxALIGN_LEFT, 3);
    NewVCPollingENCKeyRK = new wxTextCtrl(Panel9, ID_TEXTCTRL29, _("FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF"), wxDefaultPosition, wxSize(203,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL29"));
    NewVCPollingENCKeyRK->SetMaxLength(32);
    StaticBoxSizer25->Add(NewVCPollingENCKeyRK, 1, wxALL|wxALIGN_LEFT, 3);
    StaticBoxSizer23->Add(StaticBoxSizer25, 0, wxALL|wxEXPAND, 3);
    bChangeVCPollingENCKey = new wxButton(Panel9, ID_BUTTON10, _("Change VC polling ENC key"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON10"));
    StaticBoxSizer23->Add(bChangeVCPollingENCKey, 0, wxALL|wxALIGN_LEFT, 3);
    Panel9->SetSizer(StaticBoxSizer23);
    StaticBoxSizer23->Fit(Panel9);
    StaticBoxSizer23->SetSizeHints(Panel9);
    Panel10 = new wxPanel(Notebook1, ID_PANEL10, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL10"));
    StaticBoxSizer26 = new wxStaticBoxSizer(wxVERTICAL, Panel10, wxEmptyString);
    StaticBoxSizer27 = new wxStaticBoxSizer(wxVERTICAL, Panel10, _("Provided AES key"));
    StaticText40 = new wxStaticText(Panel10, ID_STATICTEXT41, _("Enter card configuration key (16 bytes):"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT41"));
    StaticBoxSizer27->Add(StaticText40, 0, wxALL|wxALIGN_LEFT, 3);
    CurrentConfKeyTB = new wxTextCtrl(Panel10, ID_TEXTCTRL30, _("FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF"), wxDefaultPosition, wxSize(203,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL30"));
    CurrentConfKeyTB->SetMaxLength(32);
    StaticBoxSizer27->Add(CurrentConfKeyTB, 1, wxALL|wxALIGN_LEFT, 3);
    StaticText41 = new wxStaticText(Panel10, ID_STATICTEXT42, _("Enter new VC polling MAC key (16 bytes):"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT42"));
    StaticBoxSizer27->Add(StaticText41, 0, wxALL|wxALIGN_LEFT, 3);
    NewMACTB = new wxTextCtrl(Panel10, ID_TEXTCTRL31, _("FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF"), wxDefaultPosition, wxSize(203,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL31"));
    NewMACTB->SetMaxLength(32);
    StaticBoxSizer27->Add(NewMACTB, 1, wxALL|wxALIGN_LEFT, 3);
    StaticBoxSizer26->Add(StaticBoxSizer27, 0, wxALL|wxEXPAND, 3);
    StaticBoxSizer28 = new wxStaticBoxSizer(wxVERTICAL, Panel10, _("Reader AES key"));
    StaticText42 = new wxStaticText(Panel10, ID_STATICTEXT43, _("Enter reader key index for configuration key (0 - 15):"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT43"));
    StaticBoxSizer28->Add(StaticText42, 0, wxALL|wxALIGN_LEFT, 3);
    CurrentConfIndex = new wxComboBox(Panel10, ID_COMBOBOX11, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, wxCB_READONLY, wxDefaultValidator, _T("ID_COMBOBOX11"));
    CurrentConfIndex->SetSelection( CurrentConfIndex->Append(_("0")) );
    CurrentConfIndex->Append(_("1"));
    CurrentConfIndex->Append(_("2"));
    CurrentConfIndex->Append(_("3"));
    CurrentConfIndex->Append(_("4"));
    CurrentConfIndex->Append(_("5"));
    CurrentConfIndex->Append(_("6"));
    CurrentConfIndex->Append(_("7"));
    CurrentConfIndex->Append(_("8"));
    CurrentConfIndex->Append(_("9"));
    CurrentConfIndex->Append(_("10"));
    CurrentConfIndex->Append(_("11"));
    CurrentConfIndex->Append(_("12"));
    CurrentConfIndex->Append(_("13"));
    CurrentConfIndex->Append(_("14"));
    CurrentConfIndex->Append(_("15"));
    StaticBoxSizer28->Add(CurrentConfIndex, 0, wxALL|wxALIGN_LEFT, 3);
    StaticText43 = new wxStaticText(Panel10, ID_STATICTEXT44, _("Enter new card VC polling MAC key (16 bytes):"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT44"));
    StaticBoxSizer28->Add(StaticText43, 0, wxALL|wxALIGN_LEFT, 3);
    NewMACTB_RK = new wxTextCtrl(Panel10, ID_TEXTCTRL32, _("FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF"), wxDefaultPosition, wxSize(203,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL32"));
    NewMACTB_RK->SetMaxLength(32);
    StaticBoxSizer28->Add(NewMACTB_RK, 0, wxALL|wxALIGN_LEFT, 3);
    StaticBoxSizer26->Add(StaticBoxSizer28, 0, wxALL|wxEXPAND, 3);
    bChangeVCpolingMACKey = new wxButton(Panel10, ID_BUTTON11, _("Change VC polling MAC key"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON11"));
    StaticBoxSizer26->Add(bChangeVCpolingMACKey, 0, wxALL|wxALIGN_LEFT, 3);
    Panel10->SetSizer(StaticBoxSizer26);
    StaticBoxSizer26->Fit(Panel10);
    StaticBoxSizer26->SetSizeHints(Panel10);
    Panel11 = new wxPanel(Notebook1, ID_PANEL11, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL11"));
    StaticBoxSizer38 = new wxStaticBoxSizer(wxHORIZONTAL, Panel11, wxEmptyString);
    Notebook2 = new wxNotebook(Panel11, ID_NOTEBOOK2, wxDefaultPosition, wxDefaultSize, 0, _T("ID_NOTEBOOK2"));
    Panel14 = new wxPanel(Notebook2, ID_PANEL14, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL14"));
    StaticBoxSizer39 = new wxStaticBoxSizer(wxVERTICAL, Panel14, wxEmptyString);
    BoxSizer9 = new wxBoxSizer(wxHORIZONTAL);
    StaticBoxSizer40 = new wxStaticBoxSizer(wxVERTICAL, Panel14, _("Provided  key"));
    BoxSizer11 = new wxBoxSizer(wxVERTICAL);
    BoxSizer12 = new wxBoxSizer(wxHORIZONTAL);
    BR_Provided_A = new wxRadioButton(Panel14, ID_RADIOBUTTON7, _("KEY A"), wxDefaultPosition, wxDefaultSize, wxRB_GROUP, wxDefaultValidator, _T("ID_RADIOBUTTON7"));
    BR_Provided_A->SetValue(true);
    BoxSizer12->Add(BR_Provided_A, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    BR_Provided_B = new wxRadioButton(Panel14, ID_RADIOBUTTON8, _("KEY B"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON8"));
    BoxSizer12->Add(BR_Provided_B, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    BoxSizer12->Add(-1,-1,0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    StaticText52 = new wxStaticText(Panel14, ID_STATICTEXT53, _("Block number:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT53"));
    BoxSizer12->Add(StaticText52, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BR_BlockNr = new wxComboBox(Panel14, ID_COMBOBOX14, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, wxCB_READONLY, wxDefaultValidator, _T("ID_COMBOBOX14"));
    BR_BlockNr->SetSelection( BR_BlockNr->Append(_("0")) );
    BR_BlockNr->Append(_("1"));
    BR_BlockNr->Append(_("2"));
    BR_BlockNr->Append(_("3"));
    BR_BlockNr->Append(_("4"));
    BR_BlockNr->Append(_("5"));
    BR_BlockNr->Append(_("6"));
    BR_BlockNr->Append(_("7"));
    BR_BlockNr->Append(_("8"));
    BR_BlockNr->Append(_("9"));
    BR_BlockNr->Append(_("10"));
    BR_BlockNr->Append(_("11"));
    BR_BlockNr->Append(_("12"));
    BR_BlockNr->Append(_("13"));
    BR_BlockNr->Append(_("14"));
    BR_BlockNr->Append(_("15"));
    BR_BlockNr->Append(_("16"));
    BR_BlockNr->Append(_("17"));
    BR_BlockNr->Append(_("18"));
    BR_BlockNr->Append(_("19"));
    BR_BlockNr->Append(_("20"));
    BR_BlockNr->Append(_("21"));
    BR_BlockNr->Append(_("22"));
    BR_BlockNr->Append(_("23"));
    BR_BlockNr->Append(_("24"));
    BR_BlockNr->Append(_("25"));
    BR_BlockNr->Append(_("26"));
    BR_BlockNr->Append(_("27"));
    BR_BlockNr->Append(_("28"));
    BR_BlockNr->Append(_("29"));
    BR_BlockNr->Append(_("30"));
    BR_BlockNr->Append(_("31"));
    BR_BlockNr->Append(_("32"));
    BR_BlockNr->Append(_("33"));
    BR_BlockNr->Append(_("34"));
    BR_BlockNr->Append(_("35"));
    BR_BlockNr->Append(_("36"));
    BR_BlockNr->Append(_("37"));
    BR_BlockNr->Append(_("38"));
    BR_BlockNr->Append(_("39"));
    BR_BlockNr->Append(_("40"));
    BR_BlockNr->Append(_("41"));
    BR_BlockNr->Append(_("42"));
    BR_BlockNr->Append(_("43"));
    BR_BlockNr->Append(_("44"));
    BR_BlockNr->Append(_("45"));
    BR_BlockNr->Append(_("46"));
    BR_BlockNr->Append(_("47"));
    BR_BlockNr->Append(_("48"));
    BR_BlockNr->Append(_("49"));
    BR_BlockNr->Append(_("50"));
    BR_BlockNr->Append(_("51"));
    BR_BlockNr->Append(_("52"));
    BR_BlockNr->Append(_("53"));
    BR_BlockNr->Append(_("54"));
    BR_BlockNr->Append(_("55"));
    BR_BlockNr->Append(_("56"));
    BR_BlockNr->Append(_("57"));
    BR_BlockNr->Append(_("58"));
    BR_BlockNr->Append(_("59"));
    BR_BlockNr->Append(_("60"));
    BR_BlockNr->Append(_("61"));
    BR_BlockNr->Append(_("62"));
    BR_BlockNr->Append(_("63"));
    BR_BlockNr->Append(_("64"));
    BR_BlockNr->Append(_("65"));
    BR_BlockNr->Append(_("66"));
    BR_BlockNr->Append(_("67"));
    BR_BlockNr->Append(_("68"));
    BR_BlockNr->Append(_("69"));
    BR_BlockNr->Append(_("70"));
    BR_BlockNr->Append(_("71"));
    BR_BlockNr->Append(_("72"));
    BR_BlockNr->Append(_("73"));
    BR_BlockNr->Append(_("74"));
    BR_BlockNr->Append(_("75"));
    BR_BlockNr->Append(_("76"));
    BR_BlockNr->Append(_("77"));
    BR_BlockNr->Append(_("78"));
    BR_BlockNr->Append(_("79"));
    BR_BlockNr->Append(_("80"));
    BR_BlockNr->Append(_("81"));
    BR_BlockNr->Append(_("82"));
    BR_BlockNr->Append(_("83"));
    BR_BlockNr->Append(_("84"));
    BR_BlockNr->Append(_("85"));
    BR_BlockNr->Append(_("86"));
    BR_BlockNr->Append(_("87"));
    BR_BlockNr->Append(_("88"));
    BR_BlockNr->Append(_("89"));
    BR_BlockNr->Append(_("90"));
    BR_BlockNr->Append(_("91"));
    BR_BlockNr->Append(_("92"));
    BR_BlockNr->Append(_("93"));
    BR_BlockNr->Append(_("94"));
    BR_BlockNr->Append(_("95"));
    BR_BlockNr->Append(_("96"));
    BR_BlockNr->Append(_("97"));
    BR_BlockNr->Append(_("98"));
    BR_BlockNr->Append(_("99"));
    BR_BlockNr->Append(_("100"));
    BR_BlockNr->Append(_("101"));
    BR_BlockNr->Append(_("102"));
    BR_BlockNr->Append(_("103"));
    BR_BlockNr->Append(_("104"));
    BR_BlockNr->Append(_("105"));
    BR_BlockNr->Append(_("106"));
    BR_BlockNr->Append(_("107"));
    BR_BlockNr->Append(_("108"));
    BR_BlockNr->Append(_("109"));
    BR_BlockNr->Append(_("110"));
    BR_BlockNr->Append(_("111"));
    BR_BlockNr->Append(_("112"));
    BR_BlockNr->Append(_("113"));
    BR_BlockNr->Append(_("114"));
    BR_BlockNr->Append(_("115"));
    BR_BlockNr->Append(_("116"));
    BR_BlockNr->Append(_("117"));
    BR_BlockNr->Append(_("118"));
    BR_BlockNr->Append(_("119"));
    BR_BlockNr->Append(_("120"));
    BR_BlockNr->Append(_("121"));
    BR_BlockNr->Append(_("122"));
    BR_BlockNr->Append(_("123"));
    BR_BlockNr->Append(_("124"));
    BR_BlockNr->Append(_("125"));
    BR_BlockNr->Append(_("126"));
    BR_BlockNr->Append(_("127"));
    BR_BlockNr->Append(_("128"));
    BR_BlockNr->Append(_("129"));
    BR_BlockNr->Append(_("130"));
    BR_BlockNr->Append(_("131"));
    BR_BlockNr->Append(_("132"));
    BR_BlockNr->Append(_("133"));
    BR_BlockNr->Append(_("134"));
    BR_BlockNr->Append(_("135"));
    BR_BlockNr->Append(_("136"));
    BR_BlockNr->Append(_("137"));
    BR_BlockNr->Append(_("138"));
    BR_BlockNr->Append(_("139"));
    BR_BlockNr->Append(_("140"));
    BR_BlockNr->Append(_("141"));
    BR_BlockNr->Append(_("142"));
    BR_BlockNr->Append(_("143"));
    BR_BlockNr->Append(_("144"));
    BR_BlockNr->Append(_("145"));
    BR_BlockNr->Append(_("146"));
    BR_BlockNr->Append(_("147"));
    BR_BlockNr->Append(_("148"));
    BR_BlockNr->Append(_("149"));
    BR_BlockNr->Append(_("150"));
    BR_BlockNr->Append(_("151"));
    BR_BlockNr->Append(_("152"));
    BR_BlockNr->Append(_("153"));
    BR_BlockNr->Append(_("154"));
    BR_BlockNr->Append(_("155"));
    BR_BlockNr->Append(_("156"));
    BR_BlockNr->Append(_("157"));
    BR_BlockNr->Append(_("158"));
    BR_BlockNr->Append(_("159"));
    BR_BlockNr->Append(_("160"));
    BR_BlockNr->Append(_("161"));
    BR_BlockNr->Append(_("162"));
    BR_BlockNr->Append(_("163"));
    BR_BlockNr->Append(_("164"));
    BR_BlockNr->Append(_("165"));
    BR_BlockNr->Append(_("166"));
    BR_BlockNr->Append(_("167"));
    BR_BlockNr->Append(_("168"));
    BR_BlockNr->Append(_("169"));
    BR_BlockNr->Append(_("170"));
    BR_BlockNr->Append(_("171"));
    BR_BlockNr->Append(_("172"));
    BR_BlockNr->Append(_("173"));
    BR_BlockNr->Append(_("174"));
    BR_BlockNr->Append(_("175"));
    BR_BlockNr->Append(_("176"));
    BR_BlockNr->Append(_("177"));
    BR_BlockNr->Append(_("178"));
    BR_BlockNr->Append(_("179"));
    BR_BlockNr->Append(_("180"));
    BR_BlockNr->Append(_("181"));
    BR_BlockNr->Append(_("182"));
    BR_BlockNr->Append(_("183"));
    BR_BlockNr->Append(_("184"));
    BR_BlockNr->Append(_("185"));
    BR_BlockNr->Append(_("186"));
    BR_BlockNr->Append(_("187"));
    BR_BlockNr->Append(_("188"));
    BR_BlockNr->Append(_("189"));
    BR_BlockNr->Append(_("190"));
    BR_BlockNr->Append(_("191"));
    BR_BlockNr->Append(_("192"));
    BR_BlockNr->Append(_("193"));
    BR_BlockNr->Append(_("194"));
    BR_BlockNr->Append(_("195"));
    BR_BlockNr->Append(_("196"));
    BR_BlockNr->Append(_("197"));
    BR_BlockNr->Append(_("198"));
    BR_BlockNr->Append(_("199"));
    BR_BlockNr->Append(_("200"));
    BR_BlockNr->Append(_("201"));
    BR_BlockNr->Append(_("202"));
    BR_BlockNr->Append(_("203"));
    BR_BlockNr->Append(_("204"));
    BR_BlockNr->Append(_("205"));
    BR_BlockNr->Append(_("206"));
    BR_BlockNr->Append(_("207"));
    BR_BlockNr->Append(_("208"));
    BR_BlockNr->Append(_("209"));
    BR_BlockNr->Append(_("210"));
    BR_BlockNr->Append(_("211"));
    BR_BlockNr->Append(_("212"));
    BR_BlockNr->Append(_("213"));
    BR_BlockNr->Append(_("214"));
    BR_BlockNr->Append(_("215"));
    BR_BlockNr->Append(_("216"));
    BR_BlockNr->Append(_("217"));
    BR_BlockNr->Append(_("218"));
    BR_BlockNr->Append(_("219"));
    BR_BlockNr->Append(_("220"));
    BR_BlockNr->Append(_("221"));
    BR_BlockNr->Append(_("222"));
    BR_BlockNr->Append(_("223"));
    BR_BlockNr->Append(_("224"));
    BR_BlockNr->Append(_("225"));
    BR_BlockNr->Append(_("226"));
    BR_BlockNr->Append(_("227"));
    BR_BlockNr->Append(_("228"));
    BR_BlockNr->Append(_("229"));
    BR_BlockNr->Append(_("230"));
    BR_BlockNr->Append(_("231"));
    BR_BlockNr->Append(_("232"));
    BR_BlockNr->Append(_("233"));
    BR_BlockNr->Append(_("234"));
    BR_BlockNr->Append(_("235"));
    BR_BlockNr->Append(_("236"));
    BR_BlockNr->Append(_("237"));
    BR_BlockNr->Append(_("238"));
    BR_BlockNr->Append(_("239"));
    BR_BlockNr->Append(_("240"));
    BR_BlockNr->Append(_("241"));
    BR_BlockNr->Append(_("242"));
    BR_BlockNr->Append(_("243"));
    BR_BlockNr->Append(_("244"));
    BR_BlockNr->Append(_("245"));
    BR_BlockNr->Append(_("246"));
    BR_BlockNr->Append(_("247"));
    BR_BlockNr->Append(_("248"));
    BR_BlockNr->Append(_("249"));
    BR_BlockNr->Append(_("250"));
    BR_BlockNr->Append(_("251"));
    BR_BlockNr->Append(_("252"));
    BR_BlockNr->Append(_("253"));
    BR_BlockNr->Append(_("254"));
    BR_BlockNr->Append(_("255"));
    BoxSizer12->Add(BR_BlockNr, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    BoxSizer11->Add(BoxSizer12, 0, wxALL|wxEXPAND, 3);
    BoxSizer21 = new wxBoxSizer(wxHORIZONTAL);
    StaticText51 = new wxStaticText(Panel14, ID_STATICTEXT52, _("Key:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT52"));
    BoxSizer21->Add(StaticText51, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    BR_Key = new wxTextCtrl(Panel14, ID_TEXTCTRL38, wxEmptyString, wxDefaultPosition, wxSize(203,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL38"));
    BR_Key->SetMaxLength(32);
    BoxSizer21->Add(BR_Key, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    BoxSizer11->Add(BoxSizer21, 0, wxALL|wxEXPAND, 3);
    bBRProvidedKey = new wxButton(Panel14, ID_BUTTON16, _("Block read provided key"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON16"));
    BoxSizer11->Add(bBRProvidedKey, 1, wxALL|wxALIGN_LEFT, 5);
    StaticBoxSizer40->Add(BoxSizer11, 0, wxALL|wxEXPAND, 3);
    BoxSizer9->Add(StaticBoxSizer40, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    StaticBoxSizer41 = new wxStaticBoxSizer(wxVERTICAL, Panel14, _("Reader key"));
    BoxSizer22 = new wxBoxSizer(wxHORIZONTAL);
    BR_Reader_KeyA = new wxRadioButton(Panel14, ID_RADIOBUTTON9, _("KEY A"), wxDefaultPosition, wxDefaultSize, wxRB_GROUP, wxDefaultValidator, _T("ID_RADIOBUTTON9"));
    BR_Reader_KeyA->SetValue(true);
    BoxSizer22->Add(BR_Reader_KeyA, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    BR_Reader_KeyB = new wxRadioButton(Panel14, ID_RADIOBUTTON10, _("KEY B"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON10"));
    BoxSizer22->Add(BR_Reader_KeyB, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    BoxSizer22->Add(-1,-1,0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    StaticText53 = new wxStaticText(Panel14, ID_STATICTEXT54, _("Block number:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT54"));
    BoxSizer22->Add(StaticText53, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    BR_Reader_BlockNr = new wxComboBox(Panel14, ID_COMBOBOX15, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, wxCB_READONLY, wxDefaultValidator, _T("ID_COMBOBOX15"));
    BR_Reader_BlockNr->SetSelection( BR_Reader_BlockNr->Append(_("0")) );
    BR_Reader_BlockNr->Append(_("1"));
    BR_Reader_BlockNr->Append(_("2"));
    BR_Reader_BlockNr->Append(_("3"));
    BR_Reader_BlockNr->Append(_("4"));
    BR_Reader_BlockNr->Append(_("5"));
    BR_Reader_BlockNr->Append(_("6"));
    BR_Reader_BlockNr->Append(_("7"));
    BR_Reader_BlockNr->Append(_("8"));
    BR_Reader_BlockNr->Append(_("9"));
    BR_Reader_BlockNr->Append(_("10"));
    BR_Reader_BlockNr->Append(_("11"));
    BR_Reader_BlockNr->Append(_("12"));
    BR_Reader_BlockNr->Append(_("13"));
    BR_Reader_BlockNr->Append(_("14"));
    BR_Reader_BlockNr->Append(_("15"));
    BR_Reader_BlockNr->Append(_("16"));
    BR_Reader_BlockNr->Append(_("17"));
    BR_Reader_BlockNr->Append(_("18"));
    BR_Reader_BlockNr->Append(_("19"));
    BR_Reader_BlockNr->Append(_("20"));
    BR_Reader_BlockNr->Append(_("21"));
    BR_Reader_BlockNr->Append(_("22"));
    BR_Reader_BlockNr->Append(_("23"));
    BR_Reader_BlockNr->Append(_("24"));
    BR_Reader_BlockNr->Append(_("25"));
    BR_Reader_BlockNr->Append(_("26"));
    BR_Reader_BlockNr->Append(_("27"));
    BR_Reader_BlockNr->Append(_("28"));
    BR_Reader_BlockNr->Append(_("29"));
    BR_Reader_BlockNr->Append(_("30"));
    BR_Reader_BlockNr->Append(_("31"));
    BR_Reader_BlockNr->Append(_("32"));
    BR_Reader_BlockNr->Append(_("33"));
    BR_Reader_BlockNr->Append(_("34"));
    BR_Reader_BlockNr->Append(_("35"));
    BR_Reader_BlockNr->Append(_("36"));
    BR_Reader_BlockNr->Append(_("37"));
    BR_Reader_BlockNr->Append(_("38"));
    BR_Reader_BlockNr->Append(_("39"));
    BR_Reader_BlockNr->Append(_("40"));
    BR_Reader_BlockNr->Append(_("41"));
    BR_Reader_BlockNr->Append(_("42"));
    BR_Reader_BlockNr->Append(_("43"));
    BR_Reader_BlockNr->Append(_("44"));
    BR_Reader_BlockNr->Append(_("45"));
    BR_Reader_BlockNr->Append(_("46"));
    BR_Reader_BlockNr->Append(_("47"));
    BR_Reader_BlockNr->Append(_("48"));
    BR_Reader_BlockNr->Append(_("49"));
    BR_Reader_BlockNr->Append(_("50"));
    BR_Reader_BlockNr->Append(_("51"));
    BR_Reader_BlockNr->Append(_("52"));
    BR_Reader_BlockNr->Append(_("53"));
    BR_Reader_BlockNr->Append(_("54"));
    BR_Reader_BlockNr->Append(_("55"));
    BR_Reader_BlockNr->Append(_("56"));
    BR_Reader_BlockNr->Append(_("57"));
    BR_Reader_BlockNr->Append(_("58"));
    BR_Reader_BlockNr->Append(_("59"));
    BR_Reader_BlockNr->Append(_("60"));
    BR_Reader_BlockNr->Append(_("61"));
    BR_Reader_BlockNr->Append(_("62"));
    BR_Reader_BlockNr->Append(_("63"));
    BR_Reader_BlockNr->Append(_("64"));
    BR_Reader_BlockNr->Append(_("65"));
    BR_Reader_BlockNr->Append(_("66"));
    BR_Reader_BlockNr->Append(_("67"));
    BR_Reader_BlockNr->Append(_("68"));
    BR_Reader_BlockNr->Append(_("69"));
    BR_Reader_BlockNr->Append(_("70"));
    BR_Reader_BlockNr->Append(_("71"));
    BR_Reader_BlockNr->Append(_("72"));
    BR_Reader_BlockNr->Append(_("73"));
    BR_Reader_BlockNr->Append(_("74"));
    BR_Reader_BlockNr->Append(_("75"));
    BR_Reader_BlockNr->Append(_("76"));
    BR_Reader_BlockNr->Append(_("77"));
    BR_Reader_BlockNr->Append(_("78"));
    BR_Reader_BlockNr->Append(_("79"));
    BR_Reader_BlockNr->Append(_("80"));
    BR_Reader_BlockNr->Append(_("81"));
    BR_Reader_BlockNr->Append(_("82"));
    BR_Reader_BlockNr->Append(_("83"));
    BR_Reader_BlockNr->Append(_("84"));
    BR_Reader_BlockNr->Append(_("85"));
    BR_Reader_BlockNr->Append(_("86"));
    BR_Reader_BlockNr->Append(_("87"));
    BR_Reader_BlockNr->Append(_("88"));
    BR_Reader_BlockNr->Append(_("89"));
    BR_Reader_BlockNr->Append(_("90"));
    BR_Reader_BlockNr->Append(_("91"));
    BR_Reader_BlockNr->Append(_("92"));
    BR_Reader_BlockNr->Append(_("93"));
    BR_Reader_BlockNr->Append(_("94"));
    BR_Reader_BlockNr->Append(_("95"));
    BR_Reader_BlockNr->Append(_("96"));
    BR_Reader_BlockNr->Append(_("97"));
    BR_Reader_BlockNr->Append(_("98"));
    BR_Reader_BlockNr->Append(_("99"));
    BR_Reader_BlockNr->Append(_("100"));
    BR_Reader_BlockNr->Append(_("101"));
    BR_Reader_BlockNr->Append(_("102"));
    BR_Reader_BlockNr->Append(_("103"));
    BR_Reader_BlockNr->Append(_("104"));
    BR_Reader_BlockNr->Append(_("105"));
    BR_Reader_BlockNr->Append(_("106"));
    BR_Reader_BlockNr->Append(_("107"));
    BR_Reader_BlockNr->Append(_("108"));
    BR_Reader_BlockNr->Append(_("109"));
    BR_Reader_BlockNr->Append(_("110"));
    BR_Reader_BlockNr->Append(_("111"));
    BR_Reader_BlockNr->Append(_("112"));
    BR_Reader_BlockNr->Append(_("113"));
    BR_Reader_BlockNr->Append(_("114"));
    BR_Reader_BlockNr->Append(_("115"));
    BR_Reader_BlockNr->Append(_("116"));
    BR_Reader_BlockNr->Append(_("117"));
    BR_Reader_BlockNr->Append(_("118"));
    BR_Reader_BlockNr->Append(_("119"));
    BR_Reader_BlockNr->Append(_("120"));
    BR_Reader_BlockNr->Append(_("121"));
    BR_Reader_BlockNr->Append(_("122"));
    BR_Reader_BlockNr->Append(_("123"));
    BR_Reader_BlockNr->Append(_("124"));
    BR_Reader_BlockNr->Append(_("125"));
    BR_Reader_BlockNr->Append(_("126"));
    BR_Reader_BlockNr->Append(_("127"));
    BR_Reader_BlockNr->Append(_("128"));
    BR_Reader_BlockNr->Append(_("129"));
    BR_Reader_BlockNr->Append(_("130"));
    BR_Reader_BlockNr->Append(_("131"));
    BR_Reader_BlockNr->Append(_("132"));
    BR_Reader_BlockNr->Append(_("133"));
    BR_Reader_BlockNr->Append(_("134"));
    BR_Reader_BlockNr->Append(_("135"));
    BR_Reader_BlockNr->Append(_("136"));
    BR_Reader_BlockNr->Append(_("137"));
    BR_Reader_BlockNr->Append(_("138"));
    BR_Reader_BlockNr->Append(_("139"));
    BR_Reader_BlockNr->Append(_("140"));
    BR_Reader_BlockNr->Append(_("141"));
    BR_Reader_BlockNr->Append(_("142"));
    BR_Reader_BlockNr->Append(_("143"));
    BR_Reader_BlockNr->Append(_("144"));
    BR_Reader_BlockNr->Append(_("145"));
    BR_Reader_BlockNr->Append(_("146"));
    BR_Reader_BlockNr->Append(_("147"));
    BR_Reader_BlockNr->Append(_("148"));
    BR_Reader_BlockNr->Append(_("149"));
    BR_Reader_BlockNr->Append(_("150"));
    BR_Reader_BlockNr->Append(_("151"));
    BR_Reader_BlockNr->Append(_("152"));
    BR_Reader_BlockNr->Append(_("153"));
    BR_Reader_BlockNr->Append(_("154"));
    BR_Reader_BlockNr->Append(_("155"));
    BR_Reader_BlockNr->Append(_("156"));
    BR_Reader_BlockNr->Append(_("157"));
    BR_Reader_BlockNr->Append(_("158"));
    BR_Reader_BlockNr->Append(_("159"));
    BR_Reader_BlockNr->Append(_("160"));
    BR_Reader_BlockNr->Append(_("161"));
    BR_Reader_BlockNr->Append(_("162"));
    BR_Reader_BlockNr->Append(_("163"));
    BR_Reader_BlockNr->Append(_("164"));
    BR_Reader_BlockNr->Append(_("165"));
    BR_Reader_BlockNr->Append(_("166"));
    BR_Reader_BlockNr->Append(_("167"));
    BR_Reader_BlockNr->Append(_("168"));
    BR_Reader_BlockNr->Append(_("169"));
    BR_Reader_BlockNr->Append(_("170"));
    BR_Reader_BlockNr->Append(_("171"));
    BR_Reader_BlockNr->Append(_("172"));
    BR_Reader_BlockNr->Append(_("173"));
    BR_Reader_BlockNr->Append(_("174"));
    BR_Reader_BlockNr->Append(_("175"));
    BR_Reader_BlockNr->Append(_("176"));
    BR_Reader_BlockNr->Append(_("177"));
    BR_Reader_BlockNr->Append(_("178"));
    BR_Reader_BlockNr->Append(_("179"));
    BR_Reader_BlockNr->Append(_("180"));
    BR_Reader_BlockNr->Append(_("181"));
    BR_Reader_BlockNr->Append(_("182"));
    BR_Reader_BlockNr->Append(_("183"));
    BR_Reader_BlockNr->Append(_("184"));
    BR_Reader_BlockNr->Append(_("185"));
    BR_Reader_BlockNr->Append(_("186"));
    BR_Reader_BlockNr->Append(_("187"));
    BR_Reader_BlockNr->Append(_("188"));
    BR_Reader_BlockNr->Append(_("189"));
    BR_Reader_BlockNr->Append(_("190"));
    BR_Reader_BlockNr->Append(_("191"));
    BR_Reader_BlockNr->Append(_("192"));
    BR_Reader_BlockNr->Append(_("193"));
    BR_Reader_BlockNr->Append(_("194"));
    BR_Reader_BlockNr->Append(_("195"));
    BR_Reader_BlockNr->Append(_("196"));
    BR_Reader_BlockNr->Append(_("197"));
    BR_Reader_BlockNr->Append(_("198"));
    BR_Reader_BlockNr->Append(_("199"));
    BR_Reader_BlockNr->Append(_("200"));
    BR_Reader_BlockNr->Append(_("201"));
    BR_Reader_BlockNr->Append(_("202"));
    BR_Reader_BlockNr->Append(_("203"));
    BR_Reader_BlockNr->Append(_("204"));
    BR_Reader_BlockNr->Append(_("205"));
    BR_Reader_BlockNr->Append(_("206"));
    BR_Reader_BlockNr->Append(_("207"));
    BR_Reader_BlockNr->Append(_("208"));
    BR_Reader_BlockNr->Append(_("209"));
    BR_Reader_BlockNr->Append(_("210"));
    BR_Reader_BlockNr->Append(_("211"));
    BR_Reader_BlockNr->Append(_("212"));
    BR_Reader_BlockNr->Append(_("213"));
    BR_Reader_BlockNr->Append(_("214"));
    BR_Reader_BlockNr->Append(_("215"));
    BR_Reader_BlockNr->Append(_("216"));
    BR_Reader_BlockNr->Append(_("217"));
    BR_Reader_BlockNr->Append(_("218"));
    BR_Reader_BlockNr->Append(_("219"));
    BR_Reader_BlockNr->Append(_("220"));
    BR_Reader_BlockNr->Append(_("221"));
    BR_Reader_BlockNr->Append(_("222"));
    BR_Reader_BlockNr->Append(_("223"));
    BR_Reader_BlockNr->Append(_("224"));
    BR_Reader_BlockNr->Append(_("225"));
    BR_Reader_BlockNr->Append(_("226"));
    BR_Reader_BlockNr->Append(_("227"));
    BR_Reader_BlockNr->Append(_("228"));
    BR_Reader_BlockNr->Append(_("229"));
    BR_Reader_BlockNr->Append(_("230"));
    BR_Reader_BlockNr->Append(_("231"));
    BR_Reader_BlockNr->Append(_("232"));
    BR_Reader_BlockNr->Append(_("233"));
    BR_Reader_BlockNr->Append(_("234"));
    BR_Reader_BlockNr->Append(_("235"));
    BR_Reader_BlockNr->Append(_("236"));
    BR_Reader_BlockNr->Append(_("237"));
    BR_Reader_BlockNr->Append(_("238"));
    BR_Reader_BlockNr->Append(_("239"));
    BR_Reader_BlockNr->Append(_("240"));
    BR_Reader_BlockNr->Append(_("241"));
    BR_Reader_BlockNr->Append(_("242"));
    BR_Reader_BlockNr->Append(_("243"));
    BR_Reader_BlockNr->Append(_("244"));
    BR_Reader_BlockNr->Append(_("245"));
    BR_Reader_BlockNr->Append(_("246"));
    BR_Reader_BlockNr->Append(_("247"));
    BR_Reader_BlockNr->Append(_("248"));
    BR_Reader_BlockNr->Append(_("249"));
    BR_Reader_BlockNr->Append(_("250"));
    BR_Reader_BlockNr->Append(_("251"));
    BR_Reader_BlockNr->Append(_("252"));
    BR_Reader_BlockNr->Append(_("253"));
    BR_Reader_BlockNr->Append(_("254"));
    BR_Reader_BlockNr->Append(_("255"));
    BoxSizer22->Add(BR_Reader_BlockNr, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    StaticBoxSizer41->Add(BoxSizer22, 0, wxALL|wxEXPAND, 3);
    BoxSizer23 = new wxBoxSizer(wxHORIZONTAL);
    StaticText54 = new wxStaticText(Panel14, ID_STATICTEXT55, _("Reader key index :"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT55"));
    BoxSizer23->Add(StaticText54, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    BR_Reader_KeyIndex = new wxComboBox(Panel14, ID_COMBOBOX16, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, wxCB_READONLY, wxDefaultValidator, _T("ID_COMBOBOX16"));
    BR_Reader_KeyIndex->SetSelection( BR_Reader_KeyIndex->Append(_("0")) );
    BR_Reader_KeyIndex->Append(_("1"));
    BR_Reader_KeyIndex->Append(_("2"));
    BR_Reader_KeyIndex->Append(_("3"));
    BR_Reader_KeyIndex->Append(_("4"));
    BR_Reader_KeyIndex->Append(_("5"));
    BR_Reader_KeyIndex->Append(_("6"));
    BR_Reader_KeyIndex->Append(_("7"));
    BR_Reader_KeyIndex->Append(_("8"));
    BR_Reader_KeyIndex->Append(_("9"));
    BR_Reader_KeyIndex->Append(_("10"));
    BR_Reader_KeyIndex->Append(_("11"));
    BR_Reader_KeyIndex->Append(_("12"));
    BR_Reader_KeyIndex->Append(_("13"));
    BR_Reader_KeyIndex->Append(_("14"));
    BR_Reader_KeyIndex->Append(_("15"));
    BR_Reader_KeyIndex->Append(_("16"));
    BR_Reader_KeyIndex->Append(_("17"));
    BR_Reader_KeyIndex->Append(_("18"));
    BR_Reader_KeyIndex->Append(_("19"));
    BR_Reader_KeyIndex->Append(_("20"));
    BR_Reader_KeyIndex->Append(_("21"));
    BR_Reader_KeyIndex->Append(_("22"));
    BR_Reader_KeyIndex->Append(_("23"));
    BR_Reader_KeyIndex->Append(_("24"));
    BR_Reader_KeyIndex->Append(_("25"));
    BR_Reader_KeyIndex->Append(_("26"));
    BR_Reader_KeyIndex->Append(_("27"));
    BR_Reader_KeyIndex->Append(_("28"));
    BR_Reader_KeyIndex->Append(_("29"));
    BR_Reader_KeyIndex->Append(_("30"));
    BR_Reader_KeyIndex->Append(_("31"));
    BoxSizer23->Add(BR_Reader_KeyIndex, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    StaticText113 = new wxStaticText(Panel14, ID_STATICTEXT114, _("(0 - 31 for CRYPTO 1) and (0 - 15 for AES key)"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT114"));
    BoxSizer23->Add(StaticText113, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    StaticBoxSizer41->Add(BoxSizer23, 0, wxALL|wxEXPAND, 3);
    bBRReaderKey = new wxButton(Panel14, ID_BUTTON17, _("Block read Reader key"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON17"));
    StaticBoxSizer41->Add(bBRReaderKey, 0, wxALL|wxALIGN_LEFT, 3);
    BoxSizer9->Add(StaticBoxSizer41, 1, wxALL|wxEXPAND, 3);
    StaticBoxSizer39->Add(BoxSizer9, 0, wxALL|wxEXPAND, 3);
    BoxSizer10 = new wxBoxSizer(wxHORIZONTAL);
    StaticBoxSizer42 = new wxStaticBoxSizer(wxVERTICAL, Panel14, _("AKM1 key"));
    BoxSizer24 = new wxBoxSizer(wxHORIZONTAL);
    BR_AKM1_KeyA = new wxRadioButton(Panel14, ID_RADIOBUTTON11, _("KEY A"), wxDefaultPosition, wxDefaultSize, wxRB_GROUP, wxDefaultValidator, _T("ID_RADIOBUTTON11"));
    BR_AKM1_KeyA->SetValue(true);
    BoxSizer24->Add(BR_AKM1_KeyA, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    BR_AKM1_KeyB = new wxRadioButton(Panel14, ID_RADIOBUTTON12, _("KEY B"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON12"));
    BoxSizer24->Add(BR_AKM1_KeyB, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    BoxSizer24->Add(-1,-1,0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    StaticText55 = new wxStaticText(Panel14, ID_STATICTEXT56, _("Block number:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT56"));
    BoxSizer24->Add(StaticText55, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    BR_AKM1_BlockNR = new wxComboBox(Panel14, ID_COMBOBOX17, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, wxCB_READONLY, wxDefaultValidator, _T("ID_COMBOBOX17"));
    BR_AKM1_BlockNR->SetSelection( BR_AKM1_BlockNR->Append(_("0")) );
    BR_AKM1_BlockNR->Append(_("1"));
    BR_AKM1_BlockNR->Append(_("2"));
    BR_AKM1_BlockNR->Append(_("3"));
    BR_AKM1_BlockNR->Append(_("4"));
    BR_AKM1_BlockNR->Append(_("5"));
    BR_AKM1_BlockNR->Append(_("6"));
    BR_AKM1_BlockNR->Append(_("7"));
    BR_AKM1_BlockNR->Append(_("8"));
    BR_AKM1_BlockNR->Append(_("9"));
    BR_AKM1_BlockNR->Append(_("10"));
    BR_AKM1_BlockNR->Append(_("11"));
    BR_AKM1_BlockNR->Append(_("12"));
    BR_AKM1_BlockNR->Append(_("13"));
    BR_AKM1_BlockNR->Append(_("14"));
    BR_AKM1_BlockNR->Append(_("15"));
    BR_AKM1_BlockNR->Append(_("16"));
    BR_AKM1_BlockNR->Append(_("17"));
    BR_AKM1_BlockNR->Append(_("18"));
    BR_AKM1_BlockNR->Append(_("19"));
    BR_AKM1_BlockNR->Append(_("20"));
    BR_AKM1_BlockNR->Append(_("21"));
    BR_AKM1_BlockNR->Append(_("22"));
    BR_AKM1_BlockNR->Append(_("23"));
    BR_AKM1_BlockNR->Append(_("24"));
    BR_AKM1_BlockNR->Append(_("25"));
    BR_AKM1_BlockNR->Append(_("26"));
    BR_AKM1_BlockNR->Append(_("27"));
    BR_AKM1_BlockNR->Append(_("28"));
    BR_AKM1_BlockNR->Append(_("29"));
    BR_AKM1_BlockNR->Append(_("30"));
    BR_AKM1_BlockNR->Append(_("31"));
    BR_AKM1_BlockNR->Append(_("32"));
    BR_AKM1_BlockNR->Append(_("33"));
    BR_AKM1_BlockNR->Append(_("34"));
    BR_AKM1_BlockNR->Append(_("35"));
    BR_AKM1_BlockNR->Append(_("36"));
    BR_AKM1_BlockNR->Append(_("37"));
    BR_AKM1_BlockNR->Append(_("38"));
    BR_AKM1_BlockNR->Append(_("39"));
    BR_AKM1_BlockNR->Append(_("40"));
    BR_AKM1_BlockNR->Append(_("41"));
    BR_AKM1_BlockNR->Append(_("42"));
    BR_AKM1_BlockNR->Append(_("43"));
    BR_AKM1_BlockNR->Append(_("44"));
    BR_AKM1_BlockNR->Append(_("45"));
    BR_AKM1_BlockNR->Append(_("46"));
    BR_AKM1_BlockNR->Append(_("47"));
    BR_AKM1_BlockNR->Append(_("48"));
    BR_AKM1_BlockNR->Append(_("49"));
    BR_AKM1_BlockNR->Append(_("50"));
    BR_AKM1_BlockNR->Append(_("51"));
    BR_AKM1_BlockNR->Append(_("52"));
    BR_AKM1_BlockNR->Append(_("53"));
    BR_AKM1_BlockNR->Append(_("54"));
    BR_AKM1_BlockNR->Append(_("55"));
    BR_AKM1_BlockNR->Append(_("56"));
    BR_AKM1_BlockNR->Append(_("57"));
    BR_AKM1_BlockNR->Append(_("58"));
    BR_AKM1_BlockNR->Append(_("59"));
    BR_AKM1_BlockNR->Append(_("60"));
    BR_AKM1_BlockNR->Append(_("61"));
    BR_AKM1_BlockNR->Append(_("62"));
    BR_AKM1_BlockNR->Append(_("63"));
    BR_AKM1_BlockNR->Append(_("64"));
    BR_AKM1_BlockNR->Append(_("65"));
    BR_AKM1_BlockNR->Append(_("66"));
    BR_AKM1_BlockNR->Append(_("67"));
    BR_AKM1_BlockNR->Append(_("68"));
    BR_AKM1_BlockNR->Append(_("69"));
    BR_AKM1_BlockNR->Append(_("70"));
    BR_AKM1_BlockNR->Append(_("71"));
    BR_AKM1_BlockNR->Append(_("72"));
    BR_AKM1_BlockNR->Append(_("73"));
    BR_AKM1_BlockNR->Append(_("74"));
    BR_AKM1_BlockNR->Append(_("75"));
    BR_AKM1_BlockNR->Append(_("76"));
    BR_AKM1_BlockNR->Append(_("77"));
    BR_AKM1_BlockNR->Append(_("78"));
    BR_AKM1_BlockNR->Append(_("79"));
    BR_AKM1_BlockNR->Append(_("80"));
    BR_AKM1_BlockNR->Append(_("81"));
    BR_AKM1_BlockNR->Append(_("82"));
    BR_AKM1_BlockNR->Append(_("83"));
    BR_AKM1_BlockNR->Append(_("84"));
    BR_AKM1_BlockNR->Append(_("85"));
    BR_AKM1_BlockNR->Append(_("86"));
    BR_AKM1_BlockNR->Append(_("87"));
    BR_AKM1_BlockNR->Append(_("88"));
    BR_AKM1_BlockNR->Append(_("89"));
    BR_AKM1_BlockNR->Append(_("90"));
    BR_AKM1_BlockNR->Append(_("91"));
    BR_AKM1_BlockNR->Append(_("92"));
    BR_AKM1_BlockNR->Append(_("93"));
    BR_AKM1_BlockNR->Append(_("94"));
    BR_AKM1_BlockNR->Append(_("95"));
    BR_AKM1_BlockNR->Append(_("96"));
    BR_AKM1_BlockNR->Append(_("97"));
    BR_AKM1_BlockNR->Append(_("98"));
    BR_AKM1_BlockNR->Append(_("99"));
    BR_AKM1_BlockNR->Append(_("100"));
    BR_AKM1_BlockNR->Append(_("101"));
    BR_AKM1_BlockNR->Append(_("102"));
    BR_AKM1_BlockNR->Append(_("103"));
    BR_AKM1_BlockNR->Append(_("104"));
    BR_AKM1_BlockNR->Append(_("105"));
    BR_AKM1_BlockNR->Append(_("106"));
    BR_AKM1_BlockNR->Append(_("107"));
    BR_AKM1_BlockNR->Append(_("108"));
    BR_AKM1_BlockNR->Append(_("109"));
    BR_AKM1_BlockNR->Append(_("110"));
    BR_AKM1_BlockNR->Append(_("111"));
    BR_AKM1_BlockNR->Append(_("112"));
    BR_AKM1_BlockNR->Append(_("113"));
    BR_AKM1_BlockNR->Append(_("114"));
    BR_AKM1_BlockNR->Append(_("115"));
    BR_AKM1_BlockNR->Append(_("116"));
    BR_AKM1_BlockNR->Append(_("117"));
    BR_AKM1_BlockNR->Append(_("118"));
    BR_AKM1_BlockNR->Append(_("119"));
    BR_AKM1_BlockNR->Append(_("120"));
    BR_AKM1_BlockNR->Append(_("121"));
    BR_AKM1_BlockNR->Append(_("122"));
    BR_AKM1_BlockNR->Append(_("123"));
    BR_AKM1_BlockNR->Append(_("124"));
    BR_AKM1_BlockNR->Append(_("125"));
    BR_AKM1_BlockNR->Append(_("126"));
    BR_AKM1_BlockNR->Append(_("127"));
    BR_AKM1_BlockNR->Append(_("128"));
    BR_AKM1_BlockNR->Append(_("129"));
    BR_AKM1_BlockNR->Append(_("130"));
    BR_AKM1_BlockNR->Append(_("131"));
    BR_AKM1_BlockNR->Append(_("132"));
    BR_AKM1_BlockNR->Append(_("133"));
    BR_AKM1_BlockNR->Append(_("134"));
    BR_AKM1_BlockNR->Append(_("135"));
    BR_AKM1_BlockNR->Append(_("136"));
    BR_AKM1_BlockNR->Append(_("137"));
    BR_AKM1_BlockNR->Append(_("138"));
    BR_AKM1_BlockNR->Append(_("139"));
    BR_AKM1_BlockNR->Append(_("140"));
    BR_AKM1_BlockNR->Append(_("141"));
    BR_AKM1_BlockNR->Append(_("142"));
    BR_AKM1_BlockNR->Append(_("143"));
    BR_AKM1_BlockNR->Append(_("144"));
    BR_AKM1_BlockNR->Append(_("145"));
    BR_AKM1_BlockNR->Append(_("146"));
    BR_AKM1_BlockNR->Append(_("147"));
    BR_AKM1_BlockNR->Append(_("148"));
    BR_AKM1_BlockNR->Append(_("149"));
    BR_AKM1_BlockNR->Append(_("150"));
    BR_AKM1_BlockNR->Append(_("151"));
    BR_AKM1_BlockNR->Append(_("152"));
    BR_AKM1_BlockNR->Append(_("153"));
    BR_AKM1_BlockNR->Append(_("154"));
    BR_AKM1_BlockNR->Append(_("155"));
    BR_AKM1_BlockNR->Append(_("156"));
    BR_AKM1_BlockNR->Append(_("157"));
    BR_AKM1_BlockNR->Append(_("158"));
    BR_AKM1_BlockNR->Append(_("159"));
    BR_AKM1_BlockNR->Append(_("160"));
    BR_AKM1_BlockNR->Append(_("161"));
    BR_AKM1_BlockNR->Append(_("162"));
    BR_AKM1_BlockNR->Append(_("163"));
    BR_AKM1_BlockNR->Append(_("164"));
    BR_AKM1_BlockNR->Append(_("165"));
    BR_AKM1_BlockNR->Append(_("166"));
    BR_AKM1_BlockNR->Append(_("167"));
    BR_AKM1_BlockNR->Append(_("168"));
    BR_AKM1_BlockNR->Append(_("169"));
    BR_AKM1_BlockNR->Append(_("170"));
    BR_AKM1_BlockNR->Append(_("171"));
    BR_AKM1_BlockNR->Append(_("172"));
    BR_AKM1_BlockNR->Append(_("173"));
    BR_AKM1_BlockNR->Append(_("174"));
    BR_AKM1_BlockNR->Append(_("175"));
    BR_AKM1_BlockNR->Append(_("176"));
    BR_AKM1_BlockNR->Append(_("177"));
    BR_AKM1_BlockNR->Append(_("178"));
    BR_AKM1_BlockNR->Append(_("179"));
    BR_AKM1_BlockNR->Append(_("180"));
    BR_AKM1_BlockNR->Append(_("181"));
    BR_AKM1_BlockNR->Append(_("182"));
    BR_AKM1_BlockNR->Append(_("183"));
    BR_AKM1_BlockNR->Append(_("184"));
    BR_AKM1_BlockNR->Append(_("185"));
    BR_AKM1_BlockNR->Append(_("186"));
    BR_AKM1_BlockNR->Append(_("187"));
    BR_AKM1_BlockNR->Append(_("188"));
    BR_AKM1_BlockNR->Append(_("189"));
    BR_AKM1_BlockNR->Append(_("190"));
    BR_AKM1_BlockNR->Append(_("191"));
    BR_AKM1_BlockNR->Append(_("192"));
    BR_AKM1_BlockNR->Append(_("193"));
    BR_AKM1_BlockNR->Append(_("194"));
    BR_AKM1_BlockNR->Append(_("195"));
    BR_AKM1_BlockNR->Append(_("196"));
    BR_AKM1_BlockNR->Append(_("197"));
    BR_AKM1_BlockNR->Append(_("198"));
    BR_AKM1_BlockNR->Append(_("199"));
    BR_AKM1_BlockNR->Append(_("200"));
    BR_AKM1_BlockNR->Append(_("201"));
    BR_AKM1_BlockNR->Append(_("202"));
    BR_AKM1_BlockNR->Append(_("203"));
    BR_AKM1_BlockNR->Append(_("204"));
    BR_AKM1_BlockNR->Append(_("205"));
    BR_AKM1_BlockNR->Append(_("206"));
    BR_AKM1_BlockNR->Append(_("207"));
    BR_AKM1_BlockNR->Append(_("208"));
    BR_AKM1_BlockNR->Append(_("209"));
    BR_AKM1_BlockNR->Append(_("210"));
    BR_AKM1_BlockNR->Append(_("211"));
    BR_AKM1_BlockNR->Append(_("212"));
    BR_AKM1_BlockNR->Append(_("213"));
    BR_AKM1_BlockNR->Append(_("214"));
    BR_AKM1_BlockNR->Append(_("215"));
    BR_AKM1_BlockNR->Append(_("216"));
    BR_AKM1_BlockNR->Append(_("217"));
    BR_AKM1_BlockNR->Append(_("218"));
    BR_AKM1_BlockNR->Append(_("219"));
    BR_AKM1_BlockNR->Append(_("220"));
    BR_AKM1_BlockNR->Append(_("221"));
    BR_AKM1_BlockNR->Append(_("222"));
    BR_AKM1_BlockNR->Append(_("223"));
    BR_AKM1_BlockNR->Append(_("224"));
    BR_AKM1_BlockNR->Append(_("225"));
    BR_AKM1_BlockNR->Append(_("226"));
    BR_AKM1_BlockNR->Append(_("227"));
    BR_AKM1_BlockNR->Append(_("228"));
    BR_AKM1_BlockNR->Append(_("229"));
    BR_AKM1_BlockNR->Append(_("230"));
    BR_AKM1_BlockNR->Append(_("231"));
    BR_AKM1_BlockNR->Append(_("232"));
    BR_AKM1_BlockNR->Append(_("233"));
    BR_AKM1_BlockNR->Append(_("234"));
    BR_AKM1_BlockNR->Append(_("235"));
    BR_AKM1_BlockNR->Append(_("236"));
    BR_AKM1_BlockNR->Append(_("237"));
    BR_AKM1_BlockNR->Append(_("238"));
    BR_AKM1_BlockNR->Append(_("239"));
    BR_AKM1_BlockNR->Append(_("240"));
    BR_AKM1_BlockNR->Append(_("241"));
    BR_AKM1_BlockNR->Append(_("242"));
    BR_AKM1_BlockNR->Append(_("243"));
    BR_AKM1_BlockNR->Append(_("244"));
    BR_AKM1_BlockNR->Append(_("245"));
    BR_AKM1_BlockNR->Append(_("246"));
    BR_AKM1_BlockNR->Append(_("247"));
    BR_AKM1_BlockNR->Append(_("248"));
    BR_AKM1_BlockNR->Append(_("249"));
    BR_AKM1_BlockNR->Append(_("250"));
    BR_AKM1_BlockNR->Append(_("251"));
    BR_AKM1_BlockNR->Append(_("252"));
    BR_AKM1_BlockNR->Append(_("253"));
    BR_AKM1_BlockNR->Append(_("254"));
    BR_AKM1_BlockNR->Append(_("255"));
    BoxSizer24->Add(BR_AKM1_BlockNR, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    StaticBoxSizer42->Add(BoxSizer24, 1, wxALL|wxEXPAND, 3);
    bBRAKM1 = new wxButton(Panel14, ID_BUTTON18, _("Block read AKM1 key"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON18"));
    StaticBoxSizer42->Add(bBRAKM1, 1, wxALL|wxALIGN_LEFT, 5);
    BoxSizer10->Add(StaticBoxSizer42, 1, wxALL|wxEXPAND, 3);
    StaticBoxSizer43 = new wxStaticBoxSizer(wxVERTICAL, Panel14, _("AKM2 key"));
    BoxSizer25 = new wxBoxSizer(wxHORIZONTAL);
    BR_AKM2_KeyA = new wxRadioButton(Panel14, ID_RADIOBUTTON13, _("KEY A"), wxDefaultPosition, wxDefaultSize, wxRB_GROUP, wxDefaultValidator, _T("ID_RADIOBUTTON13"));
    BR_AKM2_KeyA->SetValue(true);
    BoxSizer25->Add(BR_AKM2_KeyA, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    BR_AKM2_KeyB = new wxRadioButton(Panel14, ID_RADIOBUTTON14, _("KEY B"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON14"));
    BoxSizer25->Add(BR_AKM2_KeyB, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    BoxSizer25->Add(-1,-1,0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    StaticText56 = new wxStaticText(Panel14, ID_STATICTEXT57, _("Block number:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT57"));
    BoxSizer25->Add(StaticText56, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    BR_AKM2_BlockNR = new wxComboBox(Panel14, ID_COMBOBOX18, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, wxCB_READONLY, wxDefaultValidator, _T("ID_COMBOBOX18"));
    BR_AKM2_BlockNR->SetSelection( BR_AKM2_BlockNR->Append(_("0")) );
    BR_AKM2_BlockNR->Append(_("1"));
    BR_AKM2_BlockNR->Append(_("2"));
    BR_AKM2_BlockNR->Append(_("3"));
    BR_AKM2_BlockNR->Append(_("4"));
    BR_AKM2_BlockNR->Append(_("5"));
    BR_AKM2_BlockNR->Append(_("6"));
    BR_AKM2_BlockNR->Append(_("7"));
    BR_AKM2_BlockNR->Append(_("8"));
    BR_AKM2_BlockNR->Append(_("9"));
    BR_AKM2_BlockNR->Append(_("10"));
    BR_AKM2_BlockNR->Append(_("11"));
    BR_AKM2_BlockNR->Append(_("12"));
    BR_AKM2_BlockNR->Append(_("13"));
    BR_AKM2_BlockNR->Append(_("14"));
    BR_AKM2_BlockNR->Append(_("15"));
    BR_AKM2_BlockNR->Append(_("16"));
    BR_AKM2_BlockNR->Append(_("17"));
    BR_AKM2_BlockNR->Append(_("18"));
    BR_AKM2_BlockNR->Append(_("19"));
    BR_AKM2_BlockNR->Append(_("20"));
    BR_AKM2_BlockNR->Append(_("21"));
    BR_AKM2_BlockNR->Append(_("22"));
    BR_AKM2_BlockNR->Append(_("23"));
    BR_AKM2_BlockNR->Append(_("24"));
    BR_AKM2_BlockNR->Append(_("25"));
    BR_AKM2_BlockNR->Append(_("26"));
    BR_AKM2_BlockNR->Append(_("27"));
    BR_AKM2_BlockNR->Append(_("28"));
    BR_AKM2_BlockNR->Append(_("29"));
    BR_AKM2_BlockNR->Append(_("30"));
    BR_AKM2_BlockNR->Append(_("31"));
    BR_AKM2_BlockNR->Append(_("32"));
    BR_AKM2_BlockNR->Append(_("33"));
    BR_AKM2_BlockNR->Append(_("34"));
    BR_AKM2_BlockNR->Append(_("35"));
    BR_AKM2_BlockNR->Append(_("36"));
    BR_AKM2_BlockNR->Append(_("37"));
    BR_AKM2_BlockNR->Append(_("38"));
    BR_AKM2_BlockNR->Append(_("39"));
    BR_AKM2_BlockNR->Append(_("40"));
    BR_AKM2_BlockNR->Append(_("41"));
    BR_AKM2_BlockNR->Append(_("42"));
    BR_AKM2_BlockNR->Append(_("43"));
    BR_AKM2_BlockNR->Append(_("44"));
    BR_AKM2_BlockNR->Append(_("45"));
    BR_AKM2_BlockNR->Append(_("46"));
    BR_AKM2_BlockNR->Append(_("47"));
    BR_AKM2_BlockNR->Append(_("48"));
    BR_AKM2_BlockNR->Append(_("49"));
    BR_AKM2_BlockNR->Append(_("50"));
    BR_AKM2_BlockNR->Append(_("51"));
    BR_AKM2_BlockNR->Append(_("52"));
    BR_AKM2_BlockNR->Append(_("53"));
    BR_AKM2_BlockNR->Append(_("54"));
    BR_AKM2_BlockNR->Append(_("55"));
    BR_AKM2_BlockNR->Append(_("56"));
    BR_AKM2_BlockNR->Append(_("57"));
    BR_AKM2_BlockNR->Append(_("58"));
    BR_AKM2_BlockNR->Append(_("59"));
    BR_AKM2_BlockNR->Append(_("60"));
    BR_AKM2_BlockNR->Append(_("61"));
    BR_AKM2_BlockNR->Append(_("62"));
    BR_AKM2_BlockNR->Append(_("63"));
    BR_AKM2_BlockNR->Append(_("64"));
    BR_AKM2_BlockNR->Append(_("65"));
    BR_AKM2_BlockNR->Append(_("66"));
    BR_AKM2_BlockNR->Append(_("67"));
    BR_AKM2_BlockNR->Append(_("68"));
    BR_AKM2_BlockNR->Append(_("69"));
    BR_AKM2_BlockNR->Append(_("70"));
    BR_AKM2_BlockNR->Append(_("71"));
    BR_AKM2_BlockNR->Append(_("72"));
    BR_AKM2_BlockNR->Append(_("73"));
    BR_AKM2_BlockNR->Append(_("74"));
    BR_AKM2_BlockNR->Append(_("75"));
    BR_AKM2_BlockNR->Append(_("76"));
    BR_AKM2_BlockNR->Append(_("77"));
    BR_AKM2_BlockNR->Append(_("78"));
    BR_AKM2_BlockNR->Append(_("79"));
    BR_AKM2_BlockNR->Append(_("80"));
    BR_AKM2_BlockNR->Append(_("81"));
    BR_AKM2_BlockNR->Append(_("82"));
    BR_AKM2_BlockNR->Append(_("83"));
    BR_AKM2_BlockNR->Append(_("84"));
    BR_AKM2_BlockNR->Append(_("85"));
    BR_AKM2_BlockNR->Append(_("86"));
    BR_AKM2_BlockNR->Append(_("87"));
    BR_AKM2_BlockNR->Append(_("88"));
    BR_AKM2_BlockNR->Append(_("89"));
    BR_AKM2_BlockNR->Append(_("90"));
    BR_AKM2_BlockNR->Append(_("91"));
    BR_AKM2_BlockNR->Append(_("92"));
    BR_AKM2_BlockNR->Append(_("93"));
    BR_AKM2_BlockNR->Append(_("94"));
    BR_AKM2_BlockNR->Append(_("95"));
    BR_AKM2_BlockNR->Append(_("96"));
    BR_AKM2_BlockNR->Append(_("97"));
    BR_AKM2_BlockNR->Append(_("98"));
    BR_AKM2_BlockNR->Append(_("99"));
    BR_AKM2_BlockNR->Append(_("100"));
    BR_AKM2_BlockNR->Append(_("101"));
    BR_AKM2_BlockNR->Append(_("102"));
    BR_AKM2_BlockNR->Append(_("103"));
    BR_AKM2_BlockNR->Append(_("104"));
    BR_AKM2_BlockNR->Append(_("105"));
    BR_AKM2_BlockNR->Append(_("106"));
    BR_AKM2_BlockNR->Append(_("107"));
    BR_AKM2_BlockNR->Append(_("108"));
    BR_AKM2_BlockNR->Append(_("109"));
    BR_AKM2_BlockNR->Append(_("110"));
    BR_AKM2_BlockNR->Append(_("111"));
    BR_AKM2_BlockNR->Append(_("112"));
    BR_AKM2_BlockNR->Append(_("113"));
    BR_AKM2_BlockNR->Append(_("114"));
    BR_AKM2_BlockNR->Append(_("115"));
    BR_AKM2_BlockNR->Append(_("116"));
    BR_AKM2_BlockNR->Append(_("117"));
    BR_AKM2_BlockNR->Append(_("118"));
    BR_AKM2_BlockNR->Append(_("119"));
    BR_AKM2_BlockNR->Append(_("120"));
    BR_AKM2_BlockNR->Append(_("121"));
    BR_AKM2_BlockNR->Append(_("122"));
    BR_AKM2_BlockNR->Append(_("123"));
    BR_AKM2_BlockNR->Append(_("124"));
    BR_AKM2_BlockNR->Append(_("125"));
    BR_AKM2_BlockNR->Append(_("126"));
    BR_AKM2_BlockNR->Append(_("127"));
    BR_AKM2_BlockNR->Append(_("128"));
    BR_AKM2_BlockNR->Append(_("129"));
    BR_AKM2_BlockNR->Append(_("130"));
    BR_AKM2_BlockNR->Append(_("131"));
    BR_AKM2_BlockNR->Append(_("132"));
    BR_AKM2_BlockNR->Append(_("133"));
    BR_AKM2_BlockNR->Append(_("134"));
    BR_AKM2_BlockNR->Append(_("135"));
    BR_AKM2_BlockNR->Append(_("136"));
    BR_AKM2_BlockNR->Append(_("137"));
    BR_AKM2_BlockNR->Append(_("138"));
    BR_AKM2_BlockNR->Append(_("139"));
    BR_AKM2_BlockNR->Append(_("140"));
    BR_AKM2_BlockNR->Append(_("141"));
    BR_AKM2_BlockNR->Append(_("142"));
    BR_AKM2_BlockNR->Append(_("143"));
    BR_AKM2_BlockNR->Append(_("144"));
    BR_AKM2_BlockNR->Append(_("145"));
    BR_AKM2_BlockNR->Append(_("146"));
    BR_AKM2_BlockNR->Append(_("147"));
    BR_AKM2_BlockNR->Append(_("148"));
    BR_AKM2_BlockNR->Append(_("149"));
    BR_AKM2_BlockNR->Append(_("150"));
    BR_AKM2_BlockNR->Append(_("151"));
    BR_AKM2_BlockNR->Append(_("152"));
    BR_AKM2_BlockNR->Append(_("153"));
    BR_AKM2_BlockNR->Append(_("154"));
    BR_AKM2_BlockNR->Append(_("155"));
    BR_AKM2_BlockNR->Append(_("156"));
    BR_AKM2_BlockNR->Append(_("157"));
    BR_AKM2_BlockNR->Append(_("158"));
    BR_AKM2_BlockNR->Append(_("159"));
    BR_AKM2_BlockNR->Append(_("160"));
    BR_AKM2_BlockNR->Append(_("161"));
    BR_AKM2_BlockNR->Append(_("162"));
    BR_AKM2_BlockNR->Append(_("163"));
    BR_AKM2_BlockNR->Append(_("164"));
    BR_AKM2_BlockNR->Append(_("165"));
    BR_AKM2_BlockNR->Append(_("166"));
    BR_AKM2_BlockNR->Append(_("167"));
    BR_AKM2_BlockNR->Append(_("168"));
    BR_AKM2_BlockNR->Append(_("169"));
    BR_AKM2_BlockNR->Append(_("170"));
    BR_AKM2_BlockNR->Append(_("171"));
    BR_AKM2_BlockNR->Append(_("172"));
    BR_AKM2_BlockNR->Append(_("173"));
    BR_AKM2_BlockNR->Append(_("174"));
    BR_AKM2_BlockNR->Append(_("175"));
    BR_AKM2_BlockNR->Append(_("176"));
    BR_AKM2_BlockNR->Append(_("177"));
    BR_AKM2_BlockNR->Append(_("178"));
    BR_AKM2_BlockNR->Append(_("179"));
    BR_AKM2_BlockNR->Append(_("180"));
    BR_AKM2_BlockNR->Append(_("181"));
    BR_AKM2_BlockNR->Append(_("182"));
    BR_AKM2_BlockNR->Append(_("183"));
    BR_AKM2_BlockNR->Append(_("184"));
    BR_AKM2_BlockNR->Append(_("185"));
    BR_AKM2_BlockNR->Append(_("186"));
    BR_AKM2_BlockNR->Append(_("187"));
    BR_AKM2_BlockNR->Append(_("188"));
    BR_AKM2_BlockNR->Append(_("189"));
    BR_AKM2_BlockNR->Append(_("190"));
    BR_AKM2_BlockNR->Append(_("191"));
    BR_AKM2_BlockNR->Append(_("192"));
    BR_AKM2_BlockNR->Append(_("193"));
    BR_AKM2_BlockNR->Append(_("194"));
    BR_AKM2_BlockNR->Append(_("195"));
    BR_AKM2_BlockNR->Append(_("196"));
    BR_AKM2_BlockNR->Append(_("197"));
    BR_AKM2_BlockNR->Append(_("198"));
    BR_AKM2_BlockNR->Append(_("199"));
    BR_AKM2_BlockNR->Append(_("200"));
    BR_AKM2_BlockNR->Append(_("201"));
    BR_AKM2_BlockNR->Append(_("202"));
    BR_AKM2_BlockNR->Append(_("203"));
    BR_AKM2_BlockNR->Append(_("204"));
    BR_AKM2_BlockNR->Append(_("205"));
    BR_AKM2_BlockNR->Append(_("206"));
    BR_AKM2_BlockNR->Append(_("207"));
    BR_AKM2_BlockNR->Append(_("208"));
    BR_AKM2_BlockNR->Append(_("209"));
    BR_AKM2_BlockNR->Append(_("210"));
    BR_AKM2_BlockNR->Append(_("211"));
    BR_AKM2_BlockNR->Append(_("212"));
    BR_AKM2_BlockNR->Append(_("213"));
    BR_AKM2_BlockNR->Append(_("214"));
    BR_AKM2_BlockNR->Append(_("215"));
    BR_AKM2_BlockNR->Append(_("216"));
    BR_AKM2_BlockNR->Append(_("217"));
    BR_AKM2_BlockNR->Append(_("218"));
    BR_AKM2_BlockNR->Append(_("219"));
    BR_AKM2_BlockNR->Append(_("220"));
    BR_AKM2_BlockNR->Append(_("221"));
    BR_AKM2_BlockNR->Append(_("222"));
    BR_AKM2_BlockNR->Append(_("223"));
    BR_AKM2_BlockNR->Append(_("224"));
    BR_AKM2_BlockNR->Append(_("225"));
    BR_AKM2_BlockNR->Append(_("226"));
    BR_AKM2_BlockNR->Append(_("227"));
    BR_AKM2_BlockNR->Append(_("228"));
    BR_AKM2_BlockNR->Append(_("229"));
    BR_AKM2_BlockNR->Append(_("230"));
    BR_AKM2_BlockNR->Append(_("231"));
    BR_AKM2_BlockNR->Append(_("232"));
    BR_AKM2_BlockNR->Append(_("233"));
    BR_AKM2_BlockNR->Append(_("234"));
    BR_AKM2_BlockNR->Append(_("235"));
    BR_AKM2_BlockNR->Append(_("236"));
    BR_AKM2_BlockNR->Append(_("237"));
    BR_AKM2_BlockNR->Append(_("238"));
    BR_AKM2_BlockNR->Append(_("239"));
    BR_AKM2_BlockNR->Append(_("240"));
    BR_AKM2_BlockNR->Append(_("241"));
    BR_AKM2_BlockNR->Append(_("242"));
    BR_AKM2_BlockNR->Append(_("243"));
    BR_AKM2_BlockNR->Append(_("244"));
    BR_AKM2_BlockNR->Append(_("245"));
    BR_AKM2_BlockNR->Append(_("246"));
    BR_AKM2_BlockNR->Append(_("247"));
    BR_AKM2_BlockNR->Append(_("248"));
    BR_AKM2_BlockNR->Append(_("249"));
    BR_AKM2_BlockNR->Append(_("250"));
    BR_AKM2_BlockNR->Append(_("251"));
    BR_AKM2_BlockNR->Append(_("252"));
    BR_AKM2_BlockNR->Append(_("253"));
    BR_AKM2_BlockNR->Append(_("254"));
    BR_AKM2_BlockNR->Append(_("255"));
    BoxSizer25->Add(BR_AKM2_BlockNR, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    StaticBoxSizer43->Add(BoxSizer25, 0, wxALL|wxEXPAND, 3);
    bBRAKM2 = new wxButton(Panel14, ID_BUTTON19, _("Block read AKM2 key"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON19"));
    StaticBoxSizer43->Add(bBRAKM2, 1, wxALL|wxALIGN_LEFT, 5);
    BoxSizer10->Add(StaticBoxSizer43, 1, wxALL|wxEXPAND, 3);
    StaticBoxSizer39->Add(BoxSizer10, 0, wxALL|wxEXPAND, 3);
    StaticText106 = new wxStaticText(Panel14, ID_STATICTEXT107, _("Block: (0 - 128 for 2K cards and 0 -255 for 4K cards)"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT107"));
    StaticBoxSizer39->Add(StaticText106, 0, wxALL|wxALIGN_LEFT, 3);
    Panel14->SetSizer(StaticBoxSizer39);
    StaticBoxSizer39->Fit(Panel14);
    StaticBoxSizer39->SetSizeHints(Panel14);
    Panel15 = new wxPanel(Notebook2, ID_PANEL15, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL15"));
    StaticBoxSizer44 = new wxStaticBoxSizer(wxVERTICAL, Panel15, wxEmptyString);
    BoxSizer26 = new wxBoxSizer(wxHORIZONTAL);
    StaticBoxSizer45 = new wxStaticBoxSizer(wxVERTICAL, Panel15, _("Provided key"));
    BoxSizer27 = new wxBoxSizer(wxVERTICAL);
    BoxSizer28 = new wxBoxSizer(wxHORIZONTAL);
    BSR_Provided_KeyA = new wxRadioButton(Panel15, ID_RADIOBUTTON15, _("KEY A"), wxDefaultPosition, wxDefaultSize, wxRB_GROUP, wxDefaultValidator, _T("ID_RADIOBUTTON15"));
    BSR_Provided_KeyA->SetValue(true);
    BoxSizer28->Add(BSR_Provided_KeyA, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    BSR_Provided_KeyB = new wxRadioButton(Panel15, ID_RADIOBUTTON16, _("KEY B"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON16"));
    BoxSizer28->Add(BSR_Provided_KeyB, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    BoxSizer28->Add(-1,-1,0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    StaticText67 = new wxStaticText(Panel15, ID_STATICTEXT68, _("Sector:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT68"));
    BoxSizer28->Add(StaticText67, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    BSR_SectorNr = new wxComboBox(Panel15, ID_COMBOBOX24, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, wxCB_READONLY, wxDefaultValidator, _T("ID_COMBOBOX24"));
    BSR_SectorNr->SetSelection( BSR_SectorNr->Append(_("0")) );
    BSR_SectorNr->Append(_("1"));
    BSR_SectorNr->Append(_("2"));
    BSR_SectorNr->Append(_("3"));
    BSR_SectorNr->Append(_("4"));
    BSR_SectorNr->Append(_("5"));
    BSR_SectorNr->Append(_("6"));
    BSR_SectorNr->Append(_("7"));
    BSR_SectorNr->Append(_("8"));
    BSR_SectorNr->Append(_("9"));
    BSR_SectorNr->Append(_("10"));
    BSR_SectorNr->Append(_("11"));
    BSR_SectorNr->Append(_("12"));
    BSR_SectorNr->Append(_("13"));
    BSR_SectorNr->Append(_("14"));
    BSR_SectorNr->Append(_("15"));
    BSR_SectorNr->Append(_("16"));
    BSR_SectorNr->Append(_("17"));
    BSR_SectorNr->Append(_("18"));
    BSR_SectorNr->Append(_("19"));
    BSR_SectorNr->Append(_("20"));
    BSR_SectorNr->Append(_("21"));
    BSR_SectorNr->Append(_("22"));
    BSR_SectorNr->Append(_("23"));
    BSR_SectorNr->Append(_("24"));
    BSR_SectorNr->Append(_("25"));
    BSR_SectorNr->Append(_("26"));
    BSR_SectorNr->Append(_("27"));
    BSR_SectorNr->Append(_("28"));
    BSR_SectorNr->Append(_("29"));
    BSR_SectorNr->Append(_("30"));
    BSR_SectorNr->Append(_("31"));
    BSR_SectorNr->Append(_("32"));
    BSR_SectorNr->Append(_("33"));
    BSR_SectorNr->Append(_("34"));
    BSR_SectorNr->Append(_("35"));
    BSR_SectorNr->Append(_("36"));
    BSR_SectorNr->Append(_("37"));
    BSR_SectorNr->Append(_("38"));
    BSR_SectorNr->Append(_("39"));
    BoxSizer28->Add(BSR_SectorNr, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    StaticText57 = new wxStaticText(Panel15, ID_STATICTEXT58, _("Block:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT58"));
    BoxSizer28->Add(StaticText57, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    BSR_BlockNr = new wxComboBox(Panel15, ID_COMBOBOX19, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, wxCB_READONLY, wxDefaultValidator, _T("ID_COMBOBOX19"));
    BSR_BlockNr->SetSelection( BSR_BlockNr->Append(_("0")) );
    BSR_BlockNr->Append(_("1"));
    BSR_BlockNr->Append(_("2"));
    BSR_BlockNr->Append(_("3"));
    BSR_BlockNr->Append(_("4"));
    BSR_BlockNr->Append(_("5"));
    BSR_BlockNr->Append(_("6"));
    BSR_BlockNr->Append(_("7"));
    BSR_BlockNr->Append(_("8"));
    BSR_BlockNr->Append(_("9"));
    BSR_BlockNr->Append(_("10"));
    BSR_BlockNr->Append(_("11"));
    BSR_BlockNr->Append(_("12"));
    BSR_BlockNr->Append(_("13"));
    BSR_BlockNr->Append(_("14"));
    BSR_BlockNr->Append(_("15"));
    BoxSizer28->Add(BSR_BlockNr, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    BoxSizer27->Add(BoxSizer28, 0, wxALL|wxALIGN_LEFT, 3);
    BoxSizer29 = new wxBoxSizer(wxHORIZONTAL);
    StaticText58 = new wxStaticText(Panel15, ID_STATICTEXT59, _("Key:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT59"));
    BoxSizer29->Add(StaticText58, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    BSR_Key = new wxTextCtrl(Panel15, ID_TEXTCTRL39, wxEmptyString, wxDefaultPosition, wxSize(203,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL39"));
    BSR_Key->SetMaxLength(32);
    BoxSizer29->Add(BSR_Key, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    BoxSizer27->Add(BoxSizer29, 0, wxALL|wxALIGN_LEFT, 3);
    bBSRProvidedKey = new wxButton(Panel15, ID_BUTTON20, _("Block in sector read provided key"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON20"));
    BoxSizer27->Add(bBSRProvidedKey, 1, wxALL|wxALIGN_LEFT, 5);
    StaticBoxSizer45->Add(BoxSizer27, 0, wxALL|wxALIGN_LEFT, 3);
    BoxSizer26->Add(StaticBoxSizer45, 1, wxALL|wxEXPAND, 3);
    StaticBoxSizer46 = new wxStaticBoxSizer(wxVERTICAL, Panel15, _("Reader key"));
    BoxSizer30 = new wxBoxSizer(wxHORIZONTAL);
    BSR_Reader_KeyA = new wxRadioButton(Panel15, ID_RADIOBUTTON17, _("KEY A"), wxDefaultPosition, wxDefaultSize, wxRB_GROUP, wxDefaultValidator, _T("ID_RADIOBUTTON17"));
    BSR_Reader_KeyA->SetValue(true);
    BoxSizer30->Add(BSR_Reader_KeyA, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    BSR_Reader_KeyB = new wxRadioButton(Panel15, ID_RADIOBUTTON18, _("KEY B"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON18"));
    BoxSizer30->Add(BSR_Reader_KeyB, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    BoxSizer30->Add(-1,-1,0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    StaticText70 = new wxStaticText(Panel15, ID_STATICTEXT71, _("Sector:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT71"));
    BoxSizer30->Add(StaticText70, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    BSR_Reader_SectorNr = new wxComboBox(Panel15, ID_COMBOBOX25, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, wxCB_READONLY, wxDefaultValidator, _T("ID_COMBOBOX25"));
    BSR_Reader_SectorNr->SetSelection( BSR_Reader_SectorNr->Append(_("0")) );
    BSR_Reader_SectorNr->Append(_("1"));
    BSR_Reader_SectorNr->Append(_("2"));
    BSR_Reader_SectorNr->Append(_("3"));
    BSR_Reader_SectorNr->Append(_("4"));
    BSR_Reader_SectorNr->Append(_("5"));
    BSR_Reader_SectorNr->Append(_("6"));
    BSR_Reader_SectorNr->Append(_("7"));
    BSR_Reader_SectorNr->Append(_("8"));
    BSR_Reader_SectorNr->Append(_("9"));
    BSR_Reader_SectorNr->Append(_("10"));
    BSR_Reader_SectorNr->Append(_("11"));
    BSR_Reader_SectorNr->Append(_("12"));
    BSR_Reader_SectorNr->Append(_("13"));
    BSR_Reader_SectorNr->Append(_("14"));
    BSR_Reader_SectorNr->Append(_("15"));
    BSR_Reader_SectorNr->Append(_("16"));
    BSR_Reader_SectorNr->Append(_("17"));
    BSR_Reader_SectorNr->Append(_("18"));
    BSR_Reader_SectorNr->Append(_("19"));
    BSR_Reader_SectorNr->Append(_("20"));
    BSR_Reader_SectorNr->Append(_("21"));
    BSR_Reader_SectorNr->Append(_("22"));
    BSR_Reader_SectorNr->Append(_("23"));
    BSR_Reader_SectorNr->Append(_("24"));
    BSR_Reader_SectorNr->Append(_("25"));
    BSR_Reader_SectorNr->Append(_("26"));
    BSR_Reader_SectorNr->Append(_("27"));
    BSR_Reader_SectorNr->Append(_("28"));
    BSR_Reader_SectorNr->Append(_("29"));
    BSR_Reader_SectorNr->Append(_("30"));
    BSR_Reader_SectorNr->Append(_("31"));
    BSR_Reader_SectorNr->Append(_("32"));
    BSR_Reader_SectorNr->Append(_("33"));
    BSR_Reader_SectorNr->Append(_("34"));
    BSR_Reader_SectorNr->Append(_("35"));
    BSR_Reader_SectorNr->Append(_("36"));
    BSR_Reader_SectorNr->Append(_("37"));
    BSR_Reader_SectorNr->Append(_("38"));
    BSR_Reader_SectorNr->Append(_("39"));
    BoxSizer30->Add(BSR_Reader_SectorNr, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    StaticText59 = new wxStaticText(Panel15, ID_STATICTEXT60, _("Block:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT60"));
    BoxSizer30->Add(StaticText59, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    BSR_Reader_BlockNR = new wxComboBox(Panel15, ID_COMBOBOX20, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, wxCB_READONLY, wxDefaultValidator, _T("ID_COMBOBOX20"));
    BSR_Reader_BlockNR->SetSelection( BSR_Reader_BlockNR->Append(_("0")) );
    BSR_Reader_BlockNR->Append(_("1"));
    BSR_Reader_BlockNR->Append(_("2"));
    BSR_Reader_BlockNR->Append(_("3"));
    BSR_Reader_BlockNR->Append(_("4"));
    BSR_Reader_BlockNR->Append(_("5"));
    BSR_Reader_BlockNR->Append(_("6"));
    BSR_Reader_BlockNR->Append(_("7"));
    BSR_Reader_BlockNR->Append(_("8"));
    BSR_Reader_BlockNR->Append(_("9"));
    BSR_Reader_BlockNR->Append(_("10"));
    BSR_Reader_BlockNR->Append(_("11"));
    BSR_Reader_BlockNR->Append(_("12"));
    BSR_Reader_BlockNR->Append(_("13"));
    BSR_Reader_BlockNR->Append(_("14"));
    BSR_Reader_BlockNR->Append(_("15"));
    BoxSizer30->Add(BSR_Reader_BlockNR, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    StaticBoxSizer46->Add(BoxSizer30, 0, wxALL|wxEXPAND, 3);
    BoxSizer31 = new wxBoxSizer(wxHORIZONTAL);
    StaticText60 = new wxStaticText(Panel15, ID_STATICTEXT61, _("Reader key index :"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT61"));
    BoxSizer31->Add(StaticText60, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    BSR_Reader_KeyIndex = new wxComboBox(Panel15, ID_COMBOBOX21, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, wxCB_READONLY, wxDefaultValidator, _T("ID_COMBOBOX21"));
    BSR_Reader_KeyIndex->SetSelection( BSR_Reader_KeyIndex->Append(_("0")) );
    BSR_Reader_KeyIndex->Append(_("1"));
    BSR_Reader_KeyIndex->Append(_("2"));
    BSR_Reader_KeyIndex->Append(_("3"));
    BSR_Reader_KeyIndex->Append(_("4"));
    BSR_Reader_KeyIndex->Append(_("5"));
    BSR_Reader_KeyIndex->Append(_("6"));
    BSR_Reader_KeyIndex->Append(_("7"));
    BSR_Reader_KeyIndex->Append(_("8"));
    BSR_Reader_KeyIndex->Append(_("9"));
    BSR_Reader_KeyIndex->Append(_("10"));
    BSR_Reader_KeyIndex->Append(_("11"));
    BSR_Reader_KeyIndex->Append(_("12"));
    BSR_Reader_KeyIndex->Append(_("13"));
    BSR_Reader_KeyIndex->Append(_("14"));
    BSR_Reader_KeyIndex->Append(_("15"));
    BSR_Reader_KeyIndex->Append(_("16"));
    BSR_Reader_KeyIndex->Append(_("17"));
    BSR_Reader_KeyIndex->Append(_("18"));
    BSR_Reader_KeyIndex->Append(_("19"));
    BSR_Reader_KeyIndex->Append(_("20"));
    BSR_Reader_KeyIndex->Append(_("21"));
    BSR_Reader_KeyIndex->Append(_("22"));
    BSR_Reader_KeyIndex->Append(_("23"));
    BSR_Reader_KeyIndex->Append(_("24"));
    BSR_Reader_KeyIndex->Append(_("25"));
    BSR_Reader_KeyIndex->Append(_("26"));
    BSR_Reader_KeyIndex->Append(_("27"));
    BSR_Reader_KeyIndex->Append(_("28"));
    BSR_Reader_KeyIndex->Append(_("29"));
    BSR_Reader_KeyIndex->Append(_("30"));
    BSR_Reader_KeyIndex->Append(_("31"));
    BoxSizer31->Add(BSR_Reader_KeyIndex, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    StaticText112 = new wxStaticText(Panel15, ID_STATICTEXT113, _("(0 - 31 for CRYPTO 1) and (0 - 15 for AES key)"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT113"));
    BoxSizer31->Add(StaticText112, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    StaticBoxSizer46->Add(BoxSizer31, 0, wxALL|wxEXPAND, 3);
    bBSRReader = new wxButton(Panel15, ID_BUTTON21, _("Block in sector read Reader key"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON21"));
    StaticBoxSizer46->Add(bBSRReader, 0, wxALL|wxALIGN_LEFT, 3);
    BoxSizer26->Add(StaticBoxSizer46, 1, wxALL|wxEXPAND, 3);
    StaticBoxSizer44->Add(BoxSizer26, 0, wxALL|wxEXPAND, 3);
    BoxSizer32 = new wxBoxSizer(wxHORIZONTAL);
    StaticBoxSizer47 = new wxStaticBoxSizer(wxVERTICAL, Panel15, _("AKM1 key"));
    BoxSizer33 = new wxBoxSizer(wxHORIZONTAL);
    BSR_AKM1_KeyA = new wxRadioButton(Panel15, ID_RADIOBUTTON19, _("KEY A"), wxDefaultPosition, wxDefaultSize, wxRB_GROUP, wxDefaultValidator, _T("ID_RADIOBUTTON19"));
    BSR_AKM1_KeyA->SetValue(true);
    BoxSizer33->Add(BSR_AKM1_KeyA, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    BSR_AKM1_KeyB = new wxRadioButton(Panel15, ID_RADIOBUTTON20, _("KEY B"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON20"));
    BoxSizer33->Add(BSR_AKM1_KeyB, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    BoxSizer33->Add(-1,-1,0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    StaticText73 = new wxStaticText(Panel15, ID_STATICTEXT74, _("Sector:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT74"));
    BoxSizer33->Add(StaticText73, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    BSR_AKM1_SectorNr = new wxComboBox(Panel15, ID_COMBOBOX26, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, wxCB_READONLY, wxDefaultValidator, _T("ID_COMBOBOX26"));
    BSR_AKM1_SectorNr->SetSelection( BSR_AKM1_SectorNr->Append(_("0")) );
    BSR_AKM1_SectorNr->Append(_("1"));
    BSR_AKM1_SectorNr->Append(_("2"));
    BSR_AKM1_SectorNr->Append(_("3"));
    BSR_AKM1_SectorNr->Append(_("4"));
    BSR_AKM1_SectorNr->Append(_("5"));
    BSR_AKM1_SectorNr->Append(_("6"));
    BSR_AKM1_SectorNr->Append(_("7"));
    BSR_AKM1_SectorNr->Append(_("8"));
    BSR_AKM1_SectorNr->Append(_("9"));
    BSR_AKM1_SectorNr->Append(_("10"));
    BSR_AKM1_SectorNr->Append(_("11"));
    BSR_AKM1_SectorNr->Append(_("12"));
    BSR_AKM1_SectorNr->Append(_("13"));
    BSR_AKM1_SectorNr->Append(_("14"));
    BSR_AKM1_SectorNr->Append(_("15"));
    BSR_AKM1_SectorNr->Append(_("16"));
    BSR_AKM1_SectorNr->Append(_("17"));
    BSR_AKM1_SectorNr->Append(_("18"));
    BSR_AKM1_SectorNr->Append(_("19"));
    BSR_AKM1_SectorNr->Append(_("20"));
    BSR_AKM1_SectorNr->Append(_("21"));
    BSR_AKM1_SectorNr->Append(_("22"));
    BSR_AKM1_SectorNr->Append(_("23"));
    BSR_AKM1_SectorNr->Append(_("24"));
    BSR_AKM1_SectorNr->Append(_("25"));
    BSR_AKM1_SectorNr->Append(_("26"));
    BSR_AKM1_SectorNr->Append(_("27"));
    BSR_AKM1_SectorNr->Append(_("28"));
    BSR_AKM1_SectorNr->Append(_("29"));
    BSR_AKM1_SectorNr->Append(_("30"));
    BSR_AKM1_SectorNr->Append(_("31"));
    BSR_AKM1_SectorNr->Append(_("32"));
    BSR_AKM1_SectorNr->Append(_("33"));
    BSR_AKM1_SectorNr->Append(_("34"));
    BSR_AKM1_SectorNr->Append(_("35"));
    BSR_AKM1_SectorNr->Append(_("36"));
    BSR_AKM1_SectorNr->Append(_("37"));
    BSR_AKM1_SectorNr->Append(_("38"));
    BSR_AKM1_SectorNr->Append(_("39"));
    BoxSizer33->Add(BSR_AKM1_SectorNr, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    StaticText61 = new wxStaticText(Panel15, ID_STATICTEXT62, _("Block:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT62"));
    BoxSizer33->Add(StaticText61, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    BSR_AKM1_BlockNr = new wxComboBox(Panel15, ID_COMBOBOX22, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, wxCB_READONLY, wxDefaultValidator, _T("ID_COMBOBOX22"));
    BSR_AKM1_BlockNr->SetSelection( BSR_AKM1_BlockNr->Append(_("0")) );
    BSR_AKM1_BlockNr->Append(_("1"));
    BSR_AKM1_BlockNr->Append(_("2"));
    BSR_AKM1_BlockNr->Append(_("3"));
    BSR_AKM1_BlockNr->Append(_("4"));
    BSR_AKM1_BlockNr->Append(_("5"));
    BSR_AKM1_BlockNr->Append(_("6"));
    BSR_AKM1_BlockNr->Append(_("7"));
    BSR_AKM1_BlockNr->Append(_("8"));
    BSR_AKM1_BlockNr->Append(_("9"));
    BSR_AKM1_BlockNr->Append(_("10"));
    BSR_AKM1_BlockNr->Append(_("11"));
    BSR_AKM1_BlockNr->Append(_("12"));
    BSR_AKM1_BlockNr->Append(_("13"));
    BSR_AKM1_BlockNr->Append(_("14"));
    BSR_AKM1_BlockNr->Append(_("15"));
    BoxSizer33->Add(BSR_AKM1_BlockNr, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    StaticBoxSizer47->Add(BoxSizer33, 1, wxALL|wxALIGN_LEFT, 3);
    bBSRAKM1 = new wxButton(Panel15, ID_BUTTON22, _("Block in sector read AKM1 key"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON22"));
    StaticBoxSizer47->Add(bBSRAKM1, 1, wxALL|wxALIGN_LEFT, 5);
    BoxSizer32->Add(StaticBoxSizer47, 1, wxALL|wxEXPAND, 3);
    StaticBoxSizer48 = new wxStaticBoxSizer(wxVERTICAL, Panel15, _("AKM2 key"));
    BoxSizer34 = new wxBoxSizer(wxHORIZONTAL);
    BSR_AKM2_KeyA = new wxRadioButton(Panel15, ID_RADIOBUTTON21, _("KEY A"), wxDefaultPosition, wxDefaultSize, wxRB_GROUP, wxDefaultValidator, _T("ID_RADIOBUTTON21"));
    BSR_AKM2_KeyA->SetValue(true);
    BoxSizer34->Add(BSR_AKM2_KeyA, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    BSR_AKM2_KeyB = new wxRadioButton(Panel15, ID_RADIOBUTTON22, _("KEY B"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON22"));
    BoxSizer34->Add(BSR_AKM2_KeyB, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    BoxSizer34->Add(-1,-1,0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    StaticText75 = new wxStaticText(Panel15, ID_STATICTEXT76, _("Sector:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT76"));
    BoxSizer34->Add(StaticText75, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    BSR_AKM2_SectorNr = new wxComboBox(Panel15, ID_COMBOBOX27, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, wxCB_READONLY, wxDefaultValidator, _T("ID_COMBOBOX27"));
    BSR_AKM2_SectorNr->SetSelection( BSR_AKM2_SectorNr->Append(_("0")) );
    BSR_AKM2_SectorNr->Append(_("1"));
    BSR_AKM2_SectorNr->Append(_("2"));
    BSR_AKM2_SectorNr->Append(_("3"));
    BSR_AKM2_SectorNr->Append(_("4"));
    BSR_AKM2_SectorNr->Append(_("5"));
    BSR_AKM2_SectorNr->Append(_("6"));
    BSR_AKM2_SectorNr->Append(_("7"));
    BSR_AKM2_SectorNr->Append(_("8"));
    BSR_AKM2_SectorNr->Append(_("9"));
    BSR_AKM2_SectorNr->Append(_("10"));
    BSR_AKM2_SectorNr->Append(_("11"));
    BSR_AKM2_SectorNr->Append(_("12"));
    BSR_AKM2_SectorNr->Append(_("13"));
    BSR_AKM2_SectorNr->Append(_("14"));
    BSR_AKM2_SectorNr->Append(_("15"));
    BSR_AKM2_SectorNr->Append(_("16"));
    BSR_AKM2_SectorNr->Append(_("17"));
    BSR_AKM2_SectorNr->Append(_("18"));
    BSR_AKM2_SectorNr->Append(_("19"));
    BSR_AKM2_SectorNr->Append(_("20"));
    BSR_AKM2_SectorNr->Append(_("21"));
    BSR_AKM2_SectorNr->Append(_("22"));
    BSR_AKM2_SectorNr->Append(_("23"));
    BSR_AKM2_SectorNr->Append(_("24"));
    BSR_AKM2_SectorNr->Append(_("25"));
    BSR_AKM2_SectorNr->Append(_("26"));
    BSR_AKM2_SectorNr->Append(_("27"));
    BSR_AKM2_SectorNr->Append(_("28"));
    BSR_AKM2_SectorNr->Append(_("29"));
    BSR_AKM2_SectorNr->Append(_("30"));
    BSR_AKM2_SectorNr->Append(_("31"));
    BSR_AKM2_SectorNr->Append(_("32"));
    BSR_AKM2_SectorNr->Append(_("33"));
    BSR_AKM2_SectorNr->Append(_("34"));
    BSR_AKM2_SectorNr->Append(_("35"));
    BSR_AKM2_SectorNr->Append(_("36"));
    BSR_AKM2_SectorNr->Append(_("37"));
    BSR_AKM2_SectorNr->Append(_("38"));
    BSR_AKM2_SectorNr->Append(_("39"));
    BoxSizer34->Add(BSR_AKM2_SectorNr, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    StaticText62 = new wxStaticText(Panel15, ID_STATICTEXT63, _("Block:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT63"));
    BoxSizer34->Add(StaticText62, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    BSR_AKM2_BlockNr = new wxComboBox(Panel15, ID_COMBOBOX23, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, wxCB_READONLY, wxDefaultValidator, _T("ID_COMBOBOX23"));
    BSR_AKM2_BlockNr->SetSelection( BSR_AKM2_BlockNr->Append(_("0")) );
    BSR_AKM2_BlockNr->Append(_("1"));
    BSR_AKM2_BlockNr->Append(_("2"));
    BSR_AKM2_BlockNr->Append(_("3"));
    BSR_AKM2_BlockNr->Append(_("4"));
    BSR_AKM2_BlockNr->Append(_("5"));
    BSR_AKM2_BlockNr->Append(_("6"));
    BSR_AKM2_BlockNr->Append(_("7"));
    BSR_AKM2_BlockNr->Append(_("8"));
    BSR_AKM2_BlockNr->Append(_("9"));
    BSR_AKM2_BlockNr->Append(_("10"));
    BSR_AKM2_BlockNr->Append(_("11"));
    BSR_AKM2_BlockNr->Append(_("12"));
    BSR_AKM2_BlockNr->Append(_("13"));
    BSR_AKM2_BlockNr->Append(_("14"));
    BSR_AKM2_BlockNr->Append(_("15"));
    BoxSizer34->Add(BSR_AKM2_BlockNr, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    StaticBoxSizer48->Add(BoxSizer34, 0, wxALL|wxALIGN_LEFT, 3);
    bBSRAKM2 = new wxButton(Panel15, ID_BUTTON23, _("Block in sector read AKM2 key"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON23"));
    StaticBoxSizer48->Add(bBSRAKM2, 1, wxALL|wxALIGN_LEFT, 5);
    BoxSizer32->Add(StaticBoxSizer48, 1, wxALL|wxEXPAND, 3);
    StaticBoxSizer44->Add(BoxSizer32, 0, wxALL|wxEXPAND, 3);
    StaticText105 = new wxStaticText(Panel15, ID_STATICTEXT106, _("Sector: (0 - 31 for 2K cards) and (0 - 39 for 4K cards), Block: (0 - 3 for sectors 0 - 31) and (0 - 15 for sectors 32 - 39)"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT106"));
    StaticBoxSizer44->Add(StaticText105, 0, wxALL|wxALIGN_LEFT, 3);
    Panel15->SetSizer(StaticBoxSizer44);
    StaticBoxSizer44->Fit(Panel15);
    StaticBoxSizer44->SetSizeHints(Panel15);
    Panel16 = new wxPanel(Notebook2, ID_PANEL16, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL16"));
    StaticBoxSizer49 = new wxStaticBoxSizer(wxVERTICAL, Panel16, wxEmptyString);
    BoxSizer35 = new wxBoxSizer(wxHORIZONTAL);
    StaticBoxSizer50 = new wxStaticBoxSizer(wxVERTICAL, Panel16, _("Provided key"));
    BoxSizer36 = new wxBoxSizer(wxHORIZONTAL);
    LR_Provided_KeyA = new wxRadioButton(Panel16, ID_RADIOBUTTON23, _("KEY A"), wxDefaultPosition, wxDefaultSize, wxRB_GROUP, wxDefaultValidator, _T("ID_RADIOBUTTON23"));
    LR_Provided_KeyA->SetValue(true);
    BoxSizer36->Add(LR_Provided_KeyA, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    LR_Provided_KeyB = new wxRadioButton(Panel16, ID_RADIOBUTTON24, _("KEY B"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON24"));
    BoxSizer36->Add(LR_Provided_KeyB, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    BoxSizer36->Add(-1,-1,0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    StaticText63 = new wxStaticText(Panel16, ID_STATICTEXT64, _("Address:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT64"));
    BoxSizer36->Add(StaticText63, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    LR_ProvidedAddr = new wxTextCtrl(Panel16, ID_TEXTCTRL40, wxEmptyString, wxDefaultPosition, wxSize(39,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL40"));
    LR_ProvidedAddr->SetMaxLength(4);
    BoxSizer36->Add(LR_ProvidedAddr, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    StaticText68 = new wxStaticText(Panel16, ID_STATICTEXT69, _("Number of bytes:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT69"));
    BoxSizer36->Add(StaticText68, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    LR_Provided_Bytes = new wxTextCtrl(Panel16, ID_TEXTCTRL41, wxEmptyString, wxDefaultPosition, wxSize(39,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL41"));
    LR_Provided_Bytes->SetMaxLength(4);
    BoxSizer36->Add(LR_Provided_Bytes, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    StaticBoxSizer50->Add(BoxSizer36, 0, wxALL|wxEXPAND, 3);
    BoxSizer37 = new wxBoxSizer(wxHORIZONTAL);
    StaticText69 = new wxStaticText(Panel16, ID_STATICTEXT70, _("Key:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT70"));
    BoxSizer37->Add(StaticText69, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    LR_Key = new wxTextCtrl(Panel16, ID_TEXTCTRL42, wxEmptyString, wxDefaultPosition, wxSize(203,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL42"));
    LR_Key->SetMaxLength(32);
    BoxSizer37->Add(LR_Key, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    StaticBoxSizer50->Add(BoxSizer37, 0, wxALL|wxEXPAND, 3);
    bLRProvided = new wxButton(Panel16, ID_BUTTON24, _("Linear read provided key"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON24"));
    StaticBoxSizer50->Add(bLRProvided, 0, wxALL|wxALIGN_LEFT, 3);
    BoxSizer35->Add(StaticBoxSizer50, 1, wxALL|wxEXPAND, 3);
    StaticBoxSizer51 = new wxStaticBoxSizer(wxVERTICAL, Panel16, _("Reader key"));
    BoxSizer38 = new wxBoxSizer(wxHORIZONTAL);
    LR_Reader_KeyA = new wxRadioButton(Panel16, ID_RADIOBUTTON25, _("KEY A"), wxDefaultPosition, wxDefaultSize, wxRB_GROUP, wxDefaultValidator, _T("ID_RADIOBUTTON25"));
    LR_Reader_KeyA->SetValue(true);
    BoxSizer38->Add(LR_Reader_KeyA, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    LR_Reader_KeyB = new wxRadioButton(Panel16, ID_RADIOBUTTON26, _("KEY B"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON26"));
    BoxSizer38->Add(LR_Reader_KeyB, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    BoxSizer38->Add(-1,-1,0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    StaticText64 = new wxStaticText(Panel16, ID_STATICTEXT65, _("Address:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT65"));
    BoxSizer38->Add(StaticText64, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    LR_ReaderAddr = new wxTextCtrl(Panel16, ID_TEXTCTRL43, wxEmptyString, wxDefaultPosition, wxSize(39,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL43"));
    LR_ReaderAddr->SetMaxLength(4);
    BoxSizer38->Add(LR_ReaderAddr, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    StaticText71 = new wxStaticText(Panel16, ID_STATICTEXT72, _("Number of bytes:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT72"));
    BoxSizer38->Add(StaticText71, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    LR_ReaderBytes = new wxTextCtrl(Panel16, ID_TEXTCTRL44, wxEmptyString, wxDefaultPosition, wxSize(39,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL44"));
    LR_ReaderBytes->SetMaxLength(4);
    BoxSizer38->Add(LR_ReaderBytes, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    StaticBoxSizer51->Add(BoxSizer38, 0, wxALL|wxEXPAND, 3);
    BoxSizer39 = new wxBoxSizer(wxHORIZONTAL);
    StaticText72 = new wxStaticText(Panel16, ID_STATICTEXT73, _("Key index:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT73"));
    BoxSizer39->Add(StaticText72, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    LR_ReaderKeyIndex = new wxComboBox(Panel16, ID_COMBOBOX28, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, wxCB_READONLY, wxDefaultValidator, _T("ID_COMBOBOX28"));
    LR_ReaderKeyIndex->SetSelection( LR_ReaderKeyIndex->Append(_("0")) );
    LR_ReaderKeyIndex->Append(_("1"));
    LR_ReaderKeyIndex->Append(_("2"));
    LR_ReaderKeyIndex->Append(_("3"));
    LR_ReaderKeyIndex->Append(_("4"));
    LR_ReaderKeyIndex->Append(_("5"));
    LR_ReaderKeyIndex->Append(_("6"));
    LR_ReaderKeyIndex->Append(_("7"));
    LR_ReaderKeyIndex->Append(_("8"));
    LR_ReaderKeyIndex->Append(_("9"));
    LR_ReaderKeyIndex->Append(_("10"));
    LR_ReaderKeyIndex->Append(_("11"));
    LR_ReaderKeyIndex->Append(_("12"));
    LR_ReaderKeyIndex->Append(_("13"));
    LR_ReaderKeyIndex->Append(_("14"));
    LR_ReaderKeyIndex->Append(_("15"));
    LR_ReaderKeyIndex->Append(_("16"));
    LR_ReaderKeyIndex->Append(_("17"));
    LR_ReaderKeyIndex->Append(_("18"));
    LR_ReaderKeyIndex->Append(_("19"));
    LR_ReaderKeyIndex->Append(_("20"));
    LR_ReaderKeyIndex->Append(_("21"));
    LR_ReaderKeyIndex->Append(_("22"));
    LR_ReaderKeyIndex->Append(_("23"));
    LR_ReaderKeyIndex->Append(_("24"));
    LR_ReaderKeyIndex->Append(_("25"));
    LR_ReaderKeyIndex->Append(_("26"));
    LR_ReaderKeyIndex->Append(_("27"));
    LR_ReaderKeyIndex->Append(_("28"));
    LR_ReaderKeyIndex->Append(_("29"));
    LR_ReaderKeyIndex->Append(_("30"));
    LR_ReaderKeyIndex->Append(_("31"));
    BoxSizer39->Add(LR_ReaderKeyIndex, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    StaticText111 = new wxStaticText(Panel16, ID_STATICTEXT112, _("(0 - 31 for CRYPTO 1) and (0 - 15 for AES key)"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT112"));
    BoxSizer39->Add(StaticText111, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    StaticBoxSizer51->Add(BoxSizer39, 0, wxALL|wxEXPAND, 3);
    bLRReader = new wxButton(Panel16, ID_BUTTON25, _("Linear read reader key"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON25"));
    StaticBoxSizer51->Add(bLRReader, 0, wxALL|wxALIGN_LEFT, 3);
    BoxSizer35->Add(StaticBoxSizer51, 1, wxALL|wxEXPAND, 3);
    StaticBoxSizer49->Add(BoxSizer35, 0, wxALL|wxEXPAND, 3);
    BoxSizer40 = new wxBoxSizer(wxHORIZONTAL);
    StaticBoxSizer52 = new wxStaticBoxSizer(wxVERTICAL, Panel16, _("AKM1 key"));
    BoxSizer41 = new wxBoxSizer(wxHORIZONTAL);
    LR_AKM1_KeyA = new wxRadioButton(Panel16, ID_RADIOBUTTON27, _("KEY A"), wxDefaultPosition, wxDefaultSize, wxRB_GROUP, wxDefaultValidator, _T("ID_RADIOBUTTON27"));
    LR_AKM1_KeyA->SetValue(true);
    BoxSizer41->Add(LR_AKM1_KeyA, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    LR_AKM1_KeyB = new wxRadioButton(Panel16, ID_RADIOBUTTON28, _("KEY B"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON28"));
    BoxSizer41->Add(LR_AKM1_KeyB, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    BoxSizer41->Add(-1,-1,0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    StaticText65 = new wxStaticText(Panel16, ID_STATICTEXT66, _("Address:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT66"));
    BoxSizer41->Add(StaticText65, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    LR_AKM1_Addr = new wxTextCtrl(Panel16, ID_TEXTCTRL45, wxEmptyString, wxDefaultPosition, wxSize(39,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL45"));
    BoxSizer41->Add(LR_AKM1_Addr, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    StaticText74 = new wxStaticText(Panel16, ID_STATICTEXT75, _("Number of bytes:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT75"));
    BoxSizer41->Add(StaticText74, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    LR_AKM1_Bytes = new wxTextCtrl(Panel16, ID_TEXTCTRL46, wxEmptyString, wxDefaultPosition, wxSize(39,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL46"));
    LR_AKM1_Bytes->SetMaxLength(4);
    BoxSizer41->Add(LR_AKM1_Bytes, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    StaticBoxSizer52->Add(BoxSizer41, 1, wxALL|wxEXPAND, 3);
    bLRAKM1 = new wxButton(Panel16, ID_BUTTON26, _("Linear read AKM1 key"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON26"));
    StaticBoxSizer52->Add(bLRAKM1, 0, wxALL|wxALIGN_LEFT, 3);
    BoxSizer40->Add(StaticBoxSizer52, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    StaticBoxSizer53 = new wxStaticBoxSizer(wxVERTICAL, Panel16, _("AKM2 \\key"));
    BoxSizer42 = new wxBoxSizer(wxHORIZONTAL);
    LR_AKM2_KeyA = new wxRadioButton(Panel16, ID_RADIOBUTTON29, _("KEY A"), wxDefaultPosition, wxDefaultSize, wxRB_GROUP, wxDefaultValidator, _T("ID_RADIOBUTTON29"));
    LR_AKM2_KeyA->SetValue(true);
    BoxSizer42->Add(LR_AKM2_KeyA, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    LR_AKM2_KeyB = new wxRadioButton(Panel16, ID_RADIOBUTTON30, _("KEY B"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON30"));
    BoxSizer42->Add(LR_AKM2_KeyB, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer42->Add(-1,-1,0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    StaticText66 = new wxStaticText(Panel16, ID_STATICTEXT67, _("Address:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT67"));
    BoxSizer42->Add(StaticText66, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    LR_AKM2_Addr = new wxTextCtrl(Panel16, ID_TEXTCTRL47, wxEmptyString, wxDefaultPosition, wxSize(39,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL47"));
    BoxSizer42->Add(LR_AKM2_Addr, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    StaticText76 = new wxStaticText(Panel16, ID_STATICTEXT77, _("Number of bytes:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT77"));
    BoxSizer42->Add(StaticText76, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    LR_AKM2_Bytes = new wxTextCtrl(Panel16, ID_TEXTCTRL48, wxEmptyString, wxDefaultPosition, wxSize(39,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL48"));
    LR_AKM2_Bytes->SetMaxLength(4);
    BoxSizer42->Add(LR_AKM2_Bytes, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    StaticBoxSizer53->Add(BoxSizer42, 0, wxALL|wxEXPAND, 3);
    bLRAKM2 = new wxButton(Panel16, ID_BUTTON27, _("Linear read AKM2 key"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON27"));
    StaticBoxSizer53->Add(bLRAKM2, 0, wxALL|wxALIGN_LEFT, 3);
    BoxSizer40->Add(StaticBoxSizer53, 1, wxALL|wxEXPAND, 3);
    StaticBoxSizer49->Add(BoxSizer40, 0, wxALL|wxEXPAND, 3);
    StaticText104 = new wxStaticText(Panel16, ID_STATICTEXT105, _("Address: (0 - 1519 for 2K cards) and (0 - 3439 for 4K cards)"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT105"));
    StaticBoxSizer49->Add(StaticText104, 0, wxALL|wxALIGN_LEFT, 3);
    Panel16->SetSizer(StaticBoxSizer49);
    StaticBoxSizer49->Fit(Panel16);
    StaticBoxSizer49->SetSizeHints(Panel16);
    Notebook2->AddPage(Panel14, _("Block read"), false);
    Notebook2->AddPage(Panel15, _("Block in sector read"), false);
    Notebook2->AddPage(Panel16, _("Linear read"), false);
    StaticBoxSizer38->Add(Notebook2, 1, wxALL|wxEXPAND, 0);
    Panel11->SetSizer(StaticBoxSizer38);
    StaticBoxSizer38->Fit(Panel11);
    StaticBoxSizer38->SetSizeHints(Panel11);
    Panel12 = new wxPanel(Notebook1, ID_PANEL12, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL12"));
    StaticBoxSizer54 = new wxStaticBoxSizer(wxVERTICAL, Panel12, wxEmptyString);
    Notebook3 = new wxNotebook(Panel12, ID_NOTEBOOK3, wxDefaultPosition, wxDefaultSize, 0, _T("ID_NOTEBOOK3"));
    Panel17 = new wxPanel(Notebook3, ID_PANEL17, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL17"));
    StaticBoxSizer55 = new wxStaticBoxSizer(wxVERTICAL, Panel17, wxEmptyString);
    BoxSizer44 = new wxBoxSizer(wxHORIZONTAL);
    StaticBoxSizer56 = new wxStaticBoxSizer(wxVERTICAL, Panel17, _("Provided key"));
    BoxSizer46 = new wxBoxSizer(wxHORIZONTAL);
    BW_Provided_KeyA = new wxRadioButton(Panel17, ID_RADIOBUTTON31, _("Key A"), wxDefaultPosition, wxDefaultSize, wxRB_GROUP, wxDefaultValidator, _T("ID_RADIOBUTTON31"));
    BW_Provided_KeyA->SetValue(true);
    BoxSizer46->Add(BW_Provided_KeyA, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    BW_Provided_KeyB = new wxRadioButton(Panel17, ID_RADIOBUTTON32, _("Key B"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON32"));
    BoxSizer46->Add(BW_Provided_KeyB, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    StaticText79 = new wxStaticText(Panel17, ID_STATICTEXT80, _("Block :"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT80"));
    BoxSizer46->Add(StaticText79, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    BW_Provided_BlockNr = new wxComboBox(Panel17, ID_COMBOBOX29, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, wxCB_READONLY, wxDefaultValidator, _T("ID_COMBOBOX29"));
    BW_Provided_BlockNr->SetSelection( BW_Provided_BlockNr->Append(_("0")) );
    BW_Provided_BlockNr->Append(_("1"));
    BW_Provided_BlockNr->Append(_("2"));
    BW_Provided_BlockNr->Append(_("3"));
    BW_Provided_BlockNr->Append(_("4"));
    BW_Provided_BlockNr->Append(_("5"));
    BW_Provided_BlockNr->Append(_("6"));
    BW_Provided_BlockNr->Append(_("7"));
    BW_Provided_BlockNr->Append(_("8"));
    BW_Provided_BlockNr->Append(_("9"));
    BW_Provided_BlockNr->Append(_("10"));
    BW_Provided_BlockNr->Append(_("11"));
    BW_Provided_BlockNr->Append(_("12"));
    BW_Provided_BlockNr->Append(_("13"));
    BW_Provided_BlockNr->Append(_("14"));
    BW_Provided_BlockNr->Append(_("15"));
    BW_Provided_BlockNr->Append(_("16"));
    BW_Provided_BlockNr->Append(_("17"));
    BW_Provided_BlockNr->Append(_("18"));
    BW_Provided_BlockNr->Append(_("19"));
    BW_Provided_BlockNr->Append(_("20"));
    BW_Provided_BlockNr->Append(_("21"));
    BW_Provided_BlockNr->Append(_("22"));
    BW_Provided_BlockNr->Append(_("23"));
    BW_Provided_BlockNr->Append(_("24"));
    BW_Provided_BlockNr->Append(_("25"));
    BW_Provided_BlockNr->Append(_("26"));
    BW_Provided_BlockNr->Append(_("27"));
    BW_Provided_BlockNr->Append(_("28"));
    BW_Provided_BlockNr->Append(_("29"));
    BW_Provided_BlockNr->Append(_("30"));
    BW_Provided_BlockNr->Append(_("31"));
    BW_Provided_BlockNr->Append(_("32"));
    BW_Provided_BlockNr->Append(_("33"));
    BW_Provided_BlockNr->Append(_("34"));
    BW_Provided_BlockNr->Append(_("35"));
    BW_Provided_BlockNr->Append(_("36"));
    BW_Provided_BlockNr->Append(_("37"));
    BW_Provided_BlockNr->Append(_("38"));
    BW_Provided_BlockNr->Append(_("39"));
    BW_Provided_BlockNr->Append(_("40"));
    BW_Provided_BlockNr->Append(_("41"));
    BW_Provided_BlockNr->Append(_("42"));
    BW_Provided_BlockNr->Append(_("43"));
    BW_Provided_BlockNr->Append(_("44"));
    BW_Provided_BlockNr->Append(_("45"));
    BW_Provided_BlockNr->Append(_("46"));
    BW_Provided_BlockNr->Append(_("47"));
    BW_Provided_BlockNr->Append(_("48"));
    BW_Provided_BlockNr->Append(_("49"));
    BW_Provided_BlockNr->Append(_("50"));
    BW_Provided_BlockNr->Append(_("51"));
    BW_Provided_BlockNr->Append(_("52"));
    BW_Provided_BlockNr->Append(_("53"));
    BW_Provided_BlockNr->Append(_("54"));
    BW_Provided_BlockNr->Append(_("55"));
    BW_Provided_BlockNr->Append(_("56"));
    BW_Provided_BlockNr->Append(_("57"));
    BW_Provided_BlockNr->Append(_("58"));
    BW_Provided_BlockNr->Append(_("59"));
    BW_Provided_BlockNr->Append(_("60"));
    BW_Provided_BlockNr->Append(_("61"));
    BW_Provided_BlockNr->Append(_("62"));
    BW_Provided_BlockNr->Append(_("63"));
    BW_Provided_BlockNr->Append(_("64"));
    BW_Provided_BlockNr->Append(_("65"));
    BW_Provided_BlockNr->Append(_("66"));
    BW_Provided_BlockNr->Append(_("67"));
    BW_Provided_BlockNr->Append(_("68"));
    BW_Provided_BlockNr->Append(_("69"));
    BW_Provided_BlockNr->Append(_("70"));
    BW_Provided_BlockNr->Append(_("71"));
    BW_Provided_BlockNr->Append(_("72"));
    BW_Provided_BlockNr->Append(_("73"));
    BW_Provided_BlockNr->Append(_("74"));
    BW_Provided_BlockNr->Append(_("75"));
    BW_Provided_BlockNr->Append(_("76"));
    BW_Provided_BlockNr->Append(_("77"));
    BW_Provided_BlockNr->Append(_("78"));
    BW_Provided_BlockNr->Append(_("79"));
    BW_Provided_BlockNr->Append(_("80"));
    BW_Provided_BlockNr->Append(_("81"));
    BW_Provided_BlockNr->Append(_("82"));
    BW_Provided_BlockNr->Append(_("83"));
    BW_Provided_BlockNr->Append(_("84"));
    BW_Provided_BlockNr->Append(_("85"));
    BW_Provided_BlockNr->Append(_("86"));
    BW_Provided_BlockNr->Append(_("87"));
    BW_Provided_BlockNr->Append(_("88"));
    BW_Provided_BlockNr->Append(_("89"));
    BW_Provided_BlockNr->Append(_("90"));
    BW_Provided_BlockNr->Append(_("91"));
    BW_Provided_BlockNr->Append(_("92"));
    BW_Provided_BlockNr->Append(_("93"));
    BW_Provided_BlockNr->Append(_("94"));
    BW_Provided_BlockNr->Append(_("95"));
    BW_Provided_BlockNr->Append(_("96"));
    BW_Provided_BlockNr->Append(_("97"));
    BW_Provided_BlockNr->Append(_("98"));
    BW_Provided_BlockNr->Append(_("99"));
    BW_Provided_BlockNr->Append(_("100"));
    BW_Provided_BlockNr->Append(_("101"));
    BW_Provided_BlockNr->Append(_("102"));
    BW_Provided_BlockNr->Append(_("103"));
    BW_Provided_BlockNr->Append(_("104"));
    BW_Provided_BlockNr->Append(_("105"));
    BW_Provided_BlockNr->Append(_("106"));
    BW_Provided_BlockNr->Append(_("107"));
    BW_Provided_BlockNr->Append(_("108"));
    BW_Provided_BlockNr->Append(_("109"));
    BW_Provided_BlockNr->Append(_("110"));
    BW_Provided_BlockNr->Append(_("111"));
    BW_Provided_BlockNr->Append(_("112"));
    BW_Provided_BlockNr->Append(_("113"));
    BW_Provided_BlockNr->Append(_("114"));
    BW_Provided_BlockNr->Append(_("115"));
    BW_Provided_BlockNr->Append(_("116"));
    BW_Provided_BlockNr->Append(_("117"));
    BW_Provided_BlockNr->Append(_("118"));
    BW_Provided_BlockNr->Append(_("119"));
    BW_Provided_BlockNr->Append(_("120"));
    BW_Provided_BlockNr->Append(_("121"));
    BW_Provided_BlockNr->Append(_("122"));
    BW_Provided_BlockNr->Append(_("123"));
    BW_Provided_BlockNr->Append(_("124"));
    BW_Provided_BlockNr->Append(_("125"));
    BW_Provided_BlockNr->Append(_("126"));
    BW_Provided_BlockNr->Append(_("127"));
    BW_Provided_BlockNr->Append(_("128"));
    BW_Provided_BlockNr->Append(_("129"));
    BW_Provided_BlockNr->Append(_("130"));
    BW_Provided_BlockNr->Append(_("131"));
    BW_Provided_BlockNr->Append(_("132"));
    BW_Provided_BlockNr->Append(_("133"));
    BW_Provided_BlockNr->Append(_("134"));
    BW_Provided_BlockNr->Append(_("135"));
    BW_Provided_BlockNr->Append(_("136"));
    BW_Provided_BlockNr->Append(_("137"));
    BW_Provided_BlockNr->Append(_("138"));
    BW_Provided_BlockNr->Append(_("139"));
    BW_Provided_BlockNr->Append(_("140"));
    BW_Provided_BlockNr->Append(_("141"));
    BW_Provided_BlockNr->Append(_("142"));
    BW_Provided_BlockNr->Append(_("143"));
    BW_Provided_BlockNr->Append(_("144"));
    BW_Provided_BlockNr->Append(_("145"));
    BW_Provided_BlockNr->Append(_("146"));
    BW_Provided_BlockNr->Append(_("147"));
    BW_Provided_BlockNr->Append(_("148"));
    BW_Provided_BlockNr->Append(_("149"));
    BW_Provided_BlockNr->Append(_("150"));
    BW_Provided_BlockNr->Append(_("151"));
    BW_Provided_BlockNr->Append(_("152"));
    BW_Provided_BlockNr->Append(_("153"));
    BW_Provided_BlockNr->Append(_("154"));
    BW_Provided_BlockNr->Append(_("155"));
    BW_Provided_BlockNr->Append(_("156"));
    BW_Provided_BlockNr->Append(_("157"));
    BW_Provided_BlockNr->Append(_("158"));
    BW_Provided_BlockNr->Append(_("159"));
    BW_Provided_BlockNr->Append(_("160"));
    BW_Provided_BlockNr->Append(_("161"));
    BW_Provided_BlockNr->Append(_("162"));
    BW_Provided_BlockNr->Append(_("163"));
    BW_Provided_BlockNr->Append(_("164"));
    BW_Provided_BlockNr->Append(_("165"));
    BW_Provided_BlockNr->Append(_("166"));
    BW_Provided_BlockNr->Append(_("167"));
    BW_Provided_BlockNr->Append(_("168"));
    BW_Provided_BlockNr->Append(_("169"));
    BW_Provided_BlockNr->Append(_("170"));
    BW_Provided_BlockNr->Append(_("171"));
    BW_Provided_BlockNr->Append(_("172"));
    BW_Provided_BlockNr->Append(_("173"));
    BW_Provided_BlockNr->Append(_("174"));
    BW_Provided_BlockNr->Append(_("175"));
    BW_Provided_BlockNr->Append(_("176"));
    BW_Provided_BlockNr->Append(_("177"));
    BW_Provided_BlockNr->Append(_("178"));
    BW_Provided_BlockNr->Append(_("179"));
    BW_Provided_BlockNr->Append(_("180"));
    BW_Provided_BlockNr->Append(_("181"));
    BW_Provided_BlockNr->Append(_("182"));
    BW_Provided_BlockNr->Append(_("183"));
    BW_Provided_BlockNr->Append(_("184"));
    BW_Provided_BlockNr->Append(_("185"));
    BW_Provided_BlockNr->Append(_("186"));
    BW_Provided_BlockNr->Append(_("187"));
    BW_Provided_BlockNr->Append(_("188"));
    BW_Provided_BlockNr->Append(_("189"));
    BW_Provided_BlockNr->Append(_("190"));
    BW_Provided_BlockNr->Append(_("191"));
    BW_Provided_BlockNr->Append(_("192"));
    BW_Provided_BlockNr->Append(_("193"));
    BW_Provided_BlockNr->Append(_("194"));
    BW_Provided_BlockNr->Append(_("195"));
    BW_Provided_BlockNr->Append(_("196"));
    BW_Provided_BlockNr->Append(_("197"));
    BW_Provided_BlockNr->Append(_("198"));
    BW_Provided_BlockNr->Append(_("199"));
    BW_Provided_BlockNr->Append(_("200"));
    BW_Provided_BlockNr->Append(_("201"));
    BW_Provided_BlockNr->Append(_("202"));
    BW_Provided_BlockNr->Append(_("203"));
    BW_Provided_BlockNr->Append(_("204"));
    BW_Provided_BlockNr->Append(_("205"));
    BW_Provided_BlockNr->Append(_("206"));
    BW_Provided_BlockNr->Append(_("207"));
    BW_Provided_BlockNr->Append(_("208"));
    BW_Provided_BlockNr->Append(_("209"));
    BW_Provided_BlockNr->Append(_("210"));
    BW_Provided_BlockNr->Append(_("211"));
    BW_Provided_BlockNr->Append(_("212"));
    BW_Provided_BlockNr->Append(_("213"));
    BW_Provided_BlockNr->Append(_("214"));
    BW_Provided_BlockNr->Append(_("215"));
    BW_Provided_BlockNr->Append(_("216"));
    BW_Provided_BlockNr->Append(_("217"));
    BW_Provided_BlockNr->Append(_("218"));
    BW_Provided_BlockNr->Append(_("219"));
    BW_Provided_BlockNr->Append(_("220"));
    BW_Provided_BlockNr->Append(_("221"));
    BW_Provided_BlockNr->Append(_("222"));
    BW_Provided_BlockNr->Append(_("223"));
    BW_Provided_BlockNr->Append(_("224"));
    BW_Provided_BlockNr->Append(_("225"));
    BW_Provided_BlockNr->Append(_("226"));
    BW_Provided_BlockNr->Append(_("227"));
    BW_Provided_BlockNr->Append(_("228"));
    BW_Provided_BlockNr->Append(_("229"));
    BW_Provided_BlockNr->Append(_("230"));
    BW_Provided_BlockNr->Append(_("231"));
    BW_Provided_BlockNr->Append(_("232"));
    BW_Provided_BlockNr->Append(_("233"));
    BW_Provided_BlockNr->Append(_("234"));
    BW_Provided_BlockNr->Append(_("235"));
    BW_Provided_BlockNr->Append(_("236"));
    BW_Provided_BlockNr->Append(_("237"));
    BW_Provided_BlockNr->Append(_("238"));
    BW_Provided_BlockNr->Append(_("239"));
    BW_Provided_BlockNr->Append(_("240"));
    BW_Provided_BlockNr->Append(_("241"));
    BW_Provided_BlockNr->Append(_("242"));
    BW_Provided_BlockNr->Append(_("243"));
    BW_Provided_BlockNr->Append(_("244"));
    BW_Provided_BlockNr->Append(_("245"));
    BW_Provided_BlockNr->Append(_("246"));
    BW_Provided_BlockNr->Append(_("247"));
    BW_Provided_BlockNr->Append(_("248"));
    BW_Provided_BlockNr->Append(_("249"));
    BW_Provided_BlockNr->Append(_("250"));
    BW_Provided_BlockNr->Append(_("251"));
    BW_Provided_BlockNr->Append(_("252"));
    BW_Provided_BlockNr->Append(_("253"));
    BW_Provided_BlockNr->Append(_("254"));
    BW_Provided_BlockNr->Append(_("255"));
    BoxSizer46->Add(BW_Provided_BlockNr, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    StaticBoxSizer56->Add(BoxSizer46, 1, wxALL|wxEXPAND, 3);
    BoxSizer47 = new wxBoxSizer(wxHORIZONTAL);
    StaticText80 = new wxStaticText(Panel17, ID_STATICTEXT81, _("Key:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT81"));
    BoxSizer47->Add(StaticText80, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    BW_Provided_Key = new wxTextCtrl(Panel17, ID_TEXTCTRL50, wxEmptyString, wxDefaultPosition, wxSize(203,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL50"));
    BW_Provided_Key->SetMaxLength(32);
    BoxSizer47->Add(BW_Provided_Key, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    StaticBoxSizer56->Add(BoxSizer47, 1, wxALL|wxEXPAND, 3);
    bBWProvidedKey = new wxButton(Panel17, ID_BUTTON28, _("Block write provided key"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON28"));
    StaticBoxSizer56->Add(bBWProvidedKey, 1, wxALL|wxALIGN_LEFT, 3);
    BoxSizer44->Add(StaticBoxSizer56, 1, wxALL|wxEXPAND, 3);
    StaticBoxSizer57 = new wxStaticBoxSizer(wxVERTICAL, Panel17, _("Reader key"));
    BoxSizer48 = new wxBoxSizer(wxHORIZONTAL);
    BW_Reader_KeyA = new wxRadioButton(Panel17, ID_RADIOBUTTON33, _("Key A"), wxDefaultPosition, wxDefaultSize, wxRB_GROUP, wxDefaultValidator, _T("ID_RADIOBUTTON33"));
    BW_Reader_KeyA->SetValue(true);
    BoxSizer48->Add(BW_Reader_KeyA, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    BW_Reader_KeyB = new wxRadioButton(Panel17, ID_RADIOBUTTON34, _("Key B"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON34"));
    BoxSizer48->Add(BW_Reader_KeyB, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    StaticText81 = new wxStaticText(Panel17, ID_STATICTEXT82, _("Block :"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT82"));
    BoxSizer48->Add(StaticText81, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    BW_Reader_BlockNr = new wxComboBox(Panel17, ID_COMBOBOX30, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, wxCB_READONLY, wxDefaultValidator, _T("ID_COMBOBOX30"));
    BW_Reader_BlockNr->SetSelection( BW_Reader_BlockNr->Append(_("0")) );
    BW_Reader_BlockNr->Append(_("1"));
    BW_Reader_BlockNr->Append(_("2"));
    BW_Reader_BlockNr->Append(_("3"));
    BW_Reader_BlockNr->Append(_("4"));
    BW_Reader_BlockNr->Append(_("5"));
    BW_Reader_BlockNr->Append(_("6"));
    BW_Reader_BlockNr->Append(_("7"));
    BW_Reader_BlockNr->Append(_("8"));
    BW_Reader_BlockNr->Append(_("9"));
    BW_Reader_BlockNr->Append(_("10"));
    BW_Reader_BlockNr->Append(_("11"));
    BW_Reader_BlockNr->Append(_("12"));
    BW_Reader_BlockNr->Append(_("13"));
    BW_Reader_BlockNr->Append(_("14"));
    BW_Reader_BlockNr->Append(_("15"));
    BW_Reader_BlockNr->Append(_("16"));
    BW_Reader_BlockNr->Append(_("17"));
    BW_Reader_BlockNr->Append(_("18"));
    BW_Reader_BlockNr->Append(_("19"));
    BW_Reader_BlockNr->Append(_("20"));
    BW_Reader_BlockNr->Append(_("21"));
    BW_Reader_BlockNr->Append(_("22"));
    BW_Reader_BlockNr->Append(_("23"));
    BW_Reader_BlockNr->Append(_("24"));
    BW_Reader_BlockNr->Append(_("25"));
    BW_Reader_BlockNr->Append(_("26"));
    BW_Reader_BlockNr->Append(_("27"));
    BW_Reader_BlockNr->Append(_("28"));
    BW_Reader_BlockNr->Append(_("29"));
    BW_Reader_BlockNr->Append(_("30"));
    BW_Reader_BlockNr->Append(_("31"));
    BW_Reader_BlockNr->Append(_("32"));
    BW_Reader_BlockNr->Append(_("33"));
    BW_Reader_BlockNr->Append(_("34"));
    BW_Reader_BlockNr->Append(_("35"));
    BW_Reader_BlockNr->Append(_("36"));
    BW_Reader_BlockNr->Append(_("37"));
    BW_Reader_BlockNr->Append(_("38"));
    BW_Reader_BlockNr->Append(_("39"));
    BW_Reader_BlockNr->Append(_("40"));
    BW_Reader_BlockNr->Append(_("41"));
    BW_Reader_BlockNr->Append(_("42"));
    BW_Reader_BlockNr->Append(_("43"));
    BW_Reader_BlockNr->Append(_("44"));
    BW_Reader_BlockNr->Append(_("45"));
    BW_Reader_BlockNr->Append(_("46"));
    BW_Reader_BlockNr->Append(_("47"));
    BW_Reader_BlockNr->Append(_("48"));
    BW_Reader_BlockNr->Append(_("49"));
    BW_Reader_BlockNr->Append(_("50"));
    BW_Reader_BlockNr->Append(_("51"));
    BW_Reader_BlockNr->Append(_("52"));
    BW_Reader_BlockNr->Append(_("53"));
    BW_Reader_BlockNr->Append(_("54"));
    BW_Reader_BlockNr->Append(_("55"));
    BW_Reader_BlockNr->Append(_("56"));
    BW_Reader_BlockNr->Append(_("57"));
    BW_Reader_BlockNr->Append(_("58"));
    BW_Reader_BlockNr->Append(_("59"));
    BW_Reader_BlockNr->Append(_("60"));
    BW_Reader_BlockNr->Append(_("61"));
    BW_Reader_BlockNr->Append(_("62"));
    BW_Reader_BlockNr->Append(_("63"));
    BW_Reader_BlockNr->Append(_("64"));
    BW_Reader_BlockNr->Append(_("65"));
    BW_Reader_BlockNr->Append(_("66"));
    BW_Reader_BlockNr->Append(_("67"));
    BW_Reader_BlockNr->Append(_("68"));
    BW_Reader_BlockNr->Append(_("69"));
    BW_Reader_BlockNr->Append(_("70"));
    BW_Reader_BlockNr->Append(_("71"));
    BW_Reader_BlockNr->Append(_("72"));
    BW_Reader_BlockNr->Append(_("73"));
    BW_Reader_BlockNr->Append(_("74"));
    BW_Reader_BlockNr->Append(_("75"));
    BW_Reader_BlockNr->Append(_("76"));
    BW_Reader_BlockNr->Append(_("77"));
    BW_Reader_BlockNr->Append(_("78"));
    BW_Reader_BlockNr->Append(_("79"));
    BW_Reader_BlockNr->Append(_("80"));
    BW_Reader_BlockNr->Append(_("81"));
    BW_Reader_BlockNr->Append(_("82"));
    BW_Reader_BlockNr->Append(_("83"));
    BW_Reader_BlockNr->Append(_("84"));
    BW_Reader_BlockNr->Append(_("85"));
    BW_Reader_BlockNr->Append(_("86"));
    BW_Reader_BlockNr->Append(_("87"));
    BW_Reader_BlockNr->Append(_("88"));
    BW_Reader_BlockNr->Append(_("89"));
    BW_Reader_BlockNr->Append(_("90"));
    BW_Reader_BlockNr->Append(_("91"));
    BW_Reader_BlockNr->Append(_("92"));
    BW_Reader_BlockNr->Append(_("93"));
    BW_Reader_BlockNr->Append(_("94"));
    BW_Reader_BlockNr->Append(_("95"));
    BW_Reader_BlockNr->Append(_("96"));
    BW_Reader_BlockNr->Append(_("97"));
    BW_Reader_BlockNr->Append(_("98"));
    BW_Reader_BlockNr->Append(_("99"));
    BW_Reader_BlockNr->Append(_("100"));
    BW_Reader_BlockNr->Append(_("101"));
    BW_Reader_BlockNr->Append(_("102"));
    BW_Reader_BlockNr->Append(_("103"));
    BW_Reader_BlockNr->Append(_("104"));
    BW_Reader_BlockNr->Append(_("105"));
    BW_Reader_BlockNr->Append(_("106"));
    BW_Reader_BlockNr->Append(_("107"));
    BW_Reader_BlockNr->Append(_("108"));
    BW_Reader_BlockNr->Append(_("109"));
    BW_Reader_BlockNr->Append(_("110"));
    BW_Reader_BlockNr->Append(_("111"));
    BW_Reader_BlockNr->Append(_("112"));
    BW_Reader_BlockNr->Append(_("113"));
    BW_Reader_BlockNr->Append(_("114"));
    BW_Reader_BlockNr->Append(_("115"));
    BW_Reader_BlockNr->Append(_("116"));
    BW_Reader_BlockNr->Append(_("117"));
    BW_Reader_BlockNr->Append(_("118"));
    BW_Reader_BlockNr->Append(_("119"));
    BW_Reader_BlockNr->Append(_("120"));
    BW_Reader_BlockNr->Append(_("121"));
    BW_Reader_BlockNr->Append(_("122"));
    BW_Reader_BlockNr->Append(_("123"));
    BW_Reader_BlockNr->Append(_("124"));
    BW_Reader_BlockNr->Append(_("125"));
    BW_Reader_BlockNr->Append(_("126"));
    BW_Reader_BlockNr->Append(_("127"));
    BW_Reader_BlockNr->Append(_("128"));
    BW_Reader_BlockNr->Append(_("129"));
    BW_Reader_BlockNr->Append(_("130"));
    BW_Reader_BlockNr->Append(_("131"));
    BW_Reader_BlockNr->Append(_("132"));
    BW_Reader_BlockNr->Append(_("133"));
    BW_Reader_BlockNr->Append(_("134"));
    BW_Reader_BlockNr->Append(_("135"));
    BW_Reader_BlockNr->Append(_("136"));
    BW_Reader_BlockNr->Append(_("137"));
    BW_Reader_BlockNr->Append(_("138"));
    BW_Reader_BlockNr->Append(_("139"));
    BW_Reader_BlockNr->Append(_("140"));
    BW_Reader_BlockNr->Append(_("141"));
    BW_Reader_BlockNr->Append(_("142"));
    BW_Reader_BlockNr->Append(_("143"));
    BW_Reader_BlockNr->Append(_("144"));
    BW_Reader_BlockNr->Append(_("145"));
    BW_Reader_BlockNr->Append(_("146"));
    BW_Reader_BlockNr->Append(_("147"));
    BW_Reader_BlockNr->Append(_("148"));
    BW_Reader_BlockNr->Append(_("149"));
    BW_Reader_BlockNr->Append(_("150"));
    BW_Reader_BlockNr->Append(_("151"));
    BW_Reader_BlockNr->Append(_("152"));
    BW_Reader_BlockNr->Append(_("153"));
    BW_Reader_BlockNr->Append(_("154"));
    BW_Reader_BlockNr->Append(_("155"));
    BW_Reader_BlockNr->Append(_("156"));
    BW_Reader_BlockNr->Append(_("157"));
    BW_Reader_BlockNr->Append(_("158"));
    BW_Reader_BlockNr->Append(_("159"));
    BW_Reader_BlockNr->Append(_("160"));
    BW_Reader_BlockNr->Append(_("161"));
    BW_Reader_BlockNr->Append(_("162"));
    BW_Reader_BlockNr->Append(_("163"));
    BW_Reader_BlockNr->Append(_("164"));
    BW_Reader_BlockNr->Append(_("165"));
    BW_Reader_BlockNr->Append(_("166"));
    BW_Reader_BlockNr->Append(_("167"));
    BW_Reader_BlockNr->Append(_("168"));
    BW_Reader_BlockNr->Append(_("169"));
    BW_Reader_BlockNr->Append(_("170"));
    BW_Reader_BlockNr->Append(_("171"));
    BW_Reader_BlockNr->Append(_("172"));
    BW_Reader_BlockNr->Append(_("173"));
    BW_Reader_BlockNr->Append(_("174"));
    BW_Reader_BlockNr->Append(_("175"));
    BW_Reader_BlockNr->Append(_("176"));
    BW_Reader_BlockNr->Append(_("177"));
    BW_Reader_BlockNr->Append(_("178"));
    BW_Reader_BlockNr->Append(_("179"));
    BW_Reader_BlockNr->Append(_("180"));
    BW_Reader_BlockNr->Append(_("181"));
    BW_Reader_BlockNr->Append(_("182"));
    BW_Reader_BlockNr->Append(_("183"));
    BW_Reader_BlockNr->Append(_("184"));
    BW_Reader_BlockNr->Append(_("185"));
    BW_Reader_BlockNr->Append(_("186"));
    BW_Reader_BlockNr->Append(_("187"));
    BW_Reader_BlockNr->Append(_("188"));
    BW_Reader_BlockNr->Append(_("189"));
    BW_Reader_BlockNr->Append(_("190"));
    BW_Reader_BlockNr->Append(_("191"));
    BW_Reader_BlockNr->Append(_("192"));
    BW_Reader_BlockNr->Append(_("193"));
    BW_Reader_BlockNr->Append(_("194"));
    BW_Reader_BlockNr->Append(_("195"));
    BW_Reader_BlockNr->Append(_("196"));
    BW_Reader_BlockNr->Append(_("197"));
    BW_Reader_BlockNr->Append(_("198"));
    BW_Reader_BlockNr->Append(_("199"));
    BW_Reader_BlockNr->Append(_("200"));
    BW_Reader_BlockNr->Append(_("201"));
    BW_Reader_BlockNr->Append(_("202"));
    BW_Reader_BlockNr->Append(_("203"));
    BW_Reader_BlockNr->Append(_("204"));
    BW_Reader_BlockNr->Append(_("205"));
    BW_Reader_BlockNr->Append(_("206"));
    BW_Reader_BlockNr->Append(_("207"));
    BW_Reader_BlockNr->Append(_("208"));
    BW_Reader_BlockNr->Append(_("209"));
    BW_Reader_BlockNr->Append(_("210"));
    BW_Reader_BlockNr->Append(_("211"));
    BW_Reader_BlockNr->Append(_("212"));
    BW_Reader_BlockNr->Append(_("213"));
    BW_Reader_BlockNr->Append(_("214"));
    BW_Reader_BlockNr->Append(_("215"));
    BW_Reader_BlockNr->Append(_("216"));
    BW_Reader_BlockNr->Append(_("217"));
    BW_Reader_BlockNr->Append(_("218"));
    BW_Reader_BlockNr->Append(_("219"));
    BW_Reader_BlockNr->Append(_("220"));
    BW_Reader_BlockNr->Append(_("221"));
    BW_Reader_BlockNr->Append(_("222"));
    BW_Reader_BlockNr->Append(_("223"));
    BW_Reader_BlockNr->Append(_("224"));
    BW_Reader_BlockNr->Append(_("225"));
    BW_Reader_BlockNr->Append(_("226"));
    BW_Reader_BlockNr->Append(_("227"));
    BW_Reader_BlockNr->Append(_("228"));
    BW_Reader_BlockNr->Append(_("229"));
    BW_Reader_BlockNr->Append(_("230"));
    BW_Reader_BlockNr->Append(_("231"));
    BW_Reader_BlockNr->Append(_("232"));
    BW_Reader_BlockNr->Append(_("233"));
    BW_Reader_BlockNr->Append(_("234"));
    BW_Reader_BlockNr->Append(_("235"));
    BW_Reader_BlockNr->Append(_("236"));
    BW_Reader_BlockNr->Append(_("237"));
    BW_Reader_BlockNr->Append(_("238"));
    BW_Reader_BlockNr->Append(_("239"));
    BW_Reader_BlockNr->Append(_("240"));
    BW_Reader_BlockNr->Append(_("241"));
    BW_Reader_BlockNr->Append(_("242"));
    BW_Reader_BlockNr->Append(_("243"));
    BW_Reader_BlockNr->Append(_("244"));
    BW_Reader_BlockNr->Append(_("245"));
    BW_Reader_BlockNr->Append(_("246"));
    BW_Reader_BlockNr->Append(_("247"));
    BW_Reader_BlockNr->Append(_("248"));
    BW_Reader_BlockNr->Append(_("249"));
    BW_Reader_BlockNr->Append(_("250"));
    BW_Reader_BlockNr->Append(_("251"));
    BW_Reader_BlockNr->Append(_("252"));
    BW_Reader_BlockNr->Append(_("253"));
    BW_Reader_BlockNr->Append(_("254"));
    BW_Reader_BlockNr->Append(_("255"));
    BoxSizer48->Add(BW_Reader_BlockNr, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    StaticBoxSizer57->Add(BoxSizer48, 0, wxALL|wxEXPAND, 3);
    BoxSizer49 = new wxBoxSizer(wxHORIZONTAL);
    StaticText82 = new wxStaticText(Panel17, ID_STATICTEXT83, _("Key index :"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT83"));
    BoxSizer49->Add(StaticText82, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    BW_Reader_KeyIndex = new wxComboBox(Panel17, ID_COMBOBOX31, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, wxCB_READONLY, wxDefaultValidator, _T("ID_COMBOBOX31"));
    BW_Reader_KeyIndex->SetSelection( BW_Reader_KeyIndex->Append(_("0")) );
    BW_Reader_KeyIndex->Append(_("1"));
    BW_Reader_KeyIndex->Append(_("2"));
    BW_Reader_KeyIndex->Append(_("3"));
    BW_Reader_KeyIndex->Append(_("4"));
    BW_Reader_KeyIndex->Append(_("5"));
    BW_Reader_KeyIndex->Append(_("6"));
    BW_Reader_KeyIndex->Append(_("7"));
    BW_Reader_KeyIndex->Append(_("8"));
    BW_Reader_KeyIndex->Append(_("9"));
    BW_Reader_KeyIndex->Append(_("10"));
    BW_Reader_KeyIndex->Append(_("11"));
    BW_Reader_KeyIndex->Append(_("12"));
    BW_Reader_KeyIndex->Append(_("13"));
    BW_Reader_KeyIndex->Append(_("14"));
    BW_Reader_KeyIndex->Append(_("15"));
    BW_Reader_KeyIndex->Append(_("16"));
    BW_Reader_KeyIndex->Append(_("17"));
    BW_Reader_KeyIndex->Append(_("18"));
    BW_Reader_KeyIndex->Append(_("19"));
    BW_Reader_KeyIndex->Append(_("20"));
    BW_Reader_KeyIndex->Append(_("21"));
    BW_Reader_KeyIndex->Append(_("22"));
    BW_Reader_KeyIndex->Append(_("23"));
    BW_Reader_KeyIndex->Append(_("24"));
    BW_Reader_KeyIndex->Append(_("25"));
    BW_Reader_KeyIndex->Append(_("26"));
    BW_Reader_KeyIndex->Append(_("27"));
    BW_Reader_KeyIndex->Append(_("28"));
    BW_Reader_KeyIndex->Append(_("29"));
    BW_Reader_KeyIndex->Append(_("30"));
    BW_Reader_KeyIndex->Append(_("31"));
    BoxSizer49->Add(BW_Reader_KeyIndex, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    StaticText110 = new wxStaticText(Panel17, ID_STATICTEXT111, _("(0 - 31 for CRYPTO 1) and (0 - 15 for AES key)"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT111"));
    BoxSizer49->Add(StaticText110, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    StaticBoxSizer57->Add(BoxSizer49, 0, wxALL|wxEXPAND, 3);
    bBWReaderKey = new wxButton(Panel17, ID_BUTTON29, _("Block write reader key"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON29"));
    StaticBoxSizer57->Add(bBWReaderKey, 1, wxALL|wxALIGN_LEFT, 3);
    BoxSizer44->Add(StaticBoxSizer57, 1, wxALL|wxEXPAND, 3);
    StaticBoxSizer55->Add(BoxSizer44, 0, wxALL|wxEXPAND, 3);
    BoxSizer45 = new wxBoxSizer(wxHORIZONTAL);
    StaticBoxSizer58 = new wxStaticBoxSizer(wxVERTICAL, Panel17, _("AKM1 key"));
    BoxSizer50 = new wxBoxSizer(wxHORIZONTAL);
    BW_AKM1_KeyA = new wxRadioButton(Panel17, ID_RADIOBUTTON35, _("Key A"), wxDefaultPosition, wxDefaultSize, wxRB_GROUP, wxDefaultValidator, _T("ID_RADIOBUTTON35"));
    BW_AKM1_KeyA->SetValue(true);
    BoxSizer50->Add(BW_AKM1_KeyA, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    BW_AKM1_KeyB = new wxRadioButton(Panel17, ID_RADIOBUTTON36, _("Key B"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON36"));
    BoxSizer50->Add(BW_AKM1_KeyB, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    StaticText83 = new wxStaticText(Panel17, ID_STATICTEXT84, _("Block :"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT84"));
    BoxSizer50->Add(StaticText83, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    BW_AKM1_BlockNr = new wxComboBox(Panel17, ID_COMBOBOX32, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, wxCB_READONLY, wxDefaultValidator, _T("ID_COMBOBOX32"));
    BW_AKM1_BlockNr->SetSelection( BW_AKM1_BlockNr->Append(_("0")) );
    BW_AKM1_BlockNr->Append(_("1"));
    BW_AKM1_BlockNr->Append(_("2"));
    BW_AKM1_BlockNr->Append(_("3"));
    BW_AKM1_BlockNr->Append(_("4"));
    BW_AKM1_BlockNr->Append(_("5"));
    BW_AKM1_BlockNr->Append(_("6"));
    BW_AKM1_BlockNr->Append(_("7"));
    BW_AKM1_BlockNr->Append(_("8"));
    BW_AKM1_BlockNr->Append(_("9"));
    BW_AKM1_BlockNr->Append(_("10"));
    BW_AKM1_BlockNr->Append(_("11"));
    BW_AKM1_BlockNr->Append(_("12"));
    BW_AKM1_BlockNr->Append(_("13"));
    BW_AKM1_BlockNr->Append(_("14"));
    BW_AKM1_BlockNr->Append(_("15"));
    BW_AKM1_BlockNr->Append(_("16"));
    BW_AKM1_BlockNr->Append(_("17"));
    BW_AKM1_BlockNr->Append(_("18"));
    BW_AKM1_BlockNr->Append(_("19"));
    BW_AKM1_BlockNr->Append(_("20"));
    BW_AKM1_BlockNr->Append(_("21"));
    BW_AKM1_BlockNr->Append(_("22"));
    BW_AKM1_BlockNr->Append(_("23"));
    BW_AKM1_BlockNr->Append(_("24"));
    BW_AKM1_BlockNr->Append(_("25"));
    BW_AKM1_BlockNr->Append(_("26"));
    BW_AKM1_BlockNr->Append(_("27"));
    BW_AKM1_BlockNr->Append(_("28"));
    BW_AKM1_BlockNr->Append(_("29"));
    BW_AKM1_BlockNr->Append(_("30"));
    BW_AKM1_BlockNr->Append(_("31"));
    BW_AKM1_BlockNr->Append(_("32"));
    BW_AKM1_BlockNr->Append(_("33"));
    BW_AKM1_BlockNr->Append(_("34"));
    BW_AKM1_BlockNr->Append(_("35"));
    BW_AKM1_BlockNr->Append(_("36"));
    BW_AKM1_BlockNr->Append(_("37"));
    BW_AKM1_BlockNr->Append(_("38"));
    BW_AKM1_BlockNr->Append(_("39"));
    BW_AKM1_BlockNr->Append(_("40"));
    BW_AKM1_BlockNr->Append(_("41"));
    BW_AKM1_BlockNr->Append(_("42"));
    BW_AKM1_BlockNr->Append(_("43"));
    BW_AKM1_BlockNr->Append(_("44"));
    BW_AKM1_BlockNr->Append(_("45"));
    BW_AKM1_BlockNr->Append(_("46"));
    BW_AKM1_BlockNr->Append(_("47"));
    BW_AKM1_BlockNr->Append(_("48"));
    BW_AKM1_BlockNr->Append(_("49"));
    BW_AKM1_BlockNr->Append(_("50"));
    BW_AKM1_BlockNr->Append(_("51"));
    BW_AKM1_BlockNr->Append(_("52"));
    BW_AKM1_BlockNr->Append(_("53"));
    BW_AKM1_BlockNr->Append(_("54"));
    BW_AKM1_BlockNr->Append(_("55"));
    BW_AKM1_BlockNr->Append(_("56"));
    BW_AKM1_BlockNr->Append(_("57"));
    BW_AKM1_BlockNr->Append(_("58"));
    BW_AKM1_BlockNr->Append(_("59"));
    BW_AKM1_BlockNr->Append(_("60"));
    BW_AKM1_BlockNr->Append(_("61"));
    BW_AKM1_BlockNr->Append(_("62"));
    BW_AKM1_BlockNr->Append(_("63"));
    BW_AKM1_BlockNr->Append(_("64"));
    BW_AKM1_BlockNr->Append(_("65"));
    BW_AKM1_BlockNr->Append(_("66"));
    BW_AKM1_BlockNr->Append(_("67"));
    BW_AKM1_BlockNr->Append(_("68"));
    BW_AKM1_BlockNr->Append(_("69"));
    BW_AKM1_BlockNr->Append(_("70"));
    BW_AKM1_BlockNr->Append(_("71"));
    BW_AKM1_BlockNr->Append(_("72"));
    BW_AKM1_BlockNr->Append(_("73"));
    BW_AKM1_BlockNr->Append(_("74"));
    BW_AKM1_BlockNr->Append(_("75"));
    BW_AKM1_BlockNr->Append(_("76"));
    BW_AKM1_BlockNr->Append(_("77"));
    BW_AKM1_BlockNr->Append(_("78"));
    BW_AKM1_BlockNr->Append(_("79"));
    BW_AKM1_BlockNr->Append(_("80"));
    BW_AKM1_BlockNr->Append(_("81"));
    BW_AKM1_BlockNr->Append(_("82"));
    BW_AKM1_BlockNr->Append(_("83"));
    BW_AKM1_BlockNr->Append(_("84"));
    BW_AKM1_BlockNr->Append(_("85"));
    BW_AKM1_BlockNr->Append(_("86"));
    BW_AKM1_BlockNr->Append(_("87"));
    BW_AKM1_BlockNr->Append(_("88"));
    BW_AKM1_BlockNr->Append(_("89"));
    BW_AKM1_BlockNr->Append(_("90"));
    BW_AKM1_BlockNr->Append(_("91"));
    BW_AKM1_BlockNr->Append(_("92"));
    BW_AKM1_BlockNr->Append(_("93"));
    BW_AKM1_BlockNr->Append(_("94"));
    BW_AKM1_BlockNr->Append(_("95"));
    BW_AKM1_BlockNr->Append(_("96"));
    BW_AKM1_BlockNr->Append(_("97"));
    BW_AKM1_BlockNr->Append(_("98"));
    BW_AKM1_BlockNr->Append(_("99"));
    BW_AKM1_BlockNr->Append(_("100"));
    BW_AKM1_BlockNr->Append(_("101"));
    BW_AKM1_BlockNr->Append(_("102"));
    BW_AKM1_BlockNr->Append(_("103"));
    BW_AKM1_BlockNr->Append(_("104"));
    BW_AKM1_BlockNr->Append(_("105"));
    BW_AKM1_BlockNr->Append(_("106"));
    BW_AKM1_BlockNr->Append(_("107"));
    BW_AKM1_BlockNr->Append(_("108"));
    BW_AKM1_BlockNr->Append(_("109"));
    BW_AKM1_BlockNr->Append(_("110"));
    BW_AKM1_BlockNr->Append(_("111"));
    BW_AKM1_BlockNr->Append(_("112"));
    BW_AKM1_BlockNr->Append(_("113"));
    BW_AKM1_BlockNr->Append(_("114"));
    BW_AKM1_BlockNr->Append(_("115"));
    BW_AKM1_BlockNr->Append(_("116"));
    BW_AKM1_BlockNr->Append(_("117"));
    BW_AKM1_BlockNr->Append(_("118"));
    BW_AKM1_BlockNr->Append(_("119"));
    BW_AKM1_BlockNr->Append(_("120"));
    BW_AKM1_BlockNr->Append(_("121"));
    BW_AKM1_BlockNr->Append(_("122"));
    BW_AKM1_BlockNr->Append(_("123"));
    BW_AKM1_BlockNr->Append(_("124"));
    BW_AKM1_BlockNr->Append(_("125"));
    BW_AKM1_BlockNr->Append(_("126"));
    BW_AKM1_BlockNr->Append(_("127"));
    BW_AKM1_BlockNr->Append(_("128"));
    BW_AKM1_BlockNr->Append(_("129"));
    BW_AKM1_BlockNr->Append(_("130"));
    BW_AKM1_BlockNr->Append(_("131"));
    BW_AKM1_BlockNr->Append(_("132"));
    BW_AKM1_BlockNr->Append(_("133"));
    BW_AKM1_BlockNr->Append(_("134"));
    BW_AKM1_BlockNr->Append(_("135"));
    BW_AKM1_BlockNr->Append(_("136"));
    BW_AKM1_BlockNr->Append(_("137"));
    BW_AKM1_BlockNr->Append(_("138"));
    BW_AKM1_BlockNr->Append(_("139"));
    BW_AKM1_BlockNr->Append(_("140"));
    BW_AKM1_BlockNr->Append(_("141"));
    BW_AKM1_BlockNr->Append(_("142"));
    BW_AKM1_BlockNr->Append(_("143"));
    BW_AKM1_BlockNr->Append(_("144"));
    BW_AKM1_BlockNr->Append(_("145"));
    BW_AKM1_BlockNr->Append(_("146"));
    BW_AKM1_BlockNr->Append(_("147"));
    BW_AKM1_BlockNr->Append(_("148"));
    BW_AKM1_BlockNr->Append(_("149"));
    BW_AKM1_BlockNr->Append(_("150"));
    BW_AKM1_BlockNr->Append(_("151"));
    BW_AKM1_BlockNr->Append(_("152"));
    BW_AKM1_BlockNr->Append(_("153"));
    BW_AKM1_BlockNr->Append(_("154"));
    BW_AKM1_BlockNr->Append(_("155"));
    BW_AKM1_BlockNr->Append(_("156"));
    BW_AKM1_BlockNr->Append(_("157"));
    BW_AKM1_BlockNr->Append(_("158"));
    BW_AKM1_BlockNr->Append(_("159"));
    BW_AKM1_BlockNr->Append(_("160"));
    BW_AKM1_BlockNr->Append(_("161"));
    BW_AKM1_BlockNr->Append(_("162"));
    BW_AKM1_BlockNr->Append(_("163"));
    BW_AKM1_BlockNr->Append(_("164"));
    BW_AKM1_BlockNr->Append(_("165"));
    BW_AKM1_BlockNr->Append(_("166"));
    BW_AKM1_BlockNr->Append(_("167"));
    BW_AKM1_BlockNr->Append(_("168"));
    BW_AKM1_BlockNr->Append(_("169"));
    BW_AKM1_BlockNr->Append(_("170"));
    BW_AKM1_BlockNr->Append(_("171"));
    BW_AKM1_BlockNr->Append(_("172"));
    BW_AKM1_BlockNr->Append(_("173"));
    BW_AKM1_BlockNr->Append(_("174"));
    BW_AKM1_BlockNr->Append(_("175"));
    BW_AKM1_BlockNr->Append(_("176"));
    BW_AKM1_BlockNr->Append(_("177"));
    BW_AKM1_BlockNr->Append(_("178"));
    BW_AKM1_BlockNr->Append(_("179"));
    BW_AKM1_BlockNr->Append(_("180"));
    BW_AKM1_BlockNr->Append(_("181"));
    BW_AKM1_BlockNr->Append(_("182"));
    BW_AKM1_BlockNr->Append(_("183"));
    BW_AKM1_BlockNr->Append(_("184"));
    BW_AKM1_BlockNr->Append(_("185"));
    BW_AKM1_BlockNr->Append(_("186"));
    BW_AKM1_BlockNr->Append(_("187"));
    BW_AKM1_BlockNr->Append(_("188"));
    BW_AKM1_BlockNr->Append(_("189"));
    BW_AKM1_BlockNr->Append(_("190"));
    BW_AKM1_BlockNr->Append(_("191"));
    BW_AKM1_BlockNr->Append(_("192"));
    BW_AKM1_BlockNr->Append(_("193"));
    BW_AKM1_BlockNr->Append(_("194"));
    BW_AKM1_BlockNr->Append(_("195"));
    BW_AKM1_BlockNr->Append(_("196"));
    BW_AKM1_BlockNr->Append(_("197"));
    BW_AKM1_BlockNr->Append(_("198"));
    BW_AKM1_BlockNr->Append(_("199"));
    BW_AKM1_BlockNr->Append(_("200"));
    BW_AKM1_BlockNr->Append(_("201"));
    BW_AKM1_BlockNr->Append(_("202"));
    BW_AKM1_BlockNr->Append(_("203"));
    BW_AKM1_BlockNr->Append(_("204"));
    BW_AKM1_BlockNr->Append(_("205"));
    BW_AKM1_BlockNr->Append(_("206"));
    BW_AKM1_BlockNr->Append(_("207"));
    BW_AKM1_BlockNr->Append(_("208"));
    BW_AKM1_BlockNr->Append(_("209"));
    BW_AKM1_BlockNr->Append(_("210"));
    BW_AKM1_BlockNr->Append(_("211"));
    BW_AKM1_BlockNr->Append(_("212"));
    BW_AKM1_BlockNr->Append(_("213"));
    BW_AKM1_BlockNr->Append(_("214"));
    BW_AKM1_BlockNr->Append(_("215"));
    BW_AKM1_BlockNr->Append(_("216"));
    BW_AKM1_BlockNr->Append(_("217"));
    BW_AKM1_BlockNr->Append(_("218"));
    BW_AKM1_BlockNr->Append(_("219"));
    BW_AKM1_BlockNr->Append(_("220"));
    BW_AKM1_BlockNr->Append(_("221"));
    BW_AKM1_BlockNr->Append(_("222"));
    BW_AKM1_BlockNr->Append(_("223"));
    BW_AKM1_BlockNr->Append(_("224"));
    BW_AKM1_BlockNr->Append(_("225"));
    BW_AKM1_BlockNr->Append(_("226"));
    BW_AKM1_BlockNr->Append(_("227"));
    BW_AKM1_BlockNr->Append(_("228"));
    BW_AKM1_BlockNr->Append(_("229"));
    BW_AKM1_BlockNr->Append(_("230"));
    BW_AKM1_BlockNr->Append(_("231"));
    BW_AKM1_BlockNr->Append(_("232"));
    BW_AKM1_BlockNr->Append(_("233"));
    BW_AKM1_BlockNr->Append(_("234"));
    BW_AKM1_BlockNr->Append(_("235"));
    BW_AKM1_BlockNr->Append(_("236"));
    BW_AKM1_BlockNr->Append(_("237"));
    BW_AKM1_BlockNr->Append(_("238"));
    BW_AKM1_BlockNr->Append(_("239"));
    BW_AKM1_BlockNr->Append(_("240"));
    BW_AKM1_BlockNr->Append(_("241"));
    BW_AKM1_BlockNr->Append(_("242"));
    BW_AKM1_BlockNr->Append(_("243"));
    BW_AKM1_BlockNr->Append(_("244"));
    BW_AKM1_BlockNr->Append(_("245"));
    BW_AKM1_BlockNr->Append(_("246"));
    BW_AKM1_BlockNr->Append(_("247"));
    BW_AKM1_BlockNr->Append(_("248"));
    BW_AKM1_BlockNr->Append(_("249"));
    BW_AKM1_BlockNr->Append(_("250"));
    BW_AKM1_BlockNr->Append(_("251"));
    BW_AKM1_BlockNr->Append(_("252"));
    BW_AKM1_BlockNr->Append(_("253"));
    BW_AKM1_BlockNr->Append(_("254"));
    BW_AKM1_BlockNr->Append(_("255"));
    BoxSizer50->Add(BW_AKM1_BlockNr, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    StaticBoxSizer58->Add(BoxSizer50, 1, wxALL|wxEXPAND, 3);
    bBWAKM1Key = new wxButton(Panel17, ID_BUTTON30, _("Block write AKM1 key"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON30"));
    StaticBoxSizer58->Add(bBWAKM1Key, 0, wxALL|wxALIGN_LEFT, 3);
    BoxSizer45->Add(StaticBoxSizer58, 1, wxALL|wxEXPAND, 3);
    StaticBoxSizer59 = new wxStaticBoxSizer(wxVERTICAL, Panel17, _("AKM2 key"));
    BoxSizer51 = new wxBoxSizer(wxHORIZONTAL);
    BW_AKM2_KeyA = new wxRadioButton(Panel17, ID_RADIOBUTTON37, _("Key A"), wxDefaultPosition, wxDefaultSize, wxRB_GROUP, wxDefaultValidator, _T("ID_RADIOBUTTON37"));
    BW_AKM2_KeyA->SetValue(true);
    BoxSizer51->Add(BW_AKM2_KeyA, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    BW_AKM2_KeyB = new wxRadioButton(Panel17, ID_RADIOBUTTON38, _("Key B"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON38"));
    BoxSizer51->Add(BW_AKM2_KeyB, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    StaticText84 = new wxStaticText(Panel17, ID_STATICTEXT85, _("Block :"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT85"));
    BoxSizer51->Add(StaticText84, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    BW_AKM2_BlockNr = new wxChoice(Panel17, ID_CHOICE1, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE1"));
    BW_AKM2_BlockNr->SetSelection( BW_AKM2_BlockNr->Append(_("0")) );
    BW_AKM2_BlockNr->Append(_("1"));
    BW_AKM2_BlockNr->Append(_("2"));
    BW_AKM2_BlockNr->Append(_("3"));
    BW_AKM2_BlockNr->Append(_("4"));
    BW_AKM2_BlockNr->Append(_("5"));
    BW_AKM2_BlockNr->Append(_("6"));
    BW_AKM2_BlockNr->Append(_("7"));
    BW_AKM2_BlockNr->Append(_("8"));
    BW_AKM2_BlockNr->Append(_("9"));
    BW_AKM2_BlockNr->Append(_("10"));
    BW_AKM2_BlockNr->Append(_("11"));
    BW_AKM2_BlockNr->Append(_("12"));
    BW_AKM2_BlockNr->Append(_("13"));
    BW_AKM2_BlockNr->Append(_("14"));
    BW_AKM2_BlockNr->Append(_("15"));
    BW_AKM2_BlockNr->Append(_("16"));
    BW_AKM2_BlockNr->Append(_("17"));
    BW_AKM2_BlockNr->Append(_("18"));
    BW_AKM2_BlockNr->Append(_("19"));
    BW_AKM2_BlockNr->Append(_("20"));
    BW_AKM2_BlockNr->Append(_("21"));
    BW_AKM2_BlockNr->Append(_("22"));
    BW_AKM2_BlockNr->Append(_("23"));
    BW_AKM2_BlockNr->Append(_("24"));
    BW_AKM2_BlockNr->Append(_("25"));
    BW_AKM2_BlockNr->Append(_("26"));
    BW_AKM2_BlockNr->Append(_("27"));
    BW_AKM2_BlockNr->Append(_("28"));
    BW_AKM2_BlockNr->Append(_("29"));
    BW_AKM2_BlockNr->Append(_("30"));
    BW_AKM2_BlockNr->Append(_("31"));
    BW_AKM2_BlockNr->Append(_("32"));
    BW_AKM2_BlockNr->Append(_("33"));
    BW_AKM2_BlockNr->Append(_("34"));
    BW_AKM2_BlockNr->Append(_("35"));
    BW_AKM2_BlockNr->Append(_("36"));
    BW_AKM2_BlockNr->Append(_("37"));
    BW_AKM2_BlockNr->Append(_("38"));
    BW_AKM2_BlockNr->Append(_("39"));
    BW_AKM2_BlockNr->Append(_("40"));
    BW_AKM2_BlockNr->Append(_("41"));
    BW_AKM2_BlockNr->Append(_("42"));
    BW_AKM2_BlockNr->Append(_("43"));
    BW_AKM2_BlockNr->Append(_("44"));
    BW_AKM2_BlockNr->Append(_("45"));
    BW_AKM2_BlockNr->Append(_("46"));
    BW_AKM2_BlockNr->Append(_("47"));
    BW_AKM2_BlockNr->Append(_("48"));
    BW_AKM2_BlockNr->Append(_("49"));
    BW_AKM2_BlockNr->Append(_("50"));
    BW_AKM2_BlockNr->Append(_("51"));
    BW_AKM2_BlockNr->Append(_("52"));
    BW_AKM2_BlockNr->Append(_("53"));
    BW_AKM2_BlockNr->Append(_("54"));
    BW_AKM2_BlockNr->Append(_("55"));
    BW_AKM2_BlockNr->Append(_("56"));
    BW_AKM2_BlockNr->Append(_("57"));
    BW_AKM2_BlockNr->Append(_("58"));
    BW_AKM2_BlockNr->Append(_("59"));
    BW_AKM2_BlockNr->Append(_("60"));
    BW_AKM2_BlockNr->Append(_("61"));
    BW_AKM2_BlockNr->Append(_("62"));
    BW_AKM2_BlockNr->Append(_("63"));
    BW_AKM2_BlockNr->Append(_("64"));
    BW_AKM2_BlockNr->Append(_("65"));
    BW_AKM2_BlockNr->Append(_("66"));
    BW_AKM2_BlockNr->Append(_("67"));
    BW_AKM2_BlockNr->Append(_("68"));
    BW_AKM2_BlockNr->Append(_("69"));
    BW_AKM2_BlockNr->Append(_("70"));
    BW_AKM2_BlockNr->Append(_("71"));
    BW_AKM2_BlockNr->Append(_("72"));
    BW_AKM2_BlockNr->Append(_("73"));
    BW_AKM2_BlockNr->Append(_("74"));
    BW_AKM2_BlockNr->Append(_("75"));
    BW_AKM2_BlockNr->Append(_("76"));
    BW_AKM2_BlockNr->Append(_("77"));
    BW_AKM2_BlockNr->Append(_("78"));
    BW_AKM2_BlockNr->Append(_("79"));
    BW_AKM2_BlockNr->Append(_("80"));
    BW_AKM2_BlockNr->Append(_("81"));
    BW_AKM2_BlockNr->Append(_("82"));
    BW_AKM2_BlockNr->Append(_("83"));
    BW_AKM2_BlockNr->Append(_("84"));
    BW_AKM2_BlockNr->Append(_("85"));
    BW_AKM2_BlockNr->Append(_("86"));
    BW_AKM2_BlockNr->Append(_("87"));
    BW_AKM2_BlockNr->Append(_("88"));
    BW_AKM2_BlockNr->Append(_("89"));
    BW_AKM2_BlockNr->Append(_("90"));
    BW_AKM2_BlockNr->Append(_("91"));
    BW_AKM2_BlockNr->Append(_("92"));
    BW_AKM2_BlockNr->Append(_("93"));
    BW_AKM2_BlockNr->Append(_("94"));
    BW_AKM2_BlockNr->Append(_("95"));
    BW_AKM2_BlockNr->Append(_("96"));
    BW_AKM2_BlockNr->Append(_("97"));
    BW_AKM2_BlockNr->Append(_("98"));
    BW_AKM2_BlockNr->Append(_("99"));
    BW_AKM2_BlockNr->Append(_("100"));
    BW_AKM2_BlockNr->Append(_("101"));
    BW_AKM2_BlockNr->Append(_("102"));
    BW_AKM2_BlockNr->Append(_("103"));
    BW_AKM2_BlockNr->Append(_("104"));
    BW_AKM2_BlockNr->Append(_("105"));
    BW_AKM2_BlockNr->Append(_("106"));
    BW_AKM2_BlockNr->Append(_("107"));
    BW_AKM2_BlockNr->Append(_("108"));
    BW_AKM2_BlockNr->Append(_("109"));
    BW_AKM2_BlockNr->Append(_("110"));
    BW_AKM2_BlockNr->Append(_("111"));
    BW_AKM2_BlockNr->Append(_("112"));
    BW_AKM2_BlockNr->Append(_("113"));
    BW_AKM2_BlockNr->Append(_("114"));
    BW_AKM2_BlockNr->Append(_("115"));
    BW_AKM2_BlockNr->Append(_("116"));
    BW_AKM2_BlockNr->Append(_("117"));
    BW_AKM2_BlockNr->Append(_("118"));
    BW_AKM2_BlockNr->Append(_("119"));
    BW_AKM2_BlockNr->Append(_("120"));
    BW_AKM2_BlockNr->Append(_("121"));
    BW_AKM2_BlockNr->Append(_("122"));
    BW_AKM2_BlockNr->Append(_("123"));
    BW_AKM2_BlockNr->Append(_("124"));
    BW_AKM2_BlockNr->Append(_("125"));
    BW_AKM2_BlockNr->Append(_("126"));
    BW_AKM2_BlockNr->Append(_("127"));
    BW_AKM2_BlockNr->Append(_("128"));
    BW_AKM2_BlockNr->Append(_("129"));
    BW_AKM2_BlockNr->Append(_("130"));
    BW_AKM2_BlockNr->Append(_("131"));
    BW_AKM2_BlockNr->Append(_("132"));
    BW_AKM2_BlockNr->Append(_("133"));
    BW_AKM2_BlockNr->Append(_("134"));
    BW_AKM2_BlockNr->Append(_("135"));
    BW_AKM2_BlockNr->Append(_("136"));
    BW_AKM2_BlockNr->Append(_("137"));
    BW_AKM2_BlockNr->Append(_("138"));
    BW_AKM2_BlockNr->Append(_("139"));
    BW_AKM2_BlockNr->Append(_("140"));
    BW_AKM2_BlockNr->Append(_("141"));
    BW_AKM2_BlockNr->Append(_("142"));
    BW_AKM2_BlockNr->Append(_("143"));
    BW_AKM2_BlockNr->Append(_("144"));
    BW_AKM2_BlockNr->Append(_("145"));
    BW_AKM2_BlockNr->Append(_("146"));
    BW_AKM2_BlockNr->Append(_("147"));
    BW_AKM2_BlockNr->Append(_("148"));
    BW_AKM2_BlockNr->Append(_("149"));
    BW_AKM2_BlockNr->Append(_("150"));
    BW_AKM2_BlockNr->Append(_("151"));
    BW_AKM2_BlockNr->Append(_("152"));
    BW_AKM2_BlockNr->Append(_("153"));
    BW_AKM2_BlockNr->Append(_("154"));
    BW_AKM2_BlockNr->Append(_("155"));
    BW_AKM2_BlockNr->Append(_("156"));
    BW_AKM2_BlockNr->Append(_("157"));
    BW_AKM2_BlockNr->Append(_("158"));
    BW_AKM2_BlockNr->Append(_("159"));
    BW_AKM2_BlockNr->Append(_("160"));
    BW_AKM2_BlockNr->Append(_("161"));
    BW_AKM2_BlockNr->Append(_("162"));
    BW_AKM2_BlockNr->Append(_("163"));
    BW_AKM2_BlockNr->Append(_("164"));
    BW_AKM2_BlockNr->Append(_("165"));
    BW_AKM2_BlockNr->Append(_("166"));
    BW_AKM2_BlockNr->Append(_("167"));
    BW_AKM2_BlockNr->Append(_("168"));
    BW_AKM2_BlockNr->Append(_("169"));
    BW_AKM2_BlockNr->Append(_("170"));
    BW_AKM2_BlockNr->Append(_("171"));
    BW_AKM2_BlockNr->Append(_("172"));
    BW_AKM2_BlockNr->Append(_("173"));
    BW_AKM2_BlockNr->Append(_("174"));
    BW_AKM2_BlockNr->Append(_("175"));
    BW_AKM2_BlockNr->Append(_("176"));
    BW_AKM2_BlockNr->Append(_("177"));
    BW_AKM2_BlockNr->Append(_("178"));
    BW_AKM2_BlockNr->Append(_("179"));
    BW_AKM2_BlockNr->Append(_("180"));
    BW_AKM2_BlockNr->Append(_("181"));
    BW_AKM2_BlockNr->Append(_("182"));
    BW_AKM2_BlockNr->Append(_("183"));
    BW_AKM2_BlockNr->Append(_("184"));
    BW_AKM2_BlockNr->Append(_("185"));
    BW_AKM2_BlockNr->Append(_("186"));
    BW_AKM2_BlockNr->Append(_("187"));
    BW_AKM2_BlockNr->Append(_("188"));
    BW_AKM2_BlockNr->Append(_("189"));
    BW_AKM2_BlockNr->Append(_("190"));
    BW_AKM2_BlockNr->Append(_("191"));
    BW_AKM2_BlockNr->Append(_("192"));
    BW_AKM2_BlockNr->Append(_("193"));
    BW_AKM2_BlockNr->Append(_("194"));
    BW_AKM2_BlockNr->Append(_("195"));
    BW_AKM2_BlockNr->Append(_("196"));
    BW_AKM2_BlockNr->Append(_("197"));
    BW_AKM2_BlockNr->Append(_("198"));
    BW_AKM2_BlockNr->Append(_("199"));
    BW_AKM2_BlockNr->Append(_("200"));
    BW_AKM2_BlockNr->Append(_("201"));
    BW_AKM2_BlockNr->Append(_("202"));
    BW_AKM2_BlockNr->Append(_("203"));
    BW_AKM2_BlockNr->Append(_("204"));
    BW_AKM2_BlockNr->Append(_("205"));
    BW_AKM2_BlockNr->Append(_("206"));
    BW_AKM2_BlockNr->Append(_("207"));
    BW_AKM2_BlockNr->Append(_("208"));
    BW_AKM2_BlockNr->Append(_("209"));
    BW_AKM2_BlockNr->Append(_("210"));
    BW_AKM2_BlockNr->Append(_("211"));
    BW_AKM2_BlockNr->Append(_("212"));
    BW_AKM2_BlockNr->Append(_("213"));
    BW_AKM2_BlockNr->Append(_("214"));
    BW_AKM2_BlockNr->Append(_("215"));
    BW_AKM2_BlockNr->Append(_("216"));
    BW_AKM2_BlockNr->Append(_("217"));
    BW_AKM2_BlockNr->Append(_("218"));
    BW_AKM2_BlockNr->Append(_("219"));
    BW_AKM2_BlockNr->Append(_("220"));
    BW_AKM2_BlockNr->Append(_("221"));
    BW_AKM2_BlockNr->Append(_("222"));
    BW_AKM2_BlockNr->Append(_("223"));
    BW_AKM2_BlockNr->Append(_("224"));
    BW_AKM2_BlockNr->Append(_("225"));
    BW_AKM2_BlockNr->Append(_("226"));
    BW_AKM2_BlockNr->Append(_("227"));
    BW_AKM2_BlockNr->Append(_("228"));
    BW_AKM2_BlockNr->Append(_("229"));
    BW_AKM2_BlockNr->Append(_("230"));
    BW_AKM2_BlockNr->Append(_("231"));
    BW_AKM2_BlockNr->Append(_("232"));
    BW_AKM2_BlockNr->Append(_("233"));
    BW_AKM2_BlockNr->Append(_("234"));
    BW_AKM2_BlockNr->Append(_("235"));
    BW_AKM2_BlockNr->Append(_("236"));
    BW_AKM2_BlockNr->Append(_("237"));
    BW_AKM2_BlockNr->Append(_("238"));
    BW_AKM2_BlockNr->Append(_("239"));
    BW_AKM2_BlockNr->Append(_("240"));
    BW_AKM2_BlockNr->Append(_("241"));
    BW_AKM2_BlockNr->Append(_("242"));
    BW_AKM2_BlockNr->Append(_("243"));
    BW_AKM2_BlockNr->Append(_("244"));
    BW_AKM2_BlockNr->Append(_("245"));
    BW_AKM2_BlockNr->Append(_("246"));
    BW_AKM2_BlockNr->Append(_("247"));
    BW_AKM2_BlockNr->Append(_("248"));
    BW_AKM2_BlockNr->Append(_("249"));
    BW_AKM2_BlockNr->Append(_("250"));
    BW_AKM2_BlockNr->Append(_("251"));
    BW_AKM2_BlockNr->Append(_("252"));
    BW_AKM2_BlockNr->Append(_("253"));
    BW_AKM2_BlockNr->Append(_("254"));
    BW_AKM2_BlockNr->Append(_("255"));
    BoxSizer51->Add(BW_AKM2_BlockNr, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    StaticBoxSizer59->Add(BoxSizer51, 0, wxALL|wxEXPAND, 3);
    bBWAKM2Key = new wxButton(Panel17, ID_BUTTON31, _("Block write AKM2 key"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON31"));
    StaticBoxSizer59->Add(bBWAKM2Key, 0, wxALL|wxALIGN_LEFT, 3);
    BoxSizer45->Add(StaticBoxSizer59, 1, wxALL|wxEXPAND, 3);
    StaticBoxSizer55->Add(BoxSizer45, 0, wxALL|wxEXPAND, 3);
    StaticText102 = new wxStaticText(Panel17, ID_STATICTEXT103, _("Block: (0 - 128 for 2K cards) and (0 - 255 for 4K cards)"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT103"));
    StaticBoxSizer55->Add(StaticText102, 0, wxALL|wxALIGN_LEFT, 0);
    Panel17->SetSizer(StaticBoxSizer55);
    StaticBoxSizer55->Fit(Panel17);
    StaticBoxSizer55->SetSizeHints(Panel17);
    Panel18 = new wxPanel(Notebook3, ID_PANEL18, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL18"));
    StaticBoxSizer60 = new wxStaticBoxSizer(wxVERTICAL, Panel18, wxEmptyString);
    BoxSizer52 = new wxBoxSizer(wxHORIZONTAL);
    StaticBoxSizer61 = new wxStaticBoxSizer(wxVERTICAL, Panel18, _("Provided key"));
    BoxSizer54 = new wxBoxSizer(wxHORIZONTAL);
    BSW_Provided_KeyA = new wxRadioButton(Panel18, ID_RADIOBUTTON39, _("Key A"), wxDefaultPosition, wxDefaultSize, wxRB_GROUP, wxDefaultValidator, _T("ID_RADIOBUTTON39"));
    BSW_Provided_KeyA->SetValue(true);
    BoxSizer54->Add(BSW_Provided_KeyA, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    BSW_Provided_KeyB = new wxRadioButton(Panel18, ID_RADIOBUTTON40, _("Key B"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON40"));
    BoxSizer54->Add(BSW_Provided_KeyB, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    StaticText85 = new wxStaticText(Panel18, ID_STATICTEXT86, _("Sector:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT86"));
    BoxSizer54->Add(StaticText85, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    BSW_Provided_SectorNr = new wxComboBox(Panel18, ID_COMBOBOX33, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, wxCB_READONLY, wxDefaultValidator, _T("ID_COMBOBOX33"));
    BSW_Provided_SectorNr->SetSelection( BSW_Provided_SectorNr->Append(_("0")) );
    BSW_Provided_SectorNr->Append(_("1"));
    BSW_Provided_SectorNr->Append(_("2"));
    BSW_Provided_SectorNr->Append(_("3"));
    BSW_Provided_SectorNr->Append(_("4"));
    BSW_Provided_SectorNr->Append(_("5"));
    BSW_Provided_SectorNr->Append(_("6"));
    BSW_Provided_SectorNr->Append(_("7"));
    BSW_Provided_SectorNr->Append(_("8"));
    BSW_Provided_SectorNr->Append(_("9"));
    BSW_Provided_SectorNr->Append(_("10"));
    BSW_Provided_SectorNr->Append(_("11"));
    BSW_Provided_SectorNr->Append(_("12"));
    BSW_Provided_SectorNr->Append(_("13"));
    BSW_Provided_SectorNr->Append(_("14"));
    BSW_Provided_SectorNr->Append(_("15"));
    BSW_Provided_SectorNr->Append(_("16"));
    BSW_Provided_SectorNr->Append(_("17"));
    BSW_Provided_SectorNr->Append(_("18"));
    BSW_Provided_SectorNr->Append(_("19"));
    BSW_Provided_SectorNr->Append(_("20"));
    BSW_Provided_SectorNr->Append(_("21"));
    BSW_Provided_SectorNr->Append(_("22"));
    BSW_Provided_SectorNr->Append(_("23"));
    BSW_Provided_SectorNr->Append(_("24"));
    BSW_Provided_SectorNr->Append(_("25"));
    BSW_Provided_SectorNr->Append(_("26"));
    BSW_Provided_SectorNr->Append(_("27"));
    BSW_Provided_SectorNr->Append(_("28"));
    BSW_Provided_SectorNr->Append(_("29"));
    BSW_Provided_SectorNr->Append(_("30"));
    BSW_Provided_SectorNr->Append(_("31"));
    BSW_Provided_SectorNr->Append(_("32"));
    BSW_Provided_SectorNr->Append(_("33"));
    BSW_Provided_SectorNr->Append(_("34"));
    BSW_Provided_SectorNr->Append(_("35"));
    BSW_Provided_SectorNr->Append(_("36"));
    BSW_Provided_SectorNr->Append(_("37"));
    BSW_Provided_SectorNr->Append(_("38"));
    BSW_Provided_SectorNr->Append(_("39"));
    BoxSizer54->Add(BSW_Provided_SectorNr, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    StaticText86 = new wxStaticText(Panel18, ID_STATICTEXT87, _("Block:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT87"));
    BoxSizer54->Add(StaticText86, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    BSW_Provided_BlockNr = new wxComboBox(Panel18, ID_COMBOBOX34, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, wxCB_READONLY, wxDefaultValidator, _T("ID_COMBOBOX34"));
    BSW_Provided_BlockNr->SetSelection( BSW_Provided_BlockNr->Append(_("0")) );
    BSW_Provided_BlockNr->Append(_("1"));
    BSW_Provided_BlockNr->Append(_("2"));
    BSW_Provided_BlockNr->Append(_("3"));
    BSW_Provided_BlockNr->Append(_("4"));
    BSW_Provided_BlockNr->Append(_("5"));
    BSW_Provided_BlockNr->Append(_("6"));
    BSW_Provided_BlockNr->Append(_("7"));
    BSW_Provided_BlockNr->Append(_("8"));
    BSW_Provided_BlockNr->Append(_("9"));
    BSW_Provided_BlockNr->Append(_("10"));
    BSW_Provided_BlockNr->Append(_("11"));
    BSW_Provided_BlockNr->Append(_("12"));
    BSW_Provided_BlockNr->Append(_("13"));
    BSW_Provided_BlockNr->Append(_("14"));
    BSW_Provided_BlockNr->Append(_("15"));
    BoxSizer54->Add(BSW_Provided_BlockNr, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    StaticBoxSizer61->Add(BoxSizer54, 1, wxALL|wxEXPAND, 3);
    BoxSizer55 = new wxBoxSizer(wxHORIZONTAL);
    StaticText87 = new wxStaticText(Panel18, ID_STATICTEXT88, _("Key:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT88"));
    BoxSizer55->Add(StaticText87, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    BSW_Provided_Key = new wxTextCtrl(Panel18, ID_TEXTCTRL51, wxEmptyString, wxDefaultPosition, wxSize(203,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL51"));
    BSW_Provided_Key->SetMaxLength(32);
    BoxSizer55->Add(BSW_Provided_Key, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    StaticBoxSizer61->Add(BoxSizer55, 1, wxALL|wxEXPAND, 3);
    bBSWProvidedKey = new wxButton(Panel18, ID_BUTTON32, _("Block in sector write provided key"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON32"));
    StaticBoxSizer61->Add(bBSWProvidedKey, 0, wxALL|wxALIGN_LEFT, 3);
    BoxSizer52->Add(StaticBoxSizer61, 1, wxALL|wxEXPAND, 3);
    StaticBoxSizer62 = new wxStaticBoxSizer(wxVERTICAL, Panel18, _("Reader key"));
    BoxSizer56 = new wxBoxSizer(wxHORIZONTAL);
    BSW_Reader_KeyA = new wxRadioButton(Panel18, ID_RADIOBUTTON41, _("Key A"), wxDefaultPosition, wxDefaultSize, wxRB_GROUP, wxDefaultValidator, _T("ID_RADIOBUTTON41"));
    BSW_Reader_KeyA->SetValue(true);
    BoxSizer56->Add(BSW_Reader_KeyA, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    BSW_Reader_KeyB = new wxRadioButton(Panel18, ID_RADIOBUTTON42, _("Key B"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON42"));
    BoxSizer56->Add(BSW_Reader_KeyB, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    StaticText88 = new wxStaticText(Panel18, ID_STATICTEXT89, _("Sector:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT89"));
    BoxSizer56->Add(StaticText88, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    BSW_Reader_SectorNr = new wxComboBox(Panel18, ID_COMBOBOX35, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, wxCB_READONLY, wxDefaultValidator, _T("ID_COMBOBOX35"));
    BSW_Reader_SectorNr->SetSelection( BSW_Reader_SectorNr->Append(_("0")) );
    BSW_Reader_SectorNr->Append(_("1"));
    BSW_Reader_SectorNr->Append(_("2"));
    BSW_Reader_SectorNr->Append(_("3"));
    BSW_Reader_SectorNr->Append(_("4"));
    BSW_Reader_SectorNr->Append(_("5"));
    BSW_Reader_SectorNr->Append(_("6"));
    BSW_Reader_SectorNr->Append(_("7"));
    BSW_Reader_SectorNr->Append(_("8"));
    BSW_Reader_SectorNr->Append(_("9"));
    BSW_Reader_SectorNr->Append(_("10"));
    BSW_Reader_SectorNr->Append(_("11"));
    BSW_Reader_SectorNr->Append(_("12"));
    BSW_Reader_SectorNr->Append(_("13"));
    BSW_Reader_SectorNr->Append(_("14"));
    BSW_Reader_SectorNr->Append(_("15"));
    BSW_Reader_SectorNr->Append(_("16"));
    BSW_Reader_SectorNr->Append(_("17"));
    BSW_Reader_SectorNr->Append(_("18"));
    BSW_Reader_SectorNr->Append(_("19"));
    BSW_Reader_SectorNr->Append(_("20"));
    BSW_Reader_SectorNr->Append(_("21"));
    BSW_Reader_SectorNr->Append(_("22"));
    BSW_Reader_SectorNr->Append(_("23"));
    BSW_Reader_SectorNr->Append(_("24"));
    BSW_Reader_SectorNr->Append(_("25"));
    BSW_Reader_SectorNr->Append(_("26"));
    BSW_Reader_SectorNr->Append(_("27"));
    BSW_Reader_SectorNr->Append(_("28"));
    BSW_Reader_SectorNr->Append(_("29"));
    BSW_Reader_SectorNr->Append(_("30"));
    BSW_Reader_SectorNr->Append(_("31"));
    BSW_Reader_SectorNr->Append(_("32"));
    BSW_Reader_SectorNr->Append(_("33"));
    BSW_Reader_SectorNr->Append(_("34"));
    BSW_Reader_SectorNr->Append(_("35"));
    BSW_Reader_SectorNr->Append(_("36"));
    BSW_Reader_SectorNr->Append(_("37"));
    BSW_Reader_SectorNr->Append(_("38"));
    BSW_Reader_SectorNr->Append(_("39"));
    BoxSizer56->Add(BSW_Reader_SectorNr, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    StaticText89 = new wxStaticText(Panel18, ID_STATICTEXT90, _("Block:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT90"));
    BoxSizer56->Add(StaticText89, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    BSW_Reader_BlockNr = new wxComboBox(Panel18, ID_COMBOBOX36, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, wxCB_READONLY, wxDefaultValidator, _T("ID_COMBOBOX36"));
    BSW_Reader_BlockNr->SetSelection( BSW_Reader_BlockNr->Append(_("0")) );
    BSW_Reader_BlockNr->Append(_("1"));
    BSW_Reader_BlockNr->Append(_("2"));
    BSW_Reader_BlockNr->Append(_("3"));
    BSW_Reader_BlockNr->Append(_("4"));
    BSW_Reader_BlockNr->Append(_("5"));
    BSW_Reader_BlockNr->Append(_("6"));
    BSW_Reader_BlockNr->Append(_("7"));
    BSW_Reader_BlockNr->Append(_("8"));
    BSW_Reader_BlockNr->Append(_("9"));
    BSW_Reader_BlockNr->Append(_("10"));
    BSW_Reader_BlockNr->Append(_("11"));
    BSW_Reader_BlockNr->Append(_("12"));
    BSW_Reader_BlockNr->Append(_("13"));
    BSW_Reader_BlockNr->Append(_("14"));
    BSW_Reader_BlockNr->Append(_("15"));
    BoxSizer56->Add(BSW_Reader_BlockNr, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    StaticBoxSizer62->Add(BoxSizer56, 0, wxALL|wxEXPAND, 3);
    BoxSizer57 = new wxBoxSizer(wxHORIZONTAL);
    StaticText90 = new wxStaticText(Panel18, ID_STATICTEXT91, _("Key index:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT91"));
    BoxSizer57->Add(StaticText90, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    BSW_Reader_KeyIndex = new wxComboBox(Panel18, ID_COMBOBOX37, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, wxCB_READONLY, wxDefaultValidator, _T("ID_COMBOBOX37"));
    BSW_Reader_KeyIndex->SetSelection( BSW_Reader_KeyIndex->Append(_("0")) );
    BSW_Reader_KeyIndex->Append(_("1"));
    BSW_Reader_KeyIndex->Append(_("2"));
    BSW_Reader_KeyIndex->Append(_("3"));
    BSW_Reader_KeyIndex->Append(_("4"));
    BSW_Reader_KeyIndex->Append(_("5"));
    BSW_Reader_KeyIndex->Append(_("6"));
    BSW_Reader_KeyIndex->Append(_("7"));
    BSW_Reader_KeyIndex->Append(_("8"));
    BSW_Reader_KeyIndex->Append(_("9"));
    BSW_Reader_KeyIndex->Append(_("10"));
    BSW_Reader_KeyIndex->Append(_("11"));
    BSW_Reader_KeyIndex->Append(_("12"));
    BSW_Reader_KeyIndex->Append(_("13"));
    BSW_Reader_KeyIndex->Append(_("14"));
    BSW_Reader_KeyIndex->Append(_("15"));
    BSW_Reader_KeyIndex->Append(_("16"));
    BSW_Reader_KeyIndex->Append(_("17"));
    BSW_Reader_KeyIndex->Append(_("18"));
    BSW_Reader_KeyIndex->Append(_("19"));
    BSW_Reader_KeyIndex->Append(_("20"));
    BSW_Reader_KeyIndex->Append(_("21"));
    BSW_Reader_KeyIndex->Append(_("22"));
    BSW_Reader_KeyIndex->Append(_("23"));
    BSW_Reader_KeyIndex->Append(_("24"));
    BSW_Reader_KeyIndex->Append(_("25"));
    BSW_Reader_KeyIndex->Append(_("26"));
    BSW_Reader_KeyIndex->Append(_("27"));
    BSW_Reader_KeyIndex->Append(_("28"));
    BSW_Reader_KeyIndex->Append(_("29"));
    BSW_Reader_KeyIndex->Append(_("30"));
    BSW_Reader_KeyIndex->Append(_("31"));
    BoxSizer57->Add(BSW_Reader_KeyIndex, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    StaticText109 = new wxStaticText(Panel18, ID_STATICTEXT110, _("(0 - 31 for CRYPTO 1) and (0 - 15 for AES key)"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT110"));
    BoxSizer57->Add(StaticText109, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    StaticBoxSizer62->Add(BoxSizer57, 0, wxALL|wxEXPAND, 3);
    bBSWReaderKey = new wxButton(Panel18, ID_BUTTON33, _("Block in sector write reader key"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON33"));
    StaticBoxSizer62->Add(bBSWReaderKey, 0, wxALL|wxALIGN_LEFT, 3);
    BoxSizer52->Add(StaticBoxSizer62, 1, wxALL|wxEXPAND, 3);
    StaticBoxSizer60->Add(BoxSizer52, 0, wxALL|wxEXPAND, 3);
    BoxSizer53 = new wxBoxSizer(wxHORIZONTAL);
    StaticBoxSizer63 = new wxStaticBoxSizer(wxVERTICAL, Panel18, _("AKM1 key"));
    BoxSizer58 = new wxBoxSizer(wxHORIZONTAL);
    BSW_AKM1_KeyA = new wxRadioButton(Panel18, ID_RADIOBUTTON43, _("Key A"), wxDefaultPosition, wxDefaultSize, wxRB_GROUP, wxDefaultValidator, _T("ID_RADIOBUTTON43"));
    BSW_AKM1_KeyA->SetValue(true);
    BoxSizer58->Add(BSW_AKM1_KeyA, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    BSW_AKM1_KeyB = new wxRadioButton(Panel18, ID_RADIOBUTTON44, _("Key B"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON44"));
    BoxSizer58->Add(BSW_AKM1_KeyB, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    StaticText91 = new wxStaticText(Panel18, ID_STATICTEXT92, _("Sector:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT92"));
    BoxSizer58->Add(StaticText91, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    BSW_AKM1_SectorNr = new wxComboBox(Panel18, ID_COMBOBOX38, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, wxCB_READONLY, wxDefaultValidator, _T("ID_COMBOBOX38"));
    BSW_AKM1_SectorNr->SetSelection( BSW_AKM1_SectorNr->Append(_("0")) );
    BSW_AKM1_SectorNr->Append(_("1"));
    BSW_AKM1_SectorNr->Append(_("2"));
    BSW_AKM1_SectorNr->Append(_("3"));
    BSW_AKM1_SectorNr->Append(_("4"));
    BSW_AKM1_SectorNr->Append(_("5"));
    BSW_AKM1_SectorNr->Append(_("6"));
    BSW_AKM1_SectorNr->Append(_("7"));
    BSW_AKM1_SectorNr->Append(_("8"));
    BSW_AKM1_SectorNr->Append(_("9"));
    BSW_AKM1_SectorNr->Append(_("10"));
    BSW_AKM1_SectorNr->Append(_("11"));
    BSW_AKM1_SectorNr->Append(_("12"));
    BSW_AKM1_SectorNr->Append(_("13"));
    BSW_AKM1_SectorNr->Append(_("14"));
    BSW_AKM1_SectorNr->Append(_("15"));
    BSW_AKM1_SectorNr->Append(_("16"));
    BSW_AKM1_SectorNr->Append(_("17"));
    BSW_AKM1_SectorNr->Append(_("18"));
    BSW_AKM1_SectorNr->Append(_("19"));
    BSW_AKM1_SectorNr->Append(_("20"));
    BSW_AKM1_SectorNr->Append(_("21"));
    BSW_AKM1_SectorNr->Append(_("22"));
    BSW_AKM1_SectorNr->Append(_("23"));
    BSW_AKM1_SectorNr->Append(_("24"));
    BSW_AKM1_SectorNr->Append(_("25"));
    BSW_AKM1_SectorNr->Append(_("26"));
    BSW_AKM1_SectorNr->Append(_("27"));
    BSW_AKM1_SectorNr->Append(_("28"));
    BSW_AKM1_SectorNr->Append(_("29"));
    BSW_AKM1_SectorNr->Append(_("30"));
    BSW_AKM1_SectorNr->Append(_("31"));
    BSW_AKM1_SectorNr->Append(_("32"));
    BSW_AKM1_SectorNr->Append(_("33"));
    BSW_AKM1_SectorNr->Append(_("34"));
    BSW_AKM1_SectorNr->Append(_("35"));
    BSW_AKM1_SectorNr->Append(_("36"));
    BSW_AKM1_SectorNr->Append(_("37"));
    BSW_AKM1_SectorNr->Append(_("38"));
    BSW_AKM1_SectorNr->Append(_("39"));
    BoxSizer58->Add(BSW_AKM1_SectorNr, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    StaticText92 = new wxStaticText(Panel18, ID_STATICTEXT93, _("Block:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT93"));
    BoxSizer58->Add(StaticText92, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    BSW_AKM1_BlockNr = new wxComboBox(Panel18, ID_COMBOBOX39, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, wxCB_READONLY, wxDefaultValidator, _T("ID_COMBOBOX39"));
    BSW_AKM1_BlockNr->SetSelection( BSW_AKM1_BlockNr->Append(_("0")) );
    BSW_AKM1_BlockNr->Append(_("1"));
    BSW_AKM1_BlockNr->Append(_("2"));
    BSW_AKM1_BlockNr->Append(_("3"));
    BSW_AKM1_BlockNr->Append(_("4"));
    BSW_AKM1_BlockNr->Append(_("5"));
    BSW_AKM1_BlockNr->Append(_("6"));
    BSW_AKM1_BlockNr->Append(_("7"));
    BSW_AKM1_BlockNr->Append(_("8"));
    BSW_AKM1_BlockNr->Append(_("9"));
    BSW_AKM1_BlockNr->Append(_("10"));
    BSW_AKM1_BlockNr->Append(_("11"));
    BSW_AKM1_BlockNr->Append(_("12"));
    BSW_AKM1_BlockNr->Append(_("13"));
    BSW_AKM1_BlockNr->Append(_("14"));
    BSW_AKM1_BlockNr->Append(_("15"));
    BoxSizer58->Add(BSW_AKM1_BlockNr, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    StaticBoxSizer63->Add(BoxSizer58, 1, wxALL|wxEXPAND, 3);
    bBSWAKM1Key = new wxButton(Panel18, ID_BUTTON34, _("Block in sector write AKM1 key"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON34"));
    StaticBoxSizer63->Add(bBSWAKM1Key, 0, wxALL|wxALIGN_LEFT, 3);
    BoxSizer53->Add(StaticBoxSizer63, 1, wxALL|wxEXPAND, 3);
    StaticBoxSizer64 = new wxStaticBoxSizer(wxVERTICAL, Panel18, _("AKM2 key"));
    BoxSizer59 = new wxBoxSizer(wxHORIZONTAL);
    BSW_AKM2_KeyA = new wxRadioButton(Panel18, ID_RADIOBUTTON45, _("Key A"), wxDefaultPosition, wxDefaultSize, wxRB_GROUP, wxDefaultValidator, _T("ID_RADIOBUTTON45"));
    BSW_AKM2_KeyA->SetValue(true);
    BoxSizer59->Add(BSW_AKM2_KeyA, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    BSW_AKM2_KeyB = new wxRadioButton(Panel18, ID_RADIOBUTTON46, _("Key B"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON46"));
    BoxSizer59->Add(BSW_AKM2_KeyB, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    StaticText93 = new wxStaticText(Panel18, ID_STATICTEXT94, _("Sector:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT94"));
    BoxSizer59->Add(StaticText93, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    BSW_AKM2_SectorNr = new wxComboBox(Panel18, ID_COMBOBOX40, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, wxCB_READONLY, wxDefaultValidator, _T("ID_COMBOBOX40"));
    BSW_AKM2_SectorNr->SetSelection( BSW_AKM2_SectorNr->Append(_("0")) );
    BSW_AKM2_SectorNr->Append(_("1"));
    BSW_AKM2_SectorNr->Append(_("2"));
    BSW_AKM2_SectorNr->Append(_("3"));
    BSW_AKM2_SectorNr->Append(_("4"));
    BSW_AKM2_SectorNr->Append(_("5"));
    BSW_AKM2_SectorNr->Append(_("6"));
    BSW_AKM2_SectorNr->Append(_("7"));
    BSW_AKM2_SectorNr->Append(_("8"));
    BSW_AKM2_SectorNr->Append(_("9"));
    BSW_AKM2_SectorNr->Append(_("10"));
    BSW_AKM2_SectorNr->Append(_("11"));
    BSW_AKM2_SectorNr->Append(_("12"));
    BSW_AKM2_SectorNr->Append(_("13"));
    BSW_AKM2_SectorNr->Append(_("14"));
    BSW_AKM2_SectorNr->Append(_("15"));
    BSW_AKM2_SectorNr->Append(_("16"));
    BSW_AKM2_SectorNr->Append(_("17"));
    BSW_AKM2_SectorNr->Append(_("18"));
    BSW_AKM2_SectorNr->Append(_("19"));
    BSW_AKM2_SectorNr->Append(_("20"));
    BSW_AKM2_SectorNr->Append(_("21"));
    BSW_AKM2_SectorNr->Append(_("22"));
    BSW_AKM2_SectorNr->Append(_("23"));
    BSW_AKM2_SectorNr->Append(_("24"));
    BSW_AKM2_SectorNr->Append(_("25"));
    BSW_AKM2_SectorNr->Append(_("26"));
    BSW_AKM2_SectorNr->Append(_("27"));
    BSW_AKM2_SectorNr->Append(_("28"));
    BSW_AKM2_SectorNr->Append(_("29"));
    BSW_AKM2_SectorNr->Append(_("30"));
    BSW_AKM2_SectorNr->Append(_("31"));
    BSW_AKM2_SectorNr->Append(_("32"));
    BSW_AKM2_SectorNr->Append(_("33"));
    BSW_AKM2_SectorNr->Append(_("34"));
    BSW_AKM2_SectorNr->Append(_("35"));
    BSW_AKM2_SectorNr->Append(_("36"));
    BSW_AKM2_SectorNr->Append(_("37"));
    BSW_AKM2_SectorNr->Append(_("38"));
    BSW_AKM2_SectorNr->Append(_("39"));
    BoxSizer59->Add(BSW_AKM2_SectorNr, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    StaticText94 = new wxStaticText(Panel18, ID_STATICTEXT95, _("Block:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT95"));
    BoxSizer59->Add(StaticText94, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    BSW_AKM2_BlockNr = new wxComboBox(Panel18, ID_COMBOBOX41, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, wxCB_READONLY, wxDefaultValidator, _T("ID_COMBOBOX41"));
    BSW_AKM2_BlockNr->SetSelection( BSW_AKM2_BlockNr->Append(_("0")) );
    BSW_AKM2_BlockNr->Append(_("1"));
    BSW_AKM2_BlockNr->Append(_("2"));
    BSW_AKM2_BlockNr->Append(_("3"));
    BSW_AKM2_BlockNr->Append(_("4"));
    BSW_AKM2_BlockNr->Append(_("5"));
    BSW_AKM2_BlockNr->Append(_("6"));
    BSW_AKM2_BlockNr->Append(_("7"));
    BSW_AKM2_BlockNr->Append(_("8"));
    BSW_AKM2_BlockNr->Append(_("9"));
    BSW_AKM2_BlockNr->Append(_("10"));
    BSW_AKM2_BlockNr->Append(_("11"));
    BSW_AKM2_BlockNr->Append(_("12"));
    BSW_AKM2_BlockNr->Append(_("13"));
    BSW_AKM2_BlockNr->Append(_("14"));
    BSW_AKM2_BlockNr->Append(_("15"));
    BoxSizer59->Add(BSW_AKM2_BlockNr, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    StaticBoxSizer64->Add(BoxSizer59, 0, wxALL|wxEXPAND, 3);
    bBSWAKM2Key = new wxButton(Panel18, ID_BUTTON35, _("Block in sector write AKM2 key"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON35"));
    StaticBoxSizer64->Add(bBSWAKM2Key, 0, wxALL|wxALIGN_LEFT, 3);
    BoxSizer53->Add(StaticBoxSizer64, 1, wxALL|wxEXPAND, 3);
    StaticBoxSizer60->Add(BoxSizer53, 0, wxALL|wxEXPAND, 3);
    StaticText99 = new wxStaticText(Panel18, ID_STATICTEXT100, _("Sector: (0 - 31 for 2K cards) and (0 - 39 for 4K cards), Block: (0 - 3 for sectors 0 - 31) and (0 - 15 for sectors 32 - 39)"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT100"));
    StaticBoxSizer60->Add(StaticText99, 0, wxALL|wxALIGN_LEFT, 3);
    Panel18->SetSizer(StaticBoxSizer60);
    StaticBoxSizer60->Fit(Panel18);
    StaticBoxSizer60->SetSizeHints(Panel18);
    Panel19 = new wxPanel(Notebook3, ID_PANEL19, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL19"));
    StaticBoxSizer65 = new wxStaticBoxSizer(wxVERTICAL, Panel19, wxEmptyString);
    BoxSizer60 = new wxBoxSizer(wxHORIZONTAL);
    StaticBoxSizer66 = new wxStaticBoxSizer(wxVERTICAL, Panel19, _("Provided key"));
    BoxSizer62 = new wxBoxSizer(wxHORIZONTAL);
    LW_Provided_KeyA = new wxRadioButton(Panel19, ID_RADIOBUTTON47, _("Key A"), wxDefaultPosition, wxDefaultSize, wxRB_GROUP, wxDefaultValidator, _T("ID_RADIOBUTTON47"));
    LW_Provided_KeyA->SetValue(true);
    BoxSizer62->Add(LW_Provided_KeyA, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    LW_Provided_KeyB = new wxRadioButton(Panel19, ID_RADIOBUTTON48, _("Key B"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON48"));
    BoxSizer62->Add(LW_Provided_KeyB, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    StaticText95 = new wxStaticText(Panel19, ID_STATICTEXT96, _("Address:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT96"));
    BoxSizer62->Add(StaticText95, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    LW_Provided_Addr = new wxTextCtrl(Panel19, ID_TEXTCTRL52, wxEmptyString, wxDefaultPosition, wxSize(39,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL52"));
    LW_Provided_Addr->SetMaxLength(4);
    BoxSizer62->Add(LW_Provided_Addr, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    StaticBoxSizer66->Add(BoxSizer62, 1, wxALL|wxEXPAND, 3);
    BoxSizer63 = new wxBoxSizer(wxHORIZONTAL);
    StaticText97 = new wxStaticText(Panel19, ID_STATICTEXT98, _("Key:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT98"));
    BoxSizer63->Add(StaticText97, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    LW_Provided_Key = new wxTextCtrl(Panel19, ID_TEXTCTRL54, wxEmptyString, wxDefaultPosition, wxSize(203,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL54"));
    LW_Provided_Key->SetMaxLength(32);
    BoxSizer63->Add(LW_Provided_Key, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    StaticBoxSizer66->Add(BoxSizer63, 1, wxALL|wxEXPAND, 3);
    bLWProvidedKey = new wxButton(Panel19, ID_BUTTON2, _("Linear write provided key"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    StaticBoxSizer66->Add(bLWProvidedKey, 0, wxALL|wxALIGN_LEFT, 3);
    BoxSizer60->Add(StaticBoxSizer66, 1, wxALL|wxEXPAND, 3);
    StaticBoxSizer67 = new wxStaticBoxSizer(wxVERTICAL, Panel19, _("Reader key"));
    BoxSizer64 = new wxBoxSizer(wxHORIZONTAL);
    LW_Reader_KeyA = new wxRadioButton(Panel19, ID_RADIOBUTTON49, _("Key A"), wxDefaultPosition, wxDefaultSize, wxRB_GROUP, wxDefaultValidator, _T("ID_RADIOBUTTON49"));
    LW_Reader_KeyA->SetValue(true);
    BoxSizer64->Add(LW_Reader_KeyA, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    LW_Reader_KeyB = new wxRadioButton(Panel19, ID_RADIOBUTTON50, _("Key B"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON50"));
    BoxSizer64->Add(LW_Reader_KeyB, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    StaticText98 = new wxStaticText(Panel19, ID_STATICTEXT99, _("Address:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT99"));
    BoxSizer64->Add(StaticText98, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    LW_Reader_Addr = new wxTextCtrl(Panel19, ID_TEXTCTRL55, wxEmptyString, wxDefaultPosition, wxSize(39,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL55"));
    LW_Reader_Addr->SetMaxLength(4);
    BoxSizer64->Add(LW_Reader_Addr, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    StaticBoxSizer67->Add(BoxSizer64, 0, wxALL|wxEXPAND, 3);
    BoxSizer65 = new wxBoxSizer(wxHORIZONTAL);
    StaticText100 = new wxStaticText(Panel19, ID_STATICTEXT101, _("Key index:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT101"));
    BoxSizer65->Add(StaticText100, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    LW_Reader_KeyIndex = new wxComboBox(Panel19, ID_COMBOBOX42, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, wxCB_READONLY, wxDefaultValidator, _T("ID_COMBOBOX42"));
    LW_Reader_KeyIndex->SetSelection( LW_Reader_KeyIndex->Append(_("0")) );
    LW_Reader_KeyIndex->Append(_("1"));
    LW_Reader_KeyIndex->Append(_("2"));
    LW_Reader_KeyIndex->Append(_("3"));
    LW_Reader_KeyIndex->Append(_("4"));
    LW_Reader_KeyIndex->Append(_("5"));
    LW_Reader_KeyIndex->Append(_("6"));
    LW_Reader_KeyIndex->Append(_("7"));
    LW_Reader_KeyIndex->Append(_("8"));
    LW_Reader_KeyIndex->Append(_("9"));
    LW_Reader_KeyIndex->Append(_("10"));
    LW_Reader_KeyIndex->Append(_("11"));
    LW_Reader_KeyIndex->Append(_("12"));
    LW_Reader_KeyIndex->Append(_("13"));
    LW_Reader_KeyIndex->Append(_("14"));
    LW_Reader_KeyIndex->Append(_("15"));
    BoxSizer65->Add(LW_Reader_KeyIndex, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    StaticText108 = new wxStaticText(Panel19, ID_STATICTEXT109, _("(0 - 31 for CRYPTO 1) and (0 - 15 for AES key)"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT109"));
    BoxSizer65->Add(StaticText108, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    StaticBoxSizer67->Add(BoxSizer65, 0, wxALL|wxEXPAND, 3);
    bLWReaderKey = new wxButton(Panel19, ID_BUTTON36, _("Linear write reader key"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON36"));
    StaticBoxSizer67->Add(bLWReaderKey, 0, wxALL|wxALIGN_LEFT, 3);
    BoxSizer60->Add(StaticBoxSizer67, 1, wxALL|wxEXPAND, 3);
    StaticBoxSizer65->Add(BoxSizer60, 0, wxALL|wxEXPAND, 3);
    BoxSizer61 = new wxBoxSizer(wxHORIZONTAL);
    StaticBoxSizer68 = new wxStaticBoxSizer(wxVERTICAL, Panel19, _("AKM1 key"));
    BoxSizer66 = new wxBoxSizer(wxHORIZONTAL);
    LW_AKM1_KeyA = new wxRadioButton(Panel19, ID_RADIOBUTTON51, _("Key A"), wxDefaultPosition, wxDefaultSize, wxRB_GROUP, wxDefaultValidator, _T("ID_RADIOBUTTON51"));
    LW_AKM1_KeyA->SetValue(true);
    BoxSizer66->Add(LW_AKM1_KeyA, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    LW_AKM1_KeyB = new wxRadioButton(Panel19, ID_RADIOBUTTON52, _("Key B"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON52"));
    BoxSizer66->Add(LW_AKM1_KeyB, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    StaticText101 = new wxStaticText(Panel19, ID_STATICTEXT102, _("Address:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT102"));
    BoxSizer66->Add(StaticText101, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    LW_AKM1_Addr = new wxTextCtrl(Panel19, ID_TEXTCTRL57, wxEmptyString, wxDefaultPosition, wxSize(39,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL57"));
    LW_AKM1_Addr->SetMaxLength(4);
    BoxSizer66->Add(LW_AKM1_Addr, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    StaticBoxSizer68->Add(BoxSizer66, 1, wxALL|wxEXPAND, 3);
    bLWAKM1Key = new wxButton(Panel19, ID_BUTTON37, _("Linear write AKM1 key"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON37"));
    StaticBoxSizer68->Add(bLWAKM1Key, 0, wxALL|wxALIGN_LEFT, 3);
    BoxSizer61->Add(StaticBoxSizer68, 1, wxALL|wxEXPAND, 3);
    StaticBoxSizer69 = new wxStaticBoxSizer(wxVERTICAL, Panel19, _("AKM2 key"));
    BoxSizer67 = new wxBoxSizer(wxHORIZONTAL);
    LW_AKM2_KeyA = new wxRadioButton(Panel19, ID_RADIOBUTTON53, _("Key A"), wxDefaultPosition, wxDefaultSize, wxRB_GROUP, wxDefaultValidator, _T("ID_RADIOBUTTON53"));
    LW_AKM2_KeyA->SetValue(true);
    BoxSizer67->Add(LW_AKM2_KeyA, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    LW_AKM2_KeyB = new wxRadioButton(Panel19, ID_RADIOBUTTON54, _("Key B"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON54"));
    BoxSizer67->Add(LW_AKM2_KeyB, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    StaticText103 = new wxStaticText(Panel19, ID_STATICTEXT104, _("Address:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT104"));
    BoxSizer67->Add(StaticText103, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    LW_AKM2_Addr = new wxTextCtrl(Panel19, ID_TEXTCTRL59, wxEmptyString, wxDefaultPosition, wxSize(39,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL59"));
    LW_AKM2_Addr->SetMaxLength(4);
    BoxSizer67->Add(LW_AKM2_Addr, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    StaticBoxSizer69->Add(BoxSizer67, 0, wxALL|wxEXPAND, 3);
    bLWAKM2Key = new wxButton(Panel19, ID_BUTTON38, _("Linear write AKM2 key"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON38"));
    StaticBoxSizer69->Add(bLWAKM2Key, 0, wxALL|wxALIGN_LEFT, 3);
    BoxSizer61->Add(StaticBoxSizer69, 1, wxALL|wxEXPAND, 3);
    StaticBoxSizer65->Add(BoxSizer61, 0, wxALL|wxEXPAND, 3);
    StaticText96 = new wxStaticText(Panel19, ID_STATICTEXT97, _("Addres: (0 - 1519 for 2K cards) and (0 - 3439 for 4K cards)"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT97"));
    StaticBoxSizer65->Add(StaticText96, 0, wxALL|wxALIGN_LEFT, 3);
    Panel19->SetSizer(StaticBoxSizer65);
    StaticBoxSizer65->Fit(Panel19);
    StaticBoxSizer65->SetSizeHints(Panel19);
    Notebook3->AddPage(Panel17, _("Block write"), false);
    Notebook3->AddPage(Panel18, _("Block in sector write"), false);
    Notebook3->AddPage(Panel19, _("Linear write"), false);
    StaticBoxSizer54->Add(Notebook3, 1, wxALL|wxEXPAND, 0);
    BoxSizer43 = new wxBoxSizer(wxHORIZONTAL);
    StaticText78 = new wxStaticText(Panel12, ID_STATICTEXT79, _("Data:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT79"));
    BoxSizer43->Add(StaticText78, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    WriteDataTB = new wxTextCtrl(Panel12, ID_TEXTCTRL49, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL49"));
    BoxSizer43->Add(WriteDataTB, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    StaticBoxSizer54->Add(BoxSizer43, 0, wxALL|wxEXPAND, 3);
    Panel12->SetSizer(StaticBoxSizer54);
    StaticBoxSizer54->Fit(Panel12);
    StaticBoxSizer54->SetSizeHints(Panel12);
    Panel13 = new wxPanel(Notebook1, ID_PANEL13, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL13"));
    StaticBoxSizer29 = new wxStaticBoxSizer(wxVERTICAL, Panel13, wxEmptyString);
    BoxSizer19 = new wxBoxSizer(wxHORIZONTAL);
    StaticBoxSizer30 = new wxStaticBoxSizer(wxVERTICAL, Panel13, _("CRYPTO 1 keys"));
    StaticText45 = new wxStaticText(Panel13, ID_STATICTEXT46, _("Enter CRYPTO 1 key (6 bytes):"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT46"));
    StaticBoxSizer30->Add(StaticText45, 0, wxALL|wxALIGN_LEFT, 3);
    Crypto1TB = new wxTextCtrl(Panel13, ID_TEXTCTRL34, _("FFFFFFFFFFFF"), wxDefaultPosition, wxSize(203,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL34"));
    Crypto1TB->SetMaxLength(12);
    StaticBoxSizer30->Add(Crypto1TB, 1, wxALL|wxALIGN_LEFT, 3);
    StaticText46 = new wxStaticText(Panel13, ID_STATICTEXT47, _("Enter key index (0 - 31):"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT47"));
    StaticBoxSizer30->Add(StaticText46, 0, wxALL|wxALIGN_LEFT, 3);
    Crypto1Index = new wxComboBox(Panel13, ID_COMBOBOX12, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, wxCB_READONLY, wxDefaultValidator, _T("ID_COMBOBOX12"));
    Crypto1Index->SetSelection( Crypto1Index->Append(_("0")) );
    Crypto1Index->Append(_("1"));
    Crypto1Index->Append(_("2"));
    Crypto1Index->Append(_("3"));
    Crypto1Index->Append(_("4"));
    Crypto1Index->Append(_("5"));
    Crypto1Index->Append(_("6"));
    Crypto1Index->Append(_("7"));
    Crypto1Index->Append(_("8"));
    Crypto1Index->Append(_("9"));
    Crypto1Index->Append(_("10"));
    Crypto1Index->Append(_("11"));
    Crypto1Index->Append(_("12"));
    Crypto1Index->Append(_("13"));
    Crypto1Index->Append(_("14"));
    Crypto1Index->Append(_("15"));
    Crypto1Index->Append(_("16"));
    Crypto1Index->Append(_("17"));
    Crypto1Index->Append(_("18"));
    Crypto1Index->Append(_("19"));
    Crypto1Index->Append(_("20"));
    Crypto1Index->Append(_("21"));
    Crypto1Index->Append(_("22"));
    Crypto1Index->Append(_("23"));
    Crypto1Index->Append(_("24"));
    Crypto1Index->Append(_("25"));
    Crypto1Index->Append(_("26"));
    Crypto1Index->Append(_("27"));
    Crypto1Index->Append(_("28"));
    Crypto1Index->Append(_("29"));
    Crypto1Index->Append(_("30"));
    Crypto1Index->Append(_("31"));
    StaticBoxSizer30->Add(Crypto1Index, 0, wxALL|wxALIGN_LEFT, 3);
    bWriteCrypto1 = new wxButton(Panel13, ID_BUTTON12, _("Write CRYPTO 1 key into reader"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON12"));
    StaticBoxSizer30->Add(bWriteCrypto1, 1, wxALL|wxALIGN_LEFT, 3);
    BoxSizer19->Add(StaticBoxSizer30, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    StaticBoxSizer31 = new wxStaticBoxSizer(wxVERTICAL, Panel13, _("AES keys"));
    StaticText47 = new wxStaticText(Panel13, ID_STATICTEXT48, _("Enter AES key (16 bytes) :"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT48"));
    StaticBoxSizer31->Add(StaticText47, 0, wxALL, 3);
    AES_TB = new wxTextCtrl(Panel13, ID_TEXTCTRL35, _("FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF"), wxDefaultPosition, wxSize(203,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL35"));
    AES_TB->SetMaxLength(32);
    StaticBoxSizer31->Add(AES_TB, 0, wxALL|wxALIGN_LEFT, 3);
    StaticText48 = new wxStaticText(Panel13, ID_STATICTEXT49, _("Enter key index (0 - 15):"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT49"));
    StaticBoxSizer31->Add(StaticText48, 0, wxALL|wxALIGN_LEFT, 3);
    AES_Index = new wxComboBox(Panel13, ID_COMBOBOX13, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, wxCB_READONLY, wxDefaultValidator, _T("ID_COMBOBOX13"));
    AES_Index->SetSelection( AES_Index->Append(_("0")) );
    AES_Index->Append(_("1"));
    AES_Index->Append(_("2"));
    AES_Index->Append(_("3"));
    AES_Index->Append(_("4"));
    AES_Index->Append(_("5"));
    AES_Index->Append(_("6"));
    AES_Index->Append(_("7"));
    AES_Index->Append(_("8"));
    AES_Index->Append(_("9"));
    AES_Index->Append(_("10"));
    AES_Index->Append(_("11"));
    AES_Index->Append(_("12"));
    AES_Index->Append(_("13"));
    AES_Index->Append(_("14"));
    AES_Index->Append(_("15"));
    StaticBoxSizer31->Add(AES_Index, 0, wxALL|wxALIGN_LEFT, 3);
    bWriteAES = new wxButton(Panel13, ID_BUTTON13, _("Write AES key into reader"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON13"));
    StaticBoxSizer31->Add(bWriteAES, 1, wxALL|wxALIGN_LEFT, 3);
    BoxSizer19->Add(StaticBoxSizer31, 1, wxALL|wxEXPAND, 3);
    StaticBoxSizer29->Add(BoxSizer19, 0, wxALL|wxEXPAND, 3);
    BoxSizer20 = new wxBoxSizer(wxHORIZONTAL);
    StaticBoxSizer32 = new wxStaticBoxSizer(wxVERTICAL, Panel13, _("Unlock reader"));
    StaticText49 = new wxStaticText(Panel13, ID_STATICTEXT50, _("Enter password (8 characters):"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT50"));
    StaticBoxSizer32->Add(StaticText49, 0, wxALL|wxALIGN_LEFT, 3);
    UnlockKeysTB = new wxTextCtrl(Panel13, ID_TEXTCTRL36, _("11111111"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL36"));
    UnlockKeysTB->SetMaxLength(8);
    StaticBoxSizer32->Add(UnlockKeysTB, 1, wxALL|wxALIGN_LEFT, 3);
    bUnlockKeys = new wxButton(Panel13, ID_BUTTON14, _("Unlock keys"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON14"));
    StaticBoxSizer32->Add(bUnlockKeys, 1, wxALL|wxALIGN_LEFT, 3);
    BoxSizer20->Add(StaticBoxSizer32, 1, wxALL|wxEXPAND, 3);
    StaticBoxSizer33 = new wxStaticBoxSizer(wxVERTICAL, Panel13, _("Lock reader"));
    StaticText50 = new wxStaticText(Panel13, ID_STATICTEXT51, _("Enter password (8 characters):"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT51"));
    StaticBoxSizer33->Add(StaticText50, 0, wxALL, 3);
    LockKeysTB = new wxTextCtrl(Panel13, ID_TEXTCTRL37, _("11111111"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL37"));
    LockKeysTB->SetMaxLength(8);
    StaticBoxSizer33->Add(LockKeysTB, 0, wxALL|wxALIGN_LEFT, 3);
    bLockKeys = new wxButton(Panel13, ID_BUTTON15, _("Lock keys"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON15"));
    StaticBoxSizer33->Add(bLockKeys, 1, wxALL|wxALIGN_LEFT, 5);
    BoxSizer20->Add(StaticBoxSizer33, 1, wxALL|wxEXPAND, 3);
    StaticBoxSizer29->Add(BoxSizer20, 0, wxALL|wxEXPAND, 3);
    Panel13->SetSizer(StaticBoxSizer29);
    StaticBoxSizer29->Fit(Panel13);
    StaticBoxSizer29->SetSizeHints(Panel13);
    Notebook1->AddPage(Panel1, _("Card personalization"), false);
    Notebook1->AddPage(Panel2, _("Auth SL1"), false);
    Notebook1->AddPage(Panel3, _("Switch to SL3"), false);
    Notebook1->AddPage(Panel4, _("Change master key"), false);
    Notebook1->AddPage(Panel5, _("Change config key"), false);
    Notebook1->AddPage(Panel6, _("Change sectors keys"), false);
    Notebook1->AddPage(Panel7, _("Field configuration setting"), false);
    Notebook1->AddPage(Panel8, _("Get card UID"), false);
    Notebook1->AddPage(Panel9, _("Change VC polling ENC key"), false);
    Notebook1->AddPage(Panel10, _("Change VC polling MAC key"), false);
    Notebook1->AddPage(Panel11, _("Data read"), false);
    Notebook1->AddPage(Panel12, _("Data write"), false);
    Notebook1->AddPage(Panel13, _("Reader keys"), false);
    BoxSizer2->Add(Notebook1, 1, wxALL|wxEXPAND, 1);
    StaticBoxSizer1->Add(BoxSizer2, 0, wxALL|wxEXPAND, 0);
    ReaderInfo = new wxTextCtrl(this, ID_TEXTCTRL12, wxEmptyString, wxDefaultPosition, wxSize(830,143), wxTE_MULTILINE|wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL12"));
    ReaderInfo->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INACTIVEBORDER));
    wxFont ReaderInfoFont(10,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Consolas"),wxFONTENCODING_DEFAULT);
    ReaderInfo->SetFont(ReaderInfoFont);
    StaticBoxSizer1->Add(ReaderInfo, 1, wxALL|wxEXPAND, 0);
    BoxSizer8 = new wxBoxSizer(wxHORIZONTAL);
    StaticText12 = new wxStaticText(this, ID_STATICTEXT12, _("Status :"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT12"));
    BoxSizer8->Add(StaticText12, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    StatusLabel = new wxStaticText(this, ID_STATICTEXT13, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT13"));
    BoxSizer8->Add(StatusLabel, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    StaticBoxSizer1->Add(BoxSizer8, 0, wxALL|wxALIGN_LEFT, 0);
    SetSizer(StaticBoxSizer1);
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);
    Timer1.SetOwner(this, ID_TIMER1);
    Timer1.Start(100, false);
    Timer2.SetOwner(this, ID_TIMER2);
    Timer2.Start(200, false);
    StaticBoxSizer1->Fit(this);
    StaticBoxSizer1->SetSizeHints(this);

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&mfp_wxwidgetsFrame::OnbPersonalizeCardClick);
    Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&mfp_wxwidgetsFrame::OnbAesAuthSL1Click1);
    Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&mfp_wxwidgetsFrame::OnbSwitchToSL3Click);
    Connect(ID_BUTTON5,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&mfp_wxwidgetsFrame::OnButton3Click);
    Connect(ID_BUTTON6,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&mfp_wxwidgetsFrame::OnButton4Click);
    Connect(ID_BUTTON7,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&mfp_wxwidgetsFrame::OnbChangeSectorKeysClick);
    Connect(ID_BUTTON8,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&mfp_wxwidgetsFrame::OnbSetFieldConfigurationClick);
    Connect(ID_BUTTON9,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&mfp_wxwidgetsFrame::OnbGetENCMACUidClick);
    Connect(ID_BUTTON10,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&mfp_wxwidgetsFrame::OnbChangeVCPollingENCKeyClick);
    Connect(ID_BUTTON11,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&mfp_wxwidgetsFrame::OnbChangeVCpolingMACKeyClick);
    Connect(ID_BUTTON16,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&mfp_wxwidgetsFrame::OnbBRProvidedKeyClick);
    Connect(ID_BUTTON17,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&mfp_wxwidgetsFrame::OnbBRReaderKeyClick);
    Connect(ID_BUTTON18,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&mfp_wxwidgetsFrame::OnbBRAKM1Click);
    Connect(ID_BUTTON19,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&mfp_wxwidgetsFrame::OnbBRAKM2Click);
    Connect(ID_BUTTON20,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&mfp_wxwidgetsFrame::OnbBSRProvidedKeyClick);
    Connect(ID_BUTTON21,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&mfp_wxwidgetsFrame::OnbBSRReaderClick);
    Connect(ID_BUTTON22,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&mfp_wxwidgetsFrame::OnbBSRAKM1Click);
    Connect(ID_BUTTON23,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&mfp_wxwidgetsFrame::OnbBSRAKM2Click);
    Connect(ID_BUTTON24,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&mfp_wxwidgetsFrame::OnbLRProvidedClick);
    Connect(ID_BUTTON25,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&mfp_wxwidgetsFrame::OnbLRReaderClick);
    Connect(ID_BUTTON26,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&mfp_wxwidgetsFrame::OnbLRAKM1Click);
    Connect(ID_BUTTON27,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&mfp_wxwidgetsFrame::OnbLRAKM2Click);
    Connect(ID_BUTTON28,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&mfp_wxwidgetsFrame::OnbBWProvidedKeyClick);
    Connect(ID_BUTTON29,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&mfp_wxwidgetsFrame::OnbBWReaderKeyClick);
    Connect(ID_BUTTON30,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&mfp_wxwidgetsFrame::OnbBWAKM1KeyClick);
    Connect(ID_BUTTON31,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&mfp_wxwidgetsFrame::OnbBWAKM2KeyClick);
    Connect(ID_BUTTON32,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&mfp_wxwidgetsFrame::OnbBSWProvidedKeyClick);
    Connect(ID_BUTTON33,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&mfp_wxwidgetsFrame::OnbBSWReaderKeyClick);
    Connect(ID_BUTTON34,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&mfp_wxwidgetsFrame::OnbBSWAKM1KeyClick);
    Connect(ID_BUTTON35,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&mfp_wxwidgetsFrame::OnbBSWAKM2KeyClick);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&mfp_wxwidgetsFrame::OnbLWProvidedKeyClick);
    Connect(ID_BUTTON36,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&mfp_wxwidgetsFrame::OnbLWReaderKeyClick);
    Connect(ID_BUTTON37,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&mfp_wxwidgetsFrame::OnbLWAKM1KeyClick);
    Connect(ID_BUTTON38,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&mfp_wxwidgetsFrame::OnbLWAKM2KeyClick);
    Connect(ID_BUTTON12,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&mfp_wxwidgetsFrame::OnbWriteCrypto1Click);
    Connect(ID_BUTTON13,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&mfp_wxwidgetsFrame::OnbWriteAESClick);
    Connect(ID_BUTTON14,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&mfp_wxwidgetsFrame::OnbUnlockKeysClick);
    Connect(ID_BUTTON15,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&mfp_wxwidgetsFrame::OnbLockKeysClick);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&mfp_wxwidgetsFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&mfp_wxwidgetsFrame::OnAbout);
    Connect(ID_TIMER1,wxEVT_TIMER,(wxObjectEventFunction)&mfp_wxwidgetsFrame::OnTimer1Trigger);
    Connect(ID_TIMER2,wxEVT_TIMER,(wxObjectEventFunction)&mfp_wxwidgetsFrame::OnTimer2Trigger);
    //*)
}

mfp_wxwidgetsFrame::~mfp_wxwidgetsFrame()
{
    //(*Destroy(mfp_wxwidgetsFrame)
    //*)
}

void mfp_wxwidgetsFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void mfp_wxwidgetsFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void mfp_wxwidgetsFrame::OnTimer1Trigger(wxTimerEvent& event)
{
    status = ReaderOpen();

    wxString wxStatus = UFR_Status2String(status);

    if(status)
    {
        StatusLabel->SetLabel("Port not opened. Searching for reader...");
    }
    else
    {

    std::string desc = GetReaderDescription();
    desc = desc.substr(1, desc.length());
    ReaderInfo->SetValue(desc);

    Timer1.Stop();

    }

    StatusLabel->SetLabel((std::string)UFR_Status2String(status));


}

void mfp_wxwidgetsFrame::OnbPersonalizeCardClick(wxCommandEvent& event)
{
    wxString wxMasterKey = CardMasterKeyTB->GetValue();
    wxString wxConfigKey = CardConfKeyTB->GetValue();
    wxString wxLevel2SwitchKey = Level2SwitchKeyTB->GetValue();
    wxString wxLevel3SwitchKey = Level3SwitchKeyTB->GetValue();
    wxString wxSl1CardAuthKey = SL1CardAuthKeyTB->GetValue();
    wxString wxSelectVCKey = SelectVCKeyTB->GetValue();
    wxString wxProximityCheckKey = ProximityCheckKeyTB->GetValue();
    wxString wxVCPollingEncKey = VCPollingEncKeyTB->GetValue();
    wxString wxVCPollingMacKey = VCPollingMacKeyTB->GetValue();

    uint8_t master_key[16];
    uint8_t config_key[16];
    uint8_t l2_sw_key[16];
    uint8_t l3_sw_key[16];
    uint8_t l1_auth_key[16];
    uint8_t sel_vc_key[16];
    uint8_t prox_chk_key[16];
    uint8_t vc_poll_enc_key[16];
    uint8_t vc_poll_mac_key[16];

    uFR.ConvertToUint8Array((std::string)wxMasterKey, master_key);
    uFR.ConvertToUint8Array((std::string)wxConfigKey, config_key);
    uFR.ConvertToUint8Array((std::string)wxLevel2SwitchKey, l2_sw_key);
    uFR.ConvertToUint8Array((std::string)wxLevel3SwitchKey, l3_sw_key);
    uFR.ConvertToUint8Array((std::string)wxSl1CardAuthKey, l1_auth_key);
    uFR.ConvertToUint8Array((std::string)wxSelectVCKey, sel_vc_key);
    uFR.ConvertToUint8Array((std::string)wxProximityCheckKey, prox_chk_key);
    uFR.ConvertToUint8Array((std::string)wxVCPollingEncKey, vc_poll_enc_key);
    uFR.ConvertToUint8Array((std::string)wxVCPollingMacKey, vc_poll_mac_key);

    uint8_t dl_card_type;
	status = GetDlogicCardType(&dl_card_type);

	if(!(dl_card_type >= DL_MIFARE_PLUS_S_2K_SL0 && dl_card_type <= DL_MIFARE_PLUS_X_4K_SL0))
	{
		wxMessageBox("Card is not in security level 0 mode", _(""));
		return;
	}

    status = MFP_PersonalizationMinimal(master_key, config_key, l2_sw_key, l3_sw_key, l1_auth_key,
										sel_vc_key, prox_chk_key, vc_poll_enc_key, vc_poll_mac_key);

    if(!status){
        ReaderInfo->SetValue("Operation completed. Card successfully personalized.");
    }else{
        ReaderInfo->Clear();
    }

    StatusLabel->SetLabel((std::string)UFR_Status2String(status));
}

void mfp_wxwidgetsFrame::OnbAesAuthSL1Click1(wxCommandEvent& event)
{
    if(RBProvided->GetValue())
    {
        wxString wxSL1Key = SL1AuthKeyTB->GetValue();
        uint8_t sl1_auth_key[16];

        uFR.ConvertToUint8Array((std::string)wxSL1Key, sl1_auth_key);

        status = MFP_AesAuthSecurityLevel1_PK(sl1_auth_key);
    }
    else if(RBReader->GetValue())
    {
        uint8_t key_index = SL1RK->GetSelection();
        status = MFP_AesAuthSecurityLevel1(key_index);
    }

    if(!status){
        ReaderInfo->SetValue("Operation completed. AES authentication on SL1 successfully set.");
    }else{
        ReaderInfo->Clear();
    }

    StatusLabel->SetLabel((std::string)UFR_Status2String(status));
}

void mfp_wxwidgetsFrame::OnbSwitchToSL3Click(wxCommandEvent& event)
{
    if(RBProvided->GetValue())
    {
        wxString wxSL3Key = SwitchSL3KeyTB->GetValue();
        uint8_t sl3_sw_key[16];

        uFR.ConvertToUint8Array((std::string)wxSL3Key, sl3_sw_key);

        status = MFP_SwitchToSecurityLevel3_PK(sl3_sw_key);
    }
    else if(RBReader->GetValue())
    {
        uint8_t key_index = SL3RK->GetSelection();
        status = MFP_SwitchToSecurityLevel3(key_index);
    }

    if(!status){
        ReaderInfo->SetValue("Operation completed. Successfully switched to SL3.");
    }else{
        ReaderInfo->Clear();
    }

    StatusLabel->SetLabel((std::string)UFR_Status2String(status));
}

void mfp_wxwidgetsFrame::OnButton3Click(wxCommandEvent& event)
{
    if(RBProvided->GetValue())
    {
        wxString wxOldMaster = OldMasterTB->GetValue();
        wxString wxNewMaster = NewMasterTB->GetValue();

        uint8_t old_master_key[16];
        uint8_t new_master_key[16];

        uFR.ConvertToUint8Array((std::string)wxOldMaster, old_master_key);
        uFR.ConvertToUint8Array((std::string)wxNewMaster, new_master_key);

        status = MFP_ChangeMasterKey_PK(old_master_key, new_master_key);
    }
    else if(RBReader->GetValue())
    {
        uint8_t key_index = OldMasterIndex->GetSelection();
        wxString wxNewMasterRK = NewMasterRK->GetValue();
        uint8_t new_master_key[16];
        uFR.ConvertToUint8Array((std::string)wxNewMasterRK, new_master_key);

        status = MFP_ChangeMasterKey(key_index, new_master_key);
    }

    if(!status){
        ReaderInfo->SetValue("Operation completed. Master key successfully changed.");
    }else{
        ReaderInfo->Clear();
    }

    StatusLabel->SetLabel((std::string)UFR_Status2String(status));
}

void mfp_wxwidgetsFrame::OnButton4Click(wxCommandEvent& event)
{
    if(RBProvided->GetValue())
    {
        wxString wxOldConfig = OldConfigKeyTB->GetValue();
        wxString wxNewConfig = NewConfigKeyTB->GetValue();

        uint8_t old_config_key[16];
        uint8_t new_config_key[16];

        uFR.ConvertToUint8Array((std::string)wxOldConfig, old_config_key);
        uFR.ConvertToUint8Array((std::string)wxNewConfig, new_config_key);

        status = MFP_ChangeConfigurationKey_PK(old_config_key, new_config_key);
    }
    else
    {
        uint8_t key_index = OldConfigIndex->GetSelection();
        uint8_t new_config_key[16];

        wxString wxNewConfigRK = NewConfigKeyRK->GetValue();

        uFR.ConvertToUint8Array((std::string)wxNewConfigRK, new_config_key);

        status = MFP_ChangeConfigurationKey(key_index, new_config_key);
    }

    if(!status){
        ReaderInfo->SetValue("Operation completed. Configuration key successfully changed.");
    }else{
        ReaderInfo->Clear();
    }

    StatusLabel->SetLabel((std::string)UFR_Status2String(status));
}

void mfp_wxwidgetsFrame::OnbSetFieldConfigurationClick(wxCommandEvent& event)
{
    uint8_t rid_use;

    if(RB_UseRandomID->GetValue())
    {
        rid_use = 1;
    }
    else if(RB_UseUID->GetValue())
    {
        rid_use = 0;
    }

    if(RBProvided->GetValue())
    {
        wxString wxConf = FieldConfKeyTB->GetValue();
        uint8_t config_key[16];

        uFR.ConvertToUint8Array((std::string)wxConf, config_key);

        status = MFP_FieldConfigurationSet_PK(config_key, rid_use, 0);
    }
    else if(RBReader->GetValue())
    {
        uint8_t key_index = FieldConfKeyIndex->GetSelection();
        status = MFP_FieldConfigurationSet(key_index, rid_use, 0);
    }

    if(!status){
        ReaderInfo->SetValue("Operation completed. Field configuration successfully set.");
    }else{
        ReaderInfo->Clear();
    }

    StatusLabel->SetLabel((std::string)UFR_Status2String(status));
}

void mfp_wxwidgetsFrame::OnbGetENCMACUidClick(wxCommandEvent& event)
{
    uint8_t uid[10];
    uint8_t uid_len;

    if(RBProvided->GetValue())
    {
        wxString wxENC = ENCKeyTB->GetValue();
        wxString wxMAC = MACKeyTB->GetValue();

        uint8_t vc_enc_key[16];
        uint8_t vc_mac_key[16];

        uFR.ConvertToUint8Array((std::string)wxENC, vc_enc_key);
        uFR.ConvertToUint8Array((std::string)wxMAC, vc_mac_key);

        status = MFP_GetUid_PK(vc_enc_key, vc_mac_key, uid, &uid_len);
    }
    else if(RBReader->GetValue())
    {
        uint8_t key_index_enc = ENCKeyIndex->GetSelection();
        uint8_t key_index_mac = MACKeyIndex->GetSelection();

        status = MFP_GetUid(key_index_enc, key_index_mac, uid, &uid_len);
    }

    if(!status){
        ReaderInfo->SetValue("Operation completed.");
        ENCMACUidTB->SetValue(uFR.ConvertUint8ArrayToStr(uid, uid_len, " "));
    }else{
        ReaderInfo->Clear();
        ENCMACUidTB->Clear();
    }

    StatusLabel->SetLabel((std::string)UFR_Status2String(status));
}

void mfp_wxwidgetsFrame::OnbChangeVCPollingENCKeyClick(wxCommandEvent& event)
{
    if(RBProvided->GetValue())
    {
        wxString wxConfKey = CardConfigurationKeyTB->GetValue();
        wxString wxVCKey = NewVCPollingENCKeyTB->GetValue();
        uint8_t new_vc_enc_key[16];
        uint8_t config_key[16];

        uFR.ConvertToUint8Array((std::string)wxConfKey, config_key);
        uFR.ConvertToUint8Array((std::string)wxVCKey, new_vc_enc_key);

        status = MFP_ChangeVcPollingEncKey_PK(config_key, new_vc_enc_key);
    }
    else if(RBReader->GetValue())
    {
        uint8_t key_index = ConfRK->GetSelection();
        wxString wxNewKey = NewVCPollingENCKeyRK->GetValue();
        uint8_t new_vc_enc_key[16];

        uFR.ConvertToUint8Array((std::string)wxNewKey, new_vc_enc_key);

        status = MFP_ChangeVcPollingEncKey(key_index, new_vc_enc_key);
    }

    if(!status){
        ReaderInfo->SetValue("Operation completed. VC polling ENC key successfully changed.");
    }else{
        ReaderInfo->Clear();
    }

    StatusLabel->SetLabel((std::string)UFR_Status2String(status));
}

void mfp_wxwidgetsFrame::OnbChangeVCpolingMACKeyClick(wxCommandEvent& event)
{
    if(RBProvided->GetValue())
    {
        wxString wxConf = CurrentConfKeyTB->GetValue();
        wxString wxNewMac = NewMACTB->GetValue();

        uint8_t config_key[16];
        uint8_t new_vc_mac_key[16];

        uFR.ConvertToUint8Array((std::string)wxConf, config_key);
        uFR.ConvertToUint8Array((std::string)wxNewMac, new_vc_mac_key);

        status = MFP_ChangeVcPollingMacKey_PK(config_key, new_vc_mac_key);
    }
    else if(RBReader->GetValue())
    {
        uint8_t key_index = CurrentConfIndex->GetSelection();
        uint8_t new_vc_mac_key[16];
        wxString wxNewMac = NewMACTB_RK->GetValue();

        uFR.ConvertToUint8Array((std::string)wxNewMac, new_vc_mac_key);

        status = MFP_ChangeVcPollingMacKey(key_index, new_vc_mac_key);
    }

    if(!status){
        ReaderInfo->SetValue("Operation completed. VC polling MAC key successfully changed.");
    }else{
        ReaderInfo->Clear();
    }

    StatusLabel->SetLabel((std::string)UFR_Status2String(status));
}

void mfp_wxwidgetsFrame::OnbWriteCrypto1Click(wxCommandEvent& event)
{
    wxString wxCrypto1 = Crypto1TB->GetValue();
    uint8_t key_index = Crypto1Index->GetSelection();
    uint8_t crypto_1_key[16];

    uFR.ConvertToUint8Array((std::string)wxCrypto1, crypto_1_key);

    status = ReaderKeyWrite(crypto_1_key, key_index);

    if(!status){
        ReaderInfo->SetValue("Operation completed. CRYPTO 1 key successfully written.");
    }else{
        ReaderInfo->Clear();
    }

    StatusLabel->SetLabel((std::string)UFR_Status2String(status));
}


void mfp_wxwidgetsFrame::OnbWriteAESClick(wxCommandEvent& event)
{
    wxString wxAes = AES_TB->GetValue();
    uint8_t key_index = AES_Index -> GetSelection();
    uint8_t aes_key[16];

    uFR.ConvertToUint8Array((std::string)wxAes, aes_key);

    status = uFR_int_DesfireWriteAesKey(key_index, aes_key);

    if(!status){
        ReaderInfo->SetValue("Operation completed. AES key successfully written.");
    }else{
        ReaderInfo->Clear();
    }

    StatusLabel->SetLabel((std::string)UFR_Status2String(status));
}

void mfp_wxwidgetsFrame::OnbUnlockKeysClick(wxCommandEvent& event)
{
    wxString pass = UnlockKeysTB->GetValue();

    status = ReaderKeysUnlock(pass.c_str());

    if(!status){
        ReaderInfo->SetValue("Operation completed. Keys unlocked.");
    }else{
        ReaderInfo->Clear();
    }

    StatusLabel->SetLabel((std::string)UFR_Status2String(status));
}

void mfp_wxwidgetsFrame::OnbLockKeysClick(wxCommandEvent& event)
{
    wxString pass = UnlockKeysTB->GetValue();

    status = ReaderKeysLock(pass.c_str());

    if(!status){
        ReaderInfo->SetValue("Operation completed. Keys locked.");
    }else{
        ReaderInfo->Clear();
    }

    StatusLabel->SetLabel((std::string)UFR_Status2String(status));
}

void mfp_wxwidgetsFrame::OnbBRProvidedKeyClick(wxCommandEvent& event)
{
    uint8_t dl_card_type;
    uint8_t block_data[16];
    uint8_t block_nr, auth_mode;
    uint8_t crypto_1_sector_key[6], aes_sector_key[16];
    status = GetDlogicCardType(&dl_card_type);

    if((dl_card_type >= DL_MIFARE_PLUS_S_2K_SL1 && dl_card_type <= DL_MIFARE_PLUS_EV1_2K_SL1)
			|| (dl_card_type >= DL_MIFARE_PLUS_S_4K_SL1 && dl_card_type <= DL_MIFARE_PLUS_EV1_4K_SL1))
    {
        if(BR_Provided_A->GetValue())
        {
            auth_mode = MIFARE_AUTHENT1A;
        }
        else if(BR_Provided_B->GetValue())
        {
            auth_mode = MIFARE_AUTHENT1B;
        }

        wxString wxKey = BR_Key->GetValue();

        if(wxKey.Length() != 12)
        {
            wxMessageBox("Card type is : " + uFR.GetDlTypeName(dl_card_type) + ". Key must be 6 bytes long- CRYPTO 1 key");
            ReaderInfo->Clear();
            return;
        }

        block_nr = BR_BlockNr->GetSelection();
        uFR.ConvertToUint8Array((std::string)wxKey, crypto_1_sector_key);
        status = BlockRead_PK(block_data, block_nr, auth_mode, crypto_1_sector_key);

    }
    else
    {
        if(BR_Provided_A->GetValue())
        {
            auth_mode = MIFARE_PLUS_AES_AUTHENT1A;
        }
        else if(BR_Provided_B->GetValue())
        {
            auth_mode = MIFARE_PLUS_AES_AUTHENT1B;
        }

        wxString wxKey = BR_Key->GetValue();

        if(wxKey.Length() != 32)
        {
            wxMessageBox("Card type is : " + uFR.GetDlTypeName(dl_card_type) + ". Key must be 16 bytes long - AES key");
            ReaderInfo->Clear();
            return;
        }

        block_nr = BR_BlockNr->GetSelection();
        uFR.ConvertToUint8Array((std::string)wxKey, aes_sector_key);
        status = BlockRead_PK(block_data, block_nr, auth_mode, aes_sector_key);

    }

    if(!status){
        ReaderInfo->SetValue("Operation completed. Block data :\n" + uFR.ConvertUint8ArrayToStr(block_data, 16, " "));
    }else{
        ReaderInfo->Clear();
    }

    StatusLabel->SetLabel((std::string)UFR_Status2String(status));
}

void mfp_wxwidgetsFrame::OnbBRReaderKeyClick(wxCommandEvent& event)
{
    uint8_t auth_mode;
    uint8_t block_data[16];
    uint8_t block_nr;
    uint8_t key_index;

    if(BR_Reader_KeyA->GetValue())
    {
        auth_mode = MIFARE_AUTHENT1A;
    }
    else if(BR_Reader_KeyB->GetValue())
    {
        auth_mode = MIFARE_AUTHENT1B;
    }

    block_nr = BR_Reader_BlockNr->GetSelection();
    key_index = BR_Reader_KeyIndex->GetSelection();

    status = BlockRead(block_data, block_nr, auth_mode, key_index);

    if(!status){
        ReaderInfo->SetValue("Operation completed. Block data :\n" + uFR.ConvertUint8ArrayToStr(block_data, 16, " "));
    }else{
        ReaderInfo->Clear();
    }

    StatusLabel->SetLabel((std::string)UFR_Status2String(status));
}

void mfp_wxwidgetsFrame::OnbBRAKM1Click(wxCommandEvent& event)
{
    uint8_t auth_mode;
    uint8_t block_nr;
    uint8_t block_data[16];

    if(BR_AKM1_KeyA->GetValue())
    {
        auth_mode = MIFARE_AUTHENT1A;
    }
    else if(BR_AKM1_KeyB->GetValue())
    {
        auth_mode = MIFARE_AUTHENT1B;
    }

    block_nr = BR_AKM1_BlockNR->GetSelection();

    status = BlockRead_AKM1(block_data, block_nr, auth_mode);

    if(!status){
        ReaderInfo->SetValue("Operation completed. Block data :\n" + uFR.ConvertUint8ArrayToStr(block_data, 16, " "));
    }else{
        ReaderInfo->Clear();
    }

    StatusLabel->SetLabel((std::string)UFR_Status2String(status));
}

void mfp_wxwidgetsFrame::OnbBRAKM2Click(wxCommandEvent& event)
{
    uint8_t auth_mode;
    uint8_t block_nr;
    uint8_t block_data[16];

    if(BR_AKM2_KeyA->GetValue())
    {
        auth_mode = MIFARE_AUTHENT1A;
    }
    else if(BR_AKM2_KeyB->GetValue())
    {
        auth_mode = MIFARE_AUTHENT1B;
    }

    block_nr = BR_AKM2_BlockNR->GetSelection();

    status = BlockRead_AKM2(block_data, block_nr, auth_mode);

    if(!status){
        ReaderInfo->SetValue("Operation completed. Block data :\n" + uFR.ConvertUint8ArrayToStr(block_data, 16, " "));
    }else{
        ReaderInfo->Clear();
    }

    StatusLabel->SetLabel((std::string)UFR_Status2String(status));
}

void mfp_wxwidgetsFrame::OnbBSRProvidedKeyClick(wxCommandEvent& event)
{
    uint8_t dl_card_type;
    uint8_t block_data[16];
    uint8_t block_nr, auth_mode, sector_nr;
    uint8_t crypto_1_sector_key[6], aes_sector_key[16];

    status = GetDlogicCardType(&dl_card_type);

    if((dl_card_type >= DL_MIFARE_PLUS_S_2K_SL1 && dl_card_type <= DL_MIFARE_PLUS_EV1_2K_SL1)
			|| (dl_card_type >= DL_MIFARE_PLUS_S_4K_SL1 && dl_card_type <= DL_MIFARE_PLUS_EV1_4K_SL1))
    {
        if(BSR_Provided_KeyA->GetValue())
        {
            auth_mode = MIFARE_AUTHENT1A;
        }
        else if(BSR_Provided_KeyB->GetValue())
        {
            auth_mode = MIFARE_AUTHENT1B;
        }

        wxString wxKey = BSR_Key->GetValue();

        if(wxKey.Length() != 12)
        {
            wxMessageBox("Card type is : " + uFR.GetDlTypeName(dl_card_type) + ". Key must be 6 bytes long - CRYPTO 1 key");
            ReaderInfo->Clear();
            return;
        }

        uFR.ConvertToUint8Array((std::string)wxKey, crypto_1_sector_key);
        block_nr = BSR_BlockNr->GetSelection();
        sector_nr = BSR_SectorNr->GetSelection();

        status = BlockInSectorRead_PK(block_data, sector_nr, block_nr, auth_mode, crypto_1_sector_key);

    }
    else
    {
        if(BSR_Provided_KeyA->GetValue())
        {
            auth_mode = MIFARE_PLUS_AES_AUTHENT1A;
        }
        else if(BSR_Provided_KeyB->GetValue())
        {
            auth_mode = MIFARE_PLUS_AES_AUTHENT1B;
        }

        wxString wxKey = BSR_Key->GetValue();

        if(wxKey.Length() != 32)
        {
            wxMessageBox("Card type is : " + uFR.GetDlTypeName(dl_card_type) + ". Key must be 6 bytes long - AES key");
            ReaderInfo->Clear();
            return;
        }

        uFR.ConvertToUint8Array((std::string)wxKey, aes_sector_key);
        block_nr = BSR_BlockNr->GetSelection();
        sector_nr = BSR_SectorNr->GetSelection();

        status = BlockInSectorRead_PK(block_data, sector_nr, block_nr, auth_mode, aes_sector_key);
    }

    if(!status){
        ReaderInfo->SetValue("Operation completed. Block data :\n" + uFR.ConvertUint8ArrayToStr(block_data, 16, " "));
    }else{
        ReaderInfo->Clear();
    }

    StatusLabel->SetLabel((std::string)UFR_Status2String(status));
}

void mfp_wxwidgetsFrame::OnbBSRReaderClick(wxCommandEvent& event)
{
    uint8_t block_data[16];
    uint8_t block_nr, auth_mode, sector_nr;
    uint8_t key_index;

    if(BSR_Reader_KeyA->GetValue())
    {
        auth_mode = MIFARE_AUTHENT1A;
    }
    else if(BSR_Reader_KeyB->GetValue())
    {
        auth_mode = MIFARE_AUTHENT1B;
    }

    block_nr = BSR_Reader_BlockNR->GetSelection();
    sector_nr = BSR_Reader_SectorNr->GetSelection();
    key_index = BSR_Reader_KeyIndex->GetSelection();

    status = BlockInSectorRead(block_data, sector_nr, block_nr, auth_mode, key_index);

    if(!status){
        ReaderInfo->SetValue("Operation completed. Block data :\n" + uFR.ConvertUint8ArrayToStr(block_data, 16, " "));
    }else{
        ReaderInfo->Clear();
    }

    StatusLabel->SetLabel((std::string)UFR_Status2String(status));
}

void mfp_wxwidgetsFrame::OnbBSRAKM1Click(wxCommandEvent& event)
{
    uint8_t block_data[16];
    uint8_t block_nr, auth_mode, sector_nr;

    if(BSR_AKM1_KeyA->GetValue())
    {
        auth_mode = MIFARE_AUTHENT1A;
    }
    else if(BSR_AKM1_KeyB->GetValue())
    {
        auth_mode = MIFARE_AUTHENT1B;
    }

    block_nr = BSR_AKM1_BlockNr->GetSelection();
    sector_nr = BSR_AKM1_SectorNr->GetSelection();

    status = BlockInSectorRead_AKM1(block_data, sector_nr, block_nr, auth_mode);

    if(!status){
        ReaderInfo->SetValue("Operation completed. Block data :\n" + uFR.ConvertUint8ArrayToStr(block_data, 16, " "));
    }else{
        ReaderInfo->Clear();
    }

    StatusLabel->SetLabel((std::string)UFR_Status2String(status));
}



void mfp_wxwidgetsFrame::OnbBSRAKM2Click(wxCommandEvent& event)
{
    uint8_t block_data[16];
    uint8_t block_nr, auth_mode, sector_nr;

    if(BSR_AKM2_KeyA->GetValue())
    {
        auth_mode = MIFARE_AUTHENT1A;
    }
    else if(BSR_AKM2_KeyB->GetValue())
    {
        auth_mode = MIFARE_AUTHENT1B;
    }

    block_nr = BSR_AKM2_BlockNr->GetSelection();
    sector_nr = BSR_AKM2_SectorNr->GetSelection();

    status = BlockInSectorRead_AKM2(block_data, sector_nr, block_nr, auth_mode);

    if(!status){
        ReaderInfo->SetValue("Operation completed. Block data :\n" + uFR.ConvertUint8ArrayToStr(block_data, 16, " "));
    }else{
        ReaderInfo->Clear();
    }

    StatusLabel->SetLabel((std::string)UFR_Status2String(status));
}

void mfp_wxwidgetsFrame::OnbLRProvidedClick(wxCommandEvent& event)
{
    uint8_t auth_mode;
    uint8_t dl_card_type;
    uint8_t crypto_1_sector_key[6];
    uint8_t aes_sector_key[16];
    uint8_t linear_data[3440];
	uint16_t lin_addr, lin_len, ret_bytes;

    status = GetDlogicCardType(&dl_card_type);

    if((dl_card_type >= DL_MIFARE_PLUS_S_2K_SL1 && dl_card_type <= DL_MIFARE_PLUS_EV1_2K_SL1)
        || (dl_card_type >= DL_MIFARE_PLUS_S_4K_SL1 && dl_card_type <= DL_MIFARE_PLUS_EV1_4K_SL1))
    {
        if(LR_Provided_KeyA->GetValue())
        {
            auth_mode = MIFARE_AUTHENT1A;
        }
        else if(LR_Provided_KeyB->GetValue())
        {
            auth_mode = MIFARE_AUTHENT1B;
        }

        wxString wxKey = LR_Key->GetValue();

        if(wxKey.Length() != 12)
        {
            wxMessageBox("Card type is : " + uFR.GetDlTypeName(dl_card_type) + ". Key must be 6 bytes long - AES key");
            ReaderInfo->Clear();
            return;
        }

        uFR.ConvertToUint8Array((std::string)wxKey, crypto_1_sector_key);
        lin_addr = wxAtoi(LR_ProvidedAddr->GetValue());
        lin_len = wxAtoi(LR_Provided_Bytes->GetValue());

        status = LinearRead_PK(linear_data, lin_addr, lin_len, &ret_bytes, auth_mode, crypto_1_sector_key);
    }
    else
    {
        if(LR_Provided_KeyA->GetValue())
        {
            auth_mode = MIFARE_PLUS_AES_AUTHENT1A;
        }
        else if(LR_Provided_KeyB->GetValue())
        {
            auth_mode = MIFARE_PLUS_AES_AUTHENT1B;
        }

        wxString wxKey = LR_Key->GetValue();

        if(wxKey.Length() != 32)
        {
            wxMessageBox("Card type is : " + uFR.GetDlTypeName(dl_card_type) + ". Key must be 16 bytes long - AES key");
            ReaderInfo->Clear();
            return;
        }

        uFR.ConvertToUint8Array((std::string)wxKey, aes_sector_key);
        lin_addr = wxAtoi(LR_ProvidedAddr->GetValue());
        lin_len = wxAtoi(LR_Provided_Bytes->GetValue());

        status = LinearRead_PK(linear_data, lin_addr, lin_len, &ret_bytes, auth_mode, aes_sector_key);
    }

    wxString wxLen = "";
    wxLen << ret_bytes;

    if(!status){
        ReaderInfo->SetValue("Operation completed. Data [" + wxLen + " bytes] : \n" + uFR.ConvertUint8ArrayToStr(linear_data, ret_bytes, " "));
    }else{
        ReaderInfo->Clear();
    }

    StatusLabel->SetLabel((std::string)UFR_Status2String(status));
}

void mfp_wxwidgetsFrame::OnbLRReaderClick(wxCommandEvent& event)
{
    uint8_t auth_mode;
    uint8_t linear_data[3440];
	uint16_t lin_addr, lin_len, ret_bytes;
	uint8_t key_index;

    if(LR_Reader_KeyA->GetValue())
    {
        auth_mode = MIFARE_AUTHENT1A;
    }
    else if(LR_Reader_KeyB->GetValue())
    {
        auth_mode = MIFARE_AUTHENT1B;
    }

    lin_addr = wxAtoi(LR_ReaderAddr->GetValue());
    lin_len = wxAtoi(LR_ReaderBytes->GetValue());
    key_index = LR_ReaderKeyIndex->GetSelection();

    status = LinearRead(linear_data, lin_addr, lin_len, &ret_bytes, auth_mode, key_index);

    wxString wxLen = "";
    wxLen << ret_bytes;

    if(!status){
        ReaderInfo->SetValue("Operation completed. Data [" + wxLen + " bytes] : \n" + uFR.ConvertUint8ArrayToStr(linear_data, ret_bytes, " "));
    }else{
        ReaderInfo->Clear();
    }

    StatusLabel->SetLabel((std::string)UFR_Status2String(status));
}

void mfp_wxwidgetsFrame::OnbLRAKM1Click(wxCommandEvent& event)
{
    uint8_t auth_mode;
    uint8_t linear_data[3440];
	uint16_t lin_addr, lin_len, ret_bytes;

    if(LR_AKM1_KeyA->GetValue())
    {
        auth_mode = MIFARE_AUTHENT1A;
    }
    else if(LR_AKM1_KeyB->GetValue())
    {
        auth_mode = MIFARE_AUTHENT1B;
    }

    lin_addr = wxAtoi(LR_AKM1_Addr->GetValue());
    lin_len = wxAtoi(LR_AKM1_Bytes->GetValue());

    status = LinearRead_AKM1(linear_data, lin_addr, lin_len, &ret_bytes, auth_mode);

    wxString wxLen = "";
    wxLen << ret_bytes;

    if(!status){
        ReaderInfo->SetValue("Operation completed. Data [" + wxLen + " bytes] : \n" + uFR.ConvertUint8ArrayToStr(linear_data, ret_bytes, " "));
    }else{
        ReaderInfo->Clear();
    }

    StatusLabel->SetLabel((std::string)UFR_Status2String(status));
}

void mfp_wxwidgetsFrame::OnbLRAKM2Click(wxCommandEvent& event)
{
    uint8_t auth_mode;
    uint8_t linear_data[3440];
	uint16_t lin_addr, lin_len, ret_bytes;

    if(LR_AKM2_KeyA->GetValue())
    {
        auth_mode = MIFARE_AUTHENT1A;
    }
    else if(LR_AKM2_KeyB->GetValue())
    {
        auth_mode = MIFARE_AUTHENT1B;
    }

    lin_addr = wxAtoi(LR_AKM2_Addr->GetValue());
    lin_len = wxAtoi(LR_AKM2_Bytes->GetValue());

    status = LinearRead_AKM2(linear_data, lin_addr, lin_len, &ret_bytes, auth_mode);

    wxString wxLen = "";
    wxLen << ret_bytes;

    if(!status){
        ReaderInfo->SetValue("Operation completed. Data [" + wxLen + " bytes] : \n" + uFR.ConvertUint8ArrayToStr(linear_data, ret_bytes, " "));
    }else{
        ReaderInfo->Clear();
    }

    StatusLabel->SetLabel((std::string)UFR_Status2String(status));
}

void mfp_wxwidgetsFrame::OnbBWProvidedKeyClick(wxCommandEvent& event)
{
    uint8_t dl_card_type;
    uint8_t block_data[16];
    uint8_t block_nr, auth_mode;
    uint8_t crypto_1_sector_key[6], aes_sector_key[16];
    status = GetDlogicCardType(&dl_card_type);

    memset(block_data, 0, 16);

    if((dl_card_type >= DL_MIFARE_PLUS_S_2K_SL1 && dl_card_type <= DL_MIFARE_PLUS_EV1_2K_SL1)
			|| (dl_card_type >= DL_MIFARE_PLUS_S_4K_SL1 && dl_card_type <= DL_MIFARE_PLUS_EV1_4K_SL1))
    {
        if(BW_Provided_KeyA->GetValue())
        {
            auth_mode = MIFARE_AUTHENT1A;
        }
        else if(BW_Provided_KeyB->GetValue())
        {
            auth_mode = MIFARE_AUTHENT1B;
        }

        wxString wxKey = BW_Provided_Key->GetValue();

        if(wxKey.Length() != 12){
            wxMessageBox("Card type is " + uFR.GetDlTypeName(dl_card_type) + " . Key must be 6 bytes long - CRYPTO 1 key");
            return;
        }

        uFR.ConvertToUint8Array((std::string)wxKey, crypto_1_sector_key);

        block_nr = BW_Provided_BlockNr->GetSelection();

        wxString wxBlockData = WriteDataTB->GetValue();

        if(wxBlockData.Length() > 32){
            wxMessageBox("Block data must be 16 bytes long or less");
            return;
        }

        uFR.ConvertToUint8Array((std::string)wxBlockData, block_data);

        status = BlockWrite_PK(block_data, block_nr, auth_mode, crypto_1_sector_key);
    }
    else
    {
        if(BW_Provided_KeyA->GetValue())
        {
            auth_mode = MIFARE_PLUS_AES_AUTHENT1A;
        }
        else if(BW_Provided_KeyB->GetValue())
        {
            auth_mode = MIFARE_PLUS_AES_AUTHENT1B;
        }

        wxString wxKey = BW_Provided_Key->GetValue();

        if(wxKey.Length() != 32){
            wxMessageBox("Card type is " + uFR.GetDlTypeName(dl_card_type) + " . Key must be 16 bytes long- AES key");
            return;
        }

        uFR.ConvertToUint8Array((std::string)wxKey, aes_sector_key);

        block_nr = BW_Provided_BlockNr->GetSelection();

        wxString wxBlockData = WriteDataTB->GetValue();

        if(wxBlockData.Length() > 32){
            wxMessageBox("Block data must be 16 bytes long or less");
            return;
        }

        uFR.ConvertToUint8Array((std::string)wxBlockData, block_data);

        status = BlockWrite_PK(block_data, block_nr, auth_mode, aes_sector_key);

    }

    if(!status){
        ReaderInfo->SetValue("Operation completed. Block written.");
    }else{
        ReaderInfo->Clear();
    }

    StatusLabel->SetLabel((std::string)UFR_Status2String(status));
}

void mfp_wxwidgetsFrame::OnbBWReaderKeyClick(wxCommandEvent& event)
{
    uint8_t block_data[16];
    uint8_t block_nr, auth_mode;
    uint8_t key_index;

    memset(block_data, 0, 16);

     if(BW_Reader_KeyA->GetValue())
     {
        auth_mode = MIFARE_AUTHENT1A;
     }
     else if(BW_Reader_KeyB->GetValue())
     {
        auth_mode = MIFARE_AUTHENT1B;
     }

     block_nr = BW_Reader_BlockNr->GetSelection();
     key_index = BW_Reader_KeyIndex->GetSelection();

     wxString wxBlockData = WriteDataTB->GetValue();

     if(wxBlockData.Length() > 32){
        wxMessageBox("Block data must be 16 bytes long or less");
        return;
     }

     uFR.ConvertToUint8Array((std::string)wxBlockData, block_data);

     status = BlockWrite(block_data, block_nr, auth_mode, key_index);

     if(!status){
        ReaderInfo->SetValue("Operation completed. Block written.");
    }else{
        ReaderInfo->Clear();
    }

    StatusLabel->SetLabel((std::string)UFR_Status2String(status));
}

void mfp_wxwidgetsFrame::OnbBWAKM1KeyClick(wxCommandEvent& event)
{
    uint8_t block_data[16];
    uint8_t block_nr, auth_mode;

    memset(block_data, 0, 16);

     if(BW_AKM1_KeyA->GetValue())
     {
        auth_mode = MIFARE_AUTHENT1A;
     }
     else if(BW_AKM1_KeyB->GetValue())
     {
        auth_mode = MIFARE_AUTHENT1B;
     }

     block_nr = BW_AKM1_BlockNr->GetSelection();

     wxString wxBlockData = WriteDataTB->GetValue();

     if(wxBlockData.Length() > 32){
        wxMessageBox("Block data must be 16 bytes long or less");
        return;
     }

     uFR.ConvertToUint8Array((std::string)wxBlockData, block_data);

     status = BlockWrite_AKM1(block_data, block_nr, auth_mode);

    if(!status){
        ReaderInfo->SetValue("Operation completed. Block written.");
    }else{
        ReaderInfo->Clear();
    }

    StatusLabel->SetLabel((std::string)UFR_Status2String(status));
}

void mfp_wxwidgetsFrame::OnbBWAKM2KeyClick(wxCommandEvent& event)
{
    uint8_t block_data[16];
    uint8_t block_nr, auth_mode;

    memset(block_data, 0, 16);

     if(BW_AKM2_KeyA->GetValue())
     {
        auth_mode = MIFARE_AUTHENT1A;
     }
     else if(BW_AKM2_KeyB->GetValue())
     {
        auth_mode = MIFARE_AUTHENT1B;
     }

     block_nr = BW_AKM2_BlockNr->GetSelection();

     wxString wxBlockData = WriteDataTB->GetValue();

     if(wxBlockData.Length() > 32){
        wxMessageBox("Block data must be 16 bytes long or less");
        return;
     }

     uFR.ConvertToUint8Array((std::string)wxBlockData, block_data);

     status = BlockWrite_AKM2(block_data, block_nr, auth_mode);

    if(!status){
        ReaderInfo->SetValue("Operation completed. Block successfully written.");
    }else{
        ReaderInfo->Clear();
    }

    StatusLabel->SetLabel((std::string)UFR_Status2String(status));
}

void mfp_wxwidgetsFrame::OnbBSWProvidedKeyClick(wxCommandEvent& event)
{
    uint8_t dl_card_type;
    uint8_t block_data[16];
    uint8_t block_nr, auth_mode, sector_nr;
    uint8_t crypto_1_sector_key[6], aes_sector_key[16];

    memset(block_data, 0, 16);

    status = GetDlogicCardType(&dl_card_type);

    if((dl_card_type >= DL_MIFARE_PLUS_S_2K_SL1 && dl_card_type <= DL_MIFARE_PLUS_EV1_2K_SL1)
			|| (dl_card_type >= DL_MIFARE_PLUS_S_4K_SL1 && dl_card_type <= DL_MIFARE_PLUS_EV1_4K_SL1))
    {
        if(BSW_Provided_KeyA->GetValue())
        {
            auth_mode = MIFARE_AUTHENT1A;
        }
        else if(BSW_Provided_KeyB->GetValue())
        {
            auth_mode = MIFARE_AUTHENT1B;
        }

        wxString wxKey = BSW_Provided_Key->GetValue();

        if(wxKey.Length() != 12){
            wxMessageBox("Card type is " + uFR.GetDlTypeName(dl_card_type) + " . Key must be 6 bytes long - CRYPTO 1 key");
            return;
        }

        uFR.ConvertToUint8Array((std::string)wxKey, crypto_1_sector_key);

        block_nr = BSW_Provided_BlockNr->GetSelection();
        sector_nr = BSW_Provided_SectorNr->GetSelection();

        wxString wxBlockData = WriteDataTB->GetValue();

        if(wxBlockData.Length() > 32){
            wxMessageBox("Block data must be 16 bytes long or less");
            return;
        }

        uFR.ConvertToUint8Array((std::string)wxBlockData, block_data);

        status = BlockInSectorWrite_PK(block_data, sector_nr, block_nr, auth_mode, crypto_1_sector_key);
    }
    else
    {
        if(BSW_Provided_KeyA->GetValue())
        {
            auth_mode = MIFARE_PLUS_AES_AUTHENT1A;
        }
        else if(BSW_Provided_KeyB->GetValue())
        {
            auth_mode = MIFARE_PLUS_AES_AUTHENT1B;
        }

        wxString wxKey = BSW_Provided_Key->GetValue();

        if(wxKey.Length() != 32){
            wxMessageBox("Card type is " + uFR.GetDlTypeName(dl_card_type) + " . Key must be 16 bytes long - AES key");
            return;
        }

        uFR.ConvertToUint8Array((std::string)wxKey, aes_sector_key);

        block_nr = BSW_Provided_BlockNr->GetSelection();
        sector_nr = BSW_Provided_SectorNr->GetSelection();

        wxString wxBlockData = WriteDataTB->GetValue();

        if(wxBlockData.Length() > 32){
            wxMessageBox("Block data must be 16 bytes long or less");
            return;
        }

        uFR.ConvertToUint8Array((std::string)wxBlockData, block_data);

        status = BlockInSectorWrite_PK(block_data, sector_nr, block_nr, auth_mode, aes_sector_key);
    }

    if(!status){
        ReaderInfo->SetValue("Operation completed. Block in sector successfully written.");
    }else{
        ReaderInfo->Clear();
    }

    StatusLabel->SetLabel((std::string)UFR_Status2String(status));
}

void mfp_wxwidgetsFrame::OnbBSWReaderKeyClick(wxCommandEvent& event)
{
    uint8_t key_index;
    uint8_t block_data[16];
    uint8_t block_nr, auth_mode, sector_nr;

    if(BSW_Reader_KeyA->GetValue())
    {
        auth_mode = MIFARE_AUTHENT1A;
    }
    else if(BSW_Reader_KeyB->GetValue())
    {
        auth_mode = MIFARE_AUTHENT1B;
    }

    block_nr = BSW_Reader_BlockNr->GetSelection();
    sector_nr = BSW_Reader_SectorNr->GetSelection();
    key_index = BSW_Reader_KeyIndex->GetSelection();

    wxString wxBlockData = WriteDataTB->GetValue();

    if(wxBlockData.Length() > 32){
        wxMessageBox("Block data must be 16 bytes long or less");
        return;
    }

    uFR.ConvertToUint8Array((std::string)wxBlockData, block_data);

    status = BlockInSectorWrite(block_data, sector_nr, block_nr, auth_mode, key_index);

    if(!status){
        ReaderInfo->SetValue("Operation completed. Block in sector successfully written.");
    }else{
        ReaderInfo->Clear();
    }

    StatusLabel->SetLabel((std::string)UFR_Status2String(status));
}

void mfp_wxwidgetsFrame::OnbBSWAKM1KeyClick(wxCommandEvent& event)
{
    uint8_t block_data[16];
    uint8_t block_nr, auth_mode, sector_nr;

    if(BSW_AKM1_KeyA->GetValue())
    {
        auth_mode = MIFARE_AUTHENT1A;
    }
    else if(BSW_AKM1_KeyB->GetValue())
    {
        auth_mode = MIFARE_AUTHENT1B;
    }

    block_nr = BSW_AKM1_BlockNr->GetSelection();
    sector_nr = BSW_AKM1_SectorNr->GetSelection();

    wxString wxBlockData = WriteDataTB->GetValue();

    if(wxBlockData.Length() > 32){
        wxMessageBox("Block data must be 16 bytes long or less");
        return;
    }

    uFR.ConvertToUint8Array((std::string)wxBlockData, block_data);

    status = BlockInSectorWrite_AKM1(block_data, sector_nr, block_nr, auth_mode);

    if(!status){
        ReaderInfo->SetValue("Operation completed. Block in sector successfully written.");
    }else{
        ReaderInfo->Clear();
    }

    StatusLabel->SetLabel((std::string)UFR_Status2String(status));
}

void mfp_wxwidgetsFrame::OnbBSWAKM2KeyClick(wxCommandEvent& event)
{
    uint8_t block_data[16];
    uint8_t block_nr, auth_mode, sector_nr;

    if(BSW_AKM2_KeyA->GetValue())
    {
        auth_mode = MIFARE_AUTHENT1A;
    }
    else if(BSW_AKM2_KeyB->GetValue())
    {
        auth_mode = MIFARE_AUTHENT1B;
    }

    block_nr = BSW_AKM2_BlockNr->GetSelection();
    sector_nr = BSW_AKM2_SectorNr->GetSelection();

    wxString wxBlockData = WriteDataTB->GetValue();

    if(wxBlockData.Length() > 32){
        wxMessageBox("Block data must be 16 bytes long or less");
        return;
    }

    uFR.ConvertToUint8Array((std::string)wxBlockData, block_data);

    status = BlockInSectorWrite_AKM2(block_data, sector_nr, block_nr, auth_mode);

    if(!status){
        ReaderInfo->SetValue("Operation completed. Block in sector successfully written.");
    }else{
        ReaderInfo->Clear();
    }

    StatusLabel->SetLabel((std::string)UFR_Status2String(status));
}

void mfp_wxwidgetsFrame::OnTimer2Trigger(wxTimerEvent& event)
{
    uint8_t card_type, sak, uid_size;
    uint8_t uid[10];

    status = GetDlogicCardType(&card_type);

    if(!status){
        CType->SetValue(uFR.GetDlTypeName(card_type));
        GetCardIdEx(&sak, uid, &uid_size);
        CUid->SetValue(uFR.ConvertUint8ArrayToStr(uid, uid_size, " "));
    }else{
        CType->SetValue((std::string)UFR_Status2String(status));
        CUid->SetValue((std::string)UFR_Status2String(status));
    }
}

void mfp_wxwidgetsFrame::OnbLWProvidedKeyClick(wxCommandEvent& event)
{
    uint8_t dl_card_type = 0;
    uint8_t auth_mode;
    uint16_t lin_addr = 0;
    uint16_t lin_len = 0;
    uint8_t crypto_1_sector_key[6];
    uint8_t aes_sector_key[16];
    uint8_t linear_data[3439];
    uint16_t ret_bytes = 0;

    status = GetDlogicCardType(&dl_card_type);

    if((dl_card_type >= DL_MIFARE_PLUS_S_2K_SL1 && dl_card_type <= DL_MIFARE_PLUS_EV1_2K_SL1)
							|| (dl_card_type >= DL_MIFARE_PLUS_S_4K_SL1 && dl_card_type <= DL_MIFARE_PLUS_EV1_4K_SL1))
    {
        if(LW_Provided_KeyA->GetValue())
        {
            auth_mode = MIFARE_AUTHENT1A;
        }
        else if(LW_Provided_KeyB->GetValue())
        {
            auth_mode = MIFARE_AUTHENT1B;
        }

        wxString wxKey = LW_Provided_Key->GetValue();

        if(wxKey.Length() != 12){
            wxMessageBox("Card type is " + uFR.GetDlTypeName(dl_card_type) + " . Key must be 6 bytes long - CRYPTO 1 key");
            return;
        }

        lin_addr = wxAtoi(LW_Provided_Addr->GetValue());

        uFR.ConvertToUint8Array((std::string)wxKey, crypto_1_sector_key);

        wxString wxData = WriteDataTB->GetValue();

        uFR.ConvertToUint8Array((std::string)wxData, linear_data);

        lin_len = wxData.Length() / 2;

        status = LinearWrite_PK(linear_data, lin_addr, lin_len, &ret_bytes, auth_mode, crypto_1_sector_key);
    }
    else
    {
        if(LW_Provided_KeyA->GetValue())
        {
            auth_mode = MIFARE_PLUS_AES_AUTHENT1A;
        }
        else if(LW_Provided_KeyB->GetValue())
        {
            auth_mode = MIFARE_PLUS_AES_AUTHENT1B;
        }

        wxString wxKey = LW_Provided_Key->GetValue();

        if(wxKey.Length() != 32){
            wxMessageBox("Card type is " + uFR.GetDlTypeName(dl_card_type) + " . Key must be 16 bytes long - AES key");
            return;
        }

        lin_addr = wxAtoi(LW_Provided_Addr->GetValue());

        uFR.ConvertToUint8Array((std::string)wxKey, aes_sector_key);

        wxString wxData = WriteDataTB->GetValue();

        uFR.ConvertToUint8Array((std::string)wxData, linear_data);

        lin_len = wxData.Length() / 2;

        status = LinearWrite_PK(linear_data, lin_addr, lin_len, &ret_bytes, auth_mode, aes_sector_key);
    }

    wxString wxLen = "";
    wxLen << ret_bytes;

    if(!status){
        ReaderInfo->SetValue("Operation completed. Linear data [" + wxLen + " bytes] successfully written.");
    }else{
        ReaderInfo->Clear();
    }

    StatusLabel->SetLabel((std::string)UFR_Status2String(status));
}

void mfp_wxwidgetsFrame::OnbLWReaderKeyClick(wxCommandEvent& event)
{
    uint8_t auth_mode;
    uint16_t lin_addr = 0;
    uint16_t lin_len = 0;
    uint8_t linear_data[3439];
    uint16_t ret_bytes = 0;
    uint8_t key_index;

    if(LW_Reader_KeyA->GetValue())
    {
        auth_mode = MIFARE_AUTHENT1A;
    }
    else if(LW_Reader_KeyB->GetValue())
    {
        auth_mode = MIFARE_AUTHENT1B;
    }

    lin_addr = wxAtoi(LW_Reader_Addr->GetValue());
    key_index = LW_Reader_KeyIndex->GetSelection();

    wxString wxData = WriteDataTB->GetValue();

    uFR.ConvertToUint8Array((std::string)wxData, linear_data);

    lin_len = wxData.Length() / 2;

    status = LinearWrite(linear_data, lin_addr, lin_len, &ret_bytes, auth_mode, key_index);

    wxString wxLen = "";
    wxLen << ret_bytes;

    if(!status){
        ReaderInfo->SetValue("Operation completed. Linear data [" + wxLen + " bytes] successfully written.");
    }else{
        ReaderInfo->Clear();
    }

    StatusLabel->SetLabel((std::string)UFR_Status2String(status));
}

void mfp_wxwidgetsFrame::OnbLWAKM1KeyClick(wxCommandEvent& event)
{
    uint8_t auth_mode;
    uint16_t lin_addr = 0;
    uint16_t lin_len = 0;
    uint8_t linear_data[3439];
    uint16_t ret_bytes = 0;

    if(LW_AKM1_KeyA->GetValue())
    {
        auth_mode = MIFARE_AUTHENT1A;
    }
    else if(LW_AKM1_KeyB->GetValue())
    {
        auth_mode = MIFARE_AUTHENT1B;
    }

    lin_addr = wxAtoi(LW_AKM1_Addr->GetValue());

    wxString wxData = WriteDataTB->GetValue();

    uFR.ConvertToUint8Array((std::string)wxData, linear_data);

    lin_len = wxData.Length() / 2;

    status = LinearWrite_AKM1(linear_data, lin_addr, lin_len, &ret_bytes, auth_mode);

    wxString wxLen = "";
    wxLen << ret_bytes;

    if(!status){
        ReaderInfo->SetValue("Operation completed. Linear data [" + wxLen + " bytes] successfully written.");
    }else{
        ReaderInfo->Clear();
    }

    StatusLabel->SetLabel((std::string)UFR_Status2String(status));
}

void mfp_wxwidgetsFrame::OnbLWAKM2KeyClick(wxCommandEvent& event)
{
    uint8_t auth_mode;
    uint16_t lin_addr = 0;
    uint16_t lin_len = 0;
    uint8_t linear_data[3439];
    uint16_t ret_bytes = 0;

    if(LW_AKM2_KeyA->GetValue())
    {
        auth_mode = MIFARE_AUTHENT1A;
    }
    else if(LW_AKM2_KeyB->GetValue())
    {
        auth_mode = MIFARE_AUTHENT1B;
    }

    lin_addr = wxAtoi(LW_AKM2_Addr->GetValue());

    wxString wxData = WriteDataTB->GetValue();

    uFR.ConvertToUint8Array((std::string)wxData, linear_data);

    lin_len = wxData.Length() / 2;

    status = LinearWrite_AKM2(linear_data, lin_addr, lin_len, &ret_bytes, auth_mode);

    wxString wxLen = "";
    wxLen << ret_bytes;

    if(!status){
        ReaderInfo->SetValue("Operation completed. Linear data [" + wxLen + " bytes] successfully written.");
    }else{
        ReaderInfo->Clear();
    }

    StatusLabel->SetLabel((std::string)UFR_Status2String(status));
}

void mfp_wxwidgetsFrame::OnbChangeSectorKeysClick(wxCommandEvent& event)
{
    uint8_t auth_mode;
    uint8_t sector_nr = SectorNumber->GetSelection();

    if(RB_AES_KEY_A->GetValue())
    {
        auth_mode =  MIFARE_PLUS_AES_AUTHENT1A;
    }
    else if(RB_AES_KEY_B->GetValue())
    {
        auth_mode = MIFARE_PLUS_AES_AUTHENT1B;
    }

    if(RBProvided->GetValue())
    {
        wxString wxOldSector = OldAesSectorKeyTB->GetValue();
        wxString wxNewSector = NewAesSectorKeyTB->GetValue();

        uint8_t old_sector_key[16];
        uint8_t new_sector_key[16];

        uFR.ConvertToUint8Array((std::string)wxOldSector, old_sector_key);
        uFR.ConvertToUint8Array((std::string)wxNewSector, new_sector_key);

        status = MFP_ChangeSectorKey_PK(sector_nr, auth_mode, old_sector_key, new_sector_key);
    }
    else if(RBReader->GetValue())
    {
        uint8_t key_index = AESKeyIndex->GetSelection();
        uint8_t new_sector_key[16];
        wxString wxNewSector = NewAesSectorKeyRK->GetValue();

        uFR.ConvertToUint8Array((std::string)wxNewSector, new_sector_key);

        status = MFP_ChangeSectorKey(sector_nr, auth_mode, key_index, new_sector_key);
    }

    if(!status){
        ReaderInfo->SetValue("Operation completed. Sector key successfully changed.");
    }else{
        ReaderInfo->Clear();
    }

    StatusLabel->SetLabel((std::string)UFR_Status2String(status));
}
