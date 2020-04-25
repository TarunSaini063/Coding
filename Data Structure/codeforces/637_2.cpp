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
		int n,k;
		cin>>n>>k;
		vector<int> arr(n),cnt(n,0),ans(n+1,0);
		for(int i=0;i<n;i++) cin>>arr[i];
		for(int i=1;i<n-1;i++)
		{
			if(arr[i]>arr[i-1]&&arr[i]>arr[i+1]) cnt[i]=1;
		}
		for(int i=1;i<=n;i++) ans[i]=ans[i-1]+cnt[i-1];
		int mx=0,i1=1;
		for(int i=0;i+k<=n;i++)
		 {
		 	int tp=ans[i+k-1]-ans[i+1];
		 	if(mx<tp)
			{
				mx=tp;
				i1=i+1;
			}
		 }
		cout<<mx+1<<" "<<i1<<"\n";
	}
	return 0;
}