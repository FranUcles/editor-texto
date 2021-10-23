#include <iostream>
#include <sstream>
#include "Tokens.h"
#include "InterpreteComandos.h"
using namespace std;

//{Funciones Diccionario
void Meter(ConjuntoPalabras dic,string palabra)
{
    dic.inserta(palabra);
}
void Borrar(ConjuntoPalabras dic,string palabra)
{
   dic.elimina(palabra);
}
void Comprobar(ConjuntoPalabras dic,string palabra)
{
    cout << palabra;
    if(!dic.consulta(palabra)) cout << "[error]";
}
//}
void InterpreteComandos::procesarDiccionario()
{
    dic.vacia();
    int token;
    string cadena;
    while(siguienteToken(token, cadena) && token != FINCOMANDO)
    {
        if(token == PALABRA) Meter(dic,cadena);
    }
    cout << "[" << dic.nTotal() << " palabras]";
}
void InterpreteComandos::procesarInsertar()
{
    int token;
    string cadena;
    while(siguienteToken(token, cadena) && token != FINCOMANDO)
        if(token == PALABRA) Meter(dic,cadena);

    cout << "[" << dic.nTotal() << " palabras]";
}
void InterpreteComandos::procesarEliminar()
{
    int token;
    string cadena;
    while(siguienteToken(token, cadena) && token != FINCOMANDO)
        if(token == PALABRA) Borrar(dic,cadena);

    cout << "[" << dic.nTotal() << " palabras]";
}
void InterpreteComandos::procesarComando(string cadena)
{
    istringstream cadin(cadena);
    string comando, parametro;
    cadin >> comando;
    if(comando == "texto") procesarTexto();
    else if(comando == "diccionario") procesarDiccionario();
    else if(comando == "insertar") procesarInsertar();
    else if(comando == "eliminar") procesarEliminar();
    else
    {
        cadin >> parametro;
        if(comando == "sugiere") procesarSugiere(parametro);
        else if(comando == "autocorregir") procesarAutocorregir(parametro);
        else if(comando == "completar") procesarCompletar(parametro);
        else if(comando == "comodines") procesarComodines(parametro);
        else if(comando == "anagramas") procesarAnagramas(parametro);
        else if(comando == "rimar") procesarRimar(parametro);
        else if(comando == "movil") procesarMovil(parametro);
        else if(comando == "resumen") procesarResumen(parametro);
    }
}
void InterpreteComandos::procesarTexto()
{
    int token;
    string cadena;
    while(siguienteToken(token, cadena) && token != FINCOMANDO)
    {
        if(token == COMANDO) procesarComando(cadena);
        else if (token == PALABRA) Comprobar(dic,cadena);
        else cout << cadena;
    }
}
void InterpreteComandos::procesarSugiere(string param)
{
    //cout << "[" << param << "]";
}
void InterpreteComandos::procesarAutocorregir(string param)
{
    //cout << "[" << param << "]";
}
void InterpreteComandos::procesarCompletar(string param)
{
    //cout << "[" << param << "]";
}
void InterpreteComandos::procesarComodines(string param)
{
    //cout << "[" << param << "]";
}
void InterpreteComandos::procesarAnagramas(string param)
{
    //cout << "[" << param << "]";
}
void InterpreteComandos::procesarRimar(string param)
{
    //cout << "[" << param << "]";
}
void InterpreteComandos::procesarMovil(string param)
{
    //cout << "[" << param << "]";
}
void InterpreteComandos::procesarResumen(string param)
{
    //cout << "[" << param << "]";
}
