#ifndef __INTERPRETE_COMANDOS_H__
#include <iostream>
#include "ConjuntoPalabras.h"

using namespace std;
class InterpreteComandos
{
private:
    ConjuntoPalabras dic;
public:
    void procesarSugiere(string param);
    void procesarAutocorregir(string param);
    void procesarCompletar(string param);
    void procesarComodines(string param);
    void procesarAnagramas(string param);
    void procesarRimar(string param);
    void procesarMovil(string param);
    void procesarResumen(string param);
    void procesarTexto();
    void procesarComando(string cadena);
    void procesarEliminar();
    void procesarInsertar();
    void procesarDiccionario();
};
#endif // __INTERPRETE_COMANDOS_H__
