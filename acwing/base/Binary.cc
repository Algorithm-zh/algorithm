#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int main (int argc, char *argv[]) {
  int n;
  cin >> n;
  for(int i = 0; i < n; i ++)
  {
    int t, sum = 0;
    cin >> t;
    while(t)
    {
      sum += t & 1; 
      t = t >> 1;
    }
    cout << sum << ' ';
  }
  
  return 0;
}
