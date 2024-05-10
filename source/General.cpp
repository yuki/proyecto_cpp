//cabecera propia
#include "General.h"
//demas includes, que de ponerlo en el "General.h" nos da errores... asi que
//asi que he decidido dejarlo aqui, a pesar de no ser de estilo "bonito".
#include "Grupo.h"

typedef deque<Grupo> Grupdeq;      //por vagueza
typedef Grupdeq::iterator Grupit;  //igual :D

//Variable externa que se encarga de guardar en memoria todos los grupos que
//tenemos actualmente, antes de finalizar el programa, se volcaran a fichero.
Grupdeq grupos;



/*****************************************************************************
* INICIO: Funcion que ni recibe ni devuelve nada
* Esta funcion es la primera que se llama al iniciarse el programa. Lo que hace
* es mirar el fichero "Grupos.dat", leerlo e introducir en el deque los grupos
* que estaban almacenados en el fichero.
******************************************************************************/
void Inicio (void)
{
    extern deque<Grupo> grupos; //declarado arriba del todo
    char* desde=new char[11];
    strcpy(desde,"Grupos.dat");
    ifstream entrada (desde,ios_base::binary);
    if (entrada){
        Grupo cual;
        cual.Leer(entrada); //leemos el fichero
        while (!entrada.eof()){
            grupos.push_back(cual); //lo insertamos al final del deque
            cual.Leer(entrada); //leemos el fichero
        }
    }
    entrada.close();
    delete desde;//que no se nos olvide
}

/*****************************************************************************
 * FINAL: Funcion que ni recibe ni devuelve nada;
 * Esta funcion es la ultima que se llama, justo antes de cerrar el programa, y
 * su funcion es recorrer el deque desde la primera posicion hasta la ultima,
 * guardando cada posicion en el fichero "Griupos.dat". Despues liberara el deque.
******************************************************************************/
void Final (void)
{
    extern deque<Grupo> grupos; //variable externa declarada mas arriba
    char* donde=new char[11];
    strcpy(donde,"Grupos.dat");
    ofstream salida (donde,ios_base::binary);
    for (Grupit it=grupos.begin(); it!=grupos.end(); it++){
        Grupo medio=*it; //asignamos lo que apunta el iterador a una var
        medio.Salvar(salida);  //lo guardamos en un fichero
       // Sigfile (donde);
    }
    salida.close();
    delete donde;//que no se nos olvide
}

/*****************************************************************************
 * CUANTOS: Funcion que recibe una cadena de chars y devuelve un entero.
 * Esta funcion se encarga de ir mirando mediante la cadena de chars si existe
 * un fichero con ese nombre, en ese caso se aumenta el entero 'numero', que
 * sera devuelto, para conocer el numero de ficheros que tenemos.
 * ***************************************************************************/
int Cuantos (char* desde)
{
    int numero=0;
    for (int i=1;i<MAX_GRUPOS;i++){
        ifstream entrada (desde);
        if (entrada){
            numero++;
            entrada.close();    // cerramos el fichero abierto
            Sigfile (desde);
        }
        else break;     //si el fichero no existe salimos del bucle
    }
    return numero;
}

/******************************************************************************
 * SIGFILE: Funcion que recibe un char* como parametro sin devolver nada.
 * Esta funcion aumenta los chars 0 y 1 dependiendo de como esten, es decir, lo
 * aumentan como si las dos primeras letras fueran numeros, para indicar el numero
 * de archivo.
*******************************************************************************/
void Sigfile (char* cual)
{
    if (cual[1]=='9'){
        cual[0]++;     //aumentamos en una decena de 09 a 10.dat
        cual[1]=0;     //ponemos a 0 la unidad de 09 a 10.dat
    }
    else cual[1]++;
}
