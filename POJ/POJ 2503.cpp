//STL map
#include <iostream>
#include <cstring>
#include <string>
#include <map>
#include <cstdio>
using namespace std;

int main()
{
    map <string,string> dic;
    char str1[12],str2[12],str[30];
    while(gets(str))
    {
        if(strlen(str)==0)
            break;
        sscanf(str,"%s %s",str1,str2);
        dic[str2]=str1;
    }
    string str3,ans;
    while(cin >> str3)
    {
        ans=dic[string(str3)];
        if(ans.length()==0)
            cout << "eh" << endl;
        else
            cout << ans << endl;
    }
    return 0;
}


//sort+二分查找
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 100005

int index;  //词典总条数

struct Words
{
    char e[15];
    char f[15];
} w[MAXN];

int cmp(Words a,Words b)
{
    if(strcmp(a.f,b.f)==-1)
        return 1;
    return 0;
}

int biSearch(char s[])
{
    int left=0,right=index-1;
    int mid;
    while(left<=right)
    {
        mid=(left+right)/2;
        int temp=strcmp(w[mid].f,s);
        if(temp==0)
            return mid;
        else if(temp==-1)
            left=mid+1;
        else
            right=mid-1;
    }
    return -1;
}

int main()
{
    char str[25];
    index=0;
    while(gets(str))
    {
        if(str[0]=='\0')
            break;
        sscanf(str,"%s%s",w[index].e,w[index].f);
        index++;
    }
    sort(w,w+index,cmp);
    //cout << cmp(w[3],w[4]) << endl;
    //cout << cmp(3,2) << endl;
    while(gets(str))
    {
        int val=biSearch(str);
        if(val==-1)
            puts("eh");
        else
            printf("%s\n",w[val].e);
    }
    return 0;
}


//ELFHash
