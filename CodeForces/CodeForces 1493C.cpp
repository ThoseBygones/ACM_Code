/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2022-05-10
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

char s[MAXN];
int pre[MAXN][30];  //pre[i][j]表示前i个字符中，字母 'a' + j 出现的次数的前缀和

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n, k;
        scanf("%d%d%s", &n, &k, s + 1);
        if(n % k)
        {
            puts("-1");
            continue;
        }
        for(int i = 1; i <= n; i++) //求前缀和
        {
            for(int j = 0; j < 26; j++)
                pre[i][j] = pre[i - 1][j] + (s[i] == 'a' + j);
        }
        int cnt = 0;    //需要修改的总次数
        for(int i = 0; i < 26; i++)
            cnt += (k - pre[n][i] % k) % k;
        if(!cnt)    //不需要修改
        {
            printf("%s\n", s + 1);
            continue;
        }
        bool flag = false;  //是否找到了合法的新序列
        for(int i = n; i && !flag; i--)  //枚举修改位
        {
            pre[i][s[i] - 'a']--;
            for(int j = s[i] - 'a' + 1; j < 26; j++)    //枚举修改位可以修改成的大于原字母的新字母
            {
                pre[i][j]++;
                int cnt = 0;
                for(int a = 0; a < 26; a++)
                    cnt += (k - pre[i][a] % k) % k;
                //printf("%d - %c: cnt: %d\n", i, s[i] + 1, cnt);
                if(cnt <= n - i)    //这样的修改可行，剩下的 n - i 位有可能通过修改以后得到合法的字符串
                {
                    for(int a = 1; a <= i - 1; a++)
                        printf("%c", s[a]);
                    printf("%c", j + 'a');
                    for(int a = 0; a < n - i - cnt; a++)    //不需要修改的位补最小的字母
                        printf("a");
                    for(int a = 0; a < 26; a++) //第 i + 1 位开始按照字典序最小重排列
                    {
                        int tmp = (k - pre[i][a] % k) % k;
                        while(tmp--)
                            printf("%c", a + 'a');
                    }
                    puts("");
                    flag = true;
                    break;
                }
                pre[i][j]--;
            }
            pre[i][s[i] - 'a']++;
        }
        if(!flag)
            puts("-1");
    }
    return 0;
}
