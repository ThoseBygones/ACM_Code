#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005

int a[MAXN],b[MAXN];

int cmp(int a,int b)
{
    return a>b;
}

int main()
{
    int n,k;
    while(scanf("%d %d",&n,&k)!=EOF)
    {
        for(int i=0; i<n; i++)
        {
            scanf("%d",&a[i]);
            b[i]=a[i]%10;
            a[i]/=10;
        }
        sort(b,b+n,cmp);
        for(int i=0; i<n; i++)
        {
            if(10-b[i]<=k)
            {
                a[i]++;
                k-=10-b[i];
            }
        }
        int sum=0;
        for(int i=0; i<n; i++)
            sum+=a[i];
        printf("%d\n",min(sum+k/10,10*n));
    }
    return 0;
}
