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
		int x,y;
		cin>>x>>y;
		vector<int> arr1(x),arr2(y);
		for(int i=0;i<x;i++) cin>>arr1[i];
		for(int i=0;i<y;i++) cin>>arr2[i];
		while(true)
		{
			int lt=arr1[x-1],j=y-1,i=x-2;
			while(arr2[j]>lt&&j>=0) j--;
			if(j==-1) break;
			while(arr1[i]>arr2[j]&&i>=0)
			{
				arr1[i+1]=arr1[i];
				i--;
			} 
			arr1[i+1]=arr2[j];
			arr2[j]=lt;
		}
		for(auto j: arr1) cout<<j<<" ";
		for(auto j :arr2) cout<<j<<" ";
		cout<<"\n";
	}
	return 0;
}