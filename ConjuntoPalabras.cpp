#include <iostream>
#include <list>
#include "ConjuntoPalabras.h"
#include "Tokens.h"
using namespace std;

ConjuntoPalabras::ConjuntoPalabras()
    {
        nPalabras = 0;
    }
void ConjuntoPalabras::inserta(string palabra)
    {
        list<string>::iterator itPalabras = palabras.begin();
        while(itPalabras != palabras.end() && *itPalabras < palabra) itPalabras++;
        if(itPalabras == palabras.end() || *itPalabras != palabra)
        {
            palabras.insert(itPalabras,palabra);
            nPalabras++;
        }
    }
    void ConjuntoPalabras::elimina(string palabra)
    {
        list<string>::iterator itPalabras = palabras.begin();
        while(itPalabras != palabras.end() && *itPalabras < palabra) itPalabras++;
        if(itPalabras != palabras.end() && *itPalabras == palabra)
        {
            palabras.erase(itPalabras);
            nPalabras--;
        }
    }
    bool ConjuntoPalabras::consulta(string palabra)
    {
        tipoPal tPalabra = tipoCadena(palabra);
        string minu;
        if(tPalabra == MAYUS || tPalabra == FRASE) minu = minuscula(palabra, tPalabra);
        list<string>::iterator itPalabras = palabras.begin();
        while(itPalabras != palabras.end() && (*itPalabras != palabra || *itPalabras != minu)) itPalabras++;
        if(itPalabras != palabras.end()) return false;
        else return true;
    }
    void ConjuntoPalabras::vacia()
    {
        palabras.clear();
        nPalabras = 0;
    }
    int ConjuntoPalabras::nTotal()
    {
        return nPalabras;
    }
