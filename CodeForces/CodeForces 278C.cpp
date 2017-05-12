#include <bits/stdc++.h>
#define LL long long
using namespace std;

#define MAXN 105

struct Employees
{
    int lang[MAXN];
} e[MAXN];

int fa[MAXN];
int n,m;

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
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; i++)
        fa[i]=i;
    int no=0;   //一种语言都不会的人数
    for(int i=1; i<=n; i++)
    {
        int num,temp;
        scanf("%d",&num);
        if(num==0)
            no++;
        while(num--)
        {
            scanf("%d",&temp);
            e[i].lang[temp]=1;
        }
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=i+1; j<=n; j++)
        {
            for(int k=1; k<=m; k++)
            {
                if(e[i].lang[k] && e[j].lang[k])
                {
                    unionset(i,j);
                    //cout << i << "-" << j << endl;
                    break;
                }
            }
        }
    }
    int cnt=0;
    for(int i=1; i<=n; i++)
    {
        if(fa[i]==i)
            cnt++;
    }
    if(no==n)   //所有人都是一种语言都不会
        printf("%d\n",cnt);
    else
        printf("%d\n",cnt-1);
    return 0;
}
