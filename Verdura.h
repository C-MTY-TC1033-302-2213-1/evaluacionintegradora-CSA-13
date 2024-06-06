#ifndef Verdura_h
#define Verdura_h

#include <stdio.h>
#include <string>
#include "Producto.h"
using namespace std;

class Verdura : public Producto {
private:
    string temporada;

public:
    Verdura();
    Verdura(string _nombre, int _precio, int _peso, string _temporada);

    string str() override;
    int calcularTotalPagar() override;
};

#endif