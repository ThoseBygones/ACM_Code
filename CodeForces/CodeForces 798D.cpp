//二维贪心
/*
对于二维的贪心我们可以先让它变成其中一维有序，然后考虑另一维如何贪心。
正确性：
对于数组b，除了按照数组a从大到小排序后先选的第一个大小难说外，之后两两一组每一组选择的都是b大的，而且还有多选的，所以选择数组b中的元素和一定比剩下的元素和大。
对于数组a，从第一个开始看，每一组当前选择的一定比下一组剩下的a大（因为有序）。
*/
#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005

struct Node
{
    int val;
    int id;
} a[MAXN],b[MAXN];

bool cmp(Node x,Node y)
{
    return x.val>y.val;
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++) //将a数组从大到小排序
    {
        scanf("%d",&a[i].val);
        a[i].id=i;
    }
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&b[i].val);
        b[i].id=i;
    }
    sort(a+1,a+1+n,cmp);
    vector <int> ans;
    printf("%d\n",n/2+1);
    ans.push_back(a[1].id); //然后选择第一个
    for(int i=2; i<=n; i+=2)    //每两个一组，选择b大的一个
    {
        if(i<n)
        {
            if(b[a[i].id].val<b[a[i+1].id].val)
                ans.push_back(a[i+1].id);
            else
                ans.push_back(a[i].id);
        }
        else    //如果n是偶数再选择最后一个
            ans.push_back(a[i].id);
    }
    for(int i=0; i<ans.size(); i++)
    {
        if(i==0)
            printf("%d",ans[i]);
        else
            printf(" %d",ans[i]);
    }
    puts("");
    return 0;
}
