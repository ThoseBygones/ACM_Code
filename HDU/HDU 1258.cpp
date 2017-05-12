#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int num[15],ans[15],t,n,flag,sum;

int cmp(int a,int b)
{
    return a>b;
}

void dfs(int posa,int posb,int sum)
{
    if(sum>t)
        return ;
    if(sum==t)
    {
        flag=1;
        for(int i=0;i<posb;i++)
        {
            if(i)
                printf("+%d",ans[i]);
            else
                printf("%d",ans[i]);
        }
        cout << endl;
    }
    for(int i=posa;i<n;i++)
    {
        ans[posb]=num[i];
        dfs(i+1,posb+1,sum+num[i]);
        while(i+1<n && num[i]==num[i+1])
            i++;
    }
}

int main()
{
    while(scanf("%d %d",&t,&n),t||n)
    {
        for(int i=0;i<n;i++)
            scanf("%d",&num[i]);
        sort(num,num+n,cmp);
        printf("Sums of %d:\n",t);
        flag=0;
        dfs(0,0,0);
        if(!flag)
        {
            printf("NONE\n");
        }
    }
    return 0;
}
