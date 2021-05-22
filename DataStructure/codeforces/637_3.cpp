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
		int arr[n];
		vector<pair<int,int>> v;
		for(int i=0;i<n;i++) {cin>>arr[i]; v.pb(mk(arr[i],i+1));}
		sort(all(v));
		int fl=0;
		int pr=-1;
		for(int i=0;i<n-1;i++)
		{
			if(pr==-1){if(v[i].ss<n) pr=v[i].ss+1;}
			else
			{
				if(pr!=v[i].ss)
				{
					fl=1;
					break;
				}
				else
				{
					if(v[i].ss<n) pr=v[i].ss+1;
					else pr=-1;
				}
			}
		} 
		if(fl==1) cout<<"No"<<"\n";
		else cout<<"Yes"<<"\n";

	}
	return 0;
}