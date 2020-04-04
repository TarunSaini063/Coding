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
void sieve()
{
	int arr[10001]={0};
	for(int i=2;i<=10000;i++)
	{
		if(arr[i]==0)
		{
			primes.pb(i);
			for(int j=2*i;j<=10000;j+=i) arr[j]=1;
		}
	}
}
int main(void)
{
	FIO	
	sieve();
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int arr[n];
		for(int i=0;i<n;i++) cin>>arr[i];
		int ans=0;
		for(int i=1;i<n;i++) 
		{
			if(arr[i]<arr[i-1]) 
			{
				ans+=arr[i-1]-arr[i];
				arr[i]=arr[i-1];
			}
		}
		int tp=0,sc=INT_MAX;
		for(auto j : primes)
		{
			tp=0;
			for(int i=0;i<n;i++)
			{
				if(arr[i]%j!=0)
				{
					tp+=j-arr[i]%j;
				}
			}
			sc=min(sc,tp);
		}
		cout<<sc+ans<<endl;
	}
	return 0;
}