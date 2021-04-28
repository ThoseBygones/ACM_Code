/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-04-28
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm: 思维
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

const int MAXN = 1005;

char a[MAXN][MAXN], b[MAXN][MAXN];
int mat[MAXN][MAXN];

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
        {
            scanf("%s", a[i]);
            for(int j = 0; j < n; j++)
                mat[i][j] = a[i][j] - '0';
        }
        for(int i = 0; i < n; i++)
        {
            scanf("%s", b[i]);
            for(int j = 0; j < n; j++)
                mat[i][j] ^= b[i][j] - '0';
        }
        for(int i = 0; i < n; i++)  //固定第一列
        {
            if(mat[i][0])   //如果该列第一个元素为1，则翻转该行
            {
                for(int j = 0; j < n; j++)
                    mat[i][j] ^= 1;
            }
        }
        bool flag = true;
        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(mat[i][j] != mat[0][j])  //判断每行是否完全相同，即每列元素自己是否一致
                {
                    flag = false;
                    break;
                }
            }
        }
        puts(flag ? "YES" : "NO");
    }
    return 0;
}
