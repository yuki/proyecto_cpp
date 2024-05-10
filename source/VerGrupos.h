//---------------------------------------------------------------------------

#ifndef VerGruposH
#define VerGruposH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <QControls.hpp>
#include <QStdCtrls.hpp>
#include <QForms.hpp>


//includes del GUI
#include "Bienvenida.h"
#include "ComprEntradas.h"
#include "AcercaDe.h"

//include de la parte intermedia
#include "Grupo.h"
#include "General.h"
#include "Comprar.h"
#include <QMenus.hpp>
#include <QTypes.hpp>

//---------------------------------------------------------------------------
class TFVerGrupos : public TForm
{
__published:	// IDE-managed Components
        TLabel *LVerGrupos;
        TLabel *LGrupos;
        TListBox *ListGrupos;
        TLabel *LFechas;
        TListBox *ListFechas;
        TLabel *LPrecios;
        TListBox *ListPrecios;
        TButton *BVolver;
        TButton *BIrComprar;
        TMainMenu *MenuPrincipal;
        TMenuItem *Ira1;
        TMenuItem *VerGrupos1;
        TMenuItem *VerGrupos2;
        TMenuItem *Principal1;
        TMenuItem *Salir1;
        TMenuItem *Ayuda1;
        TMenuItem *Acercade1;
        void __fastcall FormShow(TObject *Sender);
        void __fastcall ListGruposClick(TObject *Sender);
        void __fastcall BVolverClick(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall BIrComprarClick(TObject *Sender);
        void __fastcall FormHide(TObject *Sender);
        void __fastcall VerGrupos1Click(TObject *Sender);
        void __fastcall Principal1Click(TObject *Sender);
        void __fastcall Salir1Click(TObject *Sender);
        void __fastcall Acercade1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TFVerGrupos(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFVerGrupos *FVerGrupos;
//---------------------------------------------------------------------------
#endif
