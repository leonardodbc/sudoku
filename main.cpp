#include <iostream>
#include <time.h>
using namespace std;
#define TAM 9

int main() {

    while(true) 
    {
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

        switch (auxMenu)
        {
            case 1: 
            {
                system("cls");  

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

                int random;
                random = (rand() + time(NULL)) % 4 + 1;
                int gabarito[TAM][TAM] = {0};
                cout << random;
                cout << endl << endl;

                switch (random)
                { // Switch para randomizar a matriz gabarito

                    case 1: //Matriz normal
                    {
                        for (int i = 0; i < TAM; i ++) {
                            for (int j = 0; j < TAM; j ++) {
                                gabarito[i][j] = sudoku[i][j];
                            }
                        }

                        break;
                    }

                    case 2: //Matriz transposta
                    {
                        for (int i = 0; i < TAM; i++) {
                            for (int j = 0; j < TAM; j ++) {
                                gabarito[i][j] = sudoku[j][i];
                            }
                        }

                        for (int i = 0; i < TAM; i++) {
                            for (int j = 0; j < TAM; j ++) {
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

                system("pause");
                system("cls");
                break;
            }
            case 2: 
            {
                system("cls");
                cout << "Como jogar:\n\n";
                cout << "Escolha uma coordenada (que nao tenha numero), decidindo a linha e a coluna.\n\n";
                cout << "Insira a letra da linha, o numero da coluna e em seguida o numero escolhido.\n\n";
                cout << "Exemplo:   a 2 6   (linha \"a\", coluna \"2\" e o numero inserido e 6 )\n\n";
                system("pause");
                system("cls");
                break;
            }
            case 3: 
            {
                system("cls");
                cout << "Equipe de Desenvolvimento: Carlos Osair De Souza, Eduardo Lechinski Ramos e Leonardo de Borba Cardoso\nMes/Ano: 06/2023\nProfessor: Rafael Ballottin Martins\nDisciplina: Algoritmos e Programação\n";
                system("pause");
                system("cls");
                break;
            }
            case 4: 
            {
                return 0;
            }
        }
    }
    return 0;
}