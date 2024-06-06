#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <string>

class Producto {
public:
    Producto(std::string nombre, double precio, int cantidad);
    virtual ~Producto() {}
    std::string getNombre() const;
    void setNombre(std::string nombre);
    double getPrecio() const;
    void setPrecio(double precio);
    int getCantidad() const;
    void setCantidad(int cantidad);
private:
    std::string nombre;
    double precio;
    int cantidad;
};

#endif // PRODUCTO_H