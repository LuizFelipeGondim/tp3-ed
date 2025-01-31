#ifndef VOO_HPP
#define VOO_HPP

#include <iostream>
#include <string>
#include <ctime>

class Voo {
private:
  std::string origem;
  std::string destino;
  float preco;
  int assentosDisponiveis;
  std::time_t dataHoraPartida;
  std::time_t dataHoraChegada;
  std::time_t duracaoVoo;
  int numeroParadas;

public:
  
  Voo(
    std::string origem, 
    std::string destino, 
    float preco, 
    int assentosDisponiveis, 
    std::time_t dataHoraPartida, 
    std::time_t dataHoraChegada, 
    int numeroParadas
  );

  // Exibe os dados formatados
  void mostrarVoo() const;

private:
  // Função auxiliar para formatar data/hora
  std::string formatarHorario(std::time_t dataHora) const;
};

#endif
