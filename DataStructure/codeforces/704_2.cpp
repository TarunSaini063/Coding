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
const int mxn = 1e5+2;
int arr[mxn],idx[mxn];
int main(void)
{
	FIO	
	int t; 
	cin>>t; 
	while(t--){
		int n; 
		cin>>n;
		unordered_map<int,int> mp;
		for(int i=0; i<n ;i++){
			cin>>arr[i];
			idx[arr[i]] = i;
		}
		vector<int> ans;
		int start=n-1,end;
		for(int i = n;i>=1; i--){
			if(mp.count(idx[i])==0){
				for(int j = idx[i];j<=start;j++){
					ans.pb(arr[j]);
					mp[j]=1;
				}
				start = idx[i]-1;
			}
		}
		for(int i: ans) cout<<i<<" ";
			cout<<"\n";
	}
	return 0;
}