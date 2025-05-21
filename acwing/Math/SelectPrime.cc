#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
/*
* 朴素筛选法,将每个数的所有倍数全部删掉,时间复杂度为o(nlogn)
*  核心思想:如果一个数n没有被2~n-1这里面的数的删掉,说明就不存在它的因数,说明这个数就是质数
* 但是该方法有个弊端就是会重复筛,比如6就会被2,3都筛一下,浪费时间
* 优化方法1(埃式筛法):在筛选的适合可以只将质数的倍数删掉,为什么?因为合数等于质因子的乘积,
*         所以你这个合数肯定能在前面找到一个质数来删掉自己,就是把for循环放到if里
*         时间复杂度为o(nloglogn)
* 优化方法2(线性筛选法):核心思想为每个合数只会被它的最小质因子筛掉
*         1. i % prime[j] == 0
*             pj一定是i的最小质因子,pj一定是pj * i的最小质因子
*         2. i % prime[j] != 0
*             pj一定小于i的所有质因子, 那么pj也一定是 pj * i的最小质因子
*         所以这两种情况就可以合并为一种
*         因为每个数都只会被最小质因子筛掉,每个数只有一个最小质因子,所以每个数只会被筛一次
*         时间复杂度在10^7情况下比优化1快2倍
*/
int n;
bool st[N];//是否为质数,否的话就是质数
int prime[N], cnt;
void Prime_1(int x)
{
  for(int i = 2; i <= n; i ++)
  {
    if(!st[i])
    {
      //是质数加加进去
      prime[cnt ++] = i;
    }
    for(int j = i + i; j <= n; j += i)st[j] = true;
  }

}
void Prime_2(int x)
{
  for(int i = 2; i <= n; i ++)
  {
    if(!st[i])
    {
      //是质数加加进去
      prime[cnt ++] = i;
      for(int j = i + i; j <= n; j += i)st[j] = true;
    }
  }
}
void Prime_3(int x)
{
  for(int i = 2; i <= n; i ++)
  {
    if(!st[i]) prime[cnt ++] = i;
    //从小到大遍历质数,用最小的质数去筛每个合数
    for(int j = 0; prime[j] <= n / i; j ++)//prime[j] * i <= n
    {
      st[prime[j] * i] = true;
      if(i % prime[j] == 0)break;//prime[j]一定是i的最小质因子
    }
  }
}
int main (int argc, char *argv[]) {
  
  cin >> n;
//  Prime_1(n);
//  Prime_2(n);
  Prime_3(n);
  cout << cnt;
  return 0;
}
