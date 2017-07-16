#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    int a,b;
    while(~scanf("%d%d",&a,&b))
    {
        int x=__gcd(a,b);
        int y=a/x*b;
        printf("%d %d\n",x,y);
    }
    return 0;
}
