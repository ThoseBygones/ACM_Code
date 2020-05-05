/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-05-05
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: CodeForces
 *  Algorithm: 模拟
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

const int MAXN = 3005;
const int MAXM = 3000005;

vector<int> v[MAXM];
char s[MAXN];

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    scanf("%s", s + 1);
    int rd = 0, cnt = 0; //扫描趟数和交换次数
    while(true)
    {
        bool modify = false;    //这一趟扫描是否有交换
        for(int i = 1; i < n; i++)
        {
            if(s[i] == 'R' && s[i+1] == 'L')
            {
                swap(s[i], s[i+1]);
                v[rd].PB(i);
                modify = true;
                cnt++;
                i++;    //下个判断从i+2开始
            }
        }
        rd++;
        if(!modify) //此轮没有修改，说明已经没有面对面的学生了
            break;
    }
    rd--;   //最后一趟没有操作，减去即可
    if(k < rd || cnt < k)
    {
        puts("-1");
        return 0;
    }
    int segcnt = 0; //某几趟交换中拆出来的单独交换次数
    for(int i = 0; i < rd; i++)
    {
        int pos = 0;
        while(pos + 1 < v[i].size() && segcnt + rd + 1 <= k)    //该趟还可以拆分且该趟拆分后新增的段数加上原趟数不超过k
        {
            printf("1 %d\n", v[i][pos]);
            segcnt++;   //拆分出的交换次数+1
            pos++;  //检查下个位置是否可拆
        }
        printf("%d", v[i].size() - pos);
        for(int j = pos; j < v[i].size(); j++)
            printf(" %d", v[i][j]);
        puts("");
    }
    return 0;
}
