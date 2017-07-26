#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    int kase=1;
    int m;
    while(~scanf("%d",&m))
    {
        double a=log(2);
        double b=log(10);
        int ans=floor(m*log(2)/log(10));
        printf("Case #%d: %d\n",kase++,ans);
    }
    return 0;
}
