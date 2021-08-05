/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-08-04
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: HDU
 *  Algorithm: STL deque / list
 ********************************************************************************
 *  Algo-Description:
 ********************************************************************************
 */

#include <bits/stdc++.h>
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

const int MAXN = 150005;


/* STL deque */

map<int, deque<int> > dq;

void read(int &x)
{
    char ch = getchar();
    x = 0;
    for(; ch < '0' || ch > '9'; ch = getchar());
    for(; ch >= '0' && ch <= '9'; ch = getchar())
        x = x * 10 + ch - '0';
}

int main()
{
    int n, m;
    while(~scanf("%d%d", &n, &m))
    {
        for(int i = 1; i <= n; i++)
            dq[i].clear();
        int op;
        while(m--)
        {
            read(op);
            if(op == 1)
            {
                int u, w, val;
                read(u), read(w), read(val);
                if(!w)
                    dq[u].push_front(val);
                else
                    dq[u].push_back(val);
            }
            else if(op == 2)
            {
                int u, w;
                read(u), read(w);
                if(dq[u].empty())
                    puts("-1");
                else
                {
                    if(!w)
                    {
                        printf("%d\n", dq[u].front());
                        dq[u].pop_front();
                    }
                    else
                    {
                        printf("%d\n", dq[u].back());
                        dq[u].pop_back();
                    }
                }
            }
            else if(op == 3)
            {
                int u, v, w;
                read(u), read(v), read(w);
                if(!w)
                {
                    dq[u].insert(dq[u].end(), dq[v].begin(), dq[v].end());  //889ms
                    while(!dq[v].empty()) //1419ms
                    {
                        dq[u].push_back(dq[v].front());
                        dq[v].pop_front();
                    }
                }
                else
                {
                    dq[u].insert(dq[u].end(), dq[v].rbegin(), dq[v].rend());
                    while(!dq[v].empty())
                    {
                        dq[u].push_back(dq[v].back());
                        dq[v].pop_back();
                    }
                }
                dq[v].clear();
            }
        }
    }
    return 0;
}


/* STL list */

list<int> ls[MAXN];

void read(int &x)
{
    char ch = getchar();
    x = 0;
    for(; ch < '0' || ch > '9'; ch = getchar());
    for(; ch >= '0' && ch <= '9'; ch = getchar())
        x = x * 10 + ch - '0';
}

int main()
{
    int n, m;
    while(~scanf("%d%d", &n, &m))
    {
        for(int i = 1; i <= n; i++)
            ls[i].clear();
        int op;
        while(m--)
        {
            read(op);
            if(op == 1)
            {
                int u, w, val;
                read(u), read(w), read(val);
                if(!w)
                    ls[u].push_front(val);
                else
                    ls[u].push_back(val);
            }
            else if(op == 2)
            {
                int u, w;
                read(u), read(w);
                if(ls[u].empty())
                    puts("-1");
                else
                {
                    if(!w)
                    {
                        printf("%d\n", ls[u].front());
                        ls[u].pop_front();
                    }
                    else
                    {
                        printf("%d\n", ls[u].back());
                        ls[u].pop_back();
                    }
                }
            }
            else if(op == 3)
            {
                int u, v, w;
                read(u), read(v), read(w);
                /*if(!w)
                {
                    //ls[u].insert(ls[u].end(), ls[v].begin(), ls[v].end());  //655ms, 9940kB
                    while(!ls[v].empty()) //639ms, 7828kB
                    {
                        ls[u].push_back(ls[v].front());
                        ls[v].pop_front();
                    }
                }
                else
                {
                    //ls[u].insert(ls[u].end(), ls[v].rbegin(), ls[v].rend());

                    while(!ls[v].empty())
                    {
                        ls[u].push_back(ls[v].back());
                        ls[v].pop_back();
                    }
                }
                ls[v].clear();
                */
                if(w)   //468ms, 7828kB
                    ls[v].reverse();
                ls[u].splice(ls[u].end(), ls[v]);    //splice函数会自动清空ls[v]，常数时间复杂度
            }
        }
    }
    return 0;
}
