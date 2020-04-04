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
vector<vector<int>> arr;
bool check(double h,double v)
{
	double tp;
	for(int i=0;i<(int)arr.size();i++)
	{
		tp=h;
		tp-=arr[i][0];
		if(tp<=0) continue;
		if(tp>=arr[i][3]) v-=(arr[i][1]*arr[i][2]*arr[i][3]);
		else v-=(tp*arr[i][2]*arr[i][3]);
		if(v<0) return false;
	}
	// cout<<"volume "<<v<<" mid "<<h<<endl;
	return (v==0);
}
int main(void)
{
	FIO	
	int k;
	cin>>k;
	while(k--)
	{
		int n,mn=INT_MAX,mx=INT_MIN;
		cin>>n;
		arr=vector<vector<int>> (n);
		for(int i=0;i<n;i++) 
		{
			arr[i]=vector<int> (4);
			cin>>arr[i][0]>>arr[i][1]>>arr[i][2]>>arr[i][3];
			mn=min(arr[i][0],mn);
			mx=max(mx,arr[i][0]+arr[i][3]);
		}
		double ans=-1,v;
		cin>>v;
		mx=(double)mx*1.0;
		mn=(double)mn*1.0;

		
		while(mx-mn>1e-8)
		{
			double mid=(mn+mx)/2.;
			if(check(mid,v)) {ans=mid;mx=mid;}
			else mn=mid;
			

		}
		if(ans!=-1) cout<<fixed<<setprecision(2)<<ans<<endl;
		else cout<<"OVERFLOW"<<endl;
	}
	return 0;
}