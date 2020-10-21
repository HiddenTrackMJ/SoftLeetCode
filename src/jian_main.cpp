
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

  int n, x = 0, y = 0;
  std::cin >> n;
  char a[100];
  int b[100];
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
    //std::cin >> " ";
    std::cin >> b[i];
  }

  for (int i = 0; i < n; i++) {
    if (a[i] == 'W') x = x - 2;
    if (a[i] == 'E') x = x + 2;
    if (a[i] == 'S') y = y - 2;
    if (a[i] == 'N') y = y + 2;
  }
  cout << x << " " << y << endl;
}