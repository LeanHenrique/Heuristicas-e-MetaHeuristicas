#ifndef NODE_H
#define NODE_H

// Estrutura para armazenar as coordenadas de cada ponto
struct Node {
    double x; // Coordenada x
    double y; // Coordenada y

    // Construtor padrão
    Node() : x(0.0), y(0.0) {}

    // Construtor parametrizado
    Node(double xCoord, double yCoord) : x(xCoord), y(yCoord) {}
};

#endif // NODE_H
