#include<iostream>
using namespace std;

int sign[200100];
int step[200100];
int que[200100];

int main()
{
    int N,K;
    cin>>N>>K;
    int stop=0;
    int frist=0;
    que[stop++]=N;
    while(frist<stop)
    {
        int temp=que[frist++];
        if(temp==K)
            break;
        if(sign[temp+1]==0&&temp<K)
        {
            sign[temp+1]=1;
            que[stop++]=temp+1;
            step[temp+1]=step[temp]+1;
        }
        if(sign[temp-1]==0&&temp>0)
        {
            sign[temp-1]=1;
            que[stop++]=temp-1;
            step[temp-1]=step[temp]+1;
        }
        if(sign[temp*2]==0&&temp<K)
        {
            sign[temp*2]=1;
            que[stop++]=temp*2;
            step[temp*2]=step[temp]+1;
        }
    }
    cout<<step[K]<<endl;
    return 0;
}
