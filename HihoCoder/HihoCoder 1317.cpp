/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-01-28
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: HihoCoder
 *  Algorithm: DLX��ȷ����
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

const int MAXN = 105;
const int MAXM = 105;
const int MAXNODE = 10005;
//�б�Ŵ�1��ʼ���б��Ϊ1~n�����0�Ǳ�ͷ���; ���1~n�Ǹ��ж�����������

class DLX
{
public:
    int m, sz;  //�����������
    int nds[MAXN];  //ÿ�н����

    int row[MAXNODE], col[MAXNODE]; //row/col����������¼ĳ����ŵĽ���ھ����е��кź��к�
    int L[MAXNODE], R[MAXNODE], U[MAXNODE], D[MAXNODE]; //U/D/R/L����������¼ĳ����ŵĽ����������ҽ��ı�ţ�ʮ������

    int ansd, ans[MAXM];    //��������ͽ�

    void init(int m)    //mΪ����
    {
        this -> m = m;
        //������
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

    //ɾ����
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

    //�ָ���
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


    int ret;
    int vis[MAXN];

    bool dfs(int d)
    {
        if(R[0] == 0)
        {
            ansd = d;
            return true;
        }
        //��S��С������ɾ������
        int c = R[0];
        for(int i = R[0]; i != 0; i = R[i])
        {
            if(nds[i] < nds[c])
                c = i;
        }
        removeCol(c);
        for(int i = D[c]; i != c; i = D[i])
        {
            for(int j = R[i]; j != i; j = R[j])
                removeCol(col[j]);
            if(dfs(d + 1))
                return true;
            for(int j = L[i]; j != i; j = L[j])
                restoreCol(col[j]);
        }
        restoreCol(c);
        return false;
    }

    void solve(int n, int m)
    {
        init(m);
        for(int i = 0; i < n; i++)
        {
            vector<int> v;
            for(int j = 0; j < m; j++)
            {
                int x;
                scanf("%d", &x);
                if(x)
                    v.PB(j + 1);
            }
            addRow(i, v);
        }
        puts(dfs(0) ? "Yes": "No");
    }
} dlx;

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        dlx.solve(n, m);
    }
    return 0;
}
