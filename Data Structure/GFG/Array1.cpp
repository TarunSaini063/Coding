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
		ll k;
		cin>>n>>k;
		vector<ll> arr(n+1);
		int fl=1;
		for(int i=1;i<=n;i++) cin>>arr[i];
		ll sm=0;
		int i=1,j=1;
		while(i<=n&&sm+arr[i]<=k)
		{
			sm+=arr[i];
			i++;
		}
		while(j<=i)
		{
			
			if(sm<k) sm+=arr[i++];
			if(sm>k) sm-=arr[j++];
			if(sm==k){
				fl=0;
				break;
			}
			if(sm<k&&i>n) break;
		}
		if(fl==1) cout<<-1<<"\n";
		else cout<<j<<" "<<i-1<<"\n";
	}
	return 0;
}