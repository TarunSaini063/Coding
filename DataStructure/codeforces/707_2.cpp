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
		int arr[n];
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		int var = arr[n-1];
		vector<int> res;
		for(int i=n-1;i>=0;i--)
		{
			if(i<n-1){
				var=max(var,arr[i]);
			}
			if(var==0){
				res.push_back(0);
			}
			else{
				res.push_back(1);
			}
			var--;	
		}
		reverse(res.begin(),res.end());
		for(int i=0;i<n;i++){
			cout<<res[i]<<" ";
		}
		cout<<"\n";
	}
	return 0;
}