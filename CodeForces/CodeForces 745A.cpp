#include <bits/stdc++.h>
#define LL long long
using namespace std;

char str[55][55];

int main()
{
    scanf("%s",str[0]);
    int len=strlen(str[0]);
    int cnt=1;
    for(int i=1; i<len; i++)
    {
        str[i][0]=str[i-1][len-1];
        for(int j=1; j<len; j++)
            str[i][j]=str[i-1][j-1];
        bool flag=false;
        for(int j=0; j<i; j++)
        {
            if(strcmp(str[i],str[j])==0)
            {
                flag=true;
                break;
            }
        }
        if(!flag)
            cnt++;
    }
    printf("%d\n",cnt);
    return 0;
}
