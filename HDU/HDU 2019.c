#include<stdio.h>
int main()
{
    int m,n,i,j,temp,arr[200];
    int sort(int m);
    while(scanf("%d %d",&n,&m)!=EOF&&n!=0&&m!=0)
    {
        for(i=0; i<n; i++)
            scanf("%d",&arr[i]);
        arr[n]=m;
        for(i=0; i<n; i++)
        {
            if(m<arr[i])
            {
                for(j=n; j>=i; j--)
                    arr[j+1]=arr[j];
                arr[i]=m;
                break;
            }
        }
        for(i=0; i<n+1; i++)
            if(i==n)
                printf("%d\n",arr[i]);
            else
                printf("%d ",arr[i]);
    }
    return 0;
}
