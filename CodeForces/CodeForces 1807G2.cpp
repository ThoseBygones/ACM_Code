/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2025-01-18
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm: 排序 + 贪心
 ********************************************************************************
 *  Algo-Description:
 * > 序列最初的数为 1，因此第一个新生成的数只能为 1，第二个新生成的数只能为 1 或 2。
 * > 以此类推每次新生成的最大合法数字组成的序列为：1, 1, 2, 4, 8, ...
 * > 即新生成的合法数字最大只能为前面所有数字的和，小于则能被合成；
 * > 因为序列为二进制序列 {2 ^ (k - 1)} 可以组成任意 2 ^ k - 1 以内的数，且多一个 1 可用于补足至 2 ^ k
 ********************************************************************************
 */


#include <bits/stdc++.h>
using namespace std;

template<class T> inline T sqr(T x) {return x * x;}
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

const int MAXN = 200005;

LL a[MAXN], sum[MAXN];

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            scanf("%lld", &a[i]);
        sort(a, a + n);
        for(int i = 0; i < n; i++)
            sum[i] = sum[i - 1] + a[i];
        bool flag = true;
        for(int i = n - 1; i; i--)
        {
            if(sum[i - 1] < a[i])   //第i个数必定小于等于前面i-1个数的和，否则不可能被合成
            {
                flag = false;
                break;
            }
        }
        if(a[0] != 1)   //最小的数必须为1
            flag = false;
        puts(flag ? "YES" : "NO");
    }
    return 0;
}
