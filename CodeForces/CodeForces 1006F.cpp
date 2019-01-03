/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2019-01-02
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: CodeForces
 *  Algorithm: 双向BFS
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
#define MAXN 25

int n,m;
LL g[MAXN][MAXN];
int dx1[] = {0,1};
int dy1[] = {1,0};
int dx2[] = {-1,0};
int dy2[] = {0,-1};
LL ans;
struct Node
{
    int x,y;
    LL val;
    Node() {}
    Node(int x,int y,LL val):x(x),y(y),val(val) {}
    bool operator <(const Node &nd) const
    {
        if(x == nd.x)
        {
            if(y == nd.y)
                return val < nd.val;
            return y < nd.y;
        }
        return x < nd.x;
    }
};

map<Node,LL> mp;

bool inMap(Node tmp)
{
    if(tmp.x > 0 && tmp.x <= n && tmp.y > 0 && tmp.y <= m)
        return true;
    return false;
}

void bfs1(Node st)
{
    queue<Node> q;
    q.push(st);
    while(!q.empty())
    {
        Node tmp = q.front();
        q.pop();
        if(tmp.x + tmp.y == (n + m) / 2 + 1)
        {
            mp[tmp]++;
            continue;
        }
        for(int i = 0; i < 2; i++)
        {
            Node nxt;
            nxt.x = tmp.x + dx1[i];
            nxt.y = tmp.y + dy1[i];
            if(inMap(nxt))
            {
                nxt.val = tmp.val ^ g[nxt.x][nxt.y];
                q.push(nxt);
            }
        }
    }
}

void bfs2(Node st)
{
    queue<Node> q;
    q.push(st);
    while(!q.empty())
    {
        Node tmp = q.front();
        q.pop();
        if(tmp.x + tmp.y == (n + m) / 2 + 1)
        {
            tmp.val ^= g[tmp.x][tmp.y]; //多异或了一次g[tmp.x][tmp.y]，再次异或以抵消
            ans += mp[tmp];
            continue;
        }
        for(int i = 0; i < 2; i++)
        {
            Node nxt;
            nxt.x = tmp.x + dx2[i];
            nxt.y = tmp.y + dy2[i];
            if(inMap(nxt))
            {
                nxt.val = tmp.val ^ g[nxt.x][nxt.y];
                q.push(nxt);
            }
        }
    }
}

int main()
{
    LL k;
    scanf("%d%d%I64d",&n,&m,&k);
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
            scanf("%I64d",&g[i][j]);
    }
    bfs1(Node(1,1,g[1][1]));
    bfs2(Node(n,m,k^g[n][m]));
    printf("%I64d\n",ans);
    return 0;
}
