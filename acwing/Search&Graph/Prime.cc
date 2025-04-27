#include <bits/stdc++.h>
using namespace std;
const int N = 505, INF = 0x3f3f3f3f;
/*
* prime算法是贪心算法,和Dijkstra算法类似
* 维护一个dist数组，dist数组存储每个点到已经维护好的集合的距离的最小值
* 注意这个dist数组和Dijkstra算法的不同之处，Dijkstra算法是每个点到原点距离的最小值
* 每次从dist里找在非生成树集合里的点中找出最小的，那么这个点就能加入集合
* 然后用这个点到其它点的距离更新dist,也就是dist[j] = min(g[t][j], dist[j]);
* 然后循环n次将所有点加到集合里
*/
int g[N][N];//存图
int dist[N];
bool st[N];//存储该点是否已经确定在集合中
int n, m, res;//res存储权值
int Prime()
{
  memset(dist, 0x3f, sizeof dist);
  dist[1] = 0;//从1点开始扩散生成树，1点到自己这个集合的距离为0
  //循环n次维护dist数组
  for(int i = 0; i < n; i ++)
  {
    int t = -1;
    //找出最小的dist
    for(int j = 1; j <= n; j ++)
      if(!st[j] && (t == -1 || dist[t] > dist[j]))
        t = j;
    if(dist[t] == INF)return INF;//如果为INF说明剩余的点无法到达生成树集合，最小生成树不存在，直接返回
    st[t] = true;//该点加入到集合里

    res += dist[t];//将权值加到结果里 

    //用t点更新dist数组,这里的更新是和Dijkstra的最大区别
    for(int j = 1; j <= n; j ++)
      dist[j] = std::min(dist[j], g[t][j]);
  }
  return res;
}
int main (int argc, char *argv[]) {
  cin >> n >> m;
  memset(g, 0x3f, sizeof g);//一定要初始化，不然不存在的边就变成最小边了
  for(int i = 0; i < m; i ++)
  {
    int x, y, z;
    cin >> x >> y >> z;
    g[x][y] = std::min(g[x][y], z);//重边，找出最小的作为边
    g[y][x] = g[x][y];//无向图
  }
  int m = Prime();
  if(m == INF)cout << "impossible";
  else cout << m;

  return 0;
}
