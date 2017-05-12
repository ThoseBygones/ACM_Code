#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int par[50005];

int find_set(int r)
{
    if(r!=par[r])
        par[r]=find_set(par[r]);
    return par[r];
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
    int n,m,a,b,kase=0;
    while(~scanf("%d %d",&n,&m))
    {
        if(n==0 && m==0)
            break;
        for(int i=1;i<=n;i++)
            par[i]=i;
        for(int i=0;i<m;i++)
        {
            scanf("%d %d",&a,&b);
            merge_set(a,b);
        }
        int sum=0;
        for(int i=1;i<=n;i++)
        {
            if(par[i]==i)
                sum++;
        }
        kase++;
        printf("Case %d: %d\n",kase,sum);
    }
    return 0;
}
