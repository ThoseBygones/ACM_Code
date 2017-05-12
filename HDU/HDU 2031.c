#include<stdio.h>
#include<math.h>
int main()
{

    int n,r,i,k,m,t;
    char a[10000]={'\0'};
    char c[6]={'A','B','C','D','E','F'};
    while(scanf("%d %d",&n,&r)!=EOF)
    {
        t=abs(n);
        i=0;
        while(t>=r)
        {
            a[i]=t%r+48;
            t=t/r;
            i++;
        }
        k=i;
        a[k]=t+48;
        for(i=0; i<=k; i++)
        {
            m=a[i];
            if(m>=58&&m<=63)
                a[i]=a[i]+7;
        }
        if(n<0)
            printf("-");
        for(i=k; i>=0; i--)
            printf("%c",a[i]);
        printf("\n");
    }
    return 0;
}
