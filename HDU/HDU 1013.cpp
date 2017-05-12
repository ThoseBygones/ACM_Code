#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

char str[1005];

int main()
{
    while(scanf("%s",str)!=EOF)
    {
        int sum=0;
        if(str[0]=='0')
            break;
        for(int i=0;str[i]!='\0';i++)
        {
            sum+=str[i]-'0';
            if(sum>9)
                sum=sum/10+sum%10;
        }
        cout << sum << endl;
    }
    return 0;
}
