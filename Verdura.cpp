#include "Verdura.h"
#include <sstream>

Verdura::Verdura() : Producto() {
    temporada = "";
}

Verdura::Verdura(string _nombre, int _precio, int _peso, string _temporada) 
    : Producto(_nombre, _precio, _peso), temporada(_temporada) {}

string Verdura::str() {
    stringstream ss;
    ss << "Nombre: " << nombre << "\n"
       << "Precio: " << precio << "\n"
       << "Peso: " << peso << "\n"
       << "Temporada: " << temporada << "\n";
    return ss.str();
}

int Verdura::calcularTotalPagar() {
    return precio * peso;
}