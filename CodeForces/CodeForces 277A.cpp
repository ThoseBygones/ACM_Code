#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int par[105],flag[105];

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
        par[setx]=sety;
}

int main()
{
    int n,m,k;
    while(~scanf("%d %d",&n,&m))
    {
        int sum=0;
        for(int i=1; i<=m; i++)
            par[i]=i;
        memset(flag,0,sizeof(flag));
        while(n--)
        {
            scanf("%d",&k);
            if(k==0)
                sum++;
            else
            {
                int root,lang;
                scanf("%d",&root);
                flag[root]=1;
                for(int j=1; j<k; j++)
                {
                    scanf("%d",&lang);
                    flag[lang]=1;
                    merge_set(root,lang);
                }
            }
        }
        int num=-1;
        for(int i=1; i<=m; i++)
        {
            if(flag[i]==1 && par[i]==i)
                num++;
        }
        if(num>0)
            sum+=num;
        cout << sum << endl;
    }
    return 0;
}
