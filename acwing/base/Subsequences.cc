#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5 + 10;
int main()
{
  int a[N], b[N];
  int n, m;
  cin >> n >> m;
  for(int i = 0; i < n; i ++)cin >> a[i];
  for(int i = 0; i < m; i ++)cin >> b[i];

  int i, j;
  for(i = 0, j = 0; i < n && j < m;)
  {
    if(a[i] == b[j]) i ++;
    j ++;
  }
  if(i == n)cout << "Yes";
  else cout << "No";

  return 0;
}
