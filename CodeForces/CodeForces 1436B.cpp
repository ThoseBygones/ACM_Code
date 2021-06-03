/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-06-02
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm: 素数筛
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

const int MAXN = 100000;

bool np[MAXN + 5];
vector<int> prime;

void init()
{
    np[1] = true;
    for(int i = 2; i <= MAXN; i++)
    {
        if(!np[i])
            prime.PB(i);
        for(int j = i * 2; j <= MAXN; j += i)
            np[j] = true;
    }
}

int main()
{
    init();
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        int x = 1;
        for(int i = 0; i < prime.size(); i++)
        {
            //cout << prime[i] - n + 1 << endl;
            //system("pause");
            if(prime[i] >= n && np[prime[i] - n + 1])
            {
                x = prime[i] - n + 1;
                //cout << x << endl;
                break;
            }
        }
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(i == j)
                    printf("%d%c", x, (j == n ? '\n' : ' '));
                else
                    printf("1%c", (j == n ? '\n' : ' '));
            }
        }
    }
    return 0;
}
