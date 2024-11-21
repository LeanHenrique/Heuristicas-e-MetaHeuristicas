#include "distances.h"

// Função para calcular a distância Euclidiana (distância contínua)
double calculateEUC_2D(const Node& node1, const Node& node2) {
    double dx = node1.x - node2.x;
    double dy = node1.y - node2.y;
    return std::sqrt(dx * dx + dy * dy);
}

// Função para calcular a distância ATT (distância ajustada)
double calculateATT(const Node& node1, const Node& node2) {
    double dx = std::abs(node1.x - node2.x);
    double dy = std::abs(node1.y - node2.y);
    double rij = std::sqrt(dx * dx + dy * dy);
    return static_cast<int>(std::round(rij));  // ATT arredonda a distância
}