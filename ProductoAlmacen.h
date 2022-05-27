#ifndef PRODUCTOALMACEN_H
#define PRODUCTOALMACEN_H
#include <string>

using namespace std;

class ProductoAlmacen{
    private:
        string id,
               nombre;
        double precio;
        int viejasExistencias,
            existencia;

    public:
        ProductoAlmacen(string id, string nombre, double precio, int existencia);
        ProductoAlmacen();
        string getID();
        string getNombre();
        double getPrecio();
        int getExistencias();
        int getViejasExistencias();
        void setViejasExistencias(int nuevasExistencias);
        void setExistencias(int nuevasExistencias);
        void resetExistencias();

};

#endif