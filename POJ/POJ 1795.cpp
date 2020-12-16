/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-12-02
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: POJ
 *  Algorithm: ״̬ѹ��dp + DFS
 ********************************************************************************
 *  Algo-Description:
 ********************************************************************************
 */

//#pragma comment(linker,"/STACK:102400000,102400000")
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <climits>
#include <ctime>
#include <numeric>
#include <vector>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <complex>
#include <deque>
#include <functional>
#include <list>
#include <map>
#include <string>
#include <sstream>
#include <set>
#include <stack>
#include <queue>
//#include <bits/stdc++.h>
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

const int MAXN = 16;

string s[MAXN];
int dp[1 << MAXN][MAXN];    //dp[s][i]��ʾ�ڰ����Ӵ�״̬Ϊs������£������Ϊ��i���Ӵ�ʱ���������е���̳���
int cost[MAXN][MAXN];   //cost[i][j]��ʾ�ڵ�j�������ƴ�ϵ�i�������ӵĳ��ȣ��ص����ֲ��㣩
string dna;
int n;

void init() //Ԥ����
{
    /* �ҵ����б��������Ӵ����滻Ϊĸ�� */
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i != j && s[i].find(s[j]) != string::npos)
                s[j] = s[i];
        }
    }
    /* ȥ�� */
    sort(s, s + n);
    n = unique(s, s + n) - s;
    /* ���㴮s[i]ƴ�ӵ�s[j]���ʹƴ�Ӻ���ַ������ӵĳ��ȣ��ص����ֲ��㣩 */
    for(int i = 0; i < n; i++)
    {
        int len = s[i].length();
        for(int j = 0; j < n; j++)
        {
            cost[i][j] = len;
            if(i != j)
            {
                for(int k = min(s[i].length(), s[j].length()); k; k--)
                {
                    if(s[i].substr(len - k) == s[j].substr(0, k))
                    {
                        cost[i][j] = len - k;
                        break;
                    }
                }
            }
        }
    }
}

void dfs(int pre, int sta)  //����ƴ�ӹ��̣���������ƴ��
{
    int prepos = -1;
    int presta = sta & (~(1 << pre));  //��ԭǰһ״̬
    if(!presta)
        return ;
    string nxt; //��һ���Ӵ�
    for(int cur = 0; cur < n; cur++)    //ö�ٵ�ǰ״̬�µ�����˵��Ӵ���ƴ��״̬Ϊ��pre|cur|...��
    {
        if(dp[presta][cur] != INF && dp[presta][cur] + cost[pre][cur] == dp[sta][pre])
        {
            string tmp = s[cur].substr(s[pre].length() - cost[pre][cur]);   //ƴ�ӵ�ʱ��ǰ���ظ��Ĳ���ȥ��
            if(prepos == -1 || nxt > tmp)   //ƴ����̵��ֵ�����С��
            {
                prepos = cur;
                nxt = tmp;
            }
        }
    }
    dna += nxt;
    dfs(prepos, presta);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for(int kase = 1; kase <= t; kase++)
    {
        cin >> n;
        for(int i = 0; i < n; i++)
            cin >> s[i];
        init();
        for(int i = 0; i < (1 << MAXN); i++)
            fill(dp[i], dp[i] + MAXN, INF);
        for(int i = 0; i < n; i++)
            dp[1 << i][i] = cost[i][i];
        for(int s = 0; s < (1 << n); s++)   //ö��״̬
        {
            for(int i = 0; i < n; i++)  //ö���Ӵ�
            {
                if(dp[s][i] != INF)
                {
                    for(int j = 0; j < n; j++)
                    {
                        if(!(s & (1 << j)))
                            dp[s | (1 << j)][j] = min(dp[s | (1 << j)][j], dp[s][i] + cost[j][i]);
                    }
                }
            }
        }
        int ans = INF, pos = 0;
        for(int i = 0; i < n; i++)
        {
            if(ans > dp[(1 << n) - 1][i] || (ans == dp[(1 << n) - 1][i] && s[i] < s[pos]))  //�ҵ��ֵ�����С��ǰ׺�Ӵ�
            {
                ans = dp[(1 << n) - 1][i];
                pos = i;
            }
            dna = s[pos];
        }
        dfs(pos, (1 << n) - 1);
        cout << "Scenario #" << kase <<  ":" << endl;
        cout << dna << endl << endl;
    }
    return 0;
}
