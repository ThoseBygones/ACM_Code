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

int num[34];    //��¼ÿ�����Ѿ�ӵ�е�����

int convert(char *s)
{
    for(int i=0; i<34; i++)
    {
        if(strcmp(mahjong[i],s)==0)
            return i;
    }
    return -1;
}

bool satisfy(int depth)  //�ж��Ƿ���ڿ��ӻ���˳�������������ĺ���
{
    for(int i=0; i<34; i++)
    {
        if(num[i]>=3) //���ڿ���
        {
            if(depth==3)
                return true;
            num[i]-=3;
            if(satisfy(depth+1))   //�ݹ�����ʣ�µ�ʮ�����ƣ����Ϊ0~3��
                return true;
            num[i]+=3;
        }
    }
    for(int i=0; i<24; i++)
    {
        if(i%9<=6 && num[i]>=1 && num[i+1]>=1 && num[i+2]>=1)   //����˳��
        {
            if(depth==3)
                return true;
            num[i]--;
            num[i+1]--;
            num[i+2]--;
            if(satisfy(depth+1))    //�ݹ�����ʣ�µ�ʮ�����ƣ����Ϊ0~3��
                return true;
            num[i]++;
            num[i+1]++;
            num[i+2]++;
        }
    }
    return false;
}

bool readyHand()    //�ж��Ƿ񡰺͡��ĺ���
{
    for(int i=0; i<34; i++)
    {
        if(num[i]>=2)   //��ö�ٲ��ҳ�����
        {
            num[i]-=2;
            if(satisfy(0))  //����ܡ��͡���
                return true;
            num[i]+=2;
        }
    }
    return false;
}

int main()
{
    int kase=0;
    bool on_the_pot;    //�ж��Ƿ�����
    char s[100];    //����������ַ���
    int mjId[15];   //����ö�ٵ��齫�Ƽ�¼�������е�13���Ƶı��
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
        for(int i=0; i<34; i++) //����ÿ������ȷ���Ƿ�����������
        {
            memset(num,0,sizeof(num));
            for(int j=0; j<13; j++)
            {
                num[mjId[j]]++;
            }
            if(num[i]>=4)   //�������4���򲻿����ٴΡ�������������
                continue;
            num[i]++;   //�����������������
            if(readyHand()) //�ж��Ƿ��ܡ��͡���
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
