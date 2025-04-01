#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int main() 
{
  int n, m, a[N], b[N];
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
  {
    cin >> a[i];
    b[i] = b[i - 1] + a[i];
  }

  for(int i = 0; i < m; i ++)
  {
    int l, r;
    cin >> l >> r;
    cout << b[r] - b[l - 1] << endl;
  }

  return 0;
}
