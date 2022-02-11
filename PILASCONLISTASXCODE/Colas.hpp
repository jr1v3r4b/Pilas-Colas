//
//  Colas.hpp
//  PILASCONLISTASXCODE
//
//  Created by UDP Soporte on 2/02/22.
//

#ifndef Colas_hpp
#define Colas_hpp
#pragma once
#include <stdio.h>
#include "Nodo.hpp"

class Cola
{
private:
    int limite;
    int tope;
    Nodo *Punta;
    
public:
    
    Cola(int);
    void encolar(int); //Set
    int desencolar(); //Get
    bool colaVacia();
    bool colaLlena();
    void llenarCola(Cola*); // pasar datos de cola llena a cola vacía
    void insertarInicio(int);
    void invertirCola();
    void mostraCola();
    void insertarFinal(int);
    void ordenarCola(Cola*);
    int buscarMenor(Cola* , Cola*);
    void encolarOrdenado(Cola* ,int);
};


#endif /* Colas_hpp */
