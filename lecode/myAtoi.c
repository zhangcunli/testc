#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INT_MAX 2147483647
#define INT_MIN (-INT_MAX - 1)

int isDigit(char c) {
  if ((c - '0') < 0 || (c - '0') > 9) {
    return -1;
  }
  return 0;
}

int Sign(char c) {
  if (c == '-') {
    return -1;
  } else if (c == '+') {
    return 1;
  }

  return 0;
}

int myAtoi(char* str) {
  long long result = 0;

  if (str == NULL) {
    return 0;
  }

  char* p = str;
  while (*p != '\0' && *p == ' ') {
    p++;
  }

  if (*p == '\0' || (Sign(*p) == 0 && isDigit(*p) != 0)) {
    return 0;
  }

  int flag = 1;
  int sign = Sign(*p);
  if (sign != 0) {
    flag = sign;
    p++;
  }

  while (*p != '\0' && isDigit(*p) == 0) {
    result = result * 10 + *p - '0';
    if (result > INT_MAX) {
      break;
    }
    p++;
  }
  result = result * flag;

  if (result > INT_MAX) {
    return INT_MAX;
  } else if (result < INT_MIN) {
    return INT_MIN;
  }

  return result;
}

int main() {
  char* str1 = "123";
  printf("123: str1=%d\n", myAtoi(str1));

  char* str2 = "-123";
  printf("-123: str2=%d\n", myAtoi(str2));

  char* str3 = "  -1234";
  printf("-1234: str3=%d\n", myAtoi(str3));

  char* str4 = "  -12345AB";
  printf("-12345: str4=%d\n", myAtoi(str4));

  char* str5 = "  $12345";
  printf("error: str4=%d\n", myAtoi(str5));

  char* str6 = "2147483648";
  printf("2147483647: str6=%d\n", myAtoi(str6));

  char* str7 = "9223372036854775809";
  printf("2147483647: str7=%d\n", myAtoi(str7));

  return 0;
}

/*
atoi的要求：

这个函数需要丢弃之前的空白字符，直到找到第一个非空白字符。之后从这个字符开始，选取一个可选的正号或负号后面跟随尽可能多的数字，并将其解释为数字的值。

字符串可以在形成整数的字符后包括多余的字符，将这些字符忽略，这些字符对于函数的行为没有影响。

如果字符串中的第一个非空白的字符不是有效的整数，或者没有这样的序列存在，字符串为空或者只包含空白字符则不进行转换。

如果不能执行有效的转换，则返回 0。如果正确的值超过的可表示的范围，则返回
INT_MAX（2147483647）或 INT_MIN（-2147483648）。
*/