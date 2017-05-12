#include <bits/stdc++.h>
#define LL long long
using namespace std;

#define MAXN 105
#define INF 1e18

LL n,m,k,x,y;
LL seats[MAXN][MAXN];

int main()
{
    cin >> n >> m >> k >> x >> y;
    if(n==1)
    {
        LL r=k/m;
        if(k%m)
            cout << r+1;
        else
            cout << r;
        cout << " " << r << " ";
        if(k%m>=y)
            cout << r+1 << endl;
        else
            cout << r << endl;
        return 0;
    }
    memset(seats,0,sizeof(seats));
    LL l=k%((2*n-2)*m);   //一个周期是(2*n-2)*m
    LL r=k/((2*n-2)*m);
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(i==1 || i==n)    //每一轮第1排和第n排只会被叫到一次
                seats[i][j]+=r;
            else    //其他排会被叫到2次
                seats[i][j]+=r*2;
        }
    }
    //cout << l << endl;
    LL p=1,q=1;
    LL temp;
    while(l>0)
    {
        seats[p][q]++;
        q++;
        if(q>m)
        {
            q=1;
            if(p==1)
                temp=1;
            if(p==n)
                temp=-1;
            p+=temp;
        }
        l--;
    }
    LL Max=-1,Min=INF;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            Max=max(Max,seats[i][j]);
            Min=min(Min,seats[i][j]);
        }
    }
    cout << Max << " " << Min << " " << seats[x][y] << endl;
    return 0;
}
