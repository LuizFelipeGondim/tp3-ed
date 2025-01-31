#ifndef ARVOREINDICES_HPP
#define ARVOREINDICES_HPP

#include "Vector.hpp"

template <typename T>
class ArvoreIndices {
private:
  struct No {
    T chave;
    Vector<int> indices; // Vetor com índices dos voos que possuem essa chave
    No* esquerda;
    No* direita;
    int altura;

    No(const T& chave) : chave(chave), esquerda(0), direita(0), altura(1) {}
  };

  No* raiz;

  No* inserir(No* no, const T& chave, int indiceVoo);
  No* balancear(No* no);
  int obterAltura(No* no);
  int fatorBalanceamento(No* no);
  No* rotacaoDireita(No* y);
  No* rotacaoEsquerda(No* x);
  void destruirArvore(No* no);
  void percorrerEmOrdem(No* no) const;

public:
  ArvoreIndices();
  ~ArvoreIndices();

  void inserir(const T& chave, int indiceVoo);
  void mostrarEmOrdem() const;
};

#include "ArvoreIndices.tpp" 

#endif
