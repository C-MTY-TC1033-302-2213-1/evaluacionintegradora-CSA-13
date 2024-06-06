#ifndef PEDIDO_H
#define PEDIDO_H

#include "Producto.h"
#include <string>

class Pedido {
public:
    Pedido();
    void leerArchivo(std::string nombre);
    void ticketCliente();
    double getTotal() const;
private:
    Producto* arrPtrProductos[100];
    int cantidad;
};

#endif // PEDIDO_H