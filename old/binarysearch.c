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
    while (last > first && array[last] >= key) {
      last--;
    }
    array[first] = array[last];

    while (first < last && array[first] <= key) {
      first++;
    }
    array[last] = array[first];
  }
  array[first] = key;

  quitsort(array, left, first - 1);
  quitsort(array, first + 1, right);
}

int binarysearch(int array[], int left, int right, int key) {
  if (left > right) {
    return -1;
  }

  int mid = (right + left) / 2;
  if (array[mid] == key) {
    return mid;
  } else if (array[mid] < key) {
    return binarysearch(array, mid + 1, right, key);
  } else if (array[mid] > key) {
    return binarysearch(array, left, mid - 1, key);
  }
  return -1;
}

int binarysearch2(int array[], int left, int right, int key) {
  while (left <= right) {
    int mid = (left + right) / 2;
    if (array[mid] > key) {
      right = mid - 1;
    } else if (array[mid] < key) {
      left = mid + 1;
    } else {
      return mid;
    }
  }
  return -1;
}

void printv(int array[], int left, int right, char *name) {
  int i = 0;
  for (i = 0; i <= right; i++) {
    printf("%s[%d]=%d\n", name, i, array[i]);
  }
  printf("\n");
}

void printv1(int array[], int left, int right, char *name) {
  int i = 0;
  printf("%s:", name);
  for (i = 0; i <= right; i++) {
    printf("%3d", array[i]);
  }
  printf("\n");
}

int main() {
  int r = 0;
  int key = 5;

  int v1[] = {};
  quitsort(v1, 0, (int)(sizeof(v1) / sizeof(int)) - 1);
  printv1(v1, 0, (int)(sizeof(v1) / sizeof(int)) - 1, "v1");
  r = binarysearch(v1, 0, (int)(sizeof(v1) / sizeof(int)) - 1, key);
  printf("v1: k=%d, r=%d\n\n", key, r);
  r = binarysearch2(v1, 0, (int)(sizeof(v1) / sizeof(int)) - 1, key);
  printf("v1: k=%d, r=%d\n\n", key, r);

  int v2[] = {5};
  quitsort(v2, 0, sizeof(v2) / sizeof(int) - 1);
  printv1(v2, 0, (int)(sizeof(v2) / sizeof(int)) - 1, "v2");
  r = binarysearch(v2, 0, (int)(sizeof(v2) / sizeof(int)) - 1, key);
  printf("v2: k=%d, r=%d\n\n", key, r);
  r = binarysearch2(v2, 0, (int)(sizeof(v2) / sizeof(int)) - 1, key);
  printf("v2: k=%d, r=%d\n\n", key, r);

  int v21[] = {3};
  quitsort(v21, 0, sizeof(v21) / sizeof(int) - 1);
  printv1(v21, 0, (int)(sizeof(v21) / sizeof(int)) - 1, "v21");
  r = binarysearch(v21, 0, (int)(sizeof(v21) / sizeof(int)) - 1, key);
  printf("v21: k=%d, r=%d\n\n", key, r);
  r = binarysearch2(v21, 0, (int)(sizeof(v21) / sizeof(int)) - 1, key);
  printf("v21: k=%d, r=%d\n\n", key, r);

  int v3[] = {2, 1};
  quitsort(v3, 0, sizeof(v3) / sizeof(int) - 1);
  printv1(v3, 0, (int)(sizeof(v3) / sizeof(int)) - 1, "v3");
  r = binarysearch(v3, 0, (int)(sizeof(v3) / sizeof(int)) - 1, key);
  printf("v3: k=%d, r=%d\n\n", key, r);
  r = binarysearch2(v3, 0, (int)(sizeof(v3) / sizeof(int)) - 1, key);
  printf("v3: k=%d, r=%d\n\n", key, r);

  int v31[] = {5, 2};
  quitsort(v31, 0, sizeof(v31) / sizeof(int) - 1);
  printv1(v31, 0, (int)(sizeof(v31) / sizeof(int)) - 1, "v31");
  r = binarysearch(v31, 0, (int)(sizeof(v31) / sizeof(int)) - 1, key);
  printf("v31: k=%d, r=%d\n\n", key, r);
  r = binarysearch2(v31, 0, (int)(sizeof(v31) / sizeof(int)) - 1, key);
  printf("v31: k=%d, r=%d\n\n", key, r);

  int v4[] = {3, 1, 2};
  quitsort(v4, 0, sizeof(v4) / sizeof(int) - 1);
  printv1(v4, 0, (int)(sizeof(v4) / sizeof(int)) - 1, "v4");
  r = binarysearch(v4, 0, (int)(sizeof(v4) / sizeof(int)) - 1, key);
  printf("v4: k=%d, r=%d\n\n", key, r);
  r = binarysearch2(v4, 0, (int)(sizeof(v4) / sizeof(int)) - 1, key);
  printf("v4: k=%d, r=%d\n\n", key, r);

  int v41[] = {3, 1, 5};
  quitsort(v41, 0, sizeof(v41) / sizeof(int) - 1);
  printv1(v41, 0, (int)(sizeof(v41) / sizeof(int)) - 1, "v41");
  r = binarysearch(v41, 0, (int)(sizeof(v41) / sizeof(int)) - 1, key);
  printf("v41: k=%d, r=%d\n\n", key, r);
  r = binarysearch2(v41, 0, (int)(sizeof(v41) / sizeof(int)) - 1, key);
  printf("v41: k=%d, r=%d\n\n", key, r);

  int v5[] = {5, 4, 8, 6, 7, 9, 1, 10, 23, 2};
  quitsort(v5, 0, sizeof(v5) / sizeof(int) - 1);
  printv1(v5, 0, (int)(sizeof(v5) / sizeof(int)) - 1, "v5");
  r = binarysearch(v5, 0, (int)(sizeof(v5) / sizeof(int)) - 1, key);
  printf("v5: k=%d, r=%d\n\n", key, r);
  r = binarysearch2(v5, 0, (int)(sizeof(v5) / sizeof(int)) - 1, key);
  printf("v5: k=%d, r=%d\n\n", key, r);

  int v6[] = {5, 4, 8, 6, 7, 9, 1, 10, 23, 2, 13};
  quitsort(v6, 0, sizeof(v6) / sizeof(int) - 1);
  printv1(v6, 0, (int)(sizeof(v6) / sizeof(int)) - 1, "v6");
  r = binarysearch(v6, 0, (int)(sizeof(v6) / sizeof(int)) - 1, key);
  printf("v6: k=%d, r=%d\n\n", key, r);
  r = binarysearch2(v6, 0, (int)(sizeof(v6) / sizeof(int)) - 1, key);
  printf("v6: k=%d, r=%d\n\n", key, r);

  return 0;
}