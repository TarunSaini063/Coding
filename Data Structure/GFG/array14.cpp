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
void swap(int &x,int &y){
    int t;
    t=x;
    x=y;
    y=t;
}
int partition(int l,int r,vector<int> &arr)
{
	int z=l;
	for(int i=l;i<r;i++)
	{
		if(arr[i]<arr[r])
		{
			swap(arr[i],arr[z]);
			z++;
		}
	}
	swap(arr[r],arr[z]);
	return z;
}
int solve(vector<int> arr,int l,int r,int k)
{
	if (k > 0 && k <= r - l + 1) {
	int p=partition(l,r,arr);
	if(p-l+1==k) return arr[p];
	if(p-l+1<k) return solve(arr,p+1,r,k-p-1+l);
	return solve(arr,l,p-1,k);}
	return -1;
}
int main(void)
{
	FIO	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n;
		vector<int> arr(n);
		for(int i=0;i<n;i++) cin>>arr[i];
		cin>>k;
		cout<<solve(arr,0,n-1,k)<<"\n";
	}
	return 0;
}