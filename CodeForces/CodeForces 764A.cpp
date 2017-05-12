#include <bits/stdc++.h>
using namespace std;

int gcd(int a,int b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}

int main()
{
    int n,m,z;
    scanf("%d%d%d",&n,&m,&z);
    int x=n*m/gcd(n,m);
    printf("%d\n",z/x);
    return 0;
}
