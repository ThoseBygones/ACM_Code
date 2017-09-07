#include <bits/stdc++.h>
using namespace std;

#define MAXN 1005

char s[10];

int main()
{
    scanf("%s",s);
    int ans=6;
    for(int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++)
        {
            for(int k=0; k<10; k++)
            {
                for(int p=0; p<10; p++)
                {
                    for(int q=0; q<10; q++)
                    {
                        for(int r=0; r<10; r++)
                        {
                            if(i+j+k==p+q+r)
                            {
                                int cnt=0;
                                if(s[0]-'0'!=i)
                                    cnt++;
                                if(s[1]-'0'!=j)
                                    cnt++;
                                if(s[2]-'0'!=k)
                                    cnt++;
                                if(s[3]-'0'!=p)
                                    cnt++;
                                if(s[4]-'0'!=q)
                                    cnt++;
                                if(s[5]-'0'!=r)
                                    cnt++;
                                ans=min(ans,cnt);
                            }
                        }
                    }
                }
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
