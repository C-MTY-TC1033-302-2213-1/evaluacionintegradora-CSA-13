#include "Producto.h"

Producto::Producto() : nombre(""), precio(0), peso(0) {}

Producto::Producto(string nombre, int precio, int peso)
    : nombre(nombre), precio(precio), peso(peso) {}

void Producto::setNombre(string nombre) {
    this->nombre = nombre;
}

void Producto::setPrecio(int precio) {
    this->precio = precio;
}

void Producto::setPeso(int peso) {
    this->peso = peso;
}

string Producto::getNombre() {
    return nombre;
}

int Producto::getPrecio() {
    return precio;
}

int Producto::getPeso() {
    return peso;
}

string Producto::str() {
    return "Nombre: " + nombre + ", Precio: $" + to_string(precio) + ", Peso: " + to_string(peso) + "kg";
}

int Producto::calcularTotalPagar() {
    return precio * peso;
}