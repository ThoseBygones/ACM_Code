#include<stdio.h>
int main()
{
    int m,n,x,i,j,a,b,c,arr[1000];
    while(scanf("%d %d",&m,&n)!=EOF)
    {
        i=0;
        for(x=m; x<=n; x++)
        {
            a=x/100;
            b=x%100/10;
            c=x%10;
            if(x==a*a*a+b*b*b+c*c*c)
            {
                arr[i]=x;
                i++;
            }
        }
        j=i;
        i=0;
        if(j==0)
            printf("no");
        else
            for(i=0; i<j; i++)
                if(i==j-1)
                    printf("%d",arr[i]);
                else
                    printf("%d ",arr[i]);
        printf("\n");
    }
    return 0;
}
