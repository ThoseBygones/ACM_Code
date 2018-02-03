#include <bits/stdc++.h>
using namespace std;

#define MAXN 1005
#define LL long long

int main()
{
    int n,x;
    scanf("%d",&n);
    scanf("%d",&x);
    n--;
    int Max=x,Min=x;
    int cnt=0;
    for(int i=0; i<n; i++)
    {
        scanf("%d",&x);
        if(x>Max)
        {
            Max=x;
            cnt++;
        }
        if(x<Min)
        {
            Min=x;
            cnt++;
        }
    }
    printf("%d\n",cnt);
    return 0;
}
