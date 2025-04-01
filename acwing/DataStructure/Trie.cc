#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5 + 10;
int son[N][26], cnt[N];//cnt统计字符串出现次数，son为建立的trie树
int idx;//节点唯一标识
void insert(string str)
{
  int p = 0; 
  for(int i = 0; str[i]; i ++)
  {
    int u = str[i] - 'a';
    if(!son[p][u])son[p][u] = ++ idx;//如果节点不存在那就创建一个节点

    p = son[p][u];//让p节点到子节点上
  }
  cnt[p] ++;
}
int query(string str)
{
  int p = 0;
  for(int i = 0; str[i]; i ++)
  {
    int u = str[i] - 'a';
    if(!son[p][u])return 0;

    p = son[p][u];
  }
  return cnt[p];
}
int main (int argc, char *argv[]) {
  char ch;
  string str;
  int n;
  cin >> n;
  while(n --)
  {
    cin >> ch >> str;
    if(ch == 'I')
      insert(str);
    else
      cout << query(str) << endl;
  }

  return 0;
}
