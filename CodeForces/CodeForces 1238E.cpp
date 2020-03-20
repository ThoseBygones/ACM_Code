/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-03-18
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: CodeForces
 *  Algorithm: 状压dp
 ********************************************************************************
 *  Algo-Description:
 * > dp[S]是把状态S（某些字母已经按照某种顺序在键盘上时）slowness的最小值。
 * > 每次转移选择一个还未被排列在键盘上的字母将其排列在键盘的最右端；
 * > 由于dp[S]中S的状态只记录哪些字母已经被排列在键盘上，并不记录它们被排列在键盘上的先后顺序，
 * > 因此此时的slowness值需要加上所有的已放字符和未放字符的转移次数之和；
 * > 即已经被排列在键盘上的字母对slowness的贡献值已经被计算完毕，
 * > 下一步状态转移（加入新的字母）只需要加上在已经排列在键盘上的字母和未排列在键盘上字母之间移动的代价；
 * > 因为越早被排列在键盘上的字母距离下一步将要被排列在键盘上的字母越远（两字母间移动需要经过较晚被排列在键盘上的字母），
 * > 即对于较早被排列在键盘上的字母，计算的次数越多。
 * > 对于新加入的字母，它与已加入的所有数字的距离都会 + 1，而与未加入的所有的数字都会 - 1；
 * > 即对于所有已加入的数字和未加入的数字，他们构成的两个集合之间两两字母的距离 + 1。
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

char s[MAXN];
int cnt[25][25];    //cnt[i][j]表示在键盘上从字母i向字母j移动的次数
int dp[1<<20];  //dp[S]表示键盘上字符就位情况为S（其中S的某一位为1表示该字母已就位，0表示未就位）时，键盘slowness的最小值

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    scanf("%s",s);
    for(int i=1; i<n; i++)
    {
        cnt[s[i-1]-'a'][s[i]-'a']++;
        cnt[s[i]-'a'][s[i-1]-'a']++;
    }
    fill(dp,dp+(1<<m),INF);
    dp[0] = 0;
    for(int S=0; S<(1<<m); S++)    //枚举状态
    {
        int sum = 0;    //当前状态下，所有已确定键盘位置的字母往未确定键盘位置字母移动的总数
        for(int i=0; i<m; i++)  //枚举所有未确定键盘位置的字母
        {
            if(!(S & (1<<i)))
            {
                for(int j=0; j<m; j++)  //枚举所有已确定键盘位置的字母
                {
                    if(S & (1<<j))
                        sum += cnt[j][i];
                }
            }
        }
        for(int i=0; i<m; i++)  //枚举下一个要确定键盘位置的字母
            dp[S|(1<<i)] = min(dp[S|(1<<i)],dp[S]+sum);
    }
    printf("%d\n",dp[(1<<m)-1]);
    return 0;
}
