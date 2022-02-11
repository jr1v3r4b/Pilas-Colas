//
//  Nodo.cpp
//  PILASCONLISTASXCODE
//
//  Created by UDP Soporte on 30/01/22.
//
#include "Nodo.hpp"
#include "Pila.hpp"
#include <iostream>


Nodo::Nodo()
{
    dato = 0;
    liga = nullptr;
}

int Nodo::getDato()
{
    return dato;
}
void Nodo::setDato(int d)
{
    dato = d;
}
Nodo *Nodo::getLiga()
{
    return liga;
}

void Nodo::setLiga(Nodo *liga) {

    Nodo::liga = liga;
}
