#include <bits/stdc++.h>
#include <cmath>
using namespace std;
int n;
/*
* 何为质数,除了1和它本身外没有任何的因数的数就是质数
* 优化:
*   一个数x能被分解为两个数的乘积,那么其中一个肯定大于等于根号x,另一个小于等于根号x
*   所以可以用这个x除以2~根号x,如果出现了余数为0的数,那就不是质数,否则该数就是质数
*   (1要单独判断)
*/
bool Prime(int x)
{
  for(int i = 2; i <= sqrt(x); i ++)
  {
    if(x % i == 0)return false;
  }
  return true;
}
int main (int argc, char *argv[]) {
  cin >> n;
  while(n --)
  {
    int x;
    cin >> x;
    //注意1不为质数
    if(Prime(x) && x != 1)cout << "Yes" << endl;
    else cout << "No" << endl;
  }
  return 0;
}
