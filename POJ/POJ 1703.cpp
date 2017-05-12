#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int par[100050],enemy[100050];

int find_set(int x)
{
    if(x==par[x])
        return x;
    else
        par[x]=find_set(par[x]);
    return par[x];
}

void merge_set(int x,int y)
{
    int setx,sety;
    setx=find_set(x);
    sety=find_set(y);
    if(setx!=sety)
        par[sety]=setx;
}

int main()
{
    int t,n,m,i,a,b;
    char mes;
    scanf("%d",&t);
    while(t--)
    {
        memset(enemy,0,sizeof(enemy));
        scanf("%d %d",&n,&m);
        for(i=1; i<=n; i++)
            par[i]=i;
        for(i=1; i<=m; i++)
        {
            getchar();
            scanf("%c %d %d",&mes,&a,&b);
            if(mes=='D')
            {
                if(enemy[a])
                    merge_set(enemy[a],b);
                if(enemy[b])
                    merge_set(enemy[b],a);
                enemy[a]=b;
                enemy[b]=a;
            }
            else
            {
                if(find_set(a)==find_set(enemy[b]))
                    printf("In different gangs.\n");
                else if(find_set(a)==find_set(b))
                    printf("In the same gang.\n");

                else
                    printf("Not sure yet.\n");
            }
        }
    }
    return 0;
}
