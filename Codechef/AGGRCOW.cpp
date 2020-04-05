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
bool check(int m,vector<int> &arr,int c)
{
	int prev=arr[0],c1=1;
	for(int i=1;i<(int)arr.size();i++)
	{
		if(arr[i]-prev>=m) c1++,prev=arr[i];
		if(c1>=c) return true;
	}
	return false;
}
int main(void)
{
	FIO	
	int t;
	cin>>t;
	while(t--)
	{
		int n,c,ans=0;
		cin>>n>>c;
		vector<int>arr(n);
		for(int i=0;i<n;i++) cin>>arr[i];
		sort(all(arr));
		int l=0,m;
		int r=arr.back();
		while(r-l>=2)
		{
			m=l+(r-l)/2;
			if(check(m,arr,c))
			{
				ans=m;
				l=m;
			}
			else r=m;
		}
		cout<<ans<<endl;
	}
	return 0;
}