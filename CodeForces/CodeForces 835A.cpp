#include <bits/stdc++.h>
using namespace std;

#define MAXN 1005
#define LL long long

int main()
{
    int s,v1,v2,t1,t2;
    scanf("%d%d%d%d%d",&s,&v1,&v2,&t1,&t2);
    int res1=t1*2+s*v1;
    int res2=t2*2+s*v2;
    if(res1<res2)
        puts("First");
    else if(res1>res2)
        puts("Second");
    else
        puts("Friendship");
    return 0;
}
