/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-08-17
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: UVa
 *  Algorithm: 哈夫曼编码 + 优先队列
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

const int MAXN = 105;

struct Node
{
    int freq, prio, id;
    Node() {}
    Node(int freq, int prio, int id) : freq(freq), prio(prio), id(id) {}
    bool operator < (const Node &nd) const
    {
        if(freq == nd.freq)
            return prio > nd.prio;
        return freq > nd.freq;
    }
};

priority_queue<Node> pq;
int f[MAXN], fa[MAXN], code[MAXN];  //出现频率、父结点、编码

int main()
{
    int kase = 1;
    int n, r;
    while(~scanf("%d", &r), r)
    {
        while(!pq.empty())
            pq.pop();
        memset(f, 0, sizeof(f));
        scanf("%d", &n);
        int sum = 0;
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &f[i]);
            sum += f[i];
        }
        int cnt = n;    //所有结点数量（包括虚拟结点）
        while((cnt - r) % (r - 1))
            cnt++;  //补充虚拟结点
        for(int i = 0; i < cnt; i++)
            pq.push(Node(f[i], i, i));
        int fsum = 0;   //总的频率值
        int id = cnt;
        while(pq.size() > 1)
        {
            int tsum = 0, minp = cnt;
            for(int i = 0; i < r; i++)  //分配编码
            {
                Node tmp = pq.top();
                pq.pop();
                tsum += tmp.freq;
                minp = min(minp, tmp.prio); //记录优先值
                fa[tmp.id] = id;   //记录父结点
                code[tmp.id] = i;   //记录该结点处的编码
            }
            pq.push(Node(tsum, minp, id++));
            fsum += tsum;
        }
        id--;
        printf("Set %d; average length %0.2f\n", kase++, 1.0 * fsum / sum);
        for(int i = 0; i < n; i++)
        {
            vector<char> ans;
            int cur = i;
            while(cur != id)
            {
                ans.PB(code[cur] + '0');
                cur = fa[cur];
            }
            printf("    %c: ", i + 'A');
            for(auto it = ans.rbegin(); it != ans.rend(); it++)
                printf("%c", *it);
            puts("");
        }
        puts("");
    }
    return 0;
}

/*
2 5 5 10 20 25 40
2 5 4 2 2 1 1
3 7 20 5 8 5 12 6 9
4 6 10 23 18 25 9 12
0
*/
