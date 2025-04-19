#include <cstring>
#include <iostream>
using namespace std;
const int N = 1e5 + 10, M = 2 * N;
int e[M], ne[M], h[N];
//h存储以a为起点的最后一条边的下标
bool st[M];
int n, idx;
int ans = N;
//头插法
void add(int a, int b)
{
  e[idx] = b;
  ne[idx] = h[a];
  h[a] = idx ++;
}
int dfs(int u)
{
  //标记节点已经走过
  st[u] = true;
  int sum = 1; //以当前点为根大小
  int res = 0; //删除该点后每一个连通块大小的最大值
  for(int i = h[u]; i != -1; i = ne[i])
  {
    int t = e[i];
    if(!st[t])
    {
      int s = dfs(t);//返回子节点的节点数
      sum += s;
      res = max(res, s);//找出所有分块中最大的一个
    }
  }
  res = max(res, n - sum);//和到该结点的前面的节点大小比较
  ans = min(ans, res);
  return sum;//返回以该结点为根节点的树的大小
}
int main (int argc, char *argv[]) {
  cin >> n;
  memset(h, -1, sizeof h);
  for(int i = 0; i < n - 1; i ++){
    int a, b;
    cin >> a >> b;
    //以双向图作为无向图
    add(a, b);
    add(b, a);
  }
  dfs(1);
  cout << ans;
  return 0;
}
