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
	ll n, k; set<ll> a; 
	cin>>n>>k;	
	for(ll d=1; d*d<=n; d++){
		if(n%d==0){
			a.insert({d, n/d});
		}
	}
	if(k<=a.size()) cout<<*next(a.begin(),k-1);
	else cout<<-1;
	return 0;
}