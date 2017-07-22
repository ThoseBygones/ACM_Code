#include <bits/stdc++.h>
using namespace std;

#define MAXN 105

int a[MAXN],b[MAXN];

int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    int cnt=0;
    int p=-1;
    for(int i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
        if(a[i]==0)
        {
            cnt++;
            p=i;
        }
    }
    for(int i=0; i<k; i++)
        scanf("%d",&b[i]);
    if(cnt>=2)
        puts("Yes");
    else
    {
        bool flag=false;
        a[p]=b[0];
        for(int i=1; i<n; i++)
        {
            if(a[i-1]>a[i])
            {
                flag=true;
                break;
            }
        }
        if(flag)
            puts("Yes");
        else
            puts("No");
    }
    return 0;
}
