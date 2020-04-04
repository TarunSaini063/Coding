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
bool cmp(const pair<int,int> &a,const pair<int,int>&b)
{
	if(a.ff<=b.ff) return a.ss<b.ss;
	return false;
}
int main(void)
{
	FIO	
	int t;
	cin>>t;
	while(t--)
	{
		int n,fl=0,a,b;
		string s="";
		cin>>n;
		vector<pair<int,int>> arr(n);
		for(int i=0;i<n;i++) cin>>arr[i].ff>>arr[i].ss;
		sort(all(arr));
		a=b=0;
		for(int i=0;i<n;i++)
		{
			if(arr[i].ff-a<0||arr[i].ss-b<0){fl=1;break;}
			for(int j=1;j<=arr[i].ff-a;j++) s+="R";
			for(int j=1;j<=arr[i].ss-b;j++) s+="U";
			a=arr[i].ff;b=arr[i].ss;
		}
		if(fl) cout<<"NO"<<endl;
		else cout<<"YES"<<endl<<s<<endl;
	}
	return 0;
}