/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2023-10-11
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm: 环/连通分量
 ********************************************************************************
 *  Algo-Description:
 ********************************************************************************
 */

#include <bits/stdc++.h>
using namespace std;

template<class T> inline T sqr(T x) {return x * x;}
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

const int MAXN = 200005;

int e[MAXN];    //边
int belong[MAXN];   //属于哪个连通分量

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
        {
            int x;
            scanf("%d", &x);
            e[i] = x;
            belong[i] = 0;
        }
        int cnt = 0;    //环的数量
        for(int u = 1; u <= n; u++)
        {
            if(!belong[u])
            {
                cnt++;
                for(int v = u; !belong[v]; v = e[v])
                    belong[v] = cnt;
            }
        }
        int ans = 0;
        for(int i = 1; i < n; i++)  //检查每个结点归属的连通分量情况
        {
            if(belong[i] == belong[i + 1])  //存在相邻的元素组成逆序对
            {
                ans = -1;
                break;
            }
            else    //不存在相邻元素组成的逆序对，必须先完全恢复顺序排列再多一步操作构造出一个逆序对
                ans = 1;
        }
        printf("%d\n", n - cnt + ans);
    }
    return 0;
}
