#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int main()
{
  int n, k, q[N];
  cin >> n >> k;
  for(int i = 0; i < n; i ++)cin >> q[i];
  while(k --)
  {
    int t;
    cin >> t;
    int l = -1, r = n;
    while(l + 1 < r)
    {
      int mid = r + (l - r) / 2;
      if(q[mid] < t)l = mid;
      else r = mid;
    }
    if(q[r] != t)
    {
      cout << -1 << " " << "-1" << endl;
      continue;
    }
    cout << r << ' ';
    l = -1, r = n, t += 1;//求最后一个位置即可以求>= x + 1的位置再减1
    while(l + 1 < r)
    {
      int mid = r + (l - r) / 2;
      if(q[mid] < t)l = mid;
      else r = mid;
    }
    cout << r - 1 << endl;
  }
}
