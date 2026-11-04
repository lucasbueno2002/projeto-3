#include <iostream>
#include <string>

using namespace std;

// Struct Cadastro de Tutor
struct Tutor {
    int tutor;
    string nome;
    string endereco;
};

// Struct Cadastro de Animal
struct CadastroAnimal {
    int codigo;
    string nome;
    string especie;
    int idade;
    int tutor;
};

// Menu Principal
void mostrarMenu() {
    cout << "\n##################### MENU ####################\n";
    cout << "1 - Cadastrar Tutor\n";
    cout << "2 - Mostrar Tutor\n";
    cout << "3 - Mostrar Endereco\n";
    cout << "4 - Cadastrar Animal\n";
    cout << "5 - Mostrar Animais\n";
    cout << "6 - Buscar Animais por Tutor\n";
    cout << "7 - Relatorio Geral\n";
    cout << "0 - Sair\n";
    cout << "###############################################\n";
    cout << "\nDigite sua opcao: ";
}

// Cadastro de Tutor
void cadastrarTutor(Tutor vet[], int &n) {
    cout << "\nDigite o codigo: ";
    cin >> vet[n].tutor;

    // Verificar se o codigo ja existe
    for (int i = 0; i < n; i++) {
        if (vet[i].tutor == vet[n].tutor) {
            cout << "\nCodigo ja cadastrado!\n";
            return;
        }
    }

    cin.ignore();

    cout << "Digite o nome: ";
    getline(cin, vet[n].nome);

    cout << "Digite o endereco: ";
    getline(cin, vet[n].endereco);

    n++;

    cout << "\nTutor cadastrado com sucesso!\n";
}

// Mostrar Tutor
void mostrarTutor(Tutor vet[], int n) {

    if (n == 0) {
        cout << "\nNenhum Tutor cadastrado.\n";
        return;
    }

    cout << "\n======= Tutores cadastrados ========\n";

    for (int i = 0; i < n; i++) {
        cout << "---------------------\n";
        cout << "Codigo: " << vet[i].tutor << endl;
        cout << "Nome: " << vet[i].nome << endl;
        cout << "Endereco: " << vet[i].endereco << endl;
    }

    cout << "---------------------------\n";
}

// Mostrar Endereco
void mostrarEndereco(Tutor vet[], int n) {
    int codigo;

    cout << "\nDigite o codigo do tutor: ";
    cin >> codigo;

    for (int i = 0; i < n; i++) {
        if (vet[i].tutor == codigo) {
            cout << "\nEndereco: " << vet[i].endereco << endl;
            return;
        }
    }

    cout << "\nTutor nao encontrado!\n";
}

// Cadastro de Animal
void cadastrarAnimal(CadastroAnimal animais[],
                     int &qtd, Tutor tutores[], int n) {

    cout << "\nDigite o codigo do animal: ";
    cin >> animais[qtd].codigo;

    cin.ignore();

    cout << "Digite o nome do animal: ";
    getline(cin, animais[qtd].nome);

    cout << "Digite a especie: ";
    getline(cin, animais[qtd].especie);

    cout << "Digite a idade: ";
    cin >> animais[qtd].idade;

    cout << "Digite o codigo do tutor: ";
    cin >> animais[qtd].tutor;

    // Verificar se o tutor esta cadastrado
    for (int i = 0; i < n; i++) {
        if (tutores[i].tutor == animais[qtd].tutor) {
            qtd++;
            cout << "\nAnimal cadastrado com sucesso!\n";
            return;
        }
    }

    cout << "\nTutor nao encontrado! Cadastre o tutor primeiro.\n";
}

// Mostrar Animais
void mostrarAnimais(CadastroAnimal animais[],
                    int qtd, Tutor tutores[], int n) {

    if (qtd == 0) {
        cout << "\nNenhum animal cadastrado.\n";
        return;
    }

    cout << "\n======= Animais cadastrados ========\n";

    for (int i = 0; i < qtd; i++) {
        cout << "\nCodigo: " << animais[i].codigo;
        cout << "\nNome: " << animais[i].nome;
        cout << "\nEspecie: " << animais[i].especie;
        cout << "\nIdade: " << animais[i].idade;

        for (int j = 0; j < n; j++) {
            if (animais[i].tutor == tutores[j].tutor) {
                cout << "\nTutor: " << tutores[j].nome;
                break;
            }
        }

        cout << "\n----------------------------\n";
    }
}

// Buscar Animais por Tutor
void buscarAnimais(CadastroAnimal animais[],
                   int qtd, Tutor tutores[], int n) {

    int codigo;
    bool encontrou = false;
    bool tutorEncontrado = false;

    cout << "\nDigite o codigo do tutor: ";
    cin >> codigo;

    for (int i = 0; i < n; i++) {
        if (tutores[i].tutor == codigo) {
            tutorEncontrado = true;
            cout << "\nAnimais do tutor: " << tutores[i].nome << endl;
            break;
        }
    }

    if (!tutorEncontrado) {
        cout << "\nTutor nao encontrado!\n";
        return;
    }

    for (int i = 0; i < qtd; i++) {
        if (animais[i].tutor == codigo) {
            cout << "\nNome: " << animais[i].nome;
            cout << "\nEspecie: " << animais[i].especie;
            cout << "\nIdade: " << animais[i].idade << endl;

            encontrou = true;
        }
    }

    if (!encontrou) {
        cout << "\nEsse tutor nao possui animais cadastrados.\n";
    }
}

// Relatorio Geral
void relatorioGeral(CadastroAnimal animais[],
                    int qtd, Tutor tutores[], int n) {

    if (n == 0) {
        cout << "\nNenhum tutor cadastrado.\n";
        return;
    }

    cout << "\n======= RELATORIO GERAL ========\n";

    for (int i = 0; i < n; i++) {
        int quantidade = 0;

        for (int j = 0; j < qtd; j++) {
            if (animais[j].tutor == tutores[i].tutor) {
                quantidade++;
            }
        }

        cout << "\nTutor: " << tutores[i].nome;
        cout << "\nCodigo: " << tutores[i].tutor;
        cout << "\nQuantidade de animais: " << quantidade;
        cout << "\n----------------------------\n";
    }
}

// Programa Principal
int main() {

    Tutor tutores[100];
    CadastroAnimal animais[100];

    int qtdTutores = 0;
    int qtdAnimais = 0;
    int opcao;

    do {
        mostrarMenu();
        cin >> opcao;

        switch (opcao) {

            case 1:
                if (qtdTutores < 100) {
                    cadastrarTutor(tutores, qtdTutores);
                } else {
                    cout << "\nLimite de tutores atingido!\n";
                }
                break;

            case 2:
                mostrarTutor(tutores, qtdTutores);
                break;

            case 3:
                mostrarEndereco(tutores, qtdTutores);
                break;

            case 4:
                if (qtdAnimais < 100) {
                    cadastrarAnimal(animais, qtdAnimais,
                                    tutores, qtdTutores);
                } else {
                    cout << "\nLimite de animais atingido!\n";
                }
                break;

            case 5:
                mostrarAnimais(animais, qtdAnimais,
                               tutores, qtdTutores);
                break;

            case 6:
                buscarAnimais(animais, qtdAnimais,
                              tutores, qtdTutores);
                break;

            case 7:
                relatorioGeral(animais, qtdAnimais,
                               tutores, qtdTutores);
                break;

            case 0:
                cout << "\nSaindo do programa...\n";
                break;

            default:
                cout << "\nOpcao invalida!\n";
        }

    } while (opcao != 0);

    return 0;
}
