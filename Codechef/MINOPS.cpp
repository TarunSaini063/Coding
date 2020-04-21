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
		string s1,r;
		cin>>s1>>r;
		int n=s1.size(),dif=0;
		vector<int> arr(n,0);
		for(int i=0;i<n;i++) if(s1[i]!=r[i])arr[i]=1,dif++;
		int s=0,e=n-1;
		while(s<=e)
		{
			if(arr[s]==1) break;
			s++;
		}
		while(e>=s)
		{
			if(arr[e]==1) break;
			e--;
		}
		ll len=e-s+1;
		ll cnt=0;
		while(s<=e)
		{
			while(s<=e&&arr[s]!=0) s++;
			cnt++;
			while(s<=e&&arr[s]!=1) s++;
		}
		ll ans=(len-len/2)*(len/2);
		cout<<ans<<"\n";
	}
	return 0;
}