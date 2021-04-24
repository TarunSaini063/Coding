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
		int n; 
		cin>>n;
		int arr[n+1][3],ar[n+1],dep[n+1];
		for(int i = 1; i<=n;i++) cin>>arr[i][0]>>arr[i][1];
		for(int i = 1 ;i<=n;i++) cin>>arr[i][2];

		dep[0] = arr[0][1] = 0;
		for(int i = 1 ;i<=n;i++){
			ar[i] = dep[i-1]+arr[i][0]-arr[i-1][1]+arr[i][2];
			dep[i] = max(arr[i][1],ar[i]+(arr[i][1]-arr[i][0]+1)/2);
		}
		cout<<ar[n]<<"\n";
	}
	return 0;
}