//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "untMain.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmMain*                   frmMain;
bool                        fActive     = false;
HWND                        hwndContext = NULL;

typedef WINAPI BOOL
(*tGetLayeredWindowAttributes)(HWND hwnd, COLORREF* pcrKey, BYTE* pbAlpha, DWORD* pdwFlags);

tGetLayeredWindowAttributes GetLayeredWindowAttributes;

//---------------------------------------------------------------------------
__fastcall TfrmMain::TfrmMain(TComponent* Owner):
    TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::ApplicationEvents1Message(tagMSG& Msg, bool& Handled)
{
    if (Msg.message == WM_HOTKEY)
    {
        hwndContext = GetForegroundWindow();
        fActive = true;
        POINT   p;
        GetCursorPos(&p);
        Left = p.x;
        Top = p.y;
        COLORREF    dum1    = NULL;
        DWORD       dum2    = LWA_ALPHA;
        BYTE        iInitAlpha;
        GetLayeredWindowAttributes(hwndContext, &dum1, &iInitAlpha, &dum2);
        if (iInitAlpha == 0)
        {
            iInitAlpha = 255;
        }
        trkAlpha->Position = iInitAlpha;
        Show();
        SetForegroundWindow(Handle);
        fActive = true;
        Handled = true;
    }
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::FormCreate(TObject* Sender)
{
    Caption = "TranslucerWin";
    Application->ShowMainForm = false;
    HINSTANCE   r   = LoadLibrary("user32.dll");
    GetLayeredWindowAttributes = (tGetLayeredWindowAttributes) GetProcAddress(r, "GetLayeredWindowAttributes");
    RegisterHotKey(Application->Handle, 120, MOD_CONTROL | MOD_ALT, 'T');
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::Timer1Timer(TObject* Sender)
{
    if (fActive)
    {
        if (GetForegroundWindow() != this->Handle)
        {
            Hide();
            fActive = false;
        }
    }
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::FormKeyDown(TObject* Sender, WORD& Key, TShiftState Shift)
{
    Hide();
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::trkAlphaChange(TObject* Sender)
{
    int iPos    = trkAlpha->Position;
    if (iPos < 255)
    {
        SetWindowLong(hwndContext, GWL_EXSTYLE,  //make our form a layered window
                      GetWindowLong(hwndContext, GWL_EXSTYLE) | WS_EX_LAYERED);
        SetLayeredWindowAttributes(hwndContext, NULL, iPos, LWA_ALPHA);
    }
    else
    {
        SetWindowLong(hwndContext, GWL_EXSTYLE,  //make our form a layered window
                      (GetWindowLong(hwndContext, GWL_EXSTYLE) | WS_EX_LAYERED) ^ WS_EX_LAYERED);
    }
}
//---------------------------------------------------------------------------
