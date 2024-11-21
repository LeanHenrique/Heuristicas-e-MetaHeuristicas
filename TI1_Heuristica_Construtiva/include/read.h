#ifndef READ_H
#define READ_H

#include <string>
#include <vector>
#include <utility>
#include "node.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <filesystem>

// Função para ler nós e o tipo de distância do arquivo
std::pair<std::vector<Node>, std::string> readNodesFromFile(const std::string& filename);

// Função para processar múltiplos arquivos de entrada
void processFiles(const std::vector<std::string>& inputFiles, const std::string& outputFile);

void processAllInstances(const std::string& inputFolder, const std::string& outputFile);

#endif // READ_H
