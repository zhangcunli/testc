#include <stdio.h>
#include <stdlib.h>

void reserve(char* str) {
  char * p1 = str;
  char * p2 = str;

  while (*++p2)
    ;  //一般要求不能使用strlen
  p2 -= 1;
  while (p1 < p2) {
    char c = * p1;
    *p1++ = * p2;
    *p2-- = c;
  }
   
}

int main() {
  char str123[] = "ABCD1234efgh";
  reserve(str123);
  printf("%s\n", str123);

  return 0;
}