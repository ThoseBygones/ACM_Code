/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-02-17
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: CodeForces
 *  Algorithm: 数学/贪心（？）
 ********************************************************************************
 *  Algo-Description:
 * > 从后往前遍历（避免LIS中前面的字符影响后面）。
 * > 如果当前位置的数字是0：
 *   > 该0一定是以它为起点的区间的LIS的一部分；如果改变，LIS长度一定会变小。
 *   > 同时为了使0尽量多，所以s串中的0肯定不变。
 * > 如果当前位置的数字是1：
 *   > 对于那些LIS包含它的区间，pi从1变为0对这些区间的LIS长度没有影响：
 *     > 设包含它的这些LIS序列为p1,p2,...,pi,pi+1,...,pm.（pi为当前讨论的这个1）
 *     > 显然pi+1,...,pm均为1（否则这些项不可能属于这个LIS）
 *   > 对于那些LIS不包含它的区间，该1变为0会改变这些区间的LIS长度：
 *     > 设包含它的这些LIS序列为p1,p2,...,pi,pi+1,...,pm（pi为当前讨论的这个1）。
 *     > 若想将pi从1变为0而不改变LIS长度，必须保证pi+1,...,pm中1的数量大于等于0（不含修改）。
 *     > 这种情况下该LIS的pi+1,...,pm部分取全0和全1时LIS长度均相同，故pi可改为0。
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
#define MAXN 2005

char str[MAXN];

int main()
{
    scanf("%s",str);
    int len = strlen(str);
    int zero = 0, one = 0;
    for(int i=len-1; i>=0; i--)
    {
        if(str[i] == '0')
            zero++;
        else
            one++;
        if(one > zero)
        {
            one--;
            str[i] = '0';
        }
    }
    printf("%s",str);
    return 0;
}
