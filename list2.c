#include <stdio.h>
#include <stdlib.h>

typedef int DataType;
typedef struct LinkNode {
  DataType data;
  struct LinkNode* next;
} LinkNode;  //结点结构体

typedef struct LinkList {
  LinkNode* pHead;  //头结点指针
} LinkList;         //链表

LinkList* createList() {
  LinkList* list = (LinkList*)malloc(sizeof(LinkList));
  list->pHead = NULL;

  return list;
}

LinkList* pushbackList(LinkList* list, int data) {
  if (list == NULL) {
    return NULL;
  }

  LinkNode* node = (LinkNode*)malloc(sizeof(LinkNode));
  if (node == NULL) {
    return list;
  }
  node->data = data;
  node->next = NULL;

  LinkNode* head = list->pHead;
  if (head == NULL) {
    list->pHead = node;
    return list;
  }

  while (head->next != NULL) {
    head = head->next;
  }
  head->next = node;

  return list;
}

void printlist(LinkList* list) {
  if (list == NULL) {
    return;
  }

  LinkNode* node = list->pHead;
  printf("List: ");
  while (node != NULL) {
    printf("%3d", node->data);
    node = node->next;
  }
  printf("\n");
}

//递归逆转单链表，注意退出条件
LinkNode* ReverseList(LinkNode* p, LinkList* list) {
  if (p == NULL || p->next == NULL) {
    list->pHead = p;
    return p;
  } else {
    LinkNode* q = ReverseList(p->next, list);
    q->next = p;
    p->next = NULL;
    return p;
  }
}

//非递归逆转
LinkList* ReverseList2(LinkList* list) {
  if (list == NULL || list->pHead == NULL) {
    return list;
  }

  LinkNode* pre = list->pHead;
  LinkNode* cur = pre->next;
  pre->next = NULL;
  LinkNode* tmp = NULL;
  while (cur != NULL) {
    tmp = cur->next;
    cur->next = pre;
    pre = cur;
    cur = tmp;
  }
  list->pHead = pre;

  return list;
}

LinkNode* ReverseList3(LinkNode* head) {
  if (head == NULL) {
    return NULL;
  }

  LinkNode* pre = head;
  LinkNode* cur = head->next;
  LinkNode* tmp = NULL;
  pre->next = NULL;
  while (cur != NULL) {
    tmp = cur->next;
    cur->next = pre;
    pre = cur;
    cur = tmp;
  }

  return pre;
}

int HasCircle(LinkList* list) {
  if (list == NULL || list->pHead == NULL) {
    return -1;
  }

  LinkNode* fast = list->pHead;
  LinkNode* slow = list->pHead;
  while (fast != NULL && fast->next != NULL) {
    fast = fast->next->next;
    slow = slow->next;
    if (fast == slow) {
      return 1;
    }
  }
  return -1;
}

//只移动链表节点中的数据
LinkList* BubbleSort(LinkList* list) {
  if (list == NULL || list->pHead == NULL) {
    return list;
  }

  LinkNode* cur = list->pHead;
  while (cur->next != NULL) {
    LinkNode* pre = cur;
    LinkNode* tail = pre->next;
    while (tail != NULL) {
      if (pre->data > tail->data) {
        int tmp = pre->data;
        pre->data = tail->data;
        tail->data = tmp;
      }
      pre = tail;
      tail = tail->next;
    }
    cur = cur->next;
  }

  return list;
}

int main() {
  LinkList* list = createList();
  list = pushbackList(list, 7);
  list = pushbackList(list, 3);
  list = pushbackList(list, 2);
  list = pushbackList(list, 4);
  list = pushbackList(list, 5);
  list = pushbackList(list, 1);
  int isCircle = HasCircle(list);
  printf("isCircle = %d\n", isCircle);
  printlist(list);

  ReverseList(list->pHead, list);
  printlist(list);

  ReverseList2(list);
  printlist(list);

  LinkNode* head = ReverseList3(list->pHead);
  list->pHead = head;
  printlist(list);

  printf("\nBubblesort:\n");
  BubbleSort(list);
  printlist(list);

  printf("\nBubblesort2:\n");
  //BubbleSort2(list);
  //printlist(list);
  return 0;
}

