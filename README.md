### SoftLeetCode

#### Todo
 - [x] �˽�Ī��˹���� https://www.cnblogs.com/AnnieKim/archive/2013/06/15/morristraversal.html
 - [x] �˽⶯̬�滮
 - [ ] ����֮��˫ָ�뷨
 - [ ] LCP No.19 ��Ҷ�ղؼ����ָ�Ⱥ��Ӽ� DP


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
����ջ  �����ۡ��� 42��739��496��316��901��402��581 �⡣
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



���ֲ���<br>