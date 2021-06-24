/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-06-24
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm: 数学公式 + 贪心
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

const int MAXN = 100005;

char s[MAXN];
int cnt[30];
LL p2[30];

int main()
{
    int n;
    LL sum;
    scanf("%d%lld", &n, &sum);
    scanf("%s", s + 1);
    p2[0] = 1;
    for(int i = 1; i < 26; i++)
        p2[i] = p2[i - 1] << 1;
    sum -= (p2[s[n] - 'a'] - p2[s[n - 1] - 'a']);   //s[n - 1] 必定为负贡献，s[n] 必定为正贡献
    for(int i = 1; i <= n - 2; i++) //除了 s[n - 1] 和 s[n]，其它位置的字符贡献可以构造为正或负
    {
        cnt[s[i] - 'a']++;  //记录每个字符出现的数量
        sum += p2[s[i] - 'a'];  //累计所有字符为正的贡献（初始默认为正贡献）
    }
    if(sum < 0) //尽量往正贡献凑还凑不到
        puts("No");
    else if(sum == 0)   //刚好凑到
        puts("Yes");
    else    //否则开始修改
    {
        for(int i = 25; i >= 0; i--)    //从大到小开始尝试把正贡献改为负贡献
        {
            while(cnt[i] && sum - 2 * p2[i] >= 0)   //如果该字符还有，尝试选择其中一个改为负贡献
            {
                cnt[i]--;
                sum -= 2 * p2[i];   //该字符贡献由正贡献改为负贡献，差值为自己的两倍
            }
        }
        puts(sum ? "No" : "Yes");
    }
    return 0;
}
