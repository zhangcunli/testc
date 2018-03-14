#include <stdio.h>
#include <stdlib.h>

int main() {
  int a[][5] = {{1, 2, 3, 4, 5}, {11, 21, 31, 41, 51}, {12, 22, 32, 42, 52}};
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 5; j++) {
      printf("%3d", a[i][j]);
    }
    printf("\n");
  }
  printf("\n");

  int(*b)[3] = (int **)malloc(sizeof(int) * 2 * 3);
  b[0][0] = 1;
  b[0][1] = 2;
  b[0][2] = 3;
  b[1][0] = 4;
  b[1][1] = 5;
  b[1][2] = 6;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      printf("%3d", b[i][j]);
    }
    printf("\n");
  }
  printf("\n");

  int **c = (int **)malloc(sizeof(int *) * 2);
  for (int i = 0; i < 2; i++) {
    c[i] = (int *)malloc(sizeof(int) * 3);
  }
  c[0][0] = 1;
  c[0][1] = 2;
  c[0][2] = 3;
  c[1][0] = 4;
  c[1][1] = 5;
  c[1][2] = 6;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      printf("%3d", c[i][j]);
    }
    printf("\n");
  }
  printf("\n");

  int *d[3];
  for (int i = 0; i < 2; i++) {
    d[i] = (int *)malloc(sizeof(int) * 3);
  }
  d[0][0] = 1;
  d[0][1] = 2;
  d[0][2] = 3;
  d[1][0] = 4;
  d[1][1] = 5;
  d[1][2] = 6;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      printf("%3d", d[i][j]);
    }
    printf("\n");
  }
  printf("\n");

  return 0;
}