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
	int n=101;
	int arr[n]={0};
	vector<int> primes;
	for(int i=2;i*i<=n;i++)
	{
		if(arr[i]==0)
		{
			for(int j=i*i;j<=n;j+=i) arr[j]=1;
		}
	}
	for(int i=2;i<n;i++)
	{
		if(arr[i]==0) {primes.pb(i);cout<<i<<" ";}
	}
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		int a=lower_bound(all(primes),n)-primes.begin();
		cout<<a<<endl;
		// if(primes[a]==n) cout<<n<<endl;
		// else
		// {
		// 	if(n-primes[a-1]<primes[a]-n) cout<<primes[a-1]<<endl;
		// 	else cout<<primes[a]<<endl;
		// }
		
	}
	return 0;
}