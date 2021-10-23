#ifndef __CONJUNTO_PALABRAS__H__

#include <iostream>
#include "TablaHash.h"
#include "Arbol.h"
using namespace std;

class ConjuntoPalabras
{
private:
    TablaHash th;
    Arbol ab;
public:
    ConjuntoPalabras();
    void inserta(string palabra){th.inserta(palabra); ab.inserta(palabra);};
    void elimina(string palabra){th.elimina(palabra); ab.elimina(palabra);};
    bool consulta(string palabra);
    void vacia();
    int nTotal(){return th.nTotal();};
};
#endif // __CONJUNTOPALABRAS_H__
