#include <bits/stdc++.h>
using namespace std;
#define ld double
#define ll long long
#define pb emplace_back
#define mk make_pair
#define mod 1000000007
#define ff first
#define ss second
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define all(x) x.begin(),x.end()
ll power(ll a, ll b){ll res=1;a=a%mod; while(b){if(b&1)res=(res*a)%mod; a=(a*a)%mod;b/=2;}return res;}
ll invmod(ll a){return power(a,mod-2);}
const int mx=110;
vector<int>id(110);
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
	id[q]=id[p];
}
bool solve(int x,int y)
{
	int p=root(x);
	int q=root(y);
	return p==q;
}
int main(void)
{
	FIO	
	#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	int t,m,n,a;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		init();
		int fl=0;
		vector<pair<int,int>> pr;
		for(int i=0;i<n;i++)
		{
			cin>>a;
			pr.pb(mk(a,i+1));
		}
		vector<int> mp(m);
		for(int i=0;i<m;i++)
		{
			cin>>mp[i];
		}
		sort(all(mp));
		for(auto j : mp)
		{
			if(root(j)!=root(j+1))
			{
				uni(j,j+1);
			}
		}
		sort(all(pr));
		for(int i=0;i<n;i++)
		{
			if(i+1==pr[i].ss) continue;
			if(id[i+1]!=id[pr[i].ss])
			{
				fl=1;
				break;
			}
		}
		if(fl) cout<<"No"<<"\n";
		else cout<<"YES"<<"\n";
	}
	return 0;
}