#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int x;
    bool operator < (const Node &a) const
    {
        return x<a.x;
    }
};

set <int> s;
priority_queue <Node> pq;

int main()
{
    int n;
    Node temp;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&temp.x);
        s.insert(temp.x);
        pq.push(temp);
    }
    int val;
    while(true) //优先队列维护最小的数字
    {
        for(temp=pq.top(),val=temp.x; val; val/=2)
        {
            if(!s.count(val))
                break;
        }
        if(!val)
            break;
        s.erase(temp.x);
        pq.pop();
        s.insert(val);
        temp.x=val;
        pq.push(temp);
        //cout << val << endl;
    }
    for(std::set<int>::iterator it=s.begin(); it!=s.end(); it++)
		printf("%d ",*it);
    return 0;
}
