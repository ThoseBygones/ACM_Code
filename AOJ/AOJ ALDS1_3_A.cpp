#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;

stack <int> sta;
char s[15];

int main()
{
    while(~scanf("%s",s))
    {
        if(s[0]=='+')
        {
            int a=sta.top();
            sta.pop();
            int b=sta.top();
            sta.pop();
            sta.push(a+b);
        }
        else if(s[0]=='-')
        {
            int a=sta.top();
            sta.pop();
            int b=sta.top();
            sta.pop();
            sta.push(b-a);
        }
        else if(s[0]=='*')
        {
            int a=sta.top();
            sta.pop();
            int b=sta.top();
            sta.pop();
            sta.push(a*b);
        }
        else
            sta.push(atoi(s));
    }
    printf("%d\n",sta.top());
    return 0;
}
