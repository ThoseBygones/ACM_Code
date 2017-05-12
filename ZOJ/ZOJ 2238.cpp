#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
using namespace std;

#define MAXN 100001

int edge[MAXN]; //相当于欧拉回路中的边
int s[MAXN*10];    //用数组模拟栈
char ans[MAXN*10];  //存放结果的数组
int stacksz;    //数组栈的大小
int anssz;  //结果数组的大小

void dfs(int x,int m)   //非递归的dfs
{
    int y;
    while(edge[x]<10)
    {
        y=x*10+edge[x];
        edge[x]++;
        s[stacksz++]=y;
        x=y%m;
    }
}

int main()
{
    int n,m,x;
    while(~scanf("%d",&n))
    {
        if(n==0)
            break;
        if(n==1)
        {
            printf("0123456789\n");
            continue;
        }
        stacksz=0;
        anssz=0;
        x=0;
        m=pow(10.0,n-1);
        memset(edge,0,sizeof(edge));
        dfs(x,m);
        while(stacksz)
        {
            x=s[--stacksz];
            ans[anssz++]=x%10+'0';
            x/=10;
            dfs(x,m);
        }
        for(int i=1; i<n; i++)
            printf("0");
        while(anssz)
            printf("%c",ans[--anssz]);
        printf("\n");
    }
    return 0;
}
