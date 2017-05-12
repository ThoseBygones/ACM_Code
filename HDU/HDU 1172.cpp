#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

#define MAXN 105

struct group
{
    int a;
    int b;
    int c;
} g[MAXN];

bool judge(int i,int number)
{
    int num1[5],num2[5],vis[5],cnt;
    num1[1]=g[i].a/1000;
    num1[2]=g[i].a/100%10;
    num1[3]=g[i].a/10%10;
    num1[4]=g[i].a%10;

    num2[1]=number/1000;
    num2[2]=number/100%10;
    num2[3]=number/10%10;
    num2[4]=number%10;

    memset(vis,0,sizeof(vis));
    cnt=0;
    for(int j=1; j<=4; j++)
    {
        if(num1[j]==num2[j])
            cnt++;
    }
    if(cnt!=g[i].c)
        return false;

    cnt=0;
    for(int j=1; j<=4; j++)
    {
        for(int k=1; k<=4; k++)
        {
            if(num1[j]==num2[k] && vis[k]==0)
            {
                cnt++;
                vis[k]=1;
                break;
            }
        }
    }
    if(cnt!=g[i].b)
        return false;
    return true;
}

int main()
{
    int n,record;
    while(~scanf("%d",&n)&&n)
    {
        for(int i=1; i<=n; i++)
            scanf("%d %d %d",&g[i].a,&g[i].b,&g[i].c);
        int cnt=0;
        bool flag=true;
        for(int num=1000; num<=9999; num++)
        {
            for(int i=1; i<=n; i++)
            {
                flag=judge(i,num);
                if(!flag)
                    break;
            }
            if(flag)
            {
                cnt++;
                record=num;
            }
        }
        if(cnt==1)
            printf("%d\n",record);
        else
            printf("Not sure\n");
    }
    return 0;
}
