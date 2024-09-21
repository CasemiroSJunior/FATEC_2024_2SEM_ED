/*
 * Exemplo do uso de pilha.
 *
 * Prof. Me. Orlando Saraiva Jr
 * Criado em : 05/04/2018
 */
 
#include <iostream>
#include <cstdlib>

#define STACK_MAX 6

struct Pilha {
    int data[STACK_MAX];
    int size;
};

void inicializar(Pilha* S) {
    S->size = 0;
}

void push(Pilha* S, int d) {
    if (S->size < STACK_MAX)
        S->data[S->size++] = d;
    else
        std::cerr << "Erro: pilha cheia\n";
}

int pop(Pilha* S) {
    int retorno;
    if (S->size == 0) {
        std::cerr << "Erro: pilha vazia\n";
        std::exit(-1);
    } else {
        S->size--;
        retorno = S->data[S->size];
        S->data[S->size] = 0;
        return retorno;
    }
}

void imprime_pilha(const Pilha* S) {
    for (int x = S->size; x > 0; x--)
        std::cout << S->data[x - 1] << " ";
    std::cout << std::endl;
}

int main() {
    Pilha minhaPilha;
    int valor;

    inicializar(&minhaPilha);

    push(&minhaPilha, 3);
    imprime_pilha(&minhaPilha);
    push(&minhaPilha, 5);
    imprime_pilha(&minhaPilha);
    push(&minhaPilha, 1);
    imprime_pilha(&minhaPilha);

    valor = pop(&minhaPilha);
    std::cout << "Valor desempilhado:\t" << valor << std::endl;
    valor = pop(&minhaPilha);
    std::cout << "Valor desempilhado:\t" << valor << std::endl;
    valor = pop(&minhaPilha);
    std::cout << "Valor desempilhado:\t" << valor << std::endl;

    return 0;
}

