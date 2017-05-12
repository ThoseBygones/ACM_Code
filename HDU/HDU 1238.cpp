#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

string str,str1[105];

int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        cin >> n;
        int ans=0;
        for(int i=0; i<n; i++)
            cin >> str1[i];
        for(int i=0; i<str1[0].size(); i++)
        {
            for(int j=1; i+j<=str1[0].size(); j++)
            {
                str=str1[0].substr(i,j);
                //cout << str << endl;
                int len=str.size();
                //cout << "@" << len << endl;
                bool flag=true;
                for(int k=1; k<n; k++)
                {
                    if(str1[k].find(str)<0 || str1[k].find(str)>=str1[k].size())
                    {
                        reverse(str1[k].begin(),str1[k].end());
                        //cout << str1[k] << endl;
                        if(str1[k].find(str)<0 || str1[k].find(str)>=str1[k].size())
                        {
                            //cout << str1[k].find(str) << endl;
                            flag=false;
                            break;
                        }
                    }
                    //if(!flag)
                        //break;
                }
                if(flag)
                {
                    //cout << "#" << len << endl;
                    ans=max(ans,len);
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
