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
      cur = cur->right;  // 右
    } else {
      cur = st.top();  // 中
      st.pop();
      cur->val += pre;
      pre = cur->val;
      cur = cur->left;  // 左
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
  if (dfs_camera(root, res) == 0) {  // root 无覆盖
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

    /* 递归 */
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

  vector<int> Solution::partitionLabels(string S) {
    //vector<int> res;
    //std::map<char, int> pos_map;
    //int len = S.size();
    //for (int i = 0; i < len; i++) {
    //  pos_map[S[i]] = i;    
    //}

    //for (auto it : pos_map) {
    //  cout << "it: " << it.first << " , second: " << it.second << endl;
    //}

    //for (int i = 0; i < len; i++) {
    //  int j = i;
    //  int end = pos_map[S[i]];
    //  while (1) {
    //    int endc = pos_map[S[j]];
    //    cout << "end: " << end << " , endc: " << endc << endl;
    //    end = std::max(endc, end);
    //    if (j == end) {
    //      res.push_back(j - i + 1);
    //      i = j;
    //      break;
    //    }
    //    j++;
    //  }
    //}
    //return res;
    vector<int> res;
    int pos_map[26];
    int len = S.size();
    for (int i = 0; i < len; i++) {
      pos_map[S[i] - 'a'] = i;
    }

    for (int i = 0; i < len; i++) {
      int j = i;
      int end = pos_map[S[i] - 'a'];
      while (1) {
        int endc = pos_map[S[j] - 'a'];
        end = std::max(endc, end);
        if (j == end) {
          res.push_back(j - i + 1);
          i = j;
          break;
        }
        j++;
      }
    }
    return res;
  }

  ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* curr = head;
    while (curr != nullptr) {
      ListNode* nextTemp = curr->next;
      curr->next = prev;
      prev = curr;
      curr = nextTemp;
    }
    return prev;
  }

  ListNode* endOfFirstHalf(ListNode* head) {
    ListNode* fast = head;
    ListNode* slow = head;
    while (fast->next != nullptr && fast->next->next != nullptr) {
      fast = fast->next->next;
      slow = slow->next;
    }
    return slow;
  }

  bool Solution::isPalindrome(ListNode* head) { 
    vector<int> nodes;
    int len = 0;
    while (head) {
      nodes.push_back(head->val);
      head = head->next;
      len++;
    }

    cout << "len: " << len << "; x: " << len / 2 - 1 << endl;
    for (int i = 0, j = len - 1; i <= len / 2 - 1; i++, j--) {
      cout << "nodes[i]: " << nodes[i] << "; nodes[j]: " << nodes[j]
           << endl;
      if (nodes[i] != nodes[j]) return false;
    }
    return true;

    //if (head == nullptr) {
    //  return true;
    //}

    //// 找到前半部分链表的尾节点并反转后半部分链表
    //ListNode* firstHalfEnd = endOfFirstHalf(head);
    //ListNode* secondHalfStart = reverseList(firstHalfEnd->next);

    //// 判断是否回文
    //ListNode* p1 = head;
    //ListNode* p2 = secondHalfStart;
    //bool result = true;
    //while (result && p2 != nullptr) {
    //  if (p1->val != p2->val) {
    //    result = false;
    //  }
    //  p1 = p1->next;
    //  p2 = p2->next;
    //}

    //// 还原链表并返回结果
    //// firstHalfEnd->next = reverseList(secondHalfStart);
    //return result;
  }
  


  vector<int> Solution::smallerNumbersThanCurrent(vector<int>& nums) {
    //vector<int> res;
    //int len = nums.size();
    //for (int i = 0; i < len; i++) {
    //  int s = 0;
    //  for (int j = 0; j < len; j++) {
    //    if (nums[j] < nums[i]) s++;
    //  }
    //  res.push_back(s);
    //}
    //return res;

    vector<int> cnt(101, 0);
    int n = nums.size();
    for (int i = 0; i < n; i++) {
      cnt[nums[i]]++;
    }
    for (int i = 1; i <= 100; i++) {
      cnt[i] += cnt[i - 1];
    }
    vector<int> ret;
    for (int i = 0; i < n; i++) {
      ret.push_back(nums[i] == 0 ? 0 : cnt[nums[i] - 1]);
    }
    return ret;
   }

  void dfs_preorder(TreeNode* root, vector<int>& res) {
     if (!root) {
       return;
     }
     res.push_back(root->val);
     dfs_preorder(root->left, res);
     dfs_preorder(root->right, res);
   }

   vector<int> Solution::preorderTraversal(TreeNode* root) {
     //vector<int> res;
     //dfs_preorder(root, res);
     //return res;

     vector<int> res;
     if (root == nullptr) {
       return res;
     }
     std::stack<TreeNode*> nodes;
     TreeNode* cur = root;
     while (!nodes.empty() || cur) {
       while (cur) {
         res.push_back(cur->val);
         nodes.push(cur);
         cur = cur->left;
       }
       cur = nodes.top();
       nodes.pop();
       cur = cur->right;
     }
     return res;
   }

   bool Solution::uniqueOccurrences(vector<int>& arr) {
     std::map<int, int> ret;
     std::map<int, int> cal;
     for (int i = 0; i < arr.size(); i++) {
       if (ret[arr[i]]) {
         ret[arr[i]]++;
       }
       else {
         ret[arr[i]] = 1;
       }
     }
     for (auto it : ret) {
       if (cal[it.second]) {
         return false;
       } else {
         cal[it.second] = 1;
       }
     }
     return true;
   }

   int Solution::sumNumbers(TreeNode* root) {
     if (!root) return 0;
     std::stack<std::pair<TreeNode*, int>> nodes;
     nodes.push(std::make_pair(root, root->val));
     auto res = 0;
     TreeNode* cur;
     int now;
     while (!nodes.empty()) {
       cur = nodes.top().first;
       now = nodes.top().second;
       nodes.pop();
      
       if (cur->left) 
         nodes.push(std::make_pair(cur->left, now * 10 + cur->left->val));

       if (cur->right)
         nodes.push(std::make_pair(cur->right, now * 10 + cur->right->val));

       if (!cur->left && !cur->right) res = res + now;
     }  
     return res;
   }

   int Solution::islandPerimeter(vector<vector<int>>& grid) {
     int y = grid.size();
     int a = 0, b = 0;
     for (int i = 0; i < y; i++) {
       int x = grid[i].size();
       for (int j = 0; j < x; j++) {
         if (grid[i][j] == 1) {
           ++a;
           //if ()
             if (i < y - 1 && grid [i + 1][j] == 1) ++b;
           //if ()
             if (j < x - 1 && grid [i][j + 1] == 1) ++b;
         }
       }
     }

     return a * 4 - b * 2;
   }


   vector<int> Solution::intersection(vector<int>& nums1, vector<int>& nums2) {
     std::unordered_set<int> res;
     std::vector<int> ans;
     int l1 = nums1.size();
     int l2 = nums2.size();
     for (int i = 0; i < l1; i++) {
       auto it = std::find(nums2.begin(), nums2.end(), nums1[i]);
       if (it != nums2.end()) res.emplace(nums1[i]);
     }
     ans.assign(res.begin(), res.end());
     return ans;
   }

   bool Solution::validMountainArray(vector<int>& A) {
     int N = A.size();
     int i = 0;

     while (i + 1 < N && A[i] < A[i + 1]) {
       i++;
     }

     if (i == 0 || i == N - 1) {
       return false;
     }

     while (i + 1 < N && A[i] > A[i + 1]) {
       i++;
     }

     return i == N - 1;
   }


   vector<int> Solution::sortByBits(vector<int>& arr) {
     auto count_one = [](int a) -> int {
       int cnt = 0;
       while (a) a = a & (a - 1), cnt++;
       return cnt;
     };
     sort(arr.begin(), arr.end(), [&](int a, int b) -> bool {
       int num_a = count_one(a), num_b = count_one(b);
       return num_a != num_b ? num_a < num_b : a < b;
     });
     return arr;
   }

   int Solution::maxProfit(vector<int>& prices) {
     int len = prices.size();
     int tmp;
     int ans = 0;
     if (len <= 1)
       return 0;
     else
       tmp = prices[len - 1];
     for (int i = len - 2; i >= 0; i--) {
       int cur = prices[i];
       if (cur > prices[i + 1]) {
         ans = ans + tmp - prices[i + 1];
         cout << "ans: " << ans << " , tmp: " << tmp << ", cur: " << cur
              << endl;
         tmp = cur;
       } else if (i == 0 && cur <= prices[i + 1]) {
         ans = ans + tmp - cur;
         cout << "ans222: " << ans << " , tmp: " << tmp << ", cur: " << cur
              << endl;
       }
     }
     return ans;
   }

   bool Solution::lemonadeChange(vector<int>& bills) { 
       return true;
   }

   bool isTheSameStr(string a, string b) {
     int lenA = a.size();
     int lenB = b.size();
     if (lenA != lenB) return false;
     //for (int i = 0; i < lenA; i++) {
     //  auto res = std::find(b.begin(), b.end(), a[i]);
     //  if (res == b.end()) return false;
     //}
     std::sort(b.begin(), b.end());
     std::sort(a.begin(), a.end());
     if (a == b)
       return true;
     else
       return false;
   }

   vector<vector<string>> Solution::groupAnagrams(vector<string>& strs) {
     vector<vector<string>> ans;
     std::map<string, vector<string>> res;
     int len = strs.size();
     for (int i = 0; i < len; i++) {
       //bool flag = true;
       //for (int j = 0; j < ans.size(); j++) {
       //  if (isTheSameStr(ans[j][0], strs[i])) {
       //    ans[j].emplace_back(strs[i]);
       //    flag = false;
       //  }
       //}
       //if (flag) {
       //  vector<string> x = {strs[i]};
       //  ans.emplace_back(x);
       //}
       string ori = strs[i];
       std::sort(ori.begin(), ori.end());
       res[ori].emplace_back(strs[i]);
     }
     for (auto it = res.begin(); it != res.end(); ++it) {
       ans.emplace_back(it->second);
     }
     return ans;
   }


   bool Solution::wordPattern(string pattern, string s) {
     std::stringstream ss(s); 
     string buf;
     std::map<char, string> m;
     int i = 0;
     int len = pattern.size();
     while (ss >> buf) 
     {
       std::cout << "buf: " << buf << std::endl;
       if (len < i + 1) return false;
       auto rst = m.find(pattern[i]);
       if (rst == m.end()) {
         m[pattern[i]] = buf;
       } else {
         if (rst->second != buf) return false;
       }
       i++;
     }
     std::cout << "i: " <<i << std::endl;
     if (i != len) return false;
     std::unordered_set<string> v;
     for (auto it : m) {
       v.emplace(it.second);
     }
     ss.clear();

     if (m.size() != v.size()) return false;
     else return true;

   }

   int Solution::maxProfit(vector<int>& prices, int fee) {
     //int len = prices.size();
     //int tmp;
     //int ans = 0;
     //if (len <= 1)
     //  return 0;
     //else
     //  tmp = prices[0] + fee;
     //for (int i = 1; i < len; i++) {
     //  int cur = prices[i] + fee;
     //  if (tmp > cur) {
     //    std::cout << "tmp1: " << tmp << std::endl;
     //    tmp = cur;
     //  } else if (tmp < prices[i]) {
     //    std::cout << "tmp2: " << tmp << std::endl;
     //    ans = ans + prices[i] - tmp;
     //    tmp = prices[i];
     //  }
     //}
     //return ans;

     int dp[50000][2];
     dp[0][0] = 0;
     dp[0][1] = -prices[0];
     int ans = 0;
     for (int i = 1; i < prices.size(); i++) {
       dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i] - fee);
       dp[i][1] = max(dp[i - 1][0] - prices[i], dp[i - 1][1]);
       ans = dp[i][0];
     }
     return ans;
   }
    

   char Solution::findTheDifference(string s, string t) {
     //int len1 = s.size(), len2 = t.size();
     //std::sort(s.begin(), s.end());
     //std::sort(t.begin(), t.end());
     //for (int i = 0; i < len2; i++) {
     //  if (s[i] != t[i]) return t[i];
     //}
     //return t[0];

     //int len2 = t.size();
     //int c1 = 0, c2 = 0;
     //for (int i = 0; i < len2; i++) {
     //  if (i != len2 - 1) c1 += s[i];
     //  c2 += t[i];
     //}
     //return char(c2 - c1);

     //int len2 = t.size();
     //char c1 = 0;
     //for (int i = 0; i < len2; i++) {
     //  if (i != len2 - 1) c1 += s[i];
     //  std::cout << "c1: " << char(c1) << std::endl;
     //  c1 -= t[i];
     //  std::cout << "c2: " << char(c1) << std::endl;
     //}
     //
     //return char(c1);

     int ret = 0;
     for (char ch : s) {
       ret ^= ch;
     }
     for (char ch : t) {
       ret ^= ch;
     }
     return ret;
   }

   string Solution::removeDuplicateLetters(string s) {
     //vector<std::pair<char, int>> ans;
     //char min = 'z';
     //int min_pos = 0, max_pos = 0, i = 0;
     //for (auto ch : s) {
     //  auto it = std::find_if(
     //      ans.begin(), ans.end(),
     //      [ch](std::pair<char, int> pair) {
     //        return pair.first == ch;
     //      }
     //  );

     //  if (it != ans.end()) {
     //    int dis = it->second;  // std::distance(ans.begin(), it);
     //    if (min < ch) {
     //      if (dis < min_pos) {
     //        ans.erase(it);
     //        ans.emplace_back(std::make_pair(ch, i));
     //      }
     //    } 
     //  } else ans.emplace_back(std::make_pair(ch, i));
     //  
     //  if (ch <= min) {
     //    min = ch;
     //    min_pos = i;
     //  }

     //  ++i;
     //}
     //string res;
     //for (auto ch : ans) {
     //  res.push_back(ch.first);
     //}
     //return res;
     vector<int> vis(26), num(26);
     for (char ch : s) {
       num[ch - 'a']++;
     }

     string stk;
     for (char ch : s) {
       if (!vis[ch - 'a']) {
         while (!stk.empty() && stk.back() > ch) {
           if (num[stk.back() - 'a'] > 0) {
             vis[stk.back() - 'a'] = 0;
             stk.pop_back();
           } else {
             break;
           }
         }
         vis[ch - 'a'] = 1;
         stk.push_back(ch);
       }
       num[ch - 'a'] -= 1;
     }
     return stk;
   }

   void Solution::rotate(vector<vector<int>>& matrix) {
     int len = matrix.size();
     int n = len / 2;
     for (int i = 0; i < n; i++) {
       for (int j = 0; j < (len + 1) / 2; j++) {
         int tmp = matrix[i][j];
         matrix[i][j] = matrix[len - 1 - j][i];
         matrix[len - 1 - j][i] = matrix[len - 1 - i][len - 1 - j];
         matrix[len - 1 - i][len - 1 - j] = matrix[j][len - 1 - i];
         matrix[j][len - 1 - i] = tmp;
       }
     }
   }

   //动态规划
   int Solution::minCostClimbingStairs(vector<int>& cost) {
     int* dp = new int[cost.size() + 1];
     dp[0] = dp[1] = 0;
     int i, ans;
     for (i = 2; i <= cost.size(); i++) {
       dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
       std::cout << "first: " << dp[i - 1] + cost[i - 1]
                 << "; second: " << dp[i - 2] + cost[i - 2] <<
           "; i: " << i << std::endl;
       ans = dp[i];
     }
     return ans;
    }

   bool is_increase(int n) {
      int j = 2;
     int tmp = n % 10;
      if (n < 10) return true;
      //std::cout << "n: " << n << std::endl;
      while (1) {
        int x = n % (int)pow(10, j);
        //std::cout << "x: " << x / (int)pow(10, j - 1)  << ", tmp: " << tmp << std::endl;

        if ((x / (int)pow(10, j - 1)) < tmp)
          tmp = (x / (int)pow(10, j - 1));
        else
          return false;
        if (x == n) break;
        j++;
      }
      return true;
    }

   int Solution::monotoneIncreasingDigits(int N) { 
     if (N < 10) return N;
     string strN = std::to_string(N);
     int i = 1;
     while (i < strN.size() && strN[i - 1] <= strN[i])  i++;
     if (i < strN.size()) {
       while (i > 0 && strN[i - 1] > strN[i]) {
         strN[i - 1]--;
         i--;
       }
       for (++i; i < strN.size(); ++i) strN[i] = '9';
     }

     return std::stoi(strN);
   }


   int Solution::maxSubArray(vector<int>& nums) {
     int len = nums.size();
     if (len == 1) return nums[0];
     int x, y;
     x = max(nums[1], nums[0] + nums[1]);
     y = nums[0];
     int i;
     for (i = 2; i < len; i++) {
       y = max(x, y);
       x = max(x + nums[i], nums[i]);
     }
     return max(x, y);
   }

   vector<vector<int>> Solution::zigzagLevelOrder(TreeNode* root) {
     if (!root) return {};
     vector<vector<int>> ans;
     std::list<TreeNode*> qu;
     qu.emplace_back(root);
     bool flag = true;
     while (!qu.empty()) {
       int len = qu.size();
       std::list<int> tmp;
       for (int i = 0; i < len; i++) {
         auto front = qu.front();
         qu.pop_front();
     
         if (flag) tmp.emplace_back(front->val);
         else tmp.emplace_front(front->val);
         if (front->left) {
           qu.emplace_back(front->left);
         }
         if (front->right) {
           qu.emplace_back(front->right);
         }

       }
       ans.emplace_back(vector<int>{tmp.begin(), tmp.end()});
       flag = !flag;
     }

     return ans;
   }


   int Solution::uniquePaths(int m, int n) {
     //int dp[100][100];
     //for (int i = 0; i < m; i++) {
     //  dp[i][0] = 1;
     //}
     //for (int i = 0; i < n; i++) {
     //  dp[0][i] = 1;
     //}
     //for (int i = 1; i < m; i++) {
     //  for (int j = 1; j < n; j++) {
     //    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
     //  }
     //}
     //return dp[m - 1][n - 1];

     int dp[100];
     for (int i = 0; i < m; i++) {
       dp[i] = 1;
     }

     for (int i = 1; i < m; i++) {
       for (int j = 1; j < n; j++) {
         dp[j] = dp[j] + dp[j - 1];
       }
     }
     return dp[m - 1];
   }

   int Solution::firstUniqChar(string s) {
     std::unordered_map<char, int> char_map;
     for (int i = 0; i < s.size(); i++) {
       char_map[s[i]]++;
     }

     for (int i = 0; i < s.size(); i++) {
       if (char_map[s[i]] == 1) return i;
     }
     return -1;
   }

   int Solution::minPathSum(vector<vector<int>>& grid) {
     int m = grid.size();
     int n = grid[0].size();
     int dp[200];
     dp[0] = grid[0][0];
     for (int i = 0; i < m; ++i) {
       for (int j = 0; j < n; ++j) {
         std::cout << "dp[j] before: " << dp[j]
                   << ", grid[j][i]: " << grid[i][j]
                   << ", j: " << j
                   << std::endl;
         if (i == 0 && j > 0) dp[j] = grid[0][j] + dp[j - 1];
         if (i > 0) {
           if (j == 0) dp[j] = dp[j] + grid[i][j];
           else dp[j] = min(dp[j], dp[j - 1]) + grid[i][j];
         }
         std::cout << "dp[j]: " << dp[j] << std::endl;
       }
     }
     return dp[n - 1];
   }

   int Solution::minDistance(string word1, string word2) {
     int x = word1.size();
     int y = word2.size();
     int dp[500], pre, tmp;
     //for (int i = 0; i <= x; ++i) {
     //  dp[i] = i;
     //}

     for (int i = 0; i <= y; ++i) {
       if (i > 0) {
         tmp = dp[0];
         dp[0] = i;
       }
       for (int j = 0; j <= x; ++j) {
         if (i == 0) dp[j] = j;
         else if(j != 0){
           pre = tmp;
           tmp = dp[j];
           if (word2[i - 1] == word1[j - 1])
             dp[j] = pre;
           else
             dp[j] = std::min(min(dp[j - 1], dp[j]), pre) + 1;
         }
       }
     }
     return dp[x];
   }

   int Solution::candy(vector<int>& ratings) {
     //int* can = new int[ratings.size() + 1];
     //int min = 1, pre = 1;
     //can[0] = 1;
     //for (int i = 1; i < ratings.size(); ++i) {
     //  if (ratings[i] > ratings[i - 1])
     //    pre = pre + 1;
     //  //else if (ratings[i] < ratings[i - 1])
     //  //  pre = pre - 1;
     //  else {
     //    if (pre - 1 <= 0 && pre - 1 < min) 
     //      if (can[i - 1] + pre - 1 + ratings.size() * (1 - (pre - 1)) <
     //          can[i - 1] + pre + ratings.size() * (1 - min))
     //        pre = pre - 1;
     //    else
     //      pre = pre - 1;
     //  }
     //  can[i] = can[i - 1] + pre;
     //  if (pre <= 0 && pre < min) min = pre;
     //}
     //return can[ratings.size() - 1] + (ratings.size() * (1 - min));

    //int len = ratings.size(), right = 0, ans = 0;
    // int* left = new int[len]; 
    // for (int i = 0; i < len; ++i) {
    //   if (i > 0 && ratings[i] > ratings[i - 1]) {
    //     left[i] = left[i - 1] + 1;
    //   } else {
    //     left[i] = 1;
    //   }
    // }

    // for (int i = len - 1; i >= 0; --i) {
    //   if (i < len - 1 && ratings[i] > ratings[i + 1]) {
    //     right++;
    //   } else
    //     right = 1;
    //   ans += max(left[i], right);
    // }
    // return ans;

     vector<int> candyVec(ratings.size(), 1);
     int result = 0;
     for (int i = 1; i < ratings.size(); i++) {
       if (ratings[i] > ratings[i - 1]) candyVec[i] = candyVec[i - 1] + 1;
     }

     for (int i = ratings.size() - 2; i >= 0; i--) {
       if (ratings[i] > ratings[i + 1]) {
         candyVec[i] = max(candyVec[i], candyVec[i + 1] + 1);
       }
       result += candyVec[i];
     }

     return result + candyVec[ratings.size() - 1];

   }

   bool Solution::isValid(string s) {
     //int len = s.size();
     //std::stack<char> st;
     //for (int i = 0; i < len; ++i) {
     //  if (s[i] == '{' || s[i] == '(' || s[i] == '[') {
     //    st.push(s[i]);
     //  } else if (s[i] == '}') {
     //    if (st.empty()) return false;
     //    if (st.top() == '{')
     //      st.pop();
     //    else
     //      return false;
     //  } else if (s[i] == ')') {
     //    if (st.empty()) return false;
     //    if (st.top() == '(')
     //      st.pop();
     //    else
     //      return false;
     //  } else if (s[i] == ']') {
     //    if (st.empty()) return false;
     //    if (st.top() == '[')
     //      st.pop();
     //    else
     //      return false;
     //  }
     //}
     //if (st.empty())
     //  return true;
     //else
     //  return false;

     int len = s.size();
     std::stack<char> st;
     for (int i = 0; i < len; ++i) {
       if (s[i] == '[')
         st.push(']');
       else if (s[i] == '(')
         st.push(')');
       else if (s[i] == '{')
         st.push('}');
       else if (st.empty() || s[i] != st.top())
         return false;
       else if (!st.empty() || s[i] == st.top())
         st.pop();
     }
     return st.empty();
   }

   ListNode* Solution::mergeTwoLists(ListNode* l1, ListNode* l2) {
     ListNode* tmp = new ListNode(-1);
     ListNode* ans = tmp;

     while (l1 && l2) {
       if (l1->val > l2->val) {
         tmp->next = l2;
         l2 = l2->next;
       } else {
         tmp->next = l1;
         l1 = l1->next;
       }
       tmp = tmp->next;
     }
     tmp->next = l1 == nullptr ? l2 : l1;
     return ans->next;
   }


   bool Solution::isMatch(string s, string p) {
     int x = s.size();
     int y = p.size();
     vector<vector<bool>> dp(x + 1, vector<bool>(y + 1, false));
     dp[0][0] = true;
     for (int i = 0; i <= x; ++i) {
       for (int j = 1; j <= y; ++j) {
         if (p[j - 1] == '*' && j > 1) {
           dp[i][j] =
               dp[i][j - 2] || (i > 0 && (p[j - 2] == '.' || p[j - 2] == s[i - 1]) &&
                                (dp[i - 1][j - 2] || dp[i - 1][j]));
         } else {
           dp[i][j] = i > 0 && dp[i - 1][j - 1] && (p[j - 1] == '.' || p[j - 1] == s[i - 1]);
         }
       }
     }
     return dp[x][y];
   }


   int Solution::maxDepth(TreeNode* root) {
     if (!root) return 0;
     std::deque<TreeNode*> st;
     st.push_back(root);
     int ans = 0;
     TreeNode* tmp;
     while (!st.empty()) {
       int len = st.size();
       for (int i = 0; i < len; ++i) {
         tmp = st.back();
         st.pop_back();
         if (tmp->left) st.push_front(tmp->left);
         if (tmp->right) st.push_front(tmp->right);
       }
       ++ans;
     }
     return ans;
   }

   bool Solution::isSymmetric(TreeNode* root) {
     if (!root) return true;
     std::deque<TreeNode*> qu;
     qu.push_back(root);
     while (!qu.empty()) {
       int len = qu.size();
       for (int i = 0; i < len / 2; ++i) {
         auto front = qu.front();
         qu.pop_front();
         auto back = qu.front();
         qu.pop_front();
         if (front->val != back->val) {
           return false;
         }

         if (front->left && back->right) {
           qu.push_back(front->left);
           qu.push_back(back->right);
         }
         if (front->right && back->left) {
           qu.push_back(front->right);
           qu.push_back(back->left);
         }
         if ((front->left && !back->right) || (front->right && !back->left) ||
             (!front->left && back->right) || (!front->right && back->left)) {
           return false;
         }
       }
       if (len % 2 != 0) {
         auto fin = qu.front();
         qu.pop_front();
         if (fin->left && fin->right) {
           qu.push_back(fin->right);
           qu.push_back(fin->left);
         } else if (!fin->left && !fin->right) {
           return true;
         } else {
           return false;
         }
       }
     }

     return true;
   }

   int Solution::singleNumber(vector<int>& nums) {
     int len = nums.size();
     std::unordered_map<int, int> m;
     for (int i = 0; i < nums.size(); ++i) {
       if (++m[nums[i]] > 1) m.erase(nums[i]);
     }
     for (auto it : m) {
       if (it.second == 1) return it.first;
     }
     m.begin()->first;
     return nums[0];
   }

   int Solution::findContentChildren(vector<int>& g, vector<int>& s) {
     std::sort(g.begin(), g.end());
     std::sort(s.begin(), s.end());
     int i = 0, j = 0;
     while (i < g.size() && j < s.size()) {
       if (g[i] <= s[j]) {
         ++i;
       }
       ++j;

     }
     return i;
   }

   int Solution::maxProfit1(vector<int>& prices) {
     int len = prices.size();
     if (len <= 1) return 0;
     int tmp = prices[0], ans = 0;
     for (int i = 1; i < len; i++) {
       if (tmp > prices[i]) tmp = prices[i];
       if (prices[i] - tmp > ans) ans = prices[i] - tmp;
     }
     return tmp;
   }

   ListNode* Solution::getIntersectionNode(ListNode* headA, ListNode* headB) {
     //if (!headA || !headB) return nullptr;
     //std::stack<ListNode*> nodes1;
     //std::stack<ListNode*> nodes2;
     //while (headA || headB) {
     //  if (headA) {
     //    nodes1.push(headA);
     //    headA = headA->next;
     //  }
     //  if (headB) {
     //    nodes2.push(headB);
     //    headB = headB->next;
     //  }
     //}

     //ListNode* tmp = nullptr;
     //if (nodes1.size() == 1 && nodes2.size() == 1 &&
     //    nodes1.top() == nodes2.top())
     //  return nodes1.top();
     //while (!nodes1.empty() && !nodes2.empty()) {
     //  if (nodes1.top() != nodes2.top()) {
     //    if (!tmp) {
     //      return nullptr;
     //    } else {
     //      return tmp;
     //    }
     //  } else {
     //    tmp = nodes1.top();
     //    nodes1.pop();
     //    nodes2.pop();
     //  }
     //}
     //return tmp;

     //if (!headA || !headB) return nullptr;
     //std::vector<ListNode*> nodes1;
     //while (headA || headB) {
     //  if (headA) {
     //    nodes1.emplace_back(headA);
     //    headA = headA->next;
     //  }
     //}

     //while (headB) {
     //  int len = nodes1.size();
     //  for (int i = 0; i < len; ++i) {
     //    if (headB == nodes1[i]) return headB;
     //  }
     //}
     //return nullptr;

     if (!headA || !headB) return nullptr;
     ListNode *tmp1 = headA, *tmp2 = headB;
     while (tmp1 != tmp2) {
       tmp1 = (tmp1 != nullptr ? tmp1->next : headB);
       tmp2 = (tmp2 != nullptr ? tmp2->next : headA);
     }
     return tmp1;
   }

   int Solution::majorityElement(vector<int>& nums) {
     int len = nums.size();
     int ans;
     std::unordered_map<int, int> m;
     for (int i = 0; i < len; ++i) {
       if (++m[nums[i]] >= len / 2) {
         return nums[i];
       }
     }
     return -1;
   }

   ListNode* Solution::reverseList(ListNode* head) {
     //ListNode* new_head = nullptr;
     //while (head) {
     //  auto tmp = new ListNode(head->val);
     //  tmp->next = new_head;
     //  new_head = tmp;
     //  head = head->next;
     //}
     //return new_head;
     ListNode *tmp = nullptr, *pre = nullptr;
     while (head) {
       tmp = head;
       head = head->next;
       tmp->next = pre;
       pre = tmp;
     }
     return tmp;
   }

   int Solution::rob(vector<int>& nums) {
     int len = nums.size();
     if (len < 1) return 0;
     int pre1 = 0, pre2 = nums[0], tmp;
     for (int i = 1; i < len; ++i) {
       tmp = pre1;
       pre1 = max(pre1, pre2);
       pre2 = tmp + nums[i];
     }
     return max(pre1, pre2);
   }

   void Solution::moveZeroes(vector<int>& nums) {
     //vector<int> ans;
     //int cnt = 0;
     //for (auto it : nums) {
     //  if (it == 0)
     //    ++cnt;
     //  else
     //    ans.emplace_back(it);
     //}
     //for (int i = 0; i < cnt; ++i) {
     //  ans.emplace_back(0);
     //}
     //nums = ans;

     int indexNow = 0;
     int indexNum = 0;
     while(indexNow < nums.size()) {
       if (nums[indexNum] != 0) {
         nums[indexNow++] = nums[indexNum];
       }
       ++indexNum;

     }
     for (int i = indexNow; i < nums.size(); i++) {
       nums[i] = 0;
     }
   }

   int Solution::hammingDistance(int x, int y) {
     auto rst = x ^ y;
     int cnt = 0;
     while (rst > 1) {
       int tmp = rst % 2;
       rst = rst / 2;
       if (tmp == 1) cnt++;
     }
     return cnt;
   }

   vector<int> Solution::findDisappearedNumbers(vector<int>& nums) {
     //std::unordered_map<int, int> m;
     //vector<int> ans;
     //for (int i = 0; i < nums.size(); ++i) {
     //  m[nums[i]]++;
     //}
     //for (int i = 0; i < nums.size(); ++i) {
     //  if (m[i + 1] == 0) ans.emplace_back(i + 1);
     //}
     //return ans;
     vector<int> ans;
     for (int i = 0; i < nums.size(); ++i) {
       nums[abs(nums[i]) - 1] = abs(nums[abs(nums[i]) - 1]) * -1;
     }
     for (int i = 0; i < nums.size(); ++i) {
       if (nums[i] > 0) ans.emplace_back(i + 1);
     }
     return ans;
   }

   int Solution::diameterOfBinaryTree(TreeNode* root) {
     int a = 0, b = 0;
     if (root->left) a = maxDepth(root->left);
     if (root->right) b = maxDepth(root->right);
     return a + b + 2;
   }

   int Solution::maxProfit(int k, vector<int>& prices) {
     int len = prices.size();
     if (len < 2) return 0;
     //   k = min(k, len / 2);
     vector<vector<vector<int>>> dp(
         len, vector<vector<int>>(k + 1, vector<int>(2, 0)));
     int ans = 0, r = 0, tmp;

     dp[0][0][1] = -prices[0];
     dp[0][0][0] = 0;
     for (int i = 0; i < len; ++i) {
       if (i != 0)
         dp[i][0][1] = max(dp[i - 1][0][1], dp[i - 1][0][0] - prices[i]);
       for (int j = 1; j <= k; ++j) {
         if (i == 0)
           dp[i][j][0] = dp[i][j][1] = INT_MIN / 2;
         else {
           //    tmp = dp[i][j][0];
           dp[i][j][0] = max(dp[i - 1][j - 1][1] + prices[i], dp[i - 1][j][0]);
           dp[i][j][1] = max(dp[i - 1][j][0] - prices[i], dp[i - 1][j][1]);
           if (dp[i][j][0] > ans) {
             ans = dp[i][j][0];
             r = i;
           }
         }
       }
     }
     //  std::cout << "ans: " << ans << ", r: " << r << std::endl;
     return ans;
   }

   int Solution::lengthOfLongestSubstring(string s) {
     int len = s.size();
     if (len < 2) return len;
     std::unordered_set<char> char_set;
     int ans = 0, left = 0;
     for (int i = 0; i < len; ++i) {
       while (char_set.find(s[i]) != char_set.end()) {
         char_set.erase(s[left]);
         left++;
       }
       ans = max(ans, len + 1 - left);
       char_set.emplace(s[i]);
     }
     return ans;
   }

   int lastStoneWeight(vector<int>& stones) {
     std::priority_queue<int> q;
     for (auto it : stones) {
       q.push(it);
     }
     while (q.size() > 1) {

       auto it1 = q.top();
       q.pop();
       auto it2 = q.top();
       q.pop();
       
       if (it1 > it2) {
         q.push(it1 - it2);
       }
     }
     return q.empty() ? 0 : q.top();
   }

   vector<int> maxSlidingWindow(vector<int>& nums, int k) {
     int len = nums.size();
     vector<int> ans;
     std::priority_queue<std::pair<int, int>> qu;
     for (int i = 0; i < k; ++i) {
       qu.emplace(nums[i], i);
     }

     ans.push_back(qu.top().first);
     for (int i = k; i < len; ++i) {
       qu.emplace(nums[i], i);
       while (qu.top().second < i - k) {
         qu.pop();
       }
       ans.emplace_back(qu.top().first);
     }
     return ans;
   }

   string longestPalindrome(string s) {
     int len = s.size();
     if (len == 0) return "";
     if (len == 1) return s;
     vector<vector<int>> dp(len, vector<int>(len));
     string ans;
     int j;
     for (int k = 0; k < len; ++k) {
       for (int i = 0; i + k < len; ++i) {
         j = i + k;
         if (k == 0)
           dp[i][j] = 1;
         else if (k == 1) {
           dp[i][j] = (s[i] == s[j]);
         } else {
           dp[i][j] = dp[i + 1][j - 1] && (s[i] == s[j]);
         }

         if (ans.size() < k + 1 && dp[i][j]) ans = s.substr(i, k + 1);
         //  cout << "i: " << i << ", j: " << j << " , dp[i][j]: " << dp[i][j]
         //       << " , ans: " << ans << endl;
       }
     }
     return ans;
   }

   int fib(int n) {
     if (n < 2) return n;
     int a = 0, b = 1, s;
     for (int i = 1; i < n; ++i) {
       s = b;
       b = a + b;
       a = s;
     }
     return b;
   }

   vector<vector<int>> largeGroupPositions(string s) {
     int len = s.size();
     int cnt = 0, start, end;
     vector<vector<int>> ans;
     for (int i = 0; i < len; ++i) {
       if (i = 0) {
         start = end = 0;
         cnt = 1;
       } else {
         if (s[i] != s[i - 1]) {
           if (end - start + 1 >= 3) {
             ans.emplace_back(vector<int>{start, end});
           }
           start = end = i;
           cnt = 1;
         } else {
           end = i;
           cnt++;
         
         }
       }
     }

     return ans;
   }

   vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
     //int len = queries.size();
     //int n = equations.size();
     //vector<double> ans;
     //std::unordered_set<string> se;
     //for (int i = 0; i < n; ++i) {
     //  se.emplace(equations[i][0]);
     //  se.emplace(equations[i][1]);
     //}
     //for (int i = 0; i < len; ++i) {
     //  std::unordered_map<std::pair<string, string>, int> m;
     //  int j = 0;
     //  string a = queries[i][0];
     //  string b = queries[i][1];
     //  while (j < n) {
     //    string x = equations[j][0];
     //    string y = equations[j][1];
     //    if (se.find(a) == se.end() || se.find(b) == se.end()) {
     //      ans.emplace_back((double)-1.0);
     //      break;
     //    }
     //    if (a == b) {
     //      ans.emplace_back((double)1.0);
     //      break;
     //    }
     //    if (a == x && b == y) {
     //      ans.emplace_back(values[i]);
     //      break;
     //    }
     //    if (a == y && b == x) {
     //      ans.emplace_back(1 / values[i]);
     //      break;
     //    }
     //    if (a == x) {
     //      if (m.find(std::make_pair(b, y)) != m.end()) {
     //        ans.emplace_back(values[i] / values[m[std::make_pair(b, y)]]);
     //        break;
     //      } else if (m.find(std::make_pair(y, b)) != m.end()) {
     //        ans.emplace_back(values[i] * values[m[std::make_pair(y, b)]]);
     //        break;
     //      }
     //    }
     //    if (a == y) {
     //      if (m.find(std::make_pair(b, x)) != m.end()) {
     //        ans.emplace_back(1 / (values[i] * values[m[std::make_pair(b, x)]]));
     //        break;
     //      } else if (m.find(std::make_pair(x, b)) != m.end()) {
     //        ans.emplace_back(values[m[std::make_pair(x, b)]] / values[i]);
     //        break;
     //      }
     //    }
     //    if (b == x) {
     //      if (m.find(std::make_pair(a, y)) != m.end()) {
     //        ans.emplace_back(values[m[std::make_pair(a, y)]] / values[i]);
     //        break;
     //      } else if (m.find(std::make_pair(y, a)) != m.end()) {
     //        ans.emplace_back(values[i] * values[m[std::make_pair(y, a)]]);
     //        break;
     //      }
     //    }
     //    if (b == y) {
     //      if (m.find(std::make_pair(a, x)) != m.end()) {
     //        ans.emplace_back(values[i] * values[m[std::make_pair(a, x)]]);
     //        break;
     //      } else if (m.find(std::make_pair(x, a)) != m.end()) {
     //        ans.emplace_back(values[m[std::make_pair(x, a)]] / values[i]);
     //        break;
     //      }
     //    }
     //    m[std::make_pair(x, y)] = j;
     //    if (j == n - 1) ans.emplace_back((double)-1.0);
     //    ++j;
     //  }
     //}
     //return ans;
     int nvars = 0;
     std::unordered_map<string, int> variables;

     int n = equations.size();
     for (int i = 0; i < n; i++) {
       if (variables.find(equations[i][0]) == variables.end()) {
         variables[equations[i][0]] = nvars++;
       }
       if (variables.find(equations[i][1]) == variables.end()) {
         variables[equations[i][1]] = nvars++;
       }
     }
     vector<vector<double>> graph(nvars, vector<double>(nvars, -1.0));
     for (int i = 0; i < n; i++) {
       int va = variables[equations[i][0]], vb = variables[equations[i][1]];
       graph[va][vb] = values[i];
       graph[vb][va] = 1.0 / values[i];
     }

     for (int k = 0; k < nvars; k++) {
       for (int i = 0; i < nvars; i++) {
         for (int j = 0; j < nvars; j++) {
           if (graph[i][k] > 0 && graph[k][j] > 0) {
             graph[i][j] = graph[i][k] * graph[k][j];
           }
         }
       }
     }

     vector<double> ret;
     for (const auto& q : queries) {
       double result = -1.0;
       if (variables.find(q[0]) != variables.end() &&
           variables.find(q[1]) != variables.end()) {
         int ia = variables[q[0]], ib = variables[q[1]];
         if (graph[ia][ib] > 0) {
           result = graph[ia][ib];
         }
       }
       ret.push_back(result);
     }
     return ret;
    }

    int maxArea(vector<int>& height) {
      int len = height.size();
      int ans = 0;
      int i = 0, j = len - 1;
      while (i != j) {
        ans = max(ans, min(height[i], height[j]) * (j - i));
        if (height[i] > height[j]) ++i;
        else ++j;
      }
      return ans;
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
      int len = isConnected.size();
      vector<int> is_vi(len, 0);
      std::queue<int> qu;
      int ans = 0;
      for (int i = 0; i < len; ++i) {
        if (!is_vi[i]) {
          qu.push(i);
          while (!qu.empty()) {
            int x = qu.front();
            qu.pop();
            is_vi[x] = 1;
            for (int j = 0; j < len; ++j) {
              if (isConnected[x][j] == 1 && !is_vi[j]) qu.push(j);
            }
          }
          ans++;
        }
      }
      return ans;
    }

    void rotate(vector<int>& nums, int k) {
      //vector<int> tmp;
      //int len = nums.size();
      //for (int i = len - k; i < len; ++i) {
      //  tmp.emplace_back(nums[i]);
      //}
      //for (int i = 0; i < len - k; ++i) {
      //  tmp.emplace_back(nums[i]);
      //}
      //nums = tmp;

      int len = nums.size();
      int tmp;
      k = k / len;
      for (int i = 0; i < k; i++) {
        int n = len / k;
        if (i < len % k) n++;
        for (int j = 0; j < n; j++) {
          int tmp = nums[j * k + i];
          if (j == 0) nums[j * k + i] = nums[(n - 1) * k + i];
          else if(j == n - 1);
          else nums[j * k + i] = tmp;
        }
      }
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
      int len = nums.size();
      vector<vector<int>> ans;
      std::sort(nums.begin(), nums.end());

      for (int i = 0; i < len; i++) {
        int j = i + 1, k = len - 1;
        if (i >= 1 && nums[i] == nums[i - 1]) continue;
        for (; j < len; j++) {
          if (j > i + 1 && nums[j] == nums[j - 1]) continue;
          while (k > j && nums[k] + nums[j] > -nums[i]) k--;
          if (nums[k] + nums[j] == -nums[i])
            ans.emplace_back(vector<int>{i, j, k});
          if (j == k) break;
        }
      }
      return ans;
    }

    int maxProfit3(vector<int>& prices) {
      int len = prices.size();
      if (len < 2) return 0;
      int ans;
      vector<vector<int>> dp1(len, vector<int>(3, 0)); // i天拥有
      vector<vector<int>> dp2(len, vector<int>(3, 0)); // i天不拥有
      dp1[0][0] = -prices[0];
      dp2[0][0] = 0;
      for (int i = 0; i < len; i++) {
        if (i != 0) dp1[i][0] = max(dp1[i - 1][0], dp2[i - 1][0] - prices[i]);
        for (int j = 1; j <= 2; j++) {
          if (i == 0)
            dp1[i][j] = dp2[i][j] = INT_MIN / 2;
          else {
              dp1[i][j] = max(dp2[i - 1][j] - prices[i], dp1[i - 1][j]);
              dp2[i][j] = max(dp1[i - 1][j - 1] + prices[i], dp2[i - 1][j]);  
          }
        }
      }
      return max(dp2[len - 1][0] , dp2[len - 1][1], dp2[len - 1][2]);
    }

    string tmp_combination;
    vector<string> d_map = {"abc", "def",  "ghi", "jkl",
                            "mno", "pqrs", "tuv", "wxyz"};
    vector<string> ans_combination;
    void dfs_combination(string digits, int index) {
      if (digits.size() == index) {
        ans_combination.push_back(tmp_combination);
        return;
      }
      for (auto it : d_map[digits[index] - '2']) {
        tmp_combination.push_back(it);
        dfs_combination(digits, index + 1);
        tmp_combination.pop_back();
      }
    }

    vector<string> letterCombinations(string digits) {
      if (digits.size() == 0) return ans_combination;
      dfs_combination(digits, 0);
      return ans_combination;
    }

    vector<string> summaryRanges(vector<int>& nums) {
      //int len = nums.size();
      //if (len == 0) return {};
      //if (len == 1) return {std::to_string(nums[0])};
      //vector<string> ans;
      //int start = nums[0], end = nums[0];
      //string tmp;
      //for (int i = 1; i < len; i++) {
      //  if (nums[i] != nums[i - 1] + 1) {
      //    if (start != end) {
      //      tmp = std::to_string(start) + "->" + std::to_string(end);
      //      ans.push_back(tmp);
      //    } else
      //      ans.push_back(std::to_string(start));
      //    start = nums[i];
      //  }
      //  end = nums[i];
      //  if (i == len - 1) {
      //    if (start != end) {
      //      tmp = std::to_string(start) + "->" + std::to_string(end);
      //      ans.push_back(tmp);
      //    } else
      //      ans.push_back(std::to_string(start));
      //  }
      //}
      //return ans;

      vector<string> ans;
      int left = 0;
      for (int i = 0; i < nums.size(); ++i) {
        if (i + 1 == nums.size() || nums[i] + 1 != nums[i + 1]) {
          ans.push_back(std::to_string(nums[left]) +
                        (left == i ? "" : "->" + std::to_string(nums[i])));
          left = i + 1;
        }
      }
      return ans;
    }

    vector<string> ans;

    void dfs_genPa(string s, int left, int right) {
      if (left == 0 && right == 0) {
        ans.emplace_back(s);
        return;
      }
      if (left < 0 || right < left) return;
      dfs_genPa(s + "(", left - 1, right);
      dfs_genPa(s + ")", left, right - 1);

      //if (left == right) {
      //  dfs_genPa(s + "(", left - 1, right);
      //} else {
      //  if (left > 0)
      //    dfs_genPa(s + "(", left - 1, right);
      //  else
      //    dfs_genPa(s + ")", left, right - 1);
      //}
    }

    vector<string> generateParenthesis(int n) {
      //string tmp;
      //if (n == 0) return ans;
      //dfs_genPa("", n, n);
      //return ans;
      if (n == 0) return {};
      if (n == 1) return {"()"};
      vector<vector<string>> dp(n + 1);
      for (int i = 2; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
          for (auto x : dp[j]) {
            for (auto y : dp[i - j - 1]) {
              ans.emplace_back("(" + x + ")" + y);
            }
          }
        }
      }
      return ans;
    }

    void nextPermutation(vector<int>& nums) {
        int len = nums.size();
        int i, j, tmp_min;
        for (i = len - 2; i >= 0; --i) {
          if (nums[i] < nums[i + 1]) break;
        }
        if (i == -1) {
          std::reverse(nums.begin(), nums.end());
          return;
        }
        for (j = len - 1; j > i; --j) {
          if (nums[j] > nums[i]) break;
        }
        std::swap(nums[i], nums[j]);
        std::sort(nums.begin() + i + 1, nums.end());
    }

    vector<vector<int>> ans_permute;
    vector<bool> status_permute;
    void dfs_permute(vector<int> s, vector<int>& nums, int len) {
      if (s.size() == len) {
        ans.emplace_back(s);
        return;
      }

      for (int i = 0; i < len; i++) {
        if (!status_permute[i]) {
          status_permute[i] = true;
          s.push_back(nums[i]);
          dfs_permute(s, nums, len);
          s.pop_back();
          status_permute[i] = false;
        }
      }
    }

    vector<vector<int>> permute(vector<int>& nums) {
      int len = nums.size();
      status_permute = vector<bool>(len, false);
      return ans_permute;
    }


    //并查集解决 1202. 交换字符串中的元素
    int* fa, *rank;
    void init_1202(int n) {
      for (int i = 0; i < n; i++) {
        fa[i] = i;
        rank[i] = 1;
      }
    }

    int find_1202(int x) {
        return x == fa[x] ? x : (fa[x] = find_1202(fa[x]));
    }

    void merge_1202(int i, int j) {
        //fa[find_1202(i)] = find_1202(j);
      int x = find_1202(i), y = find_1202(j);
      if (rank[x] <= rank[y])
        fa[x] = y;
      else
        fa[y] = x;
      if (rank[x] == rank[y] && x != y) rank[y]++;
    }

    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
      int len = s.size();
      fa = new int[len];
      rank = new int[len];
      init_1202(len);
      for (auto it : pairs) merge_1202(it[0], it[1]);
      std::unordered_map<int, vector<int>> m;
      for (int i = 0; i < len; i++) m[find_1202(i)].emplace_back(i);
      for (auto it : m) {
        string tmp;
        for (auto j : it.second) tmp.push_back(s[j]);
        std::sort(tmp.begin(), tmp.end());
        for (int j = 0; j < tmp.size(); j++) {
          s[it.second[j]] = tmp[j];
        }
      }
      return s;
    }

    //todo : 用单调栈做
    vector<int> dailyTemperatures(vector<int>& T) {
      int len = T.size();
      vector<int> ans(len, 0);
      for (int i = 0; i < len - 1; i++) {
        int j;
        for (j = i + 1; j < len; j++) {
          if (T[j] > T[i]) {
            ans[i] = j - i;
            break;
          }
        }
      }
      
      return ans;
    }

    
    int largestRectangleArea(vector<int>& heights) {
      //std::stack<int> st;
      //int len = heights.size(), ans = 0;
      //vector<int> left(len), right(len, len);
      //for (int i = 0; i < len; i++) {
      //  while (!st.empty() && heights[st.top()] >= heights[i]) {
      //    right[st.top()] = i;
      //    st.pop();
      //  }
      //  left[i] = st.empty() ? -1 : st.top();
      //  st.push(i);
      //}
      //for (int i = 0; i < len; i++) {
      //  ans = max(ans, (right[i] - left[i] - 1) * heights[i]);
      //}

      //return ans;

        //单调栈
      std::stack<int> st;
      int len = heights.size(), ans = 0;
      if (len == 1) return heights[0];
      for (int i = 0; i <= len; i++) {
        while ((i == len && !st.empty()) || (!st.empty() && heights[st.top()] >= heights[i]) ) {  
          int h = heights[st.top()];
          st.pop();
          ans = max(ans, (i - (st.empty() ? 0 : st.top() + 1)) * h);
        }
        st.push(i);
      }
      return ans;
    }

    int trap(vector<int>& height) {

      //记录每个点左最大和右最大
      //int len = height.size(), ans = 0;
      //if (len == 0) return 0;
      //vector<int> left(len, 0), right(len, 0);
      //left[0] = height[0];
      //right[len - 1] = height[len - 1];
      //for (int i = 1; i < len; i++) {
      //  left[i] = max(left[i - 1], height[i]);
      //  right[len - i - 1] = max(right[len - i], height[len - i - 1]);
      //}
      //for (int i = 0; i < len; i++) {
      //  ans += min(left[i], right[i]) - height[i];
      //}
      //return ans;

      //单调栈
      int len = height.size(), ans = 0;
      if (len < 2) return 0;
      std::stack<int> st;
      for (int i = 0; i < len; i++) {
        while (!st.empty() && st.top() < height[i]) {
          int h0 = height[st.top()];
          st.pop();
          ans = ans + (min(height[i], height[st.top()]) - h0) * (i - st.top() - 1);
        }
        st.push(i);
      }
      return 0;
    }

    int* fa;
    void init(int n) {
      for (int i = 1; i <= n; i++) {
        fa[i] = i;
      }
    }

    int find(int x) { return x == fa[x] ? x : (fa[x] = find(fa[x])); }

    void merge(int i, int j) { fa[find(i)] = find(j); }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
      //并查集，如果两点已连通，则返回
      int len = edges.size();
      fa = new int[len + 1];
      init(len);
      for (int i = 0; i < len; i++) {
        if (find(edges[i][0]) != find(edges[i][1])) {
          merge(edges[i][0], edges[i][1]);
        } else {
          return edges[i];
        }
      }
      return {};
    }

    //46. 全排列 回溯

    void dfs_46(int n, vector<vector<int>>& res, vector<int>& tmp,
                vector<bool>& visited, vector<int>& nums) {
      if (tmp.size() == n) {
        res.push_back(tmp);
        return;
      }
      for (int i = 0; i < n; i++) {
        if (!visited[i]) {
          tmp.push_back(nums[i]);
          visited[i] = true;
          dfs_46(n, res, tmp, visited, nums);
          visited[i] = false;
          tmp.pop_back();
        }
      }
    }

    vector<vector<int>> permute(vector<int>& nums) {
      int len = nums.size();
      vector<vector<int>> ans;
      vector<bool> visited(len, false);
      dfs_46(len, ans, {}, visited, nums);
      return ans;
    }

    //只关注模即可
    vector<bool> prefixesDivBy5(vector<int>& A) {
      int len = A.size();
      int pre = 0;
      vector<bool> ans(len);
      for (int i = 0; i < len; i++) {
        pre = (pre * 2 + A[i]) % 5;
        ans[i] = (pre == 0);
      }
      return ans;
    }

    //39. 组合总和 回溯
    void dfs_39(vector<vector<int>>& ans, vector<int> nums, int target,
                vector<int>& tmp, int index, int len) {
      if (target == 0) {
        ans.push_back(tmp);
        return;
      }
      for (int i = index; i < len; i++) {
        if (target >= nums[i]) {
          tmp.push_back(nums[i]);
          dfs_39(ans, nums, target - nums[i], tmp, i, len);
          tmp.pop_back();
        } else
          break;
      }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
      vector<vector<int>> ans;
      vector<int> tmp;
      int len = candidates.size();
      std::sort(candidates.begin(), candidates.end());
      dfs_39(ans, candidates, target, tmp, 0, len);
      return ans;
    }


    //47. 全排列 II    回溯
    vector<vector<int>> permuteUnique(vector<int>& nums) {
      int len = nums.size();
      vector<vector<int>> ans;
    //   vector<vector<int>> res;
      vector<int> tmp;
      vector<bool> used(len, false);
      std::sort(nums.begin(), nums.end());
      std::function<void(int)> back_trace = [&](int index) {
        if (index == len) {
          ans.emplace_back(tmp);
          return;
        }
        for (int i = 0; i < len; i++) {
          if (used[i] || (i > 0 && nums[i] == nums[i - 1] && nums[i - 1] == false)) {
            continue;
          }
          if (!used[i]) {
            tmp.emplace_back(nums[i]);
            used[i] = true;
            back_trace(index + 1);
            used[i] = false;
            tmp.pop_back();
          }
        }
      };

      back_trace(0);
    //   res.assign(ans.begin(), ans.end());
      return ans;
    }

    //40. 组合总和 II  回溯
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
      int len = candidates.size();
      vector<vector<int>> ans;
      vector<int> tmp;
      vector<bool> used(len, false);
      std::sort(candidates.begin(), candidates.end());
      std::function<void(int, int)> back_trace = [&](int index, int sum) {
        if (sum == 0) {
          ans.emplace_back(tmp);
          return;
        }
        for (int i = index; i < len; i++) {
          if (sum >= candidates[i]) {  //超过target的不要
            if (i > 0 && candidates[i] == candidates[i - 1] && !used[i - 1])
              continue;             //剪掉重复的
            if (used[i]) continue;  //已经用过的不用
            tmp.emplace_back(candidates[i]);
            used[i] = true;
            back_trace(i, sum - candidates[i]);
            used[i] = false;
            tmp.pop_back();
          } else
            break;
        }
      };
      back_trace(0, target);
      return ans;
    }

     // 216. 组合总和 III  回溯
    vector<vector<int>> combinationSum3(int k, int n) {
      vector<vector<int>> ans;
      vector<int> tmp;
      std::function<void(int, int)> back_trace = [&](int index, int sum) {
        if (sum != 0 && tmp.size() == k) {
          return;
        }
        if (sum == 0 && tmp.size() == k) {
          ans.emplace_back(tmp);
          return;
        }
        for (int i = index; i < 10; i++) {
          if (sum >= i) {
            tmp.emplace_back(i);
            back_trace(i + 1, sum - i);
            tmp.pop_back();
          } else
            break;
        }
      };
      back_trace(1, n);
      return ans;
    }

    // 377. 组合总和 Ⅳ    dfs
    int combinationSum4(vector<int>& nums, int target) {
      int len = nums.size();
      vector<int> memo(target + 1, -1);
      std::sort(nums.begin(), nums.end());
      std::function<int(int)> dfs = [&](int sum) {
        if (sum == 0) return 1;
        if (sum < 0) return 0;
        if (memo[sum] != -1) return memo[sum];
        int res = 0;
        for (int i = 0; i < len; i++) {
          res += dfs(sum - nums[i]);
        }
        return memo[sum] = res;
      };
      return dfs(target);
    }

    // 377. 组合总和 Ⅳ    动态规划
    int combinationSum4(vector<int>& nums, int target) {
      int len = nums.size();
      int* dp = new int[len];
      dp[0] = 1;
      for (int i = 1; i <= target; i++) {
        for (auto num : nums) {
          if(i >= num) dp[i] += dp[i - num];
        }
      }
      return dp[target];
    }

    //647. 回文子串 中心扩展算法
    int countSubstrings(string s) {
      int len = s.size();
      if (len < 2) return len;
      unsigned long long ans = 0;
      std::function<void(int, int)> expandCenter = [&](int left, int right) {
        while (left >= 0 && right < len && s[left] == s[right]) {
          left--;
          right++;
          ans++;
        }
      };
      for (int i = 0; i < len; i++) {
        expandCenter(i, i);
        expandCenter(i, i + 1);
      }
      return ans;
    }

    //605. 种花问题 回溯复杂度太高 转为 动态规划
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
      int len = flowerbed.size(), ans = 0, pre = 0;
      //int* dp = new int[len + 2];
      for (int i = 0; i < len; i++) {
        if (pre == 0 && !flowerbed[i]) {
          if ((i == 0 && !flowerbed[i + 1]) ||
              (i == len - 1 && !flowerbed[i - 1]) ||
              !(flowerbed[i + 1] && !flowerbed[i - 1])) {
            pre = 1;
            ans++;
          }
        }
      }
      return ans >= n;
    }

    //打砖块 并查集
    vector<int> hitBricks(vector<vector<int>>& grid,
                          vector<vector<int>>& hits) {
      int m = grid.size();
      int n = grid[0].size();
      int l = hits.size();
      vector<int> res(l);
      vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
      vector<vector<int>> copy(grid);
      for (auto& v : hits) {
        copy[v[0]][v[1]] = 0;
      }

      // 构建初始[天花板]并查集
      Djset ds(m * n + 1);
      for (int j = 0; j < n; j++) {
        if (copy[0][j] == 0) continue;
        ds.merge(m * n, j);
      }

      // 初始化并查集
      for (int i = 1; i < m; i++) {
        for (int j = 0; j < n; j++) {
          if (copy[i][j] == 0) continue;
          // 上方
          if (copy[i - 1][j] == 1) {
            ds.merge(i * n + j, (i - 1) * n + j);
          }
          if (j > 0 && copy[i][j - 1] == 1) {
            ds.merge(i * n + j, i * n + j - 1);
          }
        }
      }

      // 逆序遍历hits，在sta中补砖
      for (int k = l - 1; k >= 0; k--) {
        int i = hits[k][0];
        int j = hits[k][1];

        if (grid[i][j] == 0) {
          continue;
        }
        int origin = ds.get_size(m * n);
        // 被补回的砖块位于房顶
        if (i == 0) {
          ds.merge(m * n, j);
        }

        for (auto& d : dir) {
          int r = i + d[0];
          int c = j + d[1];
          if (r < 0 || r >= m || c < 0 || c >= n || copy[r][c] == 0) continue;
          ds.merge(i * n + j, r * n + c);
        }
        int cur = ds.get_size(m * n);
        res[k] = max(0, cur - origin - 1);
        copy[i][j] = 1;
      }
      return res;
    }


    //338. 比特位计数 dp

    vector<int> countBits(int num) {
      vector<int> ans(num + 1);
      std::function<int(int)> count_1 = [](int n) {
        int count = 0;
        unsigned int flag = 1;
        while (flag) {
          if (n & flag) {
            count++;
          }
          flag = flag << 1;
        }
        return count;
      };

      for (int i = 0; i <= num; i++) {
        // ans[i] = count_1(i);
        // ans[i] = ans[i & (i - 1)] + 1;
        ans[i] = ans[i >> 1] + (i & 1);
        ans[i] = count_1(i);
      }
      return ans;
    }

    //238. 除自身以外数组的乘积 
     vector<int> productExceptSelf(vector<int>& nums) {
      int len = nums.size();
      int cnt = 0, sum2 = 1;

      vector<int> ans;
      for (int i = 0; i < len; i++) {
        if (nums[i] == 0) cnt++;
        else sum2 = sum2 * nums[i];  
      }

      for (int i = 0; i < len; i++) {
        if (cnt < 1)
          ans.emplace_back(sum2 / nums[i]);
        else {
          if (cnt == 1 && nums[i] == 0)
            ans.emplace_back(sum2);
          else
            ans.emplace_back(0);
        }
      }
      return ans;
    }

    int findDuplicate(vector<int>& nums) {
      std::unordered_map<int, int> m;
      for (int i = 0; i < nums.size(); i++) {
        if (!m.count(nums[i])) {
          m[nums[i]] = 1;
        } else
          return nums[i];
      }
      return -1;
    }

    //1232. 缀点成线
    bool checkStraightLine(vector<vector<int>>& coordinates) {
      int len = coordinates.size(), k;
      bool flag = false;
      for (int i = 1; i < len; i++) {
        auto a = coordinates[i - 1];
        auto b = coordinates[i];
        if (i == 1) {
          if (a[0] == b[0])
            flag == true;
          else
            k = (a[1] - b[1]) / (a[0] - b[0]);
        } else {
          if (flag) {
            if (k != (a[1] - b[1]) / (a[0] - b[0])) return false;
          } else {
            if (a[0] == b[0]) return false;
          }
        }
      }
      return true;
    }

    //721. 账户合并 并查集
    std::unordered_map<string, int> fa_721;
    // std::unordered_map<string, int> rank_721;
    int find(string x) {
      // cout << "x: " << x <<endl;
      if (!fa_721.count(x)) {
        fa_721[x] = -1;
        // rank_721[x] = 1;
      }
      return fa_721[x];
    }

    void merge(string i, string j) {
      //   cout << "i: " << i << ", j: "<< j << endl;
      //   string x = find(i), y = find(j);
      //   if (rank_721[x] <= rank_721[y])
      //     fa_721[x] = y;
      //   else
      //     fa_721[y] = x;
      //   if (rank_721[x] == rank_721[y] && x != y) rank_721[y]++;
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
      int len = accounts.size();
      std::map<int, vector<string>> i2addr;
      vector<vector<string>> ans;
      for (int i = 0; i < len; i++) {
        int n = accounts[i].size();
        if (n != 1) {
          auto name = accounts[i][0];
          bool flag = false;
          int x;
          for (int j = 1; j < n; j++) {
            x = find(accounts[i][j]);
            if (find(accounts[i][j]) != -1) {
              flag = true;
              //break;
            }
          }
          if (flag) {
            for (int j = 1; j < n; j++) {
              fa_721[accounts[i][j]] = x;
            }
          } else {
            for (int j = 1; j < n; j++) {
              fa_721[accounts[i][j]] = i;
            }
          }
        }
      }

      for (auto m : fa_721) {
        cout << "1: " << m.first << ", 2: " << m.second << endl;
        i2addr[m.second].emplace_back(m.first);
      }
      for (auto m : i2addr) {
        vector<string> tmp;
        tmp.emplace_back(accounts[m.first][0]);
        std::sort(m.second.begin(), m.second.end());
        for (auto it : m.second) {
          tmp.emplace_back(it);
        }
        ans.emplace_back(tmp);
      }
      return {};
    }




    //  vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    //  using namespace std;
    //  map<string, int> emailToIndex;
    //  map<string, string> emailToName;
    //  int emailsCount = 0;
    //  for (auto& account : accounts) {
    //    string& name = account[0];
    //    int size = account.size();
    //    for (int i = 1; i < size; i++) {
    //      string& email = account[i];
    //      if (!emailToIndex.count(email)) {
    //        emailToIndex[email] = emailsCount++;
    //        emailToName[email] = name;
    //      }
    //    }
    //  }
    //  UnionFind uf(emailsCount);
    //  for (auto& account : accounts) {
    //    string& firstEmail = account[1];
    //    int firstIndex = emailToIndex[firstEmail];
    //    int size = account.size();
    //    for (int i = 2; i < size; i++) {
    //      string& nextEmail = account[i];
    //      int nextIndex = emailToIndex[nextEmail];
    //      uf.unionSet(firstIndex, nextIndex);
    //    }
    //  }
    //  map<int, vector<string>> indexToEmails;
    //  for (auto& email : emailToIndex) {
    //    int index = uf.find(emailToIndex[email.first]);
    //    vector<string>& account = indexToEmails[index];
    //    account.emplace_back(email.first);
    //    indexToEmails[index] = account;
    //  }
    //  vector<vector<string>> merged;
    //  for (auto& emails : indexToEmails) {
    //    sort(emails.second.begin(), emails.second.end());
    //    string& name = emailToName[emails.second[0]];
    //    vector<string> account;
    //    account.emplace_back(name);
    //    for (auto& email : emails.second) {
    //      account.emplace_back(email);
    //    }
    //    merged.emplace_back(account);
    //  }
    //  return merged;
    //}


    //279. 完全平方数 回溯（超时）  dp  数学方法
    int numSquares(int n) {
      //int x = sqrt(n);
      //cout << "x: " << x << endl;

      //int ans = INT_MAX;
      //vector<int> tmp;
      //std::function<void(int, int)> back_trace = [&](int index, int sum) {
      //  if (sum < 0) {
      //    return;
      //  }
      //  if (sum == 0) {
      //    ans = min(ans, tmp.size());
      //    return;
      //  }
      //  for (int i = 1; i <= x; i++) {
      //    if (sum >= i) {
      //      tmp.emplace_back(i * i);
      //      back_trace(i + 1, sum - i * i);
      //      tmp.pop_back();
      //    } else
      //      break;
      //  }
      //};
      //back_trace(1, n);

      if (n <= 3) return n;
      int x = sqrt(n);
      int* dp = new int[n + 2];
      dp[0] = 0;
      dp[1] = 1;
      for (int i = 2; i <= n; i++) {
        dp[i] = INT_MAX;
        for (int j = 1; j <= x; j++) {
          if (i >= j * j) dp[i] = min(dp[i - j * j] + 1, dp[i]);
        }
      }
      return dp[n];
    }


    bool isSquare(int n) {
      int sq = (int)sqrt(n);
      return n == sq * sq;
    }

    int numSquares(int n) {
      while (n % 4 == 0) n /= 4;
      if (n % 8 == 7) return 4;
      if (isSquare(n)) return 1;
      for (int i = 1; i * i <= n; ++i) {
        if (isSquare(n - i * i)) return 2;
      }
      return 3;
    }

    //1584. 连接所有点的最小费用 并查集
    int* fa_1584;
    void init_1584(int len) {
      for (int i = 0; i < len; i++) {
        fa_1584[i] = i;
      }
    }

    int find_1584(int x) {
      return fa_1584[x] == x ? x : fa_1584[x] = find_1584(fa_1584[x]);
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
      int len = points.size();
      fa_1584 = new int[len + 1];
      std::priority_queue<std::tuple<int, int, int>,
                          vector<std::tuple<int, int, int>>,
                          std::greater<std::tuple<int, int, int>>
                          > pq;
      init_1584(len);
      for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
          auto a = points[i], b = points[j];
          pq.push(std::make_tuple(abs(a[0] - b[0]) + abs(a[1] - b[1]), i, j));
        }
      }
      int ans = 0, cnt = 0;
      while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();
        int x = find_1584(std::get<1>(top)), y = find_1584(std::get<2>(top));
        if (x != y) {
          cnt++;
          ans += find_1584(std::get<0>(top));
          fa_1584[y] = x;
        }
        if (cnt == len - 1) break;
      }
      return ans;
    }

    // 347. 前 K 个高频元素
    vector<int> topKFrequent(vector<int>& nums, int k) {
      int len = nums.size();
      vector<int> ans;
      std::unordered_map<int, int> m;
      for (int i = 0; i < len; i++) {
        m[nums[i]]++;
      }
      std::vector <std::pair<int, int>> se;
      for (auto x : m) {
        se.emplace_back(std::make_pair(x.second, x.first));
      }
      
      std::sort(se.rbegin(), se.rend());
      int cnt = 0;
      if (se.size() == 1) return {se[0].second};
      for (int i = 0; i < se.size(); i++) {
        if (i == 0)
          cnt++;
        else {
          if (se[i].first != se[i - 1].first) cnt++;
          if (k == cnt) {
            int j = i;
            while (se[j].first == se[i].first) {
              ans.emplace_back(se[j].second);
            }
            return ans;
          }
        }
      }
      return {};
    }

    // 494. 目标和 dp (可回溯)
    /*
    *  正 - 负 = target
    *  正 + 负 = sum(nums)
    *  => 2 * 正 = target + sum(nums) 
    *  => 正 = (target + sum(nums)) / 2
    */
    int findTargetSumWays(vector<int>& nums, int S) {
      int len = nums.size();
      if (len == 1 && nums[0] == abs(S)) return 1;
      int* dp = new int[len + 1];
      int sum = 0, ans = 0;
      for (int i = 0; i < len; i++) {
        sum += nums[i];
      }
      sum = (sum + S);
      if (sum % 2 != 0)
        return 0;
      else
        sum = sum / 2;
      dp[0] = 1;
      for (int i = 1; i <= sum; i++) {
        for (auto num : nums) {
          if (i >= num) dp[i] += dp[i - num];
        }
      }
      return dp[sum];
    }


    //322. 零钱兑换  dp 01背包
    int coinChange(vector<int>& coins, int amount) { 
      //if (amount == 0) return 0;
      //int len = coins.size();
      //vector<int> dp(amount + 1, 0);
      //bool flag = false;
      //for (int i = 0; i < len; i++) {
      //  if (coins[i] <= amount) flag = true;
      //  for (int j = amount; j >= coins[i]; j--) {
      //    int n = j / coins[i];
      //    if (i == 0) {
      //      if (j % coins[i] != 0)
      //        dp[j] = INT_MAX;
      //      else
      //        dp[j] = n;
      //    }
      //    else {
      //      for (int k = 0; k <= n; k++) {
      //        if (dp[j - k * coins[i]] != INT_MAX)
      //          dp[j] = min(dp[j], dp[j - k * coins[i]] + k);
      //      }
      //    }
      //  }
      //}

      //if (!flag) return -1;
      //return dp[amount] == INT_MAX ? -1 : dp[amount];
        

      if (amount == 0) return 0;
      int len = coins.size();
      int m = amount + 1;
      vector<int> dp(amount + 1, m);
      dp[0] = 0;
      for (int i = 0; i <= amount; i++) {
        for (int j = 0; j < len; j++) {
          if (coins[j] <= i) dp[i] = min(dp[i], dp[i - coins[j]] + 1);
        }
      }
      return dp[amount] > amount ? -1 : dp[amount];
    }

    //309. 最佳买卖股票时机含冷冻期 dp
    int maxProfit(vector<int>& prices) {
      //int len = prices.size();
      //if (len < 2) return 0;
      //int* dp1 = new int[len];  //拥有
      //int* dp2 = new int[len];  //不拥有
      //int* dp3 = new int[len];  //交易后不拥有
      //dp1[0] = -prices[0];
      //dp2[0] = 0;
      //dp3[0] = 0;
      //for (int i = 1; i < len; i++) {
      //  dp1[i] = max(dp2[i - 1] - prices[i], dp1[i - 1]);
      //  dp2[i] = max(dp2[i - 1], dp3[i - 1]);
      //  dp3[i] = dp1[i - 1] + prices[i];
      //}
      //return max(dp2[len - 1], dp3[len - 1]);

      // 空间优化
      int len = prices.size();
      if (len < 2) return 0;
      int dp1 = -prices[0];    //拥有
      int dp2 = 0;  //不拥有
      int dp3 = 0;  //交易后不拥有
      int tmp1, tmp2, tmp3;
      for (int i = 1; i < len; i++) {
        tmp1 = dp1;
        tmp2 = dp2;
        tmp3 = dp3;
        dp1 = max(tmp2 - prices[i], tmp1);
        dp2 = max(tmp2, tmp3);
        dp3 = tmp1 + prices[i];
      }
      return max(dp2, dp3);
    }

    //337. 打家劫舍 III dp
    int rob(TreeNode* root) {
      std::function<vector<int>(TreeNode*)> dfs = [&](TreeNode* cur) {
        vector<int> dp(2, 0);
        if (!cur) return dp;
        auto r1 = dfs(cur->left);
        auto r2 = dfs(cur->right);
        dp[0] = r1[1] + r2[1] + cur->val;
        dp[1] = max(r1[0], r1[1]) + max(r2[0], r2[1]);
        return dp;
      };

      auto res = dfs(root);
      return max(res[0], res[1]);
    }

    int dfs_camera(TreeNode* cur, int& res) {
      if (cur == NULL) return 2;

      int left = dfs_camera(cur->left, res);
      int right = dfs_camera(cur->right, res);

      if (left == 2 && right == 2) {
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
      if (dfs_camera(root, res) == 0) {  // root 无覆盖
        res++;
      }
      return res;
    }