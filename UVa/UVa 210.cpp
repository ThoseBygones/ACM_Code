/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-08-10
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: UVa
 *  Algorithm: 模拟 + STL deque
 ********************************************************************************
 *  Algo-Description:
 ********************************************************************************
 */

//#pragma comment(linker,"/STACK:102400000,102400000")
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <climits>
#include <ctime>
#include <numeric>
#include <vector>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <complex>
#include <deque>
#include <functional>
#include <list>
#include <map>
#include <string>
#include <sstream>
#include <set>
#include <stack>
#include <queue>
//#include <bits/stdc++.h>
using namespace std;

template<class T> inline T sqr(T x)
{
    return x * x;
}
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int, int> PII;
typedef pair<PII, int> PIII;
typedef pair<LL, LL> PLL;
typedef pair<LL, int> PLI;
typedef pair<LD, LD> PDD;
#define MP make_pair
#define PB push_back
#define sz(x) ((int)(x).size())
const double EPS = 1e-6;
const int INF = 0x3fffffff;
const LL LINF = INF * 1ll * INF;
const double PI = acos(-1.0);

#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define lowbit(u) (u&(-u))

const int MAXN = 105;
vector<string> prog[MAXN];   //指令
deque<int> ready;   //就绪队列
queue<int> block;   //阻塞队列
int pos[MAXN];  //每个程序执行到哪个命令了
int val[30];    //变量的值

void init()
{
    ready.clear();
    while(!block.empty())
        block.pop();
    memset(val, 0, sizeof(val));
    memset(pos, 0, sizeof(pos));
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--)
    {
        int n, t1, t2, t3, t4, t5, q;
        cin >> n >> t1 >> t2 >> t3 >> t4 >> t5 >> q;
        init();
        string com;
        for(int i = 1; i <= n; i++)
        {
            prog[i].clear();
            while(getline(cin, com))
            {
                prog[i].PB(com);
                if(com == "end")
                    break;
            }
            ready.PB(i);
        }
        bool locked = false;
        while(!ready.empty())
        {
            int pid = ready.front();
            ready.pop_front();
            int t = q;  //时间片大小
            bool flag = false;  //该程序是否被阻塞/结束
            while(t > 0)
            {
                string curcom = prog[pid][pos[pid]];    //获取当前要执行的指令
                //cout << "=== now: " << pid << " command: " << curcom << endl;
                if(curcom[2] == '=')    //赋值命令
                {
                    t -= t1;
                    string num = curcom.substr(4);
                    //cout << "num: " << num << endl;
                    int sum = 0;
                    for(int i = 0; i < num.length(); i++)
                        sum = sum * 10 + (num[i] - '0');
                    val[curcom[0] - 'a'] = sum;
                    //cout << "var: " << val[curcom[0] - 'a'] << endl;
                }
                else if(curcom[0] == 'p')   //打印命令
                {
                    t -= t2;
                    cout << pid << ": " << val[curcom[6] - 'a'] << endl;
                }
                else if(curcom[0] == 'l')   //锁定命令
                {
                    if(locked)  //已经被锁定
                    {
                        block.push(pid);    //加入阻塞队列队尾
                        flag = true;
                        break;  //不再执行该程序
                    }
                    else    //未被锁定
                    {
                        t -= t3;
                        locked = true;
                    }
                }
                else if(curcom[0] == 'u')   //解锁命令
                {
                    t -= t4;
                    locked = false;
                    if(!block.empty())  //阻塞队列非空
                    {
                        ready.push_front(block.front());    //加入就绪队列队头
                        block.pop();
                    }
                }
                else if(curcom[0] == 'e')
                {
                    flag = true;
                    break;
                }
                pos[pid]++;  //时间片还未用完，则继续执行下一条指令
            }
            if(!flag)
                ready.push_back(pid);   //当前时间片已经用完，该程序加入就绪队列队尾
        }
        if(T)
            cout << endl;
    }
    return 0;
}

/*
1
3 1 1 1 1 1 1
a = 4
print a
lock
b = 9
print b
unlock
print b
end
a = 3
print a
lock
b = 8
print b
unlock
print b
end
b = 5
a = 17
print a
print b
lock
b = 21
print b
unlock
print b
end
*/
