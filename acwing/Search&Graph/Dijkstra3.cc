#include <bits/stdc++.h>
#include <cstring>
using namespace std;
using PII = pair<int, int>;
const int N = 1.5e5 + 10;
//使用小根堆存每个点到原点的距离的最小值
priority_queue<PII, vector<PII>, greater<PII>> q;
int n, m, idx;
int e[N], ne[N], h[N], w[N];
int dist[N];
bool st[N];//哪个结点的最小值已经确定
//在二的基础上改为使用链式前向星存图
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
  while(!q.empty())//因为就是找n-1个点到原点的距离，所以其实就是遍历n次(重复加入的点都跳过了)
  {
    auto [distance, x] = q.top();q.pop();
    //该点之前已经使用过，跳过
    if(st[x])continue;
    st[x] = true;//x节点的最小值已经确定
    for(int i = h[x]; i != -1; i = ne[i])
    {
      int j = e[i];
      int d = w[i];
      //用x结点到其他点的距离更新其他点到原点的距离
      if(dist[x] + d < dist[j])
      {
        dist[j] = dist[x] + d; 
        q.push({dist[j], j});
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
