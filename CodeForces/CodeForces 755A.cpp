#include <bits/stdc++.h>
#define LL long long
using namespace std;

#define MAXN 1000005

int p[MAXN];

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=2; i<=MAXN; i++)
    {
        if(!p[i])
        {
            for(int j=i*2; j<=MAXN; j+=i)
                p[j]=1;
        }
    }
    for(int i=1; i<=1000; i++)
    {
        if(p[i*n+1])
        {
            printf("%d\n",i);
            return 0;
        }
    }
}
