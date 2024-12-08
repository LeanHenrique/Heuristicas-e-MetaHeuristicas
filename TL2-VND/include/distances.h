#ifndef DISTANCES_H
#define DISTANCES_H

#include "node.h" // Para a definição da estrutura Node
#include <cmath>  // Para funções matemáticas

// Função para calcular a distância Euclidiana (EUC_2D)
double calculateEUC_2D(const Node& node1, const Node& node2);

// Função para calcular a distância pseudo-Euclidiana (ATT)
double calculateATT(const Node& node1, const Node& node2);

#endif // DISTANCES_H
