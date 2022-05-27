#ifndef CARRITO_H
#define CARRITO_H

#include <string>
#include "ProductoCarrito.h"

using namespace std;

class Carrito{
    private:
        string cliente;
        ProductoCarrito productos[10];
        int size;
        double total;
    public:
        Carrito(ProductoCarrito productos[10],string cliente);
        Carrito();
        string getCliente();
        ProductoCarrito getProductoCarrito(string id);
        int getSize();
        double getTotal();
        void vaciarCarrito();
        void eliminarArticulo(string id);
        void imprimir();
        void setCliente(string cliente);
        void setNewData(int cantidad, string id);
        


};

#endif