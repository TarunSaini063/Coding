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
		int n,mx=0;
		ll ans=0;
		cin>>n;
		vector<int> arr(n),freq(100001,0);
		for(int i=0;i<n;i++) {cin>>arr[i];freq[arr[i]]++;mx=max(mx,arr[i]);}
		sort(all(arr));
		for(int i=0;i<n;i++)
		{
			for(int j=2*arr[i];j<=mx;j+=arr[i]) ans+=freq[j];
			if(freq[arr[i]]>1) {ans+=freq[arr[i]]-1; freq[arr[i]]--;}
		}
		cout<<ans<<endl;
	}
	return 0;
}