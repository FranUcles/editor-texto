#include <iostream>
#include "Tokens.h"

const string strTipos[] = {"MINUS", "MAYUS", "FRASE", "PROPIO"};
string strToken[4] = {"PALABRA", "SIMBOLO", "COMANDO", "FINCOM"};
char aux_minuscula(char c)
{
    char r;
    if(c == (char)0xC3)
    {
        if(c == (char)0x81) r = (char)0xA1;
        else if(c == (char)0x89) r = (char)0xA9;
        else if(c == (char)0x8D) r = (char)0xAD;
        else if(c == (char)0x93) r = (char)0xB3;
        else if(c == (char)0x9A) r = (char)0xBA;
        else if(c == (char)0x9C) r = (char)0xBC;
        else if(c == (char)0x91) r = (char)0xB1;
    }
    else r = c + ('a' - 'A');
    return r;

}
string minuscula(string & cadena, tipoPal tipo)
{
    string resultado = "";
    switch(tipo)
    {
    case MINUS:
        break;
    case FRASE:
        resultado = cadena;
        aux_minuscula(resultado[0]);
        break;
    case PROPIO:
    case MAYUS:
        for(unsigned i = 0; i < cadena.length(); i++)
            resultado = resultado + aux_minuscula(cadena[i]);
    }
    return resultado;
}
bool esmayuscula(char c, int acentuada)
{
    if(acentuada) return c == (char)0x81 || c == (char)0x89 || c == (char)0x8D || c == (char)0x93 || c == (char)0x9A || c == (char)0x9C || c == (char)0x91;
    else return c >= 'A' && c <= 'Z';
}
bool esminuscula(char c, int acentuada)
{
    if (acentuada) return c == (char)0xA1 || c == (char)0xA9 || c == (char)0xAD || c == (char)0xB3 || c == (char)0xBA || c == (char)0xBC || c == (char)0xB1;
    else return c >= 'a' && c <= 'z';
}
bool esletra(char c, int acentuada)
{
    if(c == (char) 0xC3)
    {
        c = cin.peek();
        return esmayuscula(c,ACENTUADA) || esminuscula(c,ACENTUADA);
    }
    else return esmayuscula(c) || esminuscula(c);
}
bool obtenerPalabra(string & salida)
{
    char c;
    string resultado = "";
    c = cin.get();
    while(!cin.eof() && esletra(c))
    {
        if(c == (char) 0xC3)
        {
            char ant = c;
            c = cin.get();
            resultado = resultado + ant + c;
        }
        else resultado = resultado + c;
        c = cin.get();
    }
    if(!cin.eof()) cin.putback(c);
    salida = resultado;
    return resultado != "";
}
bool obtenerComando(string & salida)
{
    char c;
    string resultado = "";
    c = cin.get();
    while(!cin.eof() && c != '>')
    {
        resultado = resultado + c;
        c = cin.get();
    }
    salida = resultado;
    return resultado != "";
}
bool obtenerSimbolo(string & salida)
{
    char c;
    string resultado = "";
    c = cin.get();
    while(!cin.eof() && !esletra(c) && c != '<')
    {
        resultado = resultado + c;
        c = cin.get();
    }
    if(!cin.eof()) cin.putback(c);
    salida = resultado;
    return resultado != "";
}
bool siguienteToken(int & token, string & cadena)
{
    char c = cin.get();
    if(!cin.eof())
    {
        bool correcto = false;
        bool letraAcentuada = esletra(c,ACENTUADA);
        cin.putback(c);
        if(esletra(c) || letraAcentuada)
        {
            correcto = obtenerPalabra(cadena);
            token = PALABRA;
        }
        else if(c == '<')
        {
            cin.ignore();
            correcto = obtenerComando(cadena);
            if(correcto) token = (cadena[0]=='/' ? FINCOMANDO : COMANDO);
        }
        else
        {
            correcto = obtenerSimbolo(cadena);
            token = SIMBOLO;
        }
        return correcto;
    }
    else return false;
}
tipoPal tipoCadena(string & cadena)
{
    int k = 0;
    bool mayus;
    bool minu;
    bool frase;
    if(cadena[k] != (char)0xC3)
    {
        mayus = esmayuscula(cadena[k]);
        minu = esminuscula(cadena[k]);
        frase = esmayuscula(cadena[k]);
    }
    else
    {
        k++;
        mayus = esmayuscula(cadena[k], ACENTUADA);
        minu = esminuscula(cadena[k], ACENTUADA);
        frase = esmayuscula(cadena[k], ACENTUADA);
    }
    for(unsigned i = k+1; i < cadena.length(); i++)
    {
        if(cadena[i] != (char)0xC3)
        {
            mayus = mayus && esmayuscula(cadena[i]);
            minu = minu && esminuscula(cadena[i]);
            frase = frase && esminuscula(cadena[i]);
        }
        else
        {
            i++;
            mayus = mayus && esmayuscula(cadena[i],ACENTUADA);
            minu = minu && esminuscula(cadena[i],ACENTUADA);
            frase = frase && esminuscula(cadena[i],ACENTUADA);
        }
    }
    if(mayus) return MAYUS;
    else if(minu) return MINUS;
    else if(frase) return FRASE;
    else return PROPIO;
}
void escribirToken(int n, int token, string cadena)
{
    cout << n << ". " << strToken[token] << ": [" << cadena << "]";
    if(token == PALABRA)
    {
        cout << " " << strTipos[tipoCadena(cadena)] << endl;
    }
    else cout << endl;
}

