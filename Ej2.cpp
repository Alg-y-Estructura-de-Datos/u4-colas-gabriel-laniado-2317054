#include <iostream>
#include "Cola/Cola.h"
using namespace std;

void depurar (Cola <int> &cola, int n){
    int a;
    Cola <int> colaaux;

    while (!cola.esVacia()){
        a=cola.desencolar();
        if (a<=n){
            colaaux.encolar(a);
        }
    }

    while (!colaaux.esVacia()){
        cola.encolar(colaaux.desencolar());
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

int main() {

    Cola <int> cola1;
    int n;

    cola1.encolar(1);
    cola1.encolar(2);
    cola1.encolar(3);
    cola1.encolar(4);
    cola1.encolar(5);
    cola1.encolar(6);

    cout<<"Ingrese el numero tope: ";
    cin>>n;

    mostrarCola(cola1);

    depurar(cola1,n);

    mostrarCola(cola1);
}
