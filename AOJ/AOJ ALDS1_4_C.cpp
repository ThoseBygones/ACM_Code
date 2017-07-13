#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>  //1320ms
//#include <unordered_map>  //800ms
#include <string>
using namespace std;

map <string,int> Hash;
//unordered_map <string,int> Hash;

int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    while(n--)
    {
        string temp,str;
        cin >> temp >> str;
        if(temp=="insert")
            Hash[str]++;
        else if(temp=="find")
        {
            if(Hash[str])
                cout << "yes" << endl;
            else
                cout << "no" << endl;
        }
    }
    return 0;
}


//190ms TAT
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

#define LL long long
#define MOD 1046527
#define NIL (-1)
#define LEN 14

char Hash[MOD][LEN];

int getChar(char ch)
{
    if(ch == 'A')
        return 1;
    else if(ch == 'C')
        return 2;
    else if(ch == 'G')
        return 3;
    else if(ch == 'T')
        return 4;
    else
        return 0;
}

LL getKey(char str[])
{
    LL sum = 0;
    LL p = 1;
    for(LL i=0; i<strlen(str); i++)
    {
        sum += p * (getChar(str[i]));
        p *= 5;
    }
    return sum;
}

int hash1(int key)
{
    return key % MOD;
}

int hash2(int key)
{
    return 1 + (key % (MOD - 1));
}

int findstr(char str[])
{
    LL key;
    LL h;
    key = getKey(str);
    for(LL i=0; ; i++)
    {
        h = (hash1(key) + i * hash2(key)) % MOD;
        if(strcmp(Hash[h],str) == 0)
            return 1;
        else if(strlen(Hash[h]) == 0)
            return 0;
    }
    return 0;
}

int insertstr(char str[])
{
    LL key;
    LL h;
    key = getKey(str);
    for(LL i=0; ; i++)
    {
        h = (hash1(key) + i * hash2(key)) % MOD;
        if(strcmp(Hash[h],str) == 0)
            return 1;
        else if(strlen(Hash[h]) == 0)
        {
            strcpy(Hash[h],str);
            return 0;
        }
    }
    return 0;
}

int main()
{
    int n,h;
    char str[LEN],com[9];
    for(int i=0; i<MOD; i++)
        Hash[i][0] = '\0';
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        scanf("%s %s",com,str);
        if(com[0] == 'i')
            insertstr(str);
        else
        {
            if(findstr(str))
                printf("yes\n");
            else
                printf("no\n");
        }
    }
    return 0;
}
