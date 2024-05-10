#include "Butacas.h"


/*****************************************************************************
 * BUTACAS: Metodo constructor de la clase del mismo nombre.
 * Esta funcion lo que hace es poner que todas las butacas estan libres, tanto
 * en la variable entera (poniendo el numero que hay libres), como en el array
 * de bools, que pone todo a false, que quiere decir que NO estan ocupadas
 * Tambien inicializa el array "categoria", con diferente numero (1,2 o 3)
 * para cada apartado dependiendo de sus coordenadas.
 * **************************************************************************/
Butacas::Butacas(void)
{
    recaudacion=0;
    for(int i=0;i<FILAS;i++)
        for (int j=0;j<NUMERO;j++){
            ocupada[i][j]=false; //cuando es FALSE=LIBRE!!!!
            switch (i){
                case 0: categoria[i][j]=0;
                        break;
                case 1: if (j==0 | j==9)
                            categoria[i][j]=0;
                        else categoria[i][j]=1;
                        break;
                case 2:
                case 3: if (j==0 | j==9)
                            categoria[i][j]=0;
                        else
                             if (j==1 | j==8)
                                categoria[i][j]=1;
                             else categoria[i][j]=2;
            }//del switch
        }
}

/*****************************************************************************
 * SALVAR: Funcion que recibe como parametro un fichero abiero en modo ofstream
 * para guardar en el los datos de la clase Butacas.
 * Esta funcion guarda en el fichero los componentes de la clase.
 ******************************************************************************/
void Butacas::Salvar (ofstream &salida)
{
   if (salida){
        salida.write((char*)&recaudacion, sizeof(recaudacion));
        for (int i=0;i<FILAS;i++)
            for (int j=0; j<NUMERO;j++)
                salida.write((char*)&ocupada[i][j], sizeof(bool));
        //Error(2);
   }
}

/*****************************************************************************
 * LEER: Funcion que recibe como parametro un fichero abiero en modo ifstream
 * para leer de el los datos de la clase Butacas.
 * Esta funcion lee del fichero los componentes de la clase.
 ******************************************************************************/
void Butacas::Leer (ifstream &entrada)
{
   if (entrada){
        entrada.read((char*)&recaudacion, sizeof(recaudacion));
        for (int i=0;i<FILAS;i++)
            for (int j=0; j<NUMERO;j++)
                entrada.read((char*)&ocupada[i][j], sizeof(ocupada[i][j]));
        //Error(2);
   }
}

/*****************************************************************************
 * COMOESTA: Funcion que recibe como parametros dos enteros y devuelve un bool.
 * Esta funcion devuelve el estado de la butaca cuya situacion es la posicion
 * marcada por los dos enteros que se pasan como parametros.
 * si devuelve TRUE=OCUPADA, si fuese FALSE=LIBRE.
 * ****************************************************************************/
bool Butacas::ComoEsta(int a, int b)
{
    return this->ocupada[a][b];
}

/******************************************************************************
 * COMOESTAC: Esta funcion es igual que la de arriba, con la diferencia es que
 * esta es llamada desde componentes que son "const", y por lo tanto devuelve
 * un bool const. (esta funcion fue creada para el constructor COPY, ya que
 * con la de arriba aparecian warnings).
 *****************************************************************************/
const bool Butacas::ComoEstaC(int a, int b) const
{
    return this->ocupada[a][b];
}


/*****************************************************************************
 * CAMBIARTRUE: Funcion que recibe dos enteros como parametros.
 * Esta funcion cambia el estado de la butaca determinada por los dos enteros
 * de false a true (es decir, de libre a ocupada). 
 * ****************************************************************************/
void Butacas::CambiarTrue(int a, int b)
{
    this->ocupada[a][b]=true;
}


/*****************************************************************************
 * CAMBIARFALSE: Funcion que recibe dos enteros como parametros.
 * Esta funcion cambia el estado de la butaca determinada por los dos enteros
 * de true a false (es decir, de ocupada a libre). 
 * ****************************************************************************/
void Butacas::CambiarFalse(int a, int b)
{
    this->ocupada[a][b]=false;
}

/****************************************************************************
* GETCATEGORIA: Funcion que recibe dos ints y devuelve otro.
* Esta funcion selecciona el elemento de la variable recaudacion. Selecciona
* el elemento que corresponde con las "coordenadas" pasadas como parametras,
* despues lo devuelve.
*****************************************************************************/
int Butacas::GetCategoria (int x, int y)
{
    return  this->categoria[x][y];
}


/*****************************************************************************
* GETRECAU: Funcion que devuelve un double.
* Esta funcion retorna el double que hay en recaudacion.
*******************************************************************************/
double Butacas::GetRecau (void)
{
    return this->recaudacion;
}
/******************************************************************************
 * GETRECAUC: Esta funcion es igual que la de arriba, con la diferencia es que
 * esta es llamada desde componentes que son "const", y por lo tanto devuelve
 * un bool const. (esta funcion fue creada para el constructor COPY, ya que
 * con la de arriba aparecian warnings).
 *****************************************************************************/
const double Butacas::GetRecauC (void) const
{
    return this->recaudacion;
}

/****************************************************************************
* SETRECAU: Funcion que recibe como parametro un double, sin devolver nada
* Esta funcion mete el valor del double pasado como parametro al objeto
* recaudacion de la clase Butacas en la que estamos.
******************************************************************************/
void Butacas::SetRecau (double x)
{
    this->recaudacion=x;
}
/******************************************************************************
 * SETRECAUC: Esta funcion es igual que la de arriba, con la diferencia es que
 * esta es llamada desde componentes que son "const", y por lo tanto devuelve
 * un bool const. (esta funcion fue creada para el constructor COPY, ya que
 * con la de arriba aparecian warnings).
 *****************************************************************************/
void Butacas::SetRecauC (const double x)
{
    this->recaudacion=x;
}

/******************************************************************************
 * SETESTADO: Recibe un bool y dos ints.
 * Esta funcion mete en la butaca de coordenadas a y b, el bool pasado como
 * parametro.
 ****************************************************************************/
void Butacas::SetEstado (bool x, int a, int b)
{
    this->ocupada[a][b]=x;
}
