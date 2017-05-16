#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 1000005

int n,m;
char s[MAXN];
int f[MAXN];

int getFail()
{
    int len = strlen(s);
    f[0] = f[1] = 0;
    for(int i = 1; i<len; i++)
    {
        int j = f[i];
        while(j && s[i] != s[j])
            j = f[j];
        f[i+1] = s[i] == s[j] ? j+1 : 0;
    }
    return len;
}

int Min(int len)
{
    int i = 0,j = 1,k = 0;
    while(i<len && j<len && k<len)
    {
        if(s[(i+k)%len] == s[(j+k)%len])    //构成回环
            k++;
        else
        {
            if(s[(i+k)%len] > s[(j+k)%len])
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

int Max(int len)
{
    int i = 0,j = 1,k = 0;
    while(i<len && j<len && k<len)
    {
        if(s[(i+k)%len] == s[(j+k)%len])
            k++;
        else
        {
            if(s[(i+k)%len] < s[(j+k)%len])
                i = max(i+k+1,j);
            else
                j = max(j+k+1,i);
            if(i == j)
                j++;
            k = 0;
        }
    }
    return min(i,j);
}

int main()
{
    while(~scanf("%s",s))
    {
        memset(f,0,sizeof(f));
        int len = getFail();
        int t = 1;
        if(len % (len - f[len]) == 0)
            t = len / (len - f[len]);
        int mmin = Min(len);
        int mmax = Max(len);
        printf("%d %d %d %d\n",mmin+1,t,mmax+1,t);
    }
    return 0;
}
