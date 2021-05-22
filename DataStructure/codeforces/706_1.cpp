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
		int n,k; 
		cin >> n>> k; 
		string s;
		cin>>s;
		if(n<2*k+1)  cout<<"NO\n";
		else{
			string start = s.substr(0,k);

			string end = s.substr(n-k,k);
			reverse(all(end));
			if(start == end	){
				cout<<"YES\n";
			}else cout<<"NO\n";
		}
	}
	return 0;
}