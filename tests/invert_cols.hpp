#define MAX 9 
#include <iostream>

void invert_cols(int matrix[MAX][MAX]) {
  for (int i = 0; i < MAX; i++) {
    for (int j = 0; j < MAX / 2; j++) {
      int temp = matrix[i][j];
      matrix[i][j] = matrix[i][MAX - j - 1];
      matrix[i][MAX - j - 1] = temp;
    }
  }

}