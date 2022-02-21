//
//  Pila.cpp
//  PILASCONLISTASXCODE
//
//  Created by UDP Soporte on 30/01/22.
//
#include "Nodo.hpp"
#include "Pila.hpp"
#include "Colas.hpp"
#include <iostream>
#include <stdio.h>


using namespace std;

Pila::Pila(int n)
{
    limite = n;
    tope = 0;
    Punta = nullptr;
    Ultimo = nullptr;
}
Nodo *Pila::getPunta()
{
    return Punta;
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

bool Pila::pilaVacia() // devuelve true cuando está vacía
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


void Pila::sumarPilas(Pila *a, Pila *b)
{
    Pila* suma = new Pila(limite);
    
    while (pilaVacia() == false)
    {
        suma->apilar(a->desapilar() + b->desapilar());
        
    }
    
    cout << "\n la suma de las pilas dió: " << endl;
    suma->mostraPila();
}


void Pila::ordenarPila(Pila* pilaPrincipal)
{
    Pila* aux1 = new Pila(limite);
    Pila* aux2 = new Pila(limite);
    int hand, sw = 0;
    
    pilaPrincipal->apilar(buscarMenor(pilaPrincipal, aux1));
    while (!aux1->pilaVacia() || !aux2->pilaVacia())
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
        pilaPrincipal->apilar(hand);
    }
}
                          
int Pila::buscarMenor(Pila* pila1, Pila* pila2)     
{
    int least;
    least = pila1->desapilar();
    
    while (!pila1->pilaVacia())
    {
        if (pila1->Punta->getDato() < least)
        {
            pila2->apilar(least);
            least = pila1->desapilar();
        }
        else
        {
            pila2->apilar(pila1->desapilar());
        }
    }
    return least;
}

void Pila::apilarOrdenado(Pila* pila,int dato)
{
    ordenarPila(pila);
    apilar(dato);
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
/*

void Cola::paresEimpares()
{
    Cola* aux1 = new Cola(limite);
    Cola* aux2 = new Cola(limite);
    
    int r->desapilar();

    aux1->encolar();
    
    while (desapilar()) {
        <#statements#>
    }
    
    
}
*/
