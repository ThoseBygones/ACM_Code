#include <bits/stdc++.h>
using namespace std;

#define MAXN 805

int ans[MAXN],vis[MAXN];

struct Scoreboard
{
    int a;
    int b;
    int score;
} s[MAXN*MAXN];

int cmp(Scoreboard a,Scoreboard b)
{
    return a.score>b.score;
}

int main()
{
    int n;
    int id=0;
    scanf("%d",&n);
    for(int i=2; i<=2*n; i++)
    {
        for(int j=1; j<i; j++)
        {
            scanf("%d",&s[id].score);
            s[id].a=j;
            s[id].b=i;
            id++;
        }
    }
    sort(s,s+id,cmp);
    for(int i=0; i<id; i++)
    {
        if(!vis[s[i].a] && !vis[s[i].b])
        {
            ans[s[i].a]=s[i].b;
            ans[s[i].b]=s[i].a;
            vis[s[i].a]=1;
            vis[s[i].b]=1;
        }
    }
    for(int i=1; i<2*n; i++)
        printf("%d ",ans[i]);
    printf("%d\n",ans[2*n]);
    return 0;
}
