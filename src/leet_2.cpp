#include "pch.h"
using std::vector;


// 947. 移除最多的同行或同列石头 并查集
std::unordered_map<int, int> fa, rank;
void init(int n) {
  for (int i = 0; i < n; i++) {
    fa[i] = i;
    rank[i] = 1;
  }
}

int find(int x) { return x == fa[x] ? x : (fa[x] = find(fa[x])); }

void merge(int i, int j) {
  // fa[find_1202(i)] = find_1202(j);
  int x = find(i), y = find(j);
  if (rank[x] <= rank[y])
    fa[x] = y;
  else
    fa[y] = x;
  if (rank[x] == rank[y] && x != y) rank[y]++;
}
int removeStones(vector<vector<int>>& stones) {
  int len = stones.size();
  //fa = new int[len];
  //rank = new int[len];
  init(len);
  for (int i = 0; i < len; i++) {
    merge(stones[i][0], stones[i][1] + 10000);
  }
  int num = 0;
  for (auto x : fa) {
    if (x.first == x.second) {
      num++;
    }
  }
  return num;
}

