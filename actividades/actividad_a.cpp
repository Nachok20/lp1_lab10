#include <iostream>
#include <cmath>
using namespace std;

int vidaActual;
int vidaMaxima;

void calcularPorcentajeVida() {
    if (vidaActual <= 0) {
        cout << "El personaje esta sin vida" << endl;
        return;
    }
    if (vidaMaxima <= 0) {
        cout << "La vida maxima debe ser mayor a cero" << endl;
        return;
    }
    double porcentaje = 100.0 * vidaActual / vidaMaxima;
    if (porcentaje > 100) porcentaje = 100;
    cout << "Porcentaje de vida actual: " << round(porcentaje)
         << "%" << endl;
}

int main() {
    cout << "Ingrese la vida actual: ";
    cin >> vidaActual;
    cout << "Ingrese la vida maxima: ";
    cin >> vidaMaxima;
    calcularPorcentajeVida();
    return 0;
}
