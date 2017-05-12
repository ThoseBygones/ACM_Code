#include<stdio.h>
int main()
{
    int m,n,i,method[50];
    scanf("%d",&n);
    method[0]=1;
    method[1]=2;
    for(i=2; i<40; i++)
        method[i]=method[i-1]+method[i-2];
    for(i=0; i<n; i++)
    {
        scanf("%d",&m);
        printf("%d\n",method[m-2]);
    }
    return 0;
}
