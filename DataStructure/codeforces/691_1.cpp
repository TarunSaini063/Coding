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

ll gcd(ll a, ll b){
	if(a==0) return b;
	return gcd(b%a,a);
}
int main(void)
{
	FIO	
	int t = 1; 
	// cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		ll arr[n],brr[m];
		for(ll &i : arr) cin>>i;
		for(ll &i : brr) cin>>i;
		ll ans = 0;
		for(int i=1;i<n;i++){
			ans = gcd(ans,abs(arr[i]-arr[0]));
		}
		for(int i =0 ; i<m ; i++){
			cout<<gcd(ans,arr[0]+brr[i])<<" ";
		}
	}
	return 0;
}