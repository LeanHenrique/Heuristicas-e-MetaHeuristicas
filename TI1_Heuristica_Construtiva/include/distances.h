#ifndef DISTANCES_H
#define DISTANCES_H

#include "node.h" // Para a definição da estrutura Node
#include <cmath>  // Para funções matemáticas

// Função para calcular a distância Euclidiana (EUC_2D)
int calculateEUC_2D(const Node& a, const Node& b);

// Função para calcular a distância pseudo-Euclidiana (ATT)
int calculateATT(const Node& a, const Node& b);

#endif // DISTANCES_H
