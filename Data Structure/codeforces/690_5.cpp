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
const int mxn = 2e5+1;
ll fact[mxn+1];
ll ncr(ll n,ll r){
	if(r>n||n<0) return 0;
	return (fact[n]*(invmod(fact[r])%mod*invmod(fact[n-r])%mod)%mod)%mod;
}
int main(void)
{
	FIO	
	int t;
	fact[0] = 1;
	for(ll i = 1;i<= mxn;i++){
		fact[i] = (i* fact[i-1])%mod;
	}
	cin>>t; 
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		vector<int> arr(n);
		for(int &i : arr) cin>>i;
		sort(all(arr));
		ll ans = 0;
		for(int i = 0 ; i< n; i++){
			int ele = upper_bound(all(arr),arr[i]+k)- arr.begin();
			ans = (ans + ncr(ele - i - 1, m-1))%mod;
		}
		cout<<ans<<"\n";
	}
	
	return 0;
}