#include <bits/stdc++.h>
#include <utility>
using namespace std;
const int N = 1e5 + 10;
int n, m, siz;
int a[N];
//堆排序,如果升序,建立大顶堆,因为每次都要把堆顶和堆底互换,这样最大元素就到最后了,
//然后除了最后一个元素的剩下的元素再重新成堆
//最关键的就是down函数(以大顶堆为例)
//它要做的就是比较当前元素和它的孩子节点的值的大小,找出最大的一个,作为当前节点,若互换了,那就继续递归down那个互换的节点
//排序思路:
//1.首先成堆,成堆就是从最后一个非叶结点开始往前down
//2.堆首与堆尾互换,堆顶down, 直到没有元素
//本题要求的是输出前几小的数,不是全排,可以使用小顶堆,每次输出堆顶后再进行互换
void down(int u)
{
  int t = u;//t记录最小节点
  //比较左右孩子和当前节点的大小
  if(2 * u <= siz && a[2 * u] < a[u])t = 2 * u;
  if(2 * u + 1 <= siz && a[2 * u + 1] < a[t])t = 2 * u + 1;
  //让最小的到当前节点处
  swap(a[u], a[t]);
  //如果互换了就需要递归处理子节点了
  if(t != u)down(t);
}
int main (int argc, char *argv[]) {
  cin >> n >> m;
  siz = n - 1;
  for(int i = 0; i < n; i ++)cin >> a[i];
  for(int i = n / 2; i >= 0; i --)down(i);
  for(int i = 0; i < m; i ++)
  {
    cout << a[0] << ' ';
    swap(a[0], a[siz --]);
    down(0);
  }

  return 0;
}
