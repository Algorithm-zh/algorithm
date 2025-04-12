#include <bits/stdc++.h>
#include <cstring>
using namespace std;
const int N = 2e5 + 10, null = 0x3f3f3f3f;//开放寻址法一般开二倍空间
int h[N];//hash表
//开放寻址法(线性探测)
int find(int x)
{
  int k = (x % N + N) % N;//保证t为非负数并且在范围内
  while(h[k] != null && h[k] != x)//这表示查找的位置已经有值占领了并且不是它自己
  {
    k ++;
    if(k == N)k = 0;//从头再开始找
  }
  return k;
}
int main (int argc, char *argv[]) {
  char ch;
  int n, x;
  cin >> n;
  memset(h, 0x3f, sizeof h);
  while (n --)
  {
    cin >> ch >> x; 
    int k = find(x);
    switch (ch) {
      case 'I': 
        h[k] = x; 
      break;
      case 'Q':
        if(h[k] == null)cout << "No" << endl;
        else cout << "Yes" << endl;
      break;
    }
  }

  return 0;
}
