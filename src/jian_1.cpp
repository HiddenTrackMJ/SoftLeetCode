#include "jian_1.h"

using std::cout;
using std::cin;
using std::endl;

int Solution::findRepeatNumber(vector<int>& nums) {
  std::vector<int> res;
  int ans;
  for (int i = 0; i < nums.size(); i++) {
    auto iter = find(res.begin(), res.end(), nums[i]);
    if (iter != res.end()) {
      ans = nums[i];
    } else {
      res.push_back(nums[i]);
    }
  }
  return ans;
}