#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

#define PII pair <int,int>

vector <pair <int,int> > v;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int h,w;
    scanf("%d%d",&h,&w);
    if(h<2 || w<2)
    {
        puts("0");
        return 0;
    }
    if(h%2==0)
    {
        for(int i=1; i<=h-1; i+=2)  //行间不交错
        {
            for(int j=1; j<=w-2; j++)   //最后一列不放
                v.push_back(make_pair(i,j));
        }
        for(int i=1; i<=h-1; i++)  //补上交错放的最后一列
            v.push_back(make_pair(i,w-1));
    }
    else if(w%2==0)
    {
        for(int i=1; i<=w-1; i+=2)  //列间不交错
        {
            for(int j=1; j<=h-2; j++)   //最后一行不放
                v.push_back(make_pair(j,i));
        }
        for(int i=1; i<=w-1; i++)   //补上交错放的最后一行
            v.push_back(make_pair(h-1,i));
    }
    else
    {
        for(int i=1; i<=w-1; i+=2)  //第一行列间先不交错放
            v.push_back(make_pair(1,i));
        for(int i=2; i<=h-1; i+=2)   //相当于化行数为偶数，从第二行开始列间交错放
        {
            for(int j=1; j<=w-2; j++)   //最后一列不放
                v.push_back(make_pair(i,j));
        }
        for(int i=2; i<=h-1; i++)   //第一行不放（否则第一行最后一张就只剩左上角了
            v.push_back(make_pair(i,w-1));  //补上交错放的最后一列
    }
    int ans=v.size();
    printf("%d\n",ans);
    for(int i=0; i<v.size(); i++)
        printf("%d %d\n",v[i].first,v[i].second);
    return 0;
}
