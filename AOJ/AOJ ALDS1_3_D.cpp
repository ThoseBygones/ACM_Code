#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;

#define MAXN 20005

int main()
{
    stack <int> s1;
    stack < pair<int,int> > s2; //first--该积水处当前面积，second--该积水目前的面积
    char str[MAXN];
    scanf("%s",str);
    int len=strlen(str);
    int sum=0;
    int cnt=0;
    for(int i=0; i<len; i++)
    {
        if(str[i]=='\\')
            s1.push(i);
        else if(str[i]=='/' && !s1.empty())
        {
            int j=s1.top(); //距离最近的'\'字符
            s1.pop();
            sum+=i-j;
            int temp=i-j;
            while(!s2.empty() && s2.top().first>j)  //累加的面积（'\'在最左端的'\'之后）
            {
                temp+=s2.top().second;
                s2.pop();
            }
            s2.push(make_pair(j,temp));
        }
    }
    vector <int> ans;
    while(!s2.empty())
    {
        ans.push_back(s2.top().second);
        s2.pop();
    }
    reverse(ans.begin(),ans.end());
    printf("%d\n",sum);
    printf("%d",ans.size());
    for(int i=0; i<ans.size(); i++)
        printf(" %d",ans[i]);
    puts("");
    return 0;
}
