#include <bits/stdc++.h>
using namespace std;

#define MAXN 1005

//不超过1e5的数异或最大不会超过131071(2^17-1)

int main()
{
    int n,x;
    scanf("%d%d",&n,&x);
    if(n==2 && x==0)    //两个相同的数异或才能等于0
    {
        puts("NO");
        return 0;
    }
    puts("YES");
    if(n==1)
        printf("%d\n",x);
    else if(n==2)
        printf("%d 0\n",x);
    else
    {
        int xsum=0;
        for(int i=1; i<=n-3; i++)
        {
            printf("%d ",i);
            xsum^=i;
        }
        int temp1=(1<<17);
        int temp2=(1<<18);
        printf("%d %d %d\n",temp1,temp2,(temp1^temp2^xsum^x));
    }
    return 0;
}
