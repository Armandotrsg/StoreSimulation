#ifndef PRODUCTOCARRITO_H
#define PRODUCTOCARRITO_H
#include <string>
#include "ProductoAlmacen.h"

using namespace std;

class ProductoCarrito{
    private:
        ProductoAlmacen productosCarrito;
        int cantidad;
    public:
        ProductoCarrito(ProductoAlmacen productosCarrito,int cantidad);
        ProductoCarrito();
        int getCantidad();
        double getSubtotal();
        ProductoAlmacen getProducto();
        void setCantidad(int cantidad);
        
        
};
#endif
