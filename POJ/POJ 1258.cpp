#include<iostream>
#include<cstring>
using namespace std;

#define INF 0x3f3f3f3f
int n,farm[105][105],vis[105];

int prim()
{
    int mmin,temp;
    int sum=0;
    vis[1]=1;
    for(int i=1; i<n; i++)
    {
        mmin=INF;
        for(int j=1; j<=n; j++)
        {
            if(vis[j])
            {
                for(int k=1; k<=n; k++)
                {
                    if(vis[k]==0 && farm[j][k]<mmin)
                    {
                        mmin=farm[j][k];
                        temp=k;
                    }
                }
            }
        }
        vis[temp]=1;
        sum+=mmin;
    }
    return sum;
}

int main()
{
    while(cin >> n)
    {
        memset(vis,0,sizeof(vis));
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                cin >> farm[i][j];
        int sum=prim();
        cout << sum << endl;
    }
    return 0;
}
