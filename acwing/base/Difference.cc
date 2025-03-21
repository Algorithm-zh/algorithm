#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int main()
{
  int n, m, q;
  int a[N], b[N];
  cin >> n >> m;
  //a[i] = a[i - 1] + b[i]
  //b[i] = a[i] - a[i - 1]
  for(int i = 1; i <= n; i ++)
    cin >> a[i], b[i] = a[i] - a[i - 1]; 

  while(m --)
  {
    int l, r, c;
    cin >> l >> r >> c;
    b[l] += c;
    b[r + 1] -= c;
  }

  for(int i = 1; i <= n; i ++)
    a[i] = a[i - 1] + b[i], cout << a[i] << ' ';

  return 0;
}
