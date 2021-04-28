/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-04-28
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm: ̰�� + ���� + ǰ׺��
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

const int MAXN = 200005;

int a[MAXN];
LL sum2[MAXN];
vector<int> app1, app2;

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        LL m;
        scanf("%d%lld", &n, &m);
        app1.clear(), app2.clear();
        memset(sum2, 0, sizeof(sum2));
        for(int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        for(int i = 0; i < n; i++)
        {
            int b;
            scanf("%d", &b);
            if(b == 1)
                app1.PB(a[i]);
            else
                app2.PB(a[i]);
        }
        sort(app1.begin(), app1.end(), greater<int>());
        sort(app2.begin(), app2.end(), greater<int>());
        for(int i = 0; i < app2.size(); i++)
            sum2[i + 1] = sum2[i] + app2[i];
        LL sum = 0, ans = LINF;
        //�����������ȼ�Ϊ1��app������m�Ĳ������������ȼ�Ϊ2��app
        for(int i = 0; i < app1.size(); i++)
        {
            sum += app1[i];
            if(sum >= m)    //����Ѿ�������m��С�Ŀռ���
            {
                ans = min(ans, (LL)(i + 1));
                break;
            }
            else    //������Ŀռ仹����
            {
                //�����ҵ�С�ڵ��� m - sum ��ǰ׺��λ�ã����ڲ���
                int pos = lower_bound(sum2 + 1, sum2 + 1 + app2.size(), m - sum) - sum2;
                if(pos == app2.size() + 1)  //û���ҵ����ʵ�λ��
                    continue;
                ans = min(ans, (LL)i + 1 + (LL)pos * 2);
            }
        }
        //printf("- %lld -\n", sum);
        //���û�����ȼ�Ϊ1��app
        //�����ҵ�С�ڵ��� m ��ǰ׺��λ�ã����ڲ���
        int pos = lower_bound(sum2 + 1, sum2 + 1 + app2.size(), m) - sum2;
        if(pos != app2.size() + 1)  //û���ҵ����ʵ�λ��
            ans = min(ans, (LL)pos * 2);
        if(ans != LINF)
            printf("%lld\n", ans);
        else
            puts("-1");
    }
    return 0;
}
