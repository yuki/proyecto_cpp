#ifndef PassH
#define PassH

/****************************************************************************
 * PASS.H: Aqui aparecen las funciones que tienen que ver con los archivos
 * "Password.h", "Recaudaciones.h" y "Eliminar.h". Basicamente lo que se hace
 * es leer el password de un fichero, y poder modificarlo, visualizar las recau-
 * daciones, y eliminar un grupo seleccionado.
 *****************************************************************************/
#include <fstream.h>

//includes del proyecto
#include "General.h"
#include "Grupo.h"
#include "Recaudacion.h"
#include "Eliminar.h"

//funciones de "Password.h"
bool LeerPass (char*);
void SalvarPass(char*);

//funciones de "Recaudacion.h"
void VerRecau (TListBox*);
void SelRecau (int numgrupo, TListBox*, TListBox*);

//funcion de "Eliminar.h"
void Eliminar (int numgrupo);


#endif
