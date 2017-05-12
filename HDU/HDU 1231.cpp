#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int a[10005];

int main()
{
    int n;
    while(~scanf("%d",&n),n)
    {
        for(int i=0; i<n; i++)
            scanf("%d",&a[i]);
        int l=a[0],r=a[0];
        int Max=a[0];
        int sum=0;
        int p=0;    //¶¯Ì¬Ö¸Õë
        for(int i=0; i<n; i++)
        {
            if(sum>=0)
                sum+=a[i];
            else
            {
                sum=a[i];
                p=a[i];
            }
            if(sum>Max)
            {
                Max=sum;
                l=p;
                r=a[i];
            }
        }
        if(Max<0)
            printf("0 %d %d\n",a[0],a[n-1]);
        else
            printf("%d %d %d\n",Max,l,r);
    }
    return 0;
}
