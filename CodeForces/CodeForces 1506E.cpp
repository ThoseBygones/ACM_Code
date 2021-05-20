/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-05-20
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm:
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

int a[MAXN];
vector<int> ans1, ans2;
bool vis[MAXN];

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        ans1.clear(), ans2.clear();
        memset(vis, false, sizeof(vis));
        for(int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        int pos = 1;    //字典序最小开始
        //字典序最小
        for(int i = 1; i <= n; i++)
        {
            if(a[i] != a[i - 1])
            {
                ans1.PB(a[i]);
                vis[a[i]] = true;
            }
            else
            {
                while(vis[pos])
                    pos++;
                ans1.PB(pos);
                vis[pos++] = true;
            }
        }
        stack<int> st;
        //字典序最大
        for(int i = 1; i <= n; i++)
        {
            if(a[i] != a[i - 1])
            {
                ans2.PB(a[i]);
            for(int j = a[i - 1] + 1; j < a[i]; j++)
                st.push(j);
            }
            else
            {
                ans2.PB(st.top());
                st.pop();
            }
        }
        for(int i = 0; i < ans1.size(); i++)
            printf("%d%c", ans1[i], (i == ans1.size() - 1 ? '\n' : ' '));
        for(int i = 0; i < ans2.size(); i++)
            printf("%d%c", ans2[i], (i == ans2.size() - 1 ? '\n' : ' '));
    }
    return 0;
}
