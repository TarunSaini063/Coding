#include <bits/stdc++.h>
using namespace std;
#define ld double
#define ll long long
#define pb push_back
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
		int n,m,x;
		cin>>n>>m;
		string s;
		cin>>s;
		vector<int> arr(n+1,0),ans(29,0),cum(n+1,0);
		for(int i=0;i<m;i++)
		{
			cin>>x;
			arr[x-1]++;
		}
		arr[n-1]++,x=0;
		for(int i=n-1;i>=0;i--)
		{
			x+=arr[i];
			ans[s[i]-'a']+=x;
		}
		for(int i=0;i<26;i++)
		{
			cout<<ans[i]<<" ";
		}
		cout<<"\n";
	}
	return 0;
}