#include<iostream>
#include<algorithm>
using namespace std;

#define INF 0x3f3f3f3f
#define MAXN 1005
int city[MAXN][MAXN],near[MAXN],want[MAXN],a,b,c;

int main()
{
    int t,s,d;
    while(cin >> t >> s >> d)
    {
        for(int i=1; i<=1000; i++)
        {
            for(int j=1; j<=1000; j++)
                city[i][j]=INF;
            city[i][i]=0;
        }
        for(int i=1; i<=t; i++)
        {
            cin >> a >> b >> c;
                city[a][b]=city[b][a]=min(city[a][b],c);
        }
        for(int i=1; i<=s; i++)
            cin >> near[i];
        for(int i=1; i<=d; i++)
            cin >> want[i];

        for(int k=1; k<=1000; k++)
        {
            for(int i=1; i<=1000; i++)
            {
                if(city[i][k]!=INF)
                {
                    for(int j=1; j<=1000; j++)
                        city[i][j]=min(city[i][k]+city[k][j],city[i][j]);
                }
            }
        }
        int mmin=INF;
        for(int i=1; i<=s; i++)
        {
            for(int j=1; j<=d; j++)
                mmin=min(city[near[i]][want[j]],mmin);
        }
        cout << mmin << endl;
    }
    return 0;
}
