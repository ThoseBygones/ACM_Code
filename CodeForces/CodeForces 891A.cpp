#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 2005

int a[MAXN];

int main()
{
    int n;
    scanf("%d",&n);
    int cnt=0;
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&a[i]);
        if(a[i]==1)
            cnt++;
    }
    if(cnt)
    {
        printf("%d",n-cnt);
        return 0;
    }
    bool flag=false;
    int step=0;
    for(int i=1; i<n; i++)
    {
        for(int j=1; j<n; j++)
        {
            int temp=__gcd(a[j],a[j+1]);
            a[j]=temp;
            if(temp==1)
            {
                flag=true;
                step=i;
                break;
            }
        }
        if(flag)
            break;
    }
    if(step)
        printf("%d\n",step+n-1);
    else
        puts("-1");
    return 0;
}
