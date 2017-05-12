#include <bits/stdc++.h>
using namespace std;

char a[100005];

int main()
{
    int n,x,y;
    scanf("%d%d%d",&n,&x,&y);
    scanf("%s",a+1);
    if(a[x]==a[y])
        puts("0");
    else
        puts("1");
    return 0;
}
