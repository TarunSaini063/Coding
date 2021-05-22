#include<iostream>
#include<vector>
#include<utility>
#include <algorithm>
using namespace std;
const int mx=1e4+5;
vector<int> id(mx);
pair<int,pair<int,int>> graph[mx];
void init()
{
	for(int i=0;i<mx;i++) id[i]=i;
}

int root(int x)
{
	while(id[x]!=x) id[x]=id[id[x]],x=id[x];
	return x;
}
void uni(int x,int y)
{
	int p=root(x);
	int q=root(y);
	id[p]=id[q];
}
int krush(int n,int e)
{
	int ans=0,x,y,w;
	for(int i=0;i<e;i++)
	{
		x=graph[i].second.first;
		y=graph[i].second.second;
		w=graph[i].first;
		if(root(x)!=root(y))
		{
			ans+=w;
			uni(x,y);
		}
	}
	return ans;
}
int main(void)
{
	init();
	int n,e,x,y,w;
	cin>>n>>e;
	for(int i=0;i<e;i++)
	{
		cin>>x>>y>>w;
		graph[i]=make_pair(w,make_pair(x,y));
	}
	sort(graph,graph+e);
	int mn=krush(n,e);
	cout<<mn<<endl;
}
