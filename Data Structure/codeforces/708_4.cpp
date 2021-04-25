#include <bits/stdc++.h>
using namespace std;
#define ld double
#define ll long long
#define pb emplace_back
#define mk make_pair
#define mod 1000000007
#define ff first
#define sz(v) (int)v.size();
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
	while(t--){
		ll n,k;
		cin>>n>>k;
		for(int i = 1;i<=k-3;i++)cout << 1 << " ";
	    n = n-k+3;
	    if(n%2==0){
	    	if(n%4==0)cout << n/2 << " " << n/4 << " " << n/4 << "\n";
	    	else cout<<2<<" "<<n/2-1<<" "<<n/2-1<<'\n';
	    }else cout << 1 << " " << n/2 << " " << n/2 << "\n";
	}
	return 0;
}
