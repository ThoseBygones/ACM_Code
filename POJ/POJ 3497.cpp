#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

map <string,int> cId;
int n,b,cnt;

struct Component
{
    int price;
    int quality;
};

vector <Component> c[1005];

int arrangeId(string s)
{
    if(!cId.count(s))
        cId[s]=cnt++;   //用map映射为不同的组件编号
    return cId[s];
}

bool satisfyNeed(int x) //品质不小于x的组件能否组装成一个价格不超过b的电脑？
{
    int sum=0;
    for(int i=0; i<cnt; i++)    //  遍历每种组件
    {
        int cheapest=b+1;   //假设最便宜的组件都比预算高
        int len=c[i].size();
        for(int j=0; j<len; j++)    //遍历每种组件的不同选择
        {
            if(c[i][j].quality>=x)  //只要这个种类组件的这个选择品质不比目标的值x低即可（因为整个电脑的整体质量是由最差的那个组件决定的）
                cheapest=min(cheapest,c[i][j].price);   //选择其中最便宜的那个
        }
        if(cheapest==b+1)   //最便宜的任意一个组件价格都比预算还高则返回false
            return false;
        sum+=cheapest;  //累加每个选中的组件的价格
        if(sum>b)   //还未购齐所有组件之前总价超过了预算就返回false
            return false;
    }
    return true;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n >> b;
        cnt=0;
        for(int i=0; i<n; i++)
            c[i].clear();
        cId.clear();
        int maxQuality=0;
        string type,name;
        int p,q;
        for(int i=0; i<n; i++)
        {
            cin >> type >> name >> p >> q;
            Component temp;
            temp.price=p;
            temp.quality=q;
            maxQuality=max(maxQuality,q);
            c[arrangeId(type)].push_back(temp);   //将不同的组件的价格和品质情况分别存储
        }
        int left=0,right=maxQuality;    //二分法求不超过b元的预算能组装成的电脑的品质
        while(left<=right)
        {
            int mid=(left+right)/2;
            //int mid=left+(right-left+1)/2;    //这样二分很好的避免了死循环，直接条件：1.left<right即可；2.只要right=mid-1和left=mid即可
            if(satisfyNeed(mid))
                left=mid+1;
            else
                right=mid-1;    //mid的值已经无法达成，因此右值变为mid-1
        }
        if((left+right)%2)  //避免陷入死循环，判断一下最后的差值是否为奇数，是的话-1
            left--;
        cout << left << endl;
    }
    return 0;
}
