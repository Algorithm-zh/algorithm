#include <algorithm>
#include <cstring>
#include <functional>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
const int N = 505;
using PII = pair<int, int>;
/*
 * 在1的基础上增加了数据规模，1的代码即会超时，所以需要优化
 * 看1的算法，每次都需要遍历dist数组，从中找到最小值，一次是o(n)
 * 外层又循环了n次，所以时间复杂度是o(n^2)
 * 所以优化方案可以从求最小值入手，便想到了小根堆，堆顶即是最小值
 * 可以使用priority_queue存储插入距离和节点的编号
 *
 * 堆优化版Dijkstra算法寻找距离最短的点时使用的是堆，每次时间复杂度为O(1)，总共循环n次，所以时间复杂度为O(n)，而更新堆的时间复杂度为O(logm)
 * 所以时间复杂度为o(nlogm)，所以堆优化版适合稀疏图
 * 
*/
int n, m;
int g[N][N];
bool st[N];//表示该点到原点的最短距离已经确定
int dist[N];//表示每个点到原点的距离
//小根堆(自动排序)
priority_queue<PII, vector<PII>, greater<PII>> heap;
int Dijkstra()
{
  memset(dist, 0x3f, sizeof dist);//初始为到原点的距离全部是最大值
  dist[1] = 0;//自己到自己为0
  heap.push({0, 1});//距离0,节点1,即自己到自己的距离为0
  for(int i = 1; i <= n; i ++)
  {
    int ver = heap.top().second, distance = heap.top().first;//得到最小值
    st[ver] = true;
    for(int j = 1; j <= n; j ++)
    {
      if(!st[j])
      {
        if(dist[j] > distance + g[ver][j])
          dist[j] = distance + g[ver][j];
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
