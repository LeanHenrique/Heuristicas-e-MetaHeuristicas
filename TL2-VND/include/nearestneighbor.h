#ifndef NEARESTNEIGHBOR_H
#define NEARESTNEIGHBOR_H

#include <vector>

// Função que aplica a heurística do vizinho mais próximo
std::vector<size_t> nearestNeighbor(const std::vector<std::vector<double>>& distanceMatrix);

// Função para calcular a distância total do percurso
double calculateTotalDistanceNeighbor(const std::vector<std::size_t>& tour, const std::vector<std::vector<double>>& distanceMatrix);

#endif // NEARESTNEIGHBOR_H
