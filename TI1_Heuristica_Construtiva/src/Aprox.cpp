#include <iostream>
#include "node.h"
#include "aprox.h"
#include <vector>
#include <limits> // Para std::numeric_limits



std::pair<std::vector<std::pair<int, int>>, std::vector<int>> primMSTWithPreorder(const std::vector<std::vector<int>>& graph) {
    std::size_t n = graph.size();
    std::vector<bool> inMST(n, false);               // Marca os vértices incluídos na MST
    std::vector<int> minWeight(n, std::numeric_limits<int>::max()); // Peso mínimo para cada nó
    std::vector<int> parent(n, -1);                  // Armazena o pai de cada nó na MST
    std::vector<std::pair<int, int>> mstEdges;       // Armazena as arestas da MST

    minWeight[0] = 0; // Começa pelo nó 0

    for (std::size_t i = 0; i < n - 1; ++i) {
        // Encontra o nó com menor peso que ainda não está na MST
        std::size_t u = std::numeric_limits<std::size_t>::max();
        for (std::size_t v = 0; v < n; ++v) {
            if (!inMST[v] && (u == std::numeric_limits<std::size_t>::max() || minWeight[v] < minWeight[u])) {
                u = v;
            }
        }

        // Adiciona o nó selecionado à MST
        inMST[u] = true;

        // Adiciona a aresta à MST, exceto para o primeiro nó
        if (parent[u] != -1) {
            mstEdges.emplace_back(parent[u], static_cast<int>(u));
        }

        // Atualiza os pesos mínimos para os nós vizinhos
        for (std::size_t v = 0; v < n; ++v) {
            if (graph[u][v] && !inMST[v] && graph[u][v] < minWeight[v]) {
                minWeight[v] = graph[u][v];
                parent[v] = static_cast<int>(u);
            }
        }
    }

    // Construir o grafo da árvore geradora mínima
    std::vector<std::vector<int>> mstTree(n);
    for (const auto& edge : mstEdges) {
        mstTree[edge.first].push_back(edge.second);
        mstTree[edge.second].push_back(edge.first);
    }

    // Realizar DFS para obter a sequência em pré-ordem
    std::vector<int> preorder;
    std::vector<bool> visited(n, false);
    dfs(mstTree, 0, visited, preorder);

    return {mstEdges, preorder};
}

int calculateTotalDistance(const std::vector<int>& preorder, const std::vector<std::vector<int>>& distanceMatrix) {
    int totalDistance = 0;
    std::size_t n = preorder.size(); // Use std::size_t aqui, não int
    
    // Percorre os vértices na ordem dada pela sequência de pré-ordem
    for (std::size_t i = 0; i < n - 1; ++i) { // Também altere o tipo de i para std::size_t
        int u = preorder[i];
        int v = preorder[i + 1];
        totalDistance += distanceMatrix[u][v];
    }
    
    // Adiciona a distância de volta ao vértice inicial (ciclo fechado)
    totalDistance += distanceMatrix[preorder[n - 1]][preorder[0]];

    return totalDistance;
}

// Função auxiliar para realizar DFS na MST
void dfs(const std::vector<std::vector<int>>& tree, int current, std::vector<bool>& visited, std::vector<int>& preorder) {
    visited[current] = true;
    preorder.push_back(current); // Adiciona o nó à sequência em pré-ordem

    for (int neighbor : tree[current]) {
        if (!visited[neighbor]) {
            dfs(tree, neighbor, visited, preorder);
        }
    }
}