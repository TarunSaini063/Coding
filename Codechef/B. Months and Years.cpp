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
	int n,j,x=0;
	cin>>n;
	int arr[n];
	int mt2[]={31,29,31,30,31,30,31,31,30,31,30,31};
	for(int i=0;i<n;i++) 
	{
		cin>>arr[i]; 
		if(arr[i]==29) x++;
	}
	if(x>=2) {
		cout<<"No"<<endl;
		return 0;
	}
	for(int i=0;i<12;i++)
	{
		if((arr[0]==mt2[i])||(i==1&&(arr[0]==28||arr[0]==29)))
		{
			for(j=0;j<n;j++)
			{
				if((i+j)%12==1&&(arr[j]==28||arr[j]==29)) continue;
				if(mt2[(i+j)%12]!=arr[j])
				{
					break;
				}
			}
			if(j==n)
			{
				cout<<"Yes"<<endl;
				return 0;
			}
		}
		
	}
	cout<<"No"<<endl;
	return 0;
}