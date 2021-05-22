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
	ll n1;
	cin>>n1;
	ll num = 1,ans=0;
	while(true){
		string a= to_string(num);
		string db = a+a;
		ll n = stoll(db);
		if(n>n1) break;
		ans++;
		num++;
	}
	cout<<ans<<'\n';
	return 0;
}