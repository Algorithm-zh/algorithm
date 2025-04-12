#include <bits/stdc++.h>
#include <utility>
using namespace std;
const int N = 1e5 + 10;
//ph[i] = j表示第i个插入的下标为j
//hp[i] = j表示下标为i的是第j个插入的
int h[N], hp[N], ph[N];
int n, m, siz;//n记录插入到了第几个,siz记录总数量
//x和y为下标
void swapHeap(int x, int y)
{
  swap(ph[hp[x]], ph[hp[y]]);
  swap(hp[x], hp[y]);
  swap(h[x], h[y]);
}
void down(int u)
{
  int t = u;
  if(2 * u <= siz && h[2 * u] < h[t])t = 2 * u;
  if(2 * u + 1 <= siz && h[2 * u + 1] < h[t])t = 2 * u + 1;
  if(t != u)
  {
    swapHeap(t, u);
    down(t);
  }
}
void up(int u)
{
  while(u / 2 && h[u / 2] > h[u])
  {
    swapHeap(u, u / 2);
    u /= 2;
  }
}

int main (int argc, char *argv[]) {
  cin >> m;
  while(m --)
  {
    char ch[2];
    int k, x;
    cin >> ch;
    switch (ch[0]) {
      case 'I': 
        cin >> x;
        siz ++; n ++;
        hp[siz] = n; ph[n] = siz;
        h[siz] = x;
        up(siz);
      break;
      case 'P':
        cout << h[1] << endl;
      break;
      case 'D':
        if(ch[1] == 'M')
        {
          swapHeap(1, siz --);
          down(1);
        }
        else
        {
          cin >> k;
          k = ph[k];
          swapHeap(k, siz --);
          down(k);up(k);
        }
      break;
      case 'C':
        cin >> k >> x;
        k = ph[k];
        h[k] = x;
        down(k);up(k);
      break;
      default:
        cout << "not support" << endl;
      break;
    }
  }
  return 0;
}
