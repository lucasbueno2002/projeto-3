#include <iostream>

using namespace std;
// Struct Cadastro de Tutor
struct Tutor {
    int tutor;
    string nome;
    string endereco;
};

// Struct Cadastro de  Animal
struct CadastroAnimal {
    int codigo;
    string nome;
    string especie;
    string idade;
};

// Menu Principal
void mostrarMenu() {
   cout << "\n##################### menu ####################\n";
   cout << "1 - Cadastrar Tutor\n";
   cout << "2 - Mostrar Tutor\n";
   cout << "3 - Mostrar Endereco\n";
   cout << "0 - Sair\n";
   cout << "###################################\n\n";
   cout << "Digite sua opcao: ";

}

// Cadastro de Tutor
void cadastrarTutor(Tutor vet[], int i) {
  cout << "\nDigite o codigo: ";
  cin >> vet[i].codigo;
  cin.ignore();

  cout << "Digite o nome: ";
  getline(cin, vet[i].nome);

  cout << "Digite o endereco: ";
  cin >> vet[i].endereco;

  cout << "\nTutor cadastrado com sucesso!\n ";
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
        cout << "Codigo: " << vet[i].codigo << endl;
        cout << "Nome: " << vet[i].nome << endl;
        cout << "Endereco: " << vet[i].endereco << endl;
   }

   cout << "---------------------------\n";

//
}

return 0; {

}
