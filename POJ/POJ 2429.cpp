#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <ctime>
using namespace std;

typedef long long LL;

const int S=20; //随机算法判定次数，S越大，判错概率越小

int cnt=0;
LL factor[20];
LL r[20];
LL k;
int num;

//Miller_Rabin判断大数(2^63)是否是素数
//(a*b)%c
LL mult_mod(LL a,LL b,LL c)
{
    a%=c;
    b%=c;
    LL ret=0;
    while(b)
    {
        if(b&1)
        {
            ret+=a;
            ret%=c;
        }
        a<<=1;
        if(a>=c) a%=c;
        b>>=1;
    }
    return ret;
}

//(x^n)%mod
LL pow_mod(LL x,LL n,LL mod)
{
    if(n==1) return x%mod;
    x%=mod;
    LL ret=1;
    LL temp=x;
    while(n)
    {
        if(n&1) ret=mult_mod(ret,temp,mod);
        temp=mult_mod(temp,temp,mod);
        n>>=1;
    }
    return ret;
}

//check a^(n-1)==1(mod n)
bool check(LL a,LL n,LL x,LL t)
{
    LL ret=pow_mod(a,x,n);
    LL last=ret;
    for(int i=1; i<=t; i++)
    {
        ret=mult_mod(ret,ret,n);
        if(ret==1&&last!=1&&last!=n-1) return true; //二次探测排除Carmichael数
        last=ret;
    }
    if(ret!=1) return true;
    return false;
}

bool Miller_Rabin(LL n)
{
    if(n<2) return false;
    if(n==2) return true;
    if((n&1)==0) return false;
    LL x=n-1;
    LL t=0;
    while((x&1)==0)
    {
        x>>=1;
        t++;
    }
    for(int i=0; i<S; i++)
    {
        LL a=rand()%(n-1)+1;
        if(check(a,n,x,t)) return false;
    }
    return true;
}


//Pollard_rho
LL gcd(LL a,LL b)
{
    if(a==0)
        return 1;
    if(a<0)
        return gcd(-a,b);
    while(b)
    {
        LL t=a%b;
        a=b;
        b=t;
    }
    return a;
}

LL Pollard_rho(LL x,LL c)
{
    LL i=1,k=2;
    LL x0=rand()%x;
    LL y=x0;
    while(true)
    {
        i++;
        x0=(mult_mod(x0,x0,x)+c)%x;
        LL d=gcd(y-x0,x);
        if(d!=1&&d!=x) return d;
        if(y==x0) return x;
        if(i==k)
        {
            y=x0;
            k+=k;
        }
    }
}

//对n进行素因子分解
/*void findfac(LL n,int k)
{
	if(n==1) return ;
	if(Miller_Rabin(n))
	{
		factor[cnt++]=n;
		return ;
	}
	LL p=n;
	int c=k;
	while(p>=n)
		p=Pollard_rho(p,c--);
	findfac(p,k);
	findfac(n/p,k);
}
*/

//对n进行素因子分解
void findfac(LL n)
{
    if(Miller_Rabin(n))//素数
    {
        factor[cnt++]=n;
        return;
    }
    LL p=n;
    while(p>=n)
        p=Pollard_rho(p,rand()%(n-1)+1);
    findfac(p);
    findfac(n/p);
}

void dfs(LL val,LL pre,LL n)
{
    if(val>sqrt(n))
        return ;
    k=max(k,val);
    for(int i=pre; i<=num; i++)
        dfs(val*r[i],i+1,n);
}

int main()
{
    LL GCD,LCM;
    LL n;
    while(~scanf("%lld%lld",&GCD,&LCM))
    {
        if(GCD==LCM)
        {
            printf("%lld %lld\n",GCD,LCM);
            continue;
        }
        cnt=0;
        n=LCM/GCD;
        findfac(n);
        sort(factor,factor+cnt);
        num=0;
        for(int i=0; i<=100; i++)
            r[i]=1;
        r[num]=factor[0];
        for(int i=1; i<cnt; i++)
        {
            if(factor[i]==factor[i-1])
                r[num]=r[num]*factor[i];
            else
            {
                num++;
                r[num]=factor[i];
            }
        }
        k=1;
        dfs(1,0,n);
        printf("%lld %lld\n",GCD*k,GCD*(n/k));
    }
    return 0;
}
