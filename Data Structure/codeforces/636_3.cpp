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
		for(auto &j : arr) cin>>j;
		ll i=0,nans=0,pans=0,nl=0,pl=0;
		while(i<n&&arr[i]>0) i++;
		while(i<n)
		{
			int mx=arr[i];i++;
			while(i<n&&arr[i]<0) mx=max(mx,arr[i]),i++;
			nans+=mx;nl++;
			// cout<<mx<<" ";
			if(i>=n) break;
			mx=arr[i];i++;
			while(i<n&&arr[i]>0) mx=max(mx,arr[i]),i++;
			nans+=mx;nl++;
			// cout<<mx<<" nans "<<nans<<"\n";
		}
		// cout<<"\n";
		i=0;
		while(i<n&&arr[i]<0) i++;
		while(i<n)
		{
			int mx=arr[i];i++;
			while(i<n&&arr[i]>0) mx=max(mx,arr[i]),i++;
			pans+=mx;pl++;
			// cout<<mx<<" ";
			if(i>=n) break;
			mx=arr[i];i++;
			while(i<n&&arr[i]<0) mx=max(mx,arr[i]),i++;
			pans+=mx;pl++;
			// cout<<mx<<" pans "<<pans<<" ";
		}

		// cout<<"\n";
		// cout<<nans<<" "<<pans<<"\n";
		if(nl==pl)
		cout<<max(nans,pans)<<"\n";
		else
		{
			if(pl>nl) cout<<pans<<"\n";
			else cout<<nans<<"\n";
		}
	}
	return 0;
}