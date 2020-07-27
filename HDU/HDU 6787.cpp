/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-07-26
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: HDU
 *  Algorithm: dp���������飩 / Ԥ���� + dp
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
const int MOD = 1000000007;

/* dp���������飩��748ms��*/

LL dp[2][MAXN][11]; //���������飩dp[i][j][k]��ʾ��ǰ��λ��i���Ѿ�������j������������λ��i���ô�������λ��i�Ѿ�������k������������ʱ�ܵķ�����

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        for(int j = 0; j <= m; j++)
        {
            for(int k = 0; k <= 10; k++)
                dp[0][j][k] = dp[1][j][k] = 0;
        }
        dp[1][0][0] = 1;
        int cur = 0;
        for(int i = 2; i <= n; i++) //ö�ٵ�ǰ��λ��i��λ��1���ܷŴ�������
        {
            for(int j = 0; j <= min(i, m); j++) //ö���Ѿ����õĴ���������
            {
                for(int k = 0; k <= 10; k++)    //ö�������Ĵ���������
                {
                    dp[cur][j][0] = (dp[cur][j][0] + dp[cur^1][j][k]) % MOD;  //λ��i�����ô�����
                    if(k && j)  //�����ǰ��λ��i-1�Ѿ������Ĵ�������������10������λ��i���ܷ��ô�����
                        dp[cur][j][k] = (dp[cur][j][k] + dp[cur^1][j-1][k-1] * (i - 1) % MOD) % MOD;  //���Դ��������Դ��͵���λ��������λ��i�Լ����ܱ����ͣ�
                }
            }
            cur ^= 1;
            for(int j = 0; j <= m; j++) //��ս�����Ҫ���µ�����
            {
                for(int k = 0; k <= 10; k++)
                    dp[cur][j][k] = 0;
            }
        }
        //printf("cur: %d\n", cur);
        printf("%lld\n", dp[cur^1][m][0] ? dp[cur^1][m][0] : -1);
    }
    return 0;
}


/* Ԥ���� + dp ��109ms�� */

int dp[MAXN][MAXN][11]; //dp[i][j][k]��ʾ��ǰ��λ��i���Ѿ�������j������������λ��i���ô�������λ��i�Ѿ�������k������������ʱ�ܵķ�����

int main()
{
    int t;
    scanf("%d", &t);
    /* Ԥ����dp */
    dp[1][0][0] = 1;
    for(int i = 2; i <= 1000; i++) //ö�ٵ�ǰ��λ��i��λ��1���ܷŴ�������
    {
        for(int j = 0; j <= i; j++) //ö���Ѿ����õĴ���������
        {
            for(int k = 0; k <= 10; k++)    //ö�������Ĵ���������
            {
                dp[i][j][0] = (dp[i][j][0] + dp[i-1][j][k]) % MOD;  //λ��i�����ô�����
                if(k && j)  //�����ǰ��λ��i-1�Ѿ������Ĵ�������������10������λ��i���ܷ��ô�����
                    dp[i][j][k] = (dp[i][j][k] + 1LL * dp[i-1][j-1][k-1] * (i - 1) % MOD) % MOD;  //���Դ��������Դ��͵���λ��������λ��i�Լ����ܱ����ͣ�
            }
        }
    }
    while(t--)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        printf("%d\n", dp[n][m][0] ? dp[n][m][0] : -1);
    }
    return 0;
}
