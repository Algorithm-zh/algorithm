#include <iostream>
using namespace std;
const int N = 1e3 + 10;
int main() 
{
  int n, m, q, a[N][N], b[N][N];
  cin >> n >> m >> q;
  for (int i = 1; i <= n; i++)
    for(int j = 1; j <= m; j ++)
      cin >> a[i][j];

  for (int i = 1; i <= n; i++)
    for(int j = 1; j <= m; j ++)
      b[i][j] = b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1] + a[i][j];

  for(int i = 0; i < m; i ++)
  {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    cout << b[x2][y2] + b[x1 - 1][y1 - 1] - b[x2][y1 - 1] - b[x1 - 1][y2] << endl;
  }

  return 0;
}
