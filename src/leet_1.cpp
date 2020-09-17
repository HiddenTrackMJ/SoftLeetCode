#include "leet_1.h"

ListNode* Solution::int2node(int* a, int len) {
  ListNode* res;
  ListNode* tmp;

  for (int i = 0; i < len; i++) {
    int cur = a[i];
    std::cout << "cur: " << cur << std::endl;
    ListNode* x = new ListNode(cur);
    if (i == 0) {
      res = x;
      tmp = x;
    } else {
      tmp->next = x;
      tmp = x;
    }
    delete x;
  }
  return res;
}

ListNode* Solution::addTwoNumbers(ListNode* l1, ListNode* l2) {
  ListNode* res;
  ListNode* tmp;
  bool flag = false;
  bool is_first = true;

  while (l1 != NULL || l2 != NULL) {
    if (l1 != NULL && l2 != NULL) {
 
      int cur1 = l1->val;
      int cur2 = l2->val;
      
      int sum = cur1 + cur2;
      if (flag) {
        ++sum;
        flag = false;
      }
      std::cout << "x: " << cur1 << " ;y: " << cur2 << " ;sum: " << sum
                << std::endl;
      ListNode* x;
      if (sum < 10)
        x = new ListNode(sum);
      else {
        x = new ListNode(sum - 10);
        flag = true;
      }

      if (is_first) {
        res = x;
        tmp = x;
        is_first = false;
      } else {
        tmp->next = x;
        tmp = x;
      }
      l1 = l1->next;
      l2 = l2->next;
      delete x;

    } else if (l1 != NULL && l2 == NULL) {

      int cur1 = l1->val;
      int sum = cur1;
      if (flag) {
        ++sum;
        flag = false;
      }
      ListNode* x;
      if (sum < 10)
        x = new ListNode(sum);
      else {
        x = new ListNode(sum - 10);
        flag = true;
      }
      std::cout << "x: " << cur1 << " ;sum: " << sum << std::endl;
      tmp->next = x;
      tmp = x;
      l1 = l1->next;
      delete x;

    } else if (l1 == NULL && l2 != NULL) {

      int cur2 = l2->val;
      int sum = cur2;
      if (flag) {
        ++sum;
        flag = false;
      }
      ListNode* x;
      if (sum < 10)
        x = new ListNode(sum);
      else {
        x = new ListNode(sum - 10);
        flag = true;
      }
      std::cout << "y: " << cur2 << " ;sum: " << sum << std::endl;
      tmp->next = x;
      tmp = x;
      l2 = l2->next;
      delete x;
    } 
  }
  if (flag) {
    ListNode* x = new ListNode(1);
    std::cout << " ;sum: " << 1 << std::endl;
    tmp->next = x;
    tmp = x;
    delete x;
  }
  //while (l2 != NULL) {
  //  int root = l2->val;
  //  std::cout << "x: " << root << std::endl;
  //  l2 = l2->next;
  //}

  return res;
}


 void inorder(TreeNode* root, vector<int>& res) {
  if (!root) {
    return;
  }
  inorder(root->left, res);
  res.push_back(root->val);
  std::cout << "cur:" << root->val << std::endl;
  inorder(root->right, res);
}

vector<int> Solution::inorderTraversal(TreeNode* root) {
  vector<int> res;
  inorder(root, res);
  return res;
}

vector<int> Solution::inorderTraversal2(TreeNode* root) {
  vector<int> res;
  vector<TreeNode*> nodes;
  //TreeNode* root = root;
  bool flag = false;

  while (root != NULL) {
    if (root->left != NULL && !flag) {
      nodes.push_back(root);
      std::cout << "move to left: " << root->val << std::endl;
      root = root->left;
    } else {
      std::cout << "push: " << root->val << std::endl;
      res.push_back(root->val);
      if (root->right != NULL) {
        std::cout << "move to right: " << root->val << std::endl;
        root = root->right;
        flag = false;
      } else {
        if (nodes.empty()) break;
        root = nodes.back();
        std::cout << "back to middle: " << root->val << std::endl;
        nodes.pop_back();
        flag = true;
      }
    }
  }
  return res;
}

void inorder_reverse(TreeNode* root, vector<int>& res) {
  if (!root) {
    return;
  }
  inorder_reverse(root->left, res);
  auto left = root->left;
  auto right = root->right;
  root->left = left;
  root->right = right;
  inorder_reverse(root->right, res);
}

TreeNode* Solution::invertTree(TreeNode* root) {
  while (root) {
    auto left = root->left;
    auto right = root->right;
    root;
  }
  return root;
}