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
int main(void)
{
	FIO	
	int n,m,a,b,ans=0;
	cin>>n>>m;
	vector<set<int>>v(n+1),vr(n+1);
	for(int i=0;i<m;i++)
	{
		cin>>a>>b;
		v[a].insert(b);
		vr[b].insert(a);
	}
	for(int i=1;i<n;i++)
	{
		if(v[i].size()<=2)continue;
		for(int j=1;j<n;j++)
		{
			if(vr[j].size()<=2||j==i)continue;
			int cnt=0;
			for(auto k : v[i])
			{
				if(vr[j].find(k)!=vr[j].end()) cnt++;
			}
			if(cnt>=3)ans+=cnt*(cnt-1)*(cnt-2)/6;
		}
	}
	cout<<ans<<endl;
	return 0;
}