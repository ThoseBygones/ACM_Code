/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-06-29
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm: 单调栈
 ********************************************************************************
 *  Algo-Description:
 * > 一个 k 生成的数组里面必定有 1 ~ n - k + 1 的所有数字；
 * > 1~ n - k + 1 这些数字之间：
 *   > 每个数字元素必定可以有一个区间长度 >= k
 *   > 这个区间的最小值为这个数字 (1 <= i <= n - k + 1)
 * > 因为如果区间长度大于等于 k 了，那么肯定能取到 k 这个长度的区间。
 * > 所以对于每一个 1 ~ n 的数，寻找一个长度最大的区间，满足：
 *   > 该元素是区间的最小值；
 *   > 该长度最大的区间满足 len[n - i + 1] >= i。
 * > 两遍单调栈，每次找一个元素右边第一个比它小的元素和左边第一个比它小的元素
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

const int MAXN = 300005;

struct Node
{
    int val, id;
    Node() {}
    Node(int val, int id) : val(val), id(id) {}
} sta[MAXN];

int a[MAXN], l[MAXN], r[MAXN], ans[MAXN];

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
            l[i] = r[i] = -1;
            ans[i] = 0;
        }
        int top = -1;
        for(int i = 1; i <= n; i++)
        {
            while(~top && sta[top].val > a[i])
                r[sta[top--].id] = i;   //向右延伸到的位置
            sta[++top] = Node(a[i], i);
        }
        while(~top)
            r[sta[top--].id] = n + 1;
        top = -1;
        for(int i = n; i; i--)
        {
            while(~top && sta[top].val > a[i])
                l[sta[top--].id] = i;   //向左有伸到的位置
            sta[++top] = Node(a[i], i);
        }
        while(~top)
            l[sta[top--].id] = 0;
        /*for(int i = 1; i <= n; i++)
            printf("%d - %d\n", l[i], r[i]);
        */
        for(int i = 1; i <= n; i++)
            ans[a[i]] = max(ans[a[i]], r[i] - l[i] - 1);    //最大能覆盖的区间长度
        for(int i = 2; i <= n; i++)
            ans[i] = min(ans[i - 1], ans[i]);   //数字i前面数字的区间长度一定大于等于ans[i]
        /*for(int i = 1; i <= n; i++)
            printf("ans: %d\n", ans[i]);
        */
        for(int i = 1; i <= n; i++)
        {
            if(ans[n - i + 1] >= i)
                printf("1");
            else
                printf("0");
        }
        puts("");
    }
    return 0;
}
