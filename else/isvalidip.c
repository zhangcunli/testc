#include <stdio.h>
#include <stdlib.h>

int isvalid_ip(const char *str) {
  if (str == NULL) {
    return -1;
  }

  int cnt = 0;
  char *p = str;
  while (*p != '\0') {
    if (*p == '.') {
      cnt++;
    }
    p++;
  }
  if (cnt != 3) {
    printf("error, cnt=%d\n", cnt);
    return -1;
  }

  char *p2 = str;
  while (*p2 != '\0') {
    int num = 0;
    int len = 0;
    while (*p2 != '\0' && *p2 != '.') {
      num = num * 10 + *p2 - '0';
      printf("while 1: num=%d, p2=%c\n", num, *p2);
      p2++;
      len++;
    }
    printf("init::: len=%d, num=%d\n", len, num);

    if (len == 1 && (num < 0 || num > 9)) {
      printf("1. len=%d, num=%d\n", len, num);
      return -1;
    } else if ((len == 2) && (num < 10 || num > 99)) {
      printf("2. len=%d, num=%d\n", len, num);
      return -1;
    } else if (len == 3 && (num < 100 || num > 255)) {
      printf("3. len=%d, num=%d\n", len, num);
      return -1;
    } else if (len > 3) {
      printf("4. len=%d, num=%d\n", len, num);

      return -1;
    }

    printf("\n\n");
    if (*p2 != '\0') {
      p2++;
    }
  }

  return 0;
}

int main() {
  char *str1 = "10.12.11.122";
  printf("str1:%s, ret=%d\n", str1, isvalid_ip(str1));

  /*
    char *str2 = "0.12.11.122";
    printf("str2:%s, ret=%d\n", str2, isvalid_ip(str2));

    char *str3 = "12.11.122";
    printf("str3:%s, ret=%d\n", str3, isvalid_ip(str3));

    char *str4 = "a.12.11.122";
    printf("str4:%s, ret=%d\n", str4, isvalid_ip(str4));
  */

  return 0;
}