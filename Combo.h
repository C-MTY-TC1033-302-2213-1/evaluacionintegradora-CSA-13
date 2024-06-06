#ifndef COMBO_H
#define COMBO_H

#include "Producto.h"
#include <string>

class Combo : public Producto {
public:
    Combo(std::string nombre, double precio, int cantidad, int descuento);
    int getDescuento() const;
    void setDescuento(int descuento);
private:
    int descuento;
};

#endif // COMBO_H