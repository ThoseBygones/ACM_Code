/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-07-26
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: HDU
 *  Algorithm:
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

const int MAXN = 100005;

bool r[MAXN];   //�ҳ���·��ǰ��ÿ��λ���Ƿ�ռ��

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        int lmax = -1, rmax = 0;    //lmax��Ϊ-1����Ӱ��ֻ���ҳ�����1λ���г������
        memset(r, false, sizeof(r));
        for(int i = 0; i < n; i++)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            if(x == 1)
            {
                rmax = max(rmax, y);
                r[y] = true;
            }
            else
            {
                if(!r[y+1]) //�ҳ����ĵ�y+1λ��δ��ռ�ã����󳵵���yλ�õĳ�����
                {
                    rmax = max(rmax, y + 1);
                    r[y+1] = true;
                }
                else
                    lmax = max(lmax, y);
            }
        }
        printf("%d\n", max(lmax + 3, rmax + 1));
    }
    return 0;
}
