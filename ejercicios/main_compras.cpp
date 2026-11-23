#include "compras.h"

int main() {
    srand(static_cast<unsigned>(time(nullptr)));
    string nombre;
    cout << "Nombre del cliente: ";
    getline(cin, nombre);
    double total = registrarProductos();
    cout << fixed << setprecision(2)
         << "Total sin descuento: S/ " << total << endl;
    descuentoPuntero(nombre, &total);
    cout << "Precio final a pagar: S/ " << total << endl;
    return 0;
}
