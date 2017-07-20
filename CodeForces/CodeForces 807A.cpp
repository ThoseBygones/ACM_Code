#include <bits/stdc++.h>
using namespace std;

#define MAXN 1005

int a[MAXN],b[MAXN];

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
        scanf("%d%d",&a[i],&b[i]);
    for(int i=1; i<=n; i++)
    {
        if(a[i]!=b[i])
        {
            puts("rated");
            return 0;
        }
    }
    for(int i=2; i<=n; i++)
    {
        if(a[i]>a[i-1] || b[i]>b[i-1])
        {
            puts("unrated");
            return 0;
        }
    }
    puts("maybe");
    return 0;
}
