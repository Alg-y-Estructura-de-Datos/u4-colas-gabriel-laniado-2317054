#include <iostream>
#include "Cola/Cola.h"
using namespace std;

int sumaTotal (Cola <int> &cola, int n){
    Cola <int> aux;
    int auxn, suma=0;

    while (!cola.esVacia()){
        if (cola.peek()==n){
            return suma;
        }
        auxn = cola.desencolar();
        suma+=auxn;
        aux.encolar(auxn);
    }

    while (!aux.esVacia()){
    auxn=aux.desencolar();
    cola.encolar(auxn);
    }

    return suma;
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

int main(){
    Cola<int> cola;
    int numero;

    // Lectura de la cola
    cout << "Ingrese numeros para la cola (ingrese -1 para terminar): " << endl;
    int input;
    while (cin >> input && input != -1) {
        cola.encolar(input);
    }

    // Lectura del número
    cout << "Ingrese el numero tope: ";
    cin >> numero;

    mostrarCola(cola);

    cout<<"La suma hasta ese numero es: "<<sumaTotal(cola,numero);

}