#include "Combo.h"

Combo::Combo(std::string nombre, double precio, int cantidad, int descuento)
    : Producto(nombre, precio, cantidad), descuento(descuento) {}

int Combo::getDescuento() const {
    return descuento;
}

void Combo::setDescuento(int descuento) {
    this->descuento = descuento;
}
