#include <iostream>
#include <vector>
#include <cmath> // Para round() y abs()

using namespace std;

const int ANCHO = 40;
const int ALTO = 20;

void dibujarDDA(int x0, int y0, int x1, int y1, vector<vector<char>>& lienzo);

int main() {
    // Inicializar lienzo con puntos
    vector<vector<char>> lienzo(ALTO, vector<char>(ANCHO, '.'));

    // Dibujar una línea diagonal (DDA)
    dibujarDDA(2, 2, 35, 15, lienzo);

    // Imprimir en consola
    for (int i = 0; i < ALTO; i++) {
        for (int j = 0; j < ANCHO; j++) cout << lienzo[i][j] << " ";
        cout << endl;
    }
    return 0;
}

void dibujarDDA(int x0, int y0, int x1, int y1, vector<vector<char>>& lienzo) {
    float dx = x1 - x0;
    float dy = y1 - y0;

    // Determinamos la longitud de la línea
    float pasos = (abs(dx) > abs(dy)) ? abs(dx) : abs(dy);

    // Incrementos fraccionarios
    float x_inc = dx / pasos;
    float y_inc = dy / pasos;

    float x = x0;
    float y = y0;

    for (int i = 0; i <= pasos; i++) {
        // Verificamos límites para no salirnos del arreglo
        if (round(x) >= 0 && round(x) < ANCHO && round(y) >= 0 && round(y) < ALTO) {
            lienzo[round(y)][round(x)] = '*';
        }
        x += x_inc;
        y += y_inc;
    }
}