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
	int n,q,i,j;
	cin>>n>>q;
	vector<int> arr[3];
	arr[1]=vector<int>(n+1,1);
	arr[2]=vector<int>(n+1,1);
	int block=0;
	while(q--)
	{
		cin>>i>>j;
		arr[i][j]^=1;
		if(arr[i][j]==0)
		{
			if(i==1)
			{
				if(arr[2][j]==0) block++;
				if(j<n&&arr[2][j+1]==0) block++;
				if(j>1&&arr[2][j-1]==0) block++;
			}
			else
			{
				if(arr[1][j]==0) block++;
				if(j<n&&arr[1][j+1]==0) block++;
				if(j>1&&arr[1][j-1]==0) block++;
			}
		}
		else
		{
			if(i==1)
			{
				if(arr[2][j]==0) block--;
				if(j<n&&arr[2][j+1]==0) block--;
				if(j>1&&arr[2][j-1]==0) block--;
			}
			else
			{
				if(arr[1][j]==0) block--;
				if(j<n&&arr[1][j+1]==0) block--;
				if(j>1&&arr[1][j-1]==0) block--;
			}
		}
		if(block>0) cout<<"No"<<endl;
		else cout<<"Yes"<<endl;
	}
	return 0;
}