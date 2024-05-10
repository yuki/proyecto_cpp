//---------------------------------------------------------------------------

#include <clx.h>
#pragma hdrstop
USEFORM("source/AcercaDe.cpp", FAcercaDe);
USEFORM("source/AdminGrupo.cpp", FAgreGrupos);
USEFORM("source/Administrar.cpp", FAdmin);
USEFORM("source/Bienvenida.cpp", FBienveni);
USEFORM("source/CambiarPass.cpp", FCambiarPass);
USEFORM("source/ComprEntradas.cpp", FComprarEntr);
USEFORM("source/Eliminar.cpp", FEliminar);
USEFORM("source/Password.cpp", FPass);
USEFORM("source/Recaudacion.cpp", FRecaudacion);
USEFORM("source/VerGrupos.cpp", FVerGrupos);
//---------------------------------------------------------------------------
int main(void)
{
        try
        {
                 Application->Initialize();
                 Application->CreateForm(__classid(TFBienveni), &FBienveni);
                 Application->CreateForm(__classid(TFAcercaDe), &FAcercaDe);
                 Application->CreateForm(__classid(TFAgreGrupos), &FAgreGrupos);
                 Application->CreateForm(__classid(TFAdmin), &FAdmin);
                 Application->CreateForm(__classid(TFCambiarPass), &FCambiarPass);
                 Application->CreateForm(__classid(TFComprarEntr), &FComprarEntr);
                 Application->CreateForm(__classid(TFEliminar), &FEliminar);
                 Application->CreateForm(__classid(TFPass), &FPass);
                 Application->CreateForm(__classid(TFRecaudacion), &FRecaudacion);
                 Application->CreateForm(__classid(TFVerGrupos), &FVerGrupos);
                 Application->Run();
        }
        catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }
        catch(...)
        {
                 try
                 {
                         throw Exception("");
                 }
                 catch(Exception &exception)
                 {
                         Application->ShowException(&exception);
                 }
        }
        return 0;
}
//---------------------------------------------------------------------------
