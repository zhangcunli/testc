#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse1(char* str) {
  char* p1 = str;
  char* p2 = str;

  while (*++p2)
    ;

  p2 -= 1;

  while (p1 < p2) {
    char c = *p1;
    *p1++ = * p2;
    *p2-- = c;
  }
}

void reverse2(char* str, int len) {
  if (str == NULL) {
    return;
  }

  for (int i = 0; i < len / 2; i++) {
    int c = str[i];
    str[i] = str[len - 1 - i];
    str[len - i - 1] = c;
  }
}

void reverse_str(char* str) {
  if (str == NULL) {
    return;
  }

  int len = strlen(str);
  reverse2(str, len);

  char* tmp = str;

  int short_len = 0;
  char* p = str;

  while (*str != '\0') {
    if (*str++ != ' ') {
      short_len++;
    } else {
      reverse2(p, short_len);
      p = str;
      short_len = 0;
    }

    // remember!!!
    if (*str == '\0') {
      reverse2(p, short_len);
    }
  }
}

void reverse_str1(char* str) {
  if (str == NULL) {
    return;
  }

  int len = strlen(str);
  reverse2(str, len);

  char* tmp = str;

  int short_len = 0;
  char* p = str;
  for (int i = 0; i < len; i++) {
    /*
    if (i == len - 1) {
      reverse2(p, short_len + 1);
      break;
    }*/

    if (str[i] != ' ' && i != len - 1) {
      short_len++;
    } else {
      if (i == len - 1) {
        short_len = short_len + 1;
      }
      reverse2(p, short_len);
      p = str + i + 1;
      short_len = 0;
    }
  }
}

int isDigit(char c) {
  if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
    return 1;
  }
  return -1;
}

void reverse_str_trim(char* str, int len) {
  if (str == NULL) {
    return;
  }

  char* dest = (char*)malloc(sizeof(char) * len);
  memset(dest, 0, len);

  //先逆转
  reverse2(str, len);

  //再今次找单词，找到单词后，逆序拷贝
  char* p1 = str;
  char* p2 = NULL;
  int i = 0;
  int j = 0;
  while (i < len) {
    // 1. 第一个字符
    while (isDigit(str[i]) == -1 && i < len) {
      p1++;
      i++;
    }
    p2 = p1;

    //第一个单词
    while (isDigit(str[i]) == 1 && i < len) {
      p1++;
      i++;
    }

    int flag = 0;
    char* p3 = p1 - 1;
    while (p3 >= p2) {
      dest[j++] = *p3--;
      flag = 1;
    }
    if (flag == 1 && j < len - 1) {
      dest[j++] = ' ';
    }
  }

  int end = j - 1;
  while (*(dest + end) == ' ') {
    *(dest + end) = '\0';
    end--;
  }

  while (*dest != '\0') {
    *str++ = *dest++;
  }
  *str++ = '\0';
}

int main() {
  /*
  char str123[] = "ABCD1234efgh";
  reverse1(str123);
  printf("%s\n", str123);

  reverse2(str123, strlen(str123));
  printf("%s\n", str123);
  */

  char strs[] = "I am a Chinese Pepole!";
  reverse_str(strs);
  printf("strs:%s:\n", strs);

  char strs0[] = "I am a Chinese Pepole!";
  reverse_str1(strs0);
  printf("strs0:%s:\n\n", strs0);

  char strs1[] = "We are a Chinese Pepole!";
  reverse_str(strs1);
  printf("strs1:%s:\n", strs1);

  char strs2[] = "We are a Chinese Pepole!";
  reverse_str1(strs2);
  printf("strs2:%s:\n\n", strs2);

  char strs3[] = "##We are!@#a Chinese^&&Pepole!***";
  reverse_str_trim(strs3, strlen(strs3));
  printf("strs3:%s:\n\n", strs3);

  return 0;
  }