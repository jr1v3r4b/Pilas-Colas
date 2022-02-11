//
//  Colas.cpp
//  PILASCONLISTASXCODE
//
//  Created by UDP Soporte on 2/02/22.
//

#include "Colas.hpp"
#include "Nodo.hpp"
#include "Pila.hpp"
#include "Colas.hpp"
#include <iostream>
#include <stdio.h>


using namespace std;

Cola::Cola(int n)
{
    limite = n;
    tope = 0;
    Punta = nullptr;
}


void Cola::encolar(int dato)
{
    tope++;
    insertarFinal(dato);
}

int Cola::desencolar()
{
    Nodo* p = Punta;
    Nodo* q = p->getLiga();
    int r = p->getDato();
    Punta = Punta->getLiga();
    while (q->getLiga() != nullptr)
    {
        p->setDato(q->getDato());
        q = q->getLiga();
        p = p->getLiga();
    }
    tope--;
    
    return r;
}

bool Cola::colaVacia()
{
    bool r = false;
    if( tope == 0 )
    {
        r = true;
    }
    return r;
}

bool Cola::colaLlena()
{
    if (tope == limite)
        return true;
    else
        return false;
}

void Cola::llenarCola(Cola* a)
{
    while (a->colaVacia() == false){ encolar(a->desencolar()); }
}


void Cola::invertirCola()
{
    Pila* aux1 = new Pila(limite);
    aux1->apilar(desencolar());
    encolar(aux1->desapilar());
}

void Cola::mostraCola()
{
    int aux = 0;
    Cola *colaAux = new Cola(limite);
    while (colaVacia() == false)
    {
        aux = desencolar();
        cout<< " Dato: "<< tope <<" : " << aux << endl;
        colaAux->encolar(aux);
    }
    llenarCola(colaAux);  // se llena pila auxiliar.
}

void Cola::insertarFinal(int dat)
{
    Nodo *p = Punta, *newNodo = new Nodo();
    newNodo->setDato(dat);
    
    if (Punta == nullptr)
    {
        Punta = newNodo;
    }
    else
    {
        while (p->getLiga() != nullptr)
        {
            p = p->getLiga();
        }
        p->setLiga(newNodo);
    }

}

void Cola::ordenarCola(Cola* colaPrincipal)
{
    Cola* aux1 = new Cola(limite);
    Cola* aux2 = new Cola(limite);
    int hand, sw = 0;
    
    colaPrincipal->encolar(buscarMenor(colaPrincipal, aux1));
    while (!aux1->colaVacia() || !aux2->colaVacia())
    {
        if(sw == 0)
        {
            hand = buscarMenor(aux1, aux2);
            sw = 1;
        }
        else
        {
            hand = buscarMenor(aux2, aux1);
            sw = 0;
        }
        colaPrincipal->encolar(hand);
    }
}
                          
int Cola::buscarMenor(Cola* cola1, Cola* cola2)
{
    int least;
    least = cola1->desencolar();
    
    while (!cola1->colaVacia())
    {
        if (cola1->Punta->getDato() < least)
        {
            cola2->encolar(least);
            least = cola1->desencolar();
        }
        else
        {
            cola2->encolar(cola1->desencolar());
        }
    }
    return least;
}

void Cola::encolarOrdenado(Cola* cola,int dato)
{
    ordenarCola(cola);
    encolar(dato);
}



