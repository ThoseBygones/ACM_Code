#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005

int a[MAXN];

int cmp(int a,int b)
{
    return a>b;
}

int main()
{
    int n,n1,n2;
    scanf("%d%d%d",&n,&n1,&n2);
    for(int i=1; i<=n; i++)
        scanf("%d",&a[i]);
    sort(a+1,a+n+1,cmp);
    if(n1>n2)
        swap(n1,n2);
    double sum1=0.0,sum2=0.0;
    for(int i=1; i<=n1; i++)
        sum1+=1.0*a[i];
    for(int i=n1+1; i<=n1+n2; i++)
        sum2+=1.0*a[i];
    sum1/=n1;
    sum2/=n2;
    printf("%.8f",sum1+sum2);
    return 0;
}
