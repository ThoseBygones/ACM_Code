/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-07-17
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm: ģ��
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

const int MAXN = 505;

vector<int> ans;
int a[MAXN];

void cycle_shift(int pos)
{
    swap(a[pos], a[pos+2]);
    swap(a[pos+1], a[pos+2]);
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        ans.clear();
        for(int i = 1; i <= n - 2; i++) //��С���������ÿ�α�֤��ǰ��һ��δ�����λ���ź���
        {
            int pos = -1, Min = MAXN;
            for(int j = i; j <= n; j++)
            {
                if(a[j] < Min)  //�ҵ�δ��ȫ������������С����
                {
                    Min = a[j];
                    pos = j;
                }
            }
            while(pos >= i + 2)  //ֱ��һ��ǰ����λ
            {
                pos -= 2;
                cycle_shift(pos);
                ans.PB(pos);
            }
            if(pos == i + 1)    //���ڣ�����Ҫ��������
            {
                pos = i;
                cycle_shift(i); //�Ȱ���С�ĵ�����i+2��
                ans.PB(i);
                cycle_shift(i); //�ٵ�����ǰ
                ans.PB(i);
            }
        }
        if(a[n-1] > a[n])   //�����ĩβ����������
        {
            for(int i = n; i >= 3; i--) //�Ӵ�С������ÿ�α�֤�����һ��δ�����λ���ź���
            {
                int pos = i - 1;
                cycle_shift(pos-1);
                ans.PB(pos-1);
                if(a[pos-1] == a[pos])  //������������������ȣ���϶��Ѿ��ź���
                    break;
            }
        }
        bool flag = true;
        for(int i = 1; i < n; i++)
        {
            if(a[i] > a[i+1])   //�������������ԣ����޽�
            {
                flag = false;
                break;
            }
        }
        if(flag)
        {
            printf("%d\n", ans.size());
            for(int i = 0; i < ans.size(); i++)
                printf("%d%c", ans[i], (i == ans.size() - 1 ? '\n' : ' '));
        }
        else
            puts("-1");
        /*for(int i = 1; i <= n; i++)
            printf("%d ", a[i]);
        puts("");
        */
    }
    return 0;
}
