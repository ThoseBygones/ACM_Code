/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-05-20
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm: 单调栈
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

const int MAXN = 200005;

int cnt[30];
char s[MAXN];
int sta[MAXN];
bool flag[30];  //当前某个字母是否还可以被留下

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%s", s);
        int n = strlen(s);
        memset(cnt, 0, sizeof(cnt));
        memset(flag, false, sizeof(flag));
        for(int i = 0; i < n; i++)
            cnt[s[i] - 'a']++;
        int top = -1;
        for(int i = 0; i < n; i++)
        {
            cnt[s[i] - 'a']--;
            if(flag[s[i] - 'a']) //该字母也被用过，不考虑保留
                continue;
            while(~top && s[i] - 'a' > sta[top] && cnt[sta[top]] > 0)
                flag[sta[top--]] = false;   //该字母不保留，因此后面的可以考虑保留
            sta[++top] = s[i] - 'a';
            flag[s[i] - 'a'] = true; //该字母被用过了
        }
        for(int i = 0; i <= top; i++)
            printf("%c", sta[i] + 'a');
        puts("");
    }
    return 0;
}
