#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005

int good[30];
char s[MAXN];
char a[MAXN];
char b[MAXN];

int main()
{
    int q;
    memset(good,0,sizeof(good));
    scanf("%s",s);
    int lens=strlen(s);
    for(int i=0; i<lens; i++)
        good[s[i]]=1;
    scanf("%s",a);
    int lena=strlen(a);
    scanf("%d",&q);
    while(q--)
    {
        scanf("%s",b);
        int lenb=strlen(b);
        bool flag=true;
        int i=0,j=0;    //a,b两串的指针
        while(j<lenb)
        {
            if(a[i]=='*')
            {
                for(int k=0; k<lenb-lena+1; k++)
                {
                    if(good[b[j]])
                    {
                        flag=false;
                        break;
                    }
                    j++;
                }
                i++;
            }
            else
            {
                if((a[i]=='?' && good[b[j]]) || a[i]==b[j]) //匹配
                {
                    i++;
                    j++;
                }
                else
                {
                    flag=false;
                    break;
                }
            }
        }
        if(i<lena && (lena-lenb>1 || a[lena-1]!='*'))   //a串指针还没到头，原因如果是因为a串仅比b串长超过1且a[lena-1]不是'*'，则说明不匹配
            flag=false;
        if(flag)
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}
