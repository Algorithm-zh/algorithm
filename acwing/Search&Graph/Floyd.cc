#include <algorithm>
#include <bits/stdc++.h>
#include <cstring>
using namespace std;
const int N = 205, M = 20005;
int dist[N][N];
int n, m, k;
/*
* floyd算法是多源最短路径算法,它是基于dp的算法,所以可以使用闫式dp分析法来做
* 状态表示: f[k][i][j]表示经过前k个点从i到j距离 属性:最小值
* 状态计算: f[k][i][j] = min(f[k - 1][i][j], f[k - 1][i][k] + f[k - 1][k][j])
*
*   假设节点序号是从1到n。
*   假设f[0][i][j]是一个n*n的矩阵，第i行第j列代表从i到j的权值，如果i到j有边，那么其值就为ci,j（边ij的权值）。
*   如果没有边，那么其值就为无穷大。
*
*   f[k][i][j]代表（k的取值范围是从1到n），在考虑了从1到k的节点作为中间经过的节点时，从i到j的最短路径的长度。
*
*   比如，f[1][i][j]就代表了，在考虑了1节点作为中间经过的节点时，从i到j的最短路径的长度。
*   分析可知，f[1][i][j]的值无非就是两种情况，而现在需要分析的路径也无非两种情况，i=>j，i=>1=>j：
*   【1】f[0][i][j]：i=>j这种路径的长度，小于，i=>1=>j这种路径的长度
*   【2】f[0][i][1]+f[0][1][j]：i=>1=>j这种路径的长度，小于，i=>j这种路径的长度
*   形式化说明如下：
*   f[k][i][j]可以从两种情况转移而来：
*   【1】从f[k−1][i][j]转移而来，表示i到j的最短路径不经过k这个节点
*   【2】从f[k−1][i][k]+f[k−1][k][j]转移而来，表示i到j的最短路径经过k这个节点
*
*   总结就是：f[k][i][j]=min(f[k−1][i][j],f[k−1][i][k]+f[k−1][k][j])
*   从总结上来看，发现f[k]只可能与f[k−1]有关。所以可以直接覆盖
*
*
*/
void Floyd()
{
  for(int k = 1; k <= n; k ++) 
    for(int i = 1; i <= n; i ++)
      for(int j = 1; j <= n; j ++)
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
}
int main (int argc, char *argv[]) {
  cin >> n >> m >> k;
  memset(dist, 0x3f, sizeof dist);
  for(int i = 1; i <= n; i ++)dist[i][i] = 0;//自己到自己为0
  for(int i = 0; i < m; i ++)
  {
    int x, y, z;
    cin >> x >> y >> z;
    dist[x][y] = min(dist[x][y], z);
  }
  Floyd(); 
  while(k --)
  {
    int x, y;
    cin >> x >> y;
    if(dist[x][y] >= 0x3f3f3f3f / 2)cout << "impossible" << endl;
    else cout << dist[x][y] << endl;
  }
  return 0;
}
