#include <iostream>
#include "InterpreteComandos.h"
#include "Tokens.h"
using namespace std;

int main()
{
    InterpreteComandos interprete1;
    int token;
    string cadena;
    while(siguienteToken(token,cadena))
    {
        if(token == COMANDO) interprete1.InterpreteComandos::procesarComando(cadena);
        else if(token != FINCOMANDO) cout << cadena;
    }
}

