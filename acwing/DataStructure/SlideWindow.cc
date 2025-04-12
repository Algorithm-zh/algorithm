#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e6 + 10;
int a[N], q[N];
//维护一个队列,如果求最小值,那么遍历到某值时,如果队尾大于等于该值,出队,直到队尾小于该值或队空,将该值加入到窗口末尾
//每向前遍历,队头出队输出,队头一直是每个区间的最小值
//注意队列维护的是下标,不是值
int main (int argc, char *argv[]) {
  int n, k;
  cin >> n >> k;
  for(int i = 0; i < n; i ++)cin >> a[i];
  
  int hh = 0, tt = -1;
  for(int i = 0; i < n; i ++)
  {
    //判断窗口里是否有元素,队头元素是不是在窗口内,不是将往前移动
    if(hh <= tt && i - k + 1 > q[hh])hh ++; 
    //看队尾是不是小于当前值,不是将队尾出队,因为有比他们更小的值, 这些元素全部都没用了
    while(hh <= tt && a[q[tt]] >= a[i])tt --;

    q[++ tt] = i;
    if(i >= k - 1)
      cout << a[q[hh]] << ' ';
  }
  cout << endl;
  hh = 0, tt = -1;
  for(int i = 0; i < n; i ++)
  {
    if(hh <= tt && i - k + 1 > q[hh])hh ++; 
    while(hh <= tt && a[q[tt]] <= a[i])tt --;

    q[++ tt] = i;
    if(i >= k - 1)
      cout << a[q[hh]] << ' ';
  }
  return 0;
}
