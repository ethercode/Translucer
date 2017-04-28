//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("untMain.cpp", frmMain);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    bool    MayRun  = true;
    HWND    w       = FindWindow(0, "TranslucerWin");
    if (w)
    {
        DWORD   dwMyPID = GetCurrentProcessId();
        DWORD   dwOtherPID;
        GetWindowThreadProcessId(w, &dwOtherPID);
        if (dwOtherPID != dwMyPID)
        {
            MayRun = false;
        }
    }
    if (!MayRun)
    {
        return 0;
    }
    try
    {
        Application->Initialize();
        Application->CreateForm(__classid(TfrmMain), &frmMain);
        Application->Run();
    }
    catch (Exception& exception)
    {
        Application->ShowException(&exception);
    }
    catch (...)
    {
        try
        {
            throw Exception("");
        }
        catch (Exception& exception)
        {
            Application->ShowException(&exception);
        }
    }
    return 0;
}
//---------------------------------------------------------------------------
