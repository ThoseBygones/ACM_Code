#include <bits/stdc++.h>
using namespace std;

#define MAXN 205

int a[MAXN];

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1; i<=2*n; i++)
        scanf("%d",&a[i]);
    sort(a+1,a+2*n+1);
    for(int i=1; i<=n; i++)
    {
        if(a[i]==a[n+1])
        {
            puts("NO");
            return 0;
        }
    }
    puts("YES");
    return 0;
}
