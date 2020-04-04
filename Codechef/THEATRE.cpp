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
vector<string> permutation;
void calpermutation(string s,int l,int r)
{
	if(l==r) permutation.pb(s);
	else
	{
		for(int i=l;i<=r;i++)
		{
			swap(s[l],s[i]);
			calpermutation(s,l+1,r);
			swap(s[l],s[i]);
		}
	}
}
int main(void)
{
	FIO	
	calpermutation("0123",0,3);
	int t;
	cin>>t;
	ll finalans=0;
	while(t--)
	{
		int n,x;
		char c;
		cin>>n;
		int arr[4][4];
		for(int i=0;i<4;i++)
			for(int j=0;j<4;j++)
				arr[i][j]=0;
		for(int i=0;i<n;i++)
		{
			cin>>c>>x;
			arr[c-'A'][x%4]++;
		}
		ll ans=INT_MIN,curr=0;
		for(auto j : permutation)
		{
			vector<int> tp;
			for(int i=0;i<4;i++)
			{
				tp.pb(arr[i][j[i]-'0']);
			}
			sort(all(tp),greater<int>());
			for(int i=0;i<4;i++)
			{
				if(tp[i]==0)
				{
					curr-=(4-i)*100;
					break;
				}
				curr+=(100-i*25)*tp[i];
			}
			ans=max(ans,curr);
			curr=0;
		}
		cout<<ans<<endl;
		finalans+=ans;
	}
	cout<<finalans<<endl;
	return 0;
}