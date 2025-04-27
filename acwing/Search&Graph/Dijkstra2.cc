#include <bits/stdc++.h>
#include <cstring>
using namespace std;
using PII = pair<int, int>;
const int N = 1.5e5 + 10;
/*
 * 在1的基础上增加了数据规模，1的代码即会超时，所以需要优化
 * 看1的算法，每次都需要遍历dist数组，从中找到最小值，一次是o(n)
 * 外层又循环了n次，所以时间复杂度是o(n^2)
 * 所以优化方案可以从求最小值入手，便想到了小根堆，堆顶即是最小值
 * 可以使用priority_queue存储插入距离和节点的编号
 *
 * 堆优化版Dijkstra算法寻找距离最短的点时使用的是堆，每次时间复杂度为O(1)
 * 而更新堆的时间复杂度为O(logn), 也就是说往堆中插入和出堆这两个部分时间复杂度都是o(logn)
 * 而堆插入需要遍历m条边，所以复杂度为O(m)
 * 所以时间复杂度为o((m + n)logn)，m > n, 所以堆优化版适合稀疏图,使用邻接表存储
 * 
*/
//使用小根堆存每个点到原点的距离的最小值
priority_queue<PII, vector<PII>, greater<PII>> q;
int n, m, idx;
int e[N], ne[N], h[N], w[N];
int dist[N];
bool st[N];//哪个结点的最小值已经确定
void add(int x, int y, int z)
{
  e[idx] = y;
  w[idx] = z;
  ne[idx] = h[x];
  h[x] = idx ++;
}
int Dijkstra()
{
  memset(dist, 0x3f, sizeof dist);
  dist[1] = 0;
  q.push({0, 1});
  while(!q.empty())//n
  {
    auto [distance, x] = q.top();q.pop();//logn 
    //该点之前已经使用过，跳过
    if(st[x])continue;
    st[x] = true;//x节点的最小值已经确定
    for(int i = h[x]; i != -1; i = ne[i])//n
    {
      int j = e[i];
      int d = w[i];
      //用x结点到其他点的距离更新其他点到原点的距离
      if(dist[x] + d < dist[j])
      {
        dist[j] = dist[x] + d; 
        q.push({dist[j], j});//logn
      }
    }
  }
  return dist[n];  
}
int main (int argc, char *argv[]) {
  memset(h, -1, sizeof h);
  cin >> n >> m;
  for(int i = 0; i < m; i ++)
  {
    int x, y, z;
    cin >> x >> y >> z;
    add(x, y, z);
  }
  int ans = Dijkstra();
  if(ans == 0x3f3f3f3f)cout << -1;
  else cout << ans;
  return 0;
}
