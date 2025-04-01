#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5 + 10, M = N * 31;
int son[M][2];
int idx;
//将每个数按二进制插到trie树里，然后查询时尽量走相反方向，反方向取得的即是和当前异或最大值
void insert(int x)
{
  int p = 0;
  for(int i = 30; i >= 0; i --)
  {
    int u = x >> i & 1;
    if(!son[p][u])son[p][u] = ++ idx;
    p = son[p][u];
  }
}
int query(int x)
{
  int p = 0, ans = 0;
  for(int i = 30; i >= 0; i --)
  {
    int u = x >> i & 1;
    if(son[p][!u])
    {
      p = son[p][!u];
      ans = ans * 2 + !u;
    }
    else
    {
      p = son[p][u];
      ans = ans * 2 + u;
    }
  }
  return x ^ ans;//异或值
}

