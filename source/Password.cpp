//---------------------------------------------------------------------------

#include <clx.h>
#pragma hdrstop

#include "Password.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.xfm"
TFPass *FPass;


//---------------------------------------------------------------------------
__fastcall TFPass::TFPass(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TFPass::BitBtn1Click(TObject *Sender)
{
    FPass->Hide();
    FBienveni->Show();
}
//---------------------------------------------------------------------------
void __fastcall TFPass::BitokClick(TObject *Sender)
{
    if (LeerPass(MaskPass->Text.c_str())){    //en pass.h
        FPass->Hide();
        FBienveni->Hide();
        FAdmin->Show();
    }
    else{
        Application->MessageBox("Password incorrecto","Password incorrecto");
        FPass->Hide();
    }
}
//---------------------------------------------------------------------------
void __fastcall TFPass::FormClose(TObject *Sender, TCloseAction &Action)
{
FBienveni->Show();
}
//---------------------------------------------------------------------------

void __fastcall TFPass::FormShow(TObject *Sender)
{
    MaskPass->Clear();        
}
//---------------------------------------------------------------------------

