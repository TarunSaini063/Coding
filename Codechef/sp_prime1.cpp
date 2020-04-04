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
vector<ll> primes;
void sieve()
{
	int arr[1000001]={0};
	for(int i=2;i<=1000000;i++)
	{
		if(arr[i]==0)
		{
			primes.pb(i);
			for(int j=2*i;j<=1000000;j+=i) arr[j]=1;
		}
	}
}
bool isprime(ll i)
{
	for(auto j : primes)
	{
		if(j*j<=i && i%j==0) return false;
	}
	return true;
}
int main(void)
{
	FIO	
	sieve();
	int t;
	cin>>t;
	while(t--)
	{
		ll m,n;
		int it;
		cin>>n>>m;
		if(n<=1000000)
		{
			it=lower_bound(all(primes),n)-primes.begin();
			for(int i=it;i<(int)primes.size() && primes[i]<=m;i++) cout<<primes[i]<<endl;
			if(m>1000000)
			{
				for(ll i=1000001;i<=m;i++)
				{
					if(isprime(i)) cout<<i<<endl;
				}
			}
		}
		else
		{
			for(ll i=n;i<=m;i++)
			{
				if(isprime(i)) cout<<i<<endl;
			}
		}
	}
	return 0;
}