#include <stdio.h>

struct str {
  int len;
  char s[0];
};

struct foo {
  struct str* pstr;
};

struct test {
  int i;
  char* p;
};

struct test2 {
  int i;
  short c;
  char* p;
};

int main(int argc, char** argv) {
  struct foo foo_s = {0};
  if (foo_s.pstr->s) {
    printf("foo->pstr:%x\n", foo_s.pstr->s);
  }

  struct test t;
  struct test* t1 = NULL;
  struct test2* t2 = NULL;
  printf("t:%d, sizeof(int)=%d, sizeof(ptr)=%d\n", t.i, sizeof(int),
         sizeof(char*));

  return 0;
}

// gdb array0.c -o array0 -g
// gdb array0
// b array0.c:33
// p t;  p &t;  p &(t.i); p &(t.p)
// p t1;  p t1->i; p t1->p;
// p t2;  p t2->c; p t2->p;
