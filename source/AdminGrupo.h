//---------------------------------------------------------------------------

#ifndef AdminGrupoH
#define AdminGrupoH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <QControls.hpp>
#include <QStdCtrls.hpp>
#include <QForms.hpp>
#include <QMask.hpp>
#include <QButtons.hpp>
//-----------------------------------------------------
                                                       
//includes del GUI
//includes del GUI
#include "Bienvenida.h"
#include "ComprEntradas.h"
#include "VerGrupos.h"
#include "AcercaDe.h"

#include "Administrar.h"
#include "CambiarPass.h"
#include "Recaudacion.h"
#include "Eliminar.h"

//include del .h y .cpp que mira las validaciones
#include "Validaciones.h"

//include de los ficheros del programa
#include "General.h"
#include "Butacas.h"
#include "Grupo.h"
#include "Fecha.h"


#include <QMenus.hpp>
#include <QTypes.hpp>

//---------------------------------------------------------------------------
class TFAgreGrupos : public TForm
{
__published:	// IDE-managed Components
        TLabel *LTitulo;
        TLabel *Lnombre;
        TLabel *LPrecios;
        TLabel *PrecBara;
        TLabel *PrecMedio;
        TLabel *PrecCaro;
        TEdit *NomGrupo;
        TMaskEdit *MaskPrec1;
        TMaskEdit *MaskPrec2;
        TMaskEdit *MaskPrec3;
        TBitBtn *AgreGrupOK;
        TBitBtn *AgreGrupNO;
        TLabel *LAgrFechas;
        TMaskEdit *MaskFecha1;
        TMaskEdit *MaskFecha2;
        TMaskEdit *MaskFecha3;
        TLabel *LHora;
        TMaskEdit *MaskHora1;
        TMaskEdit *MaskHora2;
        TMaskEdit *MaskHora3;
        TLabel *Lddmm;
        TLabel *Lhhmm;
        TEdit *NomGira;
        TLabel *LGira;
        TLabel *L1;
        TLabel *L2;
        TLabel *L3;
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
        void __fastcall AgreGrupOKClick(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall FormShow(TObject *Sender);
        void __fastcall VerGrupos1Click(TObject *Sender);
        void __fastcall VerGrupos2Click(TObject *Sender);
        void __fastcall Principal1Click(TObject *Sender);
        void __fastcall Salir1Click(TObject *Sender);
        void __fastcall EliminarGrupo1Click(TObject *Sender);
        void __fastcall CambiarPassword1Click(TObject *Sender);
        void __fastcall Recaudacin1Click(TObject *Sender);
        void __fastcall Acercade1Click(TObject *Sender);

private:	// User declarations
public:		// User declarations
        __fastcall TFAgreGrupos(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFAgreGrupos *FAgreGrupos;
//---------------------------------------------------------------------------
#endif
