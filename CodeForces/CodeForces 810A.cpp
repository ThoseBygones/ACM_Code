#include <bits/stdc++.h>
using namespace std;

#define MAXN 105

int a[MAXN];

int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    double sum=0.0;
    for(int i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
        sum+=1.0*a[i];
    }
    double avg=(k-0.5)*n;
    int cnt=0;
    while(sum<avg)
    {
        sum+=k;
        avg+=k-0.5;
        cnt++;
    }
    printf("%d\n",cnt);
    return 0;
}
