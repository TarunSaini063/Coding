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
vector<int> primes,req;
void sieve()
{
	int arr[201]={0};
	for(int i=2;i<=200;i++)
	{
		if(arr[i]==0)
		{
			primes.pb(i);
			for(int j=2*i;j<=200;j+=i) arr[j]=1;
		}
	}
	for(int i=0;i<(int)primes.size();i++)
	{
		for(int j=i+1;j<(int)primes.size();j++)
		{
			req.pb(primes[i]*primes[j]);
		}
	}
	sort(all(req));

}
int main(void)
{
	FIO	
	sieve();
	int t;
	cin>>t;
	while(t--)
	{
		int n,fl=0;
		cin>>n;
		for(auto j : req)
		{
			if(j>n) break;
			if(binary_search(all(req),n-j))
			{
				fl=1;
				break;
			}
		}
		if(fl) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}