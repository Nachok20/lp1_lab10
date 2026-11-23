#include "juego.h"

int main() {
    string nombre;
    int nivel;
    cout << "Ingrese el nombre del personaje: ";
    cin >> nombre;
    cout << "Ingrese el nivel del personaje: ";
    if (!(cin >> nivel) || nivel < 0 || nivel > 1000000) return 1;
    crearPersonaje(nombre, nivel);
    do {
        int danio = calcularDanio(nivel);
        vidaActual -= danio;
        if (vidaActual < 0) vidaActual = 0;
        cout << "\nSe recibio un dano de " << danio
             << " | Vida actual: " << vidaActual << endl;
        calcularPorcentajeVida();
    } while (vidaActual > 0);
    return 0;
}
