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
	vector<ll>arr;
	while(t--)
	{
		int n,fl=0;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>fl;
			arr.pb(fl*fl*1ll);
		}
		fl=0;
		sort(all(arr));
		for(int i=n-1;i>=2;i--)
		{
			int a=0,b=i-1;
			while(a<b)
			{
				if(arr[i]==arr[a]+arr[b])
				{
					fl=1;
					break;
				}
				else if(arr[i]>arr[a]+arr[b]) a++;
				else if(arr[i]<arr[a]+arr[b]) b--;
			}
		}
		if(fl==1) cout<<"Yes"<<"\n";
		else cout<<"No"<<"\n";
	}
	return 0;
}