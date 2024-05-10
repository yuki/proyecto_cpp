#ifndef FechaH
#define FechaH
#include <fstream.h>

class Fecha
{
    protected:
          char dia[6]; //5 para la fecha y el sexto para el "\0"
	  char hora[6];

    public:
        Fecha(void);
        void Salvar (ofstream &);
        void Leer (ifstream &);
        void SetDia (char*);
        void SetDiaC (const char*);
        char* GetDia (void);
        const char* GetDiaC (void) const;

        void SetHora (char*);
        void SetHoraC (const char*);
        char* GetHora (void);
        const char* GetHoraC (void) const;
};


#endif
 
