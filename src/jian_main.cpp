
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

  std::map<int, int> test_map;

  for (int i = 0; i < 300000; i++) {
    test_map[i] = i;
  }

  std::cout << "over...";
  std::this_thread::sleep_for(std::chrono::milliseconds(30000));
}