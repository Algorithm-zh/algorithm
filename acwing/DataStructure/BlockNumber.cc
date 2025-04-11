#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int p[N], cnt[N];
int find(int x)
{
  if(x != p[x])p[x] = find(p[x]);
  return p[x];
}
void merge(int x, int y)
{
  int a = find(x), b = find(y);
  if(a != b)
  {
    p[a] = b;
    cnt[b] += cnt[a];//细节点1：要加祖宗的，并且是把a的加到b上
  }
}
int main()
{
  int n, m;
  cin >> n >> m;
  for(int i = 1; i <= n; i ++)p[i] = i, cnt[i] = 1;
  while(m --)
  {
    char ch, c;
    int a, b;
    cin >> ch;
    switch (ch) {
      case 'C':
        cin >> a >> b;
        merge(a, b); 
      break;
      case 'Q':
        cin >> c;
        switch (c) {
          case '1': 
            cin >> a >> b;
            if(find(a) == find(b)) cout << "Yes" << endl;    
            else cout << "No" << endl;
          break;
          case '2':
            cin >> a;
            cout << cnt[find(a)] << endl;//细节点2：问祖宗的
          break;
        }
        break;
    }
  }

  return 0;
}

