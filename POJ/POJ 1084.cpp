/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-05-02
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: POJ
 *  Algorithm: IDA* / DLX 重复覆盖
 ********************************************************************************
 *  Algo-Description:
 ********************************************************************************
 */

//#pragma comment(linker,"/STACK:102400000,102400000")
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <climits>
#include <ctime>
#include <numeric>
#include <vector>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <complex>
#include <deque>
#include <functional>
#include <list>
#include <map>
#include <string>
#include <sstream>
#include <set>
#include <stack>
#include <queue>
//#include <bits/stdc++.h>
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

/* 解法一：IDA* */

vector<int> stk[62], squ[62];   //记录第i根木棍对应哪几个正方形；记录第i个正方形由哪几根木棍构成
int des[62];    //判断第i个正方形是否被破坏
int stkcnt, squcnt;
int ans;

void init(int n)
{
    int stride = n << 1 | 1;
    for(int i = 1; i <= n; i++) //枚举正方形的边长（大小）
    {
        for(int j = 1; (j - 1) / stride + i <= n; j += stride)  //枚举每一行每个正方形的起点跨度
        {
            for(int p = j; p - j + i <= n; p++) //枚举每行每个正方形上边的起点
            {
                squcnt++;
                for(int q = p; q < p + i; q++)  //枚举每个正方形的上下边
                {
                    squ[squcnt].PB(q);  //正方形的上边
                    stk[q].PB(squcnt);  //木棍对应正方形的边
                    squ[squcnt].PB(q + i * stride); //正方形的下边
                    stk[q + i * stride].PB(squcnt); //木棍对应正方形的边
                }
                for(int q = p + n; (q - p - n) / stride < i; q += stride)   //枚举每个正方形的左右边
                {
                    squ[squcnt].PB(q);  //正方形的左边
                    stk[q].PB(squcnt);  //木棍对应正方形的边
                    squ[squcnt].PB(q + i);  //正方形的右边
                    stk[q + i].PB(squcnt);  //木棍对应正方形的边
                }
            }
        }
    }
}

int h() //估值函数（合理缩小，实际上要删除的木棍数量要比估计的多）
{
    int cnt = 0;
    int tmp[62];
    for(int i = 1; i <= squcnt; i++)
        tmp[i] = des[i];
    for(int i = 1; i <= squcnt; i++)    //枚举每一个正方形
    {
        if(!tmp[i]) //如果该正方形未被破坏
        {
            cnt++;
            tmp[i] += squ[i].size();    //假设拿掉这根木棍相当于拿走了这根木棍所在正方形的所有木棍
            for(int j = 0; j < squ[i].size(); j++)
            {
                for(int k = 0; k < stk[squ[i][j]].size(); k++)
                    tmp[stk[squ[i][j]][k]]++;
            }
        }
    }
    //printf("cnt: %d\n", cnt);
    return cnt;
}

bool dfs(int sum, int ub)  //已经拿走的木棍和允许拿走的木棍数量上界
{
    if(sum + h() > ub)  //利用估值函数剪枝
        return false;
    //cout << sum << endl;
    int squid = 1;
    while(des[squid] > 0 && squid <= squcnt)   //枚举未被破坏的正方形
        squid++;
    if(squid > squcnt)  //如果所有的正方形都被破坏了
    {
        ans = min(ans, sum);
        return true;
    }
    for(int i = 0; i < squ[squid].size(); i++)  //对于未被破坏的正方形，尝试破坏
    {
        int tmp = squ[squid][i];    //枚举组成这个正方形的每一根木棍
        for(int j = 0; j < stk[tmp].size(); j++)    //枚举这根木棍对应的所有正方形
            des[stk[tmp][j]]++; //由该木棍组成的正方形都被破坏一条边
        if(dfs(sum + 1, ub))    //如果有合理解，直接返回
            return true;
        for(int j = 0; j < stk[tmp].size(); j++)    //枚举这根木棍对应的所有正方形
            des[stk[tmp][j]]--; //还原现场
    }
    return false;
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n, k;
        scanf("%d%d", &n, &k);
        stkcnt = (n + 1) * n * 2, squcnt = 0;   //木棍数量和正方形数量
        for(int i = 0; i <= 60; i++)
        {
            stk[i].clear();
            squ[i].clear();
        }
        init(n);
        memset(des, 0, sizeof(des));    //初始化所有木棍都存在
        for(int i = 0; i < k; i++)
        {
            int x;
            scanf("%d", &x);
            for(int j = 0; j < stk[x].size(); j++)
                des[stk[x][j]]++;
            stkcnt--;
        }
        ans = stkcnt;
        for(int i = 0; i <= stkcnt; i++)    //估计要取走的木棍数量
        {
            if(dfs(0, i))
                break;
        }
        printf("%d\n", ans);
    }
    return 0;
}


/* 解法二：DLX重复覆盖 */

const int MAXN = 65;
const int MAXNODE = 65 * 65;

class DLX
{
public:
    int m, sz;  //列数，结点数
    int S[MAXN];    //每列结点数

    int row[MAXNODE], col[MAXNODE]; //row/col数组用来记录某个标号的结点在矩阵中的行号和列号
    int L[MAXNODE], R[MAXNODE], U[MAXNODE], D[MAXNODE]; //U/D/R/L数组用来记录某个标号的结点的上下左右结点的编号（十字链表）

    int ansd, ans[MAXN];    //解的数量和解

    void init(int m)    //m为列数
    {
        this -> m = m;
        //虚拟结点
        for(int i = 0; i <= m; i++)
        {
            U[i] = i, D[i] = i, L[i] = i - 1, R[i] = i + 1;
            col[i] = i;
        }
        R[m] = 0, L[0] = m;
        sz = m + 1;
        memset(S, 0, sizeof(S));
    }

    //行列都是从1开始标号
    void addRow(int r, vector<int>& columns)
    {
        /*for(int i = 0; i < columns.size(); i++)
            printf("%d ", columns[i]);
        puts("\n----------");*/
        int first = sz;
        for(int i = 0; i < (int)columns.size(); i++)
        {
            int c = columns[i];
            L[sz] = sz - 1;
            R[sz] = sz + 1;
            D[sz] = c;
            U[sz] = U[c];
            D[U[c]] = sz;
            U[c] = sz;
            row[sz] = r;
            col[sz] = c;
            S[c]++;
            sz++;
        }
        R[sz - 1] = first;
        L[first] = sz - 1;
    }

    void removeNode(int c)
    {
        L[R[c]] = L[c];
        R[L[c]] = R[c];
        --S[col[c]];
    }

    //删除列
    void removeCol(int c)
    {
        for(int i = D[c]; i != c; i = D[i])
            removeNode(i);
    }

    void restoreNode(int c)
    {
        ++S[col[c]];
        L[R[c]] = c;
        R[L[c]] = c;
    }

    //恢复列
    void restoreCol(int c)
    {
        for(int i = U[c]; i != c; i = U[i])
            restoreNode(i);
    }

    void removeRow(int r)
    {
        for(int j = R[r]; j != r; j = R[j])
        {
            U[D[j]] = U[j];
            D[U[j]] = D[j];
            --S[col[j]];
        }
    }

    void restoreRow(int r)
    {
        for(int j = L[r]; j != r; j = L[j])
        {
            ++S[col[j]];
            U[D[j]] = j;
            D[U[j]] = j;
        }
    }

    int ret;
    int vis[MAXN];

    int h() //估价函数：模拟删除列，函数返回的是至少还需要多少行才能完成重复覆盖
    {
        memset(vis, 0, sizeof(vis));
        int res = 0;
        for(int i = R[0]; i != 0; i = R[i])
        {
            if(vis[col[i]])
                continue;
            vis[col[i]] = 1;
            ++res;
            for(int j = D[i]; j != i; j = D[j])
            {
                //printf("j: %d, R[j]: %d\n", j, R[j]);
                if(col[j])
                {
                    for(int k = R[j]; k != j; k = R[k])
                        vis[col[k]] = 1;
                }
            }
        }
        return res;
    }

    bool dfs(int d)
    {
        //printf("h(): %d\n", h());
        if(d + h() > ansd)
            return false;
        if(R[0] == 0)
            return true;
        //找S最小的列来删除加速
        int c = R[0];
        for(int i = R[0]; i != 0; i = R[i])
        {
            if(S[i] < S[c])
                c = i;
        }
        for(int i = D[c]; i != c; i = D[i])
        {
            removeCol(i);
            for(int j = R[i]; j != i; j = R[j])
                removeCol(j);
            if(dfs(d + 1))
                return true;
            for(int j = L[i]; j != i; j = L[j])
                restoreCol(j);
            restoreCol(i);
        }
        return false;
    }

    vector<int> rela[65];

    int prev(int n)
    {
        int cnt = 0, stride = n << 1 | 1;
        for(int sd = 1; sd <= n; sd++)  //枚举正方形的边长
        {
            for(int i = 1; i - 1 + sd <= n; i++) //枚举每行正方形的起始点
            {
                for(int j = 1; j - 1 + sd <= n; j++)    //枚举每个正方形上边的起始点
                {
                    bool destroy = false;   //标记这个正方形初始状态是否被破坏
                    for(int k = 0; k < sd; k++) //每个正方形的每条边
                    {
                        int s1 = (i - 1) * stride + j + k;  //正方形的上边
                        int s2 = (i - 1 + sd) * stride + j + k; //正方形的下边
                        int s3 = i * n + (i - 1) * (n + 1) + j + k * stride;    //正方形的左边
                        int s4 = i * n + (i - 1) * (n + 1) + j + k * stride + sd;   //正方形的右边
                        destroy |= (vis[s1] | vis[s2] | vis[s3] | vis[s4]); //检查这个正方形是否每条边都在
                    }
                    if(destroy)
                        continue;
                    cnt++;
                    for(int k = 0; k < sd; k++) //每个正方形的每条边
                    {
                        rela[(i - 1) * stride + j + k].PB(cnt); //正方形的上边
                        rela[(i - 1 + sd) * stride + j + k].PB(cnt);    //正方形的下边
                        rela[i * n + (i - 1) * (n + 1) + j + k * stride].PB(cnt);   //正方形的左边
                        rela[i * n + (i - 1) * (n + 1) + j + k * stride + sd].PB(cnt);  //正方形的右边
                    }
                }
            }
        }
        return cnt;
    }

    void solve(int n, int k)
    {
        int rowcnt = (n + 1) * n * 2, colcnt = 0;
        for(int i = 0; i <= rowcnt; i++)
            rela[i].clear();
        memset(vis, 0, sizeof(vis));
        for(int i = 0; i < k; i++)
        {
            int x;
            scanf("%d", &x);
            vis[x] = 1;
        }
        colcnt = prev(n);    //预处理
        //printf("colcnt: %d\n", colcnt);
        init(colcnt);
        int cnt = 0;
        for(int i = 1; i <= rowcnt; i++)
        {
            if(rela[i].size())
                addRow(++cnt, rela[i]);
        }
        /*int cnt = 0;
        for(int i = 1; i <= rowcnt; i++)
        {
            printf("i: %d\n", i);
            for(int j = 1; j <= colcnt; j++)
            {
                cnt++;
                printf("U: %d, D: %d, L: %d, R: %d\n", U[cnt], D[cnt], L[cnt], R[cnt]);
            }
        }*/
        for(ansd = 1; ansd <= rowcnt; ansd++)
        {
            if(dfs(0))
                break;
        }
        //bool flag = dfs(0);
        printf("%d\n", ansd);
    }
} dlx;

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n, k;
        scanf("%d%d", &n, &k);
        dlx.solve(n, k);
    }
    return 0;
}
