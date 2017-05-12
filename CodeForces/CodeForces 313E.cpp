#include <iostream>
#include <cstdio>
#include <stack>
#include <algorithm>
#define MAXN 100005
using namespace std;

int numa[MAXN],numb[MAXN];  //记录各数字在两个数字串中出现的次数
int ans[MAXN];  //记录答案的数组

stack <int> s;

int main()
{
    int n,m;
    int temp;
    cin >> n >> m;
    for(int i=0; i<n; i++)
    {
        scanf("%d",&temp);
        numa[temp%m]++;
    }
    for(int i=0; i<n; i++)
    {
        scanf("%d",&temp);
        numb[temp%m]++;
    }
    for(int k=0; k<2; k++)  //两次循环，第一次最佳匹配（凑出数字m-1），第二次匹配（凑出尽量接近m-1的数字）
    {
        for(int i=0; i<m; i++)
        {
            while(numa[i]>0)    //第一次匹配执行（第二次匹配不执行）
            {
                //cout << "a=" << i << endl;
                s.push(i);
                numa[i]--;
            }
            //cout << endl;
            while(s.size() && numb[m-i-1]>0)    //第一次匹配遇到能凑出数字m-1时执行，第二次匹配必定执行（最佳匹配剩下的数字）
            {
                ans[(m-i-1+s.top())%m]++;
                numb[m-i-1]--;
                //cout << "b=" << m-i-1 << endl;
                s.pop();
            }
        }
        //cout << "******round" << k+1 << "******" << endl;
    }
    for(int i=m-1; i>=0; i--)
    {
        while(ans[i]--)
            cout << i << " ";
    }
    cout << endl;
    return 0;
}
