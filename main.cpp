#include <iostream>
#include <time.h>
using namespace std;
#define TAM 9

int main() {
    srand(time(NULL));

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
                                break;
                            }

                        case 3: // Matriz invertida por linha
                            {
                                for (int i = TAM - 1; i >= 0; i--) {
                                    for (int j = 0; j < TAM; j++) {
                                        gabarito[TAM - 1 - i][j] = sudoku[i][j];
                                    }
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

                                break;
                            }

                    }



                    int matriz_jogo[TAM][TAM];
                    for (int i = 0; i < TAM; i++) { // preenche matriz_jogo com a matriz gabarito
                        for (int j = 0; j < TAM; j++) {
                            matriz_jogo[i][j] = gabarito[i][j];
                        }
                    }
                    int i = 41;
                    while (i > 0) {// Retirar as 41 posições aleatoriamente
                        int index1 = rand() % TAM;
                        int index2 = rand() % TAM;

                        if (matriz_jogo[index1][index2] != 0) {
                            matriz_jogo[index1][index2] = 0;
                            i--;
                        }
                    }

                    int count = 0;
                    while (count < 41) { // laço do jogo
                        system("clear");
                        cout << "X   " << "1 2 3 4 5 6 7 8 9\n\n";
                        for (int i = 0; i < TAM; i++) { // imprime a matrix jogo
                            cout << "\033[0m" << i + 1 << "   ";
                            for (int j = 0; j < TAM; j++) {
                                if (matriz_jogo[i][j] != 0) {
                                    cout << "\033[0m" << matriz_jogo[i][j] << " ";
                                }
                                else {
                                    cout << "\033[31mX ";
                                }
                            }
                            cout << "\n";
                        }
                        cout << "\n\033[0mescolha a posição (ex: 1 1): ";
                        int index1, index2;
                        cin >> index1 >> index2;

                        if (!(index1 < 1 || index1 > 9 || index2 < 1 || index2 > 9)) {// verifica se os numeros estão no tamanho da matriz

                            if (matriz_jogo[index1 - 1][index2 - 1] == 0) { // verifica se pode colocar o numero na posição
                                cout << "\n escolha o numero (1 - 9): ";
                                int numero_selecionado;
                                cin >> numero_selecionado;

                                if (!(numero_selecionado < 1 || numero_selecionado > 9)) {// caso o numero selecionado esteja no range de 1-9

                                    if (numero_selecionado == gabarito[index1 - 1][index2 - 1]) { // caso bata com a matriz gabarito
                                        matriz_jogo[index1 - 1][index2 - 1] = numero_selecionado;
                                        count++; // conta até 41 para terminar o laço e finalizar o jogo
                                    }
                                    else {
                                        system("clear");
                                        cout << "numero errado!!" << endl;
                                        system("read 0 -p");
                                    }
                                }
                                else {
                                    system("clear");
                                    cout << "fora do tamanho!!" << endl;
                                    system("read 0 -p");
                                }

                            }
                            else {
                                system("clear");
                                cout << "numero não pode ser alterado!!" << endl;
                                system("read 0 -p");
                            }
                        }
                        else {
                            system("clear");
                            cout << "fora do tamanho da matriz!!" << endl;
                            system("read 0 -p");
                        }
                    }
                    system("clear");
                    cout << "PARABENS!!!! Fase finalizada com sucesso!" << endl;
                    system("read 0 -p");
                    system("clear");
                    break;
                }
            case 2: // Como jogar
                {
                    system("clear");
                    cout << "Como jogar:\n\n";
                    cout << "Escolha uma coordenada (que nao tenha numero), decidindo a linha e a coluna.\n\n";
                    cout << "Insira a letra da linha, o numero da coluna e em seguida o numero escolhido.\n\n";
                    cout << "Exemplo:   a 2 6   (linha \"1\", coluna \"2\" e o numero inserido e 6 )\n\n";
                    system("read 0 -p");
                    system("clear");
                    break;
                }
            case 3: // Sobre
                {
                    system("clear");
                    cout << "Equipe de Desenvolvimento: Carlos Osair De Souza, Eduardo Lechinski Ramos e Leonardo de Borba Cardoso\nMes/Ano: 06/2023\nProfessor: Rafael Ballottin Martins\nDisciplina: Algoritmos e Programação\n";
                    system("read 0 -p");
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