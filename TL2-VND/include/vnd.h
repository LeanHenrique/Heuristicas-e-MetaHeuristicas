#ifndef VND_OPTIMIZATION_H
#define VND_OPTIMIZATION_H

#include <vector>
#include <utility>
#include <algorithm>
#include <cstddef> // Para size_t
#include "nearestneighbor.h"

using namespace std;

// Função para aplicar o operador SWAP e encontrar um ótimo local
pair<vector<size_t>, double> swapOptimization(const vector<size_t>& tour, const vector<vector<double>>& distanceMatrix);

// Função para aplicar o operador 2-opt e encontrar uma solução melhor
pair<vector<size_t>, double> twoOpt(const vector<size_t>& tour, const vector<vector<double>>& distanceMatrix);

// Função VND que alterna entre SWAP e 2-opt
vector<size_t> vnd(const vector<size_t>& tour, const vector<vector<double>>& distanceMatrix);

#endif // VND_OPTIMIZATION_H
