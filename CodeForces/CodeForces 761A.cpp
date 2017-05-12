#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    if(abs(a-b)<=1 && a+b!=0)
        puts("YES");
    else
        puts("NO");
    return 0;
}
