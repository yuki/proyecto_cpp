//---------------------------------------------------------------------------

#ifndef BienvenidaH
#define BienvenidaH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <QControls.hpp>
#include <QStdCtrls.hpp>
#include <QForms.hpp>
#include <QMenus.hpp>
#include <QTypes.hpp>

//Includes de los demas GUI's
#include "Password.h"
#include "VerGrupos.h"
#include "ComprEntradas.h"
#include "AcercaDe.h"

//includes del programa
#include "General.h"

//---------------------------------------------------------------------------
class TFBienveni : public TForm
{
__published:	// IDE-managed Components
        TLabel *LBienveni;
        TButton *BVerGrupos;
        TLabel *LTeatro;
        TButton *BComprar;
        TMainMenu *MenuPrincipal;
        TMenuItem *Ira1;
        TMenuItem *VerGrupos1;
        TMenuItem *VerGrupos2;
        TMenuItem *Principal1;
        TMenuItem *Ayuda1;
        TMenuItem *Acercade1;
        TMenuItem *Salir1;
        void __fastcall LBienveniDblClick(TObject *Sender);
        void __fastcall VerGrupos1Click(TObject *Sender);
        void __fastcall VerGrupos2Click(TObject *Sender);
        void __fastcall Acercade1Click(TObject *Sender);
        void __fastcall Salir1Click(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall BVerGruposClick(TObject *Sender);
        void __fastcall BComprarClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TFBienveni(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFBienveni *FBienveni;
//---------------------------------------------------------------------------
#endif
