// SoftLeetCode.cpp : Defines the entry point for the application.
//

#include "SoftLeetCode.h"

#include "leet_1.h"

using namespace std;


int main() {
  cout << "Hello, this is SoftLeetCode." << endl;


  Solution s;

  /*    No.1      */
  //auto res = s.twoSum2(c, 6);
  // vector<int> c = {3,2,4};
  //size_t len = res.size();
  // for (size_t j = 0; j < len; j++) {
  //  std::cout << "res"
  //            << j
  //            << " : " << res[j] << std::endl;
  //}


   /*    No.2 (1)     */
  //ListNode* a = new ListNode(1);
  //ListNode* b = new ListNode(9);
  //ListNode* c = new ListNode(9);

  //ListNode* d = new ListNode(9);
  //ListNode* e = new ListNode(9);
  //ListNode* f = new ListNode(9);
  //a->next = b;
  //b->next = c;
  //c->next = d;
  //d->next = e;

  ////d->next = e;
  ////e->next = f;
  //s.addTwoNumbers(a, f);

  /*    No.2 (2)     */
  //int a[1] = {1};
  //int b[2] = {9, 9};

  //int k = sizeof(a) / sizeof(int);
  //int p = sizeof(b) / sizeof(int);
  //std::cout << "len: " << k << std::endl;
  //std::cout << "len: " << p << std::endl;

  //ListNode* x = s.int2node(a, k);
  //ListNode* y = s.int2node(b, p);

  //auto res = s.addTwoNumbers(y, x);


  /*    No.94      */
  TreeNode* a = new TreeNode(1);
  TreeNode* b = new TreeNode(2);
  TreeNode* c = new TreeNode(3);

  a->right = b;
  b->left = c;

  auto res = s.inorderTraversal2(a);
   size_t len = res.size();
   for (size_t j = 0; j < len; j++) {
    std::cout << "res"
              << j
              << " : " << res.back() << std::endl;
     res.pop_back();
  }

  return 0;
}
