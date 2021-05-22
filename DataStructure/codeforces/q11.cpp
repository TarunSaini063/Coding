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
	ll n,k,mx1=INT_MIN;
	cin>>n>>k;
	ll arr[n],mx[n],mn[n];
	for(ll i=0;i<n;i++) cin>>arr[i];
	mx[n-1]=arr[n-1];mn[0]=arr[0];
	for(int i=n-2;i>=0;i--) mx[i]=max(arr[i],mx[i+1]);
	for(int i=1;i<n;i++) mn[i]=min(mn[i-1],arr[i]);
	for(int i=0;i<n;i++) mx1=max(mx1,mx[i]-mn[i]);
	cout<<k*mx1<<endl;
	return 0;
}