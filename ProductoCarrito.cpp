#include "ProductoAlmacen.h"
#include "ProductoCarrito.h"


ProductoCarrito::ProductoCarrito(){ //Constructor que inicializa valores default
    this->cantidad = 0;
    ProductoAlmacen randomProduct;
    this->productosCarrito = randomProduct;
}

ProductoCarrito::ProductoCarrito(ProductoAlmacen productosCarrito,int cantidad){
    this->cantidad = cantidad;
    this->productosCarrito = productosCarrito;
}
int ProductoCarrito::getCantidad(){
    return this->cantidad;
}

double ProductoCarrito::getSubtotal(){
    return this->productosCarrito.getPrecio()*this->cantidad;
}

ProductoAlmacen ProductoCarrito::getProducto(){ //Regresa el objeto ProductoAlmacén almacenado en el atributo para poder acceder a los métodos de la clase ProductoAlmacen
    return productosCarrito;
}

void ProductoCarrito::setCantidad(int cantidad){ //Actualizamos la cantidad
    this->cantidad = cantidad;
    //También debemos actualizar la cantidad de existencias llamando al método de la clase ProductoAlmacen y pasándole como argumento las existencias (antes de una compra) y las cambia
    this->productosCarrito.setExistencias(productosCarrito.getViejasExistencias()-cantidad);
}


