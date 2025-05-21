#include <bits/stdc++.h>
using namespace std;
int n;
void Prime(int x)
{
  for(int i = 2; i <= sqrt(x); i ++)
  {
    if(x % i == 0)
    {
      int s = 0;
      while(x % i == 0)
      {
        x /= i;
        s ++;
      }
      cout << i << ' ' << s << endl;
    }
  }
  //如果还有剩下的数,直接输出
  if(x > 1)
    cout << x << ' ' << 1 << endl;
  cout << endl;
}
int main (int argc, char *argv[]) {
  cin >> n;
  while (n --) {
    int x; 
    cin >> x;
    Prime(x);
  }
  
  return 0;
}
