#ifndef __ARBOL_H__

class Arbol{
private:
    //Implementacion
    int nElem;
public:
    Arbol();
    void inserta(string palabra);
    void elimina(string palabra);
    bool consulta(string palabra);
    void vacia();
    int nTotal(){return nElem;};
};

#endif // __ARBOL_H__
