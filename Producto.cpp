#include "Producto.h"

Producto::Producto(std::string nombre, double precio, int cantidad)
    : nombre(nombre), precio(precio), cantidad(cantidad) {}

std::string Producto::getNombre() const {
    return nombre;
}

void Producto::setNombre(std::string nombre) {
    this->nombre = nombre;
}

double Producto::getPrecio() const {
    return precio;
}

void Producto::setPrecio(double precio) {
    this->precio = precio;
}

int Producto::getCantidad() const {
    return cantidad;
}

void Producto::setCantidad(int cantidad) {
    this->cantidad = cantidad;
}