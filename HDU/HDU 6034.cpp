#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 100005
#define MOD 1000000007
#define LL long long

struct Weight
{
    int a[MAXN];
    int len;
    bool flag;  //是否曾经在某个字符串中以前导出现
    void init()
    {
        memset(a,0,sizeof(a));
        len=0;
        flag=false;
    }
} wei[26];

char s[MAXN];
int index[27];

bool cmp(int x,int y)
{
    if(wei[x].len==wei[y].len)
    {
        for(int i=wei[x].len; i>0; i--)
        {
            if(wei[x].a[i]==wei[y].a[i])
                continue;
            if(wei[x].a[i]>wei[y].a[i])
                return true;
            if(wei[x].a[i]<wei[y].a[i])
                return false;
        }
    }
    else if(wei[x].len>wei[y].len)
        return true;
    return false;
}

LL quickPow(LL x,LL k,LL mod)
{
    LL res = 1;
    while(k > 0)
    {
        if(k & 1)
            res = res * x % mod;
        x = x * x % mod;
        k >>= 1;
    }
    return res;
}

void add(char ch,int val)
{
    wei[ch-'a'].a[val]++;
    int p=val;
    while(wei[ch-'a'].a[p])
    {
        wei[ch-'a'].len=max(wei[ch-'a'].len,p);
        if(wei[ch-'a'].a[p]>=26)
        {
            wei[ch-'a'].a[p+1]+=wei[ch-'a'].a[p]/26;
            wei[ch-'a'].a[p]%=26;
        }
        p++;
    }
}

int main()
{
    int kase=1;
    int n;
    while(~scanf("%d",&n))
    {
        for(int i=0; i<26; i++)
            wei[i].init();
        for(int i=0; i<n; i++)
        {
            scanf("%s",s);
            int len=strlen(s);
            for(int j=0; j<len; j++)
                add(s[j],len-j);
            wei[s[0]-'a'].flag=true;
        }
        /*for(int i=0; i<=3; i++)
        {
            cout << "#" << wei[i].len << "#" << endl;
            for(int j=0; j<=7; j++)
                printf("%d ",wei[i].a[j]);
            puts("");
        }*/
        for(int i=0; i<26; i++)
            index[i]=i;
        sort(index,index+26,cmp);
        if(wei[index[25]].flag)
        {
            for(int i=24; i>=0; i--)
            {
                if(!wei[index[i]].flag)
                {
                    int temp=index[i];
                    for(int j=i+1; j<26; j++)
                        index[j-1]=index[j];
                    index[25]=temp;
                    break;
                }
            }
        }
        //for(int i=0; i<4; i++)
        //    cout << "#" << index[i] << endl;
        LL w=25;
        LL sum=0;
        for(int i=0; i<26; i++)
        {
            if(wei[index[i]].len==0)
                continue;
            for(int j=1; j<=wei[index[i]].len; j++)
            {
                sum=(sum+(wei[index[i]].a[j]*(w*quickPow(26,(LL)(j-1),MOD))%MOD)%MOD)%MOD;
            }
            w--;
        }
        printf("Case #%d: %lld\n",kase++,sum);
    }
    return 0;
}
