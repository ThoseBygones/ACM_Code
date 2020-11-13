/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-11-13
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: HDU
 *  Algorithm: �������� + ��ȡ��
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

const int MAXN = 100005;

int a[MAXN];
int q1[MAXN], q2[MAXN]; //���/��С��������

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n, k;
        scanf("%d%d", &n, &k);
        for(int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        int head1 = 1, tail1 = 0;
        int head2 = 1, tail2 = 0;
        q1[++tail1] = a[1];
        q2[++tail2] = a[1];
        LL ans = 1;
        for(int l = 1, r = 2; r <= n; r++)  //ö�������Ҷ˵㣨���Ƴ�ȡ����
        {
            while(head1 <= tail1 && q1[tail1] < a[r])   //��������ά�����ֵ
                --tail1;
            q1[++tail1] = a[r];
            while(head2 <= tail2 && q2[tail2] > a[r])   //��������ά����Сֵ
                --tail2;
            q2[++tail2] = a[r];
            while(q1[head1] - q2[head2] >= k)   //�ж������е������Сֵ���Ƿ�С��k
            {
                if(q1[head1] == a[l])
                    head1++;
                if(q2[head2] == a[l])
                    head2++;
                l++;
            }
            ans += r - l + 1;   //����������������������������
        }
        printf("%lld\n", ans);
    }
    return 0;
}
