#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

char board[10][10];
int vis[10];
int n,k,num,c;

void dfs(int i)
{
    if(k==num)
    {
        c++;
        return ;
    }
    if(i>=n)
        return;

    for(int j=0; j<n; j++)
    {
        if(vis[j]==0 && board[i][j]=='#')
        {
            vis[j]=1;
            num++;
            dfs(i+1);
            vis[j]=0;
            num--;
        }
    }
    dfs(i+1);
}

int main()
{
    while(scanf("%d %d",&n,&k))
    {
        if(n==-1 && k==-1)
            break;
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                cin >> board[i][j];
        memset(vis,0,sizeof(vis));
        c=0;
        num=0;
        dfs(0);
        cout << c << endl;
    }
    return 0;
}
