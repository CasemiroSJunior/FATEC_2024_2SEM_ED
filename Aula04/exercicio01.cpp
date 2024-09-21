#include <iostream>
#include <string>
using namespace std;

static int contadorCarros = 0;
static int contadorRevisao = 0;
bool isAnoOk = false;

int main()
{

    struct revisao
    {
        string data;
        string local;
    };


    struct cadastroCarro
    {
        string marca;
        string placa;
        int ano;
        struct revisao *vetor_revisao;
    };

    struct cadastroCarro carros;
    struct cadastroCarro *vetor_carros;

    cout << "Digite quantos carros quer cadastrar: " << endl;
    cin >> contadorCarros;

    vetor_carros = new cadastroCarro[contadorCarros];

    for (int i = 0; i < contadorCarros; i++)
    {
        cout << "Digite a marca do carro: " << endl;
        cin >> vetor_carros[i].marca;
        cout << "Digite a placa do carro:" << endl;
        cin >> vetor_carros[i].placa;
        cout << "Digite o ano do carro: " << endl;
        cin >> vetor_carros[i].ano;

        cout << "Digite quantos revisoes para este carro: " << endl;
        cin >> contadorRevisao;

        vetor_carros[i].vetor_revisao = new revisao[contadorRevisao];

        for (int j = 0; j < contadorRevisao; j++)
        {
            cout << "Digite a data da revisao:" << endl;
            cin >> vetor_carros[i].vetor_revisao[j].data;
            cout << "Digite o local da revisao: " << endl;
            cin >> vetor_carros[i].vetor_revisao[j].local;
        }
    }

    for (int i = 0; i < contadorCarros; i++){
        cout << "\n ---------------- Carro " << i << " ---------------- " << endl;
        cout << "Marca: " << vetor_carros[i].marca << endl;
        cout << "Placa: " << vetor_carros[i].placa << endl;
        cout << "Ano: " << vetor_carros[i].ano << endl;

        for (int j = 0; j < contadorRevisao; j++){
            cout << "\n ---------------- Revisao " << j << " ---------------- " << endl;
            cout << "Data: " << vetor_carros[i].vetor_revisao[j].data << endl;
            cout << "Local: " << vetor_carros[i].vetor_revisao[j].local << endl;
            cout << "----------------------------------xxx--------------------------------";
        }
        delete[] vetor_carros[i].vetor_revisao;
    }

    delete[] vetor_carros;
    return 0;
}