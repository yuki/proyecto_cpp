/***************************************************************************
 * Aqui mostramos las variables predefinidas.
 ***************************************************************************/
#ifndef GeneralH
#define GeneralH
//includes necesarios.
#include <stdio.h>
#include <fstream.h>
#include <iostream.h>
#include <deque>
using namespace std;



#define FILAS 4		//Nº de filas de asientos que tiene el teatro.
#define NUMERO 10		//Nº de columnas de asientos que tiene el teatro.

#define MAX_GRUPOS  15     // numero maximo de grupos que puede haber
#define MAX_CONCER  3      // numero maximo de conciertos por grupo
#define PRECIOS_DIF 3      // cuantos precios diferentes hay por grupo

//#include "ComprEntradas.h"

//Funciones que hacen de intermedio entre el GUI y las clases.
void Inicio (void);
void Final (void);
int Cuantos (char*);
void Sigfile (char*);

#endif  
