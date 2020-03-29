/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-03-27
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: CodeForces
 *  Algorithm:
 ********************************************************************************
 *  Algo-Description:
 ********************************************************************************
 */

#include <bits/stdc++.h>  //For CodeForces only
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
#define clr(ar,val) memset(ar, val, sizeof(ar))
#define istr stringstream
#define FOR(i,n) for(int i=0;i<(n);++i)
#define forIt(mp,it) for(__typeof(mp.begin()) it = mp.begin();it!=mp.end();it++)
const double EPS = 1e-6;
const int INF = 0x3fffffff;
const LL LINF = INF * 1ll * INF;
const double PI = acos(-1.0);

#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define lowbit(u) (u&(-u))
#define MAXN 300005

char s[MAXN];
int sum[MAXN];

int main()
{
    int n;
    scanf("%d", &n);
    scanf("%s", s + 1);
    int cnt = 0, Min = n, pos = 0;
    for(int i = 1; i <= n; i++)
    {
        if(s[i] == '(')
            cnt++;
        else
            cnt--;
        if(cnt < Min)
        {
            Min = cnt;
            pos = i;    //记录最低点
        }
    }
    if(cnt)
    {
        printf("0\n1 1\n");
        return 0;
    }
    int ans = 0;    //记录大于0的点的数量（即不交换任何括号时候的答案）
    for(int i = 1; i <= n; i++) //模拟循环位移，并将折线向上平移至y=0以上
    {
        char c = s[(pos+i-1)%n+1];
        sum[i] = sum[i-1] + (c == '(' ? 1 : -1);
        if(!sum[i]) //记录在y=0上的尖点
            ans++;
    }
    int rec = ans;
    int l = 1, r = 1;
    //交换括号序列最外层的括号（sum[i] == 1）的方案
    for(int i = 1; i <= n; i++)
    {
        if(sum[i] == 1) //找到一个备选的交换位置
        {
            int j = i + 1;
            cnt = 1;
            while(sum[j] >= 1)  //找到可以跟i位置交换的括号
            {
                if(sum[j] == 1)
                    cnt++;
                j++;
            }
            if(cnt > ans)   //更新答案
            {
                ans = cnt;
                l = i, r = j;
            }
            i = j;  //更新备选交换位置
        }
    }
    //交换括号序列第一层内层的括号（sum[i] == 2）的方案
    for(int i = 1; i <= n; i++)
    {
        if(sum[i] == 2) //找到一个备选的交换位置
        {
            int j = i + 1;
            cnt = 1;
            while(sum[j] >= 2)  //找到可以跟i位置交换的括号
            {
                if(sum[j] == 2)
                    cnt++;
                j++;
            }
            if(cnt + rec > ans) //交换第一层内层的括号不会改变外层括号情况
            {
                ans = cnt + rec;
                l = i, r = j;
            }
            i = j;
        }
    }
    printf("%d\n%d %d\n", ans, (l + pos - 1) % n + 1, (r + pos - 1) % n + 1);
    return 0;
}
