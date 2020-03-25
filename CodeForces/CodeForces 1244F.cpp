/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-03-23
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: CodeForces
 *  Algorithm:
 ********************************************************************************
 *  Algo-Description:
 ********************************************************************************
 */

#include <bits/stdc++.h>  //For CodeForces only
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
#define clr(ar,val) memset(ar, val, sizeof(ar))
#define istr stringstream
#define FOR(i,n) for(int i=0;i<(n);++i)
#define forIt(mp,it) for(__typeof(mp.begin()) it = mp.begin();it!=mp.end();it++)
const double EPS = 1e-6;
const int INF = 0x3fffffff;
const LL LINF = INF * 1ll * INF;
const double PI = acos(-1.0);

#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define lowbit(u) (u&(-u))
#define MAXN 200005

struct Segment
{
    int l, r, c;    //段的左端点、右端点和颜色
    Segment() {}
    Segment(int l, int r, int c) : l(l), r(r), c(c) {}
};

vector<Segment> seg;
char s[MAXN];
int col[MAXN*3];    //3倍大小以处理环

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    scanf("%s", s + 1);
    for(int i = 1; i <= n; i++)
        col[i] = col[i+n] = col[i+2*n] = (s[i] == 'B' ? 1 : 0);
    col[3*n+1] = (col[3*n] ^ 1);
    int l = 1;
    for(int r = 2; r <= 3 * n + 1; r++)
    {
        if(col[r] != col[l])    //上一段结束
        {
            if(r - l > 1)   //上一段的长度大于1
                seg.PB(Segment(l, r - 1, col[l]));
            l = r;
        }
    }
    for(int i = 1; i < seg.size(); i++) //处理两个段之间的颜色变化
    {
        int l = seg[i-1].r + 1, r = seg[i].l - 1;   //可变色区间的左端和右端
        if(l <= r)  //两个段之间有可变色区间
        {
            //printf("%d - %d\n", l, r);
            int lcol = col[l-1], rcol = col[r+1];   //该区间两侧连续段的颜色
            int len = r - l + 1;    //可变色区间的长度
            if(len <= 2 * k)    //若k次变化后全区间都会变色
            {
                if(lcol == rcol)    //该区间两侧连续段的颜色相同
                {
                    for(int j = l; j <= r; j++)
                        col[j] = lcol;
                }
                else    //颜色不同（此时len必定为2的倍数）
                {
                    for(int j = l; j < l + len / 2; j++)
                        col[j] = lcol;
                    for(int j = l + len / 2; j <= r; j++)
                        col[j] = rcol;
                }
            }
            else    //若k次变化后区间只有部分变色
            {
                for(int j = l; j < l + k; j++)
                    col[j] = lcol;
                for(int j = r - k + 1; j <= r; j++)
                    col[j] = rcol;
                for(int j = l + k; j <= r - k; j++)
                    col[j] = col[j-1] ^ 1;  //与前一种颜色不同
            }
        }
    }
    if((seg.size() == 0) && (k & 1))    //黑白相间且变化次数k为奇数时
    {
        for(int i = n + 1; i <= 2 * n; i++) //全部变成对立的颜色即可
            col[i] = col[i-1] ^ 1;
    }
    for(int i = n + 1; i <= 2 * n; i++) //答案输出中间的部分即可
        printf("%c", (col[i] ? 'B' : 'W'));
    puts("");
    return 0;
}
