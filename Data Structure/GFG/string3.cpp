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
		string s;
		cin>>s;
		int n=2*(int)s.size()+1;
		int arr[n];
		arr[0]=0;
		arr[1]=1;
		int r=2;
		int c=1;
		for(int i=2;i<n;i++)
		{
			arr[i]=0;
			if(i<r)
			{
				int mr=2*c-i;
				arr[i]=min(arr[mr],r-i);
			}
			while(i-arr[i]-1>=0&&i+arr[i]+1<=n&&((i+arr[i]+1)%2==0||s[(i-arr[i]-1)/2]==s[(i+arr[i]+1)/2])) arr[i]++;
			if(i+arr[i]>r)
			{
				r=i+arr[i];
				c=i;
			}
		}
		int mid=0,j;
		for(int i=1;i<n;i++)
		{
			if(arr[mid]<arr[i]) mid=i;
		}
		j=mid/2-arr[mid]/2;
		cout<<s.substr(j,arr[mid])<<"\n";
	}
	return 0;
}