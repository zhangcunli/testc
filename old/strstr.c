#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* strstr_s(char* s1, const char* s2) {
  int len = strlen(s2);
  if (len <= 0) {
    return NULL;
  }

  while (s1 != NULL) {
    if (strncmp(s1, s2, len) == 0) {
      printf("%s, %s\n", s1, s2);
      return s1;
    }
    s1++;
  }
  return NULL;
}

char* strstr2(const char* s1, const char* s2) {
  const char* p1 = s2;
  int len = strlen(s1);
  for (; p1 = strchr(p1, *s1); p1++) {
    if (strncmp(p1, s1, len) == 0) {
      printf("a: %s\n", p1);
      return (char*)p1;
    }
  }

  return NULL;
}

char* strcpy1(char* strDest, const char* strSrc) {
  if (strDest == NULL || strSrc == NULL) {
    return NULL;
  }

  char* p = strDest;
  while ((*strDest++ = *strSrc++) != '\0') {
  }
  return p;
}

int main() {
  char* str1 = "abc";
  char* str2 = "dabcddd";

  char* str_tmp = strstr_s(str2, str1);
  if (str_tmp != NULL) {
    printf("1. %s\n", str_tmp);
  }

  char* str_tmp1 = strstr(str2, str1);
  if (str_tmp1 != NULL) {
    printf("2. %s\n", str_tmp1);
  }

  char* str_tmp3 = strstr2(str1, str2);
  if (str_tmp3 != NULL) {
    printf("3. %s\n", str_tmp3);
  }

  char strDest[10] = "\0";
  char* dest = strcpy1(strDest, str2);
  printf("4. %s, %s\n", dest, strDest);
  return 0;
}