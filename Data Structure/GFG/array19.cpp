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
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int> v(n),lmax(n,0),rmin(n,INT_MAX);
	    for(int i=0;i<n;i++){
	        cin>>v[i];
	        if(i>0)
	        lmax[i] = max(lmax[i-1],v[i-1]);
	    }
	    for(int i=n-2;i>=0;i--){
	        rmin[i] = min(rmin[i+1],v[i+1]);
	    }
	    int ans = -1;
	    for(int i=1;i<n-1;i++){
	        if(lmax[i] <= v[i] && v[i]<= rmin[i]){
	            ans = v[i];
	            break;
	        }
	    }
	    cout<<ans<<endl;
	}
	return 0;
}