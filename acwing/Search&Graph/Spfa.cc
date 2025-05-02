#include <algorithm>
#include <bits/stdc++.h>
#include <cstring>
#include <queue>
#include <utility>
using namespace std;
const int N = 1e5 + 10;
/*
 * Spfa算法和Bellmanford算法一样都是解决存在负权的图的最短路径问题
 *
* Dijkstra算法是用最短的边的去更新每条边
* Spfa是用上次更新的边去更新每条边
* Bellmanford算法则是暴力的每次都把所有的边全更新了
* Spfa和Dijkstra算法的区别说白了就是Dijkstra算法使用的是优先队列, 小根堆,每次取的都是dist里最小的
* 而Spfa算法则是使用的普通队列,每次都是取队头,没有非德去取最小的
* 为什么不取最小值就能解决存在负权问题?
*   因为Dijkstra算法是在短路径上进行松弛操作,但是一旦出现负权,就会出现比之前更短的路径,使之前的短路径失效
*   而Spfa只是单纯的取上次更新的路径进行更新
*/
int e[N], ne[N], h[N], w[N], dist[N], idx;
int n, m;
bool st[N];
queue<int> q;
void add(int x, int y, int z)
{
  e[idx] = y;
  ne[idx] = h[x]; 
  w[idx] = z;
  h[x] = idx ++;
}
int Spfa()
{
  memset(dist, 0x3f, sizeof dist);
  dist[1] = 0;
  q.push(1);//1到自己的距离为0
  while(!q.empty())
  {
    auto a = q.front(); q.pop();//每次取最近一次更新的点
    if(st[a])continue;
    st[a] = true;
    for(int i = h[a]; i != -1; i = ne[i])
    {
      int b = e[i];
      if(dist[b] > dist[a] + w[i])
      {
        dist[b] = dist[a] + w[i];
        q.push(b);
        //关键之处: b点被更新了,所以将他标记取消,下次可以使用它来更新其他点
        //也就是说,直接把Dijkstra算法的这里加上这句代码它一样能解决负权问题
        st[b] = false;
      }
    }
  }
  return dist[n];
}
int main (int argc, char *argv[]) {
  cin >> n >> m; 
  memset(h, -1, sizeof h);
  for(int i = 0; i < m; i ++)
  {
    int x, y, z;
    cin >> x >> y >> z;
    add(x, y, z);
  }
  int ans = Spfa();
  if(ans > 0x3f3f3f3f / 2)cout << "impossible";
  else cout << dist[n];
  return 0;
}

