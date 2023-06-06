#include "invert_lines.hpp"
#include "transpose.hpp"
#include "invert_cols.hpp"
#define MAX 9

int main(int argc, char const* argv[]) {
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


  invert_cols(matriz);

  for (int i = 0; i < MAX; i++) {
    for (int j = 0; j < MAX; j++) {
      std::cout << matriz[i][j] << " ";
    }
    std::cout << std::endl;
  }

  return 0;
}
