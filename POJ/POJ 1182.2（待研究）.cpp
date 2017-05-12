#include <iostream>
#include <cstdio>
using namespace std;

int N,K;
int pre[50010*3];
int chi[50010*3];

int find(int x)
{
    if(x!=pre[x])
        pre[x]=find(pre[x]);
    return pre[x];
}

int main()
{
    scanf("%d%d",&N,&K);
    {
        for(int i=1; i<=N*3; i++)
            pre[i]=i;

        for(int i=1; i<=N; i++)
            chi[i]=i+N,chi[i+N]=i+2*N,chi[i+2*N]=i;

        int cmd,a,b;
        int ans=0;
        while(K--)
        {
            scanf("%d%d%d",&cmd,&a,&b);

            if(a>N||b>N)
            {
                ans++;
                continue;
            }

            int x[3],y[3];
            x[0]=find(a),y[0]=find(b);
            x[1]=chi[x[0]],x[2]=chi[x[1]];
            y[1]=chi[y[0]],y[2]=chi[y[1]];

            int flag=0;
            for(int i=0; i<3; i++)
                if(x[0]==y[i])
                    flag=1;

            if(cmd==1)
            {
                if(flag)
                {
                    if(x[0]!=y[0])
                        ans++;
                }
                else
                    for(int i=0; i<3; i++)
                        pre[y[i]]=x[i];
            }
            if(cmd==2)
            {
                if(a==b)
                {
                    ans++;
                    continue;
                }
                if(flag)
                {
                    if(chi[y[0]]!=x[0])
                        ans++;
                }
                else
                    for(int i=0; i<3; i++)
                        pre[y[i]]=x[(i+2)%3];
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
