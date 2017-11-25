#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005
#define LL long long

int main()
{
    int n;
    scanf("%d",&n);
    LL temp;
    LL a=0,b=0,c=0;
    for(int i=0; i<n; i++)
    {
        scanf("%I64d",&temp);
        a+=temp;
    }
    for(int i=0; i<n-1; i++)
    {
        scanf("%I64d",&temp);
        b+=temp;
    }
    for(int i=0; i<n-2; i++)
    {
        scanf("%I64d",&temp);
        c+=temp;
    }
    printf("%I64d\n%I64d\n",a-b,b-c);
    return 0;
}
