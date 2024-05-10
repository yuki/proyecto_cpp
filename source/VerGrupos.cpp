//---------------------------------------------------------------------------

#include <clx.h>
#pragma hdrstop

#include "VerGrupos.h"

//includes del GUI



//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.xfm"
TFVerGrupos *FVerGrupos;


//---------------------------------------------------------------------------
__fastcall TFVerGrupos::TFVerGrupos(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFVerGrupos::FormShow(TObject *Sender)
{
    ClearVer();   //en "Comprar.h"
    ShowVer ();   //en "Comprar.h"
}
//---------------------------------------------------------------------------

void __fastcall TFVerGrupos::ListGruposClick(TObject *Sender)
{
    SelGrupo (ListGrupos->ItemIndex);  //en "Comprar.h"
}
//---------------------------------------------------------------------------


void __fastcall TFVerGrupos::BVolverClick(TObject *Sender)
{
    FBienveni->Show();
    FVerGrupos->Hide();
}
//---------------------------------------------------------------------------
void __fastcall TFVerGrupos::FormClose(TObject *Sender,
      TCloseAction &Action)
{
    ClearVer();   //en "Comprar.h"
    FBienveni->Show();
}
//---------------------------------------------------------------------------

void __fastcall TFVerGrupos::BIrComprarClick(TObject *Sender)
{
    FVerGrupos->Hide();
    FComprarEntr->Show();
}
//---------------------------------------------------------------------------

void __fastcall TFVerGrupos::FormHide(TObject *Sender)
{
    ClearVer();   //en "Comprar.h"    
}
//---------------------------------------------------------------------------

void __fastcall TFVerGrupos::VerGrupos1Click(TObject *Sender)
{
    FComprarEntr->Show();
    FVerGrupos->Hide();
}
//---------------------------------------------------------------------------


void __fastcall TFVerGrupos::Principal1Click(TObject *Sender)
{
     FVerGrupos->Hide();
     FBienveni->Show();
}
//---------------------------------------------------------------------------

void __fastcall TFVerGrupos::Salir1Click(TObject *Sender)
{
    FBienveni->Close();
}
//---------------------------------------------------------------------------

void __fastcall TFVerGrupos::Acercade1Click(TObject *Sender)
{
   FAcercaDe->Show();
}
//---------------------------------------------------------------------------

