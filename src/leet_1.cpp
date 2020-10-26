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

vector<int> Solution::inorderTraversal3(TreeNode* root) {
  vector<int> res;
  TreeNode* pre;  

  while (root != NULL) {
    if (!root->left) {
      res.push_back(root->val);
      root = root->right;
    } else {
      pre = root->left;
      while (pre->right && pre->right != root) {
        pre = pre->right;
      }
      if (!pre->right) {
        pre->right = root;
        root = root->left;
      } else {
        pre->right = nullptr;
        res.push_back(root->val);
        root = root->right;
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
  if (root == nullptr) {
    return {};
  }

  std::stack <std::tuple<TreeNode*, int, std::vector<int>>> nodes;
  vector<vector<int>> res;
  TreeNode* cur;
  vector<int> cur_path = {root->val};
  nodes.push(std::make_tuple(root, root->val, cur_path));
  int cur_sum;

  while (!nodes.empty()) {
    auto tup = nodes.top();
    nodes.pop();
    cur = std::get<0>(tup);
    cur_sum = std::get<1>(tup);
    cur_path = std::get<2>(tup);
    std::cout << "cur: " << cur->val << " ; cur_sum: " << cur_sum << std::endl;
    size_t len = cur_path.size();
    for (size_t j = 0; j < len; j++) {
      std::cout << cur_path[j];
    }
    std::cout << std::endl;
    if (!cur->left && !cur->right) {
      if (cur_sum == sum) {
        res.push_back(cur_path);

        std::cout << "cur1: " << cur->val << " ; cur_sum1: " << cur_sum
                  << std::endl;
      }
    } else {
      if (cur->right) {
        auto tmp_path = cur_path;
        tmp_path.push_back(cur->right->val);
        nodes.push(
            std::make_tuple(cur->right, cur->right->val + cur_sum, tmp_path));
      }

      if (cur->left) {
        auto tmp_path = cur_path;
        tmp_path.push_back(cur->left->val);
        nodes.push(
            std::make_tuple(cur->left, cur->left->val + cur_sum, tmp_path));
      }
    }
  }

  return res;
}

vector<vector<int>> ret;
vector<int> path;

void dfs(TreeNode* root, int sum) {
  if (root == nullptr) {
    return;
  }
  path.emplace_back(root->val);
  sum -= root->val;
  if (root->left == nullptr && root->right == nullptr && sum == 0) {
    ret.emplace_back(path);
  }
  dfs(root->left, sum);
  dfs(root->right, sum);
  path.pop_back();
}

vector<vector<int>> Solution::pathSum2(TreeNode* root, int sum) {
  dfs(root, sum);
  return ret;
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


Node* Solution::connect(Node* root) {
  if (!root) return nullptr;
  std::queue<Node*> q;
  q.push(root);
  while (!q.empty()) {
    int levelNum = q.size();
    Node* next = NULL;

    while (levelNum--) {
      Node* node = q.front();
      q.pop();
      if (node->right) q.push(node->right);
      if (node->left) q.push(node->left);

      node->next = next;
      next = node;
    }
  }
  return root;
}

void Solution::reverseString(vector<char>& s) {
  size_t len = s.size();
  if (len == 0) return;
  size_t n = 0;
  if (len % 2 == 0)
    n = len / 2 - 1;
  else
    n = len / 2;
  std::cout << "n: " << n << std::endl;
  for (int i = 0; i <= n; i++) {
    char tmp = s[i];
    s[i] = s[len - 1 - i];
    s[len - 1 - i] = tmp;
  }
}


void Solution::sortColors(vector<int>& nums) {
  int len = nums.size();
  if (len == 0) return;
  for (int j = 1; j < len; j++) {
    int key = nums[j];
    int i = j - 1;
    while (i >= 0 && nums[i] > key) {
      nums[i + 1] = nums[i];
      i = i - 1;
    }
    nums[i + 1] = key;
  }
}

//vector<vector<int>> Solution::levelOrder(TreeNode* root) {
//  if (!root) {
//    return {};
//  }
//  vector<vector<int>> res;
//  vector<TreeNode*> cur = {root};
//  std::vector<vector<TreeNode*>> nodes;
//  vector<TreeNode*> next;
//  vector<int> now;
//  nodes.push_back(cur);
//  while (!nodes.empty()) {
//     
//    cur = nodes.back();
//    nodes.pop_back();
//    next.clear();
//    now.clear();
//    for (int i = 0; i < cur.size(); i++) {
//      now.push_back(cur[i]->val);
//      if (cur[i]->left) next.push_back(cur[i]->left);
//      if (cur[i]->right) next.push_back(cur[i]->right);
//    }
//    res.push_back(now);
//    if (next.size() > 0) nodes.push_back(next);
//  }
//  return res;
//}


vector<vector<int>> Solution::levelOrder(TreeNode* root) {
  if (!root) {
    return {};
  }
  vector<vector<int>> res;
  std::vector<TreeNode*> nodes;
  vector<TreeNode*> next;
  vector<int> now;
  nodes.push_back(root);

  while (!nodes.empty()) {
    //std::vector<TreeNode*> nodes = nodes;
    now.clear();
    next.clear();
    std::cout << "nodes: " << nodes.size() << std::endl;
    for (int i = 0; i < nodes.size(); i++) {
      now.push_back(nodes[i]->val);
      if (nodes[i]->left) next.push_back(nodes[i]->left);
      if (nodes[i]->right) next.push_back(nodes[i]->right);
    }
    res.push_back(now);
    nodes.clear();
    
    if (next.size() > 0) {
      nodes = next;
    }
  }
  return res;
}

bool Solution::hasCycle(ListNode* head) {
  std::unordered_set<ListNode*> seen;
  while (head != nullptr) {
    if (seen.count(head)) {
      return true;
    }
    seen.insert(head);
    head = head->next;
  }
  return false;
}

 bool Solution::hasCycle2(ListNode* head) {
  ListNode *fast = head, *slow = head;
  while (fast && fast->next) {
    fast = fast->next->next;
    slow = slow->next;
    if (slow == fast) return true;
  }
  return false;
}

 ListNode* Solution::detectCycle(ListNode* head) {
  ListNode *fast = head, *slow = head;
  while (fast && fast->next) {
    fast = fast->next->next;
    slow = slow->next;
    if (slow == fast) {
      ListNode* q = head;
      while (q != slow) {
        q = q->next;
        slow = slow->next;
      }
      return q;
    }
  }
  return nullptr;
}


 int min(int a, int b) { return (a < b ? a : b); }

 int Solution::minimumOperations(string leaves) {
   int n = leaves.size();
   int g = (leaves[0] == 'y' ? 1 : -1);
   int gmin = g;
   int ans = INT_MAX;
   for (int i = 1; i < n; ++i) {
     int isYellow = (leaves[i] == 'y');
     g += 2 * isYellow - 1;
     if (i != n - 1) {
       ans = min(ans, gmin - g);
     }
     gmin = min(gmin, g);
   }
   return ans + (g + n) / 2;
 }

  int Solution::minimumOperations2(string leaves) {
   int len = leaves.size();
   int res;
   int res1 = 0;
   int res1_r = 0;

   int res2 = 0;
   int res2_l = 0;
   int res2_r = 0;

   bool flag = true;
   bool flag2 = true;
   int i = 0, j = len - 1;
   while(1) {
     std::cout << "i: " << i << " ;j: " << j << std::endl;
     if (i == j) break;
     if (i == j - 1) break;

     if (leaves[i] == 'r') {
       ++i;
       res1++;
       if (flag) res1_r++;
     } else if (leaves[i] == 'y') {
       ++i;
       res2++;
       if (flag2) res2_l++;
     }

     if (leaves[j] == 'r') {
       --j;
       res1++;
       if (flag) res1_r++;
     } else if (leaves[j] == 'y') {
       --j;
       res2++;
       if (flag2) res2_r++;
     } 

    if (leaves[i] == 'y' && leaves[j] == 'y') {
       if (flag) flag = false;
    }
    if (leaves[i] == 'r' && leaves[j] == 'r') {
      if (!flag) {
        if (flag2) flag2 = false;
      }
    }

   }
   res1 = res2 = 0;
   for (int i = 0; i < len; i++) {
     if (leaves[i] == 'r') {
       res1++;
     } else if (leaves[i] == 'y') {
       res2++;
     }
   }
   std::cout << "res1: " << res1 << " ;res2: " << res2 << " ;res1_r: " << res1_r
             << " ;res2_l: " << res2_l << " ;res2_r: " << res2_r << std::endl;
   return min(res1 - res1_r, min(res2 - res2_l, res2 - res2_r));
 }

  vector<vector<int>> Solution::fourSum(vector<int>& nums, int target) {
   int len = nums.size();
    if (len < 4) {
     return {};
    }
   vector<vector<int>> res = {};
   sort(nums.begin(), nums.end());
   for (int i = 0; i < len; i++) {
     std::cout << "nice: " << i << std::endl;
     int cur1 = nums[i];
     for (int j = i + 1; j < len; j++) {
       int cur2 = nums[j];
       for (int x = j + 1; x < len; x++) {
         int cur3 = nums[x];
         for (int y = x + 1; y < len; y++) {
           int cur4 = nums[y];
           if (cur1 + cur2 + cur3 + cur4 == target) {
             res.push_back({cur1, cur2, cur3, cur4});
           }
         }
       }
     }
   }
   sort(res.begin(), res.end());
   res.erase(unique(res.begin(), res.end()), res.end());
   //std::cout << "nice: " << res[0][0] << std::endl;
   return res;
 }

  bool Solution::canPartition(vector<int>& nums) {
   int sum = 0;
   int len = nums.size();
   for (int i = 0; i < len; i++) sum += nums[i];
   if (sum % 2 != 0) return false;
   vector<bool> d((sum >>= 1) + 1, false);
   for (int i = 0; i < nums.size(); i++) {
     for (int s = sum; s >= nums[i]; s--) {
       if (!i)
         d[s] = (nums[i] == s);
       else
         d[s] = d[s] || d[s - nums[i]];
     }
   }
   return d[sum];
 }

  TreeNode* pre;
  void getMinDif(TreeNode* cur, int& res) {
   if (!cur) return;
    getMinDif(cur->left, res);
   if (pre) {
      res = min(res, abs((cur->val) - (pre->val)));
   }
   pre = cur;
   getMinDif(cur->right, res);
  }

  int Solution::getMinimumDifference(TreeNode* root) {
    int res;
    getMinDif(root, res);
    return res;
  }

  ListNode* Solution::swapPairs(ListNode* head) {
    if (!head) {
      return nullptr;
    }

    if (!head->next) {
      return head;
    }

    ListNode* cur = new ListNode(0);
    cur->next = head;
    ListNode* tmp = cur;

    while (tmp->next && tmp->next->next) {
      //ListNode* node1 = tmp->next;
      //ListNode* node2 = tmp->next->next;
      //tmp->next = node2;
      //node1->next = node2->next;
      //node2->next = node1;
      //tmp = node1;

      head = tmp->next->next;
      tmp->next->next = head->next;
      head->next = tmp->next;
      tmp->next = head;
      tmp = head->next;
    }

    return cur->next;
  }

  vector<string> Solution::commonChars(vector<string>& A) {
    vector<string> res;
    int len = A.size();
    int len1 = A[0].size();
    for (int j = 0; j < len1; j++) {
      bool flag = true;
      for (int i = 1; i < len; i++) {
        auto pos = A[i].find(string(&A[0][j], 1));
        if ( pos != A[i].npos) {
          //flag = true;
          //A[i].erase(pos, 1);
          A[i][pos] -= 32;
        } else
          flag = false;
      }
      if (flag) {
        //std::cout << "i: " << &A[0]
        //string s(&A[0][j], 1);
        res.push_back(string(&A[0][j], 1));
      }
    }
    
    return res;
  }


  Node* Solution::connect2(Node* root) {
    if (!root) return nullptr;
    Node* pre = root;
    Node* cur = nullptr;
    while (pre->left) {
      cur = pre;
      while (cur) {
        cur->left->next = cur->right;
        if (cur->next) cur->right->next = cur->next->left;
        cur = cur->next;
      }
      pre = pre->left;
    }
    return root;

    /* µÝ¹é */
    //void dfs_connect(Node * cur, Node * next) {
    //  if (!cur) return;
    //  cur->next = next;
    //  dfs_connect(cur->left, cur->right);
    //  dfs_connect(cur->right, cur->next ? cur->next->left : nullptr);
    //}

    //Node* connect(Node * root) {
    //  dfs_connect(root, nullptr);
    //  return root;
    //}
  }

  vector<int> Solution::sortedSquares(vector<int>& A) {
    //vector<int> res;
    //for (auto it : A) {
    //  res.push_back(pow(it, 2));
    //}
    ////sort(res.begin(), res.end());

    //for (int j = 1; j < res.size(); j++) {
    //  int key = res[j];
    //  int i = j - 1;
    //  while (i >= 0 && res[i] > key) {
    //    res[i + 1] = res[i];
    //    i = i - 1;
    //  }
    //  res[i + 1] = key;
    //}
    //return res;

    int n = A.size();
    vector<int> ans(n);
    for (int i = 0, j = n - 1, pos = n - 1; i <= j;) {
      if (A[i] * A[i] > A[j] * A[j]) {
        ans[pos] = A[i] * A[i];
        ++i;
      } else {
        ans[pos] = A[j] * A[j];
        --j;
      }
      --pos;
    }
    return ans;
  }


  ListNode* Solution::removeNthFromEnd(ListNode* head, int n) {
    if (!head->next) return nullptr;
    vector<ListNode*> nodes;
    ListNode* cur = head;
    while (cur) {
      nodes.push_back(cur);
      cur = cur->next;
    }
    // if(nodee.size() - 1 < 2 + n)
    int len = nodes.size();
    if (n <= 1) {
      std::cout << "333" << std::endl;
      nodes[len - n - 1]->next = nullptr;
    }

    else if (len - n - 1 < 0) {
      std::cout << "111" << std::endl;
      head = head->next;
    }

    else {
      std::cout << "222: " << len - n - 1 << std::endl;
      nodes[len - n - 1]->next = nodes[len - n + 1];
    }

    return head;
  }

  string delete_backspace(string S) {
    string res = "";
    int len = S.size();
    int count = 0;
    for (int i = len - 1, n = 0; i >= 0; i--) {
      if (S[i] == '#') {
        std::cout << "S[i]1: " << S[i] << std::endl;
        count++;
      } else {
        if (count > 0) {
          // continue;
          count--;
        } else {
          std::cout << "S[i]2: " << S[i] << std::endl;
          res = res + S[i];
          n++;
        }
      }
    }
    return res;
  }

  bool Solution::backspaceCompare(string S, string T) {
    auto res1 = delete_backspace(S);
    auto res2 = delete_backspace(T);
    std::cout << "res1: " << res1 << " ,res2: " << res2 << std::endl;
    if (res1 == res2) std::cout << "sss";
      return false;
  }


  void Solution::reorderList(ListNode* head) {
    std::vector<ListNode*> nodes;
    ListNode* cur = head;
    while (cur) {
      nodes.push_back(cur);
      cur = cur->next;
    }
    cur = head;
    int n = nodes.size() - 1;
    int x;
    if (nodes.size() % 2 == 0) x = (nodes.size() - 1) / 2 + 2; 
    else x = (nodes.size() - 1) / 2 + 1; 
    while (cur && x <= n ) {
      std::cout << "cur: " << cur->val << ", tail: " << nodes[n]->val << "; xxx: " <<
          (nodes.size() - 1) / 2 + 1<<std ::endl;
      nodes[n]->next = cur->next;
      cur->next = nodes[n];
      nodes[n - 1]->next = NULL;
      cur = nodes[n]->next;
      n--;
    }
  }

  bool Solution::isLongPressedName(string name, string typed) {
    char cur;
    int len1 = name.size();
    int len2 = typed.size();
    if (len2 == 0 || len2 < len1) return false;
    int i , j = 0;
    for (i = 0; i < len2; i++) {
      if (typed[i] == name[j]) {
        std::cout << "typed1: " << typed[i] << ", name1: " << name[j]
                  << ", cur1: " << cur << std::endl;
        cur = name[j];
        j++;
      } else {
        std::cout << "typed2: " << typed[i] << ", name2: " << name[j]
                  << ", cur2: " << cur
                  << std::endl;
        if (cur != typed[i]) {
          return false;
        }
      }
    }
    std::cout << "j: " << j << std::endl;
    if (j < len1 - 1 || name[j] != typed[i]) return false;
    return true;
  }


  vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
    vector<int> res;
    int len = nums.size();
    for (int i = 0; i < len; i++) {
      int s = 0;
      for (int j = 0; j < len; j++) {
        if (nums[j] < nums[i]) s++;
      }
      res.push_back(s);
    }
    return res;
   }