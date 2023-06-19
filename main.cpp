#include <iostream>
#include <time.h>
using namespace std;
#define TAM 9

int main() {

    while (true) {
        cout << "                         _         _           \n";
        cout << "                        | |       | |          \n";
        cout << "         ___  _   _   __| |  ___  | | __ _   _ \n";
        cout << "        / __|| | | | / _` | / _ \\ | |/ /| | | |\n";
        cout << "        \\__ \\| |_| || (_| || (_) ||   < | |_| |\n";
        cout << "        |___/ \\__,_| \\__,_| \\___/ |_|\\_\\ \\__,_|\n";
        cout << endl;
        cout << "1 - Jogar     2 - Como jogar     3 - Sobre     4 - Sair";

        cout << endl;
        cout << endl;

        int auxMenu;
        cout << "                     Escolha: ";
        cin >> auxMenu;

        switch (auxMenu) {
            case 1: // Jogar
                {
                    system("clear");

                    int sudoku[TAM][TAM] =
                    {
                        4, 9, 5, 2, 8, 7, 3, 6, 1,
                        7, 2, 8, 6, 1, 3, 4, 9, 5,
                        3, 6, 1, 9, 5, 4, 7, 2, 8,
                        6, 5, 3, 8, 4, 9, 2, 1, 7,
                        9, 8, 4, 1, 7, 2, 6, 5, 3,
                        2, 1, 7, 5, 3, 6, 9, 8, 4,
                        1, 3, 2, 4, 6, 5, 8, 7, 9,
                        5, 4, 6, 7, 9, 8, 1, 3, 2,
                        8, 7, 9, 3, 2, 1, 5, 4, 6
                    };

                    int random, gabarito[TAM][TAM] = { 0 };
                    random = (rand() + time(NULL)) % 4 + 1;

                    switch (random) // Switch para randomizar a matriz gabarito
                    {

                        case 1: //Matriz normal
                            {
                                for (int i = 0; i < TAM; i++) {
                                    for (int j = 0; j < TAM; j++) {
                                        gabarito[i][j] = sudoku[i][j];
                                    }
                                }

                                break;
                            }

                        case 2: //Matriz transposta
                            {
                                for (int i = 0; i < TAM; i++) {
                                    for (int j = 0; j < TAM; j++) {
                                        gabarito[i][j] = sudoku[j][i];
                                    }
                                }

                                for (int i = 0; i < TAM; i++) {
                                    for (int j = 0; j < TAM; j++) {
                                        cout << gabarito[i][j] << " ";
                                    }
                                    cout << endl;
                                }

                                break;
                            }

                        case 3: // Matriz invertida por linha
                            {
                                for (int i = TAM - 1; i >= 0; i--) {
                                    for (int j = 0; j < TAM; j++) {
                                        gabarito[TAM - 1 - i][j] = sudoku[i][j];
                                    }
                                }

                                for (int i = 0; i < TAM; i++) {
                                    for (int j = 0; j < TAM; j++) {
                                        cout << gabarito[i][j] << " ";
                                    }
                                    cout << endl;
                                }

                                break;
                            }

                        case 4: //Matriz invertida por coluna
                            {
                                for (int i = 0; i < TAM; i++) {
                                    for (int j = TAM - 1; j >= 0; j--) {
                                        gabarito[i][TAM - 1 - j] = sudoku[i][j];
                                    }
                                }

                                for (int i = 0; i < TAM; i++) {
                                    for (int j = 0; j < TAM; j++) {
                                        cout << gabarito[i][j] << " ";
                                    }
                                    cout << endl;
                                }

                                break;
                            }

                    }

                    // Retirar as 40 posições aleatoriamente

                    int linhas[TAM] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
                    char colunas[TAM] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i' };
                    int casas = 41, numero = 0, linha = 0;
                    char coluna;
                    while (casas > 0) {
                        system("clear");
                        cout << "X  ";
                        for (int i = 0; i < TAM; i++) { // imprimir as letras da coluna
                            cout << colunas[i] << " ";
                        }

                        cout << endl << endl;

                        for (int i = 0; i < TAM; i++) { // imprimir o numero das linhas e a matriz gabarito
                            cout << linhas[i] << "  ";
                            for (int j = 0; j < TAM; j++) {
                                cout << gabarito[i][j] << " ";
                            }
                            cout << endl;
                        }

                        cout << endl;
                        cout << "Informe sua jogada: ";
                        cin >> coluna >> linha >> numero;
                        cout << endl;
                        system("read -p 0");
                        casas = casas - 20;
                    };

                    system("read -p 0");
                    system("clear");
                    break;
                }
            case 2: // Como jogar
                {
                    system("clear");
                    cout << "Como jogar:\n\n";
                    cout << "Escolha uma coordenada (que nao tenha numero), decidindo a linha e a coluna.\n\n";
                    cout << "Insira a letra da linha, o numero da coluna e em seguida o numero escolhido.\n\n";
                    cout << "Exemplo:   a 2 6   (linha \"a\", coluna \"2\" e o numero inserido e 6 )\n\n";
                    system("read -p 0");
                    system("clear");
                    break;
                }
            case 3: // Sobre
                {
                    system("clear");
                    cout << "Equipe de Desenvolvimento: Carlos Osair De Souza, Eduardo Lechinski Ramos e Leonardo de Borba Cardoso\nMes/Ano: 06/2023\nProfessor: Rafael Ballottin Martins\nDisciplina: Algoritmos e Programação\n";
                    system("read -p 0");
                    system("clear");
                    break;
                }
            case 4: // Sair
                {
                    return 0;
                }
        }
    }
    return 0;
}