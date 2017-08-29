#include <bits/stdc++.h>
using namespace std;

#define MAXN 1005
#define LL long long

LL n,k;
vector <LL> v1,v2;

void Print(LL val)
{
    LL sum=0;
    for(LL i=1; i<k; i++)
    {
        sum+=i*val;
        printf("%I64d ",i*val);
    }
    printf("%I64d\n",n-sum);
}

int main()
{
    scanf("%I64d%I64d",&n,&k);
    if(k>100000000)
    {
        puts("-1");
        return 0;
    }
    LL sum=(k+1)*k/2;
    for(LL i=1; i*i<=n; i++)
    {
        if(n%i==0)
        {
            v1.push_back(i);
            v2.push_back(n/i);
        }
    }
    int sz=v2.size();
    for(int i=0; i<sz; i++)
    {
        if(n/v2[i]>=sum)
        {
            Print(v2[i]);
            return 0;
        }
    }
    sz=v1.size();
    for(int i=sz-1; i>=0; i--)
    {
        if(n/v1[i]>=sum)
        {
            Print(v1[i]);
            return 0;
        }
    }
    puts("-1");
    return 0;
}
