#include <iostream>
using namespace std;
#define N 50

typedef struct{
    int id;
    string nome;
    int RA;
    string curso;
}ALUNO;

typedef struct{
    ALUNO elemento[N];
    int numeroAlunos;
}LISTA;

void inicializarLista(LISTA *l){
    l->numeroAlunos = 0;
}
int tamanho(LISTA *l){
    return l->numeroAlunos;
}

int buscaSequencial(LISTA *l, ALUNO aluno, bool exibir = false){
    int i = 0;
    while (i < l->numeroAlunos)
    {
        if (aluno.RA == l->elemento[i].RA)
        {
            return i;
        }
        else
        {
            i++;
        }
    }
    if(exibir){
        cout << "Aluno encontrado na posicao: " << i << endl;
        cout << "Informações do aluno: -------------" << endl;
        cout << "Nome: " << l->elemento[i].nome << endl;
        cout << "RA: " << l->elemento[i].RA << endl;
        cout << "Curso: " << l->elemento[i].curso << endl;
    }
    
    return -1;
}

bool adicionarAlunoLista(LISTA *l, ALUNO aluno){
    int index = tamanho(l);
    if (l->numeroAlunos >= N)
    {
        return false;
    }
    while (index > 0 && l->elemento[index - 1].id > aluno.id)
    {
        l->elemento[index] = l->elemento[index - 1];
        index--;
    }
    l->elemento[index] = aluno;
    l->numeroAlunos++;
    return true;
}

bool criarNovoAluno( ALUNO *aluno, LISTA *l){
    aluno->id = l->numeroAlunos + 1;
    cout << "Digite o nome do aluno: ";
    cin >> aluno->nome;
    cout << "Digite o RA do aluno: ";
    cin >> aluno->RA;
    cout << "Digite o curso do aluno: ";
    cin >> aluno->curso;
    if (adicionarAlunoLista(l, *aluno))
    {
        cout << "Aluno adicionado com sucesso!" << endl;
        return true;
    }
    else
    {
        cout << "Erro ao adicionar aluno!" << endl;
        return false;
    }
    
}

bool excluirAlunoLista(LISTA *l, ALUNO aluno){
    int pos, j;

    pos = buscaSequencial(l, aluno);
    if (pos == 1)
        return false;
    for (j = pos; j < l->numeroAlunos - 1; j++)
    {
        l->elemento[j] = l->elemento[j + 1];
    }
    l->numeroAlunos--;
    return true;
}

void exibirLista(LISTA* lista){
    int i;
    cout << "Lista: " << endl;
    for(i = 0 ; i < lista->numeroAlunos; i++) {
        cout << " Nome: " << lista->elemento[i].nome << endl;
        cout << " RA: " << lista->elemento[i].RA << endl;
        cout << " Curso: " << lista->elemento[i].curso << endl;
    }
    cout << endl;
}

int main(void){
    LISTA lista;
    ALUNO aluno;
    int x;
    bool deu_certo;

    inicializarLista(&lista);
    criarNovoAluno(&aluno, &lista);
    criarNovoAluno(&aluno, &lista);
    criarNovoAluno(&aluno, &lista);
    exibirLista(&lista);

    cout << "Digite o RA do aluno que deseja buscar: ";
    cin >> aluno.RA;
    buscaSequencial(&lista, aluno, true);
    cout << "Digite o RA do aluno que deseja remover: ";
    cin >> aluno.RA;
    excluirAlunoLista(&lista, aluno);
    exibirLista(&lista);

}
