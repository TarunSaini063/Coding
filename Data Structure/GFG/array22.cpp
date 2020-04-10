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
		int n,m;
		cin>>n>>m;
		int arr[n][m];
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				cin>>arr[i][j];
		int r1,r2,c1,c2;
		r1=c1=0;
		r2=n-1;c2=m-1;
		while(r1<=r2&&c1<=c2)
		{
			for(int i=c1;i<=c2;i++) cout<<arr[r1][i]<<" ";
			r1++;
			for(int i=r1;i<=r2;i++) cout<<arr[i][c2]<<" ";
			c2--;
			if(r1<=r2)
			for(int i=c2;i>=c1;i--) cout<<arr[r2][i]<<" ";
			r2--;
			if(c1<=c2)
			for(int i=r2;i>=r1;i--) cout<<arr[i][c1]<<" ";
			c1++;
		}
		cout<<"\n";
	}
	return 0;
}