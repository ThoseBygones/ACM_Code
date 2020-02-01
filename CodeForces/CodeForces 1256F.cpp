/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-02-01
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: CodeForces
 *  Algorithm:
 * > 无限次数的子串翻转可以通过一定次数相邻两个字符的交换得到。
 * > 两个字符串中每种字符出现次数必须相同。
 * > 如果某种字符出现次数大于1，答案为YES。
 * > 证明：
 *   > 先将字符串s通过交换相邻两个字符得到有序字符串；
 *   > 再将字符串t串通过交换相邻两个字符得到有序字符串。
 *   > 如果两串翻转次数的奇偶性不同，由于字符串中某种字符出现次数大于1，故可以通过交换相邻两个相同字符来使两串翻转次数的奇偶性相同。
 * > 如果字符串中没有某种字符出现次数大于1，则说明两个字符串长度一定不会大于26，此时暴力翻转判断即可。
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
#define MAXN 200005

int cnts[30],cntt[30];
char s[MAXN],t[MAXN];

int main()
{
    int q;
    scanf("%d",&q);
    while(q--)
    {
        int n;
        scanf("%d",&n);
        scanf("%s%s",s,t);
        memset(cnts,0,sizeof(cnts));
        memset(cntt,0,sizeof(cntt));
        for(int i=0; i<n; i++)
        {
            cnts[s[i]-'a']++;
            cntt[t[i]-'a']++;
        }
        bool ok = false;
        for(int i=0; i<26; i++) //判断是否所有字符出现次数相同
        {
            if(cnts[i] != cntt[i])
            {
                ok = true;
                puts("NO");
                break;
            }
        }
        if(ok)
            continue;
        for(int i=0; i<26; i++) //判断是否出现重复字符
        {
            if(cnts[i] > 1)
            {
                ok = true;
                puts("YES");
                break;
            }
        }
        if(ok)
            continue;
        int cnt1 = 0, cnt2 = 0;
        for(int i=0; i<n; i++)  //暴力翻转
        {
            for(int j=0; j<i; j++)
            {
                if(s[j] > s[i])
                    cnt1++;
                if(t[j] > t[i])
                    cnt2++;
            }
        }
        //cout << cnt1 << " " << cnt2 << endl;
        if((cnt1&1) ^ (cnt2&1))
            puts("NO");
        else
            puts("YES");
    }
    return 0;
}
