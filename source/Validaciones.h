#ifndef ValidacionesH
#define ValidacionesH
#include "AdminGrupo.h"
//#include "ComprEntradas.h"

/*************************************************************************
* En este Validaciones.h aparecen las cabeceras de las funciones que estan
* implementadas en Validaciones.cpp. Estas funciones son las que validan
* los datos metidos en el GUI para el propio programa, en "AdmingGrupo.cpp"
* (como se puede ver, no me he comido la cabeza en el nombre del cpp :-D
**************************************************************************/

void Clarear (void);
bool TodoBien (void);
void AnadirGrupo (bool);
bool GrupoBien (TEdit *);
bool FHBien (TMaskEdit *, bool);
bool PrecioBien (TMaskEdit *);
bool MayorMenorF (TMaskEdit *, TMaskEdit *);
bool MayorMenorP (TMaskEdit *, TMaskEdit *, TMaskEdit *);
void Error (int);

#endif
