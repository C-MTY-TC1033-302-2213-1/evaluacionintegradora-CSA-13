#include "Pedido.h"
#include "Verdura.h"
#include "Combo.h"
#include "Producto.h"
#include <fstream>
#include <sstream>
#include <iostream>

Pedido::Pedido() : cantidad(0) {}

void Pedido::leerArchivo(std::string nombre) {
    std::fstream archivo;
    std::string row[5];
    std::string line, word;
    archivo.open(nombre, std::ios::in);
    cantidad = 0;
    
    // lee una línea del archivo y la almacena en line
    while (getline(archivo, line)) {
        std::stringstream s(line);
        int iR = 0;
        
        // extrae caracteres de s y los almacena en word hasta que encuentra el delimitador ','
        while (getline(s, word, ',')) {
            row[iR++] = word;
        }
        
        if (row[0] == "V") { // Verdura
            arrPtrProductos[cantidad] = new Verdura("", 0, 0, row[1]);
            arrPtrProductos[cantidad]->setNombre(row[2]);
            arrPtrProductos[cantidad]->setPrecio(stoi(row[3]));
            arrPtrProductos[cantidad]->setPeso(stoi(row[4]));
        } else if (row[0] == "C") { // Combo
            arrPtrProductos[cantidad] = new Combo(row[1], stoi(row[2]), stoi(row[3]), stoi(row[4]));
        } else if (row[0] == "P") { // Producto
            arrPtrProductos[cantidad] = new Producto(row[1], stoi(row[2]), stoi(row[3]));
        }
        
        // incrementar el contador de apuntadores de arrPtrProductos
        cantidad = cantidad + 1;
    }
    archivo.close();
}

void Pedido::ticketCliente() {
    for (int i = 0; i < cantidad; ++i) {
        std::cout << arrPtrProductos[i]->getNombre() << " - $" << arrPtrProductos[i]->getPrecio() << " - "
                  << arrPtrProductos[i]->getCantidad() << " - $" << arrPtrProductos[i]->getPrecio() * arrPtrProductos[i]->getCantidad() << std::endl;
    }
    std::cout << "Total a pagar: $" << getTotal() << std::endl;
}

double Pedido::getTotal() const {
    double total = 0;
    for (int i = 0; i < cantidad; ++i) {
        total += arrPtrProductos[i]->getPrecio() * arrPtrProductos[i]->getCantidad();
    }
    return total;
}