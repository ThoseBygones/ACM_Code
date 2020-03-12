/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-03-12
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: CodeForces
 *  Algorithm: dp + BFS
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
#define MAXN 205

struct Node
{
    int i, j, k;
    char c;
    Node() {}
    Node(int i, int j, int k, char c) : i(i), j(j), k(k), c(c) {}
} pre[MAXN][MAXN][MAXN];    //记录路径

vector<char> ans;
char s[MAXN], t[MAXN];
int dp[MAXN][MAXN][MAXN];   //dp[i][j][k]表示第一个串匹配到位置i，第二个串匹配到位置j时，生成的括号序列中左括号比右括号多k个
int len1, len2;

void bfs()
{
    memset(dp, -1, sizeof(dp));
    queue<Node> q;
    q.push(Node(0,0,0,' '));
    dp[0][0][0] = 0;
    while(!q.empty())
    {
        Node cur = q.front();
        q.pop();
        //当前匹配的是左括号
        int ni = cur.i + (cur.i + 1 <= len1 && s[cur.i+1] == '(');
        int nj = cur.j + (cur.j + 1 <= len2 && t[cur.j+1] == '(');
        int nk = cur.k + 1;
        if(nk <= 200 && dp[ni][nj][nk] == -1)
        {
            dp[ni][nj][nk] = dp[cur.i][cur.j][cur.k] + 1;
            pre[ni][nj][nk] = Node(cur.i, cur.j, cur.k, '(');
            q.push(Node(ni, nj, nk, ' '));
        }
        //当前匹配的是右括号
        ni = cur.i + (cur.i + 1 <= len1 && s[cur.i+1] == ')');
        nj = cur.j + (cur.j + 1 <= len2 && t[cur.j+1] == ')');
        nk = cur.k - 1;
        if(nk >= 0 && dp[ni][nj][nk] == -1)
        {
            dp[ni][nj][nk] = dp[cur.i][cur.j][cur.k] + 1;
            pre[ni][nj][nk] = Node(cur.i, cur.j, cur.k, ')');
            q.push(Node(ni, nj, nk, ' '));
        }
    }
}

int main()
{
    scanf("%s%s", s + 1, t + 1);
    len1 = strlen(s + 1);
    len2 = strlen(t + 1);
    bfs();
    Node tmp = pre[len1][len2][0];
    ans.PB(tmp.c);
    while(tmp.i || tmp.j || tmp.k)
    {
        //cout << tmp.c << endl;
        tmp = pre[tmp.i][tmp.j][tmp.k];
        ans.PB(tmp.c);
    }
    reverse(ans.begin(), ans.end());
    for(auto c: ans)
        printf("%c", c);
    puts("");
    return 0;
}
