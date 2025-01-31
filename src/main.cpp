#include "Sistema.hpp"
#include <iostream>
 /*
#include "ArvoreIndices.hpp"

int main() {
    ArvoreIndices<std::string> arvoreDestino;
    ArvoreIndices<int> arvoreParadas;
    
    arvoreDestino.inserir("ATL", 1);
    arvoreDestino.inserir("BOS", 2);
    arvoreDestino.inserir("DFW", 3);
    arvoreDestino.inserir("EWR", 4);
    arvoreDestino.inserir("BOS", 5); // Adiciona índice ao nó existente

    arvoreParadas.inserir(0, 1);
    arvoreParadas.inserir(1, 2);
    arvoreParadas.inserir(0, 3);
    arvoreParadas.inserir(1, 4);
    arvoreParadas.inserir(0, 5); // Adiciona índice ao nó existente

    std::cout << "Árvore de Destinos:" << std::endl;
    arvoreDestino.mostrarEmOrdem();

    std::cout << "\nÁrvore de Número de Paradas:" << std::endl;
    arvoreParadas.mostrarEmOrdem();

    return 0;
}*/

/* Função para fazer a conversão manual de data/hora para time_t
std::time_t parseDataHora(const std::string& data, const std::string& hora) {
    std::tm tm = {};  // Inicializa com 0
    std::stringstream dataStream(data);
    char separador; // Para ignorar os separadores '-'
    dataStream >> tm.tm_year >> separador >> tm.tm_mon >> separador >> tm.tm_mday;

    tm.tm_year -= 1900;  // O ano começa em 1900
    tm.tm_mon -= 1;      // O mês começa de 0 (0 = Janeiro)

    std::stringstream horaStream(hora);
    horaStream >> tm.tm_hour >> separador >> tm.tm_min >> separador >> tm.tm_sec;

    if (dataStream.fail() || horaStream.fail()) {
        std::cerr << "Erro ao converter data/hora: " << data << " " << hora << std::endl;
        return -1;
    }

    return std::mktime(&tm); // Converte para time_t
}

// Função para ler os voos do arquivo e preenchê-los no vetor
void lerVoosDoTXT(const std::string& nomeArquivo, Vector<Voo*>& voos) {
    std::ifstream arquivo(nomeArquivo);
    std::string linha;
    int quantidadeRegistros = 0;

    if (!arquivo.is_open()) {
        std::cerr << "Erro ao abrir o arquivo: " << nomeArquivo << "\n";
        return;
    }

    // Ler a primeira linha para obter a quantidade de registros
    if (std::getline(arquivo, linha)) {
        quantidadeRegistros = std::stoi(linha);
    }

    // Ler os voos com base na quantidade informada
    for (int i = 0; i < quantidadeRegistros; ++i) {
        if (!std::getline(arquivo, linha)) break;

        std::stringstream ss(linha);
        std::string origem, destino, precoStr, assentosStr, partidaStr, chegadaStr, paradasStr;

        ss >> origem >> destino >> precoStr >> assentosStr >> partidaStr >> chegadaStr >> paradasStr;

        float preco = std::stof(precoStr);
        int assentos = std::stoi(assentosStr);
        int paradas = std::stoi(paradasStr);
        std::time_t partida = parseDataHora(partidaStr.substr(0, 10), partidaStr.substr(11, 8)); // Considera a substring para data e hora
        std::time_t chegada = parseDataHora(chegadaStr.substr(0, 10), chegadaStr.substr(11, 8)); 

        // Adiciona o voo ao vetor
        voos.push(new Voo(origem, destino, preco, assentos, partida, chegada, paradas));
    }
}

int main() {
    Vector<Voo*> voos;  // Vetor para armazenar os voos
    lerVoosDoTXT("input1.txt", voos);  // Lê os voos do arquivo

    // Exibe os dados de cada voo
    for (auto& voo : voos) {
        voo->mostrarDados();
    }

    return 0;
}*/
#include <unistd.h>

int main(int argc, char *argv[]) {
  std::string fileName;

  try {

    if (optind < argc) {
      fileName = argv[optind]; 
    } else {
      throw std::runtime_error("Erro: Nome do arquivo não especificado.");
    }
    Sistema sistema(fileName);
    sistema.mostrarVoos();
  } catch (const std::runtime_error& e) {
    std::cerr << e.what() << std::endl;
  }
  
  return 0;
}