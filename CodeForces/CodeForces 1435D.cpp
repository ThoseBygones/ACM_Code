/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-06-04
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm: STL stack
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

const int MAXN = 100005;

stack<int> s;
int ans[MAXN];

int main()
{
    int n;
    scanf("%d", &n);
    int id = 1;
    bool flag = true;
    for(int i = 1; i <= 2 * n; i++)
    {
        char op[2];
        scanf("%s", op);
        if(op[0] == '+')
            s.push(id++);
        else if(op[0] == '-')
        {
            int x;
            scanf("%d", &x);
            if(s.empty())
                flag = false;
            else
            {
                int top = s.top();
                s.pop();
                ans[top] = x;
                if(ans[top] < ans[top + 1]) //如果top位置（当前栈顶）元素已经弹出，但是top + 1位置的数已经入栈并弹出，且数值更大，则不符合题目要求（总是选择最小的）
                    flag = false;
            }
        }
    }
    if(flag)
    {
        puts("YES");
        for(int i = 1; i <= n; i++)
            printf("%d%c", ans[i], (i == n ? '\n' : ' '));
    }
    else
        puts("NO");
    return 0;
}
