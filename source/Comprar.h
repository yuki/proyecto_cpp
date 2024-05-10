#ifndef ComprarH
#define ComprarH

#include "General.h"
#include "ComprEntradas.h"
#include "VerGrupos.h"
/****************************************************************************
 * En este .h y su correspondiente cpp hemos implementado las funciones que
 * tienen que ver con el "ComprEntradas.cpp" y las de "VerGrupos.cpp".
 ****************************************************************************/
//----------------------------------------------------------------------------
/****************************************************************************
 * Las siguientes funciones son del "ComprEntradas.cpp" y tienen
 * que ver con la visualizacion de los datos, y lo correspondiente para hacer
 * que el GUI haga lo que tenga que hacer. Basicamente son poner los botones
 * de un cierto color, y clarear los listbox y edits.
 * Tambien llamaremos a funciones de las clases implementadas por nosotros, para
 * guardar los datos.
 *****************************************************************************/
void AlAparecer(TButton* Barray[FILAS][NUMERO]);
void Comprando (int numgrupo, int numfecha, TButton* Barray[FILAS][NUMERO]);
void Clearear (void);
void AddFechas (int numgrupo);
void SelFecha (int numfecha, int numgrupo, TButton* Barray[FILAS][NUMERO]);
double SelBut (int,int, TButton *);

/*****************************************************************************
 * Las siguientes funciones son para el "VerGrupos.cpp" y basicamente son para
 * visualizar los datos, y hacer los clears.
 *****************************************************************************/
void ClearVer (void);
void ShowVer (void);
void SelGrupo (int numgrupo);


#endif