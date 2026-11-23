#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <limits>
#include <cmath>
using namespace std;
#include <cstdlib>
#include <ctime>

double descuentoValor(string nombre, double total) {
    if (total > 150) {
        int sorteo = rand() % 100 + 1;
        cout << "Probabilidad de ganar: 25%" << endl;
        if (sorteo <= 25) {
            cout << nombre << ", obtuviste 15% de descuento." << endl;
            total *= 0.85;
        } else {
            cout << nombre << ", no obtuviste descuento." << endl;
        }
    } else {
        cout << "La compra debe superar S/ 150 para concursar." << endl;
    }
    return total;
}

int main() {
    srand(static_cast<unsigned>(time(nullptr)));
    string nombre;
    double total;
    cout << "Nombre del cliente: ";
    getline(cin, nombre);
    cout << "Total de la compra: ";
    if (!(cin >> total) || !isfinite(total) || total < 0) return 1;
    total = descuentoValor(nombre, total);
    cout << fixed << setprecision(2)
         << "Precio final a pagar: S/ " << total << endl;
    return 0;
}
