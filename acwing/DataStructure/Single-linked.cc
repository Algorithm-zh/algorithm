#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5 + 10;
int e[N], ne[N], head = -1, idx = 0;
void add_head(int x)
{
  e[idx] = x;
  ne[idx] = head;
  head = idx ++;
}
void add(int x, int k)
{
  e[idx] = x;
  ne[idx] = ne[k - 1];
  ne[k - 1] = idx ++; 
}
void remove(int k)
{
  ne[k - 1] = ne[ne[k - 1]];
}
int main (int argc, char *argv[]) {
  int m;
  cin >> m;
  while(m --)
  {
    char ch;
    int k, x;
    cin >> ch;
    switch (ch) {
      case 'I': 
        cin >> k >> x;
        add(x, k);
        break;
      case 'D':
        cin >> k;
        //要考虑到k = 0的情况，不然数组就越界了
        if(!k)head = ne[head];
        remove(k);
        break;
      case 'H':
        cin >> x;
        add_head(x);
        break;
      default:
        break;
    }
  }
  for(int i = head; i != -1; i = ne[i])
  {
    cout << e[i] << ' ';
  }

  return 0;
}
