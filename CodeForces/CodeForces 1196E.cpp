/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2019-08-13
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


int main()
{
    int q;
    scanf("%d",&q);
    while(q--)
    {
        int b,w;
        scanf("%d%d",&b,&w);
        if(max(b,w) > min(b,w) * 3 + 1)   //排除不存在的情况
            puts("NO");
        else
        {
            puts("YES");
            if(b == w)  //数量相等
            {
                for(int i=1; i<=b+w; i++)
                    printf("1 %d\n",i);
            }
            else if(b > w)  //黑色的多
            {
                int tb = b, tw = w, pos = 1;
                for(int i=1; tw; i++)   //从第二行开始把白色用完
                {
                    printf("2 %d\n",i);
                    pos = i;
                    if(i & 1)
                        tb--;
                    else
                        tw--;
                }
                printf("2 %d\n",pos+1); //补上最后一个白色后面的黑色
                tb--;
                for(int i=2; i<=pos && tb; i+=2)    //黑色还不足，则从第一行开始补
                {
                    printf("1 %d\n",i);
                    tb--;
                }
                for(int i=2; i<=pos && tb; i+=2)    //黑色还不足，则从第三行开始补
                {
                    printf("3 %d\n",i);
                    tb--;
                }
            }
            else    //白色的多
            {
                int tb = b, tw = w, pos = 1;
                for(int i=1; tb; i++)   //从第三行开始把黑色用完
                {
                    printf("3 %d\n",i);
                    pos = i;
                    if(i & 1)
                        tw--;
                    else
                        tb--;
                }
                printf("3 %d\n",pos+1); //补上最后一个黑色后面的白色
                tw--;
                for(int i=2; i<=pos && tw; i+=2)    //白色还不足，则从第二行开始补
                {
                    printf("2 %d\n",i);
                    tw--;
                }
                for(int i=2; i<=pos && tw; i+=2)    //白色还不足，则从第四行开始补
                {
                    printf("4 %d\n",i);
                    tw--;
                }
            }
        }
    }
    return 0;
}
