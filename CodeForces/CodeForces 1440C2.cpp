/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-06-10
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm: 大模拟
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

const int MAXN = 105;

struct Operation
{
    int x1, y1, x2, y2, x3, y3;
    Operation() {}
    Operation(int x1, int y1, int x2, int y2, int x3, int y3) : x1(x1), y1(y1), x2(x2), y2(y2), x3(x3), y3(y3) {}
};

vector<Operation> ans;
int a[MAXN][MAXN];

void operate(int x1, int y1, int x2, int y2, int x3, int y3)
{
    a[x1][y1] ^= 1;
    a[x2][y2] ^= 1;
    a[x3][y3] ^= 1;
    ans.PB(Operation(x1, y1, x2, y2, x3, y3));
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; i++)
        {
            char s[MAXN];
            scanf("%s", s + 1);
            for(int j = 1; j <= m; j++)
                a[i][j] = s[j] - '0';
        }
        ans.clear();
        for(int i = 1; i < n - 1; i++)
        {
            for(int j = 1; j < m; j++)
            {
                if(a[i][j])
                {
                    if(a[i][j + 1])
                        operate(i, j, i, j + 1, i + 1, j);  //推到右下角
                    else
                        operate(i, j, i + 1, j, i + 1, j + 1);  //推到下方两格
                }
                else
                {
                    if(a[i][j + 1])
                        operate(i, j + 1, i + 1, j, i + 1, j + 1);  //推到下方两个
                }
            }
        }
        for(int j = 1; j < m; j++)
        {
            if(a[n - 1][j])
            {
                if(a[n][j])
                    operate(n - 1, j, n, j, n, j + 1);  //推到右下角
                else
                    operate(n - 1, j, n - 1, j + 1, n, j + 1);  //推到右侧两格
            }
            else
            {
                if(a[n][j])
                    operate(n, j, n - 1, j + 1, n, j + 1);  //推到右侧两格
            }
        }

        for(int i = 1; i < n; i++)
        {
            if(a[i][m])
            {
                if(a[i + 1][m])
                {
                    operate(i, m - 1, i, m, i + 1, m - 1);
                    operate(i + 1, m, i + 1, m - 1, i, m - 1);
                }
                else
                {
                    operate(i, m, i, m - 1, i + 1, m);
                    operate(i, m - 1, i, m, i + 1, m - 1);
                    operate(i + 1, m, i, m, i + 1, m - 1);
                }
            }
        }
        if(a[n - 1][m] && a[n][m])
        {
            operate(n - 1, m - 1, n, m - 1, n - 1, m);
            operate(n, m - 1, n - 1, m - 1, n, m);
        }
        else if(a[n - 1][m])
        {
            operate(n - 1, m, n - 1, m - 1, n, m);
            operate(n - 1, m - 1, n, m - 1, n - 1, m);
            operate(n, m, n, m - 1, n - 1, m);
        }
        if(a[n][m])
        {
            operate(n, m, n - 1, m, n, m - 1);
            operate(n, m - 1, n, m, n - 1, m - 1);
            operate(n - 1, m, n, m, n - 1, m - 1);
        }
        /*for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
                printf("%d", a[i][j]);
            puts("");
        }*/
        printf("%d\n", ans.size());
        for(int i = 0; i < ans.size(); i++)
            printf("%d %d %d %d %d %d\n", ans[i].x1, ans[i].y1, ans[i].x2, ans[i].y2, ans[i].x3, ans[i].y3);
    }
    return 0;
}
