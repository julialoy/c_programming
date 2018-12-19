#include <stdlib.h>
#include <stdio.h>

/* void rotateCoords(int x_coord, int y_coord, char matrix[10][10]) { */
/*   int orig_x = x_coord; */
/*   int orig_y = y_coord; */
/*   printf("Original X: %d; Original y: %d\n", orig_x, orig_y); */

/*   int next_x = y_coord; */
/*   int next_y = 9 - x_coord; */
/*   printf("First Next_x: %d; First Next_y: %d\n", next_x, next_y); */

/*   char * temp_ptr = &matrix[next_x][next_y]; */
/*   printf("Before reassign, temp_ptr is %c\n", *temp_ptr); */
  
/*   for(int j=0; j < 4; j++) { */
/*     matrix[next_x][next_y] = matrix[orig_x][orig_y]; */
    
/*     matrix[orig_x][orig_y] = *temp_ptr; */
/*     printf("After reassign, temp_ptr is %c\n", *temp_ptr); */
/*     int temp_x = next_x; */
/*     next_x = next_y; */
/*     next_y = 9 - temp_x; */
/*     //int * next_x_ptr = &next_x; */
/*     //int * next_y_ptr = &next_y; */
/*     //getNextCoord(next_x_ptr, next_y_ptr); */
/*     printf("After reassign, next_x is %d, next_y is %d\n", next_x, next_y); */
/*   } */

/* } */
void rotate(char matrix[10][10]) {
  for(int x=0; x < 10; x++) {
    for(int y=x; y < 9 - x; y++) {
      int i = 0;
      int next_x_coord = y;
      int next_y_coord = 9 - x;
      while(i < 4) {
	char next_char = matrix[next_x_coord][next_y_coord];
	matrix[next_x_coord][next_y_coord] = matrix[x][y];
	matrix[x][y] = next_char;
	int temp_x_coord = next_x_coord;
	next_x_coord = next_y_coord;
	next_y_coord = 9 - temp_x_coord;
	i++;
      }
    }
  }
}
