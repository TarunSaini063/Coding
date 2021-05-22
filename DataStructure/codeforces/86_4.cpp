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
	int n,k;
	cin>>n>>k;
	vector<int> arr(n);
	for(auto &j:arr) cin>>j;
	sort(all(arr),greater<int>());
	vector<int> c(k);
	for(auto &j:c) cin>>j;
	int ans=0;
	for(int i=k,g=0;i>=1;i--)
	{
		while(g<n&&arr[g]==i)g++;
		int x=g/c[i-1];
		if(g%c[i-1]!=0)x++;
		ans=max(ans,x);
		// cout<<x<<" "<<ans<<"\n";
	}
	vector<vector<int>> res(ans);
	for(int i=0;i<n;i++) res[i%ans].pb(arr[i]);
	cout<<ans<<"\n";
	for(auto i : res)
	{
		cout<<i.size()<<" ";
		for(auto j : i)cout<<j<<" ";
		cout<<"\n";
	}
	return 0;
}