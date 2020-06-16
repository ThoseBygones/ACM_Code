/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-06-16
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm: ���� + STL Map + ����ת��
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

const int MAXN = 105;
const int MAXM = 65;

map<LL, bool> mp;   //�������ĳ������������ת��Ϊʮ���ƺ��Ƿ�ɾȥ
char s[MAXM];
LL a[MAXN];

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        mp.clear();
        for(int i = 0; i < n; i++)
        {
            scanf("%s", s);
            LL val = 0;
            for(int j = 0; j < m; j++)  //������ֵתʮ����ֵ
                val = (val << 1) + s[j] - '0';
            a[i] = val;
        }
        LL tot = 1LL << m;
        LL mid = (tot - 1) >> 1;
        for(int i = 0; i < n; i++)
        {
            mp[a[i]] = true;
            if(!(tot & 1) && a[i] <= mid)   //��ǰ������ʣ����������Ϊż������ɾ���������ڵ�ǰ��λ��֮ǰ��������λ����
            {
                mid++;  //��λ������
                while(mp[mid])
                    mid++;
            }
            else if((tot & 1) && a[i] >= mid)   //��ǰ������ʣ����������Ϊ��������ɾ���������ڵ�ǰ��λ��֮�󣨰�����λ����
            {
                mid--;  //��λ��ǰ��
                while(mp[mid])
                    mid--;
            }
            tot--;
        }
        vector<int> ans;
        while(mid)
        {
            ans.PB(mid % 2);
            mid >>= 1;
        }
        reverse(ans.begin(), ans.end());
        //printf("-> ");
        for(int i = 0; i < m - ans.size(); i++)
            printf("0");
        for(int i = 0; i < ans.size(); i++)
            printf("%d", ans[i]);
        puts("");
    }
    return 0;
}
