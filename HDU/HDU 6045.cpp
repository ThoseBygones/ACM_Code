#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 80005

char a[MAXN],b[MAXN];

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,x,y;
        scanf("%d%d%d",&n,&x,&y);
        scanf("%s",a);
        scanf("%s",b);
        int same=0,dif=0;
        for(int i=0; i<n; i++)
        {
            if(a[i]==b[i])
                same++;
            else
                dif++;
        }
        if(dif>=abs(x-y) && same>=(x+y-n))
            puts("Not lying");
        else
            puts("Lying");
    }
    return 0;
}
