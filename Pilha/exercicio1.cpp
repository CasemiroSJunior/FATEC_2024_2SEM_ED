#include <iostream>
#include <string>
using namespace std;

#define ParkingCapacity 10

struct Carros{
    string placa;
    string modelo;
    int ano;
};

struct Estacionamento{
    Carros carros[ParkingCapacity];
    int usedSpace;
};

void createParking(Estacionamento *e){
    e->usedSpace = 0;
};

void EstacionarCarro(Estacionamento *e, string placa, string modelo, int ano){
    if (e->usedSpace < ParkingCapacity){
        e->carros[e->usedSpace].placa = placa;
        e->carros[e->usedSpace].modelo = modelo;
        e->carros[e->usedSpace].ano = ano;
        e->usedSpace++;
    }
    else
    {
        cout << "Estacionamento cheio" << endl;
    }
};

string CheckOut(Estacionamento *e){
    string placa;
    if (e->usedSpace < 0)
    {
        cout << "Estacionamento vazio" << endl;
        exit(-1);
    }
    else
    {
        e->usedSpace--;
        placa = e->carros[e->usedSpace].placa;
        e->carros[e->usedSpace].placa = "";
        e->carros[e->usedSpace].modelo = "";
        e->carros[e->usedSpace].ano = 0;
        return placa;
    }
}

void listarCarros(Estacionamento *e){
    for(int i = e->usedSpace - 1; i>0, i--;){
        cout << "Placa: " << e->carros[i].placa << endl;
        cout << "Modelo: " << e->carros[i].modelo << endl;
        cout << "Ano: " << e->carros[i].ano << endl;
    }
}

int main()
{
    Estacionamento estacionamento;
    string carro;

    createParking(&estacionamento);
    EstacionarCarro(&estacionamento, "Case123", "Fusca", 1970);
    listarCarros(&estacionamento);
    EstacionarCarro(&estacionamento, "Orlando3223", "hb20", 2020);
    listarCarros(&estacionamento);
    EstacionarCarro(&estacionamento, "Casemoto3442", "pcx", 2023);
    listarCarros(&estacionamento);

    carro = CheckOut(&estacionamento);
    cout << "Carro retirado: " << carro << endl;

    listarCarros(&estacionamento);
    
    carro = CheckOut(&estacionamento);
    cout << "Carro retirado: " << carro << endl;
    
    listarCarros(&estacionamento);

    carro = CheckOut(&estacionamento);
    cout << "Carro retirado: " << carro << endl;


    return 0;
}