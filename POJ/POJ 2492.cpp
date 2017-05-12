#include<iostream>
#include<cstdio>
using namespace std;

int par[2005],oth[2005];

int find_set(int r)
{
    if(r!=par[r])
        return par[r]=find_set(par[r]);
    return r;
}

void merge_set(int x,int y)
{
    int xx=find_set(x);
    int yy=find_set(y);
    par[yy]=xx;
}

int main()
{
    int n,num,kase,a,b;
    cin >> n;
    for(int i=1; i<=n; i++)
    {
        scanf("%d %d",&num,&kase);
        for(int j=1; j<=num; j++)
        {
            par[j]=j;
            oth[j]=0;
        }
        int flag=0;
        for(int j=1; j<=kase; j++)
        {
            scanf("%d %d",&a,&b);
            if(flag==0)
            {
                if(find_set(a)==find_set(b))
                    flag=1;
                else
                {
                    if(oth[a]!=0)
                        merge_set(oth[a],b);
                    else if(oth[b]!=0)
                        merge_set(oth[b],a);
                    else
                    {
                        oth[a]=b;
                        oth[b]=a;
                    }
                }
            }
        }
        printf("Scenario #%d:\n",i);
        if(flag)
            printf("Suspicious bugs found!\n",i);
        else
            printf("No suspicious bugs found!\n",i);
        if(i!=n)
            cout << endl;
    }
    return 0;
}


//重做代码：
//0 -- 子节点跟父节点性别相同
//1 -- 子节点跟父节点性别不同
#include <iostream>
#include <cstdio>
#define MAXN 2005
using namespace std;

int par[MAXN],rela[MAXN];

int findset(int r)
{
    if(r!=par[r])
    {
        int temp=par[r];
        par[r]=findset(par[r]);
        rela[r]=(rela[r]+rela[temp]+1)%2;
    }
    return par[r];
}

void unionset(int x,int y)
{
    int xx=findset(x);
    int yy=findset(y);
    par[xx]=yy;
    rela[xx]=(rela[y]-rela[x])%2;
}

int main()
{
    int t,n,m;
    scanf("%d",&t);
    for(int k=1; k<=t; k++)
    {
        scanf("%d%d",&n,&m);
        bool flag=false;
        for(int i=1; i<=n; i++)
        {
            par[i]=i;
            rela[i]=1;
        }
        int x,y;
        for(int i=0; i<m; i++)
        {
            scanf("%d%d",&x,&y);
            if(findset(x)==findset(y))
            {
                if(rela[x]==rela[y])
                    flag=true;
            }
            else
                unionset(x,y);
        }
        if(flag)
            printf("Scenario #%d:\nSuspicious bugs found!\n\n",k);
        else
            printf("Scenario #%d:\nNo suspicious bugs found!\n\n",k);
    }
    return 0;
}
