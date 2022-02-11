//
//  Nodo.hpp
//  PILASCONLISTASXCODE
//
//  Created by UDP Soporte on 30/01/22.
//

#ifndef Nodo_hpp
#define Nodo_hpp
#include <stdio.h>
class Nodo {
    int dato;
    Nodo *liga;
public:
    Nodo();
    int getDato();
    void setDato(int);
    Nodo* getLiga();
    void setLiga(Nodo*);

};

#endif /* Nodo_hpp */
