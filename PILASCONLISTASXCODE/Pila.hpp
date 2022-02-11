//
//  Pila.hpp
//  PILASCONLISTASXCODE
//
//  Created by UDP Soporte on 30/01/22.
//

#ifndef Pila_hpp
#define Pila_hpp
#pragma once
#include <stdio.h>
#include "Nodo.hpp"
class Pila
{
private:
    /* data */
    int limite;
    int tope;
    Nodo *Punta;
    
public:

    Pila(int);
    void apilar(int); //Set
    int desapilar(); //Get
    bool pilaVacia();
    bool pilaLlena();
    void llenarPila(Pila*); // pasar datos de pila llena a pila vacía
    void insertarInicio(int);
    void invertirPila();
    void mostraPila();
    void ordenarPila(Pila*);
    int buscarMenor(Pila*, Pila*);
    void apilarOrdenado(Pila*, int);
    void sumarPilas(Pila*, Pila*);
    void paresEimpares();
};

#endif /* Pila_hpp */
