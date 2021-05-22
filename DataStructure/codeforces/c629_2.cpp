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
		int n,k;
		string s="";
		cin>>n>>k;
		int tp=((int)sqrt(k*8+1)-1)/2;
		int tp1=(tp+1)*tp/2;
		if(tp1==k)
		{
			for(int i=1;i<n-tp;i++) s+="a";
			s+="bb";
			while((int)s.size()<n) s+="a";
		}
		else
		{
			for(int i=1;i<n-tp;i++) s+="a";
			s+="b";
			// cout<<s<<" ";
			k-=tp1;
			while((int)s.size()-k<n) s+="a";
			s+="b";
		}
		cout<<s<<"\n";
	}
	
	return 0;
}