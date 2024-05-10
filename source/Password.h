//---------------------------------------------------------------------------

#ifndef PasswordH
#define PasswordH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <QControls.hpp>
#include <QStdCtrls.hpp>
#include <QForms.hpp>
#include <QButtons.hpp>
#include <QMask.hpp>

//include de los GUI's
#include "Administrar.h"
#include "Bienvenida.h"
//include del programa
#include "pass.h"

//---------------------------------------------------------------------------
class TFPass : public TForm
{
__published:	// IDE-managed Components
        TMaskEdit *MaskPass;
        TLabel *LIntro;
        TBitBtn *Bitok;
        TBitBtn *BitBtn1;
        void __fastcall BitBtn1Click(TObject *Sender);
        void __fastcall BitokClick(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall FormShow(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TFPass(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFPass *FPass;
//---------------------------------------------------------------------------
#endif
