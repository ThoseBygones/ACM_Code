#include <bits/stdc++.h>
using namespace std;

#define MAXN 1005

int a[MAXN];

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
        scanf("%d",&a[i]);
    if(n%2==0 || a[1]%2==0 || a[n]%2==0)
        puts("No");
    else
        puts("Yes");
    return 0;
}
