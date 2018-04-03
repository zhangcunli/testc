#include <stdio.h>
#include <stdlib.h>

void random_a(int a[], int M, int b[], int N) {
  int r = 0;

  for (int m = M - 1, j = 0; m >= M - N; m--, j++) {
    r = random() % m;
    int tmp = a[r];
    a[r] = a[m];
    a[m] = tmp;
    b[j] = tmp;
  }
}

int main() {
  int M = 100;
  int N = 10;
  int a[M];
  int b[N];
  for (int i = 0; i < M; i++) {
    a[i] = i;
    printf("%3d", a[i]);
  }
  printf("\n\n");

  random_a(a, M, b, N);
  for (int j = 0; j < N; j++) {
    printf("%3d", b[j]);
  }
  printf("\n\n");

  for (int k = 0; k < M; k++) {
    printf("%3d", a[k]);
  }
  printf("\n");

  return 0;
}