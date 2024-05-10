//---------------------------------------------------------------------------

#include <clx.h>
#pragma hdrstop

#include "Bienvenida.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.xfm"
TFBienveni *FBienveni;


//---------------------------------------------------------------------------
__fastcall TFBienveni::TFBienveni(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TFBienveni::LBienveniDblClick(TObject *Sender)
{
    FPass->Show();
    FPass->SetFocus();
}
//---------------------------------------------------------------------------


void __fastcall TFBienveni::VerGrupos1Click(TObject *Sender)
{
  FBienveni->Hide();
  FComprarEntr->Show();
}
//---------------------------------------------------------------------------

void __fastcall TFBienveni::VerGrupos2Click(TObject *Sender)
{
   FBienveni->Hide();
   FVerGrupos->Show();
}
//---------------------------------------------------------------------------

void __fastcall TFBienveni::Acercade1Click(TObject *Sender)
{
   FAcercaDe->Show();
}
//---------------------------------------------------------------------------


void __fastcall TFBienveni::Salir1Click(TObject *Sender)
{
    FBienveni->Close();
}
//---------------------------------------------------------------------------


void __fastcall TFBienveni::FormClose(TObject *Sender,
      TCloseAction &Action)
{
    Final();
}
//---------------------------------------------------------------------------

void __fastcall TFBienveni::FormCreate(TObject *Sender)
{
    Inicio();
}
//---------------------------------------------------------------------------

void __fastcall TFBienveni::BVerGruposClick(TObject *Sender)
{
   FBienveni->Hide();
   FVerGrupos->Show();
}
//---------------------------------------------------------------------------

void __fastcall TFBienveni::BComprarClick(TObject *Sender)
{
    FBienveni->Hide();
    FComprarEntr->Show();
}
//---------------------------------------------------------------------------

