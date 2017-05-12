#include <iostream>
#include <cstring>
#include <cstdio>
#include <map>
using namespace std;

char str[105];
map <char,int> alpha;
char vowel[]= {'a','e','i','o','u'};

int main()
{
    int t;
    scanf("%d",&t);
    getchar();
    while(t--)
    {
        gets(str);
        alpha.clear();
        int len=strlen(str);
        for(int i=0; i<len; i++)
            alpha[str[i]]++;
        for(int i=0; i<5; i++)
            printf("%c:%d\n",vowel[i],alpha[vowel[i]]);
        if(t)
            puts("");
    }
    return 0;
}
