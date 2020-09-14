#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <stack>

using std::vector;

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

class Solution {
 public:
  ListNode* int2node(int* a, int len);

  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);

  vector<int> inorderTraversal(TreeNode* root);

  vector<int> inorderTraversal2(TreeNode* root);

  vector<int> Solution::twoSum(vector<int>& nums, int target) {
    // std::cout << "nice";
    vector<int> others;
    size_t len = nums.size();

    for (size_t i = 0; i < len; i++) {
      std::cout << "nice: " << i << std::endl;
      int cur = nums[i];
      int other = target - cur;
      for (size_t j = i + 1; j < len; j++) {
        int next = nums[j];
        if (other == next) {
          others.push_back(i);
          others.push_back(j);
          return others;
        } else {
        }
      }
    }

    return others;
  }

  vector<int> Solution::twoSum2(vector<int>& nums, int target) {

    std::map<int, int> past;
    size_t len = nums.size();
    for (int i = 0; i < len; i++) {
      int cur = nums[i];
      int other = target - cur;
      if (auto it = past.find(other) != past.end()) {
        vector<int> others = {i, past[other]};
        return others;
      }
      past.insert(std::make_pair(cur, i));
    }
    vector<int> others;
    return others;
  }

  double str2int(std::string res) {
    std::stringstream ss;
    double n;
    ss << res;
    ss >> n;
    ss.clear();
    return n;
  }

  std::string int2str(double n) {
    std::stringstream ss;
    std::string res;
    ss << n;
    ss >> res;
    ss.clear();
    return res;
  }

   ListNode* addTwoNumbers2(ListNode* l1, ListNode* l2) {
     std::stringstream ss;
     std::string res1;
     std::string res2;

    while (l1 != NULL) {
      int i = l1->val;
      res1 = std::to_string(i) + res1;
      l1 = l1->next;
    }

    double n = (double)str2int(res1);
    std::cout << "n: " << n << std::endl;
    ss.clear();
    while (l2 != NULL) {
      int i = l2->val;
      res2 = std::to_string(i) + res2;
      l2 = l2->next;
    }

    double m = (double)str2int(res2);
    std::cout << "m: " << m << std::endl;
    ss.clear();
    double sum = m + n;
    std::string out = int2str(sum);
    std::cout << "sum: " << sum << std::endl;
    int len = out.size();
    ListNode* s;
    for (int i = 0; i < len; i++) {
      if (i == 0) {
        int x;
        ss << out[i];
        ss >> x;
        ss.clear();
        ListNode* emm = new ListNode(x);
        s = emm;
      } else {
        int x;
        ss << out[i];
        ss >> x;
        ss.clear();
        ListNode* emm = new ListNode(x);
        emm->next = s;
        s = emm;
      }
    }
    // std::string res3;
    // while (s != NULL) {
    //  int i = s->val;

    //  res3 = std::to_string(i) + res3;

    //  s = s->next;
    //}
    // std::cout << "res: " << res3 << std::endl;
    // int z = str2int(res3);
    // std::cout << "z: " << z << std::endl;

    return s;
  }

};
