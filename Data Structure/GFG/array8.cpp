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
		vector<int> arr(n);
		for(int i=0;i<n;i++) cin>>arr[i];
		int ivr=-1;
		for(int i=0;i<n-1;i++)
		{
			if(arr[i]>arr[i+1])
			{
				ivr=i+1;
				break;
			}
		}
		cout<<ivr<<"\n";
		if(ivr==-1)
		{
			cout<<0<<"\n";
		}
		else if(ivr==1&&arr[n-1]<arr[ivr])
		{
			cout<<n*(n-1)/2<<"\n";
			// cout<<"tp"<<"\n";
		}
		else
		{
			int ans=0;
			for(int i=0;i<ivr;i++)
			{
				int mx=upper_bound(arr.begin()+ivr,arr.end(),arr[i])-arr.begin();
				while(arr[mx]>=arr[i]&&mx>=ivr) mx--;
				ans+=(mx-ivr+1);
			}
			cout<<ans<<"\n";
		}

	}
	return 0;
}