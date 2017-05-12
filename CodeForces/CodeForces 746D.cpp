#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005

//vector <char> v;

int main()
{
    int n,k,a,b;
    scanf("%d%d%d%d",&n,&k,&a,&b);
    int x,y;
    char p='G',q='B';
    if(a<b) //保证a始终大于b
    {
        swap(a,b);
        swap(p,q);
    }
    x=a/(b+1);
    y=x+(a%(b+1)?1:0);
    if(y>k)
    {
        puts("NO");
        return 0;
    }
    for(int i=0; i<=b; i++)
    {
        if(i)
            printf("%c",q);
        int num=x+(a%(b+1)>i?1:0);
        for(int j=1; j<=num; j++)
            printf("%c",p);
    }
    puts("");
    return 0;
}
