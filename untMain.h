//---------------------------------------------------------------------------

#ifndef untMainH
#define untMainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <AppEvnts.hpp>
//---------------------------------------------------------------------------
class TfrmMain:public TForm
{
__published:    // IDE-managed Components
    TPanel*                 Panel1;
    TTrackBar*              trkAlpha;
    TApplicationEvents*     ApplicationEvents1;
    TTimer*                 Timer1;
    void __fastcall         ApplicationEvents1Message(tagMSG& Msg, bool& Handled);
    void __fastcall         FormCreate(TObject* Sender);
    void __fastcall         Timer1Timer(TObject* Sender);
    void __fastcall         FormKeyDown(TObject* Sender, WORD& Key, TShiftState Shift);
    void __fastcall         trkAlphaChange(TObject* Sender);
private:    // User declarations
public:     // User declarations
    __fastcall              TfrmMain(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmMain*frmMain;
//---------------------------------------------------------------------------
#endif
