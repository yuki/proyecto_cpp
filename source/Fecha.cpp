#include "Fecha.h"
#include <iostream.h>

/* **************************************************************************
 * FECHA: Metodo constructor de la clase del mismo nombre.
 * Esta funcion inicializa todos sus campos a '0', con ello sabremos si
 * han sido utilizadas.
 * **************************************************************************/

Fecha::Fecha(void)
{
    strcpy (dia,"00/00");
    strcpy (hora,"00:00");
}

/*****************************************************************************
 * SALVAR: Funcion que recibe como parametro un fichero abiero en modo ofstream
 * para guardar en el los datos de la clase Fecha.
 * Esta funcion guarda en el fichero los componentes de la clase.
 ******************************************************************************/
void Fecha::Salvar (ofstream &salida)
{
    if (salida){
         int n=strlen(this->dia)+1;
         salida.write((char*)&n,sizeof(n));
         salida.write(this->dia,sizeof(this->dia));
         n=strlen(this->hora)+1;
         salida.write((char*)&n,sizeof(n));
         salida.write(this->hora,sizeof(hora));
    }
}


/*****************************************************************************
 * LEER: Funcion que recibe como parametro un fichero abiero en modo ifstream
 * para leer de el los datos de la clase Fecha.
 * Esta funcion lee del fichero los componentes de la clase.
 ******************************************************************************/
void Fecha::Leer (ifstream &entrada)
{
    if (entrada){
         int n;
         entrada.read((char*)&n,sizeof(n));
        // dia=new char[n];
         entrada.read(this->dia,sizeof(this->dia));
         entrada.read((char*)&n,sizeof(n));
        // hora=new char[n];
         entrada.read(this->hora,sizeof(hora));
    }
}

/*****************************************************************************
* SETDIA: Funcion que recibe un int y un char* como parametros.
* Copia el contenido del parametro pasado x, en el objeto dia de la clase Fecha
*****************************************************************************/
void Fecha::SetDia (char* x)
{
    strcpy (dia,x);
}

void Fecha::SetDiaC (const char* x)
{
    strcpy (dia,x);
}

/*****************************************************************************
* GETDIA: Funcion que devuelve un string.
* Devuelve lo contenido en el objeto dia.
******************************************************************************/
char* Fecha::GetDia (void)
{
    return this->dia;
}

const char* Fecha::GetDiaC (void) const
{
    return this->dia;
}

/*****************************************************************************
* SETHORA: Funcion que recibe un int y un char* como parametros.
* Copia el contenido del parametro pasado x, en el objeto hora de la clase Fecha
*****************************************************************************/
void Fecha::SetHora (char* x)
{
   strcpy (hora,x);
}

void Fecha::SetHoraC (const char* x)
{
   strcpy (hora,x);
}

/*****************************************************************************
* GETHORA: Funcion que devuelve un string.
* Devuelve lo contenido en el objeto hora.
******************************************************************************/
char* Fecha::GetHora (void)
{
    return this->hora;
}

const char* Fecha::GetHoraC (void) const
{
    return this->hora;
}
