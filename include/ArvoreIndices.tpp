#include "ArvoreIndices.hpp"

template <typename T>
ArvoreIndices<T>::ArvoreIndices() : raiz(0) {}

template <typename T>
ArvoreIndices<T>::~ArvoreIndices() {
  destruirArvore(raiz);
}

template <typename T>
void ArvoreIndices<T>::destruirArvore(No* no) {
  if (no) {
    destruirArvore(no->esquerda);
    destruirArvore(no->direita);
    delete no;
  }
}

template <typename T>
int ArvoreIndices<T>::obterAltura(No* no) {
  return no ? no->altura : 0;
}

template <typename T>
int ArvoreIndices<T>::fatorBalanceamento(No* no) {
  return no ? obterAltura(no->esquerda) - obterAltura(no->direita) : 0;
}

template <typename T>
typename ArvoreIndices<T>::No* ArvoreIndices<T>::rotacaoDireita(No* y) {
  No* x = y->esquerda;
  No* T2 = x->direita;

  x->direita = y;
  y->esquerda = T2;

  y->altura = (obterAltura(y->esquerda) > obterAltura(y->direita) ? obterAltura(y->esquerda) : obterAltura(y->direita)) + 1;
  x->altura = (obterAltura(x->esquerda) > obterAltura(x->direita) ? obterAltura(x->esquerda) : obterAltura(x->direita)) + 1;

  return x;
}

template <typename T>
typename ArvoreIndices<T>::No* ArvoreIndices<T>::rotacaoEsquerda(No* x) {
  No* y = x->direita;
  No* T2 = y->esquerda;

  y->esquerda = x;
  x->direita = T2;

  x->altura = (obterAltura(x->esquerda) > obterAltura(x->direita) ? obterAltura(x->esquerda) : obterAltura(x->direita)) + 1;
  y->altura = (obterAltura(y->esquerda) > obterAltura(y->direita) ? obterAltura(y->esquerda) : obterAltura(y->direita)) + 1;

  return y;
}

template <typename T>
typename ArvoreIndices<T>::No* ArvoreIndices<T>::balancear(No* no) {
  int balance = fatorBalanceamento(no);

  if (balance > 1 && fatorBalanceamento(no->esquerda) >= 0)
    return rotacaoDireita(no);

  if (balance > 1 && fatorBalanceamento(no->esquerda) < 0) {
    no->esquerda = rotacaoEsquerda(no->esquerda);
    return rotacaoDireita(no);
  }

  if (balance < -1 && fatorBalanceamento(no->direita) <= 0)
    return rotacaoEsquerda(no);

  if (balance < -1 && fatorBalanceamento(no->direita) > 0) {
    no->direita = rotacaoDireita(no->direita);
    return rotacaoEsquerda(no);
  }

  return no;
}

template <typename T>
typename ArvoreIndices<T>::No* ArvoreIndices<T>::inserir(No* no, const T& chave, int indiceVoo) {
  if (!no) {
    No* novoNo = new No(chave);
    novoNo->indices.push(indiceVoo);
    return novoNo;
  }

  if (chave < no->chave) {
    no->esquerda = inserir(no->esquerda, chave, indiceVoo);
  } else if (chave > no->chave) {
    no->direita = inserir(no->direita, chave, indiceVoo);
  } else {
    no->indices.push(indiceVoo);
    return no;
  }

  no->altura = (obterAltura(no->esquerda) > obterAltura(no->direita) ? obterAltura(no->esquerda) : obterAltura(no->direita)) + 1;

  return balancear(no);
}

template <typename T>
void ArvoreIndices<T>::inserir(const T& chave, int indiceVoo) {
  raiz = inserir(raiz, chave, indiceVoo);
}

template <typename T>
void ArvoreIndices<T>::percorrerEmOrdem(No* no) const {
  if (no) {
    percorrerEmOrdem(no->esquerda);
    std::cout << no->chave << ": ";
    for (int i = 0; i < no->indices.getSize(); ++i)
      std::cout << no->indices[i] << " ";
    
    std::cout << std::endl;
    percorrerEmOrdem(no->direita);
  }
}

template <typename T>
void ArvoreIndices<T>::mostrarEmOrdem() const {
  percorrerEmOrdem(raiz);
}