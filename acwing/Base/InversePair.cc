#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int tmp[N];
long long merge_sort(int q[], int l, int r)
{
  if(l >= r)return 0;
  long long sum = 0;
  int mid = (l + r) >> 1;
  sum = merge_sort(q, l, mid) + merge_sort(q, mid + 1, r);
  int k = 0, i = l, j = mid + 1;
  while(i <= mid && j <= r)
  {
    if(q[i] <= q[j])tmp[k ++] = q[i ++];
    else{
      sum += mid - i + 1;
      tmp[k ++] = q[j ++];
    } 
  }
  while(i <= mid)tmp[k ++] = q[i ++];
  while(j <= r)tmp[k ++] = q[j ++];
  for(int i = l, j = 0; i <= r; i ++, j ++)q[i] = tmp[j];
  return sum;
}
int main()
{
  int n, q[N];
  cin >> n;
  for(int i = 0; i < n; i ++) cin >> q[i];
  cout << merge_sort(q, 0, n - 1);
}

