#include <bits/stdc++.h>
#define LL long long
using namespace std;

#define MAXN 105

int main()
{
    int n,m,k;
    while(~scanf("%d%d%d",&n,&m,&k))
    {
        int temp;
        if(k%(2*m)==0)
        {
            printf("%d %d R\n",k/(2*m),m);
            continue;
        }
        int x=k%(2*m);
        if(x%2==1)
            printf("%d %d L\n",k/(2*m)+1,x/2+1);
        else
            printf("%d %d R\n",k/(2*m)+1,x/2);
    }
    return 0;
}
