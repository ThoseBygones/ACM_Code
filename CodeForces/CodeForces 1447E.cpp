/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-06-09
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm: 贪心 + 01字典树 + dfs（递归）
 ********************************************************************************
 *  Algo-Description:
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

int dfs(vector<int> v, int dep)
{
    if(v.size() <= 2)
        return v.size();
    vector<int> v0, v1; //分别记录当前位为0和1的数字
    for(int i = 0; i < v.size(); i++)
    {
        if(v[i] & (1 << dep))   //当前位为1
            v1.PB(v[i]);
        else    //当前位为0
            v0.PB(v[i]);
    }
    int res0 = dfs(v0, dep - 1), res1 = dfs(v1, dep - 1);
    return max(res0, res1) + (min(res0, res1) ? 1 : 0);  //结点数量小的子树只能保留一个结点用于跟当前位数字不同的另一个子树合并，否则会形成森林
}

int main()
{
    int n;
    scanf("%d", &n);
    vector<int> v;
    for(int i = 1; i <= n; i++)
    {
        int x;
        scanf("%d", &x);
        v.PB(x);
    }
    int ans = dfs(v, 30);   //保留的结点数量
    printf("%d\n", n - ans);
    return 0;
}
