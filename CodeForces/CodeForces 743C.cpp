#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,x,y;
    scanf("%d",&n);
    bool flag=false;
    for(int i=n+1; i<n*2; i++)
    {
        y=n*i/__gcd(n,i);
        if(y/i+1==y/n)
        {
            x=i;
            flag=true;
            break;
        }
    }
    if(flag)
        printf("%d %d %d\n",n,x,y);
    else
        puts("-1");
    return 0;
}
