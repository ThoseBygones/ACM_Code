#include<stdio.h>
#include<math.h>
int main()
{
    int n,i,j,x,y,value,a[100],ok;
    while(scanf("%d %d",&x,&y)!=EOF)
    {
        if(x==0&&y==0)
            break;
        else
        {
            n=x;
            for(i=0; i<y-x+1; i++,n++)
            {
                value=n*n+n+41;
                a[i]=value;
            }
            ok=0;
            for(i=0; i<=y-x; i++)
            {
                for(j=2; j<=sqrt(a[i]); j++)
                {
                    if(a[i]%j==0)
                        ok=ok+1;
                }
            }
            if(ok==0)
                printf("OK\n");
            else
                printf("Sorry\n");
            /*for(i=0; i<=y-x; i++)
                printf("%d ",a[i]);
                printf("\n");*/
        }
    }
    return 0;
}
