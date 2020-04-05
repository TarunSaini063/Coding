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
vector<int> primes;
vector<ll> product;
void sieve()
{
	int n=1000001;
	int arr[n]={0};
	for(int i=2;i*i<n;i++)
	{
		if(arr[i]==0)
		{
			for(int j=i*i;j<n;j+=i) arr[j]=1;
		}
	}
	for(int i=2;i<n;i++)
	{
		if(arr[i]==0) primes.pb(i);
	}
	// cout<<primes.size()<<endl;
	// for(int i=0;i<(int)primes.size();i++)
	// {
	// 	for(int j=i;j<(int)primes.size();j++)
	// 	{
	// 		product.pb(primes[i]*1ll*primes[j]);
	// 	}
	// }
	// sort(all(product));
	// cout<<"prod"<<endl;
}
int main(void)
{
	FIO	
	sieve();
	int n,q,x;
	cin>>n>>q;
	vector<int> arr(n);
	sort(all(arr));
	for(int i=0;i<n;i++) cin>>arr[i];
	while(q--)
	{
		cin>>x;
		for(auto j : arr)
		{
			if(x<j||x==0) break;
			if(x%j==0)
			{
				while(x%j==0) x/=arr[i];
			}
		}
		if(fl) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	
	return 0;
}