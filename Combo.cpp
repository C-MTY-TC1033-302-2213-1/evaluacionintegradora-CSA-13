#include "Combo.h"

Combo::Combo() : Producto(), clave(0) {}

Combo::Combo(string nombre, int precio, int peso, int clave)
    : Producto(nombre, precio, peso), clave(clave) {}

int Combo::calcularTotalPagar() {
    int total = getPrecio() * getPeso();

    if (clave == 1) {
        total -= (total / 100) * 25;
    } else if (clave == 2) {
        total -= (total / 100) * 30;
    }

    return total;
}

string Combo::str() {
    return getNombre() + "-$" + to_string(getPrecio()) + "-" + to_string(getPeso()) + "-$" + to_string(calcularTotalPagar()) + "-" + to_string(clave);
}
