#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_L 16  //最大层数

// new_node生成一个Node结构体,同时生成包含n个Node *元素的数组
#define new_node(n) ((Node *)malloc(sizeof(Node) + n * sizeof(Node *)))

//定义key和value的类型
typedef int keyType;
typedef int valueType;

//每个节点的数据结构
typedef struct node {
  keyType key;      // key值
  valueType value;  // value值
  struct node *next[1];  // 后继指针数组，柔性数组 可实现结构体的变长
} Node;

//跳表结构
typedef struct skip_list {
  int level;   // 最大层数
  Node *head;  //指向头结点
} skip_list;

/*
  创建节点,成功返回Node*类型指针,否则返回NULL
  level 节点层数
  key   节点关键字
  vlal  节点的值
*/
Node *create_node(int level, keyType key, valueType val);

/*
  创建跳跃表，成功返回skip_list*类型指针,否则返回NULL
*/
skip_list *create_sl();

/*
插入元素的时候元素所占有的层数完全是随机算法,返回随机层数
*/
int randomLevel();

/*
  插入节点，插入成功返回true，否则返回false
  sl     跳表指针
  key   节点关键字
  vlal  节点的值
*/
bool insert(skip_list *sl, keyType key, valueType val);

/*
  删除节点，成功返回true，否则返回false
  sl     跳表指针
  key   节点关键字
*/
bool erase(skip_list *sl, keyType key);

/*
  查找节点，成功返回valueT*类型的指针，否则返回NULL
  sl     跳表指针
  key   节点关键字
*/
valueType *search(skip_list *sl, keyType key);

/*
从最高层开始逐层打印
sl 跳表指针
*/
void print_sl(skip_list *sl);

/*
释放跳跃表
sl 跳表指针
*/
void sl_free(skip_list *sl);

int main() {
  skip_list *skiplist1 = create_sl();
  insert(skiplist1, 3, 3);
  insert(skiplist1, 2, 2);
  insert(skiplist1, 4, 4);
  insert(skiplist1, 5, 5);
  insert(skiplist1, 10, 10);
  print_sl(skiplist1);

  printf("\n");
  int *v = search(skiplist1, 5);

  return 0;
}

// 创建节点
Node *create_node(int level, keyType key, valueType val) {
  Node *p = new_node(level);
  if (!p) {
    return NULL;
  }

  p->key = key;
  p->value = val;
  return p;
}

//创建跳跃表
skip_list *create_sl() {
  skip_list *sl = (skip_list *)malloc(sizeof(skip_list));  //申请跳表结构内存
  if (NULL == sl) return NULL;

  sl->level = 0;  // 设置跳表的层level，初始的层为0层（数组从0开始）

  Node *h = create_node(MAX_L - 1, 0, 0);  //创建头结点
  if (h == NULL) {
    free(sl);
    return NULL;
  }
  sl->head = h;

  int i;
  // 将header的next数组清空
  for (i = 0; i < MAX_L; ++i) {
    h->next[i] = NULL;
  }
  srand(time(0));
  return sl;
}

//插入元素的时候元素所占有的层数完全是随机算法
int randomLevel() {
  int level = 1;
  while (rand() % 2) {
    level++;
  }

  level = (MAX_L > level) ? level : MAX_L;
  return level;
}

/*
step1:查找到在每层待插入位置,跟新update数组
step2:需要随机产生一个层数
step3:从高层至下插入,与普通链表的插入完全相同。
*/
bool insert(skip_list *sl, keyType key, valueType val) {
  Node *update[MAX_L];
  Node *q = NULL, *p = sl->head;  // q,p初始化
  int i = sl->level - 1;

  /******************step1*******************/
  //从最高层往下查找需要插入的位置,并更新update
  //即把降层节点指针保存到update数组
  for (; i >= 0; --i) {
    while ((q = p->next[i]) && q->key < key) p = q;
    update[i] = p;
  }

  if (q && q->key == key)  // key已经存在的情况下
  {
    q->value = val;
    return true;
  }
  /******************step2*******************/
  //产生一个随机层数level
  int level = randomLevel();
  //如果新生成的层数比跳表的层数大
  if (level > sl->level) {
    //在update数组中将新添加的层指向header
    for (i = sl->level; i < level; ++i) {
      update[i] = sl->head;
    }
    sl->level = level;
  }
  // printf("%d\n", sizeof(Node)+level*sizeof(Node*));
  /******************step3*******************/
  //新建一个待插入节点,一层一层插入
  q = create_node(level, key, val);
  if (!q) {
    return false;
  }

  //逐层更新节点的指针,和普通链表插入一样
  for (i = level - 1; i >= 0; --i) {
    q->next[i] = update[i]->next[i];
    update[i]->next[i] = q;
  }
  return true;
}

// 删除节点
bool erase(skip_list *sl, keyType key) {
  Node *update[MAX_L];
  Node *q = NULL, *p = sl->head;
  int i = sl->level - 1;
  for (; i >= 0; --i) {
    while ((q = p->next[i]) && q->key < key) {
      p = q;
    }
    update[i] = p;
  }
  //判断是否为待删除的key
  if (!q || (q && q->key != key)) {
    return false;
  }

  //逐层删除与普通链表删除一样
  for (i = sl->level - 1; i >= 0; --i) {
    if (update[i]->next[i] == q)  //删除节点
    {
      update[i]->next[i] = q->next[i];
      //如果删除的是最高层的节点,则level--
      if (sl->head->next[i] == NULL) sl->level--;
    }
  }
  free(q);
  q = NULL;
  return true;
}

// 查找
valueType *search(skip_list *sl, keyType key) {
  Node *q = NULL;
  Node *p = sl->head;

  int i = sl->level - 1;
  for (; i >= 0; --i) {
    while ((q = p->next[i]) && q->key < key) {
      printf("serach while: level=%d, p=%d, q=%d\n", i, q->key, p->key);
      p = q;
    }
    printf("serach for: level=%d, p=%d\n", i, p->key);

    if (q && key == q->key) {
      return &(q->value);
    }
  }
  return NULL;
}

//从最高层开始逐层打印
void print_sl(skip_list *sl)
{
    Node *q;
    int i = sl->level - 1;
    for(; i >= 0; --i)
    {
        q = sl->head->next[i];
        printf("level %d:\n", i+1);

        while(q)
        {
            printf("key:%d val:%d\t", q->key, q->value);
            q = q->next[i];
        }
        printf("\n");
    }
}

// 释放跳跃表
void sl_free(skip_list *sl)
{
    if(!sl){
        return;
    }
    
    Node *q=sl->head;
    Node *next;
    while(q)
    {
        next=q->next[0];
        free(q);
        q=next;
    }
    free(sl);
}