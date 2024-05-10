//---------------------------------------------------------------------------

#ifndef AdministrarH
#define AdministrarH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <QControls.hpp>
#include <QStdCtrls.hpp>
#include <QForms.hpp>

//includes del GUI
#include "Bienvenida.h"
#include "ComprEntradas.h"
#include "VerGrupos.h"
#include "AcercaDe.h"

#include "AdminGrupo.h"
#include "CambiarPass.h"
#include "Recaudacion.h"
#include "Eliminar.h"


#include <QMenus.hpp>
#include <QTypes.hpp>

//---------------------------------------------------------------------------
class TFAdmin : public TForm
{
__published:	// IDE-managed Components
        TLabel *LBienveni;
        TLabel *Ladmin;
        TButton *BAniadir;
        TButton *BEliminar;
        TButton *BRecau;
        TButton *BCambiar;
        TButton *BVolver;
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
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall BAniadirClick(TObject *Sender);
        void __fastcall BCambiarClick(TObject *Sender);
        void __fastcall BVolverClick(TObject *Sender);
        void __fastcall BRecauClick(TObject *Sender);
        void __fastcall BEliminarClick(TObject *Sender);
        void __fastcall VerGrupos1Click(TObject *Sender);
        void __fastcall VerGrupos2Click(TObject *Sender);
        void __fastcall Principal1Click(TObject *Sender);
        void __fastcall Salir1Click(TObject *Sender);
        void __fastcall AadirGrupo1Click(TObject *Sender);
        void __fastcall EliminarGrupo1Click(TObject *Sender);
        void __fastcall CambiarPassword1Click(TObject *Sender);
        void __fastcall Recaudacin1Click(TObject *Sender);
        void __fastcall Acercade1Click(TObject *Sender);
        
private:	// User declarations
public:		// User declarations
        __fastcall TFAdmin(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFAdmin *FAdmin;
//---------------------------------------------------------------------------
#endif
