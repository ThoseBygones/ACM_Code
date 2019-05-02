/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2019-05-01
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: POJ
 *  Algorithm: 并查集 + DP
 ********************************************************************************
 *  Algo-Description:
 ********************************************************************************
 */

//#include <bits/stdc++.h>  //For CodeForces only

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
#define MAXN 610

int fa[MAXN];
int rel[MAXN];  //表示关系，0表示与祖先属于同一个集合，1表示属于不同的集合
int dp[MAXN][MAXN>>1];  //dp[i][j]表示前i个集合中有j个人是好人的方案数
int pre[MAXN][MAXN>>1]; //记录路径
int cnt[MAXN][2];   //cnt[i][0/1]表示第i个集合中两类人的个数分别为多少
int belong[MAXN];   //belong[i]表示i号人属于哪个集合
vector<int> v[MAXN][2];    //v[i][0/1]表示集合i属于0号类的有那些，1号类的有哪些
int set_cnt;    //集合的数量

int findset(int x)
{
    if(x != fa[x])
    {
        int r = fa[x];
        fa[x] = findset(fa[x]);
        rel[x] ^= rel[r];   //更新与新祖先的相对关系
    }
    return fa[x];
}

void init(int n)
{
    set_cnt = 0;
    memset(cnt,0,sizeof(cnt));
    memset(belong,0,sizeof(belong));
    memset(dp,0,sizeof(dp));
    memset(pre,0,sizeof(pre));
    for(int i=1; i<=n; i++)
    {
        fa[i] = i;
        rel[i] = 0;
    }
    for(int i=0; i<MAXN; i++)
    {
        v[i][0].clear();
        v[i][1].clear();
    }
}

int main()
{
    int n,p1,p2;
    while(~scanf("%d%d%d",&n,&p1,&p2))
    {
        if(n == 0 && p1 == 0 && p2 == 0)
            break;
        init(p1+p2);
        while(n--)
        {
            int x,y;
            char word[5];
            scanf("%d%d%s",&x,&y,word);
            int xx = findset(x);
            int yy = findset(y);
            if(xx != yy)
            {
                fa[yy] = xx;
                rel[yy] = rel[x] ^ rel[y] ^ (word[0] == 'n');
            }
        }
        for(int i=1; i<=p1+p2; i++)
        {
            int r = findset(i);
            if(!belong[r])
                belong[r] = ++set_cnt;
            belong[i] = belong[r];
            v[belong[i]][rel[i]].PB(i);
            cnt[belong[i]][rel[i]]++;
        }
        /*for(int i=1; i<=set_cnt; i++)
        {
            cout << i << ": " << cnt[i][0] << " " << cnt[i][1] << endl;
            for(int j=0; j<cnt[i][0]; j++)
                cout << v[i][0][j] << " ";
            cout << endl;
            for(int j=0; j<cnt[i][1]; j++)
                cout << v[i][1][j] << " ";
            cout << endl;
        }*/
        dp[0][0] = 1;
        for(int i=1; i<=set_cnt; i++)
        {
            for(int j=0; j<=p1; j++)
            {
                if(j >= cnt[i][0] && dp[i-1][j-cnt[i][0]])
                {
                    dp[i][j] += dp[i-1][j-cnt[i][0]];
                    pre[i][j] = j - cnt[i][0];
                }
                if(j >= cnt[i][1] && dp[i-1][j-cnt[i][1]])
                {
                    dp[i][j] += dp[i-1][j-cnt[i][1]];
                    pre[i][j] = j - cnt[i][1];
                }
            }
        }
        if(dp[set_cnt][p1] == 1)    //有唯一解
        {
            vector<int> ans;
            int tmp = p1;
            for(int i=set_cnt; i; i--)
            {
                if(tmp - pre[i][tmp] == cnt[i][0])
                {
                    for(int j=0; j<cnt[i][0]; j++)
                        ans.PB(v[i][0][j]);
                }
                else
                {
                    for(int j=0; j<cnt[i][1]; j++)
                        ans.PB(v[i][1][j]);
                }
                tmp = pre[i][tmp];
            }
            sort(ans.begin(),ans.end());
            for(int i=0; i<ans.size(); i++)
            printf("%d\n",ans[i]);
            puts("end");
        }
        else
            puts("no");
    }
    return 0;
}
