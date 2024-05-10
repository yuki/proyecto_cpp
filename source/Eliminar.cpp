//---------------------------------------------------------------------------

#include <clx.h>
#pragma hdrstop

#include "Eliminar.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.xfm"
TFEliminar *FEliminar;
//---------------------------------------------------------------------------
__fastcall TFEliminar::TFEliminar(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TFEliminar::BMenuPrinClick(TObject *Sender)
{
     FEliminar->Hide();
     FAdmin->Show();
}
//---------------------------------------------------------------------------

void __fastcall TFEliminar::FormShow(TObject *Sender)
{
    ListGrupos->Clear();
    ListFechas->Clear();
    ListRecau->Clear();
    VerRecau(ListGrupos); //en "pass.h"
}
//---------------------------------------------------------------------------

void __fastcall TFEliminar::ListGruposClick(TObject *Sender)
{
    SelRecau (ListGrupos->ItemIndex, ListFechas, ListRecau);  //en "pass.h"
}
//---------------------------------------------------------------------------

void __fastcall TFEliminar::FormClose(TObject *Sender,
      TCloseAction &Action)
{
    FAdmin->Show();
}
//---------------------------------------------------------------------------

void __fastcall TFEliminar::BEliminarClick(TObject *Sender)
{
    Eliminar (ListGrupos->ItemIndex);
}
//---------------------------------------------------------------------------

void __fastcall TFEliminar::VerGrupos1Click(TObject *Sender)
{
    FEliminar->Hide();
    FComprarEntr->Show();
}
//---------------------------------------------------------------------------

void __fastcall TFEliminar::VerGrupos2Click(TObject *Sender)
{
    FEliminar->Hide();
    FVerGrupos->Show();
}
//---------------------------------------------------------------------------

void __fastcall TFEliminar::Principal1Click(TObject *Sender)
{
    FEliminar->Hide();
    FBienveni->Show();
}
//---------------------------------------------------------------------------

void __fastcall TFEliminar::Salir1Click(TObject *Sender)
{
    FBienveni->Close();
}
//---------------------------------------------------------------------------

void __fastcall TFEliminar::AadirGrupo1Click(TObject *Sender)
{
    FEliminar->Hide();
    FAgreGrupos->Show();
}
//---------------------------------------------------------------------------


void __fastcall TFEliminar::CambiarPassword1Click(TObject *Sender)
{
    FEliminar->Hide();
    FCambiarPass->Show();
}
//---------------------------------------------------------------------------

void __fastcall TFEliminar::Recaudacin1Click(TObject *Sender)
{
    FEliminar->Hide();
    FRecaudacion->Show();         
}
//---------------------------------------------------------------------------

void __fastcall TFEliminar::Acercade1Click(TObject *Sender)
{
    FAcercaDe->Show();
}
//---------------------------------------------------------------------------

