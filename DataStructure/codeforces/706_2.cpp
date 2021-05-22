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
void solve(){
	int n,k;
	cin>>n>>k;
	set<int> s;
	for(int i = 0; i<n;i++){
		int x;
		cin>>x;
		s.insert(x);
	}
	if(k==0){
		cout<<sz(s);
		return;
	}
	int req;
	for(int i= 0 ; i<= n+10; i++){
		if(s.find(i)==s.end()){
			req = i;
			break;
		}
	}
	int mx = *(--s.end());
	if(mx == req-1){
		int ans = sz(s);
		ans+=k;
		cout<<ans;
		return;
	}
	req = ceil((req+mx)/2.0);
	int res = sz(s);
	if(s.find(req)== s.end()){
		res++;
	}
	cout<<res;
}
int main(void)
{
	FIO	
	int t;
	cin>>t;
	while(t--){
		solve();
		cout<<"\n";
	}
	return 0;
}