#include <bits/stdc++.h>
using namespace std;

#define MAXN 1005
#define LL long long

string sa="What are you doing at the end of the world? Are you busy? Will you save us?";
string sb="What are you doing while sending \"";
string sc="\"? Are you busy? Will you send \"";
string sd="\"?";
string ans="";

int lena,lenb,lenc,lend;
int idx;
LL len[55];

char dfs(int num,LL val)
{
    if(num<=idx && len[num]<val)
        return '.';
    else
    {
        if(num==0)
            return sa[val-1];
        else
        {
            if(val<=lenb)   //长度未超出b串
                return sb[val-1];
            val-=(LL)lenb;
            if(num>idx || val<=len[num-1])    //长度未超出bc串之间的递归串
                return dfs(num-1,val);
            val-=len[num-1];
            if(val<=lenc)   //长度未超出c串
                return sc[val-1];
            val-=(LL)lenc;
            if(num>idx || val<=len[num-1])  //长度未超出cd串之间的递归串
                return dfs(num-1,val);
            val-=len[num-1];
            return sd[val-1];   //长度未超出d串
        }
    }
}

int main()
{
    lena=sa.length();   //75
    lenb=sb.length();   //34
    lenc=sc.length();   //32
    lend=sd.length();   //2
    len[0]=lena;
    idx=0;
    while(len[idx]<=1e18)
    {
        idx++;
        len[idx]=2*len[idx-1]+lenb+lenc+lend;
    }
    int q;
    scanf("%d",&q);
    while(q--)
    {
        int n;
        LL k;
        scanf("%d%I64d",&n,&k);
        ans+=dfs(n,k);
    }
    cout << ans << endl;
    puts("");
    return 0;
}
