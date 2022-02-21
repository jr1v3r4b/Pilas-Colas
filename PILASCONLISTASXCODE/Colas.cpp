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
    Ultimo = nullptr;
}


void Cola::encolar(int dato)
{
    tope++;
    insertarFinal(dato);
}

int Cola::desencolar()
{
    Nodo* p = Punta;
    //Nodo* q = p->getLiga();
    int dato = p->getDato();
    
    if(tope == 1)
    {
        dato = p->getDato();
        Punta = nullptr;
        Ultimo = nullptr;
        
    }
    else
    {
        /*while (q->getLiga() != nullptr)
        {
            p->setDato(q->getDato());
            q = q->getLiga();
            p = p->getLiga();
            
            if(q->getLiga() == nullptr)
                p->setLiga(nullptr);
        }*/
        Punta = Punta->getLiga();
    }
    
    tope--;
    return dato;
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
    cout<< " Cola -> ";
    while (colaVacia() == false)
    {
        aux = desencolar();
        cout<< aux << " - ";
        colaAux->encolar(aux);
    }
    llenarCola(colaAux);  // se llena Cola auxiliar.
}   

void Cola::insertarFinal(int dat)
{
    Nodo *p = Punta;
    Nodo *newNodo = new Nodo();
    newNodo->setDato(dat);
    
    if (Punta == nullptr)
    {
        Punta = newNodo;
        Ultimo = newNodo;
    }
    else
    {
        while (p->getLiga() != nullptr)
        {
            p = p->getLiga();
        }
        p->setLiga(newNodo);
        Ultimo = p;
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
    encolar(dato);
    ordenarCola(cola);
}



void Cola::sumarColayPila(Pila* pi, Cola* co)
{
    Punta = nullptr;
    bool sw = false;
    int auxCola, auxPila;
    Cola *colaAux = new Cola(limite);
    Pila *pilaAux = new Pila(limite);
     do{
         if (sw == false || (!pi->pilaVacia() && !co->colaVacia()))
         {
             auxCola = co->desencolar();
             auxPila = pi->desapilar();
             
             encolar(auxPila + auxCola);
             
             colaAux->encolar(auxCola);
             pilaAux->apilar(auxPila);
       
            sw = true;
        }
        else {
            if (!pi->pilaVacia()) {
                auxPila = pi->desapilar();
                encolar(auxPila);
                pilaAux->apilar(auxPila);

            }
            if (!co->colaVacia()) {
                auxCola = co->desencolar();
                encolar(auxCola);
                colaAux->encolar(auxCola);

            }
        }
     }while (!pi->pilaVacia() || !co->colaVacia());
    
    pi->llenarPila(pilaAux);
    co->llenarCola(colaAux);
}

