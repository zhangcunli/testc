#include <stdio.h>
#include <stdlib.h>

void merge(int a[], int len1, int b[], int len2) {
  int i = len1 - 1;
  int j = len2 - 1;
  int k = len1 + len2 - 1;

  while (i >= 0 && j >= 0) {
    if (a[i] >= b[j]) {
      a[k--] = a[i--];
    } else {
      a[k--] = b[j--];
    }
  }

  while (i >= 0) {
    a[k--] = a[i--];
  }

  while (j >= 0) {
    a[k--] = b[j--];
  }

  return;
}

void merge2(int a[], int len1, int b[], int len2, int c[]) {
  int i = 0;
  int j = 0;
  int index = 0;
  while (i < len1 && j < len2) {
    if (a[i] <= b[j]) {
      c[index++] = a[i++];
    } else {
      c[index++] = b[j++];
    }
  }

  while (i < len1) {
    c[index++] = a[i++];
  }
  while (j < len2) {
    c[index++] = b[j++];
  }
  return;
}

//链表节点
typedef struct NodeL {
  int value;
  struct NodeL* next;
} NodeL;

//合并两个单链表
NodeL* MergeList(NodeL* head1, NodeL* head2) {
  if (head1 == NULL) return head2;
  if (head2 == NULL) return head1;

  NodeL* head = NULL;
  if (head1->value < head2->value) {
    head = head1;
    head1 = head1->next;
  } else {
    head = head2;
    head2 = head2->next;
  }

  NodeL* tmpNode = head;
  while (head1 && head2) {
    if (head1->value < head2->value) {
      head->next = head1;
      head1 = head1->next;
    } else {
      head->next = head2;
      head2 = head2->next;
    }
    head = head->next;
  }

  if (head1) {
    head->next = head1;
  }
  if (head2) {
    head->next = head2;
  }
  return tmpNode;
}

void MergeListTest() {
  NodeL* head1 = (NodeL*)malloc(sizeof(NodeL));
  head1->value = 1;
  head1->next = NULL;

  NodeL* cur = head1;
  for (int i = 3; i <= 10; i += 2) {
    NodeL* tmpNode = (NodeL*)malloc(sizeof(NodeL));
    tmpNode->value = i;
    tmpNode->next = NULL;
    cur->next = tmpNode;
    cur = tmpNode;
  }

  NodeL* head2 = (NodeL*)malloc(sizeof(NodeL));
  head2->value = 2;
  head2->next = NULL;
  cur = head2;
  for (int i = 4; i <= 10; i += 2) {
    NodeL* tmpNode = (NodeL*)malloc(sizeof(NodeL));
    tmpNode->value = i;
    tmpNode->next = NULL;
    cur->next = tmpNode;
    cur = tmpNode;
  }

  NodeL* head = MergeList(head1, head2);
  while (head) {
    printf("%3d", head->value);
    head = head->next;
  }
}

void ReversePrintList(NodeL* head) {
  if (head) {
    ReversePrintList(head->next);
    printf("%3d", head->value);
  }
}

int main() {
  int a[10] = {1, 3, 5, 7, 9, '\0'};
  int b[5] = {2, 4, 6, 8, 10};
  merge(a, 5, b, 5);
  for (int i = 0; i < 10; i++) {
    printf("%3d", a[i]);
  }
  printf("\n");

  int a1[5] = {1, 3, 5, 7, 9};
  int b1[5] = {2, 4, 6, 8, 10};
  int c[10] = {'\0'};
  merge2(a1, 10, b1, 5, c);
  for (int i = 0; i < 10; i++) {
    printf("%3d", c[i]);
  }
  printf("\n");

  //
  MergeListTest();
  printf("\n");

  NodeL* head1 = (NodeL*)malloc(sizeof(NodeL));
  head1->value = 1;
  head1->next = NULL;

  NodeL* cur = head1;
  for (int i = 2; i <= 10; i++) {
    NodeL* tmpNode = (NodeL*)malloc(sizeof(NodeL));
    tmpNode->value = i;
    tmpNode->next = NULL;
    cur->next = tmpNode;
    cur = tmpNode;
  }
  ReversePrintList(head1);

  return 0;
}