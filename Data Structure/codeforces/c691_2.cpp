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
		int n,fl=0;
		cin>>n;
		ll mn=INT_MAX,mx=INT_MIN;
		vector<ll>arr(n),rm;
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
			if(arr[i]!=-1) fl=1;
		}
		if(fl==0)
		{
			cout<<0<<" "<<0<<endl;
			continue;
		}
		for(int i=0;i<n;i++)
		{
			if(i>0&&arr[i-1]==-1&&arr[i]!=-1) mn=min(mn,arr[i]),mx=max(mx,arr[i]);
			if(i<n-1&&arr[i+1]==-1&&arr[i]!=-1) mn=min(mn,arr[i]),mx=max(mx,arr[i]);
		}
		// cout<<mx<<" "<<mn<<endl;
		ll dif=(mn+mx)/2;
		ll ans=INT_MIN;
		if(arr[0]==-1) arr[0]=dif;
		for(int i=1;i<n;i++)
		{
			if(arr[i]==-1)arr[i]=dif;
			ans=max(ans,abs(arr[i]-arr[i-1]));
		}
		cout<<ans<<" "<<dif<<endl;
	}
	return 0;
}