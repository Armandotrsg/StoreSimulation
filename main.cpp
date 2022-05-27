/*
INTEGRANTES: Armando Terrazas Gómez -  A01640924
             Fernando Gómez Mártinez - A01641228

FECHA: 03/12/2021

RETO INTEGRADOR
*/
#include "ProductoAlmacen.h"
#include "ProductoAlmacen.cpp"
#include "ProductoCarrito.h"
#include "ProductoCarrito.cpp"
#include "Carrito.h"
#include "Carrito.cpp"
#include "Almacen.h"
#include "Almacen.cpp" 
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

int main(){
    //Declaramos un arreglo de objetos Producto Almacén, Producto Carrito y Carrito usando los constructores default
    ProductoAlmacen articulos[20];
    ProductoCarrito productoCarrito[10];
    Carrito carrito;

    //Iniciamos un objeto de la librería ifstream para leer el archivo de texto
    ifstream lector("productos.txt");
    int contador = 0;  //Esta variable es para usarse dentro del ciclo while
    string linea,
           texto[80],
           campo;
    //Mientras lector no esté al final del archivo, que se ejecute el ciclo 
    while (!lector.eof()){ 
        getline(lector,linea);
        stringstream ss(linea);
        while(getline(ss,campo,',')){ //Separamos cada línea hasta que encuentre una coma
            if (contador < 80){
                texto[contador] = campo; //Almacenamos en la posición contador del arreglo de string cada palabra antes de una coma
                contador++;
            }
            
        }
    }
    
    lector.close(); //Cerramos el archivo
    contador = 0;
    for (int i = 0; i < 80; i += 4){ //Cada 4 espacios dentro del arreglo texto, se encuentran los atributos del objeto Producto Almacén
        if (texto[i] != ""){
            string id = texto[i];
            string nombre = texto[i+1];
            double precio = stod(texto[i+2]); //"stod() convierte de string a double"
            int existencia = stod(texto[i+3]); //(Programiz, s. f.)
            articulos[contador] = ProductoAlmacen(id,nombre,precio,existencia); //Pasamos al constructor los atributos que se encontraron en el archivo de texto
            contador++;
        }
    }

    Almacen almacen(articulos); //Creamos un objeto de la clase Almacén, usando el constructor le pasamos el arreglo de artículos
    string menu = "0", //Variable para controlar el menú
           nombreCliente;
    cout << "\nBienvenido a la Tienda de Abarrotes 'Gómez'" << endl;
    cout << "\nIngrese su nombre: ";
    getline(cin,nombreCliente); 
    carrito.setCliente(nombreCliente); //Le pasamos al objeto carrito el nombre del usuario, usando el método setNombre
    cout << "\n";
    
    do{
        //Mostramos el menú
        cout << "\n\t\tMENÚ:\n" << endl;
        cout << "\t1. Ver Productos"<< endl;
        cout << "\t2. Comprar"<< endl;
        cout << "\t3. Ver Carrito"<< endl;
        cout << "\t4. Editar Carrito"<< endl;
        cout << "\t5. Pagar"<< endl;
        cout << "\t6. Salir\n"<< endl;
        cout << "Ingresa la opción del menú que necesites: ";
        cin >> menu;
        if (menu == "1"){ //Ver Productos
            almacen.imprimir(); //Imprimimos los productos
        } else if (menu == "2"){ //Comprar
            if (carrito.getSize() < 10){ //Verifica que el carrito tenga menos de 10 artículos antes de agregar otro.
                bool salirWhile = false; //Nos servirá para salir del ciclo do_while
                do{
                    
                    string opcionDeCompra;
                    int cantidad;
                    //Primero solicitamos el Id del producto, si no coincide con ningún id en existencia despliega un error y se repite el ciclo
                    cout << "\nIngresa el ID del producto que deseas comprar tal cual como esté escrito: ";
                    cin >> opcionDeCompra;
                    //Verificamos que exista el ID y además haya en existencias.
                    if (almacen.getProducto(opcionDeCompra).getID() != "" && almacen.getProducto(opcionDeCompra).getExistencias() != 0){
                        //De ser así, preguntamos cuántas va a querer
                        cout << "\nIngresa la cantidad que desees comprar: ";
                        cin >> cantidad;
                        //Verificamos que la cantidad ingresada no supere el número de existencias actuales
                        if (cantidad > almacen.getProducto(opcionDeCompra).getExistencias()){
                            cout << "\nNo hay más artículos en existencia." << endl;
                        } else if (cantidad <= 0){ //Verificamos que el producto no sea menor o igual a 0
                            cout << "\nNo puede ingresar un valor menor o igual a 0\n";
                        } else {
                            //Verificamos que el producto que seleccionó no esté ya en el carrito 
                            if (carrito.getProductoCarrito(opcionDeCompra).getProducto().getID() == opcionDeCompra){
                                //De ser así cambiamos los datos del producto en el carrito
                                carrito.setNewData(carrito.getProductoCarrito(opcionDeCompra).getCantidad()+cantidad,opcionDeCompra);
                            } else {
                                //De lo contrario, ciclamos en el ciclo for 10 veces en busca de un espacio 'vacío' en el objeto de la clase ProductoCarrito que inicializamos al inicio
                                for (int j = 0; j < 10; j++){ 
                                    //Cuando encuentre en un lugar con cantidad = 0, sustituirá el valor en la posición del arreglo productoCarrito por el producto seleccionado 
                                    if (productoCarrito[j].getCantidad() == 0){
                                        productoCarrito[j] = ProductoCarrito(almacen.getProducto(opcionDeCompra),cantidad); //Igualamos al constructor
                                        carrito = Carrito(productoCarrito,nombreCliente); //Le pasamos al objeto carrito, el constructor de la clase Carrito, pasándole el arreglo de objetos de la clase ProductoCarrito y el nommbre del cliente
                                        break; //El for debe parar, ya no tiene caso seguir buscando.
                                    }
                                }
                            }
                            //Actualizamos el valor de las existencias del producto
                            almacen.setNuevasExistencias(opcionDeCompra,almacen.getProducto(opcionDeCompra).getExistencias()-cantidad); 
                            cout << "\nProducto agregado al carrito" << endl;
                            salirWhile = true; //Se actualiza a true para salir del ciclo do_while
                        }
                    } else {
                        cout << "No hay productos que coincidan con este ID. Intenta de nuevo" << endl;
                    }
                    
                } while (!salirWhile);
            } else {
                cout << "Ya llenaste tu carrito de compras\n";
            }
        } else if (menu == "3"){ //Ver el carrito
            carrito.imprimir(); //Imprimimos los productos del carrito
        } else if (menu == "4"){ //Editar artículo
            if (carrito.getSize() != 0){ //Si el tamaño del carrito es 0, no permite editar el carrito
                bool salirWhile = false;
                do {
                    string productoAEditar;
                    int cantidad;
                    //Solicitamos el ID
                    cout << "\nIngresa el ID del producto que quieras modificar: ";
                    cin >> productoAEditar;
                    //Comparamos que el ID ingresado se encuentre en el carrito
                    if (productoAEditar == carrito.getProductoCarrito(productoAEditar).getProducto().getID()){
                        //De ser así, solicitamos la cantidad a editar
                        cout << "\nIngresa la nueva cantidad del producto del carrito (Escribe 0 si lo quieres eliminar): ";
                        cin >> cantidad;
                        //Verificamos que la cantidad ingresada no supere las existencias previas, si aún no se hace ninguna compra, técnicamente siguen en existencia
                        if (cantidad > carrito.getProductoCarrito(productoAEditar).getProducto().getViejasExistencias()){
                            cout << "\nNo hay más artículos en existencia." << endl;
                        } else if (cantidad < 0){ //Si un valor es menor a 0, no es posible continuar
                            cout << "\nNo puede ingresar un valor menor 0\n";
                        } else {
                            //De haber artículos en existencia, si el usuario ingresa un 0, el artículo se elimina del carrito y las existencias en el almacén se regresan
                            if (cantidad == 0){
                                carrito.eliminarArticulo(productoAEditar);
                                almacen.setNuevasExistencias(productoAEditar,almacen.getProducto(productoAEditar).getViejasExistencias());
                                
                            } else {
                            //De ingresar un número diferente a 0, actualizamos la cantidad almacenada en el carrito y la restamos de las existencias
                                carrito.setNewData(cantidad,productoAEditar);
                                almacen.setNuevasExistencias(productoAEditar,almacen.getProducto(productoAEditar).getViejasExistencias()-cantidad);
                            }
                            salirWhile = true;
                        }
                    } else {
                        cout << "\nNo hay productos que coincidan con este ID. Intenta de nuevo" << endl;
                    }
                    
                } while (!salirWhile);
            } else {
                cout << "\nNo hay productos en el carrito aún" << endl;
            }
        } else if (menu == "5"){ //Pagar
            if (carrito.getSize() == 0){ //Verificamos que haya artículos en el carrito
                cout << "\nNo ha agregado nada al carrito\n"; 
            } else {
                cout << "\nSu total fue de $" << carrito.getTotal() << endl;
                cout << "Gracias por su compra\n";
                
                for (int i = 0; i < 10; i ++){
                    almacen.setViejasExistencias(productoCarrito[i].getProducto().getID(),almacen.getProducto(productoCarrito[i].getProducto().getID()).getExistencias());
                }

                carrito.vaciarCarrito(); //vaciamos el carrito

                for (int i = 0; i <10;i++){ 
                    ProductoAlmacen randomProduct;
                    productoCarrito[i] = ProductoCarrito(randomProduct,0); //El objeto productoCarrito debe ser restablecido a valores default de objetos de ProductoAlmacen
                    
                }
            }
        } else if (menu == "6"){ //Salir
            cout << "\nGracias por tu visita " << carrito.getCliente() << endl; //Muestra un mensaje de despedida al cliente

        } else {
            cout << "\nIngresa una opción válida" << endl; //Mensaje de que ingresó un dato incorrecto
        }
    }while(menu != "6");

    return 0;
}