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
	int n;
	cin>>n;
	vector<bool> arr(100001,false);
	while(n--)
	{
		int x,y,cnt=0,k=0; k++;
		cin>>x>>y;
		arr[x]=true;
		if(y==0)
		{
			for(int i=1;i*i<=x;i++)
			{
				if(x%i==0) {cnt++; if(x/i!=i) cnt++; arr[i]=arr[x/i]=true;}
			}
			cout<<cnt<<endl;
		}
		else
		{
			for(int i=1;i*i<=x;i++)
			{
				if(x%i==0)
				{
					for(int j=1;j<=y;j++)
					{
						if(arr[k-j]%i==0) break;
					}
				}
			}
			cout<<cnt<<endl;
		}
	}
	return 0;
}