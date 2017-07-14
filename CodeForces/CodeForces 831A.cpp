#include <bits/stdc++.h>
#define LL long long
using namespace std;

#define MAXN 105

int a[MAXN];

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
        scanf("%d",&a[i]);
    if(n==1)
        puts("YES");
    else
    {
        int flag=1;
        for(int i=2; i<=n; i++)
        {
            if(flag==1 && a[i-1]==a[i])
                flag=0;
            else if(flag==1 && a[i-1]>a[i])
                flag=-1;
            if(flag==-1 && a[i-1]<=a[i])
            {
                puts("NO");
                return 0;
            }
            else if(flag==0)
            {
                if(a[i-1]<a[i])
                {
                    puts("NO");
                    return 0;
                }
                else if(a[i-1]>a[i])
                    flag=-1;
            }
        }
        puts("YES");
    }
    return 0;
}
