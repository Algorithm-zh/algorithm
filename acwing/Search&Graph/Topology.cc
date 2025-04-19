#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
const int N = 1e5 + 10;
/*
* 求拓扑序列，首先必须是有向无环图
* 然后找出图中的入度为0的点，删掉，将其加入序列（如果有多个，挨个加进去即可）
* 然后图中就会出现新的入度为0的点，再做上面的操作
* 直到加到终点,如果有环，就会出现还没把全部点加到序列里就出现了没有入度为0的点的情况，此时输出-1
*/
int n, m;
int e[N], ne[N], h[N];
int idx, d[N];//d存储每个点的入度,
queue<int> q; 
int ans[N];//ans存储最终序列
void add(int a, int b)
{
  e[idx] = b;
  ne[idx] = h[a];
  d[b] ++;
  h[a] = idx ++;
}
bool topsort()
{
  int t = 0;//记录序列长度
  for(int i = 1; i <= n; i ++)
    if(!d[i])q.push(i);//先把所有入度为0的点加到队列里
  
  while(!q.empty())
  {
    int a = q.front();q.pop();
    ans[t ++] = a;
    for(int i = h[a]; i != -1; i = ne[i])
    {
      int b = e[i];
      if(-- d[b] == 0)q.push(b);
    }
  }
  return t == n;
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
  if(topsort())
  {
    for(int i = 0; i < n; i ++)
      cout << ans[i] << ' ';
  }else
  {
    cout << -1;
  }
  return 0;
}
