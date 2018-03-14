#include <stdio.h>
#include <stdlib.h>

void quitsort(int array[], int left, int right) {
  if (left >= right) {
    return;
  }

  int first = left;
  int last = right;
  int key = array[first];
  while (first < last) {
    while (first < last && array[last] >= key) {
      last--;
    }
    // int temp = array[first];
    // array[first] = array[last];
    // array[last] = temp;
    array[first] = array[last];

    while (first < last && array[first] <= key) {
      first++;
    }
    // temp = array[first];
    // array[first] = array[last];
    // array[last] = temp;
    array[last] = array[first];
  }
  array[first] = key;

  quitsort(array, left, first - 1);
  quitsort(array, first + 1, right);
}

void BubbleSort(int array[], int left, int right) {
  if (left >= right) {
    return;
  }

  for (int i = left; i <= right; i++) {
    for (int j = left; j <= right - 1 - i; j++) {
      if (array[j] > array[j + 1]) {
        int tmp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = tmp;
      }
    }
  }
}

void printv(int array[], int left, int right, char *name) {
  int i = 0;
  for (i = 0; i <= right; i++) {
    printf("%s[%d]=%d\n", name, i, array[i]);
  }
  printf("\n");
}
int main() {
  int v1[] = {};
  quitsort(v1, 0, (int)(sizeof(v1) / sizeof(int)) - 1);
  printv(v1, 0, (int)(sizeof(v1) / sizeof(int)) - 1, "v1");

  int v2[] = {5};
  quitsort(v2, 0, sizeof(v2) / sizeof(int) - 1);
  printv(v2, 0, sizeof(v2) / sizeof(int) - 1, "v2");

  int v3[] = {2, 1};
  quitsort(v3, 0, sizeof(v3) / sizeof(int) - 1);
  printv(v3, 0, sizeof(v3) / sizeof(int) - 1, "v3");

  int v31[] = {1, 2};
  quitsort(v31, 0, sizeof(v31) / sizeof(int) - 1);
  printv(v31, 0, sizeof(v31) / sizeof(int) - 1, "v31");

  int v4[] = {1, 2, 3};
  quitsort(v4, 0, sizeof(v4) / sizeof(int) - 1);
  printv(v4, 0, sizeof(v4) / sizeof(int) - 1, "v4");

  int v41[] = {3, 1, 2};
  quitsort(v41, 0, sizeof(v41) / sizeof(int) - 1);
  printv(v41, 0, sizeof(v41) / sizeof(int) - 1, "v41");

  int v5[] = {5, 4, 8, 6, 7, 9, 1, 10, 23, 2};
  quitsort(v5, 0, sizeof(v5) / sizeof(int) - 1);
  printv(v5, 0, sizeof(v5) / sizeof(int) - 1, "v5");

  int v6[] = {5, 4, 8, 6, 7, 9, 1, 10, 23, 2, 13};
  quitsort(v6, 0, sizeof(v6) / sizeof(int) - 1);
  printv(v6, 0, sizeof(v6) / sizeof(int) - 1, "v6");

  /////
  int v7[] = {5, 4, 8, 6, 7, 9, 1, 10, 23, 2, 13};
  BubbleSort(v7, 0, sizeof(v7) / sizeof(int) - 1);
  printv(v7, 0, sizeof(v7) / sizeof(int) - 1, "v7");
  return 0;
}