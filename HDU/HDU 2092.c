#include<stdio.h>
int main()
{
    int A,B,i,T,sum;
    scanf("%d",&T);
    for(i=0; i<T; i++)
    {
        scanf("%d %d",&A,&B);
        if(A>=100)
        A=A%100;
        if(B>=100)
        B=B%100;
        sum=(A+B)%100;
        printf("%d\n",sum);
    }
    return 0;
}
