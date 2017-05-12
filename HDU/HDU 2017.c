#include<stdio.h>
#include<string.h>
int main()
{
    char str[1000];
    int n,i,j,x;
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        scanf("%s",str);
        x=0;
        for(j=0; j<=strlen(str); j++)
        {
            if(str[j]>=48&&str[j]<=57)  //if(str[j]>='0'&&str[j]<'9')
                x=x+1;
        }
        printf("%d\n",x);
    }
    return 0;
}
