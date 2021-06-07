/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-06-07
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm: 链表模拟
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

const int MAXN = 200005;
const int MOD = 998244353;

int a[MAXN], b[MAXN];
int pre[MAXN], nxt[MAXN];   //链表的前后结点
bool vis[MAXN]; //该数字是否可以删除

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n, k;
        scanf("%d%d", &n, &k);
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
            vis[i] = false; //数组a是一个排列
        }
        for(int i = 1; i <= k; i++)
        {
            scanf("%d", &b[i]);
            vis[b[i]] = true;
        }
        a[0] = a[n + 1] = 0;
        for(int i = 1; i <= n; i++)
        {
            pre[a[i]] = a[i - 1];
            nxt[a[i]] = a[i + 1];
        }
        LL ans = 1;
        vis[0] = true;  //链表的边界
        for(int i = 1; i <= k; i++)
        {
            int cnt = 0, flag = 0;
            if(!vis[pre[b[i]]]) //该数字的前一个数字可以被删除
            {
                cnt++;
                flag = -1;
            }
            if(!vis[nxt[b[i]]]) //该数字的后一个数字可以被删除
            {
                cnt++;
                flag = 1;
            }
            if(!flag)    //不存在可行的删除方案，前功尽弃
            {
                ans = 0;
                break;
            }
            else if(flag == -1) //删除前一个数
            {
                nxt[pre[pre[b[i]]]] = b[i];
                pre[b[i]] = pre[pre[b[i]]];
            }
            else if(flag == 1)  //删除后一个数
            {
                pre[nxt[nxt[b[i]]]] = b[i];
                nxt[b[i]] = nxt[nxt[b[i]]];
            }
            vis[b[i]] = false;  //b[i]用过了，从今以后可以被删了
            //printf("%d: %d\n", i, cnt);
            ans = ans * cnt % MOD;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
