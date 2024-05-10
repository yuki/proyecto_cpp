#include "pass.h"


/*****************************************************************************
 * LEERPASS: Funcion que recibe un char* y devuelve un bool.
 * Recibe una cadena de caracteres, la cual compara con lo leido de "Password.dat"
 * si es lo mismo, devuelve un 1, si no, devuelve 0.
 * En el caso de no existir el fichero, se llamara a SalvarPass con el password
 * 'grecia' por defecto, con lo que se creara el archivo "Password.dat" con esa
 * clave. Con ello conseguimos que si el usuario borra sin querer el archivo
 * "Password.dat" no pase nada.
 ******************************************************************************/
bool LeerPass (char* pass)
{
    ifstream entrada ("Password.dat",ios_base::binary);
    char* nombre;
    if (entrada){
        int n;
        entrada.read((char*)&n,sizeof (n));
        nombre=new char[n];
        entrada.read(nombre,n);
        entrada.close();//cerramos el fichero
    }
    else{
        Application->MessageBox("No existe fichero 'Password.dat'\nEste fichero será creado con la contraseña 'grecia' por defecto","ERROR EN LECTURA DE FICHERO");
        SalvarPass ("grecia");
        return true;
    }
    return  !strcmp(nombre,pass);
}

/******************************************************************************
 * SALVARPASS: Funcion que recibe una cadena de caracteres.
 * Esta funcion recibe el nuevo password, el cual es guardado en el fichero
 * "Password.dat".
 *****************************************************************************/
void SalvarPass(char* x)
{
   ofstream salida ("Password.dat",ios_base::binary);
   if (salida){
        int n=strlen(x)+1;
        salida.write((char*)&n,sizeof (n));
        salida.write(x,n);
        salida.close();
   }
   else
      // Error(1);
   salida.close();  //cerramos el fichero
}       //fin de la funcion salvarpass

//----------------------------------------------------------------------------
//Funciones de "Recaudacion.cpp"

/****************************************************************************
 * SHOWVER: Funcion que se llama al hacer el show del form de "VerGrupos.cpp".
 * Esta funcion lo que hace es recorrer el deque donde estan los grupos e ir
 * añadiendolos al ListBox llamado ListGrupos.
 ***************************************************************************/
void VerRecau (TListBox *ListGrupos)
{
    extern deque<Grupo> grupos;  //en "General.cpp"
    deque<Grupo>::iterator it;
    if (!grupos.empty())
        for (it=grupos.begin();it!=grupos.end();it++)  //recorremos el deque.
            ListGrupos->Items->Add(AnsiString(it->GetNombre()));
    else Application->MessageBox("            Lo sentimos.\n No tenemos ningun concierto\n \t          previsto ","No hay grupos previstos");

}

/******************************************************************************
 * SELGRUPO: Funcion que recibe un entero, que es el numero del grupo seleccionado.
 * Si este int es -1 es que no se ha seleccionado grupo, en caso contrario se
 * añaden al listbox de Fechas las fechas correspondientes del grupo elejido,
 * y al listbox de recaudacion la recaudacion.
 ******************************************************************************/
void SelRecau (int numgrupo, TListBox *ListFechas, TListBox *ListRecau)
{
    if (numgrupo==-1)
        Application->MessageBox("No ha seleccionado ningun grupo\n seleccione uno","Seleccione grupo");
    else{
         ListFechas->Clear();
         ListRecau->Clear();
         extern deque<Grupo> grupos;
         for (int i=0;i<MAX_CONCER;i++)
             ListFechas->Items->Add(grupos.operator [](numgrupo).GetFDia(i));
         for (int j=0;j<PRECIOS_DIF;j++)
             ListRecau->Items->Add(grupos.operator [](numgrupo).GetRecau(j));
    }
}

//-----------------------------------------------------------------------
//funcion de "Eliminar.h"

/*****************************************************************************
 * ELIMINAR: Funcion que recibe un entero.
 * Esta funcion elimina del deque el elemento que indica el int, en el caso que
 * sea diferente a -1.
 ******************************************************************************/
void Eliminar (int numgrupo)
{
    TMessageButton Option;
    TMessageButtons msgButtons;
    if (numgrupo==-1)
        Application->MessageBox("No ha seleccionado ningun grupo\n seleccione uno","Seleccione grupo");
    else{
         extern deque<Grupo> grupos;  //en "General.cpp"
         deque<Grupo>::iterator it;
         msgButtons << smbYes << smbNo << smbCancel;
         Option = Application->MessageBox("Estas segur@ que quieres eliminar este grupo?", "Actualizacion", msgButtons, smsWarning, smbYes, smbNo);
         if(Option == smbYes){//iniciamos el eliminar el grupo.
              it=grupos.begin();
              for (int i=0;i<numgrupo;i++)
                  it++;
              grupos.erase(it);  
         FEliminar->Hide();
         FAdmin->Show();
         }
         else
            if(Option == smbCancel){
                FEliminar->Hide();
                FAdmin->Show();
            }
    }
}
