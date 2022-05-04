/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2022-04-07
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: HDU
 *  Algorithm: 双向BFS
 ********************************************************************************
 *  Algo-Description:
 ********************************************************************************
 */

#include <bits/stdc++.h>
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
const double EPS = 1e-6;
const int INF = 0x3fffffff;
const LL LINF = INF * 1ll * INF;
const double PI = acos(-1.0);

#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define lowbit(u) (u&(-u))

const int MAXN = 805;
const int dx[4] = {-1, 0, 0, 1};
const int dy[4] = {0, -1, 1, 0};

struct Node
{
    int x, y;
    Node() {}
    Node(int x, int y) : x(x), y(y) {}
} g[2];

queue<Node> q[2];
char ma[MAXN][MAXN];
int n, m;

void init()
{
    for(int i = 0; i < 2; i++)
    {
        while(!q[i].empty())
            q[i].pop();
    }
}

bool check(int x, int y, int step, char c)
{
    if(x < 0 || x >= n || y < 0 || y >= m)
        return false;
    for(int i = 0; i < 2; i++)
    {
        if(abs(x - g[i].x) + abs(y - g[i].y) <= 2 * step)
            return false;
    }
    return true;
}

bool bfs(int k, int cnt, char st, char ed, int step)
{
    queue<Node> tq = q[k];
    for(int i = 0; i < cnt; i++)
    {
        while(!tq.empty())
        {
            Node cur = tq.front();
            tq.pop();
            q[k].pop();
            if(!check(cur.x, cur.y, step, ed))
                continue;
            for(int j = 0; j < 4; j++)
            {
                int nx = cur.x + dx[j];
                int ny = cur.y + dy[j];
                if(!check(nx, ny, step, ed) || ma[nx][ny] == 'X' || ma[nx][ny] == st)
                    continue;
                if(ma[nx][ny] == ed)
                    return true;
                ma[nx][ny] = st;
                //printf("%c - %d: (%d, %d)\n", st, step, nx, ny);
                q[k].push(Node(nx, ny));
            }
        }
        tq = q[k];
    }
    return false;
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        init();
        scanf("%d%d", &n, &m);
        int gcnt = 0;
        for(int i = 0; i < n; i++)
        {
            scanf("%s", ma[i]);
            for(int j = 0; j < m; j++)
            {
                if(ma[i][j] == 'M')
                    q[0].push(Node(i, j));
                else if(ma[i][j] == 'G')
                    q[1].push(Node(i, j));
                else if(ma[i][j] == 'Z')
                    g[gcnt++] = Node(i, j);
            }
        }
        bool flag = false;
        int ans = 0;
        while(!q[0].empty() && !q[1].empty())
        {
            ans++;
            if(bfs(0, 3, 'M', 'G', ans) || bfs(1, 1, 'G', 'M', ans))
            {
                flag = true;
                break;
            }
        }
        if(flag)
            printf("%d\n", ans);
        else
            puts("-1");
    }
    return 0;
}
