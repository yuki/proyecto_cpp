//---------------------------------------------------------------------------

#include <clx.h>
#pragma hdrstop

#include "Administrar.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.xfm"
TFAdmin *FAdmin;
//---------------------------------------------------------------------------
__fastcall TFAdmin::TFAdmin(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFAdmin::FormClose(TObject *Sender, TCloseAction &Action)
{
    FBienveni->Show();
}
//---------------------------------------------------------------------------

void __fastcall TFAdmin::BAniadirClick(TObject *Sender)
{
    FAdmin->Hide();
    FAgreGrupos->Show();
}
//---------------------------------------------------------------------------



void __fastcall TFAdmin::BCambiarClick(TObject *Sender)
{
    FCambiarPass->Show();
    FAdmin->Hide();
}
//---------------------------------------------------------------------------

void __fastcall TFAdmin::BVolverClick(TObject *Sender)
{
    FAdmin->Hide();
    FBienveni->Show();
}
//---------------------------------------------------------------------------

void __fastcall TFAdmin::BRecauClick(TObject *Sender)
{
    FAdmin->Hide();
    FRecaudacion->Show();
}
//---------------------------------------------------------------------------

void __fastcall TFAdmin::BEliminarClick(TObject *Sender)
{
    FAdmin->Hide();
    FEliminar->Show();
}
//---------------------------------------------------------------------------
void __fastcall TFAdmin::VerGrupos1Click(TObject *Sender)
{
    FAdmin->Hide();
    FComprarEntr->Show();
}
//---------------------------------------------------------------------------

void __fastcall TFAdmin::VerGrupos2Click(TObject *Sender)
{
    FAdmin->Hide();
    FVerGrupos->Show();
}
//---------------------------------------------------------------------------

void __fastcall TFAdmin::Principal1Click(TObject *Sender)
{
     FAdmin->Hide();
     FBienveni->Show();
}
//---------------------------------------------------------------------------

void __fastcall TFAdmin::Salir1Click(TObject *Sender)
{
        FBienveni->Close();
}
//---------------------------------------------------------------------------

void __fastcall TFAdmin::AadirGrupo1Click(TObject *Sender)
{
      FAdmin->Hide();
      FAgreGrupos->Show();
}
//---------------------------------------------------------------------------

void __fastcall TFAdmin::EliminarGrupo1Click(TObject *Sender)
{
      FAdmin->Hide();
      FEliminar->Show();
}
//---------------------------------------------------------------------------

void __fastcall TFAdmin::CambiarPassword1Click(TObject *Sender)
{
      FAdmin->Hide();
      FCambiarPass->Show();
}
//---------------------------------------------------------------------------

void __fastcall TFAdmin::Recaudacin1Click(TObject *Sender)
{
      FAdmin->Hide();
      FRecaudacion->Show();
}
//---------------------------------------------------------------------------

void __fastcall TFAdmin::Acercade1Click(TObject *Sender)
{
      FAcercaDe->Show();
}
//---------------------------------------------------------------------------

