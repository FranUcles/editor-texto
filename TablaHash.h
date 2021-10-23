#ifndef __TABLA_HASH_H__

#include <iostream>
#include <list>
using namespace std;
const int TMAX = 4000;

class TablaHash{
private:
    list<string> tabla[TMAX];
    int nElem;
public:
    TablaHash();
    void inserta(string palabra);
    void elimina(string palabra);
    bool consulta(string palabra);
    void vacia();
    int nTotal() {return nElem;};
};


#endif // __TABLA_HASH_H__
