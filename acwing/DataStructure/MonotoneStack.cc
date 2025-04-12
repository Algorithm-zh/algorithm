//维护一个单调栈,将遍历所在位置的值与栈顶比较,如果栈顶小于该值则栈顶即所求
//如果不是,则栈顶出栈,直到栈顶小于该值或者栈空为止,最后将该值入栈
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5 + 10;
int s[N], tt;
int main (int argc, char *argv[]) {
  
  int n, x;
  cin >> n;
  for (int i = 0; i < n; i ++) {
    cin >> x;
    while(tt && s[tt] >= x)tt --;
    if(tt) cout << s[tt] << ' '; 
    else cout << -1 << ' ';

    s[++ tt] = x;
  }

  return 0;
}
