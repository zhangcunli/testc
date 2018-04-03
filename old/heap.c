#include <stdio.h>
#include <stdlib.h>

//给定父节点的索引，得到左子节点的索引
#define LeftChild(i) (2 * (i) + 1)
#define RightChild(i) (2 * (i) + 2)

// shiftdown: 下沉 a[i]; n 为a[]数组的大小；
void shiftdown(int a[], int i, int n) {
  int child = LeftChild(i);
  for (int tmp = a[i]; child = LeftChild(i), child < n; i = child) {
    //找左、右子节点中较大的节点
    if (child < n - 1 && a[child + 1] > a[child]) {
      child++;
    }

    if (a[i] < a[child]) {
      tmp = a[i];
      a[i] = a[child];
      a[child] = tmp;
    } else {
      break;
    }
  }
  return;
}

void shiftdown2(int a[], int i, int n) {
  int child = LeftChild(i);
  while (child < n) {
    if (child < n - 1 && a[child] < a[child + 1]) {
      child++;
    }
    if (a[i] < a[child]) {
      int tmp = a[i];
      a[i] = a[child];
      a[child] = tmp;
    } else {
      break;
    }
    i = child;
    child = LeftChild(i);
  }
  return;
}

void makemaxheap(int a[], int max) {
  for (int i = max / 2; i >= 0; i--) {
    // shiftdown2(a, i, max);
    shiftdown(a, i, max);
  }
  return;
}

void HeapSort(int a[], int max) {
  int n = max;
  while (n > 0) {
    int tmp = a[0];
    a[0] = a[n - 1];
    a[n - 1] = tmp;
    n = n - 1;
    shiftdown(a, 0, n);
  }
  return;
}

// a[0, n-1] 为最大堆；将 a[n] 插入，shiftup 后，a[0, n] 变为最大堆；
void shiftup(int a[], int n) { return; }

void makeminheap(int a[], int min, int max) { return; }

void makeminheap2(int a[], int max) { return; }

void printheap(int a[], int len, const char* name) {
  printf("%s:", name);
  for (int i = 0; i < len; i++) {
    printf("%3d", a[i]);
  }
  printf("\n");
}

int main() {
  int maxheap[10] = {9, 5, 6, 13, 4, 11, 3, 10, 8, 1};
  makemaxheap(maxheap, sizeof(maxheap) / sizeof(int));
  printheap(maxheap, sizeof(maxheap) / sizeof(int), "make maxheap");

  HeapSort(maxheap, sizeof(maxheap) / sizeof(int));
  printheap(maxheap, sizeof(maxheap) / sizeof(int), "sort maxheap");

  return 0;
}
