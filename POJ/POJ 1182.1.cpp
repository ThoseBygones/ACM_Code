#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int par[50005],cate[50005];

int find_set(int r)
{
    if(r!=par[r])
    {
        int root=find_set(par[r]);
        cate[r]=(cate[r]+cate[par[r]])%3;
        par[r]=root;
    }
    return par[r];
}

bool merge_set(int x,int y,int mes)
{
    int setx,sety;
    setx=find_set(x);
    sety=find_set(y);
    if(setx==sety)
    {
        if( (cate[y]-cate[x]+3)%3!=mes-1 )
            return true;
        return false;
    }
    par[sety]=setx;
    cate[sety]=(cate[x]-cate[y]+mes+2)%3;
    return false;
}

int main()
{
    int n,k,sum,d,x,y;
    scanf("%d %d",&n,&k);
    for(int i=1; i<=n; i++)
        par[i]=i;
    memset(cate,0,sizeof(cate));
    sum=0;
    while(k--)
    {
        scanf("%d %d %d",&d,&x,&y);
        if(x>n || y>n || (d==2 && x==y))    //判断假话条件2和3
            sum++;
        else if(merge_set(x,y,d))    //判断假话条件1
            sum++;
    }
    printf("%d\n",sum);
    return 0;
}

//重写的代码
//0 -- 子节点和父节点是同类
//1 -- 子节点被父节点吃
//2 -- 父节点被子节点吃
#include <iostream>
#include <cstdio>
#define MAXN 50005
using namespace std;

int par[MAXN],rela[MAXN];
int n,m;
int cnt;

int findset(int r)
{
    if(r!=par[r])
    {
        int temp=par[r];
        par[r]=findset(temp);
        rela[r]=(rela[r]+rela[temp])%3;
    }
    return par[r];
}

void mergeset(int x,int y,int r)
{
    int xx=findset(x);
    int yy=findset(y);
    if(xx==yy)
    {
        if((rela[x]-rela[y]+3)%3!=r-1)
            cnt++;
    }
    else
    {
        par[xx]=yy;
        rela[xx]=(rela[y]+r-1-rela[x]+3)%3;
    }
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0; i<=n; i++)
    {
        par[i]=i;
        rela[i]=0;
    }
    for(int i=0; i<m; i++)
    {
        int r,x,y;
        scanf("%d%d%d",&r,&x,&y);
        if(x>n || y>n)
        {
            cnt++;
            continue;
        }
        if(r==2 && x==y)
        {
            cnt++;
            continue;
        }
        mergeset(x,y,r);
    }
    printf("%d\n",cnt);
    return 0;
}
