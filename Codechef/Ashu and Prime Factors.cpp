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
	int n=1000001;
	int arr[n]={0};
	arr[0]=arr[1]=1;
	for(int i=2;i*i<=n;i++)
	{
		if(arr[i]==0)
		{
			// arr[i]=1;
			for(int j=2*i;j<n;j+=i)
			{
				if(arr[j]==0)
				{
					arr[j]=i;
					arr[i]++;
				}
			}
		}
	}
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		cout<<arr[n]+1<<endl;
	}
	return 0;
}