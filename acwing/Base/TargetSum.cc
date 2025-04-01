#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5 + 10;
int main()
{
  int a[N], b[N];
  int n, m, x;
  cin >> n >> m >> x;
  for(int i = 0; i < n; i ++)cin >> a[i];
  for(int i = 0; i < m; i ++)cin >> b[i];

  for(int i = 0, j = m - 1; i < n && j >= 0;)
  {
    int sum = a[i] + b[j];
    if(sum == x)
    {
      cout << i << ' ' << j;
      return 0;
    }
    if(sum > x)j --;
    if(sum < x)i ++;
  }
  return 0;
}
