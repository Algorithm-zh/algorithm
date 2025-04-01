#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int tmp[N];
void mergeSort(int q[], int l, int r)
{
  if(l == r)return;
  int mid = l + (r - l) / 2;
  mergeSort(q, l, mid); mergeSort(q, mid + 1, r);
  int i = l, j = mid + 1, k = 0;
  while(i <= mid && j <= r)
  {
    if(q[i] <= q[j])tmp[k ++] = q[i ++];
    else tmp[k ++] = q[j ++];
  }
  while(i <= mid)tmp[k ++] = q[i ++];
  while(j <= r)tmp[k ++] = q[j ++];

  for(int i = l, j = 0; i <= r; i ++, j ++)q[i] = tmp[j];
}
int main()
{
  int n, q[N];
  cin >> n;
  for(int i = 0; i < n; i ++)cin >> q[i];
  mergeSort(q, 0, n - 1);
  for(int i = 0; i < n; i ++)cout << q[i] << ' ';

  return 0;
}
