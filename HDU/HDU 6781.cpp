/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-07-30
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm: ̰�� + ���ȶ��� / dp
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

const int MAXN = 2005;

/* ����һ��̰�� + ���ȶ��� */

LL a[MAXN], b[MAXN];

struct Problem
{
    LL l, len;
    Problem() {}
    Problem(LL l, LL len) : l(l), len(len) {}
    bool operator <(const Problem &p) const //�����ʱʱ�䳤����Ŀ����
    {
        if(len == p.len)
            return l > p.l;
        return len < p.len;
    }
};

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
            scanf("%lld", &a[i]);
        for(int i = 1; i <= n; i++)
        {
            scanf("%lld", &b[i]);
            b[i] += b[i - 1];
        }
        priority_queue<Problem> pq;
        LL cur_time = 0;
        for(int i = 1; i <= n; i++)
        {
            if(cur_time + a[i] <= b[i]) //�����������Bob���֮ǰ���
            {
                pq.push(Problem(cur_time, a[i]));
                cur_time += a[i];
            }
            else if(!pq.empty())    //������ⲻ����Bob���֮ǰ���������֮ǰ����������Ŀ���Է��ڲ���
            {
                Problem tmp = pq.top();
                if(cur_time + a[i] - tmp.len <= b[i])    //�����ڣ�ѡ����֮ǰ�������Ŀ����ʱ����Ǹ�
                {
                    pq.pop();
                    cur_time -= tmp.len;
                    pq.push(Problem(cur_time, a[i]));
                    cur_time += a[i];
                }
            }
        }
        printf("%d\n", pq.size());
    }
    return 0;
}


/* ����������̬�滮 */

LL dp[MAXN][MAXN]; //dp[i][j]��ʾ����ǰi�⣬Alice�õ�j��ʱ�ȶ������õ����ʱ��
LL a[MAXN], b[MAXN];

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
            scanf("%lld", &a[i]);
        for(int i = 1; i <= n; i++)
            scanf("%lld", &b[i]);
        memset(dp, -1, sizeof(dp));
        dp[0][0] = 0;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= i; j++)
            {
                if(~dp[i - 1][j - 1])   //ǰһ״̬�Ϸ�
                {
                    dp[i][j - 1] = max(dp[i][j - 1], dp[i - 1][j - 1] + b[i]);  //��i�ⲻ��
                    if(dp[i - 1][j - 1] >= a[i] - b[i])  //�����i���������õ���
                        dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] - (a[i] - b[i]));
                }
            }
        }
        int ans = 0;
        for(int i = 0; i <= n; i++)
        {
            if(~dp[n][i])
                ans = i;
        }
        printf("%d\n", ans);
    }
    return 0;
}

