/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//是否是对称二叉树！！！！

class Solution {
 public:
  //迭代解法!!!
  bool isSymmetric1(TreeNode* root) {
    if (!root) {
      return true;  //空树是对称的
    }

    stack<TreeNode*> s;
    TreeNode* p = root->left;
    TreeNode* q = root->right;
    s.push(p);
    s.push(q);  //即使是空节点，也是可以push到栈里的，栈并不为空。
    while (!s.empty()) {
      p = s.top();
      s.pop();

      q = s.top();
      s.pop();

      if (!p && !q) {  // p、q都是空节点
        continue;
      }

      if ((!p && q) || (p && !q)) {  //有一个为空，不对称
        return false;
      }

      if (p->val != q->val) {
        return false;  //值不相等，不对称
      }

      s.push(p->left);
      s.push(q->right);

      s.push(p->right);
      s.push(q->left);
    }
    return true;
  }

  //递归算法
  bool isSymmetric(TreeNode* root) {
    if (root == NULL) {
      return true;
    }

    return symmetric(root->left, root->right);
  }
  bool symmetric(TreeNode* left, TreeNode* right) {
    if (left == NULL && right == NULL) {
      return true;
    }

    if ((left != NULL && right == NULL) || (left == NULL && right != NULL)) {
      return false;
    }

    //左子树和右子树对称：左子树的左子树和右子树的右子树对称，且左子树的右子树和右子树的左子树对称！！！
    if (left->val == right->val) {
      bool leftRet = symmetric(left->left, right->right);
      bool rightRet = symmetric(right->left, left->right);
      if (leftRet == true && rightRet == true) {
        return true;
      }
      return false;
    }
    return false;
  }
};