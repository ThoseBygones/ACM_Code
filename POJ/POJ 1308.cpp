#include<iostream>
#include<cstdio>
using namespace std;

int par[1005];
bool flag[1005];

int find_set(int x)
{
    if(x!=par[x])
        return find_set(par[x]);
    return par[x];
}

void merge_set(int x,int y)
{
    x=find_set(x);
    y=find_set(y);
    if(x==y)
        return;
    par[y]=x;
}

int main()
{
    int x,y,count=1,node,i;
    while(scanf("%d %d",&x,&y)!=EOF)
    {
        if(x==-1&&y==-1)
            break;
        if(x==0&&y==0)
        {
            printf("Case %d is a tree.\n",count);
            count++;
            continue;
        }
        for(i=1; i<=1005; i++)
        {
            par[i]=i;
            flag[i]=false;
        }
        flag[x]=flag[y]=true;
        node=x;
        bool tree=true;
        if(x==y)
            tree=false;
        else
            merge_set(x,y);
        while(scanf("%d %d",&x,&y)&&x!=0)
        {
            flag[x]=flag[y]=true;
            if(find_set(x)==find_set(y))
                tree=false;
            merge_set(x,y);
        }
        for(i=1;i<=1005;i++)
        {
            if(flag[i]&&find_set(i)!=find_set(node))
                tree=false;
        }
        if(tree)
        {
            printf("Case %d is a tree.\n",count);
            count++;
        }
        else
        {
            printf("Case %d is not a tree.\n",count);
            count++;
        }
    }
    return 0;
}
