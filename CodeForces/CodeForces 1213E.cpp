/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-01-01
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

char mode[6][5] = {"abc", "acb", "bac", "bca", "cab","cba"};
char str[2][3];
char res[MAXN*3];
int n;

int main()
{
    scanf("%d%s%s",&n,str[0],str[1]);
    for(int k=0; k<6; k++)  //遍历判断六种模式
    {
        bool ok = true;
        for(int i=0; i<n; i++)  //构造acbacbacb型字符串
        {
            res[i*3] = mode[k][0];
            res[i*3+1] = mode[k][1];
            res[i*3+2] = mode[k][2];
        }
        for(int i=0; i<3; i++)
        {
            if((res[i] == str[0][0] && res[i+1] == str[0][1]) || (res[i] == str[1][0] && res[i+1] == str[1][1]))
                ok = false;
        }
        if(ok)
        {
            puts("YES");
            printf("%s\n",res);
            return 0;
        }
        ok = true;
        for(int i=0; i<n; i++)  //构造aaabbbccc型字符串
        {
            res[i] = mode[k][0];
            res[i+n] = mode[k][1];
            res[i+2*n] = mode[k][2];
        }
        for(int i=0; i<3; i++)
        {
            if((res[i*n] == str[0][0] && res[i*n+1] == str[0][1]) || (res[i*n] == str[1][0] && res[i*n+1] == str[1][1]))
                ok = false;
            if(i)
            {
                if((res[i*n-1] == str[0][0] && res[i*n] == str[0][1]) || (res[i*n-1] == str[1][0] && res[i*n] == str[1][1]))
                    ok = false;
            }
        }
        if(ok)
        {
            puts("YES");
            printf("%s\n",res);
            return 0;
        }
    }
    puts("NO");
    return 0;
}
