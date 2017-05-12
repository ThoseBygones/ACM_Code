#include<iostream>
#include<algorithm>
using namespace std;

int net[55][55],par[55],n,r;

struct points
{
    int s;
    int e;
    int len;
} p[10005];

bool cmp(points a,points b)
{
    return a.len<b.len;
}

int findset(int r)
{
    if(r!=par[r])
        return par[r]=findset(par[r]);
    return r;
}

bool mergeset(int x,int y)
{
    int xx=findset(x);
    int yy=findset(y);
    if(xx!=yy)
    {
        par[yy]=xx;
        return true;
    }
    return false;
}

int kruskal()
{
    int cnt=0,sum=0;
    for(int i=1; i<=r; i++)
    {
        if(mergeset(p[i].s,p[i].e))
        {
            cnt++;
            sum+=p[i].len;
        }
        if(cnt==r-1)
            break;
    }
    return sum;
}

int main()
{
    while(cin >> n >> r)
    {
        if(n==0)
            break;
        for(int i=1; i<=n; i++)
            par[i]=i;
        for(int i=1; i<=r; i++)
            cin >> p[i].s >> p[i].e >> p[i].len;
        sort(p+1,p+r+1,cmp);
        int sum=kruskal();
        cout << sum << endl;
    }
    return 0;
}
