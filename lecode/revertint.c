#include <stdio.h>
#include <stdlib.h>

int reverse(int x) {
  const int int_max = 0x7fffffff;
  const int int_min = 0x80000000;

  long long sum = 0;
  int flag = 0;
  if (x < 0) {
    flag = 1;
    x = -1 * x;
  }
  while (x != 0) {
    sum = sum * 10 + x % 10;
    x = x / 10;
    // if (sum >= int_max || sum < int_min) {
    if (sum >= INT_MAX || sum < INT_MIN) {
      return 0;
    }
  }

  if (flag == 1) {
    sum = -1 * sum;
  }
  return sum;
}

int main() {
  int a = 123;
  printf("a=%d\n", reverse(a));

  int a1 = 120;
  printf("a1=%d\n", reverse(a1));

  int a2 = -120;
  printf("a2=%d\n", reverse(a2));

  int a3 = 1534236469;
  printf("a3=%d\n", reverse(a3));

  return 0;
}