#include "Carrito.h"
#include "ProductoAlmacen.h"
#include "ProductoCarrito.h"
#include <iostream>
#include <string>

using namespace std;

Carrito::Carrito(ProductoCarrito productos[10],string cliente){
    this->size = 0;
    this->cliente = cliente;
    for (int i = 0; i < 10; i++){
        if (productos[i].getProducto().getNombre() != ""){ //Este constructor solo agregará al atributo productos[] aquellos objetos ProductoCarrito cuya cantidad sea superior a 0
            this->productos[i] = productos[i];
            this->size++;
            
        }
    }
    double total = getTotal();
}

void Carrito::setCliente(string cliente){
    this->cliente = cliente;
}

Carrito::Carrito(){ //Constructor default, llena el atributo de productos[] de ProductosCarrito default
    this->cliente = "";
    this->size = 0;
    this->total = 0;
    ProductoCarrito carritoVacio;
    for (int i = 0; i<10;i++){
        this->productos[i] = carritoVacio;
    }
}

string Carrito::getCliente(){
    return this->cliente;
}

ProductoCarrito Carrito::getProductoCarrito(string id){ //Este método regresa el objeto ProductoCarrito que coincida con el id que ingresaron
    ProductoCarrito randomCarrito;
    for (int i = 0; i< 10; i++){
        if (this->productos[i].getProducto().getID() == id){
            randomCarrito = productos[i];
        }
    }
    return randomCarrito; //Regresa todo el objeto ProductoCarrito para poder acceder a los métodos de ProductoCarrito
}

int Carrito::getSize(){ //Actualiza el atributo size cada que se llama, si la cantidad dentro de los ProductosCarrito es mayor a 0
    int tamaño = 0;
    for (int i=0; i < 10; i++){
        if (this->productos[i].getCantidad() != 0){
            tamaño++;
        }
    }
    this -> size = tamaño;
    return this->size;
}

double Carrito::getTotal(){
    double suma = 0;
    for (int i=0;i<10;i++){
        suma += productos[i].getSubtotal();
    }
    this->total = suma;
    return this->total;
}




void Carrito::vaciarCarrito(){ //Sustituye cada valor del atributo productos[] por un objeto ProductoCarrito default
    for (int i=0;i<10;i++){
        
        ProductoAlmacen randomProduct; //(this->productos[i].getProducto().getID(),this->productos[i].getProducto().getNombre(),this->productos[i].getProducto().getPrecio(),this->productos[i].getProducto().getExistencias());
        ProductoCarrito carritoVacio(randomProduct,0);
        this->productos[i] = carritoVacio;
      
        
    }
}
void Carrito::eliminarArticulo(string id){  
    for (int i=0;i<10;i++){
        if (this->productos[i].getProducto().getID() == id){ //Cuando encuentre el id que corresponda con el Id ingresado, contador se iguala a i
            int contador = i;
            while (contador < 10){ //Mientras contador sea menor a 10, haremos un recorrido de posiciones en el arreglo productos[]
                if (contador == 9){ //Si ya está en la posición 9, para nio causar un error en índices en el arreglo, productos[9] se iguala directamente a un ProductoCarrito default
                    ProductoCarrito randomCarrito;
                    productos[contador] = randomCarrito;
                } else{
                    productos[contador] = productos[contador+1]; //La posición i, será igual a la siguiente posición i+1
                }
                contador++;
            }
            break;
        }
    }
}

void Carrito::imprimir(){
    cout << "\n\t\t\t\tCarrito de " << this->cliente << endl;
    cout << "---------------------------------------------------------------------------------------------------" << endl;
    cout << "Productos agregados: " << getSize() << endl;
    cout << "---------------------------------------------------------------------------------------------------" << endl;
    cout << "\tID\t\tARTÍCULO\t\tCANTIDAD\t\tSUBTOTAL" << endl;
    cout << "\n";
    for (int i = 0;i<10;i++){
        if (this->productos[i].getCantidad() != 0){ //Imprime solo si la cantidad es mayor a 0
            cout << "\t" << this->productos[i].getProducto().getID() << "\t\t" << this->productos[i].getProducto().getNombre() << "\t\t" << this->productos[i].getCantidad() << "\t\t" << "$" << this->productos[i].getSubtotal() << endl;
        }
        
    }
    cout << "\nTOTAL: $" << getTotal();
}

void Carrito::setNewData(int cantidad,string id){ //Cambia el valor de la cantidad del producto que coincida con el id del parámetro
    for (int i = 0; i < 10; i++){
        if (this->productos[i].getProducto().getID() == id){
            productos[i].setCantidad(cantidad);
            break;
        }
    }
}

