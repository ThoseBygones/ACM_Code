/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-03-27
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: CodeForces
 *  Algorithm:
 ********************************************************************************
 *  Algo-Description:
 ********************************************************************************
 */

#include <bits/stdc++.h>  //For CodeForces only
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
#define clr(ar,val) memset(ar, val, sizeof(ar))
#define istr stringstream
#define FOR(i,n) for(int i=0;i<(n);++i)
#define forIt(mp,it) for(__typeof(mp.begin()) it = mp.begin();it!=mp.end();it++)
const double EPS = 1e-6;
const int INF = 0x3fffffff;
const LL LINF = INF * 1ll * INF;
const double PI = acos(-1.0);

#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define lowbit(u) (u&(-u))
#define MAXN 100005

struct Passenger
{
    int pos, t;
    Passenger() {}
    Passenger(int pos, int t) : pos(pos), t(t) {}
    bool operator <(const Passenger &p) const
    {
        if(t == p.t)
            return pos > p.pos;
        return t > p.t;
    }
};

queue<int> q;   //水箱前等待打水的队列
priority_queue<int, vector<int>, greater<int> > w;  //等待去水箱前排队打水的队列
priority_queue<Passenger> h;    //饥饿队列，起身想去打水的队列
set<int> s; //用于记录不在座位上的乘客座位号的集合
LL ans[MAXN];

int main()
{
    int n, p;
    scanf("%d%d", &n, &p);
    for(int i = 1; i <= n; i++)
    {
        int x;
        scanf("%d", &x);
        h.push(Passenger(i, x));
    }
    LL curtime = 0;    //当前时间
    while(!h.empty())   //饥饿队列里还有人
    {
        Passenger pa = h.top();
        h.pop();
        q.push(pa.pos);  //先将想起身的人加入等待去水箱前排队打水的队列
        s.insert(pa.pos);   //记录该乘客离开座位
        curtime = pa.t;
        //printf("time: %d\n", curtime);
        while(!q.empty())   //水箱前还有人排队打水
        {
            int id = q.front();
            q.pop();
            curtime += p;
            ans[id] = curtime;
            //printf("curtime: %lld, id: %d\n", curtime, id);
            while(!h.empty() && h.top().t <= curtime)    //当前有人到了起身打水的时间
            {
                pa = h.top();
                h.pop();
                if(*s.begin() > pa.pos) //该乘客前面没有空着的座位，则直接到水箱前排队打水
                {
                    q.push(pa.pos);
                    s.insert(pa.pos);
                }
                else    //否则加入等待去水箱前排队打水的队列
                    w.push(pa.pos);
            }
            s.erase(id);   //该乘客打完水回到座位上
            if(!w.empty())   //等待去水箱前排队打水的队列非空
            {
                id = w.top();
                //printf("W top id: %d\n", id);
                if(s.empty() || *s.begin() > id)  //当前乘客都在座位上或者空着的座位的座位号在该乘客之后
                {
                    w.pop();    //该乘客离开等待去水箱前排队打水的队列
                    s.insert(id);
                    q.push(id);  //该乘客到水箱前排队打水
                }
            }
        }
    }
    for(int i = 1; i <= n; i++)
        printf("%lld%c", ans[i], (i == n ? '\n' : ' '));
    return 0;
}
