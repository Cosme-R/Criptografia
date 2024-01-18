#include <iostream>
#include <cstring>
#include <string>
using namespace std;

void AlgoritmoCifraColunas(int Opcao, int Colunas) {
    int posicaoString = 0;
    int quantColunas = Colunas;
    string mensagem;
    
    if (Opcao == 1) {
        cout << "Entre o texto a ser criptografado: ";
        cin >> mensagem;
        int quantLinhas = mensagem.length() / 3 + 1; 
        char cifra3x80[quantColunas][quantLinhas];
        char* charArray = new char[mensagem.length() + 1];
        charArray[mensagem.length()] = '\0';
        for (int i = 0; i < mensagem.length(); i++) {
            charArray[i] = mensagem[i];
        }
        for (int contadorLinhas = 0; contadorLinhas < quantLinhas; contadorLinhas++)
        {
            for (int contadorColunas = 0; contadorColunas < quantColunas; contadorColunas++) {
                cifra3x80[contadorColunas][contadorLinhas] = charArray[posicaoString];
                posicaoString++;
                if (posicaoString >= mensagem.length()) {
                    break;
                }
            }

        }
        cout << "Representacao da mensagem criptografada: ";
        posicaoString = 0;
        for (int contadorColunas = 0; contadorColunas < quantColunas; contadorColunas++)
        {
            for (int contadorLinhas = 0; contadorLinhas < quantLinhas; contadorLinhas++) {
                cout << cifra3x80[contadorColunas][contadorLinhas];
                if (posicaoString >= mensagem.length()) {
                    break;
                }
            }
            cout << endl;
        }
        system("pause");
        cout << endl;
    }
    else {
        cout << "Entre o texto a ser descriptografada: ";
        cin >> mensagem;
        int quantLinhas = mensagem.length() / 3 + 1; 
        char cifra3x80[quantColunas][quantLinhas];
        char* charArray = new char[mensagem.length() + 1];
        charArray[mensagem.length()] = '\0';
        for (int i = 0; i < mensagem.length(); i++) {
            charArray[i] = mensagem[i];
        }
        posicaoString = 0;
        int contadorColunas = 0;
        do {
            for (int contadorLinhas = 0; contadorLinhas < quantLinhas; contadorLinhas++) {
                cifra3x80[contadorColunas][contadorLinhas] = charArray[posicaoString];
                posicaoString++;
            }
            contadorColunas++;
        }while(contadorColunas < quantColunas);

        cout << "Mensagem descriptografada: ";

        for (int contadorLinhas = 0; contadorLinhas < quantLinhas; contadorLinhas++)
        {
            for (int contadorColunas = 0; contadorColunas < quantColunas; contadorColunas++) {
                cout << cifra3x80[contadorColunas][contadorLinhas];
            }
        }
        system("pause");
    }
}
const int msg = 1000;

int calcularTamanho(const char* str) {
    int size = 0;
    while (str[size] != '\0') {
        size++;
    }
    return size;
}

void transposicaoCriptografar(int chave, char mensagem[]) {
    int mensagemLength = calcularTamanho(mensagem);
    int colunas = (mensagemLength + chave - 1) / chave;

    char matriz[colunas][chave];
    int matrizIndex = 0;

    for (int coluna = 0; coluna < colunas; ++coluna) {
        for (int linha = 0; linha < chave; ++linha) {
            matriz[coluna][linha] = (matrizIndex < mensagemLength) ? mensagem[matrizIndex++] : 'X';
        }
    }

    for (int linha = 0; linha < chave; ++linha) {
        for (int coluna = 0; coluna < colunas; ++coluna) {
            std::cout << matriz[coluna][linha];
        }
    }
    cout << endl;
}

void transposicaoDecriptografar(int chave, char mensagem[]) {
    int mensagemLength = calcularTamanho(mensagem);
    int colunas = (mensagemLength + chave - 1) / chave;

    char matriz[chave][colunas];
    int matrizIndex = 0;

    for (int linha = 0; linha < chave; ++linha) {
        for (int coluna = 0; coluna < colunas; ++coluna) {
            matriz[linha][coluna] = (matrizIndex < mensagemLength) ? mensagem[matrizIndex++] : 'X';
        }
    }

    for (int coluna = 0; coluna < colunas; ++coluna) {
        for (int linha = 0; linha < chave; ++linha) {
            cout << matriz[linha][coluna];
        }
    }
    cout << endl;
}
void Menu() {
    int loop;
    char mensagem[msg];
    int chave;
    do {
    	chave = 0;
        system("cls");
        cout << "Algoritmos de Criptografia --- Criptografar e Descriptografar" << endl;
        cout << "1 - Criptografar cifra das Colunas" << endl;
        cout << "2 - Descriptografar  cifra das Colunas" << endl;
        cout << "3 - Criptografar por Transposicao" << endl;
        cout << "4 - Descriptografar por Transposicao" << endl;
        cout << "0 - Sair" << endl;
        cin >> loop;
        switch (loop) {
            case 1:
            	cout << "Quantas colunas o algoritmo deve possuir ?" << endl;
            	cin >> chave;
                AlgoritmoCifraColunas(1, chave);
                break;
            case 2:
            	cout << "Quantas colunas o algoritmo deve possuir ?" << endl;
            	cin >> chave;
                AlgoritmoCifraColunas(2, chave);
                break;
            case 3:
                cout << "Digite a Chave: ";
                cin >> chave;
                cout << "Digite a Mensagem: ";
                cin.ignore();
                cin.getline(mensagem, msg);
                transposicaoCriptografar(chave, mensagem);
                break;  
            case 4:
                cout << "Digite a Chave: ";
                cin >> chave;
                cout << "Digite a Mensagem: ";
                cin.ignore();
                cin.getline(mensagem, msg);
                transposicaoDecriptografar(chave, mensagem);
                break;
            case 0:
            	break;
            default:
                cout << "Insira uma opcao valida";
                break;
        }

    } while (loop != 0);

}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    Menu();

    return 1;
}
