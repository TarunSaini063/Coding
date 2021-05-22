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
	int n;
	cin>>n;
	vector<int> arr(n),l(n),r(n);

	for(int i = 0 ;i<n; i++){
		cin>>arr[i];
	}
	int mx = 0;
	for(int i = 1; i<n ; i++){
		if(arr[i]>arr[i-1]){
			l[i] = l[i-1]+1;
		}
		mx = max(mx,l[i]);
	}

	for(int i = n-2;i>=0; i--){
		if(arr[i]>arr[i+1]){
			r[i] = r[i+1]+1;
		}
		mx = max(mx,r[i]);
	}

	int cnt = 0;
	for(int i = 0 ;i<n;i++){
		if(l[i]==mx) cnt++;
		if(r[i]==mx) cnt++;
	}
	if(cnt > 2||mx%2==1){
		cout<<"0\n";
	}else{
		int ans = 0;
		for(int i = 0 ;i<n ;i++){
			if(r[i] == mx && l[i] == mx) ans++;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
