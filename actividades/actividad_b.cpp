#include <iostream>
#include <string>
using namespace std;

int vidaActual;
int vidaMaxima;

string obtenerTipo(string nombre) {
    if (nombre == "Orco" || nombre == "Goblin" ||
        nombre == "Troll" || nombre == "Dragon" ||
        nombre == "Esqueleto") return "enemigo";
    return "jugador";
}

void crearPersonaje(string nombre, int& nivel) {
    nivel += 2;
    int vida = nivel * 20;
    vidaActual = vida;
    vidaMaxima = vida;
    cout << "El " << nombre << " (" << obtenerTipo(nombre)
         << ") tiene un nivel de " << nivel
         << " con una vida de " << vidaActual << " puntos" << endl;
}

int main() {
    string nombre;
    int nivel;
    cout << "Ingrese el nombre del personaje: ";
    cin >> nombre;
    cout << "Ingrese el nivel del personaje: ";
    if (!(cin >> nivel) || nivel < 0 || nivel > 1000000) return 1;
    crearPersonaje(nombre, nivel);
    cout << "Nivel del jugador despues de la funcion: "
         << nivel << endl;
    return 0;
}
