#include <bits/stdc++.h>
using namespace std;

#define MAXN 10005
#define LL long long

int p[MAXN];
int c[MAXN];

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=2; i<=n; i++)
        scanf("%d",&p[i]);
    for(int i=1; i<=n; i++)
        scanf("%d",&c[i]);
    int cnt=0;
    for(int i=1; i<=n; i++)
    {
        if(c[i]!=c[p[i]])
            cnt++;
    }
    printf("%d\n",cnt);
    return 0;
}
