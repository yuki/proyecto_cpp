//---------------------------------------------------------------------------

#ifndef CambiarPassH
#define CambiarPassH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <QControls.hpp>
#include <QStdCtrls.hpp>
#include <QForms.hpp>
#include <QButtons.hpp>

//includes del GUI
//includes del GUI
#include "Bienvenida.h"
#include "ComprEntradas.h"
#include "VerGrupos.h"
#include "AcercaDe.h"

#include "AdminGrupo.h"
#include "Administrar.h"
#include "Recaudacion.h"
#include "Eliminar.h"

//include del programa
#include "pass.h"
#include <QMenus.hpp>
#include <QTypes.hpp>


//---------------------------------------------------------------------------
class TFCambiarPass : public TForm
{
__published:	// IDE-managed Components
        TBitBtn *AgreGrupOK;
        TBitBtn *AgreGrupNO;
        TLabel *LPassVieja;
        TLabel *LPassNuevo1;
        TLabel *LPassNuevo2;
        TEdit *EPassViejo;
        TEdit *EPassNuevo1;
        TEdit *EPassNuevo2;
        TLabel *Label4;
        TMainMenu *MenuPrincipal;
        TMenuItem *Ira1;
        TMenuItem *VerGrupos1;
        TMenuItem *VerGrupos2;
        TMenuItem *Principal1;
        TMenuItem *Salir1;
        TMenuItem *Administrador1;
        TMenuItem *AadirGrupo1;
        TMenuItem *EliminarGrupo1;
        TMenuItem *CambiarPassword1;
        TMenuItem *Recaudacin1;
        TMenuItem *Ayuda1;
        TMenuItem *Acercade1;
        void __fastcall AgreGrupNOClick(TObject *Sender);
        void __fastcall FormShow(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall AgreGrupOKClick(TObject *Sender);
        void __fastcall VerGrupos1Click(TObject *Sender);
        void __fastcall VerGrupos2Click(TObject *Sender);
        void __fastcall Principal1Click(TObject *Sender);
        void __fastcall Salir1Click(TObject *Sender);
        void __fastcall AadirGrupo1Click(TObject *Sender);
        void __fastcall EliminarGrupo1Click(TObject *Sender);
        void __fastcall Recaudacin1Click(TObject *Sender);
        void __fastcall Acercade1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TFCambiarPass(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFCambiarPass *FCambiarPass;
//---------------------------------------------------------------------------
#endif
