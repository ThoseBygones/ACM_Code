#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

struct player
{
    string name;
    int score;
} sum[1005],temp[1005],fin[1005];

int main()
{
    int i,j,k,n,cnt=0;
    cin >> n;
    for(i=0,k=0; i<n; i++,k++)
    {
        sum[k].score=0;
        cin >> temp[i].name >> temp[i].score;
        for(j=0;j<k;j++)
        {
            if(temp[i].name==sum[j].name)
            {
                k--;
                break;
            }
        }
        sum[j].name=temp[i].name;
        sum[j].score+=temp[i].score;
    }
    for(i=0;i<k;i++)
        cnt=max(cnt,sum[i].score);
    for(i=0,k=0;i<n;i++,k++)
    {
        fin[i].score=0;
        for(j=0;j<k;j++)
        {
            if(temp[i].name==fin[j].name)
            {
                k--;
                break;
            }
        }
        fin[j].name=temp[i].name;
        fin[j].score+=temp[i].score;
        if(fin[j].score>=cnt && sum[j].score==cnt)
        {
            cout << fin[j].name << endl;
            break;
        }
    }
    return 0;
}
