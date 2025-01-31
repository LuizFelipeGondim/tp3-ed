#include "Voo.hpp"
#include <iomanip>
#include <sstream>

Voo::Voo(
  std::string origem, 
  std::string destino, 
  float preco, 
  int assentosDisponiveis, 
  std::time_t dataHoraPartida, 
  std::time_t dataHoraChegada, 
  int numeroParadas
  ) : 
  origem(origem), 
  destino(destino), 
  preco(preco), 
  assentosDisponiveis(assentosDisponiveis), 
  dataHoraPartida(dataHoraPartida), 
  dataHoraChegada(dataHoraChegada), 
  duracaoVoo(dataHoraChegada - dataHoraPartida),
  numeroParadas(numeroParadas) {}


std::string Voo::formatarHorario(std::time_t dataHora) const {
  std::tm* tm = std::localtime(&dataHora);
  std::stringstream ss;
  ss << std::put_time(tm, "%Y-%m-%dT%H:%M:%S");
  return ss.str();
}

void Voo::mostrarVoo() const {
  std::cout << origem << " " << destino << " "
            << preco << " "
            << assentosDisponiveis << " "
            << formatarHorario(dataHoraPartida) << " "
            << formatarHorario(dataHoraChegada) << " "
            << numeroParadas << "\n";
}
