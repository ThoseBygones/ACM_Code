/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2019-05-26
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: CodeForces
 *  Algorithm:
 ********************************************************************************
 *  Algo-Description:
 ********************************************************************************
 */

//#include <bits/stdc++.h>  //For CodeForces only

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
#define MAXN 25

int a[MAXN][MAXN];
int cnt[1005];

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0; i<n*n; i++)
    {
        int x;
        scanf("%d",&x);
        cnt[x]++;
    }
    bool flag = false;  //是否存在奇数项
    int pos = -1;
    for(int i=1; i<=1000; i++)
    {
        if(cnt[i] & 1)  //存在奇数项
        {
            if(flag)    //不止一个奇数项
            {
                puts("NO");
                return 0;
            }
            else
            {
                flag = true;
                pos = i;    //记录那个数可以作为矩阵中心的那个数
                break;
            }
        }
    }
    bool gg = false;
    if(n & 1)   //矩阵维数为奇数
    {
        if(flag)
        {
            a[n/2][n/2] = pos;
            cnt[pos]--;
            int x = 0, y = 0;
            int xx = 0, yy = n / 2;
            bool ok4 = false;

            for(int i=1; i<=1000; i++)
            {
                while(cnt[i])
                {
                    if(cnt[i] % 4 == 0 && !ok4)
                    {
                        a[x][y] = i;
                        a[x][n-y-1] = i;
                        a[n-x-1][y] = i;
                        a[n-x-1][n-y-1] = i;
                        cnt[i] -= 4;
                        y++;
                        if(y == n/2)
                        {
                            y = 0;
                            x++;
                        }
                        if(x == n/2)
                            ok4 = true;
                    }
                    else if(cnt[i] % 2 == 0)
                    {
                        //cout << i << endl;
                        if(yy == n/2)
                        {
                            a[xx][yy] = i;
                            a[n-xx-1][yy] = i;
                            cnt[i] -= 2;
                            xx++;
                            if(xx == n/2)    //中心不填
                                yy = 0;
                        }
                        else if(xx == n/2)
                        {
                            a[xx][yy] = i;
                            a[xx][n-yy-1] = i;
                            cnt[i] -= 2;
                            yy++;
                            if(yy == n/2)
                                break;
                        }
                    }
                    else
                    {
                        puts("NO");
                        return 0;
                    }
                }
            }
        }
        else
        {
            puts("NO");
            return 0;
        }
    }
    else    //矩阵维数为偶数
    {
        if(flag)
        {
            puts("NO");
            return 0;
        }
        else
        {
            int x = 0, y = 0;
            for(int i=1; i<=1000; i++)
            {
                if(cnt[i])
                {
                    if(cnt[i] % 4 == 0)
                    {
                        while(cnt[i])
                        {
                            a[x][y] = i;
                            a[x][n-y-1] = i;
                            a[n-x-1][y] = i;
                            a[n-x-1][n-y-1] = i;
                            cnt[i] -= 4;
                            y++;
                            if(y == n/2)
                            {
                                y = 0;
                                x++;
                            }
                        }

                    }
                    else
                    {
                        puts("NO");
                        return 0;
                    }
                }
            }
        }
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(!a[i][j])
            {
                puts("NO");
                return 0;
            }
        }
    }
    puts("YES");
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
            printf("%d ",a[i][j]);
        puts("");
    }
    return 0;
}
