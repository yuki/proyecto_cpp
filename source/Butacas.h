#ifndef ButacasH
#define ButacasH
#include <fstream.h>
#include <iostream.h>
using namespace std;
//includes del proyecto
#include "General.h"

/*****************************************************************************
 * BUTACAS-CLASE: Esta clase lleva el estado de las butacas libre y ocupadas,
 * junto con la recaudacion (esta clase sera una representacion). "Categoria"
 * nos sirve para conocer la categoria de cada asiento (si es caro, barato o de
 * de precio medio), esto no se guardara en los ficheros.
******************************************************************************/
class Butacas
{
    protected:
        bool ocupada[FILAS][NUMERO]; // está la butaca [x][y] ocupada?
                                    // true=SI, false=NO
        int categoria [FILAS][NUMERO];
        double recaudacion;         //indica el dinero recaudado
    
    public:
        Butacas(void);      //metodo constructor
        void Salvar (ofstream &);
        void Leer (ifstream &);

        bool ComoEsta(int, int);
        const bool ComoEstaC(int, int)const;

        void CambiarTrue(int, int);
        void CambiarFalse(int, int);

        int GetCategoria (int, int);

        double GetRecau (void);
        const double GetRecauC (void) const;

        void SetRecau (double);
        void SetRecauC (const double);

        void SetEstado (bool x, int a, int b);
};


#endif



