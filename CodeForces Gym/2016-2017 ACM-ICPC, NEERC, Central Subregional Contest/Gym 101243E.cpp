#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

#define LL long long
#define MAXN 100005

int stu[MAXN];

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,k;
    scanf("%d%d",&n,&k);
    LL L=0,R=0;
    int Max=0;
    int p=0;
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&stu[i]);
        R+=stu[i];
        if(stu[i]>Max)
        {
            p=i;
            Max=stu[i];
        }
    }
    for(int i=1; i<p; i++)
        L+=stu[i];
    LL left=p-1;    //Greedy Guy֮ǰ��ÿһ�������ٳ�һ��cupcake
    LL right=L; //���
    //cout << right << endl;
    while(left<=k)
    {
        if(k<=right)    //���ں����������Greedy Guy��ɨս��
        {
            puts("YES");
            return 0;
        }
        left+=n-1+stu[p];
        //cout << left << endl;
        right+=R;   //����ֻ�����һ���Ժ�ķ�Χ
    }
    puts("KEK");
    return 0;
}
