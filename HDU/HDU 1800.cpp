//Hash+map
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

char str[3005][35];

int cmp(const void *a,const void *b)
{
    return strcmp((char*)a,(char*)b);
}

int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        //char s[35];
        for(int i=0; i<n; i++)
        {
            scanf("%s",str[i]);
            int j;
            for(j=0; ; j++)
            {
                if(str[i][j]!='0')
                    break;
            }
            strcpy(str[i],str[i]+j);
        }
        qsort(str,n,sizeof(str[0]),cmp);
        int cnt=0;
        int ans=0;
        for(int i=1; i<n; i++)
        {
            if(strcmp(str[i],str[i-1])==0)
                cnt++;
            else
            {
                ans=max(cnt,ans);
                cnt=0;
            }
        }
        ans=max(ans,cnt);
        printf("%d\n",ans+1);
    }
    return 0;
}
