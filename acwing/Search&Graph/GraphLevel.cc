#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
const int N = 1e5 + 10;
int n, m, idx;
int h[N], e[N], ne[N];
queue<int> q;
int d[N];//每个点到1点的距离，初始化为-1还能标记为没走过
void add(int a, int b)
{
  e[idx] = b;
  ne[idx] = h[a];
  h[a] = idx ++;
}
//求最短距离，用bfs
int bfs(int u)
{
  q.push(u);
  memset(d, -1, sizeof d);
  d[u] = 0;
  while (!q.empty()) {
    int a = q.front();q.pop();
    for(int i = h[a]; i != -1; i = ne[i])
    {
      int b = e[i];
      if(d[b] == -1)//没走过
      {
        q.push(b);
        d[b] = d[a] + 1;
      }
    }
  }
  return d[n];
}
int main (int argc, char *argv[]) {
  cin >> n >> m;
  memset(h, -1, sizeof h);
  for(int i = 0; i < m; i ++)
  {
    int a, b;
    cin >> a >> b;
    add(a, b);
  }
  cout << bfs(1);
  return 0;
}
