//---------------------------------------------------------------------------

#include <clx.h>
#pragma hdrstop

#include "ComprEntradas.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.xfm"
TFComprarEntr *FComprarEntr;


//---------------------------------------------------------------------------
__fastcall TFComprarEntr::TFComprarEntr(TComponent* Owner)
        : TForm(Owner)
{
}

//---------------------------------------------------------------------------

void __fastcall TFComprarEntr::BVolverClick(TObject *Sender)
{
    FComprarEntr->Hide();
    FBienveni->Show();
}
//---------------------------------------------------------------------------

void __fastcall TFComprarEntr::FormShow(TObject *Sender)
{
     Clearear(); //funcion en "Comprar.h"
     //el Barray es un array con los 40 botones de butacas.
     TButton* Barray[4][10]={{BA1,BA2,BA3,BA4,BA5,BA6,BA7,BA8,BA9,BA10},{BB1,BB2,BB3,BB4,BB5,BB6,BB7,BB8,BB9,BB10},{BC1,BC2,BC3,BC4,BC5,BC6,BC7,BC8,BC9,BC10},{BD1,BD2,BD3,BD4,BD5,BD6,BD7,BD8,BD9,BD10}};
     AlAparecer(Barray); //en "Comprar.h"
}
//---------------------------------------------------------------------------

void __fastcall TFComprarEntr::ListGruposClick(TObject *Sender)
{
    AddFechas (ListGrupos->ItemIndex); //en "Comprar.h"
}
//---------------------------------------------------------------------------

void __fastcall TFComprarEntr::FormClose(TObject *Sender,
      TCloseAction &Action)
{
    Clearear(); //Funcion en "Comprar.h"
    FBienveni->Show();
}
//---------------------------------------------------------------------------

void __fastcall TFComprarEntr::FormHide(TObject *Sender)
{
    Clearear(); //en "Comprar.h"
}
//---------------------------------------------------------------------------

void __fastcall TFComprarEntr::ListFechasClick(TObject *Sender)
{
        //el Barray es un array con los 40 botones de butacas.
        TButton* Barray[FILAS][NUMERO]={{BA1,BA2,BA3,BA4,BA5,BA6,BA7,BA8,BA9,BA10},{BB1,BB2,BB3,BB4,BB5,BB6,BB7,BB8,BB9,BB10},{BC1,BC2,BC3,BC4,BC5,BC6,BC7,BC8,BC9,BC10},{BD1,BD2,BD3,BD4,BD5,BD6,BD7,BD8,BD9,BD10}};
        SelFecha (ListFechas->ItemIndex, ListGrupos->ItemIndex, Barray);
}
//---------------------------------------------------------------------------

void __fastcall TFComprarEntr::BA1Click(TObject *Sender)
{
    Ecoste->Text=AnsiString(SelBut(ListGrupos->ItemIndex, 0, BA1) +
                        AnsiString (Ecoste->Text).ToDouble());
}
//---------------------------------------------------------------------------

void __fastcall TFComprarEntr::BA10Click(TObject *Sender)
{
    Ecoste->Text=AnsiString(SelBut(ListGrupos->ItemIndex, 0, BA10) +
                        AnsiString (Ecoste->Text).ToDouble());
}
//---------------------------------------------------------------------------

void __fastcall TFComprarEntr::BA2Click(TObject *Sender)
{
    Ecoste->Text=AnsiString(SelBut(ListGrupos->ItemIndex, 0, BA2) +
                        AnsiString (Ecoste->Text).ToDouble());
}
//---------------------------------------------------------------------------

void __fastcall TFComprarEntr::BA3Click(TObject *Sender)
{
    Ecoste->Text=AnsiString(SelBut(ListGrupos->ItemIndex, 0, BA3) +
                        AnsiString (Ecoste->Text).ToDouble());
}
//---------------------------------------------------------------------------

void __fastcall TFComprarEntr::BA4Click(TObject *Sender)
{
    Ecoste->Text=AnsiString(SelBut(ListGrupos->ItemIndex, 0, BA4) +
                        AnsiString (Ecoste->Text).ToDouble());
}
//---------------------------------------------------------------------------

void __fastcall TFComprarEntr::BA5Click(TObject *Sender)
{
    Ecoste->Text=AnsiString(SelBut(ListGrupos->ItemIndex, 0, BA5) +
                        AnsiString (Ecoste->Text).ToDouble());
}
//---------------------------------------------------------------------------

void __fastcall TFComprarEntr::BA6Click(TObject *Sender)
{
    Ecoste->Text=AnsiString(SelBut(ListGrupos->ItemIndex, 0, BA6) +
                        AnsiString (Ecoste->Text).ToDouble());
}
//---------------------------------------------------------------------------

void __fastcall TFComprarEntr::BA7Click(TObject *Sender)
{
    Ecoste->Text=AnsiString(SelBut(ListGrupos->ItemIndex, 0, BA7) +
                        AnsiString (Ecoste->Text).ToDouble());
}
//---------------------------------------------------------------------------

void __fastcall TFComprarEntr::BA8Click(TObject *Sender)
{
    Ecoste->Text=AnsiString(SelBut(ListGrupos->ItemIndex, 0, BA8) +
                        AnsiString (Ecoste->Text).ToDouble());
}
//---------------------------------------------------------------------------

void __fastcall TFComprarEntr::BA9Click(TObject *Sender)
{
    Ecoste->Text=AnsiString(SelBut(ListGrupos->ItemIndex, 0, BA9) +
                        AnsiString (Ecoste->Text).ToDouble());
}
//---------------------------------------------------------------------------

void __fastcall TFComprarEntr::BB1Click(TObject *Sender)
{
    Ecoste->Text=AnsiString(SelBut(ListGrupos->ItemIndex, 0, BB1) +
                        AnsiString (Ecoste->Text).ToDouble());
}
//---------------------------------------------------------------------------

void __fastcall TFComprarEntr::BB2Click(TObject *Sender)
{
    Ecoste->Text=AnsiString(SelBut(ListGrupos->ItemIndex, 1, BB2) +
                        AnsiString (Ecoste->Text).ToDouble());
}
//---------------------------------------------------------------------------

void __fastcall TFComprarEntr::BB3Click(TObject *Sender)
{
    Ecoste->Text=AnsiString(SelBut(ListGrupos->ItemIndex, 1, BB3) +
                        AnsiString (Ecoste->Text).ToDouble());
}
//---------------------------------------------------------------------------

void __fastcall TFComprarEntr::BB4Click(TObject *Sender)
{
    Ecoste->Text=AnsiString(SelBut(ListGrupos->ItemIndex, 1, BB4) +
                        AnsiString (Ecoste->Text).ToDouble());
}
//---------------------------------------------------------------------------

void __fastcall TFComprarEntr::BB5Click(TObject *Sender)
{
    Ecoste->Text=AnsiString(SelBut(ListGrupos->ItemIndex, 1, BB5) +
                        AnsiString (Ecoste->Text).ToDouble());
}
//---------------------------------------------------------------------------

void __fastcall TFComprarEntr::BB6Click(TObject *Sender)
{
    Ecoste->Text=AnsiString(SelBut(ListGrupos->ItemIndex, 1, BB6) +
                        AnsiString (Ecoste->Text).ToDouble());
}
//---------------------------------------------------------------------------

void __fastcall TFComprarEntr::BB7Click(TObject *Sender)
{
    Ecoste->Text=AnsiString(SelBut(ListGrupos->ItemIndex, 1, BB7) +
                        AnsiString (Ecoste->Text).ToDouble());
}
//---------------------------------------------------------------------------

void __fastcall TFComprarEntr::BB8Click(TObject *Sender)
{
    Ecoste->Text=AnsiString(SelBut(ListGrupos->ItemIndex, 1, BB8) +
                        AnsiString (Ecoste->Text).ToDouble());
}
//---------------------------------------------------------------------------

void __fastcall TFComprarEntr::BB9Click(TObject *Sender)
{
    Ecoste->Text=AnsiString(SelBut(ListGrupos->ItemIndex, 1, BB9) +
                        AnsiString (Ecoste->Text).ToDouble());
}
//---------------------------------------------------------------------------

void __fastcall TFComprarEntr::BB10Click(TObject *Sender)
{
    Ecoste->Text=AnsiString(SelBut(ListGrupos->ItemIndex, 0, BB10) +
                        AnsiString (Ecoste->Text).ToDouble());
}
//---------------------------------------------------------------------------

void __fastcall TFComprarEntr::BC1Click(TObject *Sender)
{
    Ecoste->Text=AnsiString(SelBut(ListGrupos->ItemIndex, 0, BC1) +
                        AnsiString (Ecoste->Text).ToDouble());
}
//---------------------------------------------------------------------------

void __fastcall TFComprarEntr::BC2Click(TObject *Sender)
{
    Ecoste->Text=AnsiString(SelBut(ListGrupos->ItemIndex, 1, BC2) +
                        AnsiString (Ecoste->Text).ToDouble());
}
//---------------------------------------------------------------------------

void __fastcall TFComprarEntr::BC3Click(TObject *Sender)
{
    Ecoste->Text=AnsiString(SelBut(ListGrupos->ItemIndex, 2, BC3) +
                        AnsiString (Ecoste->Text).ToDouble());
}
//---------------------------------------------------------------------------

void __fastcall TFComprarEntr::BC4Click(TObject *Sender)
{
    Ecoste->Text=AnsiString(SelBut(ListGrupos->ItemIndex, 2, BC4) +
                        AnsiString (Ecoste->Text).ToDouble());
}
//---------------------------------------------------------------------------

void __fastcall TFComprarEntr::BC5Click(TObject *Sender)
{
    Ecoste->Text=AnsiString(SelBut(ListGrupos->ItemIndex, 2, BC5) +
                        AnsiString (Ecoste->Text).ToDouble());
}
//---------------------------------------------------------------------------

void __fastcall TFComprarEntr::BC6Click(TObject *Sender)
{
    Ecoste->Text=AnsiString(SelBut(ListGrupos->ItemIndex, 2, BC6) +
                        AnsiString (Ecoste->Text).ToDouble());
}
//---------------------------------------------------------------------------

void __fastcall TFComprarEntr::BC7Click(TObject *Sender)
{
    Ecoste->Text=AnsiString(SelBut(ListGrupos->ItemIndex, 2, BC7) +
                        AnsiString (Ecoste->Text).ToDouble());
}
//---------------------------------------------------------------------------

void __fastcall TFComprarEntr::BC8Click(TObject *Sender)
{
    Ecoste->Text=AnsiString(SelBut(ListGrupos->ItemIndex, 2, BC8) +
                        AnsiString (Ecoste->Text).ToDouble());
}
//---------------------------------------------------------------------------

void __fastcall TFComprarEntr::BC9Click(TObject *Sender)
{
     Ecoste->Text=AnsiString(SelBut(ListGrupos->ItemIndex, 1, BC9) +
                        AnsiString (Ecoste->Text).ToDouble());
}
//---------------------------------------------------------------------------

void __fastcall TFComprarEntr::BC10Click(TObject *Sender)
{
    Ecoste->Text=AnsiString(SelBut(ListGrupos->ItemIndex, 0, BC10) +
                        AnsiString (Ecoste->Text).ToDouble());
}
//---------------------------------------------------------------------------

void __fastcall TFComprarEntr::BD1Click(TObject *Sender)
{
    Ecoste->Text=AnsiString(SelBut(ListGrupos->ItemIndex, 0, BD1) +
                        AnsiString (Ecoste->Text).ToDouble());
}
//---------------------------------------------------------------------------

void __fastcall TFComprarEntr::BD2Click(TObject *Sender)
{
    Ecoste->Text=AnsiString(SelBut(ListGrupos->ItemIndex, 1, BD2) +
                        AnsiString (Ecoste->Text).ToDouble());
}
//---------------------------------------------------------------------------

void __fastcall TFComprarEntr::BD3Click(TObject *Sender)
{
    Ecoste->Text=AnsiString(SelBut(ListGrupos->ItemIndex, 2, BD3) +
                        AnsiString (Ecoste->Text).ToDouble());
}
//---------------------------------------------------------------------------

void __fastcall TFComprarEntr::BD4Click(TObject *Sender)
{
    Ecoste->Text=AnsiString(SelBut(ListGrupos->ItemIndex, 2, BD4) +
                        AnsiString (Ecoste->Text).ToDouble());
}
//---------------------------------------------------------------------------

void __fastcall TFComprarEntr::BD5Click(TObject *Sender)
{
    Ecoste->Text=AnsiString(SelBut(ListGrupos->ItemIndex, 2, BD5) +
                        AnsiString (Ecoste->Text).ToDouble());
}
//---------------------------------------------------------------------------

void __fastcall TFComprarEntr::BD6Click(TObject *Sender)
{
    Ecoste->Text=AnsiString(SelBut(ListGrupos->ItemIndex, 2, BD6) +
                        AnsiString (Ecoste->Text).ToDouble());
}
//---------------------------------------------------------------------------

void __fastcall TFComprarEntr::BD7Click(TObject *Sender)
{
    Ecoste->Text=AnsiString(SelBut(ListGrupos->ItemIndex, 2, BD7) +
                        AnsiString (Ecoste->Text).ToDouble());
}
//---------------------------------------------------------------------------

void __fastcall TFComprarEntr::BD8Click(TObject *Sender)
{
    Ecoste->Text=AnsiString(SelBut(ListGrupos->ItemIndex, 2, BD8) +
                        AnsiString (Ecoste->Text).ToDouble());
}
//---------------------------------------------------------------------------

void __fastcall TFComprarEntr::BD9Click(TObject *Sender)
{
    Ecoste->Text=AnsiString(SelBut(ListGrupos->ItemIndex, 1, BD9) +
                        AnsiString (Ecoste->Text).ToDouble());
}
//---------------------------------------------------------------------------

void __fastcall TFComprarEntr::BD10Click(TObject *Sender)
{
    Ecoste->Text=AnsiString(SelBut(ListGrupos->ItemIndex, 0, BD10) +
                        AnsiString (Ecoste->Text).ToDouble());
}
//---------------------------------------------------------------------------

void __fastcall TFComprarEntr::BitComprarClick(TObject *Sender)
{
     TButton* Barray[4][10]={{BA1,BA2,BA3,BA4,BA5,BA6,BA7,BA8,BA9,BA10},{BB1,BB2,BB3,BB4,BB5,BB6,BB7,BB8,BB9,BB10},{BC1,BC2,BC3,BC4,BC5,BC6,BC7,BC8,BC9,BC10},{BD1,BD2,BD3,BD4,BD5,BD6,BD7,BD8,BD9,BD10}};
     Comprando (ListGrupos->ItemIndex, ListFechas->ItemIndex, Barray);
}
//---------------------------------------------------------------------------

void __fastcall TFComprarEntr::VerGrupos2Click(TObject *Sender)
{
    FComprarEntr->Hide();
    FVerGrupos->Show();
}
//---------------------------------------------------------------------------

void __fastcall TFComprarEntr::Principal1Click(TObject *Sender)
{
     FComprarEntr->Hide();
     FBienveni->Show();
}
//---------------------------------------------------------------------------

void __fastcall TFComprarEntr::Salir1Click(TObject *Sender)
{
    FBienveni->Close();
}
//---------------------------------------------------------------------------

void __fastcall TFComprarEntr::Acercade1Click(TObject *Sender)
{
   FAcercaDe->Show();
}
//---------------------------------------------------------------------------

