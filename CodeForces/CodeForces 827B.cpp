#include <bits/stdc++.h>
using namespace std;

#define MAXN 200005

vector <pair<int,int> > ans;

//Build a tree with a root of k degrees, exit-nodes 1 degree and others 2 degree.
//It is obvious that the length of the path between every two nodes now is shortest.

int depth[MAXN];    //the depth of every exit-node on the tree
int num[MAXN];  //the number of nodes on every branch of the root
int outer[MAXN];    //the most outside node of every branch

bool cmp(int x,int y)
{
    return x>y;
}

int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    int root=n-k;   //let's make the id of the root node (n-k), that means the node whose id is n-k+1~k is exit-node
    for(int i=0; i<k; i++)
        outer[i]=root;
    for(int i=1; i<root; i++)
    {
        ans.push_back(make_pair(outer[i%k],i));
        outer[i%k]=i;
        num[i%k]++;
    }
    for(int j=0; j<k; j++)
    {
        ans.push_back(make_pair(outer[(root+j)%k],root+j+1));
        outer[(root+j)%k]=root+j+1;
        num[(root+j)%k]++;
        depth[j]=num[(root+j)%k];
    }
    sort(depth,depth+k,cmp);
    printf("%d\n",depth[0]+depth[1]);
    for(int i=0; i<ans.size(); i++)
        printf("%d %d\n",ans[i].first,ans[i].second);
    return 0;
}
