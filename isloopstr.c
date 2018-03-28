#include <stdio.h>
#include <stdlib.h>

int isloopint(int a) {
  int loopint = 0;
  int tmp = a;

  while (tmp != 0) {
    loopint = loopint * 10 + tmp % 10;
    tmp = tmp / 10;
  }

  // printf("loopint=%d, but a=%d\n", loopint, a);
  if (a == loopint) {
    return 0;
  }
  return -1;
}

int main() {
  int a = 111;
  printf("a=%d, is=%d\n", a, isloopint(a));

  int b = 121;
  printf("b=%d, is=%d\n", b, isloopint(b));

  int c = 223;
  printf("c=%d, is=%d\n", c, isloopint(c));

  return 0;
}