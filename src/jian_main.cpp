
#include "jian_1.h"

//#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")

using namespace std;

int main() {
  //cout << "Hello, this is SoftLeetCode." << endl;

  //Solution s;

  ///*  No.剑指 Offer 03. 数组中重复的数字 */
  //vector<int> nums = {2, 3, 1, 0, 2, 5, 3};
  //auto res_03 = s.findRepeatNumber(nums);
  //std::cout << "res_03: " << res_03 << std::endl;

 std::priority_queue<std::tuple<int, int, int>,
                      vector<std::tuple<int, int, int>>,
                      std::greater<std::tuple<int, int, int>>>
      pq;

 pq.push(std::make_tuple(1, 3, 2));
 pq.push(std::make_tuple(7, 9, 8));
 pq.push(std::make_tuple(4, 6, 5));
 // for (int i = 0; i < 300000; i++) {
 //  pq.push(std::make_tuple(1, 3, 2));
 //}

  //vector<std::tuple<int, int, int>> v;
  //for (int i = 0; i < 300000; i++) {
  //  v.push_back(std::make_tuple(1, 3, 2));
  //}

 while (!pq.empty()) {
   std::tuple<int, int, int> t = pq.top();
 
   std::cout << "top: " <<  std::get<0>(t) << std::endl;
   pq.pop();
 }



  //std::map<int, int> test_map;

  //for (int i = 0; i < 300000; i++) {
  //  test_map[i] = i;
  //}

  std::cout << "over...";
  std::this_thread::sleep_for(std::chrono::milliseconds(30000));
}