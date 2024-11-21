#ifndef APROX_H
#define APROX_H

#include <vector>
#include <utility> // Para std::pair

// Função para calcular a MST usando Prim e retornar as arestas da MST e a sequência em pré-ordem
std::pair<std::vector<std::pair<int, int>>, std::vector<int>> primMSTWithPreorder(const std::vector<std::vector<double>>& graph) ;

// Função para calcular a distância total usando a sequência em pré-ordem e a matriz de distâncias
double calculateTotalDistanceAprox(const std::vector<int>& preorder, const std::vector<std::vector<double>>& distanceMatrix);

// Função auxiliar para realizar DFS na árvore geradora mínima
void dfs(const std::vector<std::vector<int>>& tree, int current, std::vector<bool>& visited, std::vector<int>& preorder);

#endif // APROX_H
