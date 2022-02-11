//
//  ColaVec.hpp
//  PILASCONLISTASXCODE
//
//  Created by UDP Soporte on 2/02/22.
//

#ifndef ColaVec_hpp
#define ColaVec_hpp
#pragma once
#include <iostream>
#include <stdio.h>

class ColaVec
{
private:
    int limite;
    int tope;
    int *vCola;
    
public:
    
    ColaVec(int);
    void encolar(int); //Set
    int desencolar(); //Get
    bool colaVacia();
    bool colaLlena();
//  void llenarola(ColaVec*); // pasar datos de pila llena a pila vacía
//  void insertarInicio(int);
//  void invertirCola();
//  void mostraCola();
    void ordenarCola(ColaVec);
    
};


#endif /* ColaVec_hpp */
