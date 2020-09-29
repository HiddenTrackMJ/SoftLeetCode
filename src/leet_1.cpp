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

int dfs_camera(TreeNode* cur, int& res) {
  if (cur == NULL) return 2;

  int left = dfs_camera(cur->left, res);
  int right = dfs_camera(cur->right, res);

  if (left ==2 && right == 2) {
    return 0;
  } else if (left == 0 || right == 0) {
    res++;
    return 1;
  } else if (left == 1 || right == 1) {
    return 2;
  }
}


int Solution::minCameraCover(TreeNode* root) {
  int res = 0;
  if (dfs_camera(root, res) == 0) {  // root ÎÞ¸²¸Ç
    res++;
  }
  return res;
}


TreeNode* Solution::mergeTrees(TreeNode* t1, TreeNode* t2) {
  if (!t1) {
    return t2;
  }

  if (!t2) {
    return t1;
  }

  TreeNode* cur1 = t1;
  TreeNode* cur2 = t2;
  std::stack<TreeNode*> nodes1;
  std::stack<TreeNode*> nodes2;
  nodes1.push(t1);
  nodes2.push(t2);

  //std::stack<std::pair<TreeNode*, TreeNode*>> nodes;
  //nodes.push(std::make_pair(t1, t2));




  while (!nodes1.empty() && !nodes2.empty()) {
    //std::make_pair(cur1, cur2) = nodes.top();
    //nodes.pop();


    cur1 = nodes1.top();
    nodes1.pop();

    cur2 = nodes2.top();
    nodes2.pop();

    cur1->val += cur2->val;
    std::cout << "push: " << cur1->val << std::endl;
    if (cur1->left || cur2->left) {
      TreeNode* n = new TreeNode(0);
      if (!cur1->left) cur1->left = n;
      if (!cur2->left) cur2->left = n;

      //nodes.push(std::make_pair(cur1->left, cur2->left));
      nodes1.push(cur1->left);
      nodes2.push(cur2->left);
    }

    if (cur1->right || cur2->right) {
      TreeNode* n = new TreeNode(0);

      if (!cur1->right) cur1->right = n;
      if (!cur2->right) cur2->right = n;
      //nodes.push(std::make_pair(cur1->right, cur2->right));

      nodes1.push(cur1->right);
      nodes2.push(cur2->right);
    }
  }

  return t1;
}

std::vector<int> res;
TreeNode* now = nullptr;
int count = -1;
int max_count = -1;

void dfs_findMode(TreeNode* cur, std::map<int, int>& mode_map) {
  if (!cur) {
    return;
  }

  dfs_findMode(cur->left, mode_map);

  //auto x = mode_map.find(root->val);
  //if (x == mode_map.end()) {
  //  mode_map[root->val] == 1;
  //} else {
  //  std::cout << "now : " << root->val << std::endl;
  //  mode_map[root->val]++;
  //}

  if (!now) {
    std::cout << "now3 : " << count << std::endl;
    count = 1;
  } else if (now->val == cur->val) {
    std::cout << "now4 : " << count << std::endl;
    count++;
  } else {
    std::cout << "now5 : " << count << std::endl;
    count = 1;
  }
  now = cur;

  if (max_count < count) {
    max_count = count;
    //std::cout << "now1 : " << count << std::endl;
    res.clear();
    res.push_back(now->val);
  } else if (max_count == count) {
    //std::cout << "now2 : " << count << std::endl;
    res.push_back(now->val);
  }

  dfs_findMode(cur->right, mode_map);
}

vector<int> Solution::findMode(TreeNode* root) {
  if (!root) {
    return {};
  }


  std::map<int, int> mode_map;
  dfs_findMode(root, mode_map);
  
  //auto iter = mode_map.begin();
  //int tmp = 0;
  //while (iter != mode_map.end()) {
  //  std::cout << iter->first << " : " << iter->second << std::endl;
  //  if (tmp < iter->second) {
  //    tmp = iter->second;
  //    res.clear();
  //    res.push_back(iter->first);
  //  } else if (tmp == iter->second) {
  //    res.push_back(iter->first);
  //  }
  //  iter++;
  //}
  return res;
}

TreeNode* dfs_buildTree(int inorder_start, int inorder_end, int postorder_start,
                   int postorder_end, vector<int>& inorder, vector<int>& postorder) {

  int in_root = 0;
  int root_val = postorder[postorder_end];
  std::cout << "push : " << root_val << " ;inorder_start : " << inorder_start
            << " ;inorder_end : " << inorder_end
            << " ;postorder_start : " << postorder_start
            << " ;postorder_end : " << postorder_end << std::endl;
  TreeNode* cur_root = new TreeNode(root_val);
  if (inorder_end - inorder_start == 0) {
    return cur_root;
  }

  while (inorder[in_root] != root_val && in_root < inorder_end) {
    in_root++;
  }

  int left_num = in_root - inorder_start;
  std::cout << "left num: " << left_num << std::endl;
  if (left_num > 0) {
    cur_root->left = dfs_buildTree(inorder_start, in_root - 1, postorder_start,
                                   postorder_start + left_num - 1, inorder, postorder);
  }

  int right_num = inorder_end - in_root;
  std::cout << "right_num: " << right_num << std::endl;
  if (right_num > 0) {
    cur_root->right = dfs_buildTree(in_root + 1, inorder_end, postorder_end - right_num,
                      postorder_end - 1, inorder, postorder);
  }

  return cur_root;
}

TreeNode* Solution::buildTree(vector<int>& inorder, vector<int>& postorder) {
  
  int len = postorder.size();
  if (len == 0) return nullptr;
  else return dfs_buildTree(0, len - 1, 0, len - 1, inorder, postorder);
}



vector<vector<int>> Solution::pathSum(TreeNode* root, int sum) {
  std::map<TreeNode*, vector<int>> node_path;
  vector<vector<int>> res;
  TreeNode* cur = root;

  while (cur) {

  }

}

void dfs_post(TreeNode* cur, vector<int> res) {
  if (!cur) {
    return;
  }
  dfs_post(cur->left, res);
  dfs_post(cur->right, res);
  std::cout << "push: " << cur->val << std::endl;
  res.push_back(cur->val);
}

vector<int> Solution::postorderTraversal(TreeNode* root) {
  if (!root) {
    return {};
  }
  vector<int> res;
  dfs_post(root, res);
  return res;
}

vector<int> Solution::postorderTraversal2(TreeNode* root) {
  if (!root) {
    return {};
  }
  vector<int> res;
  TreeNode* cur = nullptr;
  std::stack<TreeNode*> nodes;
  //nodes.push(root);

  while (root || !nodes.empty()) {
    while (root) {
      nodes.push(root);
      root = root->left;
    }
    root = nodes.top();
    nodes.pop();
    if (root->right == nullptr || root->right == cur) {
      res.push_back(root->val);
      cur = root;
      root = nullptr;
    } else {
      nodes.push(root);
      root = root->right;
    }
  }


  return res;
}