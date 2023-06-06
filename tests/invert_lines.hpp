#define MAX 9 
#include <iostream>

void invert_lines(int matrix[MAX][MAX]) {
  for (int i = 0; i < MAX / 2; i++) {
    for (int j = 0; j < MAX; j++) {
      int temp = matrix[i][j];
      matrix[i][j] = matrix[MAX - i - 1][j];
      matrix[MAX - i - 1][j] = temp;
    }
  }

}