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
		int n;
		cin>>n;
		vector<int> arr(2*n);
		for(int i=0;i<2*n;i++) cin>>arr[i];
		sort(all(arr));
		int ans=INT_MAX;
		for(int i=0;i<n;i++)
		{
			ans=min(ans,arr[n+i]-arr[i]);
		}
		ans=min(ans,arr[n]-arr[n-1]);
		cout<<ans<<endl;
	}
	return 0;
}