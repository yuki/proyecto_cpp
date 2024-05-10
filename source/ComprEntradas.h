//---------------------------------------------------------------------------

#ifndef ComprEntradasH
#define ComprEntradasH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <QControls.hpp>
#include <QStdCtrls.hpp>
#include <QForms.hpp>
#include <QExtCtrls.hpp>
#include <QButtons.hpp>

//includes del proyecto,son los GUI's
#include "Bienvenida.h"
#include "VerGrupos.h"
#include "AcercaDe.h"

//includes del proyecto.
#include "Validaciones.h"
#include "General.h"
#include "Grupo.h"
#include "Fecha.h"
#include "Butacas.h"
#include "Comprar.h"


#include <QMenus.hpp>
#include <QTypes.hpp>
//---------------------------------------------------------------------------
class TFComprarEntr : public TForm
{
__published:	// IDE-managed Components
        TButton *BA1;
        TButton *BA2;
        TButton *BA3;
        TButton *BA4;
        TButton *BA5;
        TButton *BA6;
        TButton *BA7;
        TButton *BA8;
        TButton *BA9;
        TButton *BA10;
        TButton *BB1;
        TButton *BB2;
        TButton *BB3;
        TButton *BB4;
        TButton *BB5;
        TButton *BB6;
        TButton *BB7;
        TButton *BB8;
        TButton *BB9;
        TButton *BB10;
        TButton *BC1;
        TButton *BC2;
        TButton *BC3;
        TButton *BC4;
        TButton *BC5;
        TButton *BC6;
        TButton *BC7;
        TButton *BC8;
        TButton *BC9;
        TButton *BC10;
        TButton *BD1;
        TButton *BD2;
        TButton *BD3;
        TButton *BD4;
        TButton *BD5;
        TButton *BD6;
        TButton *BD7;
        TButton *BD8;
        TButton *BD9;
        TButton *BD10;
        TLabel *LCompEntr;
        TLabel *LGrupo;
        TListBox *ListGrupos;
        TPanel *PEscenario;
        TLabel *LFecha;
        TListBox *ListFechas;
        TLabel *LPrecios;
        TButton *BBarato;
        TButton *BMedio;
        TEdit *EPrecBarato;
        TEdit *EPrecMedio;
        TButton *BPrecCaro;
        TEdit *EPrecCaro;
        TBitBtn *BitComprar;
        TButton *BVolver;
        TLabel *LPrecTotal;
        TEdit *Ecoste;
        TButton *BOcupado;
        TButton *BSeleccionada;
        TLabel *LOcupada;
        TLabel *LSeleccion;
        TMainMenu *MenuPrincipal;
        TMenuItem *Ira1;
        TMenuItem *VerGrupos1;
        TMenuItem *VerGrupos2;
        TMenuItem *Principal1;
        TMenuItem *Salir1;
        TMenuItem *Ayuda1;
        TMenuItem *Acercade1;
        void __fastcall BVolverClick(TObject *Sender);
        void __fastcall FormShow(TObject *Sender);
        void __fastcall ListGruposClick(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall FormHide(TObject *Sender);
        void __fastcall ListFechasClick(TObject *Sender);
        void __fastcall BA1Click(TObject *Sender);
        void __fastcall BA10Click(TObject *Sender);
        void __fastcall BA2Click(TObject *Sender);
        void __fastcall BA3Click(TObject *Sender);
        void __fastcall BA4Click(TObject *Sender);
        void __fastcall BA5Click(TObject *Sender);
        void __fastcall BA6Click(TObject *Sender);
        void __fastcall BA7Click(TObject *Sender);
        void __fastcall BA8Click(TObject *Sender);
        void __fastcall BA9Click(TObject *Sender);
        void __fastcall BB1Click(TObject *Sender);
        void __fastcall BB2Click(TObject *Sender);
        void __fastcall BB3Click(TObject *Sender);
        void __fastcall BB4Click(TObject *Sender);
        void __fastcall BB5Click(TObject *Sender);
        void __fastcall BB6Click(TObject *Sender);
        void __fastcall BB7Click(TObject *Sender);
        void __fastcall BB8Click(TObject *Sender);
        void __fastcall BB9Click(TObject *Sender);
        void __fastcall BB10Click(TObject *Sender);
        void __fastcall BC1Click(TObject *Sender);
        void __fastcall BC2Click(TObject *Sender);
        void __fastcall BC3Click(TObject *Sender);
        void __fastcall BC4Click(TObject *Sender);
        void __fastcall BC5Click(TObject *Sender);
        void __fastcall BC6Click(TObject *Sender);
        void __fastcall BC7Click(TObject *Sender);
        void __fastcall BC8Click(TObject *Sender);
        void __fastcall BC9Click(TObject *Sender);
        void __fastcall BC10Click(TObject *Sender);
        void __fastcall BD1Click(TObject *Sender);
        void __fastcall BD2Click(TObject *Sender);
        void __fastcall BD3Click(TObject *Sender);
        void __fastcall BD4Click(TObject *Sender);
        void __fastcall BD5Click(TObject *Sender);
        void __fastcall BD6Click(TObject *Sender);
        void __fastcall BD7Click(TObject *Sender);
        void __fastcall BD8Click(TObject *Sender);
        void __fastcall BD9Click(TObject *Sender);
        void __fastcall BD10Click(TObject *Sender);
        void __fastcall BitComprarClick(TObject *Sender);
        void __fastcall VerGrupos2Click(TObject *Sender);
        void __fastcall Principal1Click(TObject *Sender);
        void __fastcall Salir1Click(TObject *Sender);
        void __fastcall Acercade1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TFComprarEntr(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFComprarEntr *FComprarEntr;
//---------------------------------------------------------------------------
#endif
