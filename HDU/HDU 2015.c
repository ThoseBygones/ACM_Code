#include<stdio.h>
int main()
{
    int i,j,k,m,n,a[100],b[100],num,sum;
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        for(i=0; i<n; i++)
            a[i]=2*(i+1);
        num=n/m;
        k=0;
        for(j=0; j<num; j++)
        {
            sum=0;
            for(i=k; i<k+m; i++)
                sum=sum+a[i];
            b[j]=sum/m;
            k=k+m;
        }
        if(n%m!=0)
        {
            for(i=k; i<k+n%m; i++)
            {
                sum=0;
                sum=sum+a[i];
                b[num]=sum/(n%m);
            }
            for(j=0; j<=num; j++)
            {
                if(j==num)
                    printf("%d\n",b[j]);
                else
                    printf("%d ",b[j]);
            }
        }
        else
            for(j=0; j<num; j++)
            {
                if(j==num-1)
                    printf("%d\n",b[j]);
                else
                    printf("%d ",b[j]);
            }
    }
}
