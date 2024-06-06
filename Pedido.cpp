#include "Pedido.h"
#include <iostream>
using namespace std;

Pedido::Pedido() : cantidad(0) {
    for (int i = 0; i < MAX_PROD; ++i) {
        arrPtrProductos[i] = nullptr;
    }
}

Pedido::~Pedido() {
    for (int i = 0; i < MAX_PROD; ++i) {
        if (arrPtrProductos[i] != nullptr) {
            delete arrPtrProductos[i];
            arrPtrProductos[i] = nullptr;
        }
    }
}

void Pedido::leerArchivo(string nombre) {
    ifstream archivo(nombre);
    if (!archivo) {
        cout << "No se pudo abrir el archivo: " << nombre << endl;
        return;
    }

    string tipo, nombreProducto, temporada;
    int precio, peso, clave;

    while (archivo >> tipo) {
        if (tipo == "V") {
            archivo >> nombreProducto >> precio >> peso >> temporada;
            arrPtrProductos[cantidad++] = new Verdura(nombreProducto, precio, peso, temporada);
        } else if (tipo == "C") {
            archivo >> nombreProducto >> precio >> peso >> clave;
            arrPtrProductos[cantidad++] = new Combo(nombreProducto, precio, peso, clave);
        } else if (tipo == "P") {
            archivo >> nombreProducto >> precio >> peso;
            arrPtrProductos[cantidad++] = new Producto(nombreProducto, precio, peso);
        }
    }

    archivo.close();
}

void Pedido::ticketCliente() const {
    int totalGeneral = 0;

    for (int i = 0; i < cantidad; ++i) {
        if (arrPtrProductos[i] != nullptr) {
            cout << arrPtrProductos[i]->str() << endl;
            totalGeneral += arrPtrProductos[i]->calcularTotalPagar();
        }
    }

    cout << "Total a pagar: $" << totalGeneral << endl;
}