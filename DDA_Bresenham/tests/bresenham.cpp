#include <iostream>
#include <vector>

using namespace std;

const int ANCHO = 40;
const int ALTO = 20;

void dibujarBresenham(int x0, int y0, int x1, int y1, vector<vector<char>>& lienzo);

int main() {
    vector<vector<char>> lienzo(ALTO, vector<char>(ANCHO, '.'));

    // Dibujar una línea invertida (Bresenham)
    dibujarBresenham(2, 2, 35, 15, lienzo);

    for (int i = 0; i < ALTO; i++) {
        for (int j = 0; j < ANCHO; j++) cout << lienzo[i][j] << " ";
        cout << endl;
    }
    return 0;
}

void dibujarBresenham(int x0, int y0, int x1, int y1, vector<vector<char>>& lienzo) {
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    
    // Direcciones de avance (para soportar todas las direcciones)
    int sx = (x0 < x1) ? 1 : -1;
    int sy = (y0 < y1) ? 1 : -1;
    
    // Parámetro de decisión inicial
    int err = dx - dy;

    while (true) {
        if (x0 >= 0 && x0 < ANCHO && y0 >= 0 && y0 < ALTO) {
            lienzo[y0][x0] = '#';
        }

        if (x0 == x1 && y0 == y1) break;

        int e2 = 2 * err; // Factor de decisión

        if (e2 > -dy) {
            err -= dy;
            x0 += sx;
        }
        if (e2 < dx) {
            err += dx;
            y0 += sy;
        }
    }
}