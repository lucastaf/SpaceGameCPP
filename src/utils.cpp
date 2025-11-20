#include "raylib.h"
#include <array>
#include <cmath>

// Retorna os 3 pontos de um triângulo equilátero
std::array<Vector2, 3> getEquilateralTriangle(float x, float y, float rotation, float size,  float scaleX) {
    std::array<Vector2, 3> points{};


    const float step = 2.0f * PI / 3.0f; // 120°

    // Ângulos do triângulo "apontando para a direita":
    // vértice direito: 0
    // vértices seguintes: 120° e 240°
    for (int i = 0; i < 3; ++i) {
        float ang = 0.0f + step * i;

        // coordenadas no espaço local (raio = size)
        float px = size * std::cos(ang);
        float py = size * std::sin(ang);

        // aplicar escala no eixo X local
        px *= scaleX;

        // rotacionar pelo ângulo pedido
        float rx = px * std::cos(rotation) - py * std::sin(rotation);
        float ry = px * std::sin(rotation) + py * std::cos(rotation);

        // transladar para (x, y)
        points[i] = { x + rx, y + ry };
    }

    return points;
}