#include <iostream>
using namespace std;
const int N = 11;
//此题思路可以为从第一行开始往下递归
//那么需要记录的就是每一列，还有两个斜线的数字
//记录下路径，当遍历到最后一行就可以输出路径
//那么关键就是斜线怎么算
//一条为y = x + b,另一条为y = b - x,即b = y - x 和 b = y + x,即同一斜线上的y - x y + x得到的值相等
char path[N][N];
bool col[N], dg[2 * N], udg[2 * N];//列和斜线,开二倍是因为下面i+u时会有两倍大的时候的
int n;
void dfs(int u)
{
  //到最后一行了
  if(u == n)
  {
    for(int i = 0; i < n; i ++)
    {
      for(int j = 0; j < n; j ++)
        cout << path[i][j];
      cout << endl;
    }
    cout << endl;
  }
  for(int i = 0; i < n; i ++)
  {
    //列和两个斜线上都没人才能放
    if(!col[i] && !dg[i + u] && !udg[i - u + n])//加n是为了防止为负数
    {
      col[i] = dg[i + u] = udg[i - u + n] = true;
      path[u][i] = 'Q';
      dfs(u + 1);
      path[u][i] = '.';
      col[i] = dg[i + u] = udg[i - u + n] = false;
    }
  }
}
int main()
{
  cin >> n;
  for(int i = 0; i < n; i ++)
    for(int j = 0; j < n; j ++)
      path[i][j] = '.';
  dfs(0);

  return 0;
}
