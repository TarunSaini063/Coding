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
		for(int i=0;i<n;i++) cin>>arr[i];
		sort(all(arr));
		int ans=0,a=0,b=1;
		for(int i=n-1;i>=2;i--)
		{
			a=0;
			b=i-1;
			while(a<b)
			{
				if(arr[a]+arr[b]==arr[i])
				{
					ans++;
					a++,b--;
				}
				else if(arr[a]+arr[b]<arr[i])
				{
					a++;
				}
				else b--;
			}
		}
		if(ans==0) cout<<-1<<"\n";
		else cout<<ans<<"\n";
	}
	return 0;
}