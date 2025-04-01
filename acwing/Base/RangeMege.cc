#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;
const int N = 1e5 + 10;
using pii = pair<int, int>;
vector<pii> segs;
void merge()
{
  sort(segs.begin(), segs.end());
  int st = -2e9, ed = -2e9;
  vector<pii> ans;
  for(auto seg : segs)
  {
    if(ed < seg.first)
    {
      //上一个的末尾小于当前的开始说明区间不重合
      if(st != -2e9)ans.push_back({st, ed});
      st = seg.first;
      ed = seg.second;
    }else
    {
      ed = max(ed, seg.second); 
    }
  }
  //将最后一个区间加入
  if(st != -2e9)ans.push_back({st, ed});
  segs = ans;
}
int main (int argc, char *argv[]) {
  int n;
  cin >> n;
  for(int i = 0; i < n; i ++)
  {
    int l, r;
    cin >> l >> r;
    segs.push_back({l, r});
  }
  merge();
  cout << segs.size();

  return 0;
}
