#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int a=n*2;
    int b=m*3;
    for(int i=6; i<=min(a,b); i+=6)
    {
        if(a>b)
            b+=3;
        else
            a+=2;
    }
    printf("%d\n",max(a,b));
    return 0;
}
