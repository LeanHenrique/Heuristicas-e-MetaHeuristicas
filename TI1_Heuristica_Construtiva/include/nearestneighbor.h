#ifndef NEARESTNEIGHBOR_H
#define NEARESTNEIGHBOR_H

#include <vector>

// Função que aplica a heurística do vizinho mais próximo
std::vector<size_t> nearestNeighbor(const std::vector<std::vector<int>>& distanceMatrix);

// Função para calcular a distância total do percurso
int calculateTotalDistanceNeighbor(const std::vector<size_t>& tour, const std::vector<std::vector<int>>& distanceMatrix);

#endif // NEARESTNEIGHBOR_H
