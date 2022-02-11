//
//  main.cpp
//  PILASCONLISTASXCODE
//
//  Created by UDP Soporte on 30/01/22.
//

#include <iostream>
#include <stdio.h>
#include "Pila.hpp"
#include "Colas.hpp"
#include "Nodo.hpp"
#include "ColaVec.hpp"

using namespace std;

void Menu()
{
    cout << "\n \t Bienvenido al mundo de las pilas y las colas \n\n";
    cout << "1. Apilar. " << endl;
    cout << "2. Desapilar.  " << endl;
    cout << "3. Encolar." << endl;
    cout << "4. Desencolar. " << endl;
    cout << "5. Mostrar Pila. " << endl;
    cout << "6. Mostrar Cola.  " << endl;
    cout << "7. Invertir Pila. " << endl;
    cout << "8. Sumar Pila. " << endl;
    cout << "9. Ordenar Pila." << endl;
    cout << "10. Apilar Ordenado." << endl;
    cout << "11. Ordenar Cola." << endl;
    cout << "12. Encolar Ordenado." << endl;

    cout << "0. Salir"<< endl;

    cout << "\t Ingresar Opcion: \n " << endl;
}



int main()
{

    Pila* P1;
    Cola* C1;
    int opc=0, dato=0, n = 0;

    cout << " ingrese el tamaño de la pila o cola." << endl;
    cin >> n;
    
    P1 = new Pila(n);
    C1 = new Cola(n);

    do
    {
        Menu();
        cin >> opc;
   

        switch (opc)
        {
            case 1: //apilar
                if(!P1->pilaLlena())
                {
                    cout << " \n Ingrese un dato: ";
                    cin >> dato;
                    P1->apilar(dato);
                }
                else
                {
                    cout << "\n La Pila está llena, no se pueden apilar mas datos " << endl;
                    
                }
                cin.get();
                break;

            case 2: //desapilar
                if(!P1->pilaVacia())
                {
                    cout << " \n Se desapiló el ultimo dato: " << P1->desapilar() << endl;
                }
                else
                {
                    cout << "\n La Pila está vacia, no hay algo para mostrar. " << endl;
                }
                cin.get();
                break;

            case 3: //encolar
                if(!C1->colaLlena())
                {
                    cout << " \n Ingrese un dato: ";
                    cin >> dato;
                    C1->encolar(dato);
                }
                else
                {
                    cout << "\n La Cola está llena, no se pueden encolar mas datos. " << endl;
                    
                }
                cin.get();
                break;

            case 4: //desencolar
                if(!C1->colaVacia())
                {
                    cout << " \n Se desencoló el ultimo dato: " << C1->desencolar() << endl;
                }
                else
                {
                    cout << "\n La Cola está vacia, no hay algo para mostrar.  " << endl;
                }
                cin.get();
                break;

            case 5: // Mostrar pila
                if(!P1->pilaVacia())
                {
                    P1->mostraPila();
                }
                else
                {
                    cout << " \n No hay ningún dato en la Cola " << endl;
                }
                cin.get();
                break;

            case 6:
                if(!C1->colaVacia())
                {
                    C1->mostraCola();
                }
                else
                {
                    cout << " \n No hay ningún dato en la Cola " << endl;
                }
                cin.get();
                break;

            case 7:
                cin.get();
                break;
                
            case 8:
                cin.get();
                break;
                
            case 9:
                if(!P1->pilaVacia())
                {
                    P1->ordenarPila(P1);
                    cout << "\n se acaba de ordenar la pila" << endl;
                }
                else
                {
                    cout << " \n No hay ningún dato en la pila " << endl;
                }
                

                cin.get();
                break;
                
            case 10:
                
                if(!P1->pilaLlena())
                {
                    cout << " \n Ingrese un dato: ";
                    cin >> dato;
                    P1->apilarOrdenado(P1, dato);
                }
                else
                {
                    cout << "\n La Pila está llena, no se pueden apilar mas datos. " << endl;
                    
                }
            
                cin.get();
                break;
                
            case 11:
                
                if(!C1->colaVacia())
                {
                    C1->ordenarCola(C1);
                    cout << "\n se acaba de ordenar la Cola" << endl;
                }
                else
                {
                    cout << " \n No hay ningún dato en la Cola " << endl;
                }

                cin.get();
                break;
                
            case 12:
                
                if(!C1->colaLlena())
                {
                    cout << " \n Ingrese un dato: ";
                    cin >> dato;
                    C1->encolarOrdenado(C1, dato);
                }
                else
                {
                    cout << "\n La Cola está llena, no se pueden apilar mas datos. " << endl;
                    
                }
            
                cin.get();
                break;
                
            case 0:
                cout << " Hasta luego, nos vemos en otros programas... ";
                cin.get();
                break;


            default:
                cout<<" \n Opcion incorrecta... ";
                cin.get();
                break;
        }

        cout << endl << endl;
        cin.get();

    }while(opc > 0);

    return 0;
}
