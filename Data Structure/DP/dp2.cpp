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
		vector<int> jp(n,INT_MAX);
		jp[0]=0;
		int fl=1;
		for(int i=0;i<n;i++)
		{
			int j=i;
			if(jp[i]==INT_MAX)
			{
			    cout<<"-1"<<"\n";
			    fl=0;
			    break;
			}
			while(j<n-1&&j<i+arr[i])
			{
				jp[j+1]=min(jp[j+1],jp[i]+1);
				j++;
			}
		} 
		if(fl==1)cout<<jp[n-1]<<"\n";
	}
	return 0;
}