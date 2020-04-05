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
	int t,m,n;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		vector<int>arr1(n+1,0);
		int w,x,y,z,mx=INT_MIN,mn=INT_MAX;
		while(m--)
		{
			cin>>w>>x>>y>>z;
			if(w==1)
			{
				arr1[x]+=z;
				arr1[y+1]-=z;
			}
			else
			{
				arr1[x]-=z;
				arr1[y+1]+=z;
			}
		}
		for(int i=2;i<=n;i++) arr1[i]+=arr1[i-1];
		for(int i=1;i<=n;i++)
		{
			mx=max(mx,i+arr1[i]);
			mn=min(mn,i+arr1[i]);
		}
		cout<<mx-mn<<endl;
	}
	return 0;
}