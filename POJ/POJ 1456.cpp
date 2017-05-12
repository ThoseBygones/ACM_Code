#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int par[10005];

struct products
{
    int p;
    int d;
} pro[10005];

int find_set(int r)
{
    while(par[r]==-1)
        return r;
    return par[r]=find_set(par[r]);
}

int cmp(products a,products b)
{
    return a.p>b.p;
}

int main()
{
    int n;
    while(cin >> n)
    {
        memset(par,-1,sizeof(par));
        for(int i=0;i<n;i++)
            cin >> pro[i].p >> pro[i].d;
        sort(pro,pro+n,cmp);
        int sum=0;
        for(int i=0;i<n;i++)
        {
            int t=find_set(pro[i].d);
            if(t>0)
            {
                sum+=pro[i].p;
                par[t]=t-1;
            }
        }
        cout << sum << endl;
    }
    return 0;
}

//ÖØÐ´´úÂë£º
#include <iostream>
#include <algorithm>
#define MAXN 10005
using namespace std;

int par[MAXN];

struct Product
{
    int p;
    int d;
} pro[MAXN];

bool cmp(Product a,Product b)
{
    return a.p>b.p;
}

int findset(int r)
{
    if(r!=par[r])
        par[r]=findset(par[r]);
    return par[r];
}

int main()
{
    int n;
    while(cin >> n)
    {
        int maxp=0;
        for(int i=0; i<=10000; i++)
            par[i]=i;
        for(int i=0; i<n; i++)
            cin >> pro[i].p >> pro[i].d;
        sort(pro,pro+n,cmp);
        for(int i=0; i<n; i++)
        {
            int root=findset(pro[i].d);
            if(root>0)
            {
                par[root]=root-1;
                maxp+=pro[i].p;
            }
        }
        cout << maxp << endl;
    }
    return 0;
}
