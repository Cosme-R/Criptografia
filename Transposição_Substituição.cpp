#include <iostream>
#include <string>
using namespace std;

string substituicaoCriptografar(string texto) {
    for (size_t i = 0; i < texto.length(); ++i) {
        if (isalpha(texto[i])) {
            if (texto[i] == 'z') texto[i] = 'a';
            else if (texto[i] == 'Z') texto[i] = 'A';
            else texto[i]++;
        }
    }
    return texto;
}

string substituicaoDecriptografar(string texto) {
    for (size_t i = 0; i < texto.length(); ++i) {
        if (isalpha(texto[i])) {
            if (texto[i] == 'a') texto[i] = 'z';
            else if (texto[i] == 'A') texto[i] = 'Z';
            else texto[i]--;
        }
    }
    return texto;
}

string transposicaoCriptografar(string texto) {
    for (size_t i = 0; i < texto.length() - 1; i += 2) {
        swap(texto[i], texto[i + 1]);
    }
    return texto;
}

string transposicaoDecriptografar(string texto) {
    for (size_t i = 0; i < texto.length() - 1; i += 2) {
        swap(texto[i], texto[i + 1]);
    }
    return texto;
}

void Menu(){
	int opcao;
    string texto;

    do {
        cout << "Menu:\n";
        cout << "1. Criptografia por substituicao\n";
        cout << "2. Decriptografia por substituicao\n";
        cout << "3. Criptografia por transposicao\n";
        cout << "4. Decriptografia por transposicao\n";
        cout << "5. Sair do programa\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        if (opcao >= 1 && opcao <= 4) {
            cout << "Digite o texto: ";
            cin.ignore();
            getline(cin, texto);

            switch (opcao) {
                case 1:
                    cout << "\n\n\nTexto criptografado: " << substituicaoCriptografar(texto) <<"\n\n\n"<< endl;
                    
                    break;
                    
                case 2:
                    cout << "\n\n\nTexto decriptografado: " << substituicaoDecriptografar(texto)<<"\n\n\n" << endl;
                    break;
                case 3:
                    cout << "\n\n\nTexto criptografado: " << transposicaoCriptografar(texto)<<"\n\n\n" << endl;
                    break;
                case 4:
                    cout << "\n\n\nTexto decriptografado: " << transposicaoDecriptografar(texto)<<"\n\n\n" << endl;
                    break;
            }
        } else if (opcao != 5) {
            cout << "Opcao invalida. Tente novamente.\n";
        }
    } while (opcao != 5);

    cout << "Programa encerrado.\n";
	
}

int main() {
   setlocale(LC_ALL, "Portuguese");
   Menu();
   
    return 0;
}

