#include <iostream>
#include "Cola/Cola.h"
using namespace std;

bool sonIguales (Cola <char> &cola1, Cola <char> &cola2){    
    while (!cola1.esVacia() && !cola2.esVacia()){
        if (cola1.peek()!=cola2.peek()){
            return false;
        }
        cola1.desencolar();
        cola2.desencolar();
    }
    return cola1.esVacia() && cola2.esVacia();
}

int main() {

    Cola <char> cola1, cola2;

    cola1.encolar('a');
    cola1.encolar('b');
    cola1.encolar('c');
    cola1.encolar('d');

    cola2.encolar('a');
    cola2.encolar('b');
    cola2.encolar('c');
    cola2.encolar('d');

    if (sonIguales(cola1,cola2)){
        cout<<"Las colas son iguales";
    } else {
        cout<<"Las colas son distintas";
    }

    return 0;
}
