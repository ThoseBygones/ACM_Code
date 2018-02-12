/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2018-02-12
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: HDU
 *  Algorithm: 位运算 / 递归
 ********************************************************************************
 *  Algo-Description:
 ********************************************************************************
 */

#include <iostream>
#include <cstdio>
using namespace std;

#define MAXN 70
#define LL long long

LL pow2[MAXN];

int main()
{
    pow2[0]=1;
    for(int i=1; i<65; i++)
        pow2[i]=pow2[i-1]<<1;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,x;
        scanf("%d%d",&n,&x);
        printf("%I64d\n",pow2[n-x]);
    }
    return 0;
}
