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
	int n;
	cin>>n;
	vector<pair<int,int>> arr(n);
	for(int i=0;i<n;i++) cin>>arr[i].ff>>arr[i].ss;
	sort(all(arr));
	int mx=arr[0].ss;
	for(int i=1;i<n;i++)
	{
		if(mx>arr[i].ss)
		{
			cout<<"Happy Alex"<<endl;
			return 0;
		}
		mx=max(mx,arr[i].ss);
	}
	cout<<"Poor Alex"<<endl;
	return 0;
}