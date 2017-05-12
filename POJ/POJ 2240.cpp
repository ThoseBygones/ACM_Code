//Bellman-FordÀ„∑®£∫
#include <iostream>
#include <map>
#include <cstring>
#include <string>
#include <algorithm>
#define MAXN 35
using namespace std;

struct Exchange
{
    int u;
    int v;
    double r;
} rate[MAXN*MAXN];

double dis[MAXN];
int n,m;

map <string,int> cur;

bool Bellman_Ford()
{
    for(int k=1; k<=n; k++)
    {
        memset(dis,0,sizeof(dis));
        dis[k]=1.0;
        for(int i=1; i<=n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(dis[rate[j].u]*rate[j].r>dis[rate[j].v])
                    dis[rate[j].v]=dis[rate[j].u]*rate[j].r;
                //cout << dis[rate[j].v] << endl;
            }
        }
        if(dis[k]>1.0)
            return true;
    }
    return false;
}

int main()
{
    int kase=1;
    while(cin >> n)
    {
        if(n==0)
            break;
        cur.clear();
        memset(rate,0,sizeof(rate));
        string str;
        for(int i=1; i<=n; i++)
        {
            cin >> str;
            cur[str]=i;
        }
        cin >> m;
        for(int i=0; i<m; i++)
        {
            string u,v;
            double r;
            cin >> u >> r >> v;
            rate[i].u=cur[u];
            rate[i].v=cur[v];
            rate[i].r=r;
        }
        if(Bellman_Ford())
        {
            cout << "Case " << kase++ << ": Yes" << endl;
            continue;
        }
        else
        {
            cout << "Case " << kase++ << ": No" << endl;
            continue;
        }
    }
    return 0;
}


//FloydÀ„∑®£∫
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<map>
using namespace std;

#define INF 0x3f3f3f3f

int n,m;
map<string,int> mp;

double rate;
string str,str1,str2;
double dis[35][35];

void floyd()
{
    for(int k=1; k<=n; k++)
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(dis[i][j]<dis[i][k]*dis[k][j])
                    dis[i][j]=dis[i][k]*dis[k][j];
            }
        }
    }
}

int main()
{
    int kase=1;
    while(~scanf("%d",&n))
    {
        if(n==0)
            break;
        mp.clear();
        memset(dis,0,sizeof(dis));
        for(int i=1; i<=n; i++)
        {
            cin >> str;
            mp[str]=i;
            dis[i][i]=1;
        }
        cin >> m;
        for(int i=1; i<=m; i++)
        {
            cin >> str1 >> rate >> str2;
            dis[mp[str1]][mp[str2]]=rate;
        }
        floyd();
        int flag=0;
        for(int i=1; i<=n; i++)
        {
            if(dis[i][i]>1)
            {
                flag=1;
                break;
            }
        }
        if(flag)
            printf("Case %d: Yes\n",kase++);
        else
            printf("Case %d: No\n",kase++);
    }
    return 0;
}
