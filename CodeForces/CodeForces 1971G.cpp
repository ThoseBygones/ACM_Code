/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2025-03-06
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm: map + 优先队列 + 位运算
 ********************************************************************************
 *  Algo-Description:
 * > a xor b < 4 表明两个数的二进制表示在（除了最低两位外的）高位上是完全相同的。
 * > 因此预处理把每个数右移两位屏蔽掉最低两位，建立map。
 * > 处理后的数如果二进制表示相同，那么它们之间可以随意交换直至内部有序。
 * > 对于建立的map中，每个预处理后的二进制表示建立一个优先队列用于排序，排好序后依次放回原来的空位。
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

map<int, priority_queue<int, vector<int>, greater<int> > > mp;  //map嵌套堆
int a[MAXN];

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
            mp[a[i] >> 2].push(a[i]);   //最低两位不看，右移两位建立map
        }
        for(int i = 1; i <= n; i++)
        {
            int x = mp[a[i] >> 2].top();
            mp[a[i] >> 2].pop();
            printf("%d%c", x, i == n ? '\n' : ' ');
        }
    }
    return 0;
}
