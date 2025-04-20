#include <iostream>
#include <iterator>
#include <queue>
#include <string>
#include <unordered_map>
#include <utility>
using namespace std;
/*
* 此题可以换一个思路，将排列阵型转换为一个字符串，那么不同的字符串就相当于做了不同的排列
* 一个map记录字符串有没有出现过，也就是有没有走到过这一步
*/
//st记录当前字符串和初始字符串走过几步
unordered_map<std::string, int> d;
queue<std::string> q;
std::string start;
int bfs()
{
  std::string end = "12345678x";
  q.push(start);
  d[start] = 0;
  int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, 1, -1};
  while(!q.empty())
  {
    std::string tmp = q.front();q.pop();
    int distance = d[tmp];
    if(tmp == end)return distance;

    int index = tmp.find('x');
    int x = index / 3, y = index % 3;//转换为坐标
    //到达最终位置
    for(int i = 0; i < 4; i ++)
    {
      int x1 = x + dx[i], y1 = y + dy[i]; 
      if(x1 >= 0 && x1 < 3 && y1 >= 0 && y1 < 3)
      {
        swap(tmp[index], tmp[x1 * 3 + y1]);
        //没有出现过
        if(!d.count(tmp))
        {
          q.push(tmp);
          d[tmp] = distance + 1;
        }
        //重点：恢复状态，因为初始态已经被改了
        swap(tmp[index], tmp[x1 * 3 + y1]);
      }
    }

  }
  return -1;
}
int main (int argc, char *argv[]) {
  char ch;
  int n = 9;
  while(n --)
  {
    cin >> ch;
    start += ch;
  }
  cout << bfs();
  return 0;
}
