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
  // while (l2 != NULL) {
  //  int res = l2->val;
  //  std::cout << "x: " << res << std::endl;
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
  std::stack<TreeNode*> nodes;
  // TreeNode* res = res;
  bool flag = false;

  while (root != NULL) {
    if (root->left != NULL && !flag) {
      nodes.push(root);
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
        root = nodes.top();
        std::cout << "back to middle: " << root->val << std::endl;
        nodes.pop();
        flag = true;
      }
    }
  }
  return res;
}

bool row[9][9];
bool col[9][9];
bool block[3][3][9];
vector<std::pair<int, int>> blank_pt;
bool valid;

void repeat(vector<vector<char>>& board, int pos) {
  if (blank_pt.size() == pos) {
    valid = true;
    return;
  }

  auto i = blank_pt[pos].first;
  auto j = blank_pt[pos].second;

  for (int n = 0; n < 9 && !valid; ++n) {
    if (!row[i][n] && !col[j][n] && !block[i / 3][j / 3][n]) {
      row[i][n] = true;
      col[j][n] = true;
      block[i / 3][j / 3][n] = true;
      board[i][j] = n + '0' + 1;
      repeat(board, pos + 1);
      row[i][n] = false;
      col[j][n] = false;
      block[i / 3][j / 3][n] = false;
    }
  }
}

void Solution::solveSudoku(vector<vector<char>>& board) {
  memset(row, false, sizeof(row));
  memset(col, false, sizeof(col));
  memset(block, false, sizeof(block));
  valid = false;

  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      int num = board[i][j] - '0';
      // std::cout << i << j << ": " << num << std::endl;
      if (board[i][j] == '.') {
        blank_pt.emplace_back(i, j);
      } else {
        int num = board[i][j] - '0' - 1;
        row[i][num] = true;
        col[j][num] = true;
        block[i / 3][j / 3][num] = true;
      }
    }
  }

  repeat(board, 0);
}

void inorder_reverse(TreeNode* root) {
  if (!root) {
    return;
  }

  inorder_reverse(root->left);
  auto left = root->left;
  auto right = root->right;

  inorder_reverse(root->right);
  root->left = right;
  root->right = left;
}

TreeNode* Solution::invertTree(TreeNode* root) {
  inorder_reverse(root);
  return root;
}

TreeNode* Solution::invertTree2(TreeNode* root) {
  std::stack<TreeNode*> nodes;
  bool flag = false;

  TreeNode* res = root;
  nodes.push(root);
  if (!root) {
    return root;
  }
  while (!nodes.empty()) {
    res = nodes.top();
    nodes.pop();
    auto tmp = res->left;
    res->left = res->right;
    res->right = tmp;
    if (res->left) {
      nodes.push(res->left);
    }
    if (res->right) {
      nodes.push(res->right);
    }
  }
  return root;
}

void inorder_search(TreeNode* root, int& res) {
  if (!root) {
    return;
  }
  res += root->val;
  //std::cout << "cur1:" << root->val << "; res:" << res << std::endl;
  inorder_search(root->left, res);
  inorder_search(root->right, res);
}

void inorder_convert(TreeNode* root, int more, int root_val) {
  if (!root) {
    return;
  }

  int res = 0;
  inorder_search(root->right, res);
  int tmp = root->val;
  root->val = root->val + more + res;
  std::cout << "cur1:" << tmp << " ;cur2:" << root->val
            << "; res:" << res << "; more:" << more << "; origin:" << root_val
            << std::endl;
  more = root->val;

  if (tmp >= root_val) {
    std::cout << "xxx"
              << "cur:" << tmp << " ;origin:" << root_val
              << std::endl;
    inorder_convert(root->right, 0, root_val);
  } else {
    std::cout << "yyy"
              << "cur:" << tmp << " ;origin:" << root_val
              << std::endl;
    inorder_convert(root->right, more - res - tmp, root_val);
  }


  inorder_convert(root->left, more, root_val);
}

void inorder_convert2(TreeNode* root, int& more) {
  if (!root) {
    return;
  }

  inorder_convert2(root->right, more);
  more += root->val;
  root->val = more;
  inorder_convert2(root->left, more);
}


void traversal(TreeNode* root, int& pre) {
  std::stack<TreeNode*> st;
  TreeNode* cur = root;
  while (cur != NULL || !st.empty()) {
    if (cur != NULL) {
      st.push(cur);
      cur = cur->right;  // ÓÒ
    } else {
      cur = st.top();  // ÖÐ
      st.pop();
      cur->val += pre;
      pre = cur->val;
      cur = cur->left;  // ×ó
    }
  }
}

TreeNode* Solution::convertBST(TreeNode* root) {
  int res = 0;
  //inorder_convert(root, 0, root->val);

  //inorder_convert2(root, res);
  traversal(root, res);
  return root;
}


int Solution::minCameraCover(TreeNode* root) {
  int res = 0;
  if (!root) {
    return res;
  }
  TreeNode* cur = root;
  std::stack<TreeNode*> nodes;
  int s1, s2;

  while (cur || !nodes.empty()) {
    if (cur->left) {
      nodes.push(cur);
      cur = cur->left;

    } else {
      cur = nodes.top();
      nodes.pop();
      cur = cur->right;
    }
  }
}
