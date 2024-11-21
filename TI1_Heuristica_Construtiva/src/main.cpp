#include "node.h"
#include "distances.h"
#include "read.h"
#include "aprox.h"



int main() {
    std::string inputFolder = "instances"; // Substitua pelo caminho da sua pasta
    std::string outputFile = "resultados.txt";                // Arquivo de saída

    // Processa todos os arquivos na pasta de instâncias
    processAllInstances(inputFolder, outputFile);

    std::cout << "Processamento concluído! Resultados armazenados em " << outputFile << std::endl;

    return 0;
}