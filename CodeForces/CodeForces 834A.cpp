#include <bits/stdc++.h>
using namespace std;

#define MAXN 1005
#define LL long long

char cw[]= {'v','<','^','>'};

int main()
{
    char a,b;
    int n;
    scanf("%c %c",&a,&b);
    scanf("%d",&n);
    int x,y;
    for(int i=0; i<4; i++)
    {
        if(a==cw[i])
            x=i;
        if(b==cw[i])
            y=i;
    }
    if(n&1)
    {
        if((x-y+4)%4==n%4)
            puts("ccw");
        else
            puts("cw");
    }
    else
        puts("undefined");
    return 0;
}
