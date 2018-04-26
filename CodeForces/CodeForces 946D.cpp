/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2018-04-26
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
#define MAXN 505

char s[MAXN][MAXN];
int cnt[MAXN];  //cnt[i]表示第i天有多少节课
int v[MAXN][MAXN];  //v[i][j]表示第i天逃j节课后不在学校的最大时间
int dp[MAXN];   //dp[k]表示逃k节课后不在学校的最大时间

vector <int> pos[MAXN]; //pos[i][j]表示第i天需要上的第j节课的位置

int main()
{
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0; i<n; i++)
    {
        scanf("%s",s[i]);
        for(int j=0; j<m; j++)
        {
            if(s[i][j]=='1')
            {
                cnt[i]++;
                pos[i].PB(j);
            }
        }
    }
    //预处理
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<=min(cnt[i]-1,k); j++) //枚举逃课的节数
        {
            int sum=INF;
            for(int l=0; l<=j; l++) //从第pos[i][l]节开始逃课
                sum=min(sum,pos[i][cnt[i]-j+l-1]-pos[i][l]+1);
            v[i][j]=m-sum;
        }
        v[i][cnt[i]]=m; //逃掉全部课
    }
    //分组背包
    for(int i=0; i<n; i++)
    {
        for(int j=k; j>=0; j--)
        {
            for(int l=0; l<=min(j,cnt[i]); l++)
                dp[j]=max(dp[j],dp[j-l]+v[i][l]);
        }
    }
    printf("%d\n",m*n-dp[k]);
    return 0;
}
