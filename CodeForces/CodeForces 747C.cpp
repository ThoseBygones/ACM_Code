#include <bits/stdc++.h>
using namespace std;

#define MAXN 105
#define MAXM 1000005

int t[MAXM],k[MAXM],d[MAXM];
int ser[MAXN];

int main()
{
    int n,q;
    scanf("%d%d",&n,&q);
    memset(ser,0,sizeof(ser));
    for(int i=1; i<=q; i++)
        scanf("%d%d%d",&t[i],&k[i],&d[i]);
    for(int i=1; i<=q; i++)
    {
        int work=0;
        for(int j=1; j<=n; j++)
        {
            if(ser[j]<t[i])
                work++;
        }
        if(work<k[i])
        {
            puts("-1");
            continue;
        }
        int idsum=0;
        work=0;
        for(int j=1; j<=n && work<k[i]; j++)
        {
            if(ser[j]<t[i])
            {
                work++;
                idsum+=j;
                ser[j]=t[i]+d[i]-1;
            }
        }
        printf("%d\n",idsum);
    }
    return 0;
}
