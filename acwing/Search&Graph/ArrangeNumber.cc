#include <iostream>
using namespace std;
const int N = 8;
int n;
int path[N];//记录路径
bool st[N];//是否有过该数字
//每一位遍历n个数字，记录哪个数字已经被用了，防止重复选，回溯后将选中标志再取消,以实现剪枝
/*
*                 _ _ _
*          1_ _   2_ _     3_ _
*      12_ 13_    21_ 23_  31_ 32_
*      123 132    213 231  312 321
*
*/
//u代表遍历到哪一位了
void dfs(int u)
{
  if(u == n)
  {
    for(int i = 0; i < n; i ++)cout << path[i] << ' ';
    cout << endl;
  }
  for(int i = 1; i <= n; i ++)
  {
    //没有用过该数字
    if(!st[i])
    {
      st[i] = true;
      path[u] = i;
      dfs(u + 1);
      //回溯就将状态恢复
      st[i] = false;
    }
  }

}
int main (int argc, char *argv[]) {
  cin >> n;
  dfs(0);

  return 0;
}
