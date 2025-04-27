#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, M = 2e5 + 10;
/*
*  Kruskal的算法思想是维护一个边集合，将其从小到大进行排序，
*  如何从中选出最小的边加入到生成树中，如果加入该边后生成树没有形成回路，
*  那么该边即是最小生成树中的边, 回路通过并查集来判断
*
*  Kruskal算法和prime算法的区别:
*  prime算法是基于点的贪心算法，它维护的是一个dist,即每个点到原点的距离的最小值，
*  而由于它每次加入新点之前都要判断该点是否在生成树集合中，
*  这就从根本上决定了它不会形成回路，也就不需要判断回路
*
*  Kruskal算法是基于边的贪心算法，它每次都是从边中找最小值，没有对点进行判断，
*  所以它就有可能形成回路，所以需要判断
*
*/
int n, m, cnt;//cnt记录加入的边数有没有到达点数-1个
int f[N];
struct Edge
{
  int u, v, w;
  bool operator < (const Edge & E) const
  {
    return w < E.w;
  }
}edge[M];
int find(int x)
{
  if(x != f[x])f[x] = find(f[x]);
  return f[x];
}
int Kruskal()
{
  int ans = 0;
  //遍历边集合，按升序排序
  for(int i = 0; i < m; i ++)
  {
    int u = edge[i].u, v = edge[i].v, w = edge[i].w;
    int a = find(u), b = find(v);
    if(a != b)
    {
      f[b] = f[a];
      ans += w;
      cnt ++;
    }
  }
  if(cnt != n - 1)return 0x3f3f3f3f;
  else return ans;
}
int main (int argc, char *argv[]) {
  cin >> n >> m;
  for(int i = 1; i <= n; i ++)f[i] = i;
  for(int i = 0; i < m; i ++)
  {
    int u, v, w;
    cin >> u >> v >> w;
    edge[i] = {u, v, w};// 由于它会用并查集进行判断，所以这里不需要判断有没有重边 
  }
  sort(edge, edge + m);
  int ans = Kruskal();
  if(ans == 0x3f3f3f3f)cout << "impossible"; 
  else cout << ans;

  return 0;
}
