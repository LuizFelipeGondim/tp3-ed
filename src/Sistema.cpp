#include "Sistema.hpp"

// Função para fazer a conversão manual de data/hora para time_t
std::time_t parseDataHora(const std::string& data, const std::string& hora) {
  std::tm tm = {};  // Inicializa com 0
  std::stringstream dataStream(data);
  char separador; // Para ignorar os separadores '-'
  dataStream >> tm.tm_year >> separador >> tm.tm_mon >> separador >> tm.tm_mday;

  tm.tm_year -= 1900;
  tm.tm_mon -= 1;

  std::stringstream horaStream(hora);
  horaStream >> tm.tm_hour >> separador >> tm.tm_min >> separador >> tm.tm_sec;

  if (dataStream.fail() || horaStream.fail())
    throw std::runtime_error("Erro ao converter data/hora");

  return std::mktime(&tm); // Converte para time_t
}


Sistema::Sistema(const std::string& nomeArquivo) {
  std::ifstream arquivo(nomeArquivo);
  std::string linha;
  quantidadeRegistros = 0;

  if (!arquivo.is_open())
    throw std::runtime_error("Erro ao abrir o arquivo");

  // Ler a primeira linha para obter a quantidade de registros
  if (std::getline(arquivo, linha))
    quantidadeRegistros = std::stoi(linha);

  // Ler os voos com base na quantidade informada
  for (int i = 0; i < quantidadeRegistros; ++i) {
    if (!std::getline(arquivo, linha)) break;

    std::stringstream ss(linha);
    std::string origem, destino, precoStr, assentosStr, partidaStr, chegadaStr, paradasStr;

    ss >> origem >> destino >> precoStr >> assentosStr >> partidaStr >> chegadaStr >> paradasStr;

    float preco = std::stof(precoStr);
    int assentos = std::stoi(assentosStr);
    int paradas = std::stoi(paradasStr);
    std::time_t partida = parseDataHora(partidaStr.substr(0, 10), partidaStr.substr(11, 8));
    std::time_t chegada = parseDataHora(chegadaStr.substr(0, 10), chegadaStr.substr(11, 8)); 

    // Adiciona o voo ao vetor
    voos.push(new Voo(origem, destino, preco, assentos, partida, chegada, paradas));

    // Preenche as árvores de indices com os respectivos atributos e indices do voo 
    arvoreIndicesOrigem.inserir(origem, i);
    arvoreIndicesDestino.inserir(destino, i);
    arvoreIndicesPreco.inserir(preco, i);
    arvoreIndicesAssentos.inserir(assentos, i);
    arvoreIndicesPartida.inserir(partida, i);
    arvoreIndicesChegada.inserir(chegada, i);
    arvoreIndicesDuracao.inserir(chegada - partida, i);
    arvoreIndicesParadas.inserir(paradas, i);
  }
}

Sistema::~Sistema() {
  for (auto voo : voos)
    delete voo;
}

void Sistema::mostrarVoos() const {
  for (const auto& voo : voos)
    voo->mostrarVoo();
  /*
  std::cout << "Árvore de Origem:" << std::endl;
  arvoreIndicesOrigem.mostrarEmOrdem();

  std::cout << "Árvore de Destinos:" << std::endl;
  arvoreIndicesDestino.mostrarEmOrdem();

  std::cout << "Árvore de preco:" << std::endl;
  arvoreIndicesPreco.mostrarEmOrdem();

  std::cout << "Árvore de Assentos:" << std::endl;
  arvoreIndicesAssentos.mostrarEmOrdem();

  std::cout << "Árvore de Partida:" << std::endl;
  arvoreIndicesPartida.mostrarEmOrdem();

  std::cout << "Árvore de Chegada:" << std::endl;
  arvoreIndicesChegada.mostrarEmOrdem();

  std::cout << "Árvore de Duracao:" << std::endl;
  arvoreIndicesDuracao.mostrarEmOrdem();

  std::cout << "Árvore de Paradas:" << std::endl;
  arvoreIndicesParadas.mostrarEmOrdem();*/
}
