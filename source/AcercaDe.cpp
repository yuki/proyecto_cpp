//---------------------------------------------------------------------------

#include <clx.h>
#pragma hdrstop

#include "AcercaDe.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.xfm"
TFAcercaDe *FAcercaDe;
//---------------------------------------------------------------------------
__fastcall TFAcercaDe::TFAcercaDe(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFAcercaDe::BPrincipalClick(TObject *Sender)
{
   FAcercaDe -> Hide();
   FBienveni -> Show();        
}
//---------------------------------------------------------------------------
 

