#ifndef __TOKENS_H__
#include <iostream>
using namespace std;

extern string strToken[4];
enum tipoPal {MINUS=0, MAYUS=1, FRASE=2, PROPIO=3};
enum tipoToken {PALABRA=0, SIMBOLO=1, COMANDO=2, FINCOMANDO=3};
bool obtenerPalabra(string & salida);
bool obtenerComando(string & salida);
bool obtenerSimbolo(string & salida);
bool siguienteToken(int & token, string & cadena);
void escribirToken(int n, int token, string cadena);

const int ACENTUADA = 1;
tipoPal tipoCadena(string & cadena);
string minuscula(string & cadena, tipoPal tipo);
bool esmayuscula(char c, int acentuada = not ACENTUADA);
bool esminuscula(char c, int acentuada = not ACENTUADA);
bool esletra(char c, int acentuada = not ACENTUADA);
#endif // __TOKENS_H__
