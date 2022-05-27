#include "ProductoAlmacen.h"
#include "Almacen.h"
#include <iostream>
#include <string>

using namespace std;

//El constructor recibe un arreglo de objetos ProductoAlmacen y los guarda en la posición i del atributo productos[].
Almacen::Almacen(ProductoAlmacen productos[]){
    this->size = 0;
    for (int i=0; i < 20; i++){
        if (productos[i].getNombre() != ""){ //Solamente agregará valores si el objeto de ProductoAlmacen no está en default
            this->productos[i] = productos[i];
            this->size++; //Teniendo este if, podemos contar cuántos productos con valores diferentes a los default tenemos
        }
    }
}
ProductoAlmacen Almacen::getProducto(string id){ //Este método nos es útil para regresar el atributo productos[] en la posición indicada
    ProductoAlmacen randomObject; //Inicializamos un objeto ProductoAlmacen default, por si no encuentra ningún id igual al parámetro, este regrese un objeto default
    for (int i = 0; i < 20; i++){
        if (id == this->productos[i].getID()){ //Buscamos si el id del parámetro coincide con algún id que tengamos almacenado en el atributo productos[]
            randomObject = productos[i];
            break;
        }
    }
    return randomObject; //Regresamos el objeto completo, para poder acceder a los métodos de la clase ProductoAlmacén
}



int Almacen::getSize(){ //Get size va a verificar siempre que se llame, que size siga siendo el valor real
    int tamaño = 0;
    for (int i=0; i < 20; i++){
        if (this->productos[i].getExistencias() != 0){ //Verificamos que todos los elementos dentro del atributo productos[] tengan existencias diferentes de 0
            tamaño++;
        }
    }
    this -> size = tamaño; //Actualizamos el valor de size
    return this->size;
}

void Almacen::setNuevasExistencias(string id, int nuevasExistencias){ //Sirve para actualizar las existencias del producto que coincida con el id del parámetro
    for (int i = 0; i < 20; i++){
        if (id == productos[i].getID()){
            this->productos[i].setExistencias(nuevasExistencias);
            break;
        }
    }
}

void Almacen::setViejasExistencias(string id, int nuevasExistencias){ //Sirve para actualizar las viejas existencias del producto que coincida con el id del parámetro
    for (int i = 0; i < 20; i++){
        if (id == productos[i].getID()){
            this->productos[i].setViejasExistencias(nuevasExistencias);
            break;
        }
    }
}

void Almacen::imprimir(){
    cout << "\n\t\t\t\t\tPRODUCTOS" << endl;
    cout << "---------------------------------------------------------------------------------------------------" << endl;
    cout << "Productos disponibles: " << getSize() << endl;
    cout << "---------------------------------------------------------------------------------------------------" << endl;
    cout << "\tID\t\tARTÍCULO\t\tPRECIO\t\tEXISTENCIAS" << endl;
    cout << "\n";
    for (int i = 0; i < 20; i++){ 
        if (this->productos[i].getExistencias() != 0){ //Imprime solo los productos cuyas existencias sean superiores a 0
            cout << "\t" << productos[i].getID() << "\t\t" << productos[i].getNombre() << "\t\t"<< "$" << productos[i].getPrecio() << "\t\t"<< productos[i].getExistencias() << endl;
        } 
    }
}



