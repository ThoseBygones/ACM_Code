#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const char* mahjong[]={
"1T","2T","3T","4T","5T","6T","7T","8T","9T",
"1S","2S","3S","4S","5S","6S","7S","8S","9S",
"1W","2W","3W","4W","5W","6W","7W","8W","9W",
"DONG","NAN","XI","BEI",
"ZHONG","FA","BAI"
};

int num[34];    //记录每张牌已经拥有的数量

int convert(char *s)
{
    for(int i=0; i<34; i++)
    {
        if(strcmp(mahjong[i],s)==0)
            return i;
    }
    return -1;
}

bool satisfy(int depth)  //判断是否存在刻子或者顺子以满足条件的函数
{
    for(int i=0; i<34; i++)
    {
        if(num[i]>=3) //存在刻子
        {
            if(depth==3)
                return true;
            num[i]-=3;
            if(satisfy(depth+1))   //递归搜索剩下的十二张牌（深度为0~3）
                return true;
            num[i]+=3;
        }
    }
    for(int i=0; i<24; i++)
    {
        if(i%9<=6 && num[i]>=1 && num[i+1]>=1 && num[i+2]>=1)   //存在顺子
        {
            if(depth==3)
                return true;
            num[i]--;
            num[i+1]--;
            num[i+2]--;
            if(satisfy(depth+1))    //递归搜索剩下的十二张牌（深度为0~3）
                return true;
            num[i]++;
            num[i+1]++;
            num[i+2]++;
        }
    }
    return false;
}

bool readyHand()    //判断是否“和”的函数
{
    for(int i=0; i<34; i++)
    {
        if(num[i]>=2)   //“枚举并找出将牌
        {
            num[i]-=2;
            if(satisfy(0))  //如果能“和”牌
                return true;
            num[i]+=2;
        }
    }
    return false;
}

int main()
{
    int kase=0;
    bool on_the_pot;    //判断是否听牌
    char s[100];    //接收输入的字符串
    int mjId[15];   //根据枚举的麻将牌记录手上已有的13张牌的编号
    while(~scanf("%s",&s))
    {
        if(s[0]=='0')
            break;
        printf("Case %d:",++kase);
        mjId[0]=convert(s);
        for(int i=1; i<13; i++)
        {
            scanf("%s",&s);
            mjId[i]=convert(s);
        }
        on_the_pot=false;
        for(int i=0; i<34; i++) //遍历每张牌以确定是否“听”这张牌
        {
            memset(num,0,sizeof(num));
            for(int j=0; j<13; j++)
            {
                num[mjId[j]]++;
            }
            if(num[i]>=4)   //如果超过4张则不可能再次“听”到这张牌
                continue;
            num[i]++;   //如果“听”到这张牌
            if(readyHand()) //判断是否能“和”牌
            {
                on_the_pot=true;
                printf(" %s",mahjong[i]);
            }
            num[i]--;
        }
        if(!on_the_pot)
            printf(" Not ready");
        printf("\n");
    }
    return 0;
}
