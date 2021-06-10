/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-06-10
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm:
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
char a[MAXN][MAXN];

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; i++)
            scanf("%s", a[i] + 1);
        ans.clear();
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                if(a[i][j] == '1')
                {
                    if(i == n)
                    {
                        if(j == 1)  //左下角
                        {
                            ans.PB(Operation(i, j, i - 1, j, i, j + 1));
                            ans.PB(Operation(i - 1, j, i, j, i - 1, j + 1));
                            ans.PB(Operation(i, j + 1, i, j, i - 1, j + 1));
                        }
                        else    //右下角
                        {
                            ans.PB(Operation(i, j, i - 1, j, i, j - 1));
                            ans.PB(Operation(i, j - 1, i - 1, j - 1, i, j));
                            ans.PB(Operation(i - 1, j, i, j, i - 1, j - 1));
                        }
                    }
                    else
                    {
                        if(j == m)  //右上角
                        {
                            ans.PB(Operation(i, j, i, j - 1, i + 1, j));
                            ans.PB(Operation(i, j - 1, i, j, i + 1, j - 1));
                            ans.PB(Operation(i + 1, j, i, j, i + 1, j - 1));
                        }
                        else    //左上角
                        {
                            ans.PB(Operation(i, j, i + 1, j, i, j + 1));
                            ans.PB(Operation(i + 1, j, i, j, i + 1, j + 1));
                            ans.PB(Operation(i, j + 1, i, j, i + 1, j + 1));
                        }
                    }
                }
            }
        }
        printf("%d\n", ans.size());
        for(int i = 0; i < ans.size(); i++)
            printf("%d %d %d %d %d %d\n", ans[i].x1, ans[i].y1, ans[i].x2, ans[i].y2, ans[i].x3, ans[i].y3);
    }
    return 0;
}
