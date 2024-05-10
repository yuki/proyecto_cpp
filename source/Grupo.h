#ifndef ClaseGrupoH
#define ClaseGrupoH

#include "General.h"
#include "Fecha.h"
#include "Butacas.h"
//#include "Validaciones.h"
#include <fstream.h>
#include <iostream.h>

/*****************************************************************************
 * GRUPO-CLASE: En esta clase se utilizan las clases Butacas y Fechas.
 *****************************************************************************/

using namespace std;

class Grupo
{
  protected:
    char* nombre;               //nombre del grupo
    char* gira;                 //nombre de la gira del grupo
    Fecha fechas[MAX_CONCER];     /* Usamos la clase Fecha creada por nosotros
                                   * para llevar las fechas */
    Butacas hay [MAX_CONCER]; /* usamos la clase butacas implementada por
                              * nosotros para para llevar un recuento de las
                              * que tenemos libre u ocupadas, y la recaudacion
                              * de cada uno de los conciertos */
    double precio[MAX_CONCER];  /* hacemos un array de double's para los precios.
                                 * El [0] sera el precio barato;
                                 * el [1] sera el precio medio;
                                 * el [2] sera el precio caro */
  public:
    Grupo (void);  //constructor
    ~Grupo ();     //destructor
    Grupo& operator=(const Grupo&); //sobrecarga del operador '='
    Grupo (const Grupo &);   //  constructor "copy"

    void Leer(ifstream &);
    void Salvar (ofstream &);

    void SetNombre (int,char *);
    char* GetNombre (void);

    void SetGira (int, char*);
    char* GetGira (void);

    void SetFDia (int, char*);
    char* GetFDia (int);

    void SetFHora (int, char*);
    char* GetFHora (int);

    void SetBFalse (int,int,int);
    void SetBTrue (int,int,int);
    bool GetBEstado (int,int,int);

    void SetRecau (int, double);
    double GetRecau (int);

    void SetPrecio (int,double);
    double GetPrecio (int);

}; //fin de la clase grupo

#endif //GRUPO_H
