/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2022-05-14
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm: 博弈 + 规律
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

int a[MAXN], pre[MAXN], suf[MAXN];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for(int i = 1; i <= n; i++)
    {
        if(a[i] > a[i - 1])
            pre[i] = pre[i - 1] + 1;
        else
            pre[i] = 1;
    }
    for(int i = n; i; i--)
    {
        if(a[i] > a[i + 1])
            suf[i] = suf[i + 1] + 1;
        else
            suf[i] = 1;
    }
    int max_len = 0, max_cnt = 0;   //最长上升/下降子串长度、最长上升/下降子串数量
    bool flag = false;
    for(int i = 1; i <= n; i++)
        max_len = max(max(max_len, pre[i]), suf[i]);
    int pos = 0;
    for(int i = 1; i <= n; i++)
    {
        if(pre[i] == max_len)
            max_cnt++;
        if(suf[i] == max_len)
            max_cnt++;
        if(pre[i] == max_len && suf[i] == max_len)  //存在正好两条最长上升/下降子串起点相同
            flag = true;
    }
    if(flag && max_cnt == 2)
        printf("%d\n", max_len & 1);    //最长上升/下降子串长度为奇数是才能保证必胜，有且仅有一个位置能获胜
    else
        puts("0");
    return 0;
}
