#ifndef SISTEMA_HPP
#define SISTEMA_HPP

#include <string>
#include <fstream>
#include <sstream>
#include <stdexcept> 
#include "Vector.hpp"
#include "Voo.hpp"
#include "ArvoreIndices.hpp"

class Sistema {
private:
  int quantidadeRegistros;

  Vector<Voo*> voos;  // Vector que armazena os voos
  ArvoreIndices<std::string> arvoreIndicesOrigem;
  ArvoreIndices<std::string> arvoreIndicesDestino;
  ArvoreIndices<float> arvoreIndicesPreco;
  ArvoreIndices<int> arvoreIndicesAssentos;
  ArvoreIndices<time_t> arvoreIndicesPartida;
  ArvoreIndices<time_t> arvoreIndicesChegada;
  ArvoreIndices<time_t> arvoreIndicesDuracao;
  ArvoreIndices<int> arvoreIndicesParadas;

public:
  // Construtor que lê os voos a partir do arquivo
  Sistema(const std::string& nomeArquivo);

  // Função que mostra todos os voos selecionados
  void mostrarVoos() const;

  ~Sistema();
};

#endif
