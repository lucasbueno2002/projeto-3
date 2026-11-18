#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// Estrutura do filme
struct Filme {
    string titulo;
    string genero;
    int duracao;
};

// Cadastrar filme
void cadastrarFilme(Filme &filme) {
    cin.ignore();

    cout << "\nDigite o titulo do filme: ";
    getline(cin, filme.titulo);

    cout << "Digite o genero do filme: ";
    getline(cin, filme.genero);

    cout << "Digite a duracao em minutos: ";
    cin >> filme.duracao;

    cout << "\nFilme cadastrado com sucesso!\n";
}

// Mostrar informacoes
void mostrarFilme(Filme filme) {
    if (filme.titulo.empty()) {
        cout << "\nNenhum filme cadastrado!\n";
    } else {
        cout << "\n===== INFORMACOES DO FILME =====\n";
        cout << "Titulo: " << filme.titulo << endl;
        cout << "Genero: " << filme.genero << endl;
        cout << "Duracao: " << filme.duracao << " minutos\n";
    }
}

// Salvar informacoes no arquivo
void salvarFilme(Filme filme) {
    ofstream arquivo("filme.txt");

    if (arquivo.is_open()) {
        arquivo << filme.titulo << endl;
        arquivo << filme.genero << endl;
        arquivo << filme.duracao << endl;

        arquivo.close();

        cout << "\nInformacoes salvas com sucesso!\n";
    } else {
        cout << "\nErro ao salvar o arquivo!\n";
    }
}

// Carregar informacoes do arquivo
void carregarFilme(Filme &filme) {
    ifstream arquivo("filme.txt");

    if (arquivo.is_open()) {
        getline(arquivo, filme.titulo);
        getline(arquivo, filme.genero);
        arquivo >> filme.duracao;

        arquivo.close();

        cout << "\nInformacoes carregadas com sucesso!\n";
    } else {
        cout << "\nArquivo nao encontrado!\n";
    }
}

// Funcao principal
int main() {
    Filme filme;
    int opcao;

    do {
        cout << "\n========== MENU ==========\n";
        cout << "1 - Cadastrar filme\n";
        cout << "2 - Mostrar informacoes\n";
        cout << "3 - Salvar informacoes\n";
        cout << "4 - Carregar informacoes\n";
        cout << "0 - Sair\n";

        cout << "\nEscolha uma opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                cadastrarFilme(filme);
                break;

            case 2:
                mostrarFilme(filme);
                break;

            case 3:
                salvarFilme(filme);
                break;

            case 4:
                carregarFilme(filme);
                break;

            case 0:
                cout << "\nPrograma encerrado!\n";
                break;

            default:
                cout << "\nOpcao invalida!\n";
        }

    } while (opcao != 0);

    return 0;
}
