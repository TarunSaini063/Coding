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
		ll n,k,i,j;
		cin>>n>>k;
		vector<ll> arr(n);
		for(int i=0;i<n;i++) cin>>arr[i];
		i=0;
		j=min(n-1,k-1);
		while(j<n)
		{
			ll p=i;
			ll q=j;
			while(p<q)
			{
				swap(arr[p],arr[q]);
				p++,q--;
			}
			if(j==n-1) break;
			i+=k;
			j+=k;
			if(j>=n) j=n-1;
		}
		for(auto p: arr) cout<<p<<" ";
		cout<<"\n";
	}
	return 0;
}