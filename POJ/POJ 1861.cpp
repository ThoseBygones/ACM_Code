#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int par[1005],record[1005][2],maxlen;

struct network
{
    int s;
    int e;
    int len;
} net[15010];

bool cmp(network a,network b)
{
    return a.len < b.len;
}

int find_set(int r)
{
    if(r!=par[r])
        par[r]=find_set(par[r]);
    return par[r];
}

bool merge_set(int x,int y,int length)
{
    int setx,sety;
    setx=find_set(x);
    sety=find_set(y);
    if(setx==sety)
        return false;
    par[sety]=setx;
    maxlen=max(maxlen,length);
    return true;
}

int main()
{
    int n,m;
    while(cin >> n >> m)
    {
        maxlen=0;
        for(int i=1; i<=n; i++)
            par[i]=i;
        for(int i=0; i<m; i++)
        {
            scanf("%d %d %d",&net[i].s,&net[i].e,&net[i].len);
        }
        sort(net,net+m,cmp);
        int solve=0;
        for(int i=0; i<m; i++)
        {
            if(merge_set(net[i].s,net[i].e,net[i].len))
            {
                record[solve][0]=net[i].s;
                record[solve][1]=net[i].e;
                solve++;
            }
        }
        cout << maxlen << endl;
        cout << solve << endl;
        for(int i=0; i<solve; i++)
            cout << record[i][0] << ' ' << record[i][1] << endl;
    }
    return 0;
}
