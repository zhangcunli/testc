#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isloopstr(char* s, int len) {
  for (int i = 0; i < len / 2; i++) {
    if (s[i] != s[len - i - 1]) {
      return -1;
    }
  }

  return 0;
}
char* longestPalindrome(char* s) {
  if (s == NULL) {
    return s;
  }

  int length = strlen(s);
  if (isloopstr(s, length) == 0) {
    return s;
  }

  char* out = (char*)malloc(sizeof(char) * (length + 1));
  memset(out, 0, length + 1);

  char* p = NULL;
  int max = 0;
  for (int i = 0; i < length; i++) {
    p = s + i;
    for (int j = i; j < length; j++) {
      if (isloopstr(p, j - i + 1) == 0) {
        if (j - i + 1 > max) {
          max = j - i + 1;
          /*
          int k = 0;
          char* p1 = p;
          while (k < max) {
            out[k++] = *p1++;
          }
          */  //或者直接拷贝
          memcpy(out, p, max);
          out[max] = '\0';
        }
      }
    }
  }
  return out;
}

int main() {
  char* s1 = "a";
  printf("s1=%s\n", longestPalindrome(s1));

  char* s2 = "abad";
  printf("s2=%s\n", longestPalindrome(s2));

  char* s3 = "bb";
  printf("s3=%s\n", longestPalindrome(s3));

  char* s4 = "axdfdddfd";
  printf("s4=%s\n", longestPalindrome(s4));

  return 0;
}