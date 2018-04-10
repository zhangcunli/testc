#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define INT_MAX 2147483647
#define INT_MIN (-INT_MAX - 1)

//注：负数不是回文数
bool isPalindrome(int x) {
  if (x < 0) {
    return false;
  }

  int result = 0;
  int tmp = x;
  while (tmp != 0) {
    result = result * 10 + tmp % 10;
    tmp = tmp / 10;
  }

  if (result == x) {
    return true;
  }
  return false;
}

int main() {
  int s1 = 12321;
  printf("true: s1=%d\n", isPalindrome(s1));

  int s2 = -12321;
  printf("true: s2=%d\n", isPalindrome(s2));

  int s3 = -2147447412;
  printf("true: s3=%d\n", isPalindrome(s3));

  // char* str4 = "2147483648";
  // printf("2147483647: str6=%d\n", myAtoi(str4));

  return 0;
}
