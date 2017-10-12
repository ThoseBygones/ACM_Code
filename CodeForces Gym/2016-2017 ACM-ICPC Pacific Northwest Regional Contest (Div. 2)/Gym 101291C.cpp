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
#define MAXN 55
using namespace std;

struct Node
{
    int x,y;
    int step;
    int t;  //修改次数
    Node(){}
    Node(int x,int y,int step,int t):x(x),y(y),step(step),t(t){}
    bool operator <(const Node& a) const
    {
        if(t==a.t)
            return step>a.step;
        return t>a.t;
    }
};

char mp[MAXN][MAXN];
char order[MAXN];
int dp[MAXN][MAXN][MAXN];   //记忆化搜索
int dx[]={0,-1,0,1};
int dy[]={-1,0,1,0};    //左上右下
int n,m;
int sx,sy,ex,ey;
int len;
priority_queue <Node> pq;

int getDir(char ch)
{
    if(ch=='L')
        return 0;
    if(ch=='U')
        return 1;
    if(ch=='R')
        return 2;
    if(ch=='D')
        return 3;
}

bool inMap(int x,int y)
{
    if(x>=0 && x<n && y>=0 && y<m)
        return true;
    return false;
}

void bfs()
{
    Node now,next;
    now=Node(sx,sy,0,0);
    pq.push(now);
    while(!pq.empty())
    {
        now=pq.top();
        pq.pop();
        if(now.t<dp[now.step][now.x][now.y])
            dp[now.step][now.x][now.y]=now.t;
        else    //剪枝，当前方案需要修改的次数不比之前少，根本就不必要搜下去了
            continue;
        if(now.step<len)
        {
            int cnt=getDir(order[now.step]);
            next=Node(now.x+dx[cnt],now.y+dy[cnt],now.step+1,now.t);
            if(inMap(next.x,next.y) && mp[next.x][next.y]!='#')
                pq.push(next);
            else    //无法前进
            {
                next=Node(now.x,now.y,now.step+1,now.t);
                pq.push(next);
            }
            next=Node(now.x,now.y,now.step+1,now.t+1);  //删掉当前指令
            if(inMap(next.x,next.y) && mp[next.x][next.y]!='#')
                pq.push(next);
        }
        for(int i=0; i<4; i++)
        {
            next=Node(now.x+dx[i],now.y+dy[i],now.step,now.t+1);    //添加指令
            if(inMap(next.x,next.y) && mp[next.x][next.y]!='#')
                pq.push(next);
        }
    }
}

int main()
{
    scanf("%d%d",&n,&m);
    //memset(dp,0x3f,sizeof(dp));
    /*
    for(int i=0; i<MAXN; i++)
    {
        for(int j=0; j<MAXN; j++)
        {
            for(int k=0; k<MAXN; k++)
                dp[i][j][k]=INF;
        }
    }
    */
    for(int i=0; i<n; i++)
        scanf("%s",mp[i]);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(mp[i][j]=='R')
            {
                sx=i;
                sy=j;
            }
            if(mp[i][j]=='E')
            {
                ex=i;
                ey=j;
            }
        }
    }
    scanf("%s",order);
    len=strlen(order);
    for(int i=0; i<=len; i++)
    {
        for(int j=0; j<n; j++)
        {
            for(int k=0; k<m; k++)
                dp[i][j][k]=INF;
        }
    }
    int ans=INF;
    bfs();
    /*for(int i=0; i<=len; i++)
    {
        for(int j=0; j<=len; j++)
        {
            for(int k=0; k<=len; k++)
                printf("%d ",dp[i][j][k]);
            puts("");
        }
        cout << endl << endl;
    }*/
    for(int i=0; i<=len; i++)
        ans=min(ans,dp[i][ex][ey]);
    printf("%d\n",ans);
    return 0;
}
