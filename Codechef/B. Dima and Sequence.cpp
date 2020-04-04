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
int getone(int x)
{
	int ans=0;
	while(x)
	{
		if(x&1) ans++;
		x>>=1;
	}
	return ans;
}
int main(void)
{
	FIO	
	ll n,x,ans=0;
	cin>>n;
	int arr[40]={0};
	for(ll i=0;i<n;i++)
	{
		cin>>x;
		ans+=arr[getone(x)]++;
	}
	cout<<ans<<endl;
	return 0;
}