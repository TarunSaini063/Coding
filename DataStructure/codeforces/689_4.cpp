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
const int mxn = 1e5+1;
int arr[mxn];
ll sum[mxn + 1];
set<ll> st;
void solve(int l, int r){
	if(l>r) return;
	if(l==r){
		st.insert(arr[r]);
		return;
	}
	if(arr[l] == arr[r]){
		st.insert(sum[r+1]-sum[l]);
		return;
	}
	// cout<<l<<" "<<r<<"\n";
	int mid = (arr[l] + arr[r])/2;
	int part = upper_bound(arr+l,arr+ r,mid)-arr;
	ll currentSumLeft = sum[part] - sum[l];
	ll currentSumRight = sum[r+1] - sum[part];
	st.insert(currentSumRight);
	st.insert(currentSumLeft);
	solve(l,part-1);
	solve(part,r);
}
int main(void)
{
	FIO	
	int t;
	cin>>t;
	while(t--){
		int n,q;
		st.clear();
		cin>>n>>q;
		sum[0] = 0;
		for(int i = 0 ;i<n ;i++){
			cin>>arr[i];
		}

		sort(arr,arr + n);

		for(int i = 0 ; i < n ; i ++){
			sum[i+1] = sum[i] + arr[i];
		}
		st.insert(sum[n]);
		// for(int i = 0; i<n ;i++) cout<<sum[i]<<" ";
		solve(0,n-1);
		// cout<< n<<" "<<q<<"\n";
		// for(ll s : st) cout<<s<< " ";
		// 	cout<<"\n";
		while(q--){
			ll res;
			cin>>res;
			 if(st.find(res)!= st.end()) cout<<"Yes\n";
			 else cout<<"No\n";
		}

	}
	return 0;
}