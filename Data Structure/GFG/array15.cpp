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
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int arr[n];
		for(int i=0;i<n;i++) cin>>arr[i];
		int left[n]; 
	    int right[n]; 
	    int water = 0; 
	    left[0] = arr[0]; 
	    for (int i = 1; i < n; i++) 
	        left[i] = max(left[i - 1], arr[i]); 
	    right[n - 1] = arr[n - 1]; 
	    for (int i = n - 2; i >= 0; i--) 
	        right[i] = max(right[i + 1], arr[i]); 
	    for (int i = 0; i < n; i++) 
	        water += min(left[i], right[i]) - arr[i]; 
	    cout<<water<<"\n"; 
	}
	
	return 0;
}