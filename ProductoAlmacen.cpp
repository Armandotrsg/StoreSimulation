#include  "ProductoAlmacen.h"
#include <string>

using namespace std;

ProductoAlmacen::ProductoAlmacen(string id, string nombre, double precio, int existencia){
    this->id=id;
    this->nombre=nombre;
    this->precio=precio;
    this->existencia = existencia;
    this->viejasExistencias = this->existencia;
}

ProductoAlmacen::ProductoAlmacen(){
    this->id="";
    this->nombre="";
    this->precio=0;
    this->existencia = 0;
    this->viejasExistencias = 0;
}

string ProductoAlmacen::getID(){
    return this-> id;
}

string ProductoAlmacen::getNombre(){
    return this->nombre;
}

double ProductoAlmacen::getPrecio(){
    return this->precio;
}
int ProductoAlmacen::getExistencias(){
    return this->existencia;
}

int ProductoAlmacen::getViejasExistencias(){ //Nos sirve para llamar a las existencias si aún no se ha hecho una compra
    return this->viejasExistencias;
}

void ProductoAlmacen::setExistencias(int nuevasExistencias){
    this->existencia = nuevasExistencias;
}

void ProductoAlmacen::resetExistencias(){
    this->existencia = this->viejasExistencias; //si se elimina un artículo del carrito, nos sirve para regresar las existencias al valor original
}

void ProductoAlmacen::setViejasExistencias(int nuevasExistencias){
    this->viejasExistencias = nuevasExistencias;
    this->existencia = nuevasExistencias;
}

