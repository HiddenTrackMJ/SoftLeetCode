// SoftLeetCode.cpp : Defines the entry point for the application.
//

#include "SoftLeetCode.h"

#include "leet_1.h"

using namespace std;


int main() {
  cout << "Hello, this is SoftLeetCode." << endl;


  Solution s;
  //auto res = s.twoSum2(c, 6);
  // vector<int> c = {3,2,4};
  //size_t len = res.size();
  // for (size_t j = 0; j < len; j++) {
  //  std::cout << "res"
  //            << j
  //            << " : " << res[j] << std::endl;
  //}


  ListNode* a = new ListNode(1);
  ListNode* b = new ListNode(9);
  ListNode* c = new ListNode(9);

  ListNode* d = new ListNode(9);
  ListNode* e = new ListNode(9);
  ListNode* f = new ListNode(9);
  a->next = b;
  b->next = c;
  c->next = d;
  d->next = e;

  //d->next = e;
  //e->next = f;
  s.addTwoNumbers(a, f);
  return 0;
}
