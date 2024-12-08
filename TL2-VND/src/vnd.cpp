#include "vnd.h"

using namespace std;

// Função para aplicar o operador SWAP e encontrar um ótimo local
pair<vector<size_t>, double> swapOptimization(const vector<size_t>& tour, const vector<vector<double>>& distanceMatrix) {
    size_t n = tour.size();
    vector<size_t> bestTour = tour;
    double bestCost = calculateTotalDistanceNeighbor(tour, distanceMatrix);

    for (size_t i = 0; i < n - 1; ++i) {
        for (size_t j = i + 1; j < n; ++j) {
            // Cria uma nova rota aplicando SWAP
            vector<size_t> newTour = tour;
            swap(newTour[i], newTour[j]);

            // Calcula o custo da nova rota
            double newCost = calculateTotalDistanceNeighbor(newTour, distanceMatrix);

            // Atualiza a melhor rota e custo, se necessário
            if (newCost < bestCost) {
                bestTour = newTour;
                bestCost = newCost;
            }
        }
    }

    return {bestTour, bestCost};
}

// Função para aplicar o operador 2-opt e encontrar uma solução melhor
pair<vector<size_t>, double> twoOpt(const vector<size_t>& tour, const vector<vector<double>>& distanceMatrix) {
    size_t n = tour.size();
    vector<size_t> bestTour = tour;
    double bestCost = calculateTotalDistanceNeighbor(tour, distanceMatrix);
    bool improved = true;

    while (improved) {
        improved = false;
        for (size_t i = 1; i < n - 1; ++i) {
            for (size_t j = i + 1; j < n; ++j) {
                // Reverte o segmento entre i e j
                vector<size_t> newTour = bestTour;
                reverse(newTour.begin() + i, newTour.begin() + j + 1);

                // Calcula o custo do novo tour
                double newCost = calculateTotalDistanceNeighbor(newTour, distanceMatrix);

                // Atualiza a melhor solução, se necessário
                if (newCost < bestCost) {
                    bestTour = newTour;
                    bestCost = newCost;
                    improved = true;
                }
            }
        }
    }

    return {bestTour, bestCost};
}

// Função VND que alterna entre SWAP e 2-opt
vector<size_t> vnd(const vector<size_t>& tour, const vector<vector<double>>& distanceMatrix) {
    vector<size_t> currentTour = tour;
    double currentCost = calculateTotalDistanceNeighbor(tour, distanceMatrix);

    bool improved = true;
    while (improved) {
        improved = false;

        // 1ª Vizinhança: SWAP
        auto [swapTour, swapCost] = swapOptimization(currentTour, distanceMatrix);
        if (swapCost < currentCost) {
            currentTour = swapTour;
            currentCost = swapCost;
            improved = true;
        }

        // 2ª Vizinhança: 2-opt
        auto [twoOptTour, twoOptCost] = twoOpt(currentTour, distanceMatrix);
        if (twoOptCost < currentCost) {
            currentTour = twoOptTour;
            currentCost = twoOptCost;
            improved = true;
        }
    }

    return currentTour;
}