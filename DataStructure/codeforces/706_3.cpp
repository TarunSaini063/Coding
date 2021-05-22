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
		vector<ll> min,dia;
		int n;
		cin>>n;
		for(int i = 0; i<2*n;i++){
			int x,y;
			cin>>x>>y;
			if(x==0){
				min.pb(1ll*y*y);
			}else{
				dia.pb(1ll*x*x);
			}
		}
		sort(all(min));
		sort(all(dia));
		long double ans = 0;
		for(int i = 0; i < n;  i++){
			 double tmp = sqrt(min[i]+dia[i]);
			 // cout<<min[i]<<" "<<dia[i]<<"\n";
			 ans+=tmp;
		}
		cout<<fixed<<setprecision(15)<<ans<<"\n";
	}
	return 0;
}