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
	for(int T =1; T<=t; T++){
		int n,k,ans=0; 
		cin>>n>>k;
		string s;
		cin>>s;
		for(int i = 0; i<n/2;i++){
			ans+=(s[i]!=s[n-i-1]);
		}
		ans= abs(k-ans);
		cout<<"Case #"<<T<<": "<<ans<<"\n";
	}
	return 0;
}