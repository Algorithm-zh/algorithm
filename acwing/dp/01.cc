#include <bits/stdc++.h>
using namespace std;
/*
* 闫式dp分析法:
*          --集合
* 状态表示/
*         \
*          --属性(max,min,..)
*
* 状态计算
*
* 01背包:
* 集合f[i][j]:前i件物品容量不超过j的情况下的价值
* 属性:最大值
* 计算:f[i][j]要么包含第i件物品,要么不包含第i件物品,那么可得出状态转移方程:
* f[i][j] = max(f[i - 1][j - v[i]] + w[i], f[i - 1][j])
* 确定初始值:
* f[i][0]:从前i件物品中选出容量不超过0的背包的价值,那么f[i][0] = 0
* 优化:
* 由于f[i][j]只会用到它上一部f[i-1]的值,所以直接使用一维数组
* 但是它要用到前面的值,所以我们需要倒序遍历,不然前面的值就被覆盖了
*/
const int N = 1005;
int n, m;
int dp[N];
int v[N], w[N];
int main (int argc, char *argv[]) {
  
  cin >> n >> m;
  for(int i = 0; i < n; i ++)
    cin >> v[i] >> w[i];

  for(int i = 0; i < n; i ++)
    for(int j = m; j >= v[i]; j--)
      dp[j] = max(dp[j], dp[j - v[i]] + w[i]); 

  cout << dp[m];

  return 0;
}
