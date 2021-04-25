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
const int mxn = 1e5+2;
int arr[mxn];
int main(void)
{
	FIO	
	int t;
	cin>>t;
	while(t--){
		int n,m,x;
		cin>>n>>m;
		for(int i = 0; i<n;i++){
			cin>>x;
			x%=m;
			arr[x]++;
		}
		int ans = 0;
		for(int i = 1;i<m;i++){
			int mx = min(arr[i],arr[m-i]);
			if(mx == 0) continue;
			if(abs(arr[m-i]-arr[i])<=1){
				arr[m-i]=arr[i]=0;
				ans++;
				continue;
			}
			arr[i]-=mx;
			arr[m-i]-=mx;
			if(arr[i]>0) arr[i]--;
			if(arr[m-i]>0) arr[m-i]--;
			ans++;
		}
		if(arr[0]!=0) ans++;
		for(int i = 1 ;i<m;i++){
			if(arr[i]>0) ans+=arr[i];
		}
		for(int i = 0 ;i<m;i++)arr[i] = 0;
		cout<<ans<<'\n';
	}
	return 0;
}