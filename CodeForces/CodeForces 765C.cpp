#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define LL long long
using namespace std;

#define MAXN 105

int k,a,b;

int main()
{
    scanf("%d%d%d",&k,&a,&b);
    if(a<k && b<k)
    {
        puts("-1\n");
        return 0;
    }
    if((a%k && b<k) || (a<k) && (b%k))
    {
        puts("-1\n");
        return 0;
    }
    printf("%d\n",(a/k)+(b/k));
    return 0;
}
