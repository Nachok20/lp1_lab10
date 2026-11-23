#ifndef JUEGO_H
#define JUEGO_H
#include <iostream>
#include <string>
#include <cmath>
#include <random>
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

#endif
