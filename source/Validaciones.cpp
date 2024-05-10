//Cabecera propia
#include "Validaciones.h"

/*****************************************************************************
 * CLAREAR: Funcion que no recibe ni devuelve nada.
 * Esta funcion se encarga de poner todos los componentes de posible escritura
 * del form "FAgreGrupos" de "AdminGrupo.cpp" a "clear".
 *****************************************************************************/
void Clarear (void)
{
    FAgreGrupos->NomGrupo->Clear();
    FAgreGrupos->NomGira->Clear();
    FAgreGrupos->MaskFecha1->Clear();
    FAgreGrupos->MaskFecha2->Clear();
    FAgreGrupos->MaskFecha3->Clear();
    FAgreGrupos->MaskHora1->Clear();
    FAgreGrupos->MaskHora2->Clear();
    FAgreGrupos->MaskHora3->Clear();
    FAgreGrupos->MaskPrec1->Clear();
    FAgreGrupos->MaskPrec2->Clear();
    FAgreGrupos->MaskPrec3->Clear();
}

/******************************************************************************
 * TODOBIEN: Funcion que no recibe ningun parametro y que devuelve un bool.
 * Esta funcion se encarga de llamar a las funciones mas abajo implementadas y
 * comprobar que lo escrito en los MaskEdit's y TEdit's de "AdminGrupo.h", en el
 * form "FAgreGrupos" esté bien validado, en caso afirmativo devuelve true, por
 * el contrario devolvera  false.
 * Los "break" se han introducido para que al haber un error no siga validando, y
 * salte, en el caso de no estar los "breaks", de haber 4 fallos, aparecerian los
 * cuatro.
 ******************************************************************************/
bool TodoBien (void)
{
    bool salir=false;
    bool bien[14]; //todo sera true si todo esta validado
    for (int i=0;i<14;i++){
       if (salir) break;
          switch (i){
                case 0: bien[0]=GrupoBien (FAgreGrupos->NomGrupo);
                        if (!bien[0]){
                            salir=true;
                            break;
                        }
                case 1: bien[1]=FHBien (FAgreGrupos->MaskFecha1,true);
                        if (!bien[1]){
                            salir=true;
                            break;
                        }
                case 2: bien[2]=FHBien (FAgreGrupos->MaskFecha2,true);
                        if (!bien[2]){
                            salir=true;
                            break;
                        }
                case 3: bien[3]=FHBien (FAgreGrupos->MaskFecha3,true);
                        if (!bien[3]){
                            salir=true;
                            break;
                        }
                case 4: bien[4]=MayorMenorF (FAgreGrupos->MaskFecha1,FAgreGrupos->MaskFecha2);
                        if (!bien[4]){
                            salir=true;
                            break;
                        }
                case 5: bien[4]=MayorMenorF (FAgreGrupos->MaskFecha2,FAgreGrupos->MaskFecha3);
                        if (!bien[4]){
                            salir=true;
                            break;
                        }
                case 6: bien[5]=FHBien (FAgreGrupos->MaskHora1,false);
                        if (!bien[5]){
                            salir=true;
                            break;
                        }
                case 7: bien[6]=FHBien (FAgreGrupos->MaskHora2,false);
                        if (!bien[6]){
                            salir=true;
                            break;
                        }
                case 8: bien[7]=FHBien (FAgreGrupos->MaskHora3,false);
                        if (!bien[7]){
                            salir=true;
                            break;
                        }
                case 9: bien[8]=PrecioBien (FAgreGrupos->MaskPrec1);
                        if (!bien[8]){
                            salir=true;
                            break;
                        }
                case 10: bien[9]=PrecioBien (FAgreGrupos->MaskPrec2);
                        if (!bien[9]){
                            salir=true;
                            break;
                        }
                case 11: bien[10]=PrecioBien (FAgreGrupos->MaskPrec3);
                        if (!bien[10]){
                            salir=true;
                            break;
                        }
                case 12: bien[11]=MayorMenorP (FAgreGrupos->MaskPrec1,FAgreGrupos->MaskPrec2,FAgreGrupos->MaskPrec3);
                        if (!bien[11]){
                            salir=true;
                            break;
                        }
                case 13: bien[12]=GrupoBien (FAgreGrupos->NomGira);
                        if (!bien[12]){
                            salir=true;
                            break;
                        }
          }//del switch
    }//del for
    salir=true;
    for (int i=0;i<13;i++)
        if (!bien[i])
            salir=false;
    return salir;
}

/*****************************************************************************
 * ANADIRGRUPO: Funcion que recibe un bool y no devuelve nada.
 * En el caso de que el bool recibido sea true, se cogeran todos los datos de
 * los maskedits y tedits, y se introduciran en una variable Grupo intermedia.
 * Despues se añadira por la cola de la variable deque externa.
 *****************************************************************************/
void AnadirGrupo (bool TodoBien)
{
    if (TodoBien){
        TMessageButton Option;
        TMessageButtons msgButtons;
        msgButtons << smbYes << smbNo << smbCancel;
        Option = Application->MessageBox("Estas segur@ que quieres guardar este grupo?", "Actualizacion", msgButtons, smsWarning, smbYes, smbNo);
        if(Option == smbYes){//iniciamos el guardar el grupo.
            Grupo medio;
            //para que sea mas rapido
            TMaskEdit* fechas[3]={FAgreGrupos->MaskFecha1,FAgreGrupos->MaskFecha2,FAgreGrupos->MaskFecha3};
            TMaskEdit* horas[3]={FAgreGrupos->MaskHora1,FAgreGrupos->MaskHora2,FAgreGrupos->MaskHora3}; //para que sea mas rapido
            TMaskEdit* precios[3]={FAgreGrupos->MaskPrec1,FAgreGrupos->MaskPrec2,FAgreGrupos->MaskPrec3};//pos lo mismo :-D

            medio.SetNombre(FAgreGrupos->NomGrupo->Text.Length(),AnsiString(FAgreGrupos->NomGrupo->Text).c_str());
            medio.SetGira(FAgreGrupos->NomGira->Text.Length(),AnsiString(FAgreGrupos->NomGira->Text).c_str());
            for (int i=0;i<3;i++){
                medio.SetFDia(i,fechas[i]->Text.c_str());
                medio.SetFHora(i,horas[i]->Text.c_str());
                double cuanto=precios[i]->Text.ToDouble();
                medio.SetPrecio(i,cuanto);
            }
            extern deque <Grupo> grupos; //variable externa declarada en "General.cpp"
            if (grupos.size()<MAX_GRUPOS)
                grupos.push_back(medio); //insertamos el nuevo grupo al final del deque
            else Application->MessageBox("Hay demasiados grupos actualmente\n Borre alguno antes de introducir uno nuevo", "ERROR");
            FAgreGrupos->Hide();
            FAdmin->Show();
        }
        else
            if(Option == smbCancel){
                FAgreGrupos->Hide();
                FAdmin->Show();
            }
   }
}


/*****************************************************************************
* GRUPOBIEN: Funcion que recibe como parametro un TEdit de la VCL y devuelve
* un bool.
* Esta funcion sirve para comprobar si se ha insertado un nombre para el grupo,
* en caso afirmativo se devuelve true, en caso contrario se lanza un error y se
* devuelve false.
* Esta funcion se utiliza tanto para el nombre como para la gira, mirando que no
* empiecen por espacio, ni sea de longitud 0.
*******************************************************************************/
bool GrupoBien (TEdit *Nombre)
{
    if (Nombre->Text.Length()==0){
        Application->MessageBox("Debes de introducir un nombre de grupo y nombre de gira","ERROR EN EL GRUPO");
        Nombre->SetFocus();
        return false;
    }
    else{
         int j=0;
         for (int h=1;h<Nombre->Text.Length()+1;h++){
             j=h;
             if (AnsiString(Nombre->Text).operator [](h)!=' ') break;
         }
         if (j>1){
              Application->MessageBox("El GRUPO y la GIRA NO pueden empezar por espacios","ERROR EN EL GRUPO o GIRA");
              Nombre->SetFocus();
              return false;
         }
         else return true;
    }
}


/*****************************************************************************
* FHBIEN: Funcion que recibe un bool y un tipo TMaskEdit como parametro de la
* VCL y devuelve un bool. si fecha==True->el MaskEdit es una fecha sino es hora
* Esta funcion comprueba si se ha insertado correctamente una fecha u hora
* (devolviendo true); en caso contrario lanza un error y devuelve false. Esta
* funcion busca que no haya espacios introducidos, y que los datos sean correctos
* (en caso de la fecha, que no haya meses mayores que 12...)
********************************************************************************/
bool FHBien (TMaskEdit *fechora, bool fecha)
{
    if (fechora->Text.Length()==0){
        if (fecha)
            Application->MessageBox("Debes de introducir una fecha en la FECHA","ERROR EN LAS FECHA");
        else
            Application->MessageBox("Debes de introducir una hora en la HORA","ERROR EN LAS HORA");
        fechora->SetFocus();
        return false;
    }
    else {
          bool espacios=false;  //inicializacion de la variable
          for (int i=1;i<6;i++)
              if (fechora->Text.operator [](i)==' '){
                  espacios=true; //existe espacios entre los numeros,por lo que...
                  break;         //...es un error, salimos del bucle y lanzamos el error
              }
          if (espacios){
              if (fecha) Application->MessageBox("Debes de introducir las fechas completas en FECHAS","ERROR EN LAS FECHAS");
              else Application->MessageBox("Debes de introducir las horas completas en HORAS","ERROR EN LAS HORAS");
              fechora->SetFocus();
              return false;
          }
          else { //entramos para comprobar si la fecha/hora esta bien metida
                char  *dia,*mes; //para simplificar le hemos dado los nombres de...
                int idia,imes;   //...dia y mes, pero podria haber sido: "hora" y "mins"
                dia=new char[2];
                dia[0]=fechora->Text.operator [](1);
                dia[1]=fechora->Text.operator [](2);
                mes=new char[2];
                mes[0]=fechora->Text.operator [](4);
                mes[1]=fechora->Text.operator [](5);
                idia=atoi(dia);
                imes=atoi(mes);
                delete dia;//como no nos hacen falta estas dos var's les quitamos...
                delete mes;//..la memoria asignada, antes que se nos olvide :Þ
                if (fecha){//entramos aqui porque le ha llamado una fecha
                    if (imes>12 | imes==0){
                            Application->MessageBox("No puede haber meses mayores que 12\n      ni iguales a 0","ERROR EN LAS FECHAS");
                            fechora->SetFocus();
                            return false;
                    }
                    if (idia>31 | idia==0){
                            Application->MessageBox("No puede haber dias mayores que 31\n       ni iguales a 0","ERROR EN LAS FECHAS");
                            fechora->SetFocus();
                            return false;
                    }
                    else{
                        switch (imes){
                               case 4:
                               case 6:
                               case 9:
                               case 11: if (idia>30){
                                           Application->MessageBox("El dia introducido no puede ser para el mes introducido", "ERROR EN FECHAS");
                                           fechora->SetFocus();
                                           return false;
                                        }
                                        else break;
                               case 2: if (idia>28){
                                           Application->MessageBox("El dia introducido no puede ser para el mes introducido", "ERROR EN FECHAS");
                                           fechora->SetFocus();
                                           return false;
                                       }
                                       else break;
                        }//del switch
                    }
                }//salimos de la validacion de la fecha

                else{   //entramos aqui porque le ha llamado una hora
                        if (idia>23){
                            Application->MessageBox("No puede haber horas mayores que 23","ERROR EN LAS HORAS");
                            fechora->SetFocus();
                            return false;
                        }
                        if (imes>59){
                            Application->MessageBox("No puede haber minutos mayores a 59","ERROR EN LAS HORAS");
                            fechora->SetFocus();
                            return false;
                        }
                } //salimos de la validacion de las horas
          }

    }//del else
    return true;   //si se llega aqui es que la fecha esta bien, devolvemos true POR FIN!
}//fin de FechaBien



/******************************************************************************
* PRECIOBIEN: Funcion que devuelve un bool y que recibe como parametro un tipo
* TMaskEdit de la VCL.
* Esta funcion mira a ver si el precio que se manda como parametro esta bien,
* mira si el usuario ha introducido algun espacio, o no ha introducido nada
* (funcion para los usuarios perretes :D).
******************************************************************************/
bool PrecioBien (TMaskEdit *precio)
{
    if (precio->Text.Length()==0){
        Application->MessageBox("Debes de introducir los 3 precios","ERROR EN LOS PRECIOS");
        precio->SetFocus();
        return false;
    }
    else {
          bool espacios=false; 
          for (int i=1;i<6;i++)
              if (precio->Text.operator [](i)==' '){
                  espacios=true;
                  break;
              }
          if (espacios){
              Application->MessageBox("Debes de introducir precios completos en los PRECIOS","ERROR EN LOS PRECIOS");
              precio->SetFocus();
              return false;
          }
          else {
                char *medio=new char[6];
                strcpy(medio,precio->Text.c_str());
                medio[2]=medio[3]; // convertimos de "12,34" a "12334"
                medio[3]=medio[4]; // aqui hacemos de "12334" a "12344"
                medio[4]='\0';     //y aqui a "1234\0"-->todo ello para que funcione bien
                int num=atoi(medio);
                delete medio; //que no se nos olvide
                if (!num){
                    Application->MessageBox("Debes de introducir precios mayores a 0","ERROR EN LOS PRECIOS");
                    precio->SetFocus();
                    return false;
                }
          }
    }
    return true;
}


/*****************************************************************************
* MAYORMENORF: Funcion que devuelve un bool y que recibe como parametros dos
* TMaskEdit de la VCL.
* Esta funcion sirve para comprobar que se introducen bien las fechas y tambien
* comprueba que se meten en el orden adecuado.
*****************************************************************************/
bool MayorMenorF (TMaskEdit *uno, TMaskEdit *dos)
{
    TMaskEdit *array[2]={uno,dos};
    char *mes[2];
    int imes[2];
    for (int i=0;i<2;i++){
        mes[i]=new char [2];
        mes [i][0]=array[i]->Text.operator [](4);
        mes [i][1]=array[i]->Text.operator [](5);
    }
    for (int i=0;i<2;i++){
        imes[i]=atoi(mes[i]);
        delete mes[i]; //ya no las necesitamos
    }
    if (imes[0]>imes[1]){
        Application->MessageBox("Fechas en ORDEN INCORRECTO\n fecha 1ª debe ser menor a la 2ª\n y fecha 2ª menor que la 3ª","ERROR EN LAS FECHAS");
        array[0]->SetFocus();
        return false;
    }
    else
        if (imes[0]==imes[1]){  //los meses son iguales, que pasa con los dias?
             char *dias[2];
             int idias[2];
             for (int i=0;i<2;i++){
                 dias[i]=new char[2];
                 dias[i][0]=array[i]->Text.operator [](1);
                 dias[i][1]=array[i]->Text.operator [](2);
             }
             for (int i=0;i<2;i++){
                 idias[i]=atoi(dias[i]);
                 delete dias[i]; //borramos memoria
             }
             if (idias[0]<idias[1])
                return true;  //el primer dia es menor que el segundo
             else{  //el segundo dia es mayor que el primero*/
                  Application->MessageBox("Fechas en ORDEN INCORRECTO\n fecha 1ª debe ser menor a la 2ª\n y fecha 2ª menor que la 3ª","ERROR EN LAS FECHAS");
                  array[0]->SetFocus();
                  return false;
             }
        }
        else return true;
} // fin de MayorMenorF


/*****************************************************************************
* MAYORMENORP: Funcion que devuelve un bool y que recibe como parametros tres
* TMaskEdit de la VCL.
* Esta funcion sirve para comprobar que se introducen bien los precios y mira
* tambien si se han metido en el orden adecuado.
*****************************************************************************/
bool MayorMenorP (TMaskEdit *uno, TMaskEdit *dos, TMaskEdit *tres)
{
    if (!(uno->Text<dos->Text)){
        Application->MessageBox("Precio BARATO debe ser menor al precio MEDIO","ERROR EN LOS PRECIOS");
        dos->SetFocus();
        return false;
    }
    else
        if (!(dos->Text<tres->Text)){
            Application->MessageBox("Precio MEDIO debe ser menor que precio CARO", "ERROR EN LOS PRECIOS");
            tres->SetFocus();
            return false;
        }
        else return true;
} // fin de MayorMenorP

/*****************************************************************************
* ERROR: Funcion que recibe un entero.
* Esta funcion saca por pantalla el erro correspondiente al entero introducido.
* Esta funcion tendria que tener todos los errores... pero creo que en cierta
* manera es mejor introducir cada error en su lugar correspondiente (mas que nada
* para que si alguien lee el codigo no tenga que estar mirando atras y alante
* los cpp...
*******************************************************************************/
void Error (int cual)
{
    switch (cual){
          case 0: Application->MessageBox("Error al leer de archivo","ERROR de archivos");
                 break;
          case 1:Application->MessageBox("Error al escribir en archivo","ERROR de archivos");
                 break;
          case 2:Application->MessageBox("Grupo guardado en archivo","De acuerdo");
    }
}