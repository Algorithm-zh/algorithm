#include <algorithm>
#include <bits/stdc++.h>
#include <cstring>
using namespace std;
const int N = 505, M = 1e4 + 10, INF = 0x3f3f3f3f;
/*
* Bellman-ford算法是为了解决Dijkstra算法无法在有负边的图中求最短路径的问题而诞生的
* Dijkstra为什么不能在有负权的图中使用?
*   1---- 100 ----2----- -200 -------3
*   1----- 1  ----3
*   第一次更新dist时dist[3] = 1,3的最小值会被直接确定为1 
*   然后接下来2会被确定为100, 用2更新时dist[3]又会被更新为-100
*   这时dist[3] = -100才是真的最小值,但是它之前已经被确定了,它已经用错误的最小值把它传递出去了
*   而后面的点就会用这个错误的最小值边权进行更新
*
* 为什么Bellman-ford能解决这个问题?
* 因为它每次都把所有边全松弛了一次哈哈哈哈(硬核解决), 
* 上面不是dist[3]早被确定了所以就算dist[3]更新了新的最小值它也不会再用它更新后面的了,它会直接continue
* 但是Bellman-ford不一样,它还会更新dist[3],然后用新的更小的dist[3]再更新后面的,刁德一
* 但是代价就是,时间复杂度很高,每个点都遍历,每次都松弛所有的边,时间复杂度为O(nm)
* 注意:因为从1号到n号走的边数有限制,所以需要设置一个backup数组来备份一下dist数组
* 防止以下情况:
*   1---- 1 ----2---- 1 ----3
*   1---- 3 ----3
*   在边数限制为1的情况下,如果不设置backup数组备份原dist数组,在松弛了1-2之后dist[2]被更为了1
*   而在松弛2-3时,前面的2已经被更新过了,所以dist[3]就被更新为了2,但是这实际上是用了两条边才更新的
*   世纪dist[3]应该为3,所以用backup数组更新,dist[2] = 无穷,dist[3]就不会被更为错的值,也就是说这是为了防止连续松弛
*/
int dist[N], backup[N];
int n, m, k;
struct E
{
  int x, y, z;
}e[M];
int BellmanFord()
{
  memset(dist, 0x3f, sizeof dist);
  dist[1] = 0;
  //最多走k次
  for(int i = 0; i < k; i ++)
  {
    //重要操作:备份,防止连续松弛操作
    memcpy(backup, dist, sizeof dist);
    //对所有边都进行松弛
    for(int j = 0; j < m; j ++)
    {
      int a = e[j].x, b = e[j].y, c = e[j].z; 
      dist[b] = min(dist[b], backup[a] + c);
    }
  }
  //无限大(之所以不是0x3f3f3f3f,是因为它会被负边更新变小)
  if(dist[n] > INF / 2)return INF;
  return dist[n];
}
int main (int argc, char *argv[]) {
  cin >> n >> m >> k;
  for(int i = 0; i < m; i ++)
  {
    int x, y, z;
    cin >> x >> y >> z;
    e[i] = {x, y, z};
  }
  int ans = BellmanFord();
  if(ans == INF)cout << "impossible";
  else cout << ans;
  return 0;
}
