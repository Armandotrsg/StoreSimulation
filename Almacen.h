#ifndef ALMACEN_H
#define ALMACEN_H

#include "ProductoAlmacen.h"
#include <string>

using namespace std;

class Almacen{
    private:
        ProductoAlmacen productos[20];
        int size;
    public:
        Almacen(ProductoAlmacen productos[]);
        int getSize();
        ProductoAlmacen getProducto(string id);
        void setNuevasExistencias(string id, int nuevasExistencias);
        void setViejasExistencias(string id, int nuevasExistencias);
        void imprimir();
        

};

#endif