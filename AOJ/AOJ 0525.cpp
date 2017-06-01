#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <bitset>
using namespace std;

bitset <10000> b[10];
int n,m;
int ans;

void dfs(int col)   //行上一共有2^n种变换
{
    if(col==n)
    {
        int sum=0;
        for(int j=0; j<m; j++)
        {
            int cnt=0;
            for(int i=0; i<n; i++)
            {
                if(b[i][j])
                    cnt++;
            }
            sum+=max(cnt,n-cnt);    //每列不需要直接翻转，只需要比较一下0和1的数量哪个多（如果0多就列翻转一下）
        }
        ans=max(ans,sum);
        return ;
    }
    //行不翻转
    dfs(col+1);
    //行翻转
    b[col].flip();
    dfs(col+1);
    b[col].flip();  //还原现场
}

int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        if(n==0 && m==0)
            break;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                bool temp;
                scanf("%d",&temp);
                b[i][j]=temp;
            }
        }
        ans=0;
        dfs(0);
        printf("%d\n",ans);
    }
    return 0;
}
