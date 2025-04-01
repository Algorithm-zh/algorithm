#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;
const int N = 3e5 + 10;
typedef pair<int, int> pii;
int a[N], s[N];
vector<int> alls;
vector<pii> add, querys;
int find(int x)
{
  int l = 0, r = alls.size();
  while(l + 1 < r)
  {
    int mid = r + (l - r) / 2;
    if(alls[mid] <= x)l = mid;
    else r = mid;
  }
  return r;
}
int main (int argc, char *argv[]) {

  int n, m;
  cin >> n >> m;
  for(int i = 0; i < n; i ++)
  {
    int x, c;
    cin >> x >> c;
    add.push_back({x, c});
    alls.push_back(x);
  }
  for(int i = 0; i < m; i ++)
  {
    int l, r;
    cin >> l >> r;
    alls.push_back(l);
    alls.push_back(r);
    querys.push_back({l, r});
  }
  sort(alls.begin(), alls.end());
  alls.erase(unique(alls.begin(), alls.end()), alls.end());

  for(auto item : add)
  {
    int x = find(item.first);
    a[x] += item.second;
  }
  for(int i = 1; i <= alls.size(); i ++)
  {
    s[i] += s[i - 1] + a[i];
  }

  for (auto item : querys) {
    int l = find(item.first);       
    int r = find(item.second);
    cout << s[r] - s[l - 1] << endl;
  }

  return 0;
}
