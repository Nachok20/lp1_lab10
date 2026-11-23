#include <iostream>
#include <random>
using namespace std;

int vidaActual;
int vidaMaxima;

int calcularDanio(int nivel) {
    int danio = 3;
    danio *= nivel;
    static random_device rd;
    static mt19937 generador(rd());
    uniform_int_distribution<int> distribucion(-5, 5);
    danio += distribucion(generador);
    if (danio < 3) danio = 3;
    return danio;
}

int main() {
    int nivel;
    cout << "Ingrese el nivel del personaje: ";
    if (!(cin >> nivel) || nivel <= 0 || nivel > 1000000) return 1;
    vidaMaxima = nivel * 20;
    vidaActual = vidaMaxima;
    int danio = calcularDanio(nivel);
    vidaActual -= danio;
    double porcentaje = 100.0 * vidaActual / vidaMaxima;
    if (porcentaje < 0) porcentaje = 0;
    cout << "Dano realizado: " << danio << endl;
    cout << "Vida restante: " << vidaActual << endl;
    cout << "Porcentaje de vida que tendria el jugador: "
         << int(porcentaje + 0.5) << "%" << endl;
    return 0;
}
