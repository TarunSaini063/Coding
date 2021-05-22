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
void merge_sort(int arr[],int l,int m,int r)
{
	int l1[m-l+1];
	int r1[r-m];
	for(int i=l;i<=m;i++) l1[i-l]=arr[i];
	for(int j=m+1;j<=r;j++) r1[j-m-1]=arr[j];
	int i=0,j=0,k=l;
	while(i<m-l+1&&j<r-m)
	{
		if(l1[i]<=r1[j])
		{
			arr[k++]=l1[i++];
		}
		if(r1[j]<=l1[i])
		{
			arr[k++]=r1[j++];
		}
	}
	while(i<m-l+1) arr[k++]=l1[i++];
	while(j<r-m) arr[k++]=r1[j++];
}

void merge(int arr[],int i,int j)
{
	if(i<j)
	{
		int m=(i+j)/2;
		merge(arr,i,m);
		merge(arr,m+1,j);
		merge_sort(arr,i,m,j);
	}
}
int main(void)
{
	FIO	
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++) cin>>arr[i];
	merge(arr,0,n-1);
	for(auto j : arr) cout<<j<<" ";
	return 0;
}