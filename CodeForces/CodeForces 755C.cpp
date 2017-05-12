#include <bits/stdc++.h>
#define LL long long
using namespace std;

#define MAXN 10005

int fa[MAXN];
int n;

int findset(int x)
{
    if(x!=fa[x])
        return fa[x]=findset(fa[x]);
    return fa[x];
}

void unionset(int x,int y)
{
    int xx=findset(x);
    int yy=findset(y);
    if(xx!=yy)
        fa[xx]=yy;
}

int main()
{
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
        fa[i]=i;
    for(int i=1; i<=n; i++)
    {
        int temp;
        scanf("%d",&temp);
        unionset(i,temp);
    }
    int cnt=0;
    for(int i=1; i<=n; i++)
    {
        if(fa[i]==i)
            cnt++;
    }
    printf("%d\n",cnt);
    return 0;
}
