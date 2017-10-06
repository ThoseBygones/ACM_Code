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
#define MAXN 255
using namespace std;

struct Source
{
    int x,y,val;
};

vector <Source> ns;
char mp[MAXN][MAXN];
int vis[MAXN][MAXN];
LL sum[MAXN][MAXN];
int dx[]={-1,0,0,1};
int dy[]={0,-1,1,0};
int n,m,q,p;

bool inMap(int x,int y)
{
    if(x>=0 && x<n && y>=0 && y<m)
        return true;
    return false;
}

void bfs(Source ss)
{
    Source now,next;
    queue <Source> Q;
    now=ss;
    Q.push(now);
    vis[now.x][now.y]=1;
    while(!Q.empty())
    {
        now=Q.front();
        sum[now.x][now.y]+=now.val;
        Q.pop();
        for(int i=0; i<4; i++)
        {
            next.x=now.x+dx[i];
            next.y=now.y+dy[i];
            next.val=now.val/2;
            if(next.val==0)
                break;
            if(inMap(next.x,next.y) && !vis[next.x][next.y] && mp[next.x][next.y]!='*')
            {
                vis[next.x][next.y]=1;
                Q.push(next);
            }
        }
    }
}

int main()
{
    scanf("%d%d%d%d",&n,&m,&q,&p);
    for(int i=0; i<n; i++)
    {
        scanf("%s",mp[i]);
        for(int j=0; j<m; j++)
        {
            if(mp[i][j]>='A' && mp[i][j]<='Z')
            {
                Source temp;
                temp.x=i;
                temp.y=j;
                temp.val=q*(mp[i][j]-'A'+1);
                ns.PB(temp);
            }
        }
    }
    for(int i=0; i<ns.size(); i++)
    {
        memset(vis,0,sizeof(vis));
        bfs(ns[i]);
    }
    int cnt=0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(sum[i][j]>p)
                cnt++;
        }
    }
    printf("%d\n",cnt);
    return 0;
}
