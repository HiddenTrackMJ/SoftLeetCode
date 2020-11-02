// SoftLeetCode.cpp : Defines the entry point for the application.
//

#include "SoftLeetCode.h"

#include "leet_1.h"

//#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")

using namespace std;


int main() {
  cout << "Hello, this is SoftLeetCode." << endl;

  Solution s;

  /*    No.1      */
  // vector<int> c = {3, 2, 4};
  // auto res = s.twoSum2(c, 6);

  // size_t len = res.size();
  // for (size_t j = 0; j < len; j++) {
  //  std::cout << "res"
  //            << j
  //            << " : " << res[j] << std::endl;
  //}

  /*    No.2 (1)     */
  // ListNode* a = new ListNode(1);
  // ListNode* b = new ListNode(9);
  // ListNode* c = new ListNode(9);

  // ListNode* d = new ListNode(9);
  // ListNode* e = new ListNode(9);
  // ListNode* f = new ListNode(9);
  // a->next = b;
  // b->next = c;
  // c->next = d;
  // d->next = e;

  ////d->next = e;
  ////e->next = f;
  // s.addTwoNumbers(a, f);

  /*    No.2 (2)     */
  // int a[1] = {1};
  // int b[2] = {9, 9};

  // int k = sizeof(a) / sizeof(int);
  // int p = sizeof(b) / sizeof(int);
  // std::cout << "len: " << k << std::endl;
  // std::cout << "len: " << p << std::endl;

  // ListNode* x = s.int2node(a, k);
  // ListNode* y = s.int2node(b, p);

  // auto res = s.addTwoNumbers(y, x);

  /*    No.94      */
  // TreeNode* a = new TreeNode(1);
  // TreeNode* b = new TreeNode(2);
  // TreeNode* c = new TreeNode(3);

  // a->right = b;
  // b->left = c;

  // auto res = s.inorderTraversal2(a);
  // size_t len = res.size();
  // for (size_t j = 0; j < len; j++) {
  //  std::cout << "res"
  //            << j
  //            << " : " << res.back() << std::endl;
  //   res.pop_back();
  //}

  /*     No.37       */
  vector<vector<char>> board = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                                {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                                {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                                {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                                {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                                {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                                {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                                {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                                {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
  // TreeNode* a = new TreeNode(1);
  // TreeNode* b = new TreeNode(2);
  // TreeNode* c = new TreeNode(3);

  // a->right = b;
  // b->left = c;

  // auto res = s.inorderTraversal2(a);
  // size_t len = res.size();
  // for (size_t j = 0; j < len; j++) {
  //  std::cout << "res"
  //            << j
  //            << " : " << res.back() << std::endl;
  //   res.pop_back();
  //}

  /*    No.226     */
  // TreeNode* a = new TreeNode(4);
  // TreeNode* b = new TreeNode(2);
  // TreeNode* c = new TreeNode(7);
  // TreeNode* d = new TreeNode(1);
  // TreeNode* e = new TreeNode(3);
  // TreeNode* f = new TreeNode(6);
  // TreeNode* g = new TreeNode(9);

  // a->left = b;
  // a->right = c;
  // b->left = d;
  // b->right = e;
  // c->left = f;
  // c->right = g;

  // s.inorderTraversal(a);
  // s.invertTree2(a);
  // s.inorderTraversal(a);

  /*    No.538     */
  // TreeNode* a = new TreeNode(0);
  // TreeNode* b = new TreeNode(-2);
  // TreeNode* c = new TreeNode(3);
  // TreeNode* d = new TreeNode(-4);
  // TreeNode* e = new TreeNode(-1);
  // TreeNode* f = new TreeNode(6);
  // TreeNode* g = new TreeNode(4);

  // a->left = b;
  // a->right = c;
  ////b->left = d;
  // b->right = e;
  ////c->left = f;
  // c->right = g;

  // s.convertBST(a);
  // s.inorderTraversal(a);

  /*   No.968     */
  TreeNode* a = new TreeNode(1);
  TreeNode* b = new TreeNode(2);
  TreeNode* c = new TreeNode(3);
  TreeNode* d = new TreeNode(1);
  TreeNode* e = new TreeNode(3);
  TreeNode* f = new TreeNode(2);
  TreeNode* g = new TreeNode(1);

  // TreeNode* x = new TreeNode(-2);
  // TreeNode* y = new TreeNode(-4);
  // TreeNode* z = new TreeNode(-1);

  a->left = b;
  a->right = c;
  //b->left = d;
  //b->right = e;
  //c->left = f;
  //d->left = g;
  // c->right = g;
  // x->left = y;
  // x->right = z;

  // int res = s.minCameraCover(a);
  // std::cout << res << std::endl;

  /*   No.617     */

  // auto res = s.mergeTrees(a, x);
  // s.inorderTraversal(res);

  /*   No.501     */

  // auto res = s.findMode(a);
  // size_t len = res.size();
  // for (size_t j = 0; j < len; j++) {
  //  std::cout << "res"
  //            << j
  //            << " : " << res.back() << std::endl;
  //   res.pop_back();
  //}

  /*   No.106     */
  // vector<int> a = {9, 3, 15, 20, 7};
  // vector<int> b = {9, 15, 7, 20, 3};
  // auto res = s.buildTree(a, b);
  // s.inorderTraversal(res);

  /*   No.113     */

  // auto res = s.pathSum2(a, -1);
  // size_t len = res.size();
  // for (size_t j = 0; j < len; j++) {
  //  size_t len2 = res[j].size();
  //  std::cout << " res: ";
  //  for (size_t i = 0; i < len2; i++) {
  //    std::cout << res[j][i] << " ";
  //  }
  //  std::cout << std::endl;
  //}

  /*   No.145     */
  // s.postorderTraversal2(a);

  /*   No.117     */
  // Node* a = new Node(0);
  // Node* b = new Node(0);
  // Node* c = new Node(0);
  // a->left = b;
  // a->right = c;
  // s.connect(a);

  /*   No.344     */
  //std::vector<char> reverse_s = {
  //  'a', 'b', 'c', 'd', 'e', 'f', 'g'
  //  };
  //s.reverseString(reverse_s);
  //size_t len = reverse_s.size();
  //std::cout << "res: ";
  // for (size_t j = 0; j < len; j++) {
  //  std::cout << reverse_s[j] << ", " ;

  //}

  /*   No.75     */
  //vector<int> colors = {2, 0, 2, 1, 1, 0};
  //s.sortColors(colors);
  //size_t len = colors.size();
  //std::cout << "res: ";
  //for (size_t j = 0; j < len; j++) {
  //  std::cout << colors[j] << ", ";
  //}

  /*   No.102     */
  //auto res = s.levelOrder(a);
  //size_t len = res.size();
  //for (size_t j = 0; j < len; j++) {
  //  size_t len2 = res[j].size();
  //  std::cout << " res: ";
  //  for (size_t i = 0; i < len2; i++) {
  //    std::cout << res[j][i] << " ";
  //  }
  //  std::cout << std::endl;
  //}

  /*   No.141     */
  //ListNode* a = new ListNode(3);
  //ListNode* b = new ListNode(2);
  //ListNode* c = new ListNode(0);
  //ListNode* d = new ListNode(-4);
  //a->next = b;
  //b->next = c;
  //c->next = d;
  //d->next = b;
  //auto is_cycle = s.hasCycle2(a);
  //std::cout << "res: " << is_cycle << std::endl;

  /*   No.142     */
  //auto detect_cycle = s.detectCycle(a);
  //std::cout << "res: " << detect_cycle->val << std::endl;


  /*  LCP No.19   */
  //string leaves = "yry";
  //auto res = s.minimumOperations(leaves);
  //std::cout << "res: " << res << std::endl;


  /*   No.18     */
  //vector<int> c = {-2, -1, -1, 1, 1, 2, 2};
  //auto res = s.fourSum(c, 0);
  //size_t len = res.size();
  //for (size_t j = 0; j < len; j++) {
  //  size_t len2 = res[j].size();
  //  std::cout << " res: ";
  //  for (size_t i = 0; i < len2; i++) {
  //    std::cout << res[j][i] << " ";
  //  }
  //  std::cout << std::endl;
  //}

  /*   No.416. 分割等和子集    */
  //vector<int> s_partition = {1, 4, 11, 5};
  //auto res = s.canPartition(s_partition);
  //std::cout << res << std::endl;

  /*  No.530. 二叉搜索树的最小绝对差   */
   //TreeNode* a = new TreeNode(1);
   //TreeNode* b = new TreeNode(3);
   //TreeNode* c = new TreeNode(2);

   //a->right = b;
   //b->left = c;

   //auto res = s.getMinimumDifference(a);
   //std::cout << res << std::endl;

   //数组指针理解
   //int array[] = {1, 2, 3, 4, 5};
   //int (*ptr_array)[5] = &array;
   //for (int i = 0; i < 5; i++) {
   //  std::cout << "array[i]: " << array[i] << std::endl;
   //  std::cout << "array: " << array + i << std::endl;
   //  std::cout << "ptr_array[i]: " << ptr_array[i] << std::endl;
   //  std::cout << "ptr_array: " << ptr_array + i << std::endl;
   //  std::cout << std::endl;
   //}

   /*    24. 两两交换链表中的节点     */
    //ListNode* a = new ListNode(3);
    //ListNode* b = new ListNode(2);
    //ListNode* c = new ListNode(0);
    //ListNode* d = new ListNode(-4);
    //ListNode* e = new ListNode(-5);
    //ListNode* f = new ListNode(3);
    //ListNode* g = new ListNode(6);
    //a->next = b;
    //b->next = c;
    //c->next = d;
    //d->next = e;
    //e->next = f;
    //f->next = g;
    //auto swap_pair = s.swapPairs(a);

    //while (swap_pair) {
    //  std::cout << "res: " << swap_pair->val << std::endl;
    //  swap_pair = swap_pair->next;
    //}

   /*  No.1002. 查找常用字符  */
  //vector<string> str = {"cool", "lock", "cook"};
  //auto common_res = s.commonChars(str);
  //size_t len = common_res.size();
  //std::cout << "res: ";
  //for (size_t j = 0; j < len; j++) {
  //  std::cout << common_res[j] << ", ";
  //}

  /* No.116. 填充每个节点的下一个右侧节点指针 */
 /*  Node* a = new Node(0);
   Node* b = new Node(1);
   Node* c = new Node(0);
   a->left = b;
   a->right = c;
   s.connect(a);*/

   /*   No. 977. 有序数组的平方    */
   //vector<int> sort_q = {-4, -1, 0, 3, 10};
   //s.sortedSquares(sort_q);

   /*   No. 19. 删除链表的倒数第N个节点   */
   //ListNode* a = new ListNode(0);
   //ListNode* b = new ListNode(1);
   //a->next = b;
   //s.removeNthFromEnd(a, 2);

  /*  No. 143. 重排链表   */
  //ListNode* a = new ListNode(0);
  //ListNode* b = new ListNode(1);
  //ListNode* c = new ListNode(2);
  //ListNode* d = new ListNode(2);
  //ListNode* e = new ListNode(1);
  //ListNode* f = new ListNode(0);
  //a->next = b;
  //b->next = c;
  //c->next = d;
  //d->next = e;
  //e->next = f;
  //s.reorderList(a);
  //while (a) {
  //  std::cout << "a: " << a->val << std::endl;
  //  a = a->next;
  //}
   //ListNode* a = new ListNode(0);
   //ListNode* b = new ListNode(1);
   //a->next = b;
   //s.removeNthFromEnd(a, 2);


   /*   No. 844. 比较含退格的字符串   */
  //string S = "ab##";
  //string T = "c#d#";
  //auto back_com = s.backspaceCompare(S, T);

  /*  No. 925. 长按键入   */
  //string name = "pyplrz";
  //string typed = "ppyypllr";
  //auto long_press = s.isLongPressedName(name, typed);
  //std::cout << "long_press: " << long_press << std::endl;


  /*  No. 763. 划分字母区间  */
  //string partition = "ababcbacadefegdehijhklij";
  //auto par = s.partitionLabels(partition);
  //size_t len = par.size();
  //std::cout << "par: ";
  //for (size_t j = 0; j < len; j++) {
  //  std::cout << par[j] << ", ";
  //}

  /* No. 234. 回文链表  */
  //auto is_Pali = s.isPalindrome(a);
  //cout << "is_Pali: " << is_Pali << endl;


  /*  No. 1207. 独一无二的出现次数  */
  //vector<int> arr = {1, 2, 2, 1, 1, 2};
  //auto is_unique = s.uniqueOccurrences(arr);
  //std::cout << "is_unique: " << is_unique << std::endl;


  /*  No. 463. 岛屿的周长  */
  //vector<vector<int>> grid = {
  //    {0, 1, 0, 0}, {1, 1, 1, 0}, {0, 1, 0, 0}, {1, 1, 0, 0}};
  //auto is_land = s.islandPerimeter(grid);
  //std::cout << "is_land: " << is_land << std::endl;


  /*  No. 129. 求根到叶子节点数字之和  */
  auto sum_tree = s.sumNumbers(a);
  std::cout << "sum_tree: " << sum_tree << std::endl;

  /*   No. 349. 两个数组的交集    */
  vector<int> nums1 = {4, 9, 5};
  vector<int> nums2 = {9, 4, 9, 8, 4};
  auto inter_sec = s.intersection(nums1, nums2);
  std::cout << "inter_sec: " << std::endl;
  size_t len = inter_sec.size();
  for (size_t j = 0; j < len; j++) {
     std::cout << inter_sec[j] << ", ";
  }

  return 0;
}
