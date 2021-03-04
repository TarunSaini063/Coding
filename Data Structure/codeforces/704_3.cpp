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
int main(void)
{
	FIO	
	int n,m; 
	cin>>n>>m; 
	string s,t; 
	cin>>s>>t;
	vector<vector<int>> v1(26,vector<int>());
	for ( int i = 0 ;i<n;i++){
		v1[s[i]-'a'].pb(i);
	}

	int arr[m],j=m-1;
	arr[0] = v1[t[0]-'a'][0];

	for(int i =  n-1; j>0; i--){
		if(t[j] == s[i]){
			arr[j] = i;
			j--;
		}
	}
	int ans = 0;
	// for(int i = 0; i<m; i++) cout<<arr[i]<<" ";
	// 	cout<<"\n";
	for(int i = 0 ; i<m-1;i++){

		ans = max(ans,arr[i+1] - arr[i]);
		for(int  j = arr[i]+1;;j++){
			if(s[j] == t[i+1]){
				arr[i+1] = j;
				break;
			}
		}
	}

	cout<<ans<<"\n";

	return 0;
}