/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-04-24
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: POJ
 *  Algorithm: ��˹��Ԫ����򷽳���
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

#define MAXN 255

int a[MAXN][MAXN];  //�������
int x[MAXN];    //�⼯
int free_x[MAXN]; //�����洢���ɱ�Ԫ�����ö�����ɱ�Ԫ����ʹ�ã�
int free_num; //���ɱ�Ԫ�ĸ���

/*
��˹��Ԫ����򷽳��飨��2ȡģ��01�����飩
����ֵΪ-1��ʾ�޽⣬����ֵΪ0��ʾ��Ψһ�⣬���򷵻����ɱ�Ԫ����
*/
int Gauss_xor(int equ, int var) //equΪ��������varΪδ֪������
{
    int col, k;
    free_num = 0;
    for(k = 0, col = 0; k < equ && col < var; k++, col++)
    {
        int max_r = k;
        for(int i = k + 1; i < equ; i++)
        {
            if(abs(a[i][col]) > abs(a[max_r][col])) //��¼��һ����col��ϵ���������
                max_r = i;
        }
        if(a[max_r][col] == 0)
        {
            k--;
            free_x[free_num++] = col;   //��������ɱ�Ԫ
            continue;
        }
        if(max_r != k)
        {
            for(int j = col; j < var + 1; j++)    //����һ����col��ϵ��������л�����k��
                swap(a[k][j], a[max_r][j]);
        }
        for(int i = k + 1; i < equ; i++)    //��ʼ��Ԫ
        {
            if(a[i][col])   //ϵ������
            {
                for(int j = col; j < var + 1; j++)    //�ӵ�ǰ��col�п�ʼ��Ԫ
                    a[i][j] ^= a[k][j];
            }
        }
    }
    /*�޽�*/
    for(int i = k; i < equ; i++)
    {
        if(a[i][col])
            return -1;
    }
    /*��������*/
    if(k < var) //
        return var - k; //�������ɱ�Ԫ����
    /*��Ψһ��*/
    for(int i = var - 1; i >= 0; i--)
    {
        x[i] = a[i][var];
        for(int j = i + 1; j < var; j++)  //�ش�����⼯
            x[i] ^= (a[i][j] && x[j]);
    }
    return 0;
}

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        int col;
        while(~scanf("%d", &col), ~col)
        {
            col--;
            a[col][i] = 1;
        }
        for(int i = 0; i < n; i++)
            a[i][n] = 1;
    }
    int ans = Gauss_xor(n, n);
    if(ans == 0)    //��Ψһ��
    {
        bool flag = true;
        for(int i = 0; i < n; i++)
        {
            if(x[i])
            {
                if(flag)
                {
                    flag = false;
                    printf("%d", i + 1);
                }
                else
                    printf(" %d", i + 1);
            }
        }
        puts("");
    }
    /*
     * ��Ŀ˵��ÿ�����˲��ܱ���������ȡ�����������е��������������޹ص�
     * �ʸ÷������Ӧ������������һ��Ϊ n���� r(A) = r(A,b) = n
     * ��ˣ���������Է����� AX = b �н�����Ψһ��
     */
    else    //�޽���������⣨�������⣬���������������
        puts("No solution");
    return 0;
}
