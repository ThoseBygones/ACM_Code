/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2019-03-21
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: LightOJ
 *  Algorithm: BFS
 ********************************************************************************
 *  Algo-Description:
 ********************************************************************************
 */

//#include <bits/stdc++.h>  //For CodeForces only

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
#define MAXN 505

struct Node
{
    int x,y;
    Node() {}
    Node(int x,int y):x(x),y(y) {}
};

char mp[MAXN][MAXN];
int vis[MAXN][MAXN];
int dx[] = {-1,0,0,1};
int dy[] = {0,-1,1,0};
int rec[1005];    //记录每个落点所在连通块的答案
int ans[1005];
int n,m,q;

bool inMap(int x,int y)
{
    if(x>=0 && x<n && y>=0 && y<m)
        return true;
    return false;
}

int bfs(int x,int y,int flag)
{
    int cnt = 0;
    queue<Node> que;
    que.push(Node(x,y));
    vis[x][y] = flag;
    while(!que.empty())
    {
        Node tmp = que.front();
        que.pop();
        if(mp[tmp.x][tmp.y] == 'C')
            cnt++;
        for(int i=0; i<4; i++)
        {
            int nx = tmp.x + dx[i];
            int ny = tmp.y + dy[i];
            if(inMap(nx,ny) && !vis[nx][ny] && mp[nx][ny] != '#')
            {
                vis[nx][ny] = flag;
                que.push(Node(nx,ny));
            }
        }
    }
    return cnt;
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int kase=1; kase<=t; kase++)
    {
        scanf("%d%d%d",&n,&m,&q);
        for(int i=0; i<n; i++)
            scanf("%s",mp[i]);
        memset(vis,0,sizeof(vis));
        memset(rec,-1,sizeof(rec));
        for(int i=1; i<=q; i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            if(!vis[x-1][y-1])
            {
                rec[i] = bfs(x-1,y-1,i);
                ans[i] = rec[i];
            }
            else
                ans[i] = rec[vis[x-1][y-1]];
        }
        printf("Case %d:\n",kase);
        for(int i=1; i<=q; i++)
            printf("%d\n",ans[i]);
    }
    return 0;
}

/*
2
4 5 2
..#..
.C#C.
##..#
..C#C
1 1
4 1
4 5 4
..#..
.C#C.
##..#
..C#C
1 1
4 1
4 1
1 1
*/
