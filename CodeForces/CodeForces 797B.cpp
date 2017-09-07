#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005
#define INF 0x3f3f3f3f

int a[MAXN];

int main()
{
    int n;
    scanf("%d",&n);
    int sum=0;
    int Min=INF,Max=-INF;
    for(int i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
        if(a[i]>0)
        {
            sum+=a[i];
            if(a[i]&1)
                Min=min(a[i],Min);
        }
        else if(a[i]<0)
        {
            if(a[i]&1)
                Max=max(a[i],Max);
        }
    }
    if(sum&1)
        printf("%d\n",sum);
    else
        printf("%d\n",max(sum-Min,sum+Max));
    return 0;
}
