//cabecera propia
#include "Comprar.h"

//Las funciones de "ComprEntradas.cpp"

/******************************************************************************
 * ALAPARECER: Funcion que tiene un parametro, un array "bidimensional" de la
 * clase TButton, usada por los botones.
 * Esta funcion es llamada al hacer un show desde "ComprEntradas.cpp".
 * Esta funcion inicializa todos los botones con su color correspondiente,
 * el cual es diferente de la fila y columna en la que se encuentre. Para
 * conocer su categoria nos ayudamos de una variable de la clase Butacas de
 * "Butacas.h", que contiene la categoria para cada "coordenada".
 * Despues recorremos el deque de grupos con un iterador y vamos añadiendo
 * los grupos al "ListGrupos" de "ComprEntradas.cpp"
 *****************************************************************************/
void AlAparecer(TButton* Barray[FILAS][NUMERO])
{
    Butacas b; //variable para ayudar en la inicializacion de los botones
    for (int i=0;i<FILAS;i++)
          for (int j=0;j<NUMERO;j++){
                switch (b.GetCategoria(i,j)){
                        case 0:Barray[i][j]->Color=clOlive;
                               break;
                        case 1:Barray[i][j]->Color=clTeal;
                               break;
                        case 2:Barray[i][j]->Color=clFuchsia;
                               break;
                }
                if (Barray[i][j]->Enabled!=true)
                        Barray[i][j]->Enabled=true;
          }
    extern deque<Grupo> grupos;  //declarado en "General.cpp"
    deque<Grupo>::iterator it;   //un iterador de nuestro deque
    if (!grupos.empty()){
        for (it=grupos.begin();it!=grupos.end();it++)  //recorremos el deque.
            FComprarEntr->ListGrupos->Items->Add(it->GetNombre()); //y vamos añadiendo los nombres
    }
    else Application->MessageBox("Lo sentimos.\n No tenemos ningun concierto\nprevisto ","No hay grupos previstos");
}


void Comprando (int numgrupo, int numfecha, TButton* Barray[FILAS][NUMERO])
{
     bool salir=true;
     for (int i=0;i<FILAS;i++)
            for (int j=0;j<NUMERO;j++)
                 if (Barray[i][j]->Color==clBlack){
                        salir=false;
                        break;
                 }
     if (salir)
           Application->MessageBox("No ha seleccionado ningun asiento.\nDebe seleccionar al menos uno.","Elija asiento");
     else{
          TMessageButton Option;
          TMessageButtons msgButtons;
          msgButtons << smbYes << smbNo << smbCancel;
          Option = Application->MessageBox("Estas segur@ de los asientos?", "Actualizacion", msgButtons, smsWarning, smbYes, smbNo);
          if(Option == smbYes){//guardamos la recaudacion y las butacas ocupadas.
                extern deque<Grupo> grupos;
                Grupo it;
                it=grupos.operator [](numgrupo);
                AnsiString s=AnsiString(FComprarEntr->Ecoste->Text);
                it.SetRecau(numfecha, s.ToDouble());
                for (int i=0;i<FILAS;i++)
                     for (int j=0;j<NUMERO;j++)
                           if (Barray[i][j]->Color==clBlack)
                                it.SetBTrue(numfecha,i,j);
                grupos.operator [](numgrupo)=it;
                Application->MessageBox("Su operacion ha concluido con exito","Operacion concluida");
                FComprarEntr->Hide();
                FBienveni->Show();
          }
          else
              if(Option == smbCancel){
                  FComprarEntr->Hide();
                  FBienveni->Show();
              }
     }
}

/*****************************************************************************
 * CLEAREAR: Funcion que no recibe ni devuelve nada.
 * Esta funcion, como su propio nombre indica, "clear"ea todos los listbox y
 * edit's que hay en "ComprEntrada.h". Como esto se hace varias veces, pues
 * mejor hacer una funcion con ello.
 *****************************************************************************/
void Clearear (void)
{
     FComprarEntr->ListGrupos->Clear();
     FComprarEntr->ListFechas->Clear();
     FComprarEntr->EPrecBarato->Clear();
     FComprarEntr->EPrecMedio->Clear();
     FComprarEntr->EPrecCaro->Clear();
     FComprarEntr->Ecoste->Text=AnsiString(0);
}

/*****************************************************************************
 * ADDFECHAS: Funcion que recibe un unico int, sin devolver nada.
 * El int recibido es el grupo seleccionado en el "ListGrupos" de "ComprEntradas.h".
 * Si se ha seleccionado un grupo (si es distinto de -1) se inicializan los
 * Edit's del form "ComprEntradas.h" con los valores que hay en esa posicion en
 * el deque de grupos, que tiene el mismo orden que el "ListGrupos". Para sacar
 * los valores utilizamos funciones miembro de la clase grupo en "Grupo.h"
 *****************************************************************************/
void AddFechas (int numgrupo)
{
    if (numgrupo==-1)
        Application->MessageBox("No ha seleccionado ningun grupo\n seleccione uno","Seleccione grupo");
    else{
         FComprarEntr->ListFechas->Clear(); //limpiamos este listbox
         extern deque<Grupo> grupos; //declarada en "General.cpp"
         for (int i=0;i<MAX_CONCER;i++)
             FComprarEntr->ListFechas->Items->Add(grupos.operator [](numgrupo).GetFDia(i));
         FComprarEntr->ListFechas->ItemIndex=0;
         FComprarEntr->EPrecBarato->Text=AnsiString(grupos.operator [](numgrupo).GetPrecio(0));
         FComprarEntr->EPrecMedio->Text=AnsiString(grupos.operator [](numgrupo).GetPrecio(1));
         FComprarEntr->EPrecCaro->Text=AnsiString(grupos.operator [](numgrupo).GetPrecio(2));
    }
}

/******************************************************************************
 * SELFECHA: Funcion que recibe dos int's como parametros, junto con un
 * array de "dos dimensiones" de tipos TButtons.
 * Esta función es llamada desde "ComprEntradas.cpp", concretamente al clickear
 * sobre el "listbox" de grupos.
 * Esta funcion recorre en el deque el grupo seleccionado junto con la fecha
 * elejida, para ir mirando el estado de las butacas (con una funcion miembro
 * de la clase Butacas en "Butacas.h" accedida desde la funcion "GetBEstado" de
 * la clase Grupo en "Grupo.h"). Si la butaca es true, quiere decir que está
 * ocupada, por lo que pintamos el boton correspondiente a rojo y le ponemos el
 * "unabled" a "false", para que no se pueda pinchar. Por el contrario, si la
 * butaca es false, repintamos el boton teniendo en cuenta la categoria que es
 * que lo miramos con una variable de la clase Butacas que contiene la categoria
 * de cada posicion de las butacas. (esto de redibujar se hace porque de no
 * hacerlo, si pinchamos sobre otra fecha, se mantendrian las butacas rojas, pero
 * que pertenecen a otra fecha.... espero haberme explicado bien. 
 ******************************************************************************/
void SelFecha (int numfecha, int numgrupo, TButton* Barray[FILAS][NUMERO])
{
    if (numfecha==-1)
        Application->MessageBox("No ha seleccionado ningun grupo\n seleccione uno","Seleccione grupo");
    else{
        extern deque<Grupo> grupos; //declarada en "General.cpp"
        for (int i=0;i<FILAS;i++)
            for (int j=0;j<NUMERO;j++){
                 if (grupos.operator [](numgrupo).GetBEstado(numfecha,i,j)){
                      Barray[i][j]->Color=clRed;
                      Barray[i][j]->Enabled=false;
                 }
                 else{
                      Butacas b; //variable para ayudar en la inicializacion de los botones
                      switch (b.GetCategoria(i,j)){  //funcion de la clase butacas
                          case 0:Barray[i][j]->Color=clOlive;
                                 break;
                          case 1:Barray[i][j]->Color=clTeal;
                                 break;
                          case 2:Barray[i][j]->Color=clFuchsia;
                                 break;
                      }
                      Barray[i][j]->Enabled=true;
                 } //del else
            }//del 2º for
        FComprarEntr->Ecoste->Text=AnsiString(0);
    }//del else
}

/****************************************************************************
* SELBUT: Funcion que recibe dos int's, un TButton, y devuelve un double.
* El primer int recibido es el numero de grupo que se está cogiendo del deque
* grupos. El segundo es el valor del precio de la casilla (0 es barato, 1 medio
* y 2 es caro). Y el boton es el que ha sido pulsado.
* El double que retorna es el precio que le corresponde a esa butaca (que nos lo
* indica el 'x' e 'y', que tendremos que mirar en el deque externo grupos. Lo
* retornado puede ser negativo si el boton estaba seleccionado y el usuario lo
* "deseleccion", en caso contrario sera positivo.
******************************************************************************/
double SelBut (int x,int y, TButton *b)
{
    if (x!=-1){
        extern deque<Grupo> grupos;  //declarado en general.h
        double ret=grupos.operator [](x).GetPrecio(y);
        if (b->Color!=clBlack){
            b->Color=clBlack;
            return ret;
        }
        else {
              switch (y){
                    case 0: b->Color=clOlive;
                            return -ret;
                    case 1: b->Color=clTeal;
                            return -ret;
                    case 2: b->Color=clFuchsia;
                            return -ret;
              }
        }
    }
    else{
         Application->MessageBox("Debes seleccionar Grupo y Fecha", "ERROR");
         return 0;
    }
    return 0;
}

//----------------------------------------------------------------------------
//Las funciones de "VerGrupos.cpp"

/*****************************************************************************
 * CLEARVER: Funcion que no recibe ni devuelve nada
 * Esta funcion hace los clear de los List del form de "VerGrupos.cpp"
 *****************************************************************************/
void ClearVer (void)
{
    FVerGrupos->ListFechas->Clear();
    FVerGrupos->ListPrecios->Clear();
    FVerGrupos->ListGrupos->Clear();
}

/****************************************************************************
 * SHOWVER: Funcion que se llama al hacer el show del form de "VerGrupos.cpp".
 * Esta funcion lo que hace es recorrer el deque donde estan los grupos e ir
 * añadiendolos al ListBox llamado ListGrupos.
 ***************************************************************************/
void ShowVer (void)
{
    extern deque<Grupo> grupos;
    deque<Grupo>::iterator it;
    if (!grupos.empty())
        for (it=grupos.begin();it!=grupos.end();it++)  //recorremos el deque.
            FVerGrupos->ListGrupos->Items->Add(it->GetNombre());   //y vamos añadiendo los nombres
    else Application->MessageBox("            Lo sentimos.\n No tenemos ningun concierto\n \t          previsto ","No hay grupos previstos");

}

/******************************************************************************
 * SELGRUPO: Funcion que recibe un entero, que es el numero del grupo seleccionado.
 * Si este int es -1 es que no se ha seleccionado grupo, en caso contrario se
 * añaden al listbox de Fechas las fechas correspondientes del grupo elejido.
 ******************************************************************************/
void SelGrupo (int numgrupo)
{
    if (numgrupo==-1)
        Application->MessageBox("No ha seleccionado ningun grupo\n seleccione uno","Seleccione grupo");
    else{
         FVerGrupos->ListFechas->Clear();
         FVerGrupos->ListPrecios->Clear();
         extern deque<Grupo> grupos;
         for (int i=0;i<MAX_CONCER;i++)
             FVerGrupos->ListFechas->Items->Add(grupos.operator [](numgrupo).GetFDia(i));
         for (int j=0;j<PRECIOS_DIF;j++)
             FVerGrupos->ListPrecios->Items->Add(grupos.operator [](numgrupo).GetPrecio(j));
    }
}
