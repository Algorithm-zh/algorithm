#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e6 + 10;
void QuikSort(int q[], int l, int r)
{
  if(l >= r)return ;
  int rnd_idx = rand() % (r - l + 1) + l;
  swap(q[l], q[rnd_idx]);
  int x = q[r], i = l - 1, j = r + 1;
  while (i < j)
  {
    do i ++; while(q[i] < x);
    do j --; while(q[j] > x);
    if(i < j)swap(q[i], q[j]);
  }
  //要注意这里到底是写i - 1还是写成j,取决于上面x = q[r]还是x = q[l],因为有无限循环的问题
  //如果写成j,而q[r] > q[l....r - 1], 则经过一个while j还是为r, 那么就会死循环
  QuikSort(q, l, i - 1);
  QuikSort(q, i, r);//j + 1
}
#if 1
int main()
{
  int q[N], n;
  cin >> n;
  for(int i = 0; i < n; i ++)cin >> q[i];
  QuikSort(q, 0, n - 1);
  for(int i = 0; i < n; i ++)cout << q[i] << ' ';
  return 0;
}
#endif
