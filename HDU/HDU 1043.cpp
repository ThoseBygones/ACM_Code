/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2022-05-02
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: HDU
 *  Algorithm: A* or IDA* or 打表 + 康托展开
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


/** 方法一：A*算法 + 康托展开（842ms，6844kB） **/

const int MAXN = 362880 + 5;    //9! = 362880
const int dx[4] = {-1, 0, 0, 1};
const int dy[4] = {0, -1, 1, 0};
const char dc[] = "ulrd";

struct Node
{
    int d, h;   //d为当前距离，h为估计函数h(x)
    int pos;    //'x'（空格）的位置
    int a[9];   //数码状态
    bool operator < (const Node &nd) const
    {
        return d + h > nd.d + nd.h;
    }
};

int fac[10];
char s[2], ans[MAXN];
int vis[MAXN], pre[MAXN];   //记录路径

bool check(Node nd) //判断是否有解
{
    int rev_cnt = 0;    //逆序对数量
    for(int i = 0; i < 9; i++)
    {
        if(nd.a[i] != 8)
        {
            for(int j = i + 1; j < 9; j++)
            {
                if(nd.a[i] > nd.a[j])
                    rev_cnt++;
            }
        }
    }
    if(rev_cnt & 1)
        return false;
    return true;
}

void init()
{
    fac[0] = 1;
    for(int i = 1; i < 9; i++)
        fac[i] = fac[i - 1] * i;
}

int Cantor(Node nd)    //康托展开
{
    int val = 0;
    for(int i = 0; i < 9; i++)
    {
        int rev_cnt = 0;    //有多少个比当前数字小的数字出现在其后（逆序对数量）
        for(int j = i + 1; j < 9; j++)
        {
            if(nd.a[i] > nd.a[j])
                rev_cnt++;
        }
        val += fac[9 - i - 1] * rev_cnt;
    }
    return val;
}

int h(Node nd)  //计算估值函数h(x)，采用曼哈顿距离
{
    int val = 0;
    for(int i = 0; i < 9; i++)
    {
        if(nd.a[i] != 8)    //字母'x'不参与计算，因为其它数字都落位时，字母'x'自然也落位
            val += abs(i / 3 - nd.a[i] / 3) + abs(i % 3 - nd.a[i] % 3);
    }
    return val;
}

void A_star(Node &st)   //A*算法
{
    memset(vis, false, sizeof(vis));
    priority_queue<Node> pq;
    st.d = 0, st.h = h(st);
    vis[Cantor(st)] = true;
    pq.push(st);
    while(!pq.empty())
    {
        Node cur = pq.top();
        pq.pop();
        for(int i = 0; i < 4; i++)
        {
            Node nxt = cur;
            int nx = cur.pos / 3 + dx[i];
            int ny = cur.pos % 3 + dy[i];
            int np = nx * 3 + ny;
            if(nx < 0 || nx > 2 || ny < 0 || ny > 2)
                continue;
            swap(nxt.a[np], nxt.a[cur.pos]);
            nxt.pos = np, nxt.d++, nxt.h = h(nxt);
            int hash_next = Cantor(nxt);
            if(vis[hash_next])  //下一个状态已经出现过
                continue;
            vis[hash_next] = true;
            pq.push(nxt);
            pre[hash_next] = Cantor(cur);
            ans[hash_next] = dc[i];
            if(hash_next == 0)  //得到最终状态
                return ;
        }
    }
}

int main()
{
    //puts("GO");
    init();
    //printf("initialized!\n");
    while(~scanf("%s", s))
    {
        Node st;
        if(s[0] == 'x')
        {
            st.pos = 0;
            st.a[0] = 8;
        }
        else if(s[0] >= '1' && s[0] <= '8')
            st.a[0] = s[0] - '0' - 1;
        for(int i = 1; i < 9; i++)
        {
            scanf("%s", s);
            if(s[0] == 'x')
            {
                st.pos = i;
                st.a[i] = 8;
            }
            else if(s[0] >= '1' && s[0] <= '8')
                st.a[i] = s[0] - '0' - 1;
        }
        if(!check(st))
        {
            puts("unsolvable");
            continue;
        }
        A_star(st);
        //回溯路径
        int cur = 0, val = Cantor(st);
        stack<char> sta;
        while(cur != val)
        {
            sta.push(ans[cur]);
            cur = pre[cur];
        }
        while(!sta.empty())
        {
            printf("%c", sta.top());
            sta.pop();
        }
        puts("");
    }
    return 0;
}


/** 方法二：IDA*算法（124ms, 1384kB） **/

const int MAXN = 362880 + 5;    //9! = 362880
const int dx[4] = {-1, 0, 0, 1};
const int dy[4] = {0, -1, 1, 0};
const char dc[] = "ulrd";

int a[9];
char s[2], ans[MAXN];
int dep, min_dep;

bool check() //判断是否有解
{
    int rev_cnt = 0;    //逆序对数量
    for(int i = 0; i < 9; i++)
    {
        if(a[i] != 8)
        {
            for(int j = i + 1; j < 9; j++)
            {
                if(a[i] > a[j])
                    rev_cnt++;
            }
        }
    }
    if(rev_cnt & 1)
        return false;
    return true;
}

int h()  //计算估值函数h(x)，采用曼哈顿距离
{
    int val = 0;
    for(int i = 0; i < 9; i++)
    {
        if(a[i] != 8)    //字母'x'不参与计算，因为其它数字都落位时，字母'x'自然也落位
            val += abs(i / 3 - a[i] / 3) + abs(i % 3 - a[i] % 3);
    }
    return val;
}

bool dfs(int pos, int d, int pre)
{
    int e = h();
    if(e == 0)  //已经是目标状态
    {
        ans[d] = '\0';
        return true;
    }
    if(d + e > dep) //超出了限制的搜索深度
    {
        min_dep = min(min_dep, d + e);  //更新搜索失败的最小深度
        return false;
    }
    for(int i = 0; i < 4; i++)
    {
        int nx = pos / 3 + dx[i];
        int ny = pos % 3 + dy[i];
        int np = nx * 3 + ny;
        if(nx < 0 || nx > 2 || ny < 0 || ny > 2 || np == pre)
            continue;
        swap(a[np], a[pos]);
        ans[d] = dc[i];
        if(dfs(np, d + 1, pos))  //得到最终状态
            return true;
        swap(a[np], a[pos]);    //还原现场
    }
    return false;
}

void IDA_star(int x)
{
    dep = h();  //初始极限搜索深度为dep
    while(true)
    {
        min_dep = INF;
        if(dfs(x, 0, -1))
            break;
        dep = min_dep;  //没有搜索到结果，则从上次搜索失败的最小深度开始搜索
    }
}

int main()
{
    int pos;
    while(~scanf("%s", s))
    {
        if(s[0] == 'x')
        {
            pos = 0;
            a[0] = 8;
        }
        else if(s[0] >= '1' && s[0] <= '8')
            a[0] = s[0] - '0' - 1;
        for(int i = 1; i < 9; i++)
        {
            scanf("%s", s);
            if(s[0] == 'x')
            {
                pos = i;
                a[i] = 8;
            }
            else if(s[0] >= '1' && s[0] <= '8')
                a[i] = s[0] - '0' - 1;
        }
        if(!check())
        {
            puts("unsolvable");
            continue;
        }
        IDA_star(pos);
        printf("%s\n", ans);
    }
    return 0;
}


/** 方法三：打表 + BFS + 康托展开（93ms，5572kB） **/

const int MAXN = 362880 + 5;    //9! = 362880
const int dx[4] = {-1, 0, 0, 1};
const int dy[4] = {0, -1, 1, 0};
const char dc[] = "drlu";   //逆向推，方向相反

struct Node
{
    int pos;    //'x'（空格）的位置
    int a[9];   //数码状态
};

int fac[10];
char s[2], ans[MAXN];
int vis[MAXN], pre[MAXN];   //记录路径

bool check(Node nd) //判断是否有解
{
    int rev_cnt = 0;    //逆序对数量
    for(int i = 0; i < 9; i++)
    {
        if(nd.a[i] != 8)
        {
            for(int j = i + 1; j < 9; j++)
            {
                if(nd.a[i] > nd.a[j])
                    rev_cnt++;
            }
        }
    }
    if(rev_cnt & 1)
        return false;
    return true;
}

void init()
{
    fac[0] = 1;
    for(int i = 1; i < 9; i++)
        fac[i] = fac[i - 1] * i;
}

int Cantor(Node nd)    //康托展开
{
    int val = 0;
    for(int i = 0; i < 9; i++)
    {
        int rev_cnt = 0;    //有多少个比当前数字小的数字出现在其后（逆序对数量）
        for(int j = i + 1; j < 9; j++)
        {
            if(nd.a[i] > nd.a[j])
                rev_cnt++;
        }
        val += fac[9 - i - 1] * rev_cnt;
    }
    return val;
}

void bfs()  //BFS搜索所有状态（从最终目标状态开始反向搜索）
{
    memset(vis, false, sizeof(vis));
    queue<Node> q;
    Node tmp;
    for(int i = 0; i < 9; i++)
        tmp.a[i] = i;
    tmp.pos = 8;
    vis[Cantor(tmp)] = true;
    q.push(tmp);
    while(!q.empty())
    {
        Node cur = q.front();
        q.pop();
        for(int i = 0; i < 4; i++)
        {
            Node nxt = cur;
            int nx = cur.pos / 3 + dx[i];
            int ny = cur.pos % 3 + dy[i];
            int np = nx * 3 + ny;
            if(nx < 0 || nx > 2 || ny < 0 || ny > 2)
                continue;
            swap(nxt.a[np], nxt.a[cur.pos]);
            nxt.pos = np;
            int hash_next = Cantor(nxt);
            if(vis[hash_next])  //下一个状态已经出现过
                continue;
            vis[hash_next] = true;
            q.push(nxt);
            pre[hash_next] = Cantor(cur);
            ans[hash_next] = dc[i];
        }
    }
}

int main()
{
    init();
    bfs();  //打表枚举所有状态
    while(~scanf("%s", s))
    {
        Node st;
        if(s[0] == 'x')
        {
            st.pos = 0;
            st.a[0] = 8;
        }
        else if(s[0] >= '1' && s[0] <= '8')
            st.a[0] = s[0] - '0' - 1;
        for(int i = 1; i < 9; i++)
        {
            scanf("%s", s);
            if(s[0] == 'x')
            {
                st.pos = i;
                st.a[i] = 8;
            }
            else if(s[0] >= '1' && s[0] <= '8')
                st.a[i] = s[0] - '0' - 1;
        }
        //int hash_start = Cantor(st);
        //if(!vis[hash_start])    //改判定方法更快（78ms，5572kB）
        if(!check(st))
        {
            puts("unsolvable");
            continue;
        }
        else
        {
            //int tmp = hash_start;
            int tmp = Cantor(st);
            while(tmp != 0)
            {
                printf("%c", ans[tmp]);
                tmp = pre[tmp];
            }
            puts("");
        }
    }
    return 0;
}
