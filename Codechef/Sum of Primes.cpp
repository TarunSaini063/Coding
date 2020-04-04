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
vector<ll> arr(1000005,0);
void sieve()
{
	int n=1000005;
	for(int i=2;i*i<n;i++)
	{
		if(arr[i]==0)
		{
			for(int j=i*i;j<n;j+=i)
				arr[j]=1;
		}
	}
	for(int i=2;i<n;i++)
	{
		if(arr[i]==0)
		{
			arr[i]=i+arr[i-1];
		}
		else arr[i]=arr[i-1];
	}
}
int main(void)
{
	FIO	
	sieve();
	int n=0,l,r;
	cin>>n;
	while(n--)
	{
		cin>>l>>r;
		ll ans=arr[r]-arr[l-1];
		cout<<ans<<endl;
	}
	return 0;
}