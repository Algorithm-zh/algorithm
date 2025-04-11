#include <algorithm>
#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int p[N];//存储每个节点的父节点
int find(int x)
{
  if(x != p[x])p[x] = find(p[x]);//路径压缩,让每个节点的父节点是根节点，就可以做到一步查询
  return p[x];
}
void merge(int x, int y)
{
  if(find(x) != find(y))
    p[find(x)] = find(y);
}
int main()
{
  int n, m;
  cin >> n >> m;
  for(int i = 1; i <= n; i ++)p[i] = i;
  for(int i = 0; i < m; i ++)
  {
    char ch;
    int a, b;
    cin >> ch >> a >> b;
    switch (ch) {
      case 'M': 
        merge(a, b);
      break;
      case 'Q':
        if(find(a) == find(b)) 
          cout << "Yes" << endl;
        else
          cout << "No" << endl;
      break;
    }
  }

  return 0;
}
