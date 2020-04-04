#include <bits/stdc++.h>
using namespace std;
#define				ld				double
#define 			ll 				long long
#define 			pb 				emplace_back
#define 			mk 				make_pair
#define 			mod 			1000000007
#define 			ff 				first
#define 			ss 				second
#define 			FIO 			ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define 			all(x) 			x.begin(),x.end()
ll power(ll a, ll b){ll res=1;a=a%mod; while(b){if(b&1)res=(res*a)%mod; a=(a*a)%mod;b/=2;}return res;}
ll invmod(ll a){return power(a,mod-2);}
int mx=1000000001;
int getval(int k,vector<int> &arr)
{
	int h=0;
	for(int i=0;i<(int)arr.size();i++)
	{
		h+=ceil((arr[i]*1.0)/k);
	}
	return h;
}
int main(void)
{
	FIO	
	int t;
	cin>>t;
	while(t--)
	{
		int n,h,k,H;
		cin>>n>>h;
		vector<int> arr(n);
		for(int i=0;i<n;i++) cin>>arr[i];
		int l=1,j=mx-1;
		while(l<j-1)
		{
			k=l+(j-l)/2;
			H=getval(k,arr);
			if(H<=h) j=k;
			else l=k;
		}
		if(getval(l,arr)<=h) H=l;
		else H=j;
		cout<<H<<endl;
	}
	return 0;
}