#include<stdio.h>
#include<math.h>
int main()
{
    int m,n,x,y,s,i,j,t,b,c;
    while(scanf("%d %d",&m,&n)!=EOF)
    {
        int a[100][100];
        for(i=0; i<m; i++)
            for(j=0; j<n; j++)
                scanf("%d",&a[i][j]);
        t=a[0][0];
        b=0;
        c=0;
        for(i=0; i<m; i++)
            for(j=0; j<n; j++)
                if(abs(t)<abs(a[i][j]))
                {
                    t=a[i][j];
                    b=i;
                    c=j;
                }
        printf("%d %d %d\n",b+1,c+1,t);
    }
    return 0;
}
