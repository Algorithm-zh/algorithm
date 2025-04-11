#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
const int N = 50005;
int p[N], d[N];
/*
 * 将所有结点维护在一个集合上，通过权值来判断彼此之间的关系
 * d[N]存储的是子节点和父节点之间权值
 * 若a吃b,b吃c,c吃a
 * 则假设a是根节点,则c是第一层节点，b是第二层节点，每一层都能吃上一层，第三层能被第一层吃掉（因为是环状关系)
 * 则d[a] = 0, d[c] = 1, d[b] = 2
 * 如果d[x] >= 3,则对3取余(一共只有三个种族)
 */
int ans = 0;
int find(int x)
{
  if(x != p[x])
  {
    //路径压缩，d[x]就变成x到根节点的权值
    int u = find(p[x]);
    d[x] += d[p[x]];
    p[x] = u;
  }
  return p[x];
}

int main (int argc, char *argv[]) {
  int n, k; 
  cin >> n >> k;
  for(int i = 1; i <= n; i ++)p[i] = i;
  while(k --)
  {
    int t, x, y;
    cin >> t >> x >> y;
    if(x > n || y > n)//2
    {
      ans ++;
      continue;
    }
    int a = find(x);
    int b = find(y);
    if(t == 1)//同类，合并
    {
      if(a == b && (d[x] - d[y]) % 3)//同类的话应该为0
      {
        ans ++;
      }else
      {
        p[a] = b; 
        d[a] = d[y] - d[x];
      }
    }
    else    
    {
      if(a == b && (d[x] - d[y] - 1) % 3)//自己吃自己，是同类，之前已经说了y种族吃x种族
      {
        ans ++;
        continue;
      }else
      {
        p[a] = b;
        d[a] = d[y] + 1 - d[x];
      }
    }
  }
  cout << ans;
  return 0;
}
