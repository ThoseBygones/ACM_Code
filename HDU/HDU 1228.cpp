#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;

int number(char m[])
{
    char str0[]="zero";
    char str1[]="one";
    char str2[]="two";
    char str3[]="three";
    char str4[]="four";
    char str5[]="five";
    char str6[]="six";
    char str7[]="seven";
    char str8[]="eight";
    char str9[]="nine";
    if(strcmp(m,str0)==0)
        return 0;
    else if(strcmp(m,str1)==0)
        return 1;
    else if(strcmp(m,str2)==0)
        return 2;
    else if(strcmp(m,str3)==0)
        return 3;
    else if(strcmp(m,str4)==0)
        return 4;
    else if(strcmp(m,str5)==0)
        return 5;
    else if(strcmp(m,str6)==0)
        return 6;
    else if(strcmp(m,str7)==0)
        return 7;
    else if(strcmp(m,str8)==0)
        return 8;
    else if(strcmp(m,str9)==0)
        return 9;
}

int main()
{
    char count[10];
    int a,b;
    while(1)
    {
        a=0;
        while(scanf("%s",count)&&strcmp(count,"+"))
            a = a*10+number(count);
        b=0;
        while(scanf("%s",count)&&strcmp(count,"="))
            b = b*10+number(count);
        if(a==0&&b==0)
            return 0;
        else
            cout<<a+b<<endl;
    }
    return 0;
}
