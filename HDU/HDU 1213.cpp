#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int par[1005];

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
    int t,n,m,a,b;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
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
        cout << sum << endl;
    }
    return 0;
}
