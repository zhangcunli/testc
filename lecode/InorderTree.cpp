//看题目，要求返回中序遍历的子序列，不是打印出来
class Solution {
 public:
  vector<int> inorderTraversal(TreeNode* root) {
    vector<int> v;
    if (root == NULL) {
      return v;
    }

    //递归，将左子树递归遍历的结果顺序压入最终要返回的 vector<int> 中；
    int i = 0;
    vector<int> tmp = inorderTraversal(root->left);
    while (!tmp.empty() && i < tmp.size()) {
      v.push_back(tmp[i++]);
    }
    v.push_back(root->val);

    //递归，将右子树递归遍历的结果顺序压入最终要返回的 vector<int> 中；
    i = 0;
    vector<int> tmp1 = inorderTraversal(root->right);
    while (!tmp1.empty() && i < tmp1.size()) {
      v.push_back(tmp1[i++]);
    }
    return v;
  }
};

//非递归， 需要一个 Stack，注意过各，和前序遍历完全不一样啊!!!
class Solution2 {
 public:
  vector<int> inorderTraversal(TreeNode* root) {
    vector<int> v;
    if (root == NULL) {
      return v;
    }

    stack<TreeNode*> st;
    TreeNode* cur = root;

    while (cur != NULL || !st.empty()) {
      if (cur != NULL) {
        st.push(cur);
        cur = cur->left;
      } else {
        cur = st.top();
        v.push_back(cur->val);
        cur = cur->right;
        st.pop();
      }
    }

    return v;
  }
};

//后根遍历
vector<int> postorderTraversal(TreeNode* root) {
  vector<int> result;
  if (root == NULL) return result;
  stack<TreeNode*> s;
  TreeNode* p = root;  //当前正访问的节点
  TreeNode* q;         //记录刚刚访问过的节点
  do {
    while (p != NULL) {
      s.push(p);
      p = p->left;
    }
    q = NULL;
    while (!s.empty()) {
      p = s.top();
      s.pop();
      if (p->right == q) {  //当右子树已经访问过了，才可以访问根
        result.push_back(p->val);
        q = p;  //记录刚刚访问过的节点
      } else {
        s.push(p);  //第一次访问到该节点，需要将它重新入栈
        p = p->right;
        break;
      }
    }
  } while (!s.empty());

  return result;
}

// 95. 生成不同的二叉树。。。。醉了。。。都什么题。。。
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution3 {
 public:
  vector<TreeNode*> generateTrees(int n) {
    vector<TreeNode*> ret;
    if (n == 0) {
      return ret;
    } else if (n == 1) {
      ret.push_back(new TreeNode(1));
      ;
    } else {
      ret = genrateTree(1, n);
    }
    return ret;
  }

  vector<TreeNode*> genrateTree(int start, int end) {
    vector<TreeNode*> ret;
    if (start > end) {
      ret.push_back(nullptr);
      return ret;
    }
    if (start == end) {
      ret.push_back(new TreeNode(start));
      return ret;
    }

    for (int i = start; i <= end; i++) {
      vector<TreeNode*> leftT = genrateTree(start, i - 1);
      vector<TreeNode*> rightT = genrateTree(i + 1, end);
      for (vector<TreeNode*>::iterator m = leftT.begin(); m < leftT.end();
           m++) {
        for (vector<TreeNode*>::iterator n = rightT.begin(); n != rightT.end();
             n++) {
          TreeNode* head = new TreeNode(i);
          head->left = *m;
          head->right = *n;
          ret.push_back(head);
        }
      }
    }
    return ret;
  }
};
