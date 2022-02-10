//
//  Pila.cpp
//  PILASCONLISTASXCODE
//
//  Created by UDP Soporte on 30/01/22.
//
#include "Nodo.hpp"
#include "Pila.hpp"
#include <iostream>
#include <stdio.h>


using namespace std;

Pila::Pila(int n)
{
    limite = n;
    tope = 0;
    Punta =nullptr;
}

void Pila::apilar(int dato)
{
    tope++;
    insertarInicio(dato);
}

int Pila::desapilar()
{
    Nodo* p = Punta;
    int r = p->getDato();
    Punta = Punta->getLiga();
    tope--;
    delete(p);

    return r;
}

bool Pila::pilaVacia()
{
    bool r = false;
    if( tope == 0 )
    {
        r = true;
    }
    return r;
}

bool Pila::pilaLlena() // validacion llena(true = llena)
{
    if (tope == limite)
        return true;
    else
        return false;
}

void Pila::llenarPila(Pila *a)
{
    while (a->pilaVacia() == false){ apilar(a->desapilar()); }
}

void Pila::insertarInicio(int d)
{
    Nodo* x = new Nodo();
    x->setDato(d);

    if(Punta == nullptr)
        Punta = x;
    else
    {
        x->setLiga(Punta);
        Punta = x;
    }

}

void Pila::invertirPila()
{
    Pila* aux1 = new Pila(limite);
    Pila* aux2 = new Pila(limite);
    int r = 0;
    while (!pilaVacia())
    {
        r = desapilar();
        aux1->apilar(r);
    }
    aux2->llenarPila(aux1);
    llenarPila(aux2);
}

void Pila::mostraPila()
{
    int aux = 0;
    Pila *pilaAux = new Pila(limite);
    while (pilaVacia() == false)
    {
        aux = desapilar();
        cout<< " Dato: "<< tope <<" : " << aux << endl;
        pilaAux->apilar(aux);
    }
    llenarPila(pilaAux);  // se llena pila auxiliar.
}


