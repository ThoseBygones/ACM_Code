#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
using namespace std;

char str[1005];
set <char> ele;

int main()
{
    ele.clear();
    gets(str);
    int len=strlen(str);
    for(int i=0; i<len; i++)
    {
        if(str[i]>='a' && str[i]<='z')
            ele.insert(str[i]);
    }
    cout << ele.size() << endl;
    return 0;
}
