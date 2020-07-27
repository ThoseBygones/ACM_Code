/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-07-26
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: HDU
 *  Algorithm: ����ö��
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

int count_round(int hp, int x)  //�������Ѫ��hp�͹�����x����ܽ��ж�����
{
    if(hp % x)
        return hp / x + 1;
    else
        return hp / x;
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        int ans = INF;
        for(int i = 0; i <= count_round(1000, max(x, y)); i++)  //ö��left��mid�Դ�Ĵ���
        {
            //left��mid�Դ�i�ֺ���ʣ���Ѫ��
            int hpl1 = 1000 - i * y;
            int hpm1 = 1000 - i * x;
            int hpr1 = 1000;
            for(int j = 0; j <= count_round(1000, max(x, z)); j++)  //ö��left��right�Դ�Ĵ���
            {
                //left��right�Դ�j�ֺ���ʣ���Ѫ��
                int hpl = hpl1 - j * z;
                int hpm = hpm1;
                int hpr = hpr1 - j * x;
                if(hpl > 0 && hpm > 0 && hpr > 0) //���������Ѫ��
                {
                    if(count_round(hpm, z) == count_round(hpr, y))  //���mid��right�ܹ�ͬʱ�Դ򵽽���
                        ans = min(ans, i + j + count_round(hpm, z));
                    else
                        continue;
                }
                else if(hpl <= 0 && hpm > 0 && hpr > 0)  //���leftû��Ѫ��
                    ans = min(ans, i + j + min(count_round(hpm, z), count_round(hpr, y)));
                else if(hpm <= 0 && hpl > 0 && hpr > 0) //���midû��Ѫ��
                    ans = min(ans, i + j + min(count_round(hpl, z), count_round(hpr, x)));
                else if(hpr <= 0 && hpl > 0 && hpm > 0) //���rightû��Ѫ��
                    ans = min(ans, i + j + min(count_round(hpl, y), count_round(hpm, x)));
                else
                    ans = min(ans, i + j);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
