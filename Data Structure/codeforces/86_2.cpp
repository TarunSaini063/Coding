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
	int t1;
	cin>>t1;
	while(t1--)
	{
		string t;
		cin>>t;
		int it=1;
		for(int i=0;i<(int)t.size()-1;i++)
		{
			if(t[i]!=t[i+1]) {it=-1; break;}
		}
		if(it==1||t.size()==2)
		{
			// if(t.size()==2&&it!=1) t=t+t.front();
			cout<<t<<"\n";
			continue;
		}
		string s="";
		s+=t[0];
		for(int i=1;i<(int)t.size();i++)
		{
			if(s.back()==t[i]) s+=to_string((t[i]-'0'+1)%2);
			s+=t[i];
			// cout<<s<<" ";
		}
		cout<<s<<"\n";
	}
	return 0;
}