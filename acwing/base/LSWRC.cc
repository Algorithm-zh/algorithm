#include <iostream>
#include <algorithm>
using namespace std;
const int N = 100010;
int main()
{
  int n, a[N], s[N]{0}, len = 0;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];

  for(int l = 0, r = 0; r < n; r ++)
  {
    s[a[r]] ++;
    while(s[a[r]] > 1)s[a[l ++]] --;
    len = max(len, r - l + 1);
  }
  cout << len;

  return 0;
}
