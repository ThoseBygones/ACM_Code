/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-07-17
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm: 模拟
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
        for(int i = 1; i <= n - 2; i++) //从小到大调整，每次保证最前面一个未排序的位置排好序
        {
            int pos = -1, Min = MAXN;
            for(int j = i; j <= n; j++)
            {
                if(a[j] < Min)  //找到未完全排序区域内最小的数
                {
                    Min = a[j];
                    pos = j;
                }
            }
            while(pos >= i + 2)  //直接一步前移两位
            {
                pos -= 2;
                cycle_shift(pos);
                ans.PB(pos);
            }
            if(pos == i + 1)    //相邻，则需要调整两次
            {
                pos = i;
                cycle_shift(i); //先把最小的调整到i+2处
                ans.PB(i);
                cycle_shift(i); //再调到最前
                ans.PB(i);
            }
        }
        if(a[n-1] > a[n])   //如果最末尾两个数逆序
        {
            for(int i = n; i >= 3; i--) //从大到小调整，每次保证最后面一个未排序的位置排好序
            {
                int pos = i - 1;
                cycle_shift(pos-1);
                ans.PB(pos-1);
                if(a[pos-1] == a[pos])  //调整后相邻两个数相等，则肯定已经排好序
                    break;
            }
        }
        bool flag = true;
        for(int i = 1; i < n; i++)
        {
            if(a[i] > a[i+1])   //如果还存在逆序对，则无解
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
