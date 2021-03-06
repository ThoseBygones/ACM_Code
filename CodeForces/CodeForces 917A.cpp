/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2018-02-24
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
#define MAXN 5005

char s[MAXN];

int main()
{
    scanf("%s",s);
    int len=strlen(s);
    int ans=0;
    for(int i=0; i<len; i++)    //枚举序列的左端点
    {
        int lb=0;   //所有左括号比所有右括号多的数量（包括问号变的左右括号）
        int qm2rb=0;    //问号变成右括号的数量
        for(int j=i; j<len; j++)    //枚举序列的右端点
        {
            if(s[j]=='(')
                lb++;
            else if(s[j]==')')
            {
                if(lb==qm2rb)
                    qm2rb--;    //把一个原来变成右括号的问号变成左括号
                else
                    lb--;
                if(lb<0 || qm2rb<0)    //不是合法串
                    break;
            }
            else
            {
                if(lb==qm2rb)
                    lb++;   //变成左括号
                else
                    qm2rb++;    //变成右括号
            }
            if(!((j-i+1)&1) && lb==qm2rb)    //子串序列长度为奇数肯定不合法
            {
                //cout << i << " " << j << endl;
                ans++;
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
