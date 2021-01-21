/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-01-21
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: POJ
 *  Algorithm: ������DFS��
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

char str[15];
int sud[10][10];
bool row[10][10];   //row[i][d]��ʾ��i������d�Ƿ���ֹ�
bool col[10][10];   //col[j][d]��ʾ��j������d�Ƿ���ֹ�
bool squ[10][10];   //squ[k][d]��ʾ��k��3*3������������d�Ƿ���ֹ�

bool dfs(int x, int y)
{
    if(x == 10)
        return true;
    bool flag = false;
    if(sud[x][y])   //�ø�����������
    {
        if(y == 9)
            flag = dfs(x + 1, 1);
        else
            flag = dfs(x, y + 1);
        return flag;
    }
    else    //�ø���δ������
    {
        int z = 3 * ((x - 1) / 3) + (y - 1) / 3 + 1;
        for(int i = 1; i <= 9; i++) //ö�ٿ����������
        {
            if(!row[x][i] && !col[y][i] && !squ[z][i])  //��������ǺϷ���
            {
                sud[x][y] = i;
                row[x][i] = true;
                col[y][i] = true;
                squ[z][i] = true;
                if(y == 9)
                    flag = dfs(x + 1, 1);
                else
                    flag = dfs(x, y + 1);
                if(flag)
                    return true;
                else    //��·��ͨ����ԭ�ֳ�
                {
                    sud[x][y] = 0;
                    row[x][i] = false;
                    col[y][i] = false;
                    squ[z][i] = false;
                }
            }
        }
    }
    return false;
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        memset(row, false, sizeof(row));
        memset(col, false, sizeof(col));
        memset(squ, false, sizeof(squ));
        for(int i = 1; i <= 9; i++)
        {
            scanf("%s", str + 1);
            for(int j = 1; j <= 9; j++)
            {
                sud[i][j] = str[j] - '0';
                //cout << sud[i][j] << endl;
                if(sud[i][j])
                {
                    int k = 3 * ((i - 1) / 3) + (j - 1) / 3 + 1;
                    row[i][sud[i][j]] = true;
                    col[j][sud[i][j]] = true;
                    squ[k][sud[i][j]] = true;
                }
            }
        }
        dfs(1, 1);
        //puts("=================");
        for(int i = 1; i <= 9; i++)
        {
            for(int j = 1; j <= 9; j++)
                printf("%d", sud[i][j]);
            puts("");
        }
    }
    return 0;
}
