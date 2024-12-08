#include <vector>
#include <iostream>
#include <limits>
#include "nearestneighbor.h"

// Função que aplica a heurística do vizinho mais próximo
std::vector<std::size_t> nearestNeighbor(const std::vector<std::vector<double>>& distanceMatrix) {
    std::size_t n = distanceMatrix.size();
    std::vector<bool> visited(n, false);  // Marca os nós visitados
    std::vector<std::size_t> tour;        // Alterado para armazenar std::size_t em vez de int
    std::size_t currentNode = 0;          // Começa no nó 0 (alterado para std::size_t)
    visited[currentNode] = true;          // Marca o nó inicial como visitado
    tour.push_back(currentNode);

    // Percorre todos os nós
    for (std::size_t i = 1; i < n; ++i) {
        std::size_t nearestNeighbor = std::numeric_limits<std::size_t>::max();  // Alterado para std::size_t
        double minDistance = std::numeric_limits<double>::max();  // Alterado para double

        // Encontra o vizinho mais próximo
        for (std::size_t j = 0; j < n; ++j) {
            if (!visited[j] && distanceMatrix[currentNode][j] < minDistance) {
                minDistance = distanceMatrix[currentNode][j];
                nearestNeighbor = j;
            }
        }

        // Visita o vizinho mais próximo
        visited[nearestNeighbor] = true;
        tour.push_back(nearestNeighbor);
        currentNode = nearestNeighbor;  // Atualiza o nó atual
    }

    return tour;  // Retorna a sequência de nós visitados
}

// Função para calcular a distância total do percurso
double calculateTotalDistanceNeighbor(const std::vector<std::size_t>& tour, const std::vector<std::vector<double>>& distanceMatrix) {
    double totalDistance = 0.0;

    for (std::size_t i = 0; i < tour.size() - 1; ++i) {
        std::size_t u = tour[i];
        std::size_t v = tour[i + 1];
        totalDistance += distanceMatrix[u][v];
    }

    // Adiciona a distância do último nó até o primeiro (ciclo fechado)
    totalDistance += distanceMatrix[tour.back()][tour[0]];

    return totalDistance;
}
