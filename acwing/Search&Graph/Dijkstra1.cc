#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 505;
/*
* Dijkstra的算法思想是维护一个dist数组
* 1.记录每个点到原点的距离
* 2.遍历dist数组，找到st[i]为false的最小值，这就是该点到原点的最短距离
* 3.遍历该点到其它点的距离g[i][j] 加上 dist[i],如果小于dist[j],那就更新dist[j] = dist[i] + g[i][j]
* 重复第2条
*/
int n, m;
int g[N][N];
bool st[N];//表示该点到原点的最短距离已经确定
int dist[N];//表示每个点到原点的距离
int Dijkstra()
{
  memset(dist, 0x3f, sizeof dist);//初始为到原点的距离全部是最大值
  dist[1] = 0;//自己到自己为0
  //循环n次即能得到最终值
  for(int i = 1; i <= n; i ++)
  {
    int t = -1;
    for(int j = 1; j <= n; j ++)
    {
      //遍历dist数组，从未确定最小值里面找到其中最小的一个，此时这个dist即为该点到原点的最小值
      if(!st[j] && (t == -1 || dist[t] >= dist[j]))
        t = j;
    }
    st[t] = true;
    //用确定的t点遍历到其它点的距离，找出可以更新距离的点进行更新
    for(int j = 1; j <= n; j ++)
    {
      if(!st[j])
      {
        if(dist[j] > dist[t] + g[t][j])
          dist[j] = dist[t] + g[t][j];
      }
    }
  }
  if(dist[n] != 0x3f3f3f3f)return dist[n];
  return -1;
}
int main (int argc, char *argv[]) {
  
  cin >> n >> m;
  memset(g, 0x3f, sizeof g);
  for(int i = 0; i < m; i ++)
  {
    int x, y, z;
    cin >> x >> y >> z;
    g[x][y] = min(g[x][y], z);//重边
  }
  cout << Dijkstra();
  
  return 0;
}
