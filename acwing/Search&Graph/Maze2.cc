//在原题基础上加入记录路径的功能
#include <cstring>
#include <iostream>
#include <queue>
#include <utility>
using namespace std;
const int N = 104;
//要求的是最短路径，所以使用bfs求解
//记录哪里已经走过了
int d[N][N];//每一点到起点的距离,初始为-1
int g[N][N];
int n, m;
using PII = pair<int, int>;
PII Prev[N][N];//记录每一个点是从哪个点过来的
int bfs()
{
  queue<PII> q;//core 
  memset(d, -1, sizeof d);
  q.push({0, 0});//将起点加入队列
  d[0][0] = 0;//出发点到自己距离就为0
  int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};//移动的四个方向
  while(!q.empty())
  {
    PII t = q.front();q.pop();
    int x1 = t.first, y1 = t.second;
    for(int i = 0; i < 4; i ++)
    {
      int x = x1 + dx[i], y = y1 + dy[i];
      //越界或者有墙壁没法走或已经走过了
      if(x < 0 || y < 0 || x >= n || y >= m || g[x][y] == 1 || d[x][y] != -1)continue;
      q.push({x, y});
      d[x][y] = d[x1][y1] + 1;
      Prev[x][y] = t;
    }
  }
  //output path
  //reverse output
  int x = n - 1, y = m - 1;
  while(x || y)
  {
    cout << x << ' ' << y << endl;
    auto t = Prev[x][y];
    x = t.first, y = t.second;
  }
  cout << x << ' ' << y << endl;

  return d[n - 1][m - 1];
}
int main (int argc, char *argv[]) {
  cin >> n >> m;
  for(int i = 0; i < n; i ++)
    for(int j = 0; j < m; j ++)
      cin >> g[i][j];
  
  cout << bfs();
  
  return 0;
}
