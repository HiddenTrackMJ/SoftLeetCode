
#include "jian_1.h"

//#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")

using namespace std;

int mainxx() {
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
  return 1;
}

void bubleSort(vector<int>& nums) {
  int len = nums.size();
  bool flag = true;
  for (int i = 0; i < len; i++) {
    cout << "i: " << i << endl;
    flag = true;
    for (int j = 0; j < len - 1; j++) {
      if (nums[j] > nums[j + 1]) {
        flag = false;
        int tmp = nums[j];
        nums[j] = nums[j + 1];
        nums[j + 1] = tmp;
      }
    }
    if (flag) break;
  }
  for (auto& it : nums) {
    cout << it << " " << endl;
  }
}
   
void selectionSort(vector<int>& nums) {
  int len = nums.size();
  int index;
  for (int i = 0; i < len; i++) {
    index = i;
    for (int j = i + 1; j < len; j++) {
      if (nums[j] < nums[index]) index = j;
    }
    if (index != i) std::swap(nums[index], nums[i]);
  }
  for (auto& it : nums) {
    cout << it << " " << endl;
  }
}

void insertionSort(vector<int>& nums) {
  int len = nums.size();
  int pre, cur;
  for (int i = 1; i < len; i++) {
    pre = i - 1;
    cur = nums[i];
    while (pre >= 0 && nums[pre] > cur) {
      nums[pre + 1] = nums[pre];
        pre--;
    }
    nums[pre + 1] = cur;
  }
  cout << "insertion: " << endl;
  for (auto& it : nums) {
    cout << it << " " << endl;
  }
}

void shellSort(vector<int>& nums) {
  int len = nums.size();
  int j, cur;
  for (int gap = len / 2; gap > 0; gap /= 2) {
    for (int i = gap; i < len; i++) {
      j = i;
      cur = nums[i];
      while (j - gap >= 0 && nums[j - gap] > cur) {
        nums[j] = nums[j - gap];
        j -= gap;
      }
      nums[j] = cur;
    }
  }
  cout << "shell: " << endl;
  for (auto& it : nums) {
    cout << it << " " << endl;
  }
}




void mergeSort(vector<int>& nums) {
  int len = nums.size();
  vector<int> tmp(len);
  std::function<void(int, int, int)> merge = [&](int left, int mid, int right) {
    int i = left, j = mid + 1, t = 0;
    while (i <= mid && j <= right) {
      if (nums[i] <= nums[j]) {
        tmp[t++] = nums[i++];
      } else {
        tmp[t++] = nums[j++];
      }
    }

    while (i <= mid) tmp[t++] = nums[i++];
    while (j <= right) tmp[t++] = nums[j++];
    t = 0;
    while (left <= right) {
      nums[left++] = tmp[t++];
    }
  };
  std::function<void(int, int)> m_sort = [&](int left, int right) {
    if (left >= right) return;
    int mid = left + right >> 1;
    m_sort(left, mid);
    m_sort(mid + 1, right);
    merge(left, mid, right);
  };
  m_sort(0, len - 1);
  cout << "merge: " << endl;
  for (auto& it : nums) {
    cout << it << " " << endl;
  }
}

void quickSort(vector<int> nums) {
  int len = nums.size();
  std::function<void(int, int)> q_sort = [&](int left, int right) {
    int i = left, j = right, t, tmp;
    if (left > right) return;
    tmp = nums[left];
    while (i != j) {
      while (nums[j] >= tmp && i < j) j--;
      nums[i] = nums[j];
      while (nums[i] <= tmp && i < j) i++;
      nums[j] = nums[i];
      //if (i < j) std::swap(nums[i], nums[j]);
    }
    //nums[left] = nums[i];
    nums[i] = tmp;
    q_sort(left, i - 1);
    q_sort(i + 1, right);
  };
  q_sort(0, len - 1);
  cout << "quick: " << endl;
  for (auto& it : nums) {
    cout << it << " " << endl;
  }
}



void adjust2(vector<int>& arr, int len, int index) {
  int left = 2 * index + 1;   // index的左子节点
  int right = 2 * index + 2;  // index的右子节点
  int maxIdx = index;
  if (left < len && arr[left] > arr[maxIdx]) maxIdx = left;
  if (right < len && arr[right] > arr[maxIdx]) maxIdx = right;

  if (maxIdx != index) {
    swap(arr[maxIdx], arr[index]);
    adjust2(arr, len, maxIdx);
  }
}

// 堆排序
void heapSort2(vector<int> arr) {
  // 构建大根堆（从最后一个非叶子节点向上）
  int size = arr.size();
  for (int i = size / 2 - 1; i >= 0; i--) {
    adjust2(arr, size, i);
  }

  // 调整大根堆
  for (int i = size - 1; i >= 1; i--) {
    swap(arr[0], arr[i]);  // 将当前最大的放置到数组末尾
    adjust2(arr, i, 0);     // 将未完成排序的部分继续进行堆排序
  }
  cout << "heap2: " << endl;
  for (auto& it : arr) {
    cout << it << " " << endl;
  }
}

void heapSort(vector<int> nums) {
  int len = nums.size();
  std::function<void(vector<int>&, int, int)> adjust =
      [&](vector<int>& arr, int size, int index) {
        int child = 2 * index + 1;
        int parent = index;
        while (child < size) {
          if (child + 1 < size && nums[child + 1] > nums[child]) child++;
          if (nums[child] > nums[parent]) {
            std::swap(nums[child], nums[parent]);
            parent = child;
          }
          child = child * 2 + 1;
        }
      };

  for (int i = len / 2 - 1; i >= 0; i--) {
    adjust(nums, len, i);
  }
  for (int i = len - 1; i >= 1; i--) {
    std::swap(nums[0], nums[i]);
    adjust(nums, i, 0);
  }
  cout << "heap: " << endl;
  for (auto& it : nums) {
    cout << it << " " << endl;
  }
}

int quickSelect(vector<int> nums, int k) {
  int len = nums.size();
  std::function<std::pair<int, int>(int, int)> q_select = [&](int left, int right) {
    int pivot = nums[left];
    int i = left, j = right;
    while (i < j) {
      while (nums[j] >= pivot && i < j) j--;
      nums[i] = nums[j];
      while (nums[i] <= pivot && i < j) i++;
      nums[j] = nums[i];
    }
    nums[i] = pivot;
    if (k < i + 1)
      return q_select(left, i - 1);
    else if (k > i + 1)
      return q_select(i + 1, right);
    else
      return std::make_pair(nums[i], i + 1);
  };
  return q_select(0, len).first;
}

int main() {
  vector<int> a = {4,4,8,9,12,1,9,8,11,5,6,20};
  //bubleSort(a);
  //selectionSort(a);
  //insertionSort(a);
  //shellSort(a);
  //mergeSort(a);
  quickSort(a);
  heapSort(a);
  heapSort2(a);
}