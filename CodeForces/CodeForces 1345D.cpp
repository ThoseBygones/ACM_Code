/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-08-04
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm:
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

const int MAXN = 1005;
const int dx[4] = {-1, 0, 0, 1};
const int dy[4] = {0, -1, 1, 0};

char s[MAXN][MAXN];
bool vis[MAXN][MAXN];
int n, m;

bool inMap(int x, int y)
{
    if(x >= 0 && y >= 0 && x < n && y < m)
        return true;
    return false;
}

void dfs(int x, int y)
{
    vis[x][y] = true;
    for(int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(inMap(nx, ny) && !vis[nx][ny] && s[nx][ny] == '#')
            dfs(nx, ny);
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++)
        scanf("%s", s[i]);
    bool wrow = false, wcol = false;    //�Ƿ����ȫ�׵��к���
    for(int i = 0; i < n; i++)
    {
        int bcnt = 0;   //���к�ɫ��������
        bool black = false;  //�Ƿ��Ѿ����ֹ���ɫ����
        for(int j = 0; j < m; j++)
        {
            if(s[i][j] == '#')
            {
                bcnt++;
                if(j && black && s[i][j - 1] != '#') //�������֮ǰ�ĸ����к�ɫ�����Һ�ɫ���Ӳ�����
                {
                    puts("-1");
                    return 0;
                }
                black = true;
            }
        }
        if(!bcnt)   //����û�к�ɫ����
            wrow = true;
    }
    for(int j = 0; j < m; j++)
    {
        int bcnt = 0;   //���к�ɫ��������
        bool black = false;  //�Ƿ��Ѿ����ֹ���ɫ����
        for(int i = 0; i < n; i++)
        {
            if(s[i][j] == '#')
            {
                bcnt++;
                if(i && black && s[i - 1][j] != '#') //�������֮ǰ�ĸ����к�ɫ�����Һ�ɫ���Ӳ�����
                {
                    puts("-1");
                    return 0;
                }
                black = true;
            }
        }
        if(!bcnt)   //����û�к�ɫ����
            wcol = true;
    }
    //printf("wrow:%d wcol:%d\n", wrow, wcol);
    if(wrow ^ wcol)   //����ȫ���У��У�����δ����ȫ�׵��У��У�
    {
        puts("-1");
        return 0;
    }
    int ans = 0;    //��ͨ������
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(s[i][j] == '#' && !vis[i][j])
            {
                ans++;
                dfs(i, j);
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
