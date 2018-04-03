
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

// 写一个函数,将一个具有n个元素的字符串向左旋转i个位置。例如，将 ABC123DEF456 向左旋转 3 个位置之后得到 123DEF456ABC。
void tempArrReverse(char arr[], int len, int m) {
  char *temp = new char[m];
  // 将数组前m个元素保存到临时数组 
  for (int i = 0; i < m; i++) {
    temp[i] = arr[i];
  }

  // 将数组后面（len-m）个元素前移 
  for (int i = m; i < len; i++) {
    arr[i - m] = arr[i];
  }

  // 将临时数组所有元素复制到原数组 
  for (int i = 0; i < m; i++) {
    arr[len - m + i] = temp[i];
  }
}

void reserve_new(char * str) {
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

// 原语操作-反转数组 
void reverse(char  arr[], int start, int end) {
  int mid = (start + end) / 2;
  for (int s = start, i = 1; i < mid; s++, i++) {
    char temp = arr[s];
    arr[s] = arr[end - i];
    arr[end - i] = temp;
  }
}

void useReverse(char  arr[], int len, int m) {
  reverse(arr, 0, m);
  reverse(arr, m, len);
  reverse(arr, 0, len);
}

char *revstr(char *str, size_t len) {
  //或者在这里判断 str NULL 则返回，不要在下面判断
  char *start = str;
  char *end = str + len - 1;
  char ch;

  if (str != NULL) {
    while (start < end) {
      ch = *start;
      *start++ = *end;
      *end-- = ch;
    }
  }
  return str;
}

void reserve(char *str) {
  if (str == NULL) {
    return;
  }

  char *p = str + strlen(str) - 1;
  char temp;
  while (str < p) {
    temp = *p;
    *p-- = *str;
    *str++ = temp;
  }
}

typedef struct Node {
  struct Node *lchild;
  struct Node *rchild;
  int data;
} Node;

void depthFirstSearch(Node *root) {
  stack<Node *> nodeStack;
  //使用C++的STL标准模板库
  nodeStack.push(root);
  Node *node;
  while (!nodeStack.empty()) {
    node = nodeStack.top();
    printf("%3d", node->data);

    //遍历根结点
    nodeStack.pop();
    if (node->rchild) {
      nodeStack.push(node->rchild);
      //先将右子树压栈 
    }

    if (node->lchild) {
      nodeStack.push(node->lchild);
      //再将左子树压栈
    }
  }
}

//广度优先遍历
void breadthFirstSearch(Node *root) {
  queue<Node *> nodeQueue;
  //使用C++的STL标准模板库
  nodeQueue.push(root);
  Node *node;
  while (!nodeQueue.empty()) {
    node = nodeQueue.front();
    nodeQueue.pop();
    printf("%3d", node->data);
    if (node->lchild) {
      nodeQueue.push(node->lchild);
      //先将左子树入队
    }
    if (node->rchild) {
      nodeQueue.push(node->rchild);
      //再将右子树入
    }
  }
}

//写出在母串中查找子串出现次数的代码.
int count1(char * str, char * s)   {
     char * s1;
     char * s2;
     int count = 0;
     while (*str != '\0') {
    s1 = str;
    s2 = s;
    while (*s2 == * s1 && (*s2 != '\0') && (*s1 != '\0')) {
      s2++;
      s1++;
        
    }
    if (*s2 == '\0') count++;
    str++;
  }
  return count;
    
}

//查找第一个匹配子串位置,如果返回的是s1长度len1表示没有找到
size_t find(char * s1, char * s2) {
  size_t i = 0;
  size_t len1 = strlen(s1);
  size_t len2 = strlen(s2);

  if (len1 - len2 < 0) return len1;
  for (; i < len1 - len2; i++) {
    size_t m = i;
    for (size_t j = 0; j < len2; j++) {
      if (s1[m] != s2[j]) break;
      m++;
          
    }

    if (j == len2) break;
  }
  return i < len1 - len2 ? i : len1;
   
}

int IsReverseStr(char *str)   {
  int i, j;
  int found = 1;
  if (str == NULL) return - 1;

  char * p = str - 1;
  while (*++p != '\0')
    ;
  --p;

  while (*str == *p && str < p) {
      str++;
      p--;
    }

  if (str < p) found = 0;
  return found;
    
}

//判断一个字符串是否为合法 ip 地址
int check_ip(char *ip) {
  char * p = ip;
  int count = 0;
  while (*p != '\0') {
    if ( * p == '.') count++;
    p++;
  }

  if ( count != 3 )
    return false;

  p = ip;
  for (int i = 0; i < 4; ++i) {
    int len = 0;
    int tem = 0;
    while (*p != NULL) {
      if (*p == '.')
        break;
      tem = tem * 10 + *p - '0';
      p++;
      len++;  
    }

    if (len == 1) {
      if (tem < 0 || tem > 9)
        return false;
    }
    else if (len == 2) {
      if (tem < 10 || tem > 99)
        return false;
    }
    else if (len == 3) {
      if (tem < 100 || tem > 255)
        return false;  
    }
    else
      return false;
    
    if (*p != '\0')
      p++;
  }

  return true; 
}

int main()
{
    return 0;
}