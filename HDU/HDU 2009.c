#include<stdio.h>
#include<math.h>
int main()
{
    int m,n,i;
    float t,a[1000],sum;
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        t=n;
        a[0]=t;
        for(i=1; i<m; i++)
            a[i]=sqrt(a[i-1]);
        sum=0;
        for(i=0; i<m; i++)
            sum=sum+a[i];
        printf("%.2f\n",sum);
    }
    return 0;
}
