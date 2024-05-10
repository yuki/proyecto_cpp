//---------------------------------------------------------------------------

#include <clx.h>
#pragma hdrstop

#include "Recaudacion.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.xfm"
TFRecaudacion *FRecaudacion;
//---------------------------------------------------------------------------
__fastcall TFRecaudacion::TFRecaudacion(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TFRecaudacion::BMenuPrinClick(TObject *Sender)
{
     FRecaudacion->Hide();
     FAdmin->Show();
}
//---------------------------------------------------------------------------

void __fastcall TFRecaudacion::FormShow(TObject *Sender)
{
    ListGrupos->Clear();
    ListFechas->Clear();
    ListRecau->Clear();
    VerRecau(ListGrupos); //en "pass.h"
}
//---------------------------------------------------------------------------

void __fastcall TFRecaudacion::ListGruposClick(TObject *Sender)
{
    SelRecau (ListGrupos->ItemIndex, ListFechas, ListRecau);
}
//---------------------------------------------------------------------------

void __fastcall TFRecaudacion::FormClose(TObject *Sender,
      TCloseAction &Action)
{
    FAdmin->Show();        
}
//---------------------------------------------------------------------------

void __fastcall TFRecaudacion::VerGrupos1Click(TObject *Sender)
{
    FRecaudacion->Hide();
    FComprarEntr->Show();
}
//---------------------------------------------------------------------------

void __fastcall TFRecaudacion::Acercade1Click(TObject *Sender)
{
    FAcercaDe->Show();
}
//---------------------------------------------------------------------------

void __fastcall TFRecaudacion::VerGrupos2Click(TObject *Sender)
{
    FRecaudacion->Hide();
    FVerGrupos->Show();
}
//---------------------------------------------------------------------------

void __fastcall TFRecaudacion::Principal1Click(TObject *Sender)
{
   FRecaudacion->Hide();
   FBienveni->Show();
}
//---------------------------------------------------------------------------

void __fastcall TFRecaudacion::Salir1Click(TObject *Sender)
{
   FBienveni->Close();
}
//---------------------------------------------------------------------------

void __fastcall TFRecaudacion::AadirGrupo1Click(TObject *Sender)
{
    FRecaudacion->Hide();
    FAgreGrupos->Show();
}
//---------------------------------------------------------------------------

void __fastcall TFRecaudacion::EliminarGrupo1Click(TObject *Sender)
{
     FRecaudacion->Hide();
     FEliminar->Show();
}
//---------------------------------------------------------------------------

void __fastcall TFRecaudacion::CambiarPassword1Click(TObject *Sender)
{
    FRecaudacion->Hide();
    FCambiarPass->Show();
}
//---------------------------------------------------------------------------


