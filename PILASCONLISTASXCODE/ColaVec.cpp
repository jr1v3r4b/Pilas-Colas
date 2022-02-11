//
//  ColaVec.cpp
//  PILASCONLISTASXCODE
//
//  Created by UDP Soporte on 2/02/22.
//
#include "ColaVec.hpp"
#include <iostream>
#include <stdio.h>


using namespace std;

ColaVec::ColaVec(int tam)
{
    limite = tam -1;
    tope = -1;
    vCola = new int[tam];
}


void ColaVec::encolar(int dato)
{
    tope++;
    vCola[tope] = dato;
}

int ColaVec::desencolar()
{
    int r = vCola[0], i = 1;
    
    while (i <= tope)
    {
        vCola[i -1] = vCola[i];
        i++;
    }
    
    return r;
}

bool ColaVec::colaVacia()
{
    bool r = false;
    if( tope == 0 )
    {
        r = true;
    }
    return r;
    
    return 0;
}

bool ColaVec::colaLlena()
{
    if (tope == limite)
        return true;
    else
        return false;
}


void ordenarCola(ColaVec* a)
{
    
}


/*
void invertirCola()
{
    
}

 

void mostraCola()
{
    
    
}
*/
