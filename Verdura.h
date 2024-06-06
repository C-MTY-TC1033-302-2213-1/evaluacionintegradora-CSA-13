#ifndef VERDURA_H
#define VERDURA_H

#include "Producto.h"
#include <string>

class Verdura : public Producto {
public:
    Verdura(std::string nombre, double precio, int cantidad, std::string fecha);
    std::string getFecha() const;
    void setFecha(std::string fecha);
private:
    std::string fecha;
};

#endif // VERDURA_H
