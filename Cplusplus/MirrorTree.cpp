/*
struct TreeNode {
        int val;
        struct TreeNode *left;
        struct TreeNode *right;
        TreeNode(int x) :
                        val(x), left(NULL), right(NULL) {
        }
};*/
class Solution {
 public:
  void Mirror(TreeNode *pRoot) {
    if (pRoot == nullptr) {
      return;
    }
    stack<TreeNode *> s;
    s.push(pRoot);
    while (!s.empty()) {
      auto node = s.top();
      s.pop();
      if (node->left || node->right) {
        swap(node->left, node->right);
      }
      if (node->right) {
        s.push(node->right);
      }
      if (node->left) {
        s.push(node->left);
      }
    }
  }
};
