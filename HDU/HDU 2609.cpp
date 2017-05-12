#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 10005

struct String
{
    char s[105];
} str[MAXN];

int n,m;

bool cmp(String a,String b)
{
    return strcmp(a.s,b.s) < 1 ? true : false;
}

int getMin(char *q,int len)
{
    int i = 0,j = 1,k = 0;
    while(i<len && j<len && k<len)
    {
        if(q[(i+k)%len] == q[(j+k)%len])    //构成回环
            k++;
        else
        {
            if(q[(i+k)%len] > q[(j+k)%len])
                i = max(i+k+1,j);
            else
                j = max(j+k+1,i);
            if(i == j)
                j++;
            k = 0;
        }
        //cout << i << "#" << j << endl;
    }
    return min(i,j);
}

int main()
{
    while(~scanf("%d",&n))
    {
        for(int i=0; i<n; i++)
        {
            char temp[MAXN];
            scanf("%s",temp);
            int len=strlen(temp);
            int p=getMin(temp,len);
            strcpy(str[i].s,temp+p);
            temp[p]='\0';
            strcpy(str[i].s+len-p,temp);
            //cout << str[i].s << endl;
        }
        sort(str,str+n,cmp);
        int ans=1;
        for(int i=1; i<n; i++)
        {
            if(strcmp(str[i-1].s,str[i].s)!=0)
                ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
