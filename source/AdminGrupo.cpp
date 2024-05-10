//---------------------------------------------------------------------------

#include <clx.h>
#pragma hdrstop

#include "AdminGrupo.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.xfm"


TFAgreGrupos *FAgreGrupos;
//---------------------------------------------------------------------------
__fastcall TFAgreGrupos::TFAgreGrupos(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFAgreGrupos::AgreGrupNOClick(TObject *Sender)
{
    FAdmin->Hide();
    FBienveni->Show();
}
//---------------------------------------------------------------------------

void __fastcall TFAgreGrupos::AgreGrupOKClick(TObject *Sender)
{
    AnadirGrupo (TodoBien()); //en Validaciones.h las dos funciones.
}
//---------------------------------------------------------------------------

void __fastcall TFAgreGrupos::FormClose(TObject *Sender,
      TCloseAction &Action)
{
    FBienveni->Show();
}
//---------------------------------------------------------------------------

void __fastcall TFAgreGrupos::FormShow(TObject *Sender)
{
    Clarear ();
}
//---------------------------------------------------------------------------


void __fastcall TFAdmin::BVolverClick(TObject *Sender)
{
    FAdmin->Hide();
    FBienveni->Show();
}
//---------------------------------------------------------------------------

void __fastcall TFAgreGrupos::VerGrupos1Click(TObject *Sender)
{
    FAgreGrupos->Hide();
    FComprarEntr->Show();
}
//---------------------------------------------------------------------------

void __fastcall TFAgreGrupos::VerGrupos2Click(TObject *Sender)
{
    FAgreGrupos->Hide();
    FVerGrupos->Show();
}
//---------------------------------------------------------------------------

void __fastcall TFAgreGrupos::Principal1Click(TObject *Sender)
{
     FAgreGrupos->Hide();
     FBienveni->Show();
}
//---------------------------------------------------------------------------

void __fastcall TFAgreGrupos::Salir1Click(TObject *Sender)
{
        FBienveni->Close();
}
//---------------------------------------------------------------------------


void __fastcall TFAgreGrupos::EliminarGrupo1Click(TObject *Sender)
{
      FAgreGrupos->Hide();
      FEliminar->Show();
}
//---------------------------------------------------------------------------

void __fastcall TFAgreGrupos::CambiarPassword1Click(TObject *Sender)
{
      FAgreGrupos->Hide();
      FCambiarPass->Show();
}
//---------------------------------------------------------------------------

void __fastcall TFAgreGrupos::Recaudacin1Click(TObject *Sender)
{
     FAgreGrupos->Hide();
     FRecaudacion->Show();   
}
//---------------------------------------------------------------------------

void __fastcall TFAgreGrupos::Acercade1Click(TObject *Sender)
{
    FAcercaDe->Show();
}
//---------------------------------------------------------------------------

