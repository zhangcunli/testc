#include <stdio.h>
#include <stdlib.h>

void insertSort(int a[], int left, int right) {
  for (int i = left + 1; i < right; i++) {
    int m = i;
    for (int j = i - 1; j >= left; j--) {
      if (a[m] < a[j]) {
        int tmp = a[m];
        a[m] = a[j];
        a[j] = tmp;
      }
      m--;
    }
  }
  return;
}

void insertSort2(int a[], int left, int right) {
  for (int i = left + 1; i < right; i++) {
    int j = i - 1;
    for (j = i - 1; j >= left && a[j] > a[i]; j--)
      ;

    if (i - 1 != j) {
      int tmp = a[i];
      for (int m = i - 1; m > j; m--) {
        a[m + 1] = a[m];
      }
      a[j] = tmp;
    }
  }
  return;
}

void printarr(int a[], int left, int right, const char* name) {
  printf("%s:", name);
  for (int i = left; i < right; i++) {
    printf("%3d", a[i]);
  }
  printf("\n");
}
int main() {
  int a[] = {4, 6, 3, 5, 9, 11, 10, 7};
  insertSort(a, 0, sizeof(a) / sizeof(int));
  printarr(a, 0, sizeof(a) / sizeof(int), "arr1:");

  insertSort2(a, 0, sizeof(a) / sizeof(int));
  printarr(a, 0, sizeof(a) / sizeof(int), "arr1:");

  return 0;
}