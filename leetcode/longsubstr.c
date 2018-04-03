#include <stdio.h>
#include <stdlib.h>

int lengthOfLongestSubstring(char* s) {
  int length = 0;
  const char* p = s;
  while (*p++ != '\0') {
    length++;
  }

  int max = 0;
  for (int i = 0; i < length; i++) {
    int k = 0;
    for (int j = i; j < length; j++) {
      int m = 0;
      int flag = 0;
      while (m < k) {
        if (s[i + m++] == s[j]) {
          flag = 1;
          break;
        }
      }

      if (flag == 1) {
        break;
      }

      if (++k > max) {
        max = k;
      }
    }
  }
  return max;
}

int main() {
  char* s = "pwwkew";
  printf("length=%d\n", lengthOfLongestSubstring(s));

  return 0;
}