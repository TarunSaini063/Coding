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
	int t,n,s,k;
	cin>>t;
	while(t--)
	{
		cin>>n>>s>>k;
		vector<int> arr(k);
		for(int i=0;i<k;i++) cin>>arr[i];
		sort(all(arr));
		for(int i=0;i<n;i++)
		{
			if(s-i>0&&!binary_search(all(arr),s-i)) {cout<<i<<endl; break;}
			else if(s+i<=n&&!binary_search(all(arr),s+i)) {cout<<i<<endl;break;}
		}
	}
	return 0;
}