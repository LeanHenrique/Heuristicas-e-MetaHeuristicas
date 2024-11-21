#include "distances.h"

// Função para calcular a distância Euclidiana (EUC_2D)
int calculateEUC_2D(const Node& a, const Node& b) {
    double xd = a.x - b.x;
    double yd = a.y - b.y;
    return static_cast<int>(std::round(std::sqrt(xd * xd + yd * yd)));
}

// Função para calcular a distância pseudo-Euclidiana (ATT)
int calculateATT(const Node& a, const Node& b) {
    double xd = a.x - b.x;
    double yd = a.y - b.y;
    double rij = std::sqrt((xd * xd + yd * yd) / 10.0);
    int tij = static_cast<int>(std::round(rij));
    return (tij < rij) ? tij + 1 : tij;
}