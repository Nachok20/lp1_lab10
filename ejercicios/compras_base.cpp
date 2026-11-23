#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <limits>
#include <cmath>
using namespace std;

double registrarProductos();

int main() {
    double total = registrarProductos();
    cout << fixed << setprecision(2)
         << "Total de la compra: S/ " << total << endl;
    return 0;
}

double registrarProductos() {
    int cantidad;
    cout << "Cantidad de productos: ";
    if (!(cin >> cantidad) || cantidad <= 0) return 0;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    double total = 0, menor = 0, mayor = 0;
    string productoMenor, productoMayor;
    for (int i = 0; i < cantidad; i++) {
        string entrada, nombre;
        double precio;
        cout << "Producto " << i + 1 << " (Nombre-Costo): ";
        if (!getline(cin, entrada)) return total;
        size_t separador = entrada.find('-');
        bool valido = separador != string::npos && separador > 0;
        if (valido) {
            nombre = entrada.substr(0, separador);
            istringstream dato(entrada.substr(separador + 1));
            valido = bool(dato >> precio);
            dato >> ws;
            valido = valido && dato.eof() && isfinite(precio)
                     && precio >= 0;
            valido = valido && nombre.find_first_not_of(" ")
                     != string::npos;
        }
        if (!valido) {
            cout << "Formato invalido. Ejemplo: Camisa-50\n";
            i--;
            continue;
        }
        total += precio;
        if (i == 0 || precio < menor) {
            menor = precio;
            productoMenor = nombre;
        }
        if (i == 0 || precio > mayor) {
            mayor = precio;
            productoMayor = nombre;
        }
    }
    cout << fixed << setprecision(2);
    cout << "Producto mas costoso: " << productoMayor
         << " - S/ " << mayor << endl;
    cout << "Producto mas barato: " << productoMenor
         << " - S/ " << menor << endl;
    return total;
}
