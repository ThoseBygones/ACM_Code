/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2019-01-15
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
#define MAXN 1005

struct Star
{
    int x,y,dep;
    Star() {}
    Star(int x,int y,int dep):x(x),y(y),dep(dep) {}
};

char g[MAXN][MAXN];
int vis[MAXN][MAXN];
int n,m;
vector<Star> ans;

bool check(int x,int y,int dep)
{
    if(x - dep < 0 || x + dep >= n || y - dep < 0 || y + dep >= m)  //坐标超出图的范围
        return false;
    if(g[x-dep][y] == '*' && g[x+dep][y] == '*' && g[x][y-dep] == '*' && g[x][y+dep] == '*')
    {
        vis[x-dep][y] = 1;
        vis[x+dep][y] = 1;
        vis[x][y-dep] = 1;
        vis[x][y+dep] = 1;
        return true;
    }
    return false;
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0; i<n; i++)
        scanf("%s",g[i]);
    bool star = false;  //图中是否有星号
    for(int i=1; i<n-1; i++)
    {
        for(int j=1; j<m-1; j++)
        {
            int dep = 0;
            if(g[i][j]=='*')
            {
                star = true;
                bool flag = false;  //是否在该坐标画星星
                while(check(i,j,dep+1))
                {
                    flag = true;
                    vis[i][j] = 1;
                    dep++;
                }
                if(flag)
                    ans.PB(Star(i+1,j+1,dep));
            }
        }
    }
    if(ans.size() == 0 && star)    //画不出星星，但是图中有星号
    {
        puts("-1");
        return 0;
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(g[i][j] == '*' && !vis[i][j])    //有星号的地方没有被画出的星星覆盖
            {
                puts("-1");
                return 0;
            }
        }
    }
    int sz = ans.size();
    printf("%d\n",sz);
    if(sz)
    {
        for(int i=0; i<sz; i++)
            printf("%d %d %d\n",ans[i].x,ans[i].y,ans[i].dep);
    }
    return 0;
}
