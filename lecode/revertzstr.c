#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* convert(char* s, int numRows) {
  if (s == NULL) {
    return NULL;
  }

  int length = strlen(s);
  if (length == 0 || numRows == 0 || numRows == 1)  //特殊情况特殊处理
    return s;

  char* result = (char*)malloc(sizeof(char) * (length + 1));

  int k = 0;
  int rowlen = 2 * numRows - 2;
  for (int i = 0; i < numRows; i++) {
    for (int j = i; j < length; j += rowlen) {
      result[k++] = s[j];
      ///。。。。
      if (i != 0 && i != numRows - 1 && j - 2 * i + rowlen < length) {
        result[k++] = s[j - 2 * i + rowlen];
      }
    }
  }
  result[k] = '\0';
  return result;
}

int main() {
  char* str1 = "PAYPALISHIRING";
  printf("str1=[%s]\n", convert(str1, 3));

  char* str2 =
      "Apalindromeisaword,phrase,number,"
      "orothersequenceofunitsthatcanbereadthesamewayineitherdirection,"
      "withgeneralallowancesforadjustmentstopunctuationandworddividers.";
  printf("str2=[%s]\n", convert(str2, 2));

  return 0;
}