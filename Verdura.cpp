#include "Verdura.h"

Verdura::Verdura(std::string nombre, double precio, int cantidad, std::string fecha)
    : Producto(nombre, precio, cantidad), fecha(fecha) {}

std::string Verdura::getFecha() const {
    return fecha;
}

void Verdura::setFecha(std::string fecha) {
    this->fecha = fecha;
}
