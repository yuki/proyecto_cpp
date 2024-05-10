//---------------------------------------------------------------------------

#ifndef AcercaDeH
#define AcercaDeH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <QControls.hpp>
#include <QStdCtrls.hpp>
#include <QForms.hpp>

//includes del GUI
#include "Bienvenida.h"
#include <QExtCtrls.hpp>
#include <QGraphics.hpp>

//---------------------------------------------------------------------------
class TFAcercaDe : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *Label5;
        TImage *Image1;
        TLabel *Label2;
        TLabel *Label6;
        void __fastcall BPrincipalClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TFAcercaDe(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFAcercaDe *FAcercaDe;
//---------------------------------------------------------------------------
#endif
