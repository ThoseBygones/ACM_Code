#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int N,A,B,i;
int que[10010];
int vis[10010];
int step[10010];
int K[10010];

int main()
{
    while(scanf("%d",&N)!=EOF&&N!=0)
    {
        int first=0,stop=0;
        scanf("%d %d",&A,&B);
        for(i=1; i<N+1; i++)
            scanf("%d",&K[i]);
        memset(vis,0,sizeof(vis));
        memset(step,0,sizeof(step));
        que[stop++]=A;
        while(first<stop)
        {
            int temp=que[first++];
            if(temp==B)
                break;
            if(temp+K[temp]<=N&&temp+K[temp]>0&&vis[temp+K[temp]]==0)
            {
                vis[temp+K[temp]]=1;
                que[stop++]=temp+K[temp];
                step[temp+K[temp]]=step[temp]+1;
            }
            if(temp-K[temp]>0&&temp-K[temp]<=N&&vis[temp-K[temp]]==0)
            {
                vis[temp-K[temp]]=1;
                que[stop++]=temp-K[temp];
                step[temp-K[temp]]=step[temp]+1;
            }
        }
        if(step[B]==0)
        {
            if(A!=B)
                cout<<"-1"<<endl;
            else
                cout<<"0"<<endl;
        }
        else
            cout<<step[B]<<endl;
    }
    return 0;
}
