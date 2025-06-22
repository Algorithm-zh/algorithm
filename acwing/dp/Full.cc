#include <bits/stdc++.h>
using namespace std;
const int N = 1004;
/*
* 闫式dp分析法:
*          --集合
* 状态表示/
*         \
*          --属性(max,min,..)
*
* 状态计算
*
* 完全背包:
* 集合f[i][j]:前i件物品容量不超过j的情况下的价值
* 属性:最大值
* 计算:f[i][j]要么包含第i件物品*k个(j >= v[i]*k, k >= 1),要么不包含第i件物品,那么可得出状态转移方程:
* f[i][j] = max(f[i - 1][j - v[i]*k] + w[i]*k, f[i - 1][j])
* 确定初始值:
* f[i][0]:从前i件物品中选出容量不超过0的背包的价值,那么f[i][0] = 0
* 优化:
* f[i][j] = max(f[i - 1][j - v[i]*k] + w[i]*k, f[i - 1][j])
* f[i][j-v[i]] = max(f[i - 1][j - v[i]*(k+1)] + w[i]*k, f[i - 1][j-v[i]])
* 展开看:
* f[i][j] = max(f[i-1][j-v[i]]+w[i], f[i-1][j-2v[i]]+2w[i], f[i-1][j-3v[i]]+3w[i]....,f[i-1][j])
* f[i][j-v[i]] = max(f[i-1][j-2v[i]]+w[i], f[i-1][j-3v[i]]+2w[i], f[i-1][j-4v[i]]+3w[i]....f[i-1][j-v[i]])
* 变形得:
* f[i][j-v[i]]+w[i]= max(f[i-1][j-2v[i]]+2w[i], f[i-1][j-3v[i]]+3w[i], f[i-1][j-4v[i]]+4w[i]....f[i-1][j-v[i]]+w[i])
* 看出f[i][j-v[i]]+w[i]就是f[i-1][j-v[i]*k]+w[i]*k
* 代入得出:
* f[i][j] = max(f[i][j-v[i]]+w[i], f[i-1][j])
* 从方程里可以看出它需要前面的数据,所以不能和01一样倒着遍历了
* 优化:
* f[j] = max(f[j - v[i]] + w[i], f[j])
*/
int m, n;
int v[N], w[N];
int dp[N];
int main (int argc, char *argv[]) {

  cin >> n >> m;
  for(int i = 0; i < n; i ++)
    cin >> v[i] >> w[i];

  for(int i = 0; i < n; i ++)
    for(int j = v[i]; j <= m; j ++)
      dp[j] = max(dp[j - v[i]] + w[i], dp[j]);

  cout << dp[m];

  
  return 0;
}
