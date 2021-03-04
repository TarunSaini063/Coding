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
	int a,b,k;cin>>a>>b>>k;	
	int t=a+b-1;string s;
	for(int i=0;i<b;++i)s+='1';
	for(int i=0;i<a;++i)s+='0';
	while((s[t-k]=='0'||s[t]=='1')&&t-k>=0)t--;
	if(t-k<=0&&k)cout<<"NO"<<endl; 
	else{
		cout<<"YES"<<endl<<s<<endl;
		swap(s[t],s[t-k]);
		cout<<s<<endl; 
	}
	return 0;
}