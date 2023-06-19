#include <cstdlib>
#include <iostream>

#define MAX 9

int main(int argc, char const* argv[]) {
  srand(time(NULL));
  int matriz[MAX][MAX] =
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


  int i = 41;
  while (i > 0) {
    int index1 = rand() % MAX;
    int index2 = rand() % MAX;

    if (matriz[index1][index2] != 0) {
      matriz[index1][index2] = 0;
      i--;
    }
  }

  for (int i = 0; i < MAX; i++) {
    for (int j = 0; j < MAX; j++) {
      if (matriz[i][j] != 0) {
        std::cout << matriz[i][j] << " ";
      }
      else {
        std::cout << "X ";
      }
    }
    std::cout << "\n";
  }

  int count = 0;
  while (count < 41) {
    std::cout << "\n make a movement (example position: 1 1): ";
    int index1, index2;
    std::cin >> index1 >> index2;

    if (matriz[index1 - 1][index2 - 1] == 0) {
      std::cout << "\n which number (1 - 9): ";
      int numberSelect;
      std::cin >> numberSelect;
      if (!(numberSelect < 1 || numberSelect > 9)) {
        matriz[index1 - 1][index2 - 1] = numberSelect;
        count--;
      }
    }


    for (int i = 0; i < MAX; i++) {
      for (int j = 0; j < MAX; j++) {
        if (matriz[i][j] != 0) {
          std::cout << matriz[i][j] << " ";
        }
        else {
          std::cout << "X ";
        }
      }
      std::cout << "\n";
    }
  }

  return 0;
}
