#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
  int data;
  struct ListNode* next;
} ListNode;

typedef struct List {
  int length;
  struct ListNode* head;
  struct ListNode* end;
} List;

List* createList() {
  List* list = (List*)malloc(sizeof(List));
  list->length = 0;
  list->head = NULL;
  list->end = NULL;

  return list;
}

List* insertList(List* list, int data) {
  if (list == NULL) {
    return NULL;
  }

  ListNode* node = (ListNode*)malloc(sizeof(ListNode));
  if (node == NULL) {
    return NULL;
  }
  node->data = data;
  node->next = NULL;

  if (list->head == NULL) {
    list->head = node;
    list->end = node;
  } else {
    ListNode* tmp = list->end;
    tmp->next = node;
    list->end = node;
  }

  return list;
}

void printlist(List* list) {
  if (list == NULL) {
    return;
  }

  ListNode* node = list->head;
  printf("List: ");
  while (node != NULL) {
    printf("%3d", node->data);
    node = node->next;
  }
  printf("\n");
}

List* pushFront(List* list, int data) {
  if (list == NULL) {
    return NULL;
  }

  ListNode* node = (ListNode*)malloc(sizeof(ListNode));
  if (node == NULL) {
    return NULL;
  }
  node->data = data;
  node->next = list->head;
  list->head = node;

  return list;
}

ListNode* SearchLastKNode(List* list, int k) {
  if (list == NULL || list->head == NULL) {
    return list;
  }

  ListNode* fast = list->head;
  while (k > 0) {
    fast = fast->next;
    k--;
  }

  ListNode* slow = list->head;
  while (fast != NULL) {
    fast = fast->next;
    slow = slow->next;
  }

  return slow;
}

ListNode* SearchMidNode(List* list) {
  if (list == NULL || list->head == NULL) {
    return list;
  }

  ListNode* fast = list->head;
  ListNode* slow = list->head;
  if ((fast->next == NULL) || (fast->next->next == NULL)) {
    return slow;
  }

  while (fast != NULL && fast->next != NULL) {
    printf("fast:%d, slow=%d\n", fast->data, slow->data);
    fast = fast->next->next;
    slow = slow->next;
  }

  return slow;
}

List* ReverseList(List* list) {
  if (list == NULL) {
    return NULL;
  }

  ListNode* pre = list->head;
  ListNode* cur = pre->next;
  ListNode* tmp = NULL;
  pre->next = NULL;
  while (cur != NULL) {
    tmp = cur->next;
    cur->next = pre;
    pre = cur;
    cur = tmp;
  }

  tmp = list->head;
  list->head = list->end;
  list->end = tmp;
  return list;
}

int HasCircle(List* list) {
  if (list == NULL || list->head == NULL) {
    return -1;
  }

  ListNode* fast = list->head;
  ListNode* slow = list->head;
  while (fast != NULL && fast->next != NULL) {
    fast = fast->next->next;
    slow = slow->next;
    if (fast == slow) {
      return 1;
    }
  }
  return -1;
}

List* BubbleSort(List* list) {
  if (list == NULL || list->head == NULL) {
    return list;
  }

  ListNode* head = list->head;
  ListNode* end = list->end;

  ListNode* nodei = list->head;
  ListNode* nodej = list->head;
  while (pre->next->next != NULL) {
    ListNode* cur = pre->next;
    while (cur != NULL) {
      if (cur->data < pre->data) {
        int tmp = cur->data;
        cur->data = pre->data;
        pre->data = cur->data;
      }
      ListNode* tmp = cur->next;
      pre = cur;
      cur = tmp;
    }
  }

  return list;
}

int main() {
  List* list = createList();
  list = insertList(list, 4);
  list = insertList(list, 3);
  list = insertList(list, 1);
  list = insertList(list, 2);
  list = insertList(list, 5);
  printlist(list);

  list = pushFront(list, 7);
  printlist(list);

  ListNode* tmp1 = SearchLastKNode(list, 3);
  printf("last k[%d]=%d\n", 3, tmp1->data);
  printf("is circle=%d\n", HasCircle(list));

  ListNode* tmp2 = SearchMidNode(list);
  printf("mid k=%d\n\n", tmp2->data);

  List* list2 = createList();
  list2 = insertList(list2, 7);
  list2 = insertList(list2, 3);
  list2 = insertList(list2, 2);
  list2 = insertList(list2, 5);
  list2 = insertList(list2, 4);
  printlist(list2);
  list2 = ReverseList(list2);
  printlist(list2);
  printf("is circle=%d\n", HasCircle(list));
  list2 = BubbleSort(list2);
  printlist(list2);

  return 0;
}