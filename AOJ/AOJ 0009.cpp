#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

#define MAXN 1000005

int a[MAXN];

void judgePrime()
{
    int m=sqrt(MAXN);
    memset(a,0,sizeof(a));
    for(int i=2; i<=m; i++)
    {
        if(!a[i])
        {
            for(int j=i*i; j<MAXN; j+=i)
                a[j]=1;
        }
    }
}

int main()
{
    judgePrime();
    int n;
    while(~scanf("%d",&n))
    {
        int cnt=0;
        for(int i=2; i<=n; i++)
        {
            if(!a[i])
                cnt++;
        }
        printf("%d\n",cnt);
    }
    return 0;
}
