### SoftLeetCode

#### Todo
 - [x] �˽�Ī��˹���� https://www.cnblogs.com/AnnieKim/archive/2013/06/15/morristraversal.html
 - [x] �˽⶯̬�滮
 - [x] [����](https://leetcode-cn.com/problems/permutations/solution/hui-su-suan-fa-python-dai-ma-java-dai-ma-by-liweiw/)
 - [ ] ����֮��˫ָ�뷨
 - [ ] LCP No.19 ��Ҷ�ղؼ����ָ�Ⱥ��Ӽ� DP
 - [x] ���ֲ��� [һ�Ĵ���㶨���ֲ��Ҽ���������](https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/solution/yi-wen-dai-ni-gao-ding-er-fen-cha-zhao-j-ymwl/)[300. �����������](https://leetcode-cn.com/problems/longest-increasing-subsequence/solution/zui-chang-shang-sheng-zi-xu-lie-by-leetcode-soluti/)
 - [ ] ����ָ�� https://leetcode-cn.com/problems/find-the-duplicate-number/solution/xun-zhao-zhong-fu-shu-by-leetcode-solution/
 - [ ] Manacher �㷨 [������Ӵ�](https://leetcode-cn.com/problems/longest-palindromic-substring/solution/zui-chang-hui-wen-zi-chuan-by-leetcode-solution/) [647. �����Ӵ�](https://leetcode-cn.com/problems/palindromic-substrings/solution/hui-wen-zi-chuan-by-leetcode-solution/)
 - [ ] �������� https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/solution/hua-dong-chuang-kou-by-powcai/
 - [ ] �����㷨 [148. ��������](https://leetcode-cn.com/problems/sort-list/solution/pai-xu-lian-biao-by-leetcode-solution/)

#### �����
![](����.png)

#### �ѽӴ�����
���顢�ַ��� 
<br>
����������


#### ��¼
No.141~142 ��⻷������<br>
1��˫ָ���⻷������Ļ�ʱ��Ϊʲô��ָ���뻷��һȦû�����ʱ��ͻ�Ϳ�ָ��������
```
�� ���ĳ���ΪA,��ָ�����뻷��ʱ���ָ���ڻ��е�λ��B(ȡֵ��Χ0��A-1),
������ָ������ʱ [��ָ���ڻ�������C] ,��
    C = ( B + 2C) % A,�ȼ��� 
    An + C = B + 2C,�ϲ���
    C = An - B
    �� n=1 ʱ , 0 <= C < A
�� ��ָ���ڵ�һȦ�ض��ܺͿ�ָ������
```
LCP No.19 ��Ҷ�ղؼ�<br>
2��DP˼·��

No.416. �ָ�Ⱥ��Ӽ�<br>
3��DP˼·��

No.530. ��������������С���Բ�<br>
4�����������ǡ�ô�С��������

No.24. �������������еĽڵ�<br>
5���ݹ�͵������ַ���

No.116. ���ÿ���ڵ����һ���Ҳ�ڵ�ָ��<br>
6�����Ե������ݹ顢bfs��bfs����ʹ�ö��пռ临�ӶȽϴ󣬵ݹ��ʱ��̣��ݹ��ڴ����Ľ��١�˼·���ǣ�ͬһ���ڵ�������ӽڵ�����ڵ��next�����ҽڵ㣬
�������ӽڵ��next���Ǹø��ڵ��next��left������ø��ڵ��nextΪnull�ͽ��뵽��һ�������ڵ㣬�������ϲ�����

No. 738. ��������������<br>
7��̰�ģ� ���������֣��ҵ���һ��N[i - 1] > N[i]������i - 1��������ǰ��Ҳ����ȫ��-1����i�����Ժ������ȫ����9

No. 714. ������Ʊ�����ʱ����������<br>
8��dp[i][0]�����i�����ӵ�й�Ʊʱ������룬dp[i][1]�����i�����ӵ�й�Ʊʱ�������
```cpp
       dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i] - fee);
       dp[i][1] = max(dp[i - 1][0] - prices[i], dp[i - 1][1]);
```

No. 10. ������ʽƥ��<br>
9����̬�滮�������̫���ˡ�����

No. 169. ����Ԫ��<br>
10��Ħ��ͶƱ��

22. ��������<br>
���� ��̬�滮

1202. �����ַ����е�Ԫ�� <br>
���鼯��https://zhuanlan.zhihu.com/p/93647900/
ģ�壺
```cpp
    int* fa, *rank;
    void init_1202(int n) {
      for (int i = 0; i < n; i++) {
        fa[i] = i;
        rank[i] = 1;
      }
    }

    int find_1202(int x) {
        return x == fa[x] ? x : (fa[x] = find_1202(fa[x]));
    }

    void merge_1202(int i, int j) {
        //fa[find_1202(i)] = find_1202(j);
      int x = find_1202(i), y = find_1202(j);
      if (rank[x] <= rank[y])
        fa[x] = y;
      else
        fa[y] = x;
      if (rank[x] == rank[y] && x != y) rank[y]++;
    }
```
```cpp
    unordered_map<int, int> f, rank;
    int find(int x) {
        if (!f.count(x)) {
            f[x] = x;
            rank[x] = 1;
        }
        return f[x] == x ? x : f[x] = find(f[x]);
    }

    void unionSet(int x, int y) {
        int fx = find(x), fy = find(y);
        if (fx == fy) {
            return;
        }
        if (rank[fx] < rank[fy]) {
            swap(fx, fy);
        }
        rank[fx] += rank[fy];
        f[fy] = fx;
    }

    int numberOfConnectedComponent() {
        int num = 0;
        for (auto &[x, fa] : f) {
            if (x == fa) {
                num++;
            }
        }
        return num;
    }

```

739. ÿ���¶� <br>
����ջ https://zhuanlan.zhihu.com/p/61423849 �����ۡ��� 42��739��496��316��901��402��581 �⡣
![](����ջ.png)
<br>ģ�壺
```cpp
stack<int> mono_stk;
for (��������)) {
    while (ջ�ǿ� && ջ��Ԫ�ش��ڵ�ǰԪ��) {
        ���½��;
        ջ��Ԫ�س�ջ;
    }
    ��ջ;
}
```

46. ȫ����<br>
����

208. ʵ�� Trie (ǰ׺��) [��Ŀ](https://leetcode-cn.com/problems/implement-trie-prefix-tree/solution/)<br>
ǰ׺��ʵ�֣������Զ���ȫ��
- �ҵ�����ͬһǰ׺��ȫ����ֵ��
- ���ʵ���ö���ַ��������ݼ���
#### Trie ����һ���и�������������������ֶΣ���
- ��� R ��ָ���ӽ������ӣ�����ÿ�����Ӷ�Ӧ��ĸ�����ݼ��е�һ����ĸ��
- �����мٶ� R Ϊ 26��Сд������ĸ��������
- �����ֶΣ���ָ���ڵ��Ƕ�Ӧ���Ľ�β����ֻ�Ǽ�ǰ׺��




#### 2020.1.21 - 59 / 125
- [x] 1489. �ҵ���С��������Ĺؼ��ߺ�α�ؼ���
- [x] 337. ��ҽ��� III
- [x] 309. ���������Ʊʱ�����䶳��
- [x] 300. �����������


#### 2020.1.22 - 59 / 125
- [x] 989. ������ʽ�������ӷ� ��λɨ��
- [x] 152. �˻����������  ע�⸺�����
- [x] 581. �����������������
- [ ] 221. ��������� (�������)


#### 2020.1.24 - 70 / 139
- [x] 674. ������������� dp
- [x] 221. ���������
- [x] 437. ·���ܺ� III
- [x] 560. ��ΪK�������� ������ʱ  ����ǰ׺
- [x] 55. ��Ծ��Ϸ �ݹ鳬ʱ
- [x] 56. �ϲ�����
- [x] 78. �Ӽ� ����


#### 2020.1.25 - 71 / 139
- [x] 200. �������� ���鼯
- [x] 959. ��б�ܻ�������
- [x] 79. ��������
- [x] 236. �������������������

#### 2020.1.26 - 78 / 150
- [x] 1128. �ȼ۶���ŵ���ƶԵ�����
- [x] 34. �����������в���Ԫ�صĵ�һ�������һ��λ��
- [x] 35. ��������λ��
- [x] 33. ������ת��������
- [x] 96. ��ͬ�Ķ���������
- [x] 139. ���ʲ��
- [x] 394. �ַ�������


#### 2020.1.27 - 81/ 155
- [x] 1579. ��֤ͼ����ȫ����
- [x] 240. ������ά���� II
- [x] 208. ʵ�� Trie (ǰ׺��)
- [x] 148. ��������


#### 2020.1.28 - 81/ 155
- [x] 724. Ѱ���������������
- [x] 105. ��ǰ��������������й�������� ��ϣ���λ�ü���ʱ�����
- [x] 114. ������չ��Ϊ���� ��������

#### 2020.1.29 - 85/ 160
- [x] 1631. ��С��������·�� ���鼯
- [x] 207. �γ̱� ��������
- [x] 98. ��֤���������� ǰ����� ע��߽�

