#include <iostream>
using namespace std;
#define MAT 9

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
                system("cls");  
                
                int matriz[MAT][MAT] = 
                {
                    {4, 9, 5, 2, 8, 7, 3, 6, 1}

                }























                system("pause");
                system("cls");
                break;
             
            case 2: 
                system("cls");
                cout << "Como jogar:\n\n";
                cout << "Escolha uma coordenada (que nao tenha numero), decidindo a linha e a coluna.\n\n";
                cout << "Insira a letra da linha, o numero da coluna e em seguida o numero escolhido.\n\n";
                cout << "Exemplo:   a 2 6   (linha \"a\", coluna \"2\" e o numero inserido e 6 )\n\n";
                system("pause");
                system("cls");
                break;

            case 3:
                system("cls");
                cout << "Equipe de Desenvolvimento: Carlos Osair De Souza, Eduardo Lechinski Ramos e Leonardo de Borba Cardoso\nMes/Ano: 06/2023\nProfessor: Rafael Ballottin Martins\nDisciplina: Algoritmos e Programação\n";
                system("pause");
                system("cls");
                break;

            case 4:
                return 0;
        }
    }
    return 0;
}