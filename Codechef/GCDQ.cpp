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
int gcd(int a,int b)
{
	while(b)
	{
		a%=b;
		swap(a,b);
	}
	return a;
}
int main(void)
{
	FIO	
	int t;
	cin>>t;
	while(t--)
	{
		int n,q,l,r;
		cin>>n>>q;
		vector<int> arr(n+1),sgd(n+1),lgd(n+2);
		for(int i=1;i<=n;i++) cin>>arr[i];
		sgd[0]=0;
		lgd[n+1]=0;
		for(int i=1;i<=n;i++)
		sgd[i]=gcd(sgd[i-1],arr[i]);
		for(int i=n;i>=1;i--)
		lgd[i]=gcd(lgd[i+1],arr[i]);
		while(q--)
		{
			cin>>l>>r;
			cout<<gcd(sgd[l-1],lgd[r+1])<<endl;
		}
	}
	return 0;
}