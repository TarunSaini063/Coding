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
ll arr1[1000005],ans[1000005];
void solve()
{
	for(int i=0;i<=1000000;i++) arr1[i]=i;
	for(int i=2;i<=1000000;i++)
	{
		if(arr1[i]==i)
		{
			arr1[i]=i-1;
			for(int j=2*i;j<=1000000;j+=i)
			{
				arr1[j]=(arr1[j]/i)*(i-1);
			}
		}
	}
	for(int i=1;i<=1000000;i++)
	{
		for(int j=i;j<=1000000;j+=i)
		{
			ans[j]+=(i*arr1[i]);
		}
	}
}

int main(void)
{
	FIO	
	int t;
	solve();
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		ll answer=n*(ans[n]+1);
		cout<<answer/2<<endl;
	}
	
	return 0;
}