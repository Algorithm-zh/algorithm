#include <iostream>
using namespace std;
const int N = 1e5 + 10;
/*
 * 红蓝染色法(开区间分析法)
*  示例数组nums[]：5 7 7 8 8 10
  目标：查找 ≥8 的第一个元素的下标
  
  定义：红色区域为false, 即<target，蓝色区域为true，即>=target
  L包适L左侧是红色区域，R包括R右侧是蓝色区域
  初始时，红色和蓝色区域未扩展，分别在两侧  
  所以L = -1, R = 6
  假设nums[-1] = -♾️，nums[6] = ♾️,满足红蓝染色条件
  (啥时候结束？l + 1 = r 时不包括任何整数，退出)

  红色区域：[]
  蓝色区域：[]
  第一次: M = (L + R) / 2 = 2 (下取整)
      红|            | 蓝
          5 7 7 8 8 10
         ↑    ↑       ↑
         L    M       R
  由于nums[M]<8, L = M
-----------------------------------------
  红色区域：[5 7 7]
  蓝色区域：[8 8 10]
  第二次: M = (L + R) / 2 = 4 (下取整)
           红 |      | 蓝
         5 7 7 8 8 10
             ↑ ↑   ↑
             L M   R
  由于nums[M]≥8, R = M
-----------------------------------------
  红色区域：[5，7，7]
  蓝色区域：[8 8 10]
  第三次: M = (L + R) / 2 = 3 (下取整)
            红 |  | 蓝
          5 7  7  8 8 10
              ↑↑  ↑
              LM  R
  l + 1 = r,区间已经不包含任何整数（开区间）此时R的位置就是最终结果
*/
int main()
{
  int n, k, q[N];
  cin >> n >> k;
  for(int i = 0; i < n; i ++)cin >> q[i];
  while(k --)
  {
    int t;
    cin >> t;
    int l = -1, r = n;
    while(l + 1 < r)
    {
      int mid = r + (l - r) / 2;
      if(q[mid] < t)l = mid;
      else r = mid;
    }
    if(q[r] != t)
    {
      cout << -1 << " " << "-1" << endl;
      continue;
    }
    cout << r << ' ';
    l = -1, r = n, t += 1;//求最后一个位置即可以求>= x + 1的位置再减1
    while(l + 1 < r)
    {
      int mid = r + (l - r) / 2;
      if(q[mid] < t)l = mid;
      else r = mid;
    }
    cout << r - 1 << endl;
  }
}
