#include<stdio.h>
#include<string.h>
int main()
{
    char str[100];
    int i;
    while(gets(str)!=NULL)
    {
        for(i=0; i<strlen(str); i++)
        {
            if(i==0||str[i-1]==' ')
                str[i]=str[i]-32;
            else
                str[i]=str[i];
        }
        puts(str);
    }
    return 0;
}
