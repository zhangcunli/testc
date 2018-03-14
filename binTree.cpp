
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

typedef struct TreeNode {
  int data;
  struct TreeNode* parent;
  struct TreeNode* left;
  struct TreeNode* right;
} TreeNode;

TreeNode* InsertNode(TreeNode** root, int data) {
  TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
  if (node == NULL) {
    return NULL;
  }
  node->data = data;
  node->parent = NULL;
  node->left = NULL;
  node->right = NULL;

  if ((*root) == NULL) {
    *root = node;
    return *root;
  }

  TreeNode* cur = *root;
  TreeNode* parent = cur;
  while (cur != NULL) {
    parent = cur;
    if (data <= cur->data) {
      cur = cur->left;
    } else {
      cur = cur->right;
    }
  }

  node->parent = parent;
  if (node->data <= parent->data) {
    parent->left = node;
  } else {
    parent->right = node;
  }

  return *root;
}

//递归插入
TreeNode* InsertNode2(TreeNode** root, int data) {
  TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
  if (node == NULL) {
    return NULL;
  }
  node->data = data;
  node->parent = NULL;
  node->left = NULL;
  node->right = NULL;

  if ((*root) == NULL) {
    *root = node;
    return *root;
  }

  if (data <= (*root)->data) {
    return InsertNode2(&(*root)->left, data);
  } else {
    return InsertNode2(&(*root)->right, data);
  }

  return *root;
}
void midOrderWalk(TreeNode* root) {
  if (root != NULL) {
    midOrderWalk(root->left);
    printf("%3d", root->data);
    midOrderWalk(root->right);
  }
  return;
}

void preOrderWalk(TreeNode* root) {
  if (root != NULL) {
    printf("%3d", root->data);
    preOrderWalk(root->left);
    preOrderWalk(root->right);
  }
  return;
}

void postOrderWalk(TreeNode* root) {
  if (root != NULL) {
    postOrderWalk(root->left);
    postOrderWalk(root->right);
    printf("%3d", root->data);
  }
  return;
}

//二分搜索
TreeNode* search(TreeNode* root, int key) {
  if (root == NULL) {
    return NULL;
  }

  if (key == root->data) {
    return root;
  } else if (key < root->data) {
    return search(root->left, key);
  } else {
    return search(root->right, key);
  }
}

//非递归查找
TreeNode* search2(TreeNode* root, int key) {
  if (root == NULL) {
    return NULL;
  }

  TreeNode* node = root;
  while (node != NULL) {
    if (key == node->data) {
      return node;
    } else if (key < node->data) {
      node = node->left;
    } else {
      node = node->right;
    }
  }
  return node;
}

//深度优先前序遍历
void dfs_preorder(TreeNode* root) {
  if (root == NULL) {
    return;
  }

  stack<TreeNode*> node_stack;
  node_stack.push(root);
  while (!node_stack.empty()) {
    TreeNode* tmp = node_stack.top();
    printf("%3d", tmp->data);
    node_stack.pop();

    //注：要先将右子树节点压栈，栈顶
    if (tmp->right != NULL) {
      node_stack.push(tmp->right);
    }
    if (tmp->left != NULL) {
      node_stack.push(tmp->left);
    }
  }
  return;
}

void bfs_walk(TreeNode* root) {
  if (root == NULL) {
    return;
  }

  queue<TreeNode*> queue_node;
  queue_node.push(root);
  while (!queue_node.empty()) {
    TreeNode* tmp = queue_node.front();
    printf("%3d", tmp->data);
    queue_node.pop();

    //注：要先将左子树节点压队列，队尾
    if (tmp->left != NULL) {
      queue_node.push(tmp->left);
    }
    if (tmp->right != NULL) {
      queue_node.push(tmp->right);
    }
  }
  return;
}

int main() {
  TreeNode* root = NULL;
  InsertNode(&root, 10);
  InsertNode(&root, 8);
  InsertNode(&root, 7);
  InsertNode(&root, 12);
  InsertNode(&root, 13);
  InsertNode(&root, 5);
  InsertNode(&root, 11);

  //
  midOrderWalk(root);
  printf("\n");

  preOrderWalk(root);
  printf("\n");

  postOrderWalk(root);
  printf("\n");

  TreeNode* snode = search(root, 5);
  if (snode != NULL) {
    printf("snode=%d\n", snode->data);
  }

  snode = search(root, 4);
  if (snode != NULL) {
    printf("snode=%d\n", snode->data);
  }
  printf("\n\n");

  TreeNode* root2 = NULL;
  InsertNode2(&root2, 10);
  InsertNode2(&root2, 8);
  InsertNode2(&root2, 7);
  InsertNode2(&root2, 12);
  InsertNode2(&root2, 9);

  //
  midOrderWalk(root2);
  printf("\n");

  preOrderWalk(root2);
  printf("\n");

  snode = search2(root2, 7);
  if (snode != NULL) {
    printf("snode=%d\n", snode->data);
  }

  printf("\n\ndfs_preorder:");
  dfs_preorder(root2);

  printf("\nbfs_preorder:");
  bfs_walk(root2);

  return 0;
}