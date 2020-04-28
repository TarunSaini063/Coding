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
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		vector<int> arr(n);
		for(auto &i : arr) cin>>i;
		vector<int> pref(2*k+2,0);
		vector<int> cnt(2*k+1,0);
		for(int i=0;i<n/2;i++)
		{
			cnt[arr[i]+arr[n-i-1]]++;
		}
		for(int i=0;i<n/2;i++)
		{
			int mn=min(arr[i],arr[n-i-1])+1;
			int mx=max(arr[i],arr[n-i-1])+k;
			pref[mn]++;
			pref[mx+1]--;
		}
		for(int i=1;i<=2*k+1;i++) pref[i]+=pref[i-1];
		int ans=1e9;
		for(int i=2;i<=2*k;i++)
		{
			ans=min(ans,pref[i]-cnt[i]+2*(n/2-pref[i]));
		}
		cout<<ans<<"\n";
	}
	return 0;
}