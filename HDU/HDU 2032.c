#include<stdio.h>
int main()
{
    int i,j,k,n,a[30][30],b[2];
    k=0;
    while(scanf("%d",&b[k])!=EOF)
    {
        for(i=0; i<=b[k]-1; i++)
        {
            for(j=0; j<=b[k]-1; j++)
            {
                a[i][0]=1;
                a[i][j]=1;
            }
        }
        for(i=2; i<=b[k]-1; i++)
            for(j=1; j<=i-1; j++)
                a[i][j]=a[i-1][j-1]+a[i-1][j];
        for(i=0; i<=b[k]-1; i++)
        {
            for(j=0; j<=i; j++)
            {
                if(i==j)
                    printf("%d",a[i][j]);
                else
                    printf("%d ",a[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }

    return 0;
}
