/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-07-10
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

const int MAXN = 55;

char s[MAXN];
int b[MAXN];
int cnt[30];
int vis[MAXN];
char ans[MAXN];

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%s", s);
        int m;
        scanf("%d", &m);
        for(int i = 1; i <= m; i++)
        {
            scanf("%d", &b[i]);
            vis[i] = 0;
        }
        for(int i = 0; i < 26; i++)
            cnt[i] = 0;
        int n = strlen(s);
        for(int i = 0; i < n; i++)
            cnt[s[i]-'a']++;
        int ok = 0;
        while(ok < m)
        {
            int zerocnt = 0;
            for(int i = 1; i <= m; i++)
            {
                if(!b[i] && !vis[i])   //记录当前值为0位置的数量
                    zerocnt++;
            }
            ok += zerocnt;
            int tmp = 25;
            for(int i = 25; i >= 0; i--)    //从大到小枚举字母
            {
                if(cnt[i] >= zerocnt)   //找到字母数量足够的字符
                {
                    tmp = i;
                    break;
                }
            }
            for(int i = tmp; i < 26; i++)   //已用过的字符及比它大的字符都不能再用了
                cnt[i] = 0;
            vector<int> bb;
            for(int i = 1; i <= m; i++) //记录该轮当前值为0的b[i]
            {
                if(!b[i] && !vis[i])
                {
                    ans[i] = tmp + 'a';
                    bb.PB(i);
                }
            }
            for(int i = 1; i <= m; i++) //更新b[]数组
            {
                if(b[i])
                {
                    for(int j = 0; j < bb.size(); j++)
                        b[i] -= abs(bb[j] - i);
                }
            }
            for(int i = 0; i < bb.size(); i++)
                vis[bb[i]] = 1;
        }
        for(int i = 1; i <= m; i++)
            printf("%c", ans[i]);
        puts("");
    }
    return 0;
}
