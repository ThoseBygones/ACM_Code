#include <bits/stdc++.h>
#define LL long long
using namespace std;

#define INF 0x3f3f3f3f
#define MAXN 100005

int p[MAXN];

int main()
{
    int n;
    scanf("%d",&n);
    //for(int i=1; i<=n; i++)
    //    p[i]=i+1;
    if(n>2)
        puts("2");
    else
        puts("1");
    for(int i=2; i<=n+1; i++)
    {
        if(!p[i])
        {
            p[i]=1;
            for(int j=i*2; j<=n+1; j+=i)
                p[j]=2;
        }
    }
    for(int i=2; i<=n+1; i++)
        printf("%d ",p[i]);
    printf("\n");
    return 0;
}
