#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000005

int h[MAXN];

int main()
{
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1; i<=m; i++)
    {
        int temp;
        scanf("%d",&temp);
        h[temp]=1;
    }
    bool flag=true; //是否还可移动
    int pos=1;
    for(int i=1; i<=k; i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        if(flag)
        {
            if(h[pos])
            {
                flag=false;
                break;
            }
            if(u==pos)
                pos=v;
            else if(v==pos)
                pos=u;
            //cout << pos << endl;
        }
    }
    printf("%d\n",pos);
    return 0;
}
