#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

#define INF 0x3f3f3f3f

int a[15],b[15];
int vis[15];
int cnt,ans;

void check(int x)
{
    int len=0;
    int y=0;
    for(int i=0; i<cnt; i++)
    {
        if(!vis[i])
        {
            b[len++]=a[i];
            y=y*10+a[i];
        }
    }
    if(b[0]!=0 || len==1)   //数字就是0或者数字非前导零的情况
        ans=min(ans,abs(x-y));
    while(next_permutation(b,b+len))    //枚举全排列
    {
        y=0;
        for(int i=0; i<len; i++)
            y=y*10+b[i];
        if(b[0]!=0 || len==1)
            ans=min(ans,abs(x-y));
    }
}

void dfs(int step,int num)  //相当于枚举a组的全排列
{
    if(step==cnt/2)
    {
        check(num);
        return ;
    }
    else
    {
        for(int i=0; i<cnt; i++)
        {
            if(!vis[i])
            {
                if(a[i]==0 && step==0 && cnt>3)   //数字非零不允许前导零的存在
                    continue;
                vis[i]=1;
                dfs(step+1,num*10+a[i]);
                vis[i]=0;
            }
        }
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    getchar();
    while(t--)
    {
        cnt=0;
        char temp;
        while((temp=getchar())!='\n')
        {
            if(temp==' ')
                continue;
            a[cnt++]=temp-'0';
        }
        ans=INF;
        memset(vis,0,sizeof(vis));
        dfs(0,0);
        printf("%d\n",ans);
    }
    return 0;
}
