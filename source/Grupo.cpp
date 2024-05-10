//cabecera propia:
#include "Grupo.h"


/****************************************************************************
* GRUPO: Funcion constructora de la clase del mismo nombre
* Esta funcion inicializa el precio a 0, y el nombre y la gira.
*****************************************************************************/
Grupo::Grupo (void)
{
    nombre="";
    gira="";
    for (int i=0;i<MAX_CONCER;i++){
        precio[i]=0;
    }
}

Grupo::~Grupo ()
{
    delete nombre;
    delete gira;
}

Grupo& Grupo::operator=(const Grupo& c)
{
    this->nombre=new char[strlen (c.nombre)];
    strcpy(nombre,c.nombre);
    this->gira=new char[strlen (c.gira)];
    strcpy (gira,c.gira);
    for (int i=0;i<MAX_CONCER;i++){
         this->fechas[i].SetDiaC(c.fechas[i].GetDiaC());
         this->fechas[i].SetHoraC(c.fechas[i].GetHoraC());
         this->precio[i]=c.precio[i];
         this->hay[i].SetRecauC(c.hay[i].GetRecauC());
         for (int j=0;j<FILAS;j++)
             for(int k=0;k<NUMERO;k++)
                 this->hay[i].SetEstado(c.hay[i].ComoEstaC(j,k),j,k);
    }
    return *this;
}

Grupo::Grupo (const Grupo &c)
{
    this->nombre=new char[strlen(c.nombre)+1];
    strcpy(nombre,c.nombre);
    this->gira=new char[strlen(c.gira)+1];
    strcpy(gira,c.gira);
    for (int i=0;i<MAX_CONCER;i++){
        this->fechas[i].SetDiaC(c.fechas[i].GetDiaC());
        this->fechas[i].SetHoraC(c.fechas[i].GetHoraC());
        this->precio[i]=c.precio[i];
        this->hay[i].SetRecauC(c.hay[i].GetRecauC());
        for (int h=0;h<FILAS;h++)
            for (int j=0;j<NUMERO;j++)
                this->hay[i].SetEstado(c.hay[i].ComoEstaC(h,j),h,j);

    }
}


/****************************************************************************
 * LEER: Funcion que recibe el nombre del grupo como un objeto, y como para-
 * metro recibe el nombre del fichero de donde se va a leer la informacion
 * (todo ello de un fichero binarios-->"ios::binary").
 * 
 * La finalidad es abrir un fichero con el nombre recibido y leer el objeto
 * contenido en este, pasandolo a una variable intermedia para que despues
 * podamos cerrar el fichero y devolver el contenido.
 ***************************************************************************/

void Grupo::Leer (ifstream& entrada)
{
   // ifstream entrada (dedonde,ios_base::binary);
    if (entrada){
        int n;
        int g;
        entrada.read((char*)&n,sizeof (n));
        this->nombre=new char[n];
        entrada.read(nombre,n);
        entrada.read((char*)&g,sizeof(g));
        this->gira=new char[g];
        entrada.read(gira,g);
        for (int i=0;i<MAX_CONCER;i++){
            entrada.read((char*)&precio[i],sizeof(precio[i]));
            hay[i].Leer(entrada);
            fechas[i].Leer(entrada);
        }
        //entrada.close();//cerramos el fichero
    }
   // else Error(0);
   // entrada.close();        //cerramos el fichero
}


/****************************************************************************
 * SALVAR: Funcion que recibe un  grupo como un objeto, y como parametro
 * recibe el nombre del fichero donde se va a guardar (en binario).
 *
 * La finalidad es abrir un fichero con el nombre recibido y guardar el objeto
 * recibido como parametro en el fichero, al finalizar cerramos el fichero.
 * Para guardar el objeto llamamos a diferentes funciones implementadas en sus
 * respectivas clases.
 * **************************************************************************/

void Grupo::Salvar(ofstream &salida)
{
  // ofstream salida (donde,ios_base::binary);
   if (salida){
        int n=strlen(this->nombre)+1;
        int g=strlen (this->gira)+1;
        salida.write((char*)&n,sizeof (n));
        salida.write(nombre,n);
        salida.write((char*)&g,sizeof(g));
        salida.write(gira,g);
        for (int i=0;i<MAX_CONCER;i++){
            salida.write((char*)&precio[i],sizeof(precio[i]));
            hay[i].Salvar(salida);
            fechas[i].Salvar(salida);

        }
        //Error(2);
        //salida.close();
   }
   ///else
      // Error(1);
   //salida.close();  //cerramos el fichero
}       //fin de la funcion salvar

/****************************************************************************
* SETNOMBRE: Funcion que recibe como parametros un int y un char* no devolviendo
* nada
* Esta funcion copia el char* a la variable nombre de la clase Grupo
*****************************************************************************/
void Grupo::SetNombre (int num,char * x)
{
    nombre=new char[num+1];
    strcpy(nombre,x);
    nombre[num]='\0';
   /* char *d=new char[num];
    strcpy(d,x);
    this->nombre=string (d);
    delete(d);*/ //que no se nos olvide, que luego nos quedamos sin memoria :D
}

/*****************************************************************************
* GETNOMBRE: Funcion que devuelve un string
* Esta funcion devuelve el nombre del grupo.
******************************************************************************/
char* Grupo::GetNombre (void)
{
   return nombre;
}

/****************************************************************************
* SETGIRA: Funcion que recibe como parametros un int y un char* no devolviendo
* nada
* Esta funcion copia el char* a la variable gira de la clase Grupo
*****************************************************************************/
void Grupo::SetGira (int num, char* x)
{
    gira=new char[num+1];
    strcpy(gira,x);
    gira[num]='\0';
    /*char *d=new char[num];
    strcpy(d,x);
    this->gira=string (d);
    delete(d);*/ //borramos la memoria
}

/*****************************************************************************
* GETGIRA: Funcion que devuelve un string
* Esta funcion devuelve la gira del grupo.
******************************************************************************/
char* Grupo::GetGira (void)
{
   return this->gira;
}

/****************************************************************************
* SETFDIA: Funcion que recibe como parametros un int y un char* no devolviendo
* nada
* Esta funcion llama a la funcion miembro de la clase Fecha, a la cual le pasa
* el char* para copiar el char* a la variable dia especificada
*****************************************************************************/
void Grupo::SetFDia (int cual, char* x)
{
    this->fechas[cual].SetDia(x);
}

/*****************************************************************************
* GETFDIA: Funcion que devuelve un string y se le pasa un int como parametro
* Esta funcion devuelve el dia solicitado por el int, usando la funcion miembro
* de la clase fecha.
******************************************************************************/
char* Grupo::GetFDia (int cual)
{
    return this->fechas[cual].GetDia();
}

/****************************************************************************
* SETFHORA: Funcion que recibe como parametros un int y un char* no devolviendo
* nada
* Esta funcion llama a la funcion miembro de la clase Fecha, a la cual le pasa
* el char* para copiar el char* a la variable hora especificada
*****************************************************************************/
void Grupo::SetFHora (int cual, char* x)
{
    this->fechas[cual].SetHora(x);
}

/*****************************************************************************
* GETFHORA: Funcion que devuelve un string y se le pasa un int como parametro
* Esta funcion devuelve la hora solicitada por el int, usando la funcion miembro
* de la clase fecha.
******************************************************************************/
char* Grupo::GetFHora (int cual)
{
    return this->fechas[cual].GetHora();
}

/*****************************************************************************
* SETBFALSE: Funcion que recibe tres ints como parametros.
* Esta funcion llama a la funcion miembro "CambiarFalse" de la clase Butacas.
* Primero se selecciona cual de las actuaciones queremos, y luego se llama a
* dicha funcion para que se ponga a false la butaca seleccionada.
*****************************************************************************/

void Grupo::SetBFalse (int cual,int x,int y)
{
    this->hay[cual].CambiarFalse(x,y);
}

/*****************************************************************************
* SETBTRUE: Funcion que recibe tres ints como parametros.
* Esta funcion llama a la funcion miembro "CambiarTrue" de la clase Butacas.
* Primero se selecciona cual de las actuaciones queremos, y luego se llama a
* dicha funcion para que se ponga a true la butaca seleccionada.
*****************************************************************************/
void Grupo::SetBTrue (int cual,int x,int y)
{
    this->hay[cual].CambiarTrue(x,y);
}

/*****************************************************************************
* SETBFALSE: Funcion que recibe tres ints como parametros.
* Esta funcion llama a la funcion miembro "ComoEsta" de la clase Butacas.
* Primero se selecciona cual de las actuaciones queremos, y luego se llama a
* dicha funcion para ver el estado de la butaca seleccionada.
*****************************************************************************/
bool Grupo::GetBEstado (int cual,int x,int y)
{
    return this->hay[cual].ComoEsta(x,y);
}

/*****************************************************************************
* SETRECAU: Funcion que recibe un int y un float como parametros.
* Esta funcion elige la actuacion deseada mediante el int, y llama a la función
* miembro "SetRecau" de la clase Butacas para guardar asi el float.
*******************************************************************************/
void Grupo::SetRecau (int cual,double cuanto)
{
    //int cuanto=atoi(x);
    this->hay[cual].SetRecau(cuanto);
}

/******************************************************************************
* GETRECAU: Funcion que recibe un int y devuelve un float.
* Esta funcion elige la acuacion deseada mediante el int que se le pasa, y llama
* a la funcion miembro "GetRecau" de la clase Butacas para retornar un float.
******************************************************************************/
double Grupo::GetRecau (int cual)
{
    return this->hay[cual].GetRecau();
}

/*****************************************************************************
* SETPRECIO: Funcion que recibe un int y una char*
* Esta funcion convierte el char* a float (lo dividimos entre 100 porque al
* introducirlo tiene la forma de XX,YY siendo YY dos decimales), despues se guarda
* en la posicion del array "precio" indicada por el int pasado como parametro.
******************************************************************************/
void Grupo::SetPrecio (int cual,double cuanto)
{
   // int i=atoi(cuanto);
   // this->precio[cual]=i;
   //strcpy(precio[cual],cuanto);
   precio[cual]=cuanto;
}

/*****************************************************************************
* GETPRECIO: Funcion que recibe un int como parametro y devuelve un float.
* Accedemos a la posicion del array "precio" indicada por el entero pasado, y
* devolvemos el float que hay en esa posicion.
******************************************************************************/
double Grupo::GetPrecio (int cual)
{
    return this->precio[cual];
}
