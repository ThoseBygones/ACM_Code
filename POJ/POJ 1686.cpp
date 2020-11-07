/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-11-04
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: POJ
 *  Algorithm: 栈
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

const int MAXN = 85;

char str1[MAXN], str2[MAXN];
map<char, int> pri;

void init()
{
    pri['*'] = 2;
    pri['+'] = pri['-'] = 1;
    pri['('] = 0;
}

int cal(int a, int b, char op)
{
    if(op == '*')
        return a * b;
    if(op == '+')
        return a + b;
    if(op == '-')
        return a - b;
}

int solve(char *str)
{
    stack<char> op;
    char tmp[MAXN];
    int cnt = 0;
    for(int i = 0; i < strlen(str); i++)
    {
        if(str[i] == ' ')
            continue;
        if(isalpha(str[i]) || isdigit(str[i]))
            tmp[cnt++] = str[i];
        else
        {
            if(op.empty() || str[i] == '(')    //栈空或者为左括号
                op.push(str[i]);
            else if(str[i] == ')')  //为右括号
            {
                while(!op.empty() && op.top() != '(')
                {
                    tmp[cnt++] = op.top();
                    op.pop();
                }
                op.pop();  //弹出左括号
            }
            else    //为运算符号
            {
                while(!op.empty() && pri[str[i]] <= pri[op.top()])
                {
                    tmp[cnt++] = op.top();
                    op.pop();
                }
                op.push(str[i]);
            }
        }
    }
    while(!op.empty())
    {
        tmp[cnt++] = op.top();
        op.pop();
    }
    tmp[cnt] = '\0';
    //cout << tmp << endl;
    stack<int> num;
    for(int i = 0; i < strlen(tmp); i++)
    {
        if(isdigit(tmp[i])) //是数字
            num.push(tmp[i] - '0');
        else if(isalpha(tmp[i]))    //是字母，则该令其值为其ASCII码的值（任意赋值）
            num.push(tmp[i]);
        else
        {
            int b = num.top();
            num.pop();
            int a = num.top();
            num.pop();
            int c = cal(a, b, tmp[i]);
            num.push(c);
        }
    }
    return num.top();
}

int main()
{
    init();
    int t;
    scanf("%d", &t);
    getchar();
    while(t--)
    {
        gets(str1);
        gets(str2);
        int ans1 = solve(str1);
        int ans2 = solve(str2);
        puts(ans1 == ans2 ? "YES" : "NO");
    }
    return 0;
}
