#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 5005

int dir[MAXN];  //牛现在的方向，0-朝前，1-朝后
int mark[MAXN]; //区间i~i+k-1是否进行过反转
int n;

int work(int k)
{
    memset(mark,0,sizeof(mark));
    int cnt=0;
    int flip=0;
    for(int i=0; i+k-1<n; i++)
    {
        if((dir[i]+flip)&1)  //奇数，说明改变需要反转一下
        {
            cnt++;
            mark[i]=1;
        }
        flip+=mark[i];
        if(i-k+1>=0)    //k覆盖范围外的前面的排除
            flip-=mark[i-k+1];
    }
    //检查后面的牛有没有都面朝前方
    for(int i=n-k+1; i<n; i++)
    {
        if((dir[i]+flip)&1) //还有没有面朝前面的，则无解
            return -1;
        if(i-k+1>=0)
            flip-=mark[i-k+1];
    }
    return cnt;
}

int main()
{
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        char s[2];
        scanf("%s",s);
        if(s[0]=='F')
            dir[i]=0;
        else
            dir[i]=1;
    }
    int m=n;
    int k;
    for(int i=1; i<=n; i++)
    {
        int ans=work(i);
        if(ans!=-1 && ans<m)
        {
            m=ans;
            k=i;
        }
    }
    printf("%d %d\n",k,m);
    return 0;
}
