#include <iostream>
using namespace std;
const int N = 100006;

int m;
int e[N], l[N], r[N], idx;//0表示左指针，1表示右指针

void init()
{
    //0表示左端点，1表示右端点
    r[0] = 1, l[1] = 0;//互指
    idx = 2;
}
//在下标为k的右边插入
void add(int x,int k)
{
    e[idx] = x;
    r[idx] = r[k];
    r[k] = idx;
    l[idx] = k;
    l[r[idx]] = idx;
    idx++;
}
//删除下标为k的点
void remove(int k)
{
    r[l[k]] = r[k];
    l[r[k]] = l[k];
}
int main()
{
    init();
    cin >> m;
    while (m -- )
    {
        char ch;
        int k, x;
        cin >> ch;
        if(ch == 'L')
        {
            cin >> x;
            add(x,0);
        }else if(ch == 'R')
        {
            cin >> x;
            add(x,l[1]);
        }else if(ch == 'D')
        {
            cin >> k;
            remove(k+1);
        }else if(ch == 'I')
        {
            cin >> ch;
            if(ch == 'L')
            {
                cin >> k >> x;
                add(x,l[k+1]);
            }else if(ch == 'R')
            {
                cin >> k >> x;
                add(x,k+1);
            }
        }
    }
    for(int i = 0;i != 1;i = r[i])
    {
        if(i)cout << e[i] << ' ';
    }
    cout << endl;
}
