/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-01-26
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: POJ
 *  Algorithm: DLX精确覆盖（Dancing Links）解数独
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

const int MAXN = 16 * 16 * 16 * 4 + 5;
const int MAXM = 16 * 16 + 5;
const int MAXNODE = 16 * 16 * 16 * 16 * 4 + 5;
//行编号从1开始，列编号为1~n，结点0是表头结点; 结点1~n是各列顶部的虚拟结点

class DLX
{
public:
    int m, sz;  //列数，结点数
    int nds[MAXN];  //每列结点数

    int row[MAXNODE], col[MAXNODE]; //row/col数组用来记录某个标号的结点在矩阵中的行号和列号
    int L[MAXNODE], R[MAXNODE], U[MAXNODE], D[MAXNODE]; //U/D/R/L数组用来记录某个标号的结点的上下左右结点的编号（十字链表）

    int ansd, ans[MAXM];    //解的数量和解

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
        memset(nds, 0, sizeof(nds));
    }

    void addRow(int r, vector<int>& columns)
    {
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
            nds[c]++;
            sz++;
        }
        R[sz - 1] = first;
        L[first] = sz - 1;
    }

    void removeNode(int c)
    {
        L[R[c]] = L[c];
        R[L[c]] = R[c];
    }

    //删除列
    void removeCol(int c)
    {
        removeNode(c);
        for(int i = D[c]; i != c; i = D[i])
            removeRow(i);
    }

    void restoreNode(int c)
    {
        L[R[c]] = c;
        R[L[c]] = c;
    }

    //恢复列
    void restoreCol(int c)
    {
        for(int i = U[c]; i != c; i = U[i])
            restoreRow(i);
        restoreNode(c);
    }

    void removeRow(int r)
    {
        for(int j = R[r]; j != r; j = R[j])
        {
            U[D[j]] = U[j];
            D[U[j]] = D[j];
            --nds[col[j]];
        }
    }

    void restoreRow(int r)
    {
        for(int j = L[r]; j != r; j = L[j])
        {
            ++nds[col[j]];
            U[D[j]] = j;
            D[U[j]] = j;
        }
    }

    bool dfs(int d)
    {
        if(R[0] == 0)   //找到解
        {
            ansd = d;
            return true;
        }
        //找S最小的列来删除加速
        int c = R[0];   // 第一个未删除的列
        for(int i = R[0]; i != 0; i = R[i])
        {
            if(nds[i] < nds[c])
                c = i;
        }
        removeCol(c);   //删除第c列
        for(int i = D[c]; i != c; i = D[i]) //用结点i所在行覆盖第c列
        {
            ans[d] = row[i];
            for(int j = R[i]; j != i; j = R[j]) //删除结点i所在行能覆盖的所有其他列
                removeCol(col[j]);
            if(dfs(d + 1))
                return true;
            for(int j = L[i]; j != i; j = L[j]) //恢复结点i所在行能覆盖的所有其他列
                restoreCol(col[j]);
        }
        restoreCol(c);  //恢复第c列
        return false;
    }

    int solve(char sud[][18])
    {
        init(16 * 16 + (3 * 16) * 16);  //16*16的九宫格每个格子只能填一个字母 + 16行16列16个4*4方格每一种都限制只能有1个A~P的字母
        for(int i = 0; i < 16; i++)
        {
            for(int j = 0; j < 16; j++)
            {
                if(sud[i][j] != '-')   //该格子已经填了字母
                {
                    int num = sud[i][j] - 'A' + 1;
                    vector<int> v;
                    v.PB(i * 16 + j + 1);    //第i行第j列只能填一个字母
                    v.PB(16 * 16 + i * 16 + num);  //第i行已经填了字母num
                    v.PB(16 * 16 * 2 + j * 16 + num);  //第j行已经填了字母num
                    v.PB(16 * 16 * 3 + (i / 4 * 4 + j / 4) * 16 + num);  //第(i/3*3+j/3)个3*3的格子已经填了字母num
                    addRow(16 * 16 * i + 16 * j + num, v);
                }
                else    //该格子未填字母
                {
                    for(int num = 1; num <= 16; num++)
                    {
                        vector<int> v;
                        v.PB(i * 16 + j + 1);    //第i行第j列只能填一个字母
                        v.PB(16 * 16 + i * 16 + num);  //第i行已经填了字母num
                        v.PB(16 * 16 * 2 + j * 16 + num);  //第j行已经填了字母num
                        v.PB(16 * 16 * 3 + (i / 4 * 4 + j / 4) * 16 + num);  //第(i/3*3+j/3)个3*3的格子已经填了字母num
                        addRow(16 * 16 * i + 16 * j + num, v);
                    }
                }
            }
        }
        dfs(0);
        //cout << ansd << endl;
        for(int i = 0; i < ansd; i++)
        {
            int tmp = ans[i];
            tmp--;
            char val = tmp % 16 + 'A';
            tmp /= 16;
            int c = tmp % 16;
            tmp /= 16;
            int r = tmp;
            sud[r][c] = val;
        }
        for(int i = 0; i < 16; i++)
            printf("%s\n", sud[i]);
        puts("");
    }
} dlx;

int main()
{
    char str[18][18];
    while(~scanf("%s", str[0]))
    {
        for(int i = 1; i < 16; i++)
            scanf("%s", str[i]);
        dlx.solve(str);
    }
    return 0;
}
