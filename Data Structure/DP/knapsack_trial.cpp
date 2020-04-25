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
int knapsack_rec(int w,vector<int>val,vector<int> wt,int n)
{
	if(n==0||w==0) return 0;
	if(wt[n-1]>w) return knapsack_rec(w,val,wt,n-1);
	return max(val[n-1]+knapsack_rec(w-wt[n-1],val,wt,n-1),knapsack_rec(w,val,wt,n-1));
}
int knapsack_itr(int w,vector<int> val,vector<int> wt,int n)
{
	int dp[n+1][w+1];
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=w;j++)
		{
			if(i==0||j==0) dp[i][j]=0;
			else if(wt[i-1]>j) dp[i][j]=dp[i-1][j];
			else dp[i][j]=max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
		}
	}
	return dp[n][w];
}
int main(void)
{
	FIO	
	int n,w;
	cin>>n>>w;
	vector<int> arr(n),arr1(n),val,wt;
	for(auto &j : arr) cin>>j;
	for(auto &j : arr1) cin>>j;
	vector<pair<int,int>> pr;
	for(int i=0;i<n;i++) pr.pb(mk(arr[i]/arr1[i],i));
	// in case of fractional knapsack
	sort(all(pr),greater<pair<int,int>>());
	for(auto j : pr)
	{
		val.pb(arr[j.ss]);
		wt.pb(arr1[j.ss]);
	}
	cout<<knapsack_itr(w,val,wt,n)<<"\n";
	return 0;
}