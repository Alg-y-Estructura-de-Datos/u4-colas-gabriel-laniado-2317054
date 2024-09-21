#include <iostream>
#include "Pila/Pila.h"
#include "Cola/Cola.h"
using namespace std;

void ordenar(Cola <int>&cola, Pila<int> &pila){
    Cola <int>colaaux;
    int aux;
    if(cola.esVacia()){
        cout<<"La cola esta vacia, error";
        return;
    }

    while(!cola.esVacia()){
        aux=cola.desencolar();

        if (aux%2==0){
            colaaux.encolar(aux);
        } else{
            pila.push(aux);
        }
    }

    while (!colaaux.esVacia()){
        aux= colaaux.desencolar();
        cola.encolar(aux);
    }
}

void mostrarCola(Cola <int> &cola){
    Cola<int>aux;
    int valor;

    while (!cola.esVacia()){
        valor = cola.desencolar();
        cout<<valor<<" ->";
        aux.encolar(valor);
    }

    while (!aux.esVacia()){
        cola.encolar(aux.desencolar());
    }

    cout<<endl;
}

void mostrarPila(Pila<int>& pila) {
    Pila<int> pilaAux;

    // Desapilar elementos para mostrar sin perderlos
    while (!pila.esVacia()) {
        int valor = pila.pop();
        cout << valor << " ";
        pilaAux.push(valor);
    }
    cout << endl;

    // Restaurar la pila original
    while (!pilaAux.esVacia()) {
        pila.push(pilaAux.pop());
    }
}

int main(){

    Pila <int> pila;
    Cola <int> cola;

    cout << "Ingrese numeros para la cola (ingrese -1 para terminar): " << endl;
    int input;
    while (cin >> input && input != -1) {
        cola.encolar(input);
    }

    ordenar(cola,pila);
    cout<<"Cola con elementos pares: "<<endl;
    mostrarCola(cola);

    cout<<"Pila con elemmentos impares: "<<endl;

    mostrarPila(pila);

}