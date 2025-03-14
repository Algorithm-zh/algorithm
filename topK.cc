#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5 + 10;
int QuikSort(int q[], int l, int r, int k)
{
  if(l == r)return q[l];
  int rnd_idx = rand() % (r - l + 1) + l;
  swap(q[l], q[rnd_idx]);
  int x = q[l], i = l - 1, j = r + 1;
  while(i < j)
  {
    do i ++; while(q[i] < x);
    do j --; while(q[j] > x);
    if(i < j)swap(q[i], q[j]);
  }
  //这里是左边界的大小，不能写成i - l + 1,这也就决定了下面必须要写成s1 < k,如果写成s1 <= k
  //那么下面就得写成 j , r，这样又错了，因为j属于左边界，不能这样写
  int sl = j - l + 1;
  if(sl < k)return QuikSort(q, j + 1, r, k - i + 1);
  else return QuikSort(q, l, j, k);//这里还得保持快排防止死循环的思想,而且不能破坏分区的性质，j属于左部分，i属于右部分，分区时不能错误划分
}
int main()
{
  int q[N], n, k;
  cin >> n >> k;
  for(int i = 0; i < n; i ++) cin >> q[i];
  cout << QuikSort(q, 0, n - 1, k);
}
