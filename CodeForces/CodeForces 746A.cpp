#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    int n=min(a,min(b/2,c/4));
    printf("%d\n",n*7);
    return 0;
}
