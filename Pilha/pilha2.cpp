/*
 * Exemplo do uso de pilha.
 *
 * Prof. Me. Orlando Saraiva Jr
 * Criado em : 05/04/2018
 */
 
#include <iostream>
#include <cstdlib>

struct Node {
    int item;
    Node* next;
};

struct Pilha {
    Node* top;
    int size;
};

Pilha* inicializar() {
    Pilha* s = new Pilha; // Alocar memória usando 'new'
    s->size = 0;  // Setar o tamanho da pilha como zero.
    s->top = NULL; // O topo da pilha é NULL
    return s;
}

void push(Pilha* s, int value) {
    Node* np = new Node;  // Alocar Node usando 'new'
    if (np == NULL) {
        std::exit(1);
    }

    np->item = value; // Setar o valor no Node.
    np->next = s->top; // Copiar o último endereço que estará no topo da pilha
    s->top = np; // O topo está apontando para o novo Node criado.
    s->size++; // Incrementar o tamanho da pilha
}

int pop(Pilha* s) {
    if (s->top == NULL) {
        std::exit(1);
    }

    Node* np = s->top; // Um ponteiro de nó está apontando para o topo da pilha.
    int temp = s->top->item; // Armazenar o valor do topo da pilha.
    s->top = np->next; // O topo da pilha aponta para o nó abaixo.
    s->size--; // Decrementar o tamanho da pilha.
    delete np; // Desalocar o nó do topo usando 'delete'

    return temp; // Retornar o valor desempilhado.
}

void destruir_pilha(Pilha* s) {
    while (s->top != NULL) {
        pop(s);
    }
    delete s; // Desalocar a estrutura da pilha usando 'delete'
}

void imprime_pilha(Pilha* s) {
    if (s->top == NULL) {
        return;
    }
    
    Node* temp = s->top;
    std::cout << "# " << s->size << std::endl;
    
    while (temp != NULL) {
        std::cout << temp->item << " ";
        temp = temp->next;
    }
    
    std::cout << std::endl;
}

int main() {
    Pilha* minha_pilha = inicializar();

    imprime_pilha(minha_pilha);
    push(minha_pilha, 7);
    imprime_pilha(minha_pilha);
    push(minha_pilha, 9);
    push(minha_pilha, 3);
    push(minha_pilha, 6);
    push(minha_pilha, 2);
    push(minha_pilha, 1);
    imprime_pilha(minha_pilha);

    int valor = pop(minha_pilha);
    std::cout << "Valor desempilhado:\t" << valor << std::endl;
    valor = pop(minha_pilha);
    std::cout << "Valor desempilhado:\t" << valor << std::endl;

    imprime_pilha(minha_pilha);

    valor = pop(minha_pilha);
    std::cout << "Valor desempilhado:\t" << valor << std::endl;
    valor = pop(minha_pilha);
    std::cout << "Valor desempilhado:\t" << valor << std::endl;

    destruir_pilha(minha_pilha);
    return 0;
}

