//---------------------------------------------------------------------------

#ifndef EliminarH
#define EliminarH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <QControls.hpp>
#include <QStdCtrls.hpp>
#include <QForms.hpp>

//include del GUI
//includes del GUI
#include "Bienvenida.h"
#include "ComprEntradas.h"
#include "VerGrupos.h"
#include "AcercaDe.h"

#include "AdminGrupo.h"
#include "CambiarPass.h"
#include "Recaudacion.h"
#include "Administrar.h"

//include del programa
#include "pass.h"
#include <QMenus.hpp>
#include <QTypes.hpp>


//---------------------------------------------------------------------------
class TFEliminar : public TForm
{
__published:	// IDE-managed Components
        TLabel *LRecaudacion;
        TListBox *ListGrupos;
        TListBox *ListFechas;
        TListBox *ListRecau;
        TLabel *Fechas;
        TLabel *Grupos;
        TButton *BMenuPrin;
        TLabel *LRecau;
        TButton *BEliminar;
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
        void __fastcall BMenuPrinClick(TObject *Sender);
        void __fastcall FormShow(TObject *Sender);
        void __fastcall ListGruposClick(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall BEliminarClick(TObject *Sender);
        void __fastcall VerGrupos1Click(TObject *Sender);
        void __fastcall VerGrupos2Click(TObject *Sender);
        void __fastcall Principal1Click(TObject *Sender);
        void __fastcall Salir1Click(TObject *Sender);
        void __fastcall AadirGrupo1Click(TObject *Sender);
        void __fastcall CambiarPassword1Click(TObject *Sender);
        void __fastcall Recaudacin1Click(TObject *Sender);
        void __fastcall Acercade1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TFEliminar(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFEliminar *FEliminar;
//---------------------------------------------------------------------------
#endif
