#include <iostream>
#include <string>

using namespace std;

string criptografar(const string& msg, const string& key) {
    string criptografar = msg;
    for (size_t i = 0; i < criptografar.length(); ++i) {
        criptografar[i] = (criptografar[i] + key[i % key.length()]) % 26 + 'A';
    }
    return criptografar;
}

string descriptografar(const string& msg, const string& key) {
    string descriptografar = msg;
    for (size_t i = 0; i < descriptografar.length(); ++i) {
        descriptografar[i] = (descriptografar[i] - key[i % key.length()] + 26) % 26 + 'A';
    }
    return descriptografar;
}
void menu(){
    int opcao;
    string msg, key;
	int s =2;
    while ( s <=2) {
        cout << "Menu:\n";
        cout << "1 - Criptografar \n";
        cout << "2 - Decriptografar\n";
        cout << "3 - Sair do programa\n";
        cout << "Escolha uma opção: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                cout << "Digite a mensagem a ser criptografada: ";
                cin >> msg;
                cout << "Digite a chave: ";
                cin >> key;
                cout << "\n\nMensagem criptografada: " << criptografar(msg, key) << "\n\n\n";
                break;

            case 2:
                cout << "Digite a mensagem a ser descriptografada: ";
                cin >> msg;
                cout << "Digite a chave: ";
                cin >> key;
                cout << "\n\nMensagem descriptografada: " << descriptografar(msg, key) << "\n\n\n";
                break;

            case 3:
                cout << "Programa Finalizado.\n\n\n";
						s=3; 
					break;
            default:
                cout << "Opção inválida. Por favor, escolha uma opção válida.\n";
                break;
        }
    }

	
}

int main() {
	setlocale(LC_ALL,"portuguese");
	menu();
    return 0;
}

