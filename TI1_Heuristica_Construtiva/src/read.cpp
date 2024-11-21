#include "distances.h"
#include "aprox.h"
#include "read.h"


namespace fs = std::filesystem; // Para facilitar o uso da biblioteca


// Função para ler nós e o tipo de distância do arquivo
std::pair<std::vector<Node>, std::string> readNodesFromFile(const std::string& filename) {
    std::vector<Node> nodes;
    std::string distanceType;
    std::ifstream file(filename);
    std::string line;

    if (!file.is_open()) {
        std::cerr << "Erro ao abrir o arquivo." << std::endl;
        return {nodes, ""};
    }

    // Lê o arquivo para encontrar o tipo de distância e a seção de coordenadas
    while (std::getline(file, line)) {
        if (line.rfind("EDGE_WEIGHT_TYPE", 0) == 0) {
            std::istringstream ss(line);
            std::string key, value;
            ss >> key >> value >> distanceType;
        } else if (line == "NODE_COORD_SECTION") {
            break;
        }
    }

    // Lê as coordenadas
    while (std::getline(file, line)) {
        if (line == "EOF") {
            break;
        }

        std::istringstream ss(line);
        int id; // Variável para armazenar e descartar o ID
        Node node;

        // Lê o ID e as coordenadas x, y
        ss >> id >> node.x >> node.y;

        // Adiciona o nó ao vetor
        nodes.push_back(node);
    }

    return {nodes, distanceType};
}

// Função principal para processar múltiplos arquivos
void processFiles(const std::vector<std::string>& inputFiles, const std::string& outputFile) {
    std::ofstream out(outputFile);

    if (!out.is_open()) {
        std::cerr << "Erro ao abrir o arquivo de saída: " << outputFile << std::endl;
        return;
    }

    for (const auto& inputFile : inputFiles) {
        // Lê os nós e o tipo de distância do arquivo
        auto [nodes, distanceType] = readNodesFromFile(inputFile);
        std::cout << "qtd nós: " << nodes.size() << ", tipo de distância: " << distanceType << std::endl;

        if (nodes.empty() || distanceType.empty()) {
            out << inputFile << " - Erro ao carregar nós ou tipo de distância.\n";
            continue;
        }

        // Inicializar a matriz de adjacência
        std::size_t n = nodes.size();
        std::vector<std::vector<int>> distanceMatrix(n, std::vector<int>(n, 0));

        // Preencher a matriz de adjacência com base no tipo de distância
        for (std::size_t i = 0; i < n; ++i) {
            for (std::size_t j = 0; j < n; ++j) {
                if (i != j) {
                    if (distanceType == "EUC_2D") {
                        distanceMatrix[i][j] = calculateEUC_2D(nodes[i], nodes[j]);
                    } else if (distanceType == "ATT") {
                        distanceMatrix[i][j] = calculateATT(nodes[i], nodes[j]);
                    }
                }
            }
        }

        // Executar o algoritmo de Prim
        std::pair<std::vector<std::pair<int, int>>, std::vector<int>> result = primMSTWithPreorder(distanceMatrix);

        const auto& preorder = result.second;

        // Calcular a distância total
        int totalDistance = calculateTotalDistance(preorder, distanceMatrix);

        // Armazena o resultado no arquivo de saída
        out << inputFile << " - Distância total: " << totalDistance << "\n";
    }

    out.close();
}

void processAllInstances(const std::string& inputFolder, const std::string& outputFile) {
    std::vector<std::string> inputFiles;

    // Itera sobre os arquivos na pasta de entrada
    for (const auto& entry : fs::directory_iterator(inputFolder)) {
        if (entry.is_regular_file()) {
            inputFiles.push_back(entry.path().string()); // Adiciona o caminho completo do arquivo
        }
    }

    if (inputFiles.empty()) {
        std::cerr << "Nenhum arquivo encontrado na pasta: " << inputFolder << std::endl;
        return;
    }

    // Processa os arquivos encontrados
    processFiles(inputFiles, outputFile);
}