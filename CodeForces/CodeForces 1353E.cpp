/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-06-08
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: CodeForces
 *  Algorithm: dp + ǰ׺��
 ********************************************************************************
 *  Algo-Description:
 ********************************************************************************
 */

#include <bits/stdc++.h>
using namespace std;

template<class T> inline T sqr(T x) {return x * x;}
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

const int MAXN = 1000005;

char s[MAXN];
int pre[MAXN];  //ǰ׺�ͣ���¼�ַ�'1'�ĸ���
int dp[MAXN];   //dp[i]��ʾ��iλ�ַ�Ϊ'1'ʱ��ǰiλ�ַ�����Ҫ�޸��ַ���������Сֵ

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n, k;
        scanf("%d%d", &n, &k);
        scanf("%s", s + 1);
        for(int i = 1; i <= n; i++)
        {
            pre[i] = pre[i-1] + (s[i] == '1');
            dp[i] = pre[i-1] + (s[i] == '0');
        }
        for(int i = k + 1; i <= n; i++)
            dp[i] = min(dp[i], dp[i-k] + pre[i-1] - pre[i-k] + (s[i] == '0'));    //�ӵ�i-k���ַ�����i-1���ַ��У�����1�޸�Ϊ0
        int ans = INF;
        for(int i = 0; i <= n; i++)
            ans = min(ans, dp[i] + pre[n] - pre[i]);    //ֻ����ǰi���ַ��������ȫ������
        printf("%d\n", ans);
    }
    return 0;
}
