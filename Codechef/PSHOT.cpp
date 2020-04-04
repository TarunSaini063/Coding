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
		string s;
		int n;
		cin>>n;
		cin>>s;
		int l1=0,h1=n,l2=0,h2=n;
		int ans=-1;
		for(int i=0;i<2*n;i+=2)
		{
			if(s[i]=='1')l1++;
			else h1--;
			if(l1>h2)
			{
				ans=i+1;
				break;
			}
			if(l2>h1)
			{
				ans=i+1;
				break;
			}
			if(s[i+1]=='1') l2++;
			else h2--;
			if(l2>h1)
			{
				ans=i+2;
				break;
			}
			if(l1>h2)
			{
				ans=i+2;
				break;
			}
		}
		if(ans==-1) ans=2*n;
		cout<<ans<<endl;
	}
	return 0;
}