#include <bits/stdc++.h>
using namespace std;
#define ld double
#define ll int
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
	int q;
	cin>>q;
	while(q--){
		int n,x;
		cin>>n>>x;
		int a[100010],b[100010]={0},num0=0,num1=0;
		for(int i=0;i<n;i++){
			scanf("%1d",&a[i]);
			if(a[i]==1) num1++;
			else num0++; 
			b[i+1]=num0-num1;
		}
		int ans=0;
		for(int i=0;i<n;i++){
			if(x==b[i]&&b[n]==0) ans=-1;
			if(b[n]!=0){
				if((x-b[i])/b[n]>=0&&(x-b[i])%b[n]==0) ans++;
			}
		}
		cout<<ans;
	cout<<endl;	
	}
	return 0;
}