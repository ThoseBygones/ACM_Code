/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2022-05-05
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: HDU
 *  Algorithm: IDA* 算法
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

const int MAXN = 400005;
const int dx[4] = {1, 0, 0, -1};
const int dy[4] = {0, -1, 1, 0};
const char dc[] = "dlru";

char s[10], ans[MAXN];
int a[9], b[9], mp[9];  //初始状态，目标状态，位置映射
int dep, min_dep;   //当前限制搜索深度，上次失败搜索深度

int h() //启发函数（曼哈顿距离）
{
    int val = 0;
    for(int i = 0; i < 9; i++)
    {
        if(a[i])
            val += abs(i / 3 - mp[a[i]] / 3) + abs(i % 3 - mp[a[i]] % 3);
    }
    return val;
}

bool dfs(int pos, int d, int pre)
{
    int e = h();    //估计深度
    if(!e)  //已经达到目标状态
    {
        printf("%d\n", d);
        ans[d] = '\0';
        printf("%s\n", ans);
        return true;
    }
    if(d + e > dep) //超过限制深度，更新失败的最小深度
    {
        min_dep = min(min_dep, d + e);
        return false;
    }
    for(int i = 0; i < 4; i++)
    {
        int nx = pos / 3 + dx[i];
        int ny = pos % 3 + dy[i];
        int np = nx * 3 + ny;
        if(nx < 0 || nx > 2 || ny < 0 || ny > 2 || np == pre)
            continue;
        swap(a[pos], a[np]);
        ans[d] = dc[i];
        if(dfs(np, d + 1, pos))
            return true;
        swap(a[pos], a[np]);    //还原现场
    }
    return false;
}

void IDA_star(int pos)
{
    dep = h();  //初始限制深度为估计函数值
    while(true)
    {
        min_dep = INF;
        if(dfs(pos, 0, -1)) //搜索到目标状态则结束
            break;
        dep = min_dep;  //当前限制深度搜索失败则更新搜索限制深度为上次失败的最小深度
    }
}

int main()
{
    int t, kase = 1;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%s", s);
        int pos;
        for(int i = 0; i < 9; i++)
        {
            if(s[i] == 'X')
            {
                pos = i;
                a[i] = 0;
            }
            else
                a[i] = s[i] - '0';
        }
        scanf("%s", s);
        for(int i = 0; i < 9; i++)
        {
            if(s[i] == 'X')
                b[i] = 0;
            else
                b[i] = s[i] - '0';
            mp[b[i]] = i;
        }
        printf("Case %d: ", kase++);
        IDA_star(pos);
    }
    return 0;
}
