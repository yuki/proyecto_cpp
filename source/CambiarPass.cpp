//---------------------------------------------------------------------------

#include <clx.h>
#pragma hdrstop

#include "CambiarPass.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.xfm"
TFCambiarPass *FCambiarPass;
//---------------------------------------------------------------------------
__fastcall TFCambiarPass::TFCambiarPass(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFCambiarPass::AgreGrupNOClick(TObject *Sender)
{
     FCambiarPass->Hide();
     FAdmin->Show();
}
//---------------------------------------------------------------------------

void __fastcall TFCambiarPass::FormShow(TObject *Sender)
{
   EPassViejo->Clear();
   EPassNuevo1->Clear();
   EPassNuevo2->Clear();        
}
//---------------------------------------------------------------------------

void __fastcall TFCambiarPass::FormClose(TObject *Sender,
      TCloseAction &Action)
{
    FAdmin->Show();
}
//---------------------------------------------------------------------------

void __fastcall TFCambiarPass::AgreGrupOKClick(TObject *Sender)
{
    if (LeerPass(AnsiString(EPassViejo->Text).c_str())){
        if (!strcmp (AnsiString(EPassNuevo1->Text).c_str(),AnsiString(EPassNuevo2->Text).c_str())){
            SalvarPass(AnsiString(EPassNuevo1->Text).c_str());
            FCambiarPass->Hide();
            FAdmin->Show();
        }
    }
    else{
        Application->MessageBox("Clave mal introducida.\nNo puede cambiar el password","Error en password");

        FCambiarPass->Hide();
        FAdmin->Show();
    }
}
//---------------------------------------------------------------------------

void __fastcall TFCambiarPass::VerGrupos1Click(TObject *Sender)
{
    FCambiarPass->Hide();
    FComprarEntr->Show();
}
//---------------------------------------------------------------------------

void __fastcall TFCambiarPass::VerGrupos2Click(TObject *Sender)
{
    FCambiarPass->Hide();
    FVerGrupos->Show();
}
//---------------------------------------------------------------------------

void __fastcall TFCambiarPass::Principal1Click(TObject *Sender)
{
    FCambiarPass->Hide();
    FBienveni->Show();
}
//---------------------------------------------------------------------------

void __fastcall TFCambiarPass::Salir1Click(TObject *Sender)
{
    FBienveni->Close();
}
//---------------------------------------------------------------------------

void __fastcall TFCambiarPass::AadirGrupo1Click(TObject *Sender)
{
    FCambiarPass->Hide();
    FAgreGrupos->Show();
}
//---------------------------------------------------------------------------

void __fastcall TFCambiarPass::EliminarGrupo1Click(TObject *Sender)
{
     FCambiarPass->Hide();
     FEliminar->Show();
}
//---------------------------------------------------------------------------


void __fastcall TFCambiarPass::Recaudacin1Click(TObject *Sender)
{
    FCambiarPass->Hide();
    FRecaudacion->Show();    
}
//---------------------------------------------------------------------------

void __fastcall TFCambiarPass::Acercade1Click(TObject *Sender)
{
       FAcercaDe->Show();
}
//---------------------------------------------------------------------------

