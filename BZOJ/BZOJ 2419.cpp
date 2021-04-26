/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-04-25
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: BZOJ
 *  Algorithm: ��˹��Ԫ�����Է����� + ���������ɣ��ڵ��λ����
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

const int MAXN = 105;

double a[MAXN][MAXN];   //ϵ������
double x[MAXN]; //�⼯����ʼ��ʱ�洢�������ĳ�ϵ����

/*
��˹��Ԫ�⸡����ϵ������
����0��ʾ�޽⣬����1��ʾ�н�
*/
int Gauss(int equ, int var) //equΪ��������varΪδ֪������
{
    int k, col;
    for(k = 0, col = 0; k < equ && col < var; k++, col++)
    {
        int max_r = k;
        for(int i = k + 1; i < equ; i++)
        {
            if(fabs(a[i][col]) > fabs(a[max_r][col]))
                max_r = i;
        }
        if(fabs(a[max_r][col]) < EPS)
            return 0;
        if(k != max_r)
        {
            for(int j = col; j < var; j++)
                swap(a[k][j], a[max_r][j]);
            swap(x[k], x[max_r]);
        }
        x[k] /= a[k][col];
        for(int j = col + 1; j < var; j++)
            a[k][j] /= a[k][col];
        a[k][col] = 1;
        for(int i = 0; i < equ; i++)
        {
            if(i != k)
            {
                x[i] -= x[k] * a[i][col];
                for(int j = col + 1; j < var; j++)
                    a[i][j] -= a[k][j] * a[i][col];
                a[i][col] = 0;
            }
        }
    }
    return 1;
}

int main()
{
    int n, m;
    while(~scanf("%d%d", &n, &m))
    {
        memset(a, 0, sizeof(a));
        memset(x, 0, sizeof(x));
        for(int i = 0; i < m; i++)
        {
            int u, v;
            double r;
            scanf("%d%d%lf", &u, &v, &r);
            u--, v--;
            //������·�ĵ������㹫ʽΪ I = Sigma(I_i)
            //���ݻ��������ɣ�����һ����㣬ĳһʱ�������ĵ�����������ĵ���
            //�� Sigma(I_in) = Sigma(I_out)
            if(u)
            {
                a[u][u] += 1.0 / r; //�������ĵ���
                a[u][v] -= 1.0 / r; //�����u���е��Ʋ���������ĵ���
            }
            if(v)
            {
                a[v][v] += 1.0 / r; //�������ĵ���
                a[v][u] -= 1.0 / r; //�����v���е��Ʋ���������ĵ���
            }
        }
        a[0][0] = 1;    //��0�ŵ�Ϊ���λ�㣨����Ϊ0��
        x[n - 1] = 1;   //��n-1�ŵ����Ϊ1
        int ans = Gauss(n, n);
        printf("%.2f\n", fabs(x[n - 1]));   //��Ϊ fabs(x[0] - x[n - 1])������ x[0] = 0 ��ʡ��
    }
    return 0;
}
