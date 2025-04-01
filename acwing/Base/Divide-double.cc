#include <cstdio>
#include <iostream>
using namespace std;
const int N = 1e4;
int main()
{
  double n;
  cin >> n;
  double l = -N, r = N;
  while(r - l > 1e-8)
  {
    double mid = (r + l) / 2;
    if(mid * mid * mid >= n)r = mid;
    else l = mid;
  }
  printf("%.6f", r);
  return 0;
}
