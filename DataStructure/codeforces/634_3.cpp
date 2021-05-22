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
		vector<int> arr(n),an;
		int freq[n+5];
		int ans=0;
		memset(freq,0,sizeof(freq));
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
			freq[arr[i]]++;
		}
		for(int i=1;i<=n+3;i++)
		{
			if(freq[i]!=0) an.pb(freq[i]);
		}
		sort(all(an),greater<int>());
		// for(auto j : an) cout<<j<<" ";
		// 	cout<<"\n";
		int sz=(int)an.size();
		int tp1=0;
		for(int i=0;i<sz;i++)
		{
				ans=min(an[i],sz-i-1);
				if(an[i]-ans>=2) ans++;
				tp1=max(tp1,ans);
		}
		cout<<tp1<<"\n";
	}
	return 0;
}