/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-06-16
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

const int MAXN = 55;

int a[MAXN];

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        int cnt0 = 0, cnt1 = 0; //ż��/�����ĸ���
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
            if(a[i] & 1)
                cnt1++;
            else
                cnt0++;
        }
        if(cnt0 & 1)    //�޷�ֱ����ż����ͬ�������������
        {
            sort(a, a + n);
            bool flag = false;
            for(int i = 1; i < n; i++)
            {
                if(a[i] - a[i-1] == 1)
                {
                    flag = true;
                    break;
                }
            }
            if(flag)
                puts("YES");
            else
                puts("NO");
        }
        else
            puts("YES");
    }
    return 0;
}
