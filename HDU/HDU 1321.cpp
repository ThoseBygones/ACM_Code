#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
    char str[80];
    int n,i;
    cin >> n;
    getchar();
    while(n--)
    {
        gets(str);
        int len=strlen(str);
        for(int i=len-1;i>=0;i--)
            printf("%c",str[i]);
        cout << endl;
    }
    return 0;
}
