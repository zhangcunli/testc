#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2,
                              int nums2Size) {
  int first = 0;
  int second = 0;
  if ((nums1Size + nums2Size) % 2 == 0) {
    first = (nums1Size + nums2Size - 1) / 2;
    second = (nums1Size + nums2Size + 1) / 2;
  } else {
    first = second = (nums1Size + nums2Size) / 2;
  }
  printf("first = %d, second = %d\n", first, second);

  int* M = (int*)malloc(nums1Size + nums2Size);
  memset(M, 0, nums1Size + nums2Size);

  int sum = 0;
  int m = 0;
  int i = 0;
  int j = 0;
  for (; m < nums1Size + nums2Size - 1 && i < nums1Size && j < nums2Size;) {
    if (nums1[i] <= nums2[j]) {
      M[m++] = nums1[i];
      i++;
    } else {
      M[m++] = nums2[j];
      j++;
    }
  }

  printf("m = %d, i = %d, j = %d\n", m, i, j);
  while (i < nums1Size) {
    M[m++] = nums1[i++];
  }

  while (j < nums2Size) {
    M[m++] = nums2[j++];
  }

  for (int n = 0; n < nums2Size + nums1Size; n++) {
    printf("%3d", M[n]);
  }
  printf("\n");

  sum = M[first] + M[second];
  return (double)(sum / 2.0);
}
*/

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2,
                              int nums2Size) {
  int first = 0;
  int second = 0;
  if ((nums1Size + nums2Size) % 2 == 0) {
    first = (nums1Size + nums2Size - 1) / 2;
    second = (nums1Size + nums2Size + 1) / 2;
  } else {
    first = second = (nums1Size + nums2Size) / 2;
  }

  int sum = 0;
  int m = 0;
  int i = 0;
  int j = 0;
  for (; i < nums1Size && j < nums2Size;) {
    if (nums1[i] <= nums2[j]) {
      if (first == m || second == m) {
        sum += nums1[i];
      }
      m++;
      i++;
    } else {
      if (first == m || second == m) {
        sum += nums2[j];
      }
      m++;
      j++;
    }
  }

  while (i < nums1Size) {
    if (first == m || second == m) {
      sum += nums1[i];
    }
    m++;
    i++;
  }

  while (j < nums2Size) {
    if (first == m || second == m) {
      sum += nums2[j];
    }
    m++;
    j++;
  }

  if (first == second) {
    sum *= 2;
  }
  return (double)(sum / 2.0);
}

int main() {
  int a[2] = {1, 2};
  int b[2] = {3, 4};
  printf("media of two array:%f\n\n", findMedianSortedArrays(a, 2, b, 2));

  int a1[2] = {1, 3};
  int b1[1] = {2};
  printf("media of two array:%f\n\n", findMedianSortedArrays(a1, 2, b1, 1));

  int a2[2] = {1, 2};
  int b2[2] = {1, 2};
  printf("media of two array:%f\n\n", findMedianSortedArrays(a2, 2, b2, 2));

  int a3[4] = {2, 2, 2, 2};
  int b3[3] = {2, 2, 2};
  printf("media of two array:%f\n\n", findMedianSortedArrays(a3, 4, b3, 3));

  return 0;
}