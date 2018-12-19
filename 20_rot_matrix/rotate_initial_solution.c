#include <stdlib.h>
#include <stdio.h>

void rotate(char matrix[10][10]) {
  char rot_matrix[10][10];
  for(int x=0; x < 10; x++) {
    for(int y=0; y < 10; y++) {
      int rot_x_coord = y;
      int rot_y_coord = 9 - x;
      rot_matrix[rot_x_coord][rot_y_coord] = matrix[x][y];
    }
  }
  for(int i=0; i < 10; i++) {
    for(int j=0; j < 10; j++) {
      matrix[i][j] = rot_matrix[i][j];
    }
  }
}
