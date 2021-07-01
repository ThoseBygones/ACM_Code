/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-07-01
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm: 数学规律
 ********************************************************************************
 *  Algo-Description:
 * > 最后得到的 b 串就是将排列 p 的第 k − (n − k) 到 k − 1 个数翻转到后面去，
 * > 这样 b 串中第 k − (n − k) 到第 n 的数，形成了一个回文串。
 * > 通过模拟可以发现，相同长度回文串的逆序数是固定的（本题数字组成都是一样的，也就是左半部分数字都不同）。
 * > 那么真正影响逆序数的就是前面 k − (n − k) − 1 个数。
 * > 为了最小化，只能填 [1, 2, 3, ..., k − (n − k) − 1] ，
 * > 而 k − (n − k) 到 n 的数，则填成 [k, k − 1, k − 2, ..., k − (n − k), k − (n − k) + 1, k]；
 * > 这样的形式可以保证字典序最大。
 * > 所以结果就是把 1, 2, 3, ..., k 中后 n − k + 1 个数翻转一下。
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

const int MAXN = 100005;

int p[MAXN];

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n, k;
        scanf("%d%d", &n, &k);
        for(int i = 1; i < k - (n - k); i++)
            p[i] = i;
        int val = k;
        for(int i = k - (n - k); i <= k; i++)
            p[i] = val--;
        for(int i = 1; i <= k; i++)
            printf("%d%c", p[i], (i == k ? '\n' : ' '));
    }
    return 0;
}
