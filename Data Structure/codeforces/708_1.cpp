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
		vector<int> arr(n,0),freq(101,0),ans;
		for(int i = 0;i<n;i++) {
			cin>>arr[i];
			freq[arr[i]]++;
		}
		sort(all(arr));
		for(int i=0;i<101;i++){
			if(freq[i]--){
				ans.pb(i);
			}
		}
		for(int i=0;i<101;i++){
			if(freq[i]>0){
				while(freq[i]--){
				ans.pb(i);
			}
			}
		}
		for(int i:ans) cout<<i<<" ";
			cout<<"\n";
	}
	return 0;
}